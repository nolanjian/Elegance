#include "pch.h"
#include "ImporterImp.h"

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

	}
}