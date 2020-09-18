#include "../include/c.h"
CLASS_LOADER_REGISTER_CLASS(micros_sensor_plugin::CSensorPlugin, micros_sensor_plugin::SensorPluginBase)

namespace micros_sensor_plugin
{

  CSensorPlugin::CSensorPlugin()
  {
    k = 0;
  }

  CSensorPlugin::~CSensorPlugin()
  {
    k = 0;
  }

  int CSensorPlugin::init( std::map<std::string, std::string> &aMap)
  {
    return 0;
  }

  long CSensorPlugin::genData(char *buf)
  {
    //char *buf = malloc(1024);
    long length;
    sleep(20);
    length = random() % 255 + 1;
    memset(buf, 0, 1024);
    for (long i = 0; i < length; i++)
    {
      buf[i] = (char)(rand() % 253 + 1);
    }
    return length;
  }

  void CSensorPlugin::dataProcess(int fd, std::list<boost::shared_ptr<Label>> &labelPtrList)
  {
    int ret, length;
    char *buf = (char *)malloc(1024);
    int count = 0;
    boost::shared_ptr<Label> labelPtr;
    while (flag)
    {
      sleep(10);
      length = genData(buf); //阻塞式
      //获取标签的内容

      ret = write(fd, buf, length);
      if (ret == length)
      {
        count++;
        cout << "[CSensorPlugin::dataProcess()] The " << count << "-th write " << length << " bytes into file" << endl;
      }
      else
      {
        cout << "[CSensorPlugin::dataProcess()] The " << count << "-th write failed, write " << length << " bytes into file, but should write " << length << " bytes!" << endl;
      }
      if (!labelPtrList.empty())
      {
        for (auto iter = labelPtrList.begin(); iter != labelPtrList.end(); ++iter)
        {
          labelPtr = *iter;
          void *labelContent = labelPtr->getLabelContent();
          ret = write(fd, labelContent, labelPtr->getLabelContentLength());
          if (ret != labelPtr->getLabelContentLength())
            cout << "[CSensorPlugin::dataProcess()] Index write length is not equal to the truth length!" << endl;
        }
      }
    }
  }


  void CSensorPlugin::setK( int &j)
  {
    k = j;
  }

  int CSensorPlugin::getK() 
  {
    return k;
  }

  int CSensorPlugin::getFlag() 
  {
    return flag;
  }

  void CSensorPlugin::setFlag( int &aFlag)
  {
    flag = aFlag;
  }

  void *CSensorPlugin::getReserved() 
  {
    return reserved;
  }
  void CSensorPlugin::setReserved( void *aReserved)
  {
    reserved = aReserved;
  }
} // namespace micros_sensor_plugin
