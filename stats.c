/*=============================================================================
 =======                            INCLUDES                            =======
 =============================================================================*/
#include <stdio.h>
#include <math.h>
#include "stats.h"

/*=============================================================================
 =======                            VARIABLES                           =======
 =============================================================================*/
// int emailAlertCallCount = 0;
// int ledAlertCallCount   = 0;


struct Stats compute_statistics(const float* numberset, int setlength) 
{
    struct Stats s;
    s.average = 0;
    s.min = 0;
    s.max = 0;

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
    i++;
        
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
/*
 *******************************************************************************
 * Functions
 *******************************************************************************
*/
/*------------------------------------------------------------------------------
 * FUNCTION:   check_and_alert()
 * \brief      calls the emailAlerter and ledAlerter function.
 * \param      maxThreshold, alerters[], computedStats
 * \return     void
/*--------------------------------------------------------------------------*/
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats) 
{
    if (computedStats.average >= maxThreshold) 
    {
        alerters[0]();
        alerters[1]();
    }
}

/* EOF */

