#ifndef _H_SENSOR_PLUGIN_BASE_NAME
#define _H_SENSOR_PLUGIN_BASE_NAME
#include <iostream>
#include <map>
#include <unistd.h>
#include "label.h"
#include <list>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <boost/shared_ptr.hpp>

//#include <thread>
namespace micros_sensor_plugin
{
    using namespace std;

    class SensorPluginBase
    {
       public:
        ///used to control the data generating process. if 0, the plugin should stop to fetch data from the sensor.
        int flag;
        /// reserved for future.
        void *reserved;

    public:
        virtual void print() {}
        virtual int init(std::map<std::string, std::string>) {}
        //virtual void dataCapture(int *len, void *data) const = 0;
        virtual void dataProcess(int fd, std::list<boost::shared_ptr<Label > > &labelPtrList ) {}
        
        virtual int getFlag() {}

        virtual void setFlag(int &aFlag) {}
        

        virtual void *getReserved(){}
      
        virtual void setReserved(void *aReserved) {}
     
    };
} // namespace micros_sensor_plugin
#endif
