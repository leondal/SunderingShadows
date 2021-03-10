#include <std.h>
#include <daemons.h>

inherit DAEMON;

int check_climb(int climb_info, object ob)
{
    int skill, total, die_roll, inc, temp;
    string* armor;
    if (present("climbing tool", ob)) {
        return 1;
    }
    if (ob->query_property("spider climb") ||
        ob->query_property("flying") ||
        RACE_D->can_fly(ob)) {
        return 1;
    }
    skill = ob->query_skill("athletics") + roll_dice(1, 20);
    if (sizeof(ob->query_armour("torso"))) {
        skill += ob->skill_armor_mod(ob->query_armour("torso"));
    }

    if (skill < climb_info) {
        if ((skill + 10) < climb_info) {
            return -1;
        }else {
            return 0;
        }
    }
    return 1;
}
