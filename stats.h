#include<stdio.h>
#include "math.h"

struct Stats {
  float average;
  float min;
  float max;
};

typedef void (*alerter_funcptr)();

struct Stats compute_statistics(const float* numberset, int setlength);
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);

extern int emailAlertCallCount;
extern int ledAlertCallCount;


