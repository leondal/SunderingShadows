#include <std.h>
#include "../marsh.h"

inherit WEAPONLESS;

create()
{
    int my_hd;
    my_hd = roll_dice(2, 8) + 7;
    ::create();
    set_name("lizard");
    set_id(({ "lizard" }));
    set_short("%^RESET%^%^RED%^Scaled lizard%^RESET%^");
    set("aggressive", random(10) + 5);
    set_level(my_hd);
    set_long("A small lizard with a plethora of scales.");
    set_body_type("reptile");
    set_alignment(5);
    set_race("lizard");
    set_attacks_num(my_hd / 7 + 1);
    set_damage(2, my_hd / 2);
    set_base_damage_type("slashing");
    set_overall_ac(8 - my_hd);
    set_guild_level("fighter", my_hd);
    set_hd(my_hd, 5);
    set_max_hp(my_hd * 12 + 100);
    set_hp(my_hd * 12 + 100);
    //set_exp(1500);
    set_new_exp(my_hd, "mid");
    set_stats("strength", my_hd);
    set_stats("dexterity", my_hd);
    set_emotes(3, ({ "The lizard bites you!",
                     "%^RED%^The lizard spits a vile liquid at you!%^RESET%^",
                     "%^GREEN%^The lizard lashes out with it's sharp fangs!%^RESET%^", }), 1);
    set_max_level(18);
}
