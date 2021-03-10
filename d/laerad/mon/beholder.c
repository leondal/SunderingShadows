//beholder.c

#include <std.h>

#include <daemons.h>
// inherit "/d/laerad/mon/wander/bewander.c";
inherit MONSTER;

int count;
int eyes, i;

void do_eyes(object targ);

void create(){
	::create();

	set_name("beholder");
	set("id",({"beholder","Beholder","eye"}));
	set("short","Beholder, the Eye Tyrant");
	set("long",
@OLI
	This spheroid hangs in the air before you. A large protuding
eye dominates the front of the sphere. Ten sinuous eye stalks sit
upon the top of the sphere. A large toothy maw gapes open at the bottom
of the sphere. In a word you should be ....%^BOLD%^%^YELLOW%^AFRAID%^RESET%^
OLI
	);
	set_hd(random(5) +20,1);
	set_hp(query_hd() * 10);
	set_exp(16500);
	set_race("beholder");
	add_limb("body","body",query_hp(),0,0);
	add_limb("mouth","mouth",query_hp(),0,0);
	add_limb("stalk 1","stalk 1",query_hp(),0,0);
	add_limb("stalk 2","stalk 2",query_hp(),0,0);
	add_limb("stalk 3","stalk 3",query_hp(),0,0);
	add_limb("stalk 4","stalk 4",query_hp(),0,0);
	add_limb("stalk 5","stalk 5",query_hp(),0,0);
	add_limb("stalk 6","stalk 6",query_hp(),0,0);
	add_limb("stalk 7","stalk 7",query_hp(),0,0);
	add_limb("stalk 8","stalk 8",query_hp(),0,0);
	add_limb("stalk 9","stalk 9",query_hp(),0,0);
	add_limb("stalk 10","stalk 10",query_hp(),0,0);
    set_property("wandermon", 1);
	set_stats("strength",15);
    set_property("magic",1);
	set_stats("dexterity",7);
	set_stats("constitution",18);
	set_stats("charisma",0);
	set_stats("intelligence",16);
	set_stats("wisdom",18);
	set_overall_ac(2);
	set("aggressive",22);
	set_property("no steal",1);
	set_property("no stab",random(2));
	set_funcs(({"attack"}));
	set_func_chance(102);
//        if(!random(10)) new("/d/laerad/obj/free_ring")->move(this_object());
    set_moving(1);
    set_speed(15);
}

void attack(object targ){
    int damage;
    if(!objectp(TO) && !objectp(targ)) { return; }

    count++;
    switch (count){
      case 1:
        if(random(20)+1 > (int)("daemon/bonus_d"->monster_thaco(TO->query_hd())) - (int)(targ->query_ac())){
          damage = roll_dice(2,4);
          targ->do_damage(targ->return_target_limb(),damage);
          TO->send_messages(0,0,targ->return_target_limb(),damage,targ);
        } else {
          tell_object(targ,"The beholder misses you.");
          tell_room(environment(TO),"The beholder misses "+targ->query_cap_name()+"1",targ);
        }
        execute_attack();
        return;
        break;

      case 2:
        eyes = random(6)+1;
        i = random(eyes)+1;
        if(!present(targ->query_name(),environment(TO)))
          break;

        do_eyes(targ);
        i--;
        if(i)
          execute_attack();
        else {
          count = 0;
          return;
        }
        break;

      default:
        if(!present(targ->query_name(),environment(TO)))
          break;
        do_eyes(targ);
        i--;
        if(i)
          execute_attack();
        else {
          count = 0;
          return;
        }
        break;
    }
    return;
}

void do_eyes(object targ){
	int j;
    if(!objectp(TO) && !objectp(targ)) { return; }
	j = random(8);
	switch (j){
		case 0:
			"cmds/spells/m/_monster_summoning_i"->use_spell(TO,targ->query_name(),10,100,"mage");
			break;
		case 1:
			"cmds/spells/c/_color_spray"->use_spell(TO,targ->query_name(),10,100,"mage");
			break;
		case 2:
			"cmds/spells/s/_sleep"->use_spell(TO,targ->query_name(),20,100,"mage");
			break;
		case 3:
			"cmds/spells/c/_cause_serious_wounds"->use_spell(TO,targ->query_name(),10,100,"cleric");
			break;
		case 4:
			tell_object(targ,"%^BOLD%^%^YELLOW%^The eye sends a ray of fear hurtling toward you!\n");
			tell_room(environment(TO),"%^BOLD%^%^YELLOW%^The eye sends a ray of fear toward "+targ->query_cap_name()+"!",targ);
			if(!SAVING_D->saving_throw(targ,"rod_staff_wand"))
				targ->run_away();
			break;
		case 5:
			"cmds/spells/d/_dispel_magic"->use_spell(TO,targ->query_name(),10,100,"mage");
			break;
		case 6:
			tell_object(targ,"%^BOLD%^%^YELLOW%^The eye take all of your items and makes you drop them with his telekinetic powers!\n");
			tell_room(environment(TO),"%^BOLD%^%^YELLOW%^The eye forces "+targ->query_cap_name()+" to drop "+targ->query_posssessive()+" inventory using it's telekinetic powers!",targ);
			targ->force_me("drop all");
			break;
		case 7:
			tell_object(targ,"%^BOLD%^%^YELLOW%^The eye sends it's dreaded death ray streaking toward you!!!\n");
			tell_room(environment(TO),"%^BOLD%^%^YELLOW%^The eye sends it's dreaded death ray streaking toward "+targ->query_cap_name()+"!!!",targ);
                        "/std/effect/status/cowering"->apply_effect(targ,roll_dice(1,4));
                        targ->do_damage(targ->return_target_limb(),100);
			break;
		default: break;
	}
}

void set_paralyzed(int time, string message){
	return;
	}
