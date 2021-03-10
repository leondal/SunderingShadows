#include <std.h>
#include "../marsh.h"

inherit WEAPONLESS;

create()
{
    int my_hd;
    my_hd = roll_dice(1,4)+16;
    ::create();
    set_name("lurker");
    set("id", ({ "lurker", }));
    set("short", "%^RESET%^%^BLUE%^Swamp lurker%^RESET%^");
    set("aggressive", random(8)+5);
    set_level(my_hd);
    set_long("%^GREEN%^This creature looks like a collection of slowly moving, covered in spikes rotten vines roughly resembling a humanoid form.%^RESET%^");
    set_class("fighter");
    set_race("monstrous humanoid");
    set_body_type("human");
    set_attacks_num(my_hd/5+1);
    set_damage(3,my_hd);
    set_base_damage_type("slashing");
    set_attack_limbs(({"right hand","left hand"}));
    set_alignment(5);
    set_overall_ac(-my_hd);
    set_guild_level("fighter",my_hd);
    set_hd(my_hd,5);
    set_max_hp(my_hd*16+200);
    set_hp(my_hd*16+200);
    set_property("spell damage resistance",25);
    set_property("fire resistance",-25);
    set_mob_magic_resistance("average");
    //set_exp(3000);
    set_new_exp(my_hd,"high");
    set_stats("strength",my_hd);
    set_stats("dexterity",my_hd);
    set_stats("constitution",my_hd);
   set_max_level(20);
   set_funcs(({"special"}));
   set_func_chance(25);
}

int special(object vic)
{
    if(!objectp(TO))
        return 1;
    if(!objectp(vic))
        return 1;

    tell_room(ETO,"%^GREEN%^Lurker exhumes a cloud of spores into "+vic->QCN+"!",vic);
    tell_object(vic,"%^GREEN%^Lurker exhumes a cloud of spores into you!");

    "/std/effect/status/sickened"->apply_effect(vic,roll_dice(2,8));

    return 1;
}
