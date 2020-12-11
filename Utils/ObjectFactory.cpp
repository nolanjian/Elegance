#include "pch.h"
#include "ObjectFactory.h"

#include "Utils/Node/BaseObject.h"

namespace Elegance
{
	namespace Utils
	{
		osg::ref_ptr<BaseObject> ObjectFactory::Gen(const std::string& className)
		{
			if (m_mapGeneraters.find(className) != m_mapGeneraters.end())
			{
				return (m_mapGeneraters[className])();
			}
			return nullptr;
		}

		ObjectFactory::ObjectFactory()
		{
			Regist("BaseNode", []() {return osg::ref_ptr<BaseObject>(new BaseObject); });
		}

		void ObjectFactory::Regist(const std::string& className, std::function<osg::ref_ptr<BaseObject>(void)> fn)
		{
			if (className.empty())
			{
				throw new std::exception("Empty className!");
			}
			if (fn == nullptr)
			{
				throw new std::exception("Empty fn!");
			}
			if (m_mapGeneraters.find(className) != m_mapGeneraters.end())
			{
				throw new std::exception("Already exist this class!");
			}
			m_mapGeneraters[className] = fn;
		}
	}
}
