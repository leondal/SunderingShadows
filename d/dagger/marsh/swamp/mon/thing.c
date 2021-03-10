#include <std.h>
#include "../marsh.h"

inherit WEAPONLESS;

create()
{
    int my_hd;
    my_hd = roll_dice(2, 8) + 8;
    ::create();
    set_name("thing");
    set("id", ({ "swamp", "swamp thing", "thing" }));
    set("short", "%^RESET%^%^GREEN%^Swamp thing%^RESET%^");
    set("aggressive", random(10) + 9);
    set_level(my_hd);
    set("long", "%^GREEN%^This creature appears to be composed of wood-like skin "
        "covered with various swamp slime. Slightly humanoid it towers 10 feet "
        "in the air above you gazing around looking for food with its "
        "haunting eerie green eyes.%^RESET%^");
    set_class("fighter");
    set_race("monstrous humanoid");
    set_body_type("human");
    set_attacks_num(my_hd / 7 + 1);
    set_damage(2, my_hd / 2);
    set_base_damage_type("bludgeoning");
    set_attack_limbs(({ "right hand", "left hand" }));
    set_alignment(6);
    set_overall_ac(7 - my_hd);
    set_guild_level("fighter", my_hd);
    set_hd(my_hd, 5);
    set_max_hp(my_hd * 12 + 100);
    set_hp(my_hd * 12 + 100);
    //set_exp(1900);
    set_new_exp(my_hd, "high");
    set_stats("strength", my_hd);
    set_stats("dexterity", my_hd);
    set_emotes(3, ({ "The swamp thing moans loudly.",
                     "%^RED%^The swamp thing attempts to knock you down!%^RESET%^",
                     "%^GREEN%^The swamp thing uses the swamp to heal itself!%^RESET%^", }), 1);
    set_max_level(18);
}
