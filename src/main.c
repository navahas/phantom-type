#include <stdint.h>
#include <stdio.h>

#include "ptr_based.c"
#include "zero_cost.c"

void ptr_based_rocket() {
    rocket_idle r1 = rocket_new(11);
    rocket_armed r2 = rocket_arm(r1);
    rocket_launched r3 = rocket_launch(r2);
    rocket_reset(r3);
}

void zero_cost_rocket() {
    ZRocketIdle r1 = zrocket_new(12);
    ZRocketArmed r2 = zrocket_arm(r1);
    ZRocketLaunched r3 = zrocket_launch(r2);
    zrocket_reset(r3);
}

int main() {
    ptr_based_rocket();
    puts("");
    zero_cost_rocket();

    return 0;
}
