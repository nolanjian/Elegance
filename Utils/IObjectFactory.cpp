#include "pch.h"
#include "ObjectFactory.h"

namespace Elegance
{
	namespace Utils
	{
		IObjectFactory& IObjectFactory::Get()
		{
			static ObjectFactory s_obj;
			return s_obj;
		}
	}
}
