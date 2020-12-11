#include "pch.h"
#include "ImporterImp.h"

namespace Elegance
{
	namespace GLTF
	{
		std::shared_ptr<Importer> Importer::Excute(const ImportInfo& info)
		{
			std::shared_ptr<ImporterImp> pImp = std::make_shared<ImporterImp>(info);
			pImp->Import();
			return pImp;
		}
	}
}