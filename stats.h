/*
 *******************************************************************************
 * Structure Declaration
 *******************************************************************************
 */
struct Stats {
  float average;
  float min;
  float max;
}s;

/*
 *******************************************************************************
 * Function Declarations
 *******************************************************************************
 */
struct Stats compute_statistics(const float* numberset, int setlength);
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);

/*
 *******************************************************************************
 * Type definitions
 *******************************************************************************
*/
typedef void (*alerter_funcptr)();

/*=============================================================================
 =======                            VARIABLES                           =======
 ==============================================================================
 */
extern int emailAlertCallCount;
extern int ledAlertCallCount;

/* EOF */
