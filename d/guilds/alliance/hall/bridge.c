// /d/guilds/alliance/bridge.c

#include <std.h>
#include "../alliance.h"

inherit VAULT;

void create()
{
    object other;

    ::create();
    set_indoors(0);
    set_travel(PAVED_ROAD);
    set_terrain(VILLAGE);
    set_light(2);
    set_property("teleport proof", "/daemon/player_housing"->get_phouse_tp_proof("legendary"));
    set_short("On the Drawbridge");
    set_long("%^CYAN%^On the Drawbridge%^RESET%^\n%^BOLD%^%^WHITE%^You find yourself walking on a massive drawbridge that leads across the dark%^RESET%^ %^ORANGE%^moat%^RESET%^%^BOLD%^%^WHITE%^ that surrounds the castle. The drawbridge is  made of strong oak reinforced with iron. On it you see a large symbol that looks like two gauntlets shaking hands.%^RESET%^");
    set_listen("default", "You hear many different sounds from within the castle but they still seem distant.");
    set_smell("default", "The strong smell of the moat and wood fills your nose.");
    set_exits(([
                   "enter" : "/d/guilds/alliance/hall/gate.c",
                   "south" : "/d/shadow/room/pass/road14.c",
               ]));
    set_items(([
                   "moat" : " %^BLUE%^This is a moat that surrounds the castle, built to keep attackers from the castle walls. The only way across seems to be by this drawbridge. The water looks dark and cold and the moat seems fairly deep, deep enough to keep a fully armoured warrior from swimming across it.",
               ]));
    set_door("gate", "/d/guilds/alliance/hall/gate.c", "enter");
    set_open("gate", 0);
    add_lock("gate", "alliance ring", "lock", "There is no keyhole in this lock, but rather a circular depression with a tiny engraved image of two gauntlets shaking hands.  Otherwise it is a gigantic, but otherwise normal, gate lock.");
    set_locked("gate", 1, "lock");
    lock_difficulty("gate", get_phouse_lock_dc("epic"), "lock");
    //other = find_object_or_load(RDIR + "stair2");
    //other->set_locked("gate", 1, "lock");
    //other->set_open("gate", 0);
    set_trap_functions(({ "gate" }), ({ "lock_trap" }), ({ "pick" }), ({ get_phouse_lock_dc("epic") }));
    set_post_exit_functions(({ "enter" }), ({ "entered" }));
}

int lock_trap(string str)
{
    int stun;
    stun = TP->query_lowest_level();
    if (!stun) {
        stun = 1;
    }
    stun = 1000 / stun;
    HALL_D->alarm("%^MAGENTA%^BOLD%^Guard yells:%^RESET%^ SOMEONE IS MESSING WITH THE GATE!");
    tell_object(TP, "You look up to see a murder hole opening above you...and boulders spilling out of it!!");
    TP->force_me("emote tries to shield " + TP->query_possessive() + " head from the falling rocks!");
    tell_room(TP, "%^BOLD%^Dozens of large stones rain down on " + TPQCN, ({ TP }));
    tell_object(TP, "%^RED%^BOLD%^You are hammered to the ground by the speeding rocks!");
    TP->do_damage(1, roll_dice(8, 8));
    if (!wizardp(TP)) {
        TP->set_paralyzed(stun, "You are stunned.");
    }
    HALL_D->incoming(TO);
    return 1;
}

void entered()
{
    tell_object(TP, "As you enter, you see a sign above you that says %^BOLD%^%^WHITE%^'Remember to lock the gate as you enter!'%^RESET%^");
    return;
}
