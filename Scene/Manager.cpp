#include "pch.h"
#include "ManagerImp.h"

namespace Elegance
{
	namespace Scene
	{
		Manager& Manager::Get()
		{
			static ManagerImp s_obj;
			return s_obj;
		}
	}
}
