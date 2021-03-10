#include <std.h>
#include "../marsh.h"

inherit WEAPONLESS;

create()
{
    int my_hd;
    my_hd = roll_dice(2, 8) + 8;
    ::create();
    set_name("bogger");
    set("id", ({ "bogger", "bog thing", "thing" }));
    set("short", "%^RESET%^%^RED%^Bog thing%^RESET%^");
    set("aggressive", random(8) + 5);
    set_level(my_hd);
    set_long("%^GREEN%^This creature appears to be composed of stony skin "
             "covered with various bog slime.  Slightly humanoid, it towers 12 feet "
             "in the air above you gazing around looking for food with its "
             "haunting %^RED%^eerie red eyes.%^RESET%^");
    set_class("fighter");
    set_race("monstrous humanoid");
    set_body_type("human");
    set_attacks_num(my_hd / 3 + 1);
    set_damage(3, my_hd / 2);
    set_base_damage_type("bludgeoning");
    set_attack_limbs(({ "right hand", "left hand" }));
    set_alignment(5);
    set_overall_ac(-my_hd);
    set_guild_level("fighter", my_hd);
    set_hd(my_hd, 5);
    set_max_hp(my_hd * 25 + 150);
    set_hp(my_hd * 25 + 150);
    //set_exp(3000);
    set_new_exp(my_hd, "high");
    set_stats("strength", my_hd);
    set_stats("dexterity", my_hd);
    set_emotes(3, ({ "The bog thing shambles around you!",
                     "%^RED%^The bog thing's eyes blaze brightly!%^RESET%^",
                     "%^GREEN%^The bog thing uses the swamp to heal itself!%^RESET%^", }), 1);
    set_max_level(18);
}
