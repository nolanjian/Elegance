#pragma once

#include "Utils/Utils.h"
#include "Utils/Node/BaseObject.h"
#include <osg/Referenced>

#include <functional>

namespace Elegance
{
	namespace Utils
	{
		class UTILS_API IObjectFactory
		{
		public:
			IObjectFactory(const IObjectFactory&) = delete;
			IObjectFactory(const IObjectFactory&&) = delete;
			IObjectFactory& operator= (const IObjectFactory&) = delete;
			IObjectFactory& operator= (const IObjectFactory&&) = delete;

			virtual ~IObjectFactory() {}

			static IObjectFactory& Get();

			virtual osg::ref_ptr<BaseObject> Gen(const std::string& className) = 0;
		protected:
			IObjectFactory() {}
		};
	}
}