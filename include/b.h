#ifndef __H_B_H__
#define __H_B_H__
#include "./sensorPluginBase.h"
#include "class_loader/class_loader.h"
#include <time.h>
#include <fstream>
#include <iomanip>
//class_loader/class_loader.h >

#include <random>
namespace micros_sensor_plugin
{
    using namespace std;

    class BSensorPlugin : public SensorPluginBase
    {
        int j;

    public:
        BSensorPlugin();
        ~BSensorPlugin();
        void print()
        {
            cout << "class BSensorPlugin!" << endl;
        }
        int init(const std::map<std::string, std::string> &aMap);

        void dataProcess(int fd, std::list<boost::shared_ptr<Label>> &labelPtrList);
        long genData(char *buf);
        int getJ();
        void setJ(int k);
        int getFlag();
        void setFlag(int s);
        void setReserved(void *);
        void *getReserved();
    };
} // namespace micros_sensor_plugin
#endif
