//stag_beetle.c - Mob for low level cave area
//by Circe 3/13/05
#include <std.h>
#include "../ekibi.h"

inherit WEAPONLESS;

void create()
{
    ::create();
    set_name("stag beetle");
    set_short("A giant stag beetle");
    set_id(({ "beetle", "stag beetle", "giant beetle", "giant stag beetle", "insect" }));
    set_long("This enormous beetle is well over five feet long with a " +
             "slender body supported by six jointed legs.  By far the " +
             "most impressive feature on this insect are the two antler-" +
             "like mandible jaws protruding from its relatively small " +
             "head.  Its carapace is a %^BOLD%^%^BLACK%^glossy jet " +
             "black %^RESET%^%^CYAN%^edged with magnificent %^ORANGE%^" +
             "bronze%^RESET%^%^CYAN%^.  It would be a beautiful " +
             "creature if it didn't seem intent on killing everything " +
             "in sight!");
    set_gender(random(2) ? "male" : "female");
    set_race("beetle");
    set_body_type("insectoid");
    set_size(2);
    set_alignment(5);
    set_hd(5, 5);
    set("aggressive", 18);
    set_property("swarm", 1);
    set_class("fighter");
    set_mlevel("fighter", 5);
    set_hp(random(10) + 50);
    set_overall_ac(4);
    set_stats("strength", 12);
    set_damage(1, 4);
    set_attacks_num(2);
    set_base_damage_type("slashing");
    set_attack_limbs(({ "mouth" }));
    set_exp(135);
    set_max_level(9);
}

void die(object obj)
{
    if (!random(6)) {
        new(OBJ "stag_antler")->move(TO);
    }
    ::die(obj);
}
