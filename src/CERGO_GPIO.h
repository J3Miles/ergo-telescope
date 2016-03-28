#ifndef CERGO_GPIO_H
#define CERGO_GPIO_H
#include "CLog.h"
#include <thread>
#include <chrono>
#include <sys/stat.h>

class CERGO_GPIO
{
    public:
        CERGO_GPIO();

        int export_gpio(int);
        int unexport_gpio(int );
        int setdir_gpio(int gpionum);
        int setval_gpio(int val,int gpionum);
        int getval_gpio(int gpionum);
	int set_edge(int gpionum);
	int get_edge(int gpionum);

	
        void pulse_light(std::chrono::milliseconds,int light_name);
	void test_lights();

        enum light_colours_t{RED_RIGHT = 24,YELLOW_MIDDLE= 23,GREEN_LEFT=18};
	enum edge_types{NONE = "none", RISING = "rising", FALLING = "falling",BOTH = "both"};
        virtual ~CERGO_GPIO();
    protected:
    private:
      CLog * Log;
      bool GPIO_EXISTS = "false";
      std::string gpio_dir = "/sys/class/gpio/";
};

#endif // CERGO_GPIO_H
