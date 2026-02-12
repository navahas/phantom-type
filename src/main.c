#include <stdint.h>
#include <stdio.h>

// The Ghosts
struct Idle;
struct Armed;
struct Launched;

#define DEFINE_ROCKET(TAG)                                                     \
    struct RocketState##TAG {                                                  \
        int id;                                                                \
        struct TAG *_phantom;                                                  \
    };

DEFINE_ROCKET(Idle);
DEFINE_ROCKET(Armed);
DEFINE_ROCKET(Launched);

typedef struct RocketStateIdle rocket_idle;
typedef struct RocketStateArmed rocket_armed;
typedef struct RocketStateLaunched rocket_launched;

rocket_idle rocket_new(int id) {
    rocket_idle r = {.id = id, ._phantom = NULL};
    printf("[rocket_new] id: %d | _phantom: %p\n", r.id, r._phantom);
    return r;
}

rocket_armed rocket_arm(rocket_idle r) {
    rocket_armed r_new = {.id = r.id, ._phantom = NULL};
    printf("[rocket_arm] id: %d | _phantom: %p\n", r.id, r._phantom);
    return r_new;
}

rocket_launched rocket_launch(rocket_armed r) {
    rocket_launched r_new = {.id = r.id, ._phantom = NULL};
    printf("[rocket_launch] id: %d | _phantom: %p\n", r.id, r._phantom);
    return r_new;
}

rocket_idle rocket_reset(rocket_launched r) {
    rocket_idle r_new = {.id = r.id, ._phantom = NULL};
    printf("[rocket_reset] id: %d | _phantom: %p\n", r.id, r._phantom);
    return r_new;
}

int main() {
    rocket_idle r1 = rocket_new(11);
    rocket_armed r2 = rocket_arm(r1);
    rocket_launched r3 = rocket_launch(r2);
    rocket_reset(r3);
    return 0;
}
