#include <std.h>
#include "../marsh.h"

inherit WEAPONLESS;

create()
{
    int my_hd;
    my_hd = roll_dice(2, 10) + 4;
    ::create();
    set_name("boa");
    set("id", ({ "boa" }));
    set("short", "%^RESET%^%^RED%^Large boa%^RESET%^");
    set("aggressive", random(10) + 5);
    set_level(9);

    set("long", "A large boa constrictor.");
    set_class("fighter");
    set_body_type("snake");
    set_alignment(5);
    set("race", "snake");
    set_overall_ac(10 - my_hd);
    set_guild_level("fighter", my_hd);
    set_hd(my_hd, 5);
    set_attacks_num(my_hd / 7 + 1);
    set_damage(1, my_hd);
    set_base_damage_type("bludgeoning");
    set_max_hp(my_hd * 18);
    set_hp(my_hd * 18);
    //set_exp(1000);
    set_new_exp(my_hd, "high");
    set_stats("strength", my_hd);
    set_stats("dexterity", my_hd);
    set_emotes(3, ({ "The snake tries to wrap itself around you!",
                     "%^RED%^The boa lashes out at you!%^RESET%^",
                     "%^GREEN%^The boa entwines you!%^RESET%^", }), 1);
    set_max_level(18);
}
