#include <stdint.h>
#include <stdio.h>

typedef uint32_t u32;

typedef struct RawRocket {
    u32 id;
} RawRocket;

#define DEFINE_ROCKET_STATE(STATE)                                                                 \
    typedef struct {                                                                               \
        RawRocket rr;                                                                              \
    } ZRocket##STATE;

DEFINE_ROCKET_STATE(Idle)
DEFINE_ROCKET_STATE(Armed)
DEFINE_ROCKET_STATE(Launched)

ZRocketIdle zrocket_new(u32 id) {
    RawRocket raw_r = {
        .id = id,
    };

    ZRocketIdle r = {
        .rr = raw_r,
    };
    printf("[rocket_new] id: %d\n", r.rr.id);
    return r;
}

ZRocketArmed zrocket_arm(ZRocketIdle r) {
    ZRocketArmed r_new = { .rr = r.rr };
    printf("[rocket_arm] id: %d\n", r.rr.id);
    return r_new;
}

ZRocketLaunched zrocket_launch(ZRocketArmed r) {
    ZRocketLaunched r_new = { .rr = r.rr };
    printf("[rocket_launch] id: %d\n", r.rr.id);
    return r_new;
}

ZRocketIdle zrocket_reset(ZRocketLaunched r) {
    ZRocketIdle r_new = { .rr = r.rr };
    printf("[rocket_reset] id: %d\n", r.rr.id);
    return r_new;
}
