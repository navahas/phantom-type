#include <stdint.h>
#include <stdio.h>

typedef uint32_t u32;

// The Ghosts
struct Idle {};
struct Armed {};
struct Launched {};

#define DEFINE_ROCKET(TAG)                                                                         \
    struct RocketState##TAG {                                                                      \
        u32 id;                                                                                    \
        struct TAG _phantom;                                                                       \
    };

DEFINE_ROCKET(Idle);
DEFINE_ROCKET(Armed);
DEFINE_ROCKET(Launched);

typedef struct RocketStateIdle rocket_idle;
typedef struct RocketStateArmed rocket_armed;
typedef struct RocketStateLaunched rocket_launched;

_Static_assert(sizeof(struct RocketStateIdle) == sizeof(u32), "[ZERO_COST_ABSTRACTION] FAILED");

rocket_idle rocket_new(u32 id) {
    rocket_idle r = {
        .id = id,
    };
    return r;
}

rocket_armed rocket_arm(rocket_idle r) {
    rocket_armed r_new = {
        .id = r.id,
    };
    return r_new;
}

rocket_launched rocket_launch(rocket_armed r) {
    rocket_launched r_new = {
        .id = r.id,
    };
    return r_new;
}

rocket_idle rocket_reset(rocket_launched r) {
    rocket_idle r_new = {
        .id = r.id,
    };
    return r_new;
}
