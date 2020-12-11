#include "pch.h"
#include "ImporterImp.h"

#include "Utils/IObjectFactory.h"

#include <sstream>

namespace Elegance
{
	namespace GLTF
	{
		ImporterImp::ImporterImp(const ImportInfo& info)
			: m_info(info)
		{
		}

		bool ImporterImp::Import()
		{
			try
			{
				if (!m_info.strUTF8Json.empty())
				{
					std::stringstream	ss;
					ss << m_info.strUTF8Json;
					m_pGLTF = std::make_shared<fx::gltf::Document>(
						std::move(fx::gltf::LoadFromText(ss, fx::gltf::detail::GetDocumentRootPath(m_info.strPath))));
				}
				else
				{
					if (m_info.strPath.rfind(".glb") != std::string::npos)
					{
						m_pGLTF = std::make_shared<fx::gltf::Document>(
							std::move(fx::gltf::LoadFromBinary(m_info.strPath)));
					}
					else
					{
						m_pGLTF = std::make_shared<fx::gltf::Document>(
							std::move(fx::gltf::LoadFromText(m_info.strPath)));
					}
				}

				assert(m_pGLTF.get());
				return true;
			}
			catch (const std::exception& ex)
			{
				return false;
			}
		}
		osg::ref_ptr<Utils::BaseObject> ImporterImp::GetRoot()
		{
			return m_pRoot;
		}

		std::shared_ptr<fx::gltf::Document> ImporterImp::GetGLTF()
		{
			return m_pGLTF;
		}

		void ImporterImp::Load()
		{
			LoadAsset(m_pGLTF->asset);
			m_pResourceManager = std::make_shared<ResourceManager>(m_pGLTF, m_info.strPath);

			// Scene level
			if (m_pGLTF->scenes.size() > 0 && (m_pGLTF->scenes[0]).nodes.size() > 0)
			{
				const fx::gltf::Scene& scene = m_pGLTF->scenes[0];

				std::vector<int32_t>	nodes;
				for (auto id : scene.nodes)
				{
					nodes.push_back(static_cast<int32_t>(id));
				}
				AddNodes(m_pRoot, m_pGLTF, nodes);
			}

			// TODO if necessary
			//std::vector<std::string> extensionsUsed{};
			//std::vector<std::string> extensionsRequired{};
		}

		void ImporterImp::LoadAsset(const fx::gltf::Asset& asset)
		{
		}

		void ImporterImp::AddNodes(osg::ref_ptr<Utils::BaseObject> pNode, std::shared_ptr<fx::gltf::Document> gltfObject, const std::vector<int32_t>& nodes)
		{
			for (int32_t childID : nodes)
			{
				const fx::gltf::Node& childNode = gltfObject->nodes[childID];
				osg::ref_ptr<Utils::BaseObject> pChild = Utils::IObjectFactory::Get().Gen(GetClassType(childNode));
				if (pChild == nullptr)
				{
					continue;
				}
				InitFromGLTFNode(pChild, gltfObject, childNode);

				pNode->addChild(pChild);
			}
		}

		bool ImporterImp::ImportMesh(osg::ref_ptr<Utils::BaseObject> pNode, std::shared_ptr<fx::gltf::Document> gltfObject, const fx::gltf::Node& curNode)
		{
			if (curNode.mesh == -1)
			{
				return true;
			}

			osg::ref_ptr<osg::Geode> geo = m_pResourceManager->GetMesh(curNode.mesh);
			if (geo)
			{
				pNode->addChild(geo);
			}
			return true;
		}

		std::string ImporterImp::GetClassType(const fx::gltf::Node& node)
		{
			std::string strType("BaseObject");

			if (node.extensionsAndExtras.contains("class"))
			{
				std::string strTmp = node.extensionsAndExtras["class"].get<std::string>();
				if (!strTmp.empty())
				{
					return strTmp;
				}
			}

			return strType;
		}

		void ImporterImp::InitFromGLTFNode(osg::ref_ptr<Utils::BaseObject> pNode, std::shared_ptr<fx::gltf::Document> gltfObject, const fx::gltf::Node& curNode)
		{
			pNode->setName(curNode.name);
			pNode->getOrCreateStateSet();

#pragma region LOAD_MATRIX
			osg::Matrix mat = GetMatrix(curNode);
			if (mat.isIdentity())
			{
				osg::Quat quat = GetRotation(curNode);
				osg::Vec3 scale = GetScale(curNode);
				osg::Vec3 tran = GetTran(curNode);

				mat = GetMatrix(tran, scale, quat);
			}
			pNode->setMatrix(mat);
#pragma endregion LOAD_MATRIX

			//ImportParams(curNode.extensionsAndExtras);
			ImportMesh(pNode, gltfObject, curNode);

			// TODO
			//int32_t camera{ -1 };
			//int32_t skin{ -1 };
			//std::vector<float> weights{};

			AddNodes(pNode, gltfObject, curNode.children);
		}

		osg::Matrix ImporterImp::GetMatrix(const fx::gltf::Node& curNode)
		{
			osg::Matrix mat;
			mat.set(curNode.matrix[0], curNode.matrix[1], curNode.matrix[2], curNode.matrix[3]
				, curNode.matrix[4], curNode.matrix[5], curNode.matrix[6], curNode.matrix[7]
				, curNode.matrix[8], curNode.matrix[9], curNode.matrix[10], curNode.matrix[11]
				, curNode.matrix[12], curNode.matrix[13], curNode.matrix[14], curNode.matrix[15]);
			return mat;
		}

		osg::Matrix ImporterImp::GetMatrix(const osg::Vec3& tran, const osg::Vec3& scale, const osg::Quat& quat)
		{
			osg::Matrix mat;

			mat.postMultRotate(quat);
			mat.postMultTranslate(tran);
			mat.postMultScale(scale);
			return mat;
		}

		osg::Quat ImporterImp::GetRotation(const fx::gltf::Node& node)
		{
			osg::Quat quat;
			quat.x() = node.rotation.at(0);
			quat.y() = node.rotation.at(1);
			quat.z() = node.rotation.at(2);
			quat.w() = node.rotation.at(3);
			return quat;
		}

		osg::Vec3 ImporterImp::GetScale(const fx::gltf::Node& node)
		{
			osg::Vec3 scale;
			scale.x() = node.scale.at(0);
			scale.y() = node.scale.at(1);
			scale.z() = node.scale.at(2);
			return scale;
		}

		osg::Vec3 ImporterImp::GetTran(const fx::gltf::Node& node)
		{
			osg::Vec3 tran;
			tran.x() = node.translation.at(0);
			tran.y() = node.translation.at(1);
			tran.z() = node.translation.at(2);
			return tran;
		}
	}
}