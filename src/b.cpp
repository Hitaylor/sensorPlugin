#include "../include/b.h"

namespace micros_sensor_plugin
{
  BSensorPlugin::BSensorPlugin()
  {
    j = 0;
  }

  BSensorPlugin::~BSensorPlugin()
  {
    j = 0;
  }

  int BSensorPlugin::init(const std::map<std::string, std::string> &aMap)
  {
    return 0;
  }

  long BSensorPlugin::genData(char *buf)
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

  void BSensorPlugin::dataProcess(int fd, std::list<boost::shared_ptr<Label>> &labelPtrList)
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
        cout << "[BSensorPlugin::dataProcess()] The " << count << "-th write " << length << " bytes into file" << endl;
      }
      else
      {
        cout << "[BSensorPlugin::dataProcess()] The " << count << "-th write failed, write " << length << " bytes into file, but should write " << length << " bytes!" << endl;
      }
      if (!labelPtrList.empty())
      {
        for (auto iter = labelPtrList.begin(); iter != labelPtrList.end(); ++iter)
        {
          labelPtr = *iter;
          void *labelContent = labelPtr->getLabelContent();
          ret = write(fd, labelContent, labelPtr->getLabelContentLength());
          if (ret != labelPtr->getLabelContentLength())
            cout << "[BSensorPlugin::dataProcess()] Index write length is not equal to the truth length!" << endl;
        }
      }
    }
  }

  void BSensorPlugin::setJ(int k)
  {
    j = k;
  }

  int BSensorPlugin::getJ()
  {
    return j;
  }

  int BSensorPlugin::getFlag() 
  {
    return flag;
  }

  void BSensorPlugin::setFlag(int aFlag)
  {
    flag = aFlag;
  }

  void *BSensorPlugin::getReserved()
  {
    return reserved;
  }
  void BSensorPlugin::setReserved(void *aReserved)
  {
    reserved = aReserved;
  }

} // namespace micros_sensor_plugin

CLASS_LOADER_REGISTER_CLASS(micros_sensor_plugin::BSensorPlugin, micros_sensor_plugin::SensorPluginBase)
