#include "../include/b.h"
#include "../include/c.h"
#include "../include/sensorPluginBase.h"
#include <thread>
using namespace std;
using namespace micros_sensor_plugin;
int main()
{

   // std::thread t1(std::bind(&Child::createThread),&c1,&c1),t2(std::bind(&Child2::createThread,&c2,&c2));
   SensorPluginBase *t, *t2;
   t = new BSensorPlugin();

   t->print();
   //t->startThread();

   cout << "SIZEOF BSensorPlugin:" << sizeof(t) << endl;

   t2 = new CSensorPlugin();
   t2->print();
   //t2->startThread();
   //下面保留一个延迟函数，确保main线程不会结束，否则前面创建的2个线程会随着main线程的结束而退出！
   getchar();
   cout << "main thread exit()"<< endl;
}