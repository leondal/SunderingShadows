#include <std.h>
#include "../undead.h"

inherit CREATURE;

void create() 
{
    ::create();
    set_name("golem");
    set_id(({"golem"}));
    set_short("%^BOLD%^%^RED%^Golem");
    set_long("%^RED%^This is one of Kartakass's guardians, a golem shaped "
        "as a tall, impressive, warrior.  They heed only the work of "
        "Kartakass, and will only do his bidding.  Beware, for they "
        "are fearsome fighters indeed, well known for crushing any enemy "
        "of their dark master.%^RESET%^");
    set_race("golem");
    set_body_type("humanoid");
    set_gender("male");
    set_hd(20,8);
    set_size(3);
    set_overall_ac(-5);
    set_hp(400);
    set_property("swarm",1);
    add_limb("right fist", "right hand", 0, 0, 0);
    add_limb("left fist", "left hand", 0, 0, 0);
    set_attack_limbs(({"right fist","left fist"}));
    set_attacks_num(2);
    set_damage(3,10);
    set_base_damage_type("bludgeoning");
    set_property("swarm",1);
    set_stats("strength",22);
    set_stats("dexterity",5);
    set_stats("constitution",20);
    set("aggressive",20);
    set_exp(25000);
    set_new_exp(25,"very high");
    set_alignment(5);
    set_funcs(({"break_em"}));
    set_func_chance(10);
}

void break_em(object targ)
{
    tell_object(targ,"%^BOLD%^%^RED%^The Golem picks you up and begins tearing you in two!");
    tell_room(environment(targ),"%^BOLD%^%^RED%^The Golem picks up "+targ->QCN+" and "
        "begins tearing "+targ->QO+" in two!");

    if(!ROLLSAVE(targ,PPD))
    {
        tell_object(targ,"%^BOLD%^%^RED%^\nYou scream in pain as your spine begins to creak and pop!");
        tell_room(environment(targ),"%^BOLD%^%^RED%^"+targ->QCN+" screams in pain as "
            ""+targ->QP+" spine is twisted and bent!");
        set_property("magic",1);
        targ->do_damage("torso",roll_dice(10,20));
        set_property("magic",-1);
        set_func_chance(0);
        call_out("reset_break",250);
        return;
    }
      
    tell_object(targ,"%^BOLD%^%^RED%^\nYou manage to struggle out of the Golem's grip.");
    targ->do_damage("torso",roll_dice(3,8));
    set_func_chance(0);
    call_out("reset_break",50);
    return;
}

void reset_break_em() { set_func_chance(10); return; }
