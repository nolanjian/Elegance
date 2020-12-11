#include "pch.h"
#include "ObjectFactory.h"

namespace Elegance
{
	namespace Utils
	{
		const IObjectFactory& IObjectFactory::Get()
		{
			static ObjectFactory s_obj;
			return s_obj;
		}
	}
}
