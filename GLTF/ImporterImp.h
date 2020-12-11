#pragma once
#include "GLTF/Importer.h"
#include "GLTF/ResourceManager.h"

namespace Elegance
{
	namespace GLTF
	{
		class ImporterImp : public Importer
		{
		public:
			ImporterImp() = delete;
			ImporterImp(const ImporterImp&) = delete;
			ImporterImp& operator= (const ImporterImp&) = delete;

			ImporterImp(const ImportInfo& info);

			virtual ~ImporterImp() {}
		public:
			virtual bool Import() override;
			virtual osg::ref_ptr<Utils::BaseObject> GetRoot() override;
			virtual std::shared_ptr<fx::gltf::Document> GetGLTF() override;
		protected:
			void Load();
			void LoadAsset(const fx::gltf::Asset& asset);
			void AddNodes(osg::ref_ptr<Utils::BaseObject> pNode, std::shared_ptr<fx::gltf::Document> gltfObject, const std::vector<int32_t>& nodes);
			bool ImportMesh(osg::ref_ptr<Utils::BaseObject> pNode, std::shared_ptr<fx::gltf::Document> gltfObject, const fx::gltf::Node& curNode);
			std::string GetClassType(const fx::gltf::Node& node);
			void InitFromGLTFNode(osg::ref_ptr<Utils::BaseObject> pNode, std::shared_ptr<fx::gltf::Document> gltfObject, const fx::gltf::Node& curNode);

			osg::Matrix	GetMatrix(const fx::gltf::Node& curNode);
			osg::Matrix	GetMatrix(const osg::Vec3& tran, const osg::Vec3& scale, const osg::Quat& quat);
			osg::Quat	GetRotation(const fx::gltf::Node& node);
			osg::Vec3	GetScale(const fx::gltf::Node& node);
			osg::Vec3	GetTran(const fx::gltf::Node& node);
		private:
			ImportInfo m_info;
			std::shared_ptr<ResourceManager> m_pResourceManager;
			std::shared_ptr<fx::gltf::Document> m_pGLTF;
			osg::ref_ptr<Utils::BaseObject> m_pRoot;
		};
	}
}