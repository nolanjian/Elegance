#pragma once

#include "Utils/IObjectFactory.h"

namespace Elegance
{
	namespace Utils
	{
		class ObjectFactory : public IObjectFactory
		{
		public:
			ObjectFactory();
			virtual ~ObjectFactory() {}

			virtual void Regist(const std::string& className, std::function<osg::ref_ptr<BaseObject>(void)> fn) final;
			virtual osg::ref_ptr<BaseObject> Gen(const std::string& className) override;
		private:
			std::map<std::string, std::function<osg::ref_ptr<BaseObject>(void)>> m_mapGeneraters;
		};
	}
}