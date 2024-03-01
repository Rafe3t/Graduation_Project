#include <stdio.h>
// ACC stand for : adaptive cruse control 


#define MAX_SPEED 100.0  // Maximum speed of the vehicle in km/h %
#define MIN_DISTANCE 10.0  // Minimum safe distance in meters

double current_speed = 60.0;  // Initial speed of the vehicle in km/h %

void update_speed(double distance) {
    // ACC (how it works): Adjust speed based on the distance to the vehicle in front
    if (distance < MIN_DISTANCE) {
        // If too close, reduce speed
        current_speed -= 5.0;
    } 
    else if(distance > MIN_DISTANCE)
    {
         //  increase speed
         current_speed += 2.0;
    }
    else {
        //do nothing 
        
    }

    // Ensure speed is within the specified range
    if (current_speed < 0.0) {
        current_speed = 0.0;
    } 
    else if (current_speed > MAX_SPEED) 
    {
        current_speed = MAX_SPEED;
    }
    else 
    {
         //do nothing
    }
}

void simulate_acc() {
    double distance_to_vehicle_in_front = 20.0;  // Initial distance in meters

    for (int time = 0; time < 10; ++time) {  // Simulate it for 10 time 
        printf("Time: %ds - Current Speed: %.lf km/h - Distance to Vehicle: %.lf m\n", time, current_speed, distance_to_vehicle_in_front);

        printf("enter distance value: ");
        scanf("%lf",&distance_to_vehicle_in_front);


        // Ensure distance is non-negative
        if (distance_to_vehicle_in_front < 0.0) {
            distance_to_vehicle_in_front = 0.0;
        }
        else 
    {
         //do nothing
    }
                update_speed(distance_to_vehicle_in_front);


    }
}

int main() {
	
    printf("Adaptive Cruise Control Simulation\n");

    simulate_acc();


    return 0;
}
