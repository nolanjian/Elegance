#pragma once
#include "GLTF.h"
#include <memory>
#include <filesystem>
#include <fx/gltf.h>
#include <Utils/Node/BaseObject.h>

namespace Elegance
{
	namespace GLTF
	{
		class GLTF_API ImportInfo
		{
		public:
			std::string strUTF8Json;
			std::string strPath;
		};
		class GLTF_API Importer
		{
		public:
			virtual ~Importer(){}
			static std::shared_ptr<Importer> Excute(const ImportInfo& info);
		public:
			virtual bool Import() = 0;
			virtual osg::ref_ptr<Utils::BaseObject> GetRoot() = 0;
			virtual std::shared_ptr<fx::gltf::Document> GetGLTF() = 0;
		protected:
		private:
		};
	}
}