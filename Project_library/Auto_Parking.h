#ifndef AUTO_PARKING_H_
#define AUTO_PARKING_H_
#include "main.h"



#define lidar_time_cycle  4000       /* the time cycle of our lidar (ask ref3at)          */
#define X_AXIS_car        16 /*cm*/         /*we should put the width of our car (ask yasser)    */
#define Y_AXIS_car        26 /*cm*/        /*we should put the length of our car  (ask yasser)  */
#define MAX_Distance_BY_Lidar                 200       /*in CM */
#define tim_for_spi_Receive                   100    /*in ms*/

#define tim_every_18_degree                   200   /*in ms*/
#define tim_every_45_degree                   500   /*in ms*/
#define tim_every_90_degree                   1000   /*in ms*/
#define tim_every_180_degree                  2000   /*in ms*/
#define tim_every_270_degree                  3000   /*in ms*/



void finding_space(void);
void Parking_Car(void);

#endif
