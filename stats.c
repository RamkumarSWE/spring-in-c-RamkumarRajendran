
#include "stats.h"
struct Stats compute_statistics(const float* numberset, int setlength) 
{
    struct Stats s;
    s.average = 0.0;
    s.min = 0.0;
    s.max = 0.0;

if (setlength == 0 || numberset == 0)
{
        return s;
}
else 
{
    int num = 0; 
    float min = numberset[num];
    float max = numberset[num];
    float sum = numberset[num];
    num++;
        
    while((num>=1) && (num<setlength))
    {   
     if (numberset[num] > max) 
     {
      max = numberset[num];
     }
    else 
     {
        if(min > numberset[num])
        {
         min = numberset[num];
        }
     }
        sum += numberset[num];
        num++;    
    }          
    s.min = min;
    s.max = max;
    s.average = sum/setlength;
    }
    return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount   = 0;

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats) 
{
    if (computedStats.average >= maxThreshold) 
    {
       (void) (alerters[0]());
       (void) (alerters[1]());
    }
}



