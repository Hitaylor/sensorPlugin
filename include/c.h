#ifndef __H_C_H__
#define __H_C_H__
#include "./sensorPluginBase.h"
#include <random>
#include <time.h>
#include "class_loader/class_loader.h"
#include <fstream>
#include <iomanip>
#include <map>

namespace micros_sensor_plugin
{
    using namespace std;
    class CSensorPlugin : public SensorPluginBase
    {
        int k;

    public:
    CSensorPlugin();
    ~CSensorPlugin();
        void print()
        {
            cout << "class CSensorPlugin!" << endl;
        }
        int init( std::map<std::string, std::string> &aMap);

        void dataProcess(int fd,  std::list<boost::shared_ptr<Label > > &labelPtrList);
        long genData(char *buf);
        int getFlag() ;
        void setFlag( int &s);
        int getK() ;
        void setK( int &k);
        void setReserved( void *) ;
        void *getReserved()  ;
    };
} // namespace micros_sensor_plugin
#endif
