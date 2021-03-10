#include <daemons.h>

/**
 * @file
 * @brief These functions calculate room illumination in mud units
 */

/**
 * Calculates light value for the night time, counting in moon light. Presumes the sky is visible.
 *
 * @param env Room the object is in
 * @param light Base light value. It could be current light in the room, for example.
 * @return Illumination in mud units
 */
int night_light(object env, int light)
{
    return ((light - 3) +
            (ASTRONOMY_D->query_moon_light()) +
            (env->query_property("night light")));
}

/**
 * Calculates total light value for someone
 *
 * @param who Object you want to calculate illumination for
 * @return Light in mud units
 */
int total_light(object who)
{
    object* inv;
    object env;
    int light, i;

    if (objectp(who) && who->is_room()) {
        env = who;
    }else {
        if (!who || !(env = environment(who))) {
            return 0;
        }
    }

    inv = all_inventory(env);
    i = sizeof(inv);

    light = (int)env->query_property("light");
    while (i--) {
        light += (int)inv[i]->query_property("light");
    }

    if (env->query_property("indoors")) {
        return light;
    }
    if ((int)ASTRONOMY_D->query_eclipse()) {
        return night_light(env, light);
    }
    switch (EVENTS_D->query_time_of_day()) {
    case "dawn":
        return --light;
    case "day":
        return light;
    case "twilight":
        return --light;
    case "night":
        return night_light(env, light);
    }
    return light;
}
