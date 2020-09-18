#include <iostream>
#include <time.h>
#include <sys/timeb.h>
#include <vector>
using namespace std;

struct laderData{
	double a;
	double b;
	int c;
	};
	
int main()
{
    std::vector<struct laderData> vec;
    
    struct laderData tmp;
    for(int i=0;i<10000;i++){
    	tmp.a=1.02;
    	tmp.b = 0.234;
    	tmp.c= 1;
    	vec.push_back(tmp);
    }
    cout<<"vec.size()"<<vec.size()<<endl;
    for(int i=0;i<10000;i++) vec.pop_back();
    
    long long time_last = 0;
    time_last = time(NULL);   
    cout<<sizeof(time_last)<<endl;
    
    cout<<time_last<<endl;    //秒数

    struct timeb t1;
    ftime(&t1);

    cout<<t1.time<<endl;    //秒数
    cout<<t1.millitm<<endl;    //毫秒数
long long msc = t1.time*1000+t1.millitm;
cout<<msc<<endl;
    system("pause");
    return 0; 
}
