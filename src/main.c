#include "zero_size_v1.c"
#include "zero_size_v2.c"

void ptr_based_rocket() {
    rocket_idle r1 = rocket_new(11);
    rocket_armed r2 = rocket_arm(r1);
    rocket_launched r3 = rocket_launch(r2);
    rocket_reset(r3);

    printf("Size of Raw int: %zu\n", sizeof(uint32_t));
    printf("Size of Rocket_Idle: %zu\n", sizeof(rocket_idle));
}

void zero_cost_rocket() {
    ZRocketIdle r1 = zrocket_new(12);
    ZRocketArmed r2 = zrocket_arm(r1);
    ZRocketLaunched r3 = zrocket_launch(r2);
    zrocket_reset(r3);

    printf("Size of Raw int: %zu\n", sizeof(uint32_t));
    printf("Size of Rocket_Idle: %zu\n", sizeof(ZRocketIdle));
}

int main() {
    ptr_based_rocket();
    puts("");
    zero_cost_rocket();

    return 0;
}
