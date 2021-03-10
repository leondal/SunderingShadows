#include <std.h>
#include "../../fways.h"
inherit WEAPONLESS;

void create()
{
    object myob;
    ::create();
    set_name("dire bearhound");
    set_id(({"bearhound", "hound", "bear", "dire bearhound", "dallyhallyevil"}));

    set_short("%^RESET%^%^ORANGE%^d%^BOLD%^i%^RESET%^%^ORANGE%^r"+
    "%^BOLD%^e %^RESET%^%^ORANGE%^b%^BOLD%^ea%^RESET%^%^ORANGE%^rh"+
    "%^BOLD%^ou%^RESET%^%^ORANGE%^nd%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^This strange creature appears to be a cross "+
    "between a dire wolf and a dire bear. It is massive, almost ten feet long and "+
    "towering nearly seven feet high at the shoulders. It has the powerful snout of "+
    "a wolf with rows of vicious teeth visible within. It has a thick neck that "+
    "meets a powerful and massive body. There are numerous visible scars "+
    "all over this creature, evidence of its obvious love for battle. "+
    "A long and fluffy tail, half of it missing, completes this creature.%^RESET%^");

    set_gender("male");

    set_level(30);
    set_hd(24, 2);
    set_new_exp(25, "normal");

    set_alignment(7);
    set_size(4);
    set_overall_ac(-2);
    set_hp(300 + random(201));

    set_body_type("wolf");

    set_race("bearhound");

    add_limb("torso", 0, 0, 0, 0);
    add_limb("right foreleg", "torso", 0, 0, 0);
    add_limb("left foreleg", "torso", 0, 0, 0);
    add_limb("right claw", "right foreleg", 0, 0, 0);
    add_limb("left claw", "left foreleg", 0, 0, 0);
    add_limb("right hindleg", "torso", 0, 0, 0);
    add_limb("left hindleg", "torso", 0, 0, 0);

    set_attack_limbs(({"right claw", "left claw"}));

    set_num_attacks(4);
    set_damage(2,4);
    set_base_damage_type("slashing");

    set_stats("strength", 19);
    set_stats("dexterity", 19);
    set_stats("intelligence", 16);
    set_stats("wisdom", 14);
    set_stats("charisma", 12);
    set_stats("constitution", 21);

    set("aggressive", 30);

    set_funcs(({"bite"}));
    set_func_chance(25);

    set_property("full attacks",1);
    set_mob_magic_resistance("average");
    set_property("weapon resistance", 2);
    set_moving(1);
    set_speed(30);
    set_nogo(({DDOCK, FRPATH"road1"}));
}

void bite(object targ)
{
    string limb;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    limb = targ->return_target_limb();

    tell_object(targ, TOQCN+"%^BOLD%^%^RED%^ bites deep into your "+limb+"!%^RESET%^");

    tell_room(ETO, TOQCN+"%^BOLD%^%^RED%^ bites deep into "+targ->QCN+"%^BOLD%^%^RED%^'s"+
    " %^BOLD%^%^RED%^"+limb+"!%^RESET%^", targ);

    targ->cause_typed_damage(targ, limb, roll_dice(8, 6), "piercing");
    if(!objectp(targ)) return;
    if(roll_dice(1,20) + 12 > (int)targ->query_stats("strength") + roll_dice(1,20))
    {
        tell_object(targ, TOQCN+"%^BOLD%^%^RED%^ releases your "+limb+ " and "+
        "slams you to the ground!%^RESET%^");
        tell_room(ETO, TOQCN+"%^BOLD%^%^RED%^ releases "+targ->QCN+"%^BOLD%^%^RED%^"+
        "'s "+limb+" and slams "+targ->QO+" to the ground!%^RESET%^", targ);
        targ->set_tripped(3, "%^BOLD%^%^RED%^You struggle to regain your footing!%^RESET%^");
    }
    return;
}
