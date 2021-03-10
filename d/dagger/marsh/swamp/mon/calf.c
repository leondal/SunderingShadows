#include <std.h>
#include "../marsh.h"

inherit WEAPONLESS;

int level;

void create()
{
    ::create();
    set_name("calf");
    set_id(({"calf","headless calf","cow"}));
    set_short("%^RESET%^%^RED%^Headless calf%^RESET%^");
    set_long("The abomination before you is a sick sight! A small undead calf that was obviously "
        "beheaded in some gruesome freak manner. A viscous substance still leaks out of its "
        "severed neck and it's sickly skin is covered in matted dried blood and hair.");
    set_gender("male");

    set_class("fighter");

    level = 25 + roll_dice(1, 8);

    set_hd(level,12);
    set_level(level);
    set_size(2);
    set_base_damage_type("bludgeoning");
    add_limb("severed neck","torso",0,0,0);
    add_limb("right hoof","right foreleg",0,0,0);
    add_limb("left hoof","lef foreleg",0,0,0);
    set_attack_limbs(({"right hoof","left hoof","severed neck"}));
    set_overall_ac(-level);
    set_body_type("mammal");
    set_race("undead");
    set_guild_level("fighter",level);
    set_mlevel("fighter",level);
    set_alignment(6);
    set("aggressive",random(6)+7);
    set_property ("magic resistance",level);
    set_new_exp(level-4,"normal");
    set_max_hp(level * 18);
    set_hp(level * 18);
    set_max_level(36);
    set_funcs(({"moo"}));
    set_func_chance(75);
    set_property("no death", 1);
    set_property("no paralyzed",1);
    set_property("no tripped",1);
    set_speed(50);
    set_moving(1);
    set_nogo(({ROOMS"m44",ROOMS"m44.c"}));
    set_stats("strength",25);
    set_stats("dexterity",25);
    set_stats("constitution",25);
    set_stats("intelligence",25);
    set_stats("wisdom",25);
    set_stats("charisma",25);
    set_attacks_num(3);
    set_damage(1,(level/2));
    add_attack_bonus(roll_dice(1,6));
    add_damage_bonus(roll_dice(1,6));
}

void moo(object targ)
{
    int dam;

    if(!objectp(targ)) { return; }
    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }

    tell_room(ETO,"%^BOLD%^%^CYAN%^""The headless calf goes:%^RESET%^ "
        "MOO!!!\n%^RED%^"+targ->QCN+" screams in disgust and internal "
        "pain!%^RESET%^",targ);
    tell_object(targ,"%^BOLD%^%^CYAN%^"	"The headless calf goes:%^RESET%^ "
        "MOO!!!\n%^RED%^Your internal organs feel as though they just "
        "exploded!%^RESET%^");

    dam = (int)targ->query_level();
    dam = dam + random(dam) + random(20) + level;

    if(FORT(targ,-1*(level - 10))) { dam = dam/2; }

    targ->cause_typed_damage(targ, targ->return_target_limb(),dam,"force");
    TO->add_hp(dam);
}
