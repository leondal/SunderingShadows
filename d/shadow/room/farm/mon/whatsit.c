#include <std.h>
#include "../farm.h"

inherit WEAPONLESS;
      create(){
      object obj; 
      ::create();
	set_name("whatsit");
	set_id(({"whatsit", "wooden contraption", "farm_mon"}));
	set_short("Whatsit - A wooden contraption");
	set_long("%^ORANGE%^The barrel shaped golden "+
		"chestnut body of this contraption rests "+
		"firmly on the ground.  Rings of bronze wrap"+
		" around the barrel, giving it some stability.  "+
		"Odd gears and belts are attached to the inside "+
		"and outside of the barrel, leading one to think "+
		"this is yet another gnomish contraption.  Six arm"+
		" like appendages fashioned from a mixture of metal"+
		" and wood stick out of the man-sized barrel.  A "+
		"small rectangular box off to one side of the barrel"+
		" is covered with numerous levers and button.%^RESET%^");
	set_race("whatsit");
	set_gender("neuter");
	set_body_type("snake");
	set_overall_ac(-1);
	set_hd(11,0);
	set_class("fighter");
	set_mlevel("fighter",11);
	set_level(11);
	set_guild_level("fighter",10);
	set_size(2);
	set_max_level(15);
	set_stats("strength",16);
	set_stats("intelligence",1);
	set_stats("dexterity",8);
	set_stats("charisma",1);
	set_stats("constitution",18);
	set_stats("wisdom",1);
	set_alignment(5);
	set_mob_magic_resistance("average");
	set_property("full attacks",1);
	add_search_path("/cmds/fighter");
	remove_limb("tail");
	remove_limb("head");
	remove_limb("mouth");
	add_limb("oak arm","torso",0,0,0);
      add_limb("walnut arm","torso",0,0,0);
      add_limb("spruce arm","torso",0,0,0);
	add_limb("willow arm","torso",0,0,0);
      add_limb("cypress arm","torso",0,0,0);
      add_limb("sycamore arm","torso",0,0,0);
	set_attack_limbs(({"oak arm","walnut arm","spruce arm","willow arm","cypress arm","sycamore arm"}));
	set_attacks_num(3);
      set_base_damage_type("bludgeoning");
     	set_damage(1,2);
	set_funcs(({"arm1","arm2","arm3","arm4","arm5","arm6"}));
	set_func_chance(30);
	set_max_hp(random(50)+100);
      set_hp(query_max_hp());
      set_property("swarm",1);
      set("aggressive",18);
	add_attack_bonus(2);
	set_property("no dominate",1);
	set_property("no trip",1);
	set_property("no paralyze",1);
	set_exp(random(500)+1000);
	set_languages( ({ "common" }) );
}
void arm1(object targ)
{
	if(!"daemon/saving_d"->saving_throw(targ,"spell",-1)) {
    		tell_object(targ,"%^ORANGE%^The wooden mallet held by the oak"+
			" arm conks you upside the head!");
     		tell_room(ETO,"%^ORANGE%^The oak arm of the Whatsit conks"+
			" "+targ->QCN+" with its wooden mallet.",targ);
    				targ->do_damage("torso",random(8)+2);
        	return 1;
	}
else {
    	tell_object(targ,"%^ORANGE%^You dive just in time to avoid getting"+
		" conked on the head by the oak arm.");
     	tell_room(ETO,"%^ORANGE%^"+targ->QCN+" dives low as the oak arm of"+
		" the Whatsit swings at "+targ->QS+".",targ);
	return 1;
}
}
void arm2(object targ)
{
if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
    	tell_object(targ,"%^BLUE%^A vat of water slides out from inside the"+
		" Whatsit.  Grabbing you with its willow arm, the Whatsit dunks"+
		" you into the water and begins to wash you!");
     	tell_room(ETO,"%^BLUE%^A vat of water slides out from inside the Whatsit.  "+
		"Grabbing "+targ->QCN+" with its willow arm, the Whatsit dunks "+
		""+targ->QO+" in the water and begins to wash "+targ->QO+".",targ);
    	targ->set_paralyzed(25,"%^BOLD%^%^BLUE%^You are being washed right now.");
        		return 1;
}
else {
    	tell_object(targ,"%^BOLD%^%^BLUE%^A vat of water slides out"+
		"from inside the Whatsit and splashes you.");
     	tell_room(ETO,"%^BOLD%^%^BLUE%^A vat of water slides out from "+
		"inside the Whatsit and splashes "+targ->QCN+".",targ);
			return 1;
     }
}
void arm3(object targ)
{
    	tell_object(targ,"%^GREEN%^Chopping the grass with the shears "+
		"held by the sycamore arm, the Whatsit accidently cuts you!");
     	tell_room(ETO,"%^GREEN%^"+targ->QCN+" gets sliced by the sycamore arm"+
		" as it chops the grass with a pair of shears.",targ);
    			targ->do_damage("torso",random(6)+2);
   	return 1;
}
void arm4(object targ)
{
    	tell_object(targ,"%^YELLOW%^The walnut arm approaches "+
		"you with a hairbrush"+
		" in hand and gives your hair a savage brushing!");
     	tell_room(ETO,"%^YELLOW%^"+targ->QCN+" is savagely brushed by"+
		" the walnut arm of the Whatsit!",targ);
    			targ->do_damage("torso",random(4)+2);
   	return 1;
}
void arm5(object targ)
{
    	tell_object(targ,"%^RED%^The cypress arm mistakes you for a butter"+
		" churn and begins to violently shake you!");
     	tell_room(ETO,"%^RED%^The cypress arm of the Whatsit violently "+
		""+targ->QCN+" as if trying to make butter out of "+
		""+targ->QO+".",targ);
    			targ->do_damage("torso",random(3)+3);
   	return 1;
}

void arm6(object targ)
{
    	tell_object(targ,"%^BOLD%^%^GREEN%^The spruce arm picks you up "+
		"and starts to sweep the ground using your head!");
     	tell_room(ETO,"%^BOLD%^%^GREEN%^The spruce arm of the Whatsit picks "+
		""+targ->QCN+" up and begins to sweep the ground with "+
		""+targ->QP+" head.",targ);
    			targ->do_damage("torso",random(5)+3);
   	return 1;
}

void die(object obj) {
	tell_room(ETO,"%^BOLD%^%^ORANGE%^Smoke rolls out of the Whatsit as it suddenly jerks and stops.");
    	::die(obj);
}
