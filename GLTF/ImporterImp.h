#pragma once
#include "GLTF/Importer.h"

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
		private:
			ImportInfo m_info;
			std::shared_ptr<fx::gltf::Document> m_pGLTF;
			osg::ref_ptr<Utils::BaseObject> m_pRoot;
		};
	}
}