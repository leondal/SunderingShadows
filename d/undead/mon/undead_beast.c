//Coded by the one and only master of monsters...BANE//
#include <std.h>
#include "../undead.h"

inherit CREATURE;

void cage(object targ, int num);

void create()
{
    ::create();
    set_id(({"beast","Undead Beast"}));
    set_name("Undead Beast");
    set_short("An Undead Beast");
    set_long("The size of a small dragon, the beasts bones protrude "
	    "from rotting flesh. It has a great horned head, and its "
	    "ribs are bare and barbed, forming a nasty cage. It walks "
	    "on all fours, but can rear up on its hind legs, balancing "
	    "with its stubby tail. Its forearms end in massive claws "
	    "capable of rending to pieces most living creatures.");
    set_body_type("dragon");
    set_race("undead beast");
    set_gender("male");
    set_alignment(9);
    set_size(3);
    set_hd(30,8);
    set_mlevel("fighter",30);
    set_hp(500+random(500));
    set_stats("strength",22);
    set_stats("dexterity",19);
    set_exp(35000);
    set_new_exp(25,"boss");
    set_speed(50);
    nogo("one");
    set_overall_ac(-3);
    set("aggressive",22);
    set_mob_magic_resistance("average");
    set_damage(1,12);
    set_attacks_num(5);
    set_base_damage_type("piercing");
    set_property("full attacks",1);
    add_limb("tooth filled maw", "head", 0, 0, 0);
    add_limb("right front claw", "right foreleg", 0, 0, 0);
    add_limb("left front claw", "left foreleg", 0, 0, 0);
    add_limb("right rear claw", "right rear leg", 0, 0, 0);
    add_limb("left rear claw", "left rear leg", 0, 0, 0);
    add_limb("right skeletal wing", "right wing", 0, 0, 0);
    add_limb("left skeletal wing", "left wing", 0, 0, 0);
    add_limb("spiked tail", "tail", 0, 0, 0);
    set_attack_limbs(({"tooth filled maw",
                       "right front claw",
                       "left front claw",
                       "right rear claw",
                       "left rear claw",
                       "right skeletal wing",
                       "left skeletal wing",
                       "spiked tail"
                    }));

    set_funcs(({"trample"}));
    set_func_chance(30);
    set_resistance("negative energy",10);
    set_resistance("positive energy",-10); 
}

void trample(object targ)
{

    if(roll_dice(4,6) > targ->query_stats("dexterity"))
    {
	    tell_object(targ,"%^BOLD%^RED%^The Undead Beast charges towards you and tramples "
            "you underneath it!");
	    tell_room(ETO,"%^BOLD%^RED%^The Undead Beast charges towards "+targ->QCN+" and "
            "tramples "+targ->QO+" underneath it!",targ);
	    targ->do_damage("torso",roll_dice(3,8));
	
        if(!ROLLSAVE(targ,PPD))
        {
	        targ->do_damage("torso",roll_dice(2,8));
	        if(!ROLLSAVE(targ,RSW))
            {
		        tell_object(targ,"%^BOLD%^RED%^You are ensnared in the Beasts rib cage!");
		        tell_room(ETO,"%^BOLD%^RED%^"+targ->QCN+" is ensnared in the Beasts rib cage!",targ);
                targ->set_paralyzed(30,"You are ensnared in the Beast's rib cage!");
                TO->remove_attacker(targ);
                targ->remove_attacker(TO);
		        set_func_chance(0);
		        cage(targ,0);
	        }
	        return 1;
	    }
	    return 1;
    }
    tell_object(targ,"%^BOLD%^RED%^The Undead Beast charges at you and runs right past!");
    tell_room(ETO,"%^BOLD%^RED%^The Undead Beast charges at "+targ->QCN+" and runs "
        "right past!",targ);
    return 1;
}

void cage(object targ, int num)
{
    if(!objectp(TO))    { targ->set_paralyzed(0); return; }
    if(!objectp(targ))  { return; }

    switch( num )
    {
	case(0):
	    tell_object(targ,"The Undead Beasts ribs tear into you!");
	    tell_room(ETO,""+targ->QCN+" struggles inside the Undead Beasts rib cage!",targ);
	    targ->do_damage(targ->return_target_limb(),roll_dice(3,8));
        targ->set_paralyzed(0);
        targ->set_paralyzed(30,"You are ensnared in the Beast's rib cage!");
        TO->remove_attacker(targ);
        targ->remove_attacker(TO);
	    break;
	case(1):
	    tell_object(targ,"The Undead Beasts ribs tear into you!");
	    tell_room(ETO,""+targ->QCN+" struggles inside the Undead Beasts rib cage!",targ);
	    targ->do_damage(targ->return_target_limb(),roll_dice(3,8));
        targ->set_paralyzed(0);
        targ->set_paralyzed(30,"You are ensnared in the Beast's rib cage!");
        TO->remove_attacker(targ);
        targ->remove_attacker(TO);
	    break;
	case(2):
	    tell_object(targ,"The Undead Beasts ribs tear into you!");
	    tell_room(ETO,""+targ->QCN+" struggles inside the Undead Beasts rib cage!",targ);
	    targ->do_damage(targ->return_target_limb(),roll_dice(3,8));
        targ->set_paralyzed(0);
        targ->set_paralyzed(30,"You are ensnared in the Beast's rib cage!");
        TO->remove_attacker(targ);
        targ->remove_attacker(TO);
	    break;
	case(3):
	    tell_object(targ,"The Undead Beasts ribs tear into you!");
	    tell_room(ETO,""+targ->QCN+" struggles inside the Undead Beasts rib cage!",targ);
	    targ->do_damage(targ->return_target_limb(),roll_dice(3,8));
        targ->set_paralyzed(0);
        targ->set_paralyzed(30,"You are ensnared in the Beast's rib cage!");
        TO->remove_attacker(targ);
        targ->remove_attacker(TO);
	    break;
	case(4):
	    tell_object(targ,"The Undead Beasts ribs tear into you!");
	    tell_room(ETO,""+targ->QCN+" struggles inside the Undead Beasts rib cage!",targ);
	    targ->do_damage(targ->return_target_limb(),roll_dice(3,8));
        targ->set_paralyzed(0);
        TO->kill_ob(targ);
	    tell_object(targ,"You fall from the Beast's ribs.");
	    tell_room(ETO,""+targ->QCN+" falls from the Beast's ribs.",targ);
    	set_func_chance(30);
	    return;
    }
    num++;
    call_out("cage",8,targ,num);
    return;
}
