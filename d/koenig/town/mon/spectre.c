#include <std.h>
#include <daemons.h>

inherit MONSTER;

void create() {
  ::create();
  set_name("spectre");
  set_id( ({"spectre"}) );
  set_short("%^BOLD%^%^WHITE%^A Spooky Spectre%^RESET%^");
  set("long",
	"This spectre is no different then any other of its kind, it hates"+ 
    " all life and light. Strange that it should be here in a place teeming"+ 
	" with it." );
  set_race("spectre");
  set_gender("female");
  set_body_type("human");
  set_property("undead",1);
  set_wielding_limbs( ({"left hand", "right hand"}) );
  set_stats("strength", 15);
  set_stats("constitution", 16);
  set_stats("dexterity", 15);
  set_stats("wisdom", 18);
  set_stats("intelligence", 20);
  set_stats("charisma", 5);
  set_size(2);
  set_hd(8,3);
  set_max_hp(60);
  set_hp(60);
  set_new_exp(12, "very high");
  set_overall_ac(2);
  set_property("weakness", "raise_dead");
  set_mob_magic_resistance("average");
  set_funcs( ({"energy_drain"}) );
  set_func_chance(20);
  set("aggressive",20);
}

void energy_drain(object targ) {
	int hp_loss;
 	if(random(20)+1 > ((int)("daemon/bonus_d"->monster_thaco( TO->query_hd())) - (int)(targ->query_ac()) )){
  		if(!targ) return 0;
  		tell_room(ETO,"%^BOLD%^%^BLUE%^The spectre closes in on "+targ->query_cap_name()+" and touches them"+
  		"...draining them of their life!", targ);
  		tell_object(targ,"%^BOLD%^%^BLUE%^The spectre closes in on you and touches "
  		"you... you feel your life being slowly drained away!");
		targ->do_damage("torso",random(6)+1);
		targ->add_exp(-2000);
		
	//Stuff I stole from user.c
	//designed to decrease levels when necessary
	
		while((int)ADVANCE_D->get_exp(targ->query_level(),targ->query_class(), targ)> targ->query_exp()){
			targ->set_level((int)targ->query_level() - 1);
			hp_loss = ADVANCE_D->get_hp_bonus(targ->query_class(),targ->query_stats("constitution"),targ->query_lvl());
			targ->set_max_hp(((int)targ->query_max_hp() - hp_loss));
			targ->reduce_my_skills();
			targ->reduce_guild_level();
			if(interactive(targ)){
			ADVANCE_D->class_news(targ->query_class(), targ->query_cap_name()+" looses level to the touch of the spectre.");
		    }
		}
  	} else {
  		tell_object(targ,"The spectre misses you.");
  		say("The spectre misses "+targ->query_cap_name()+".",targ);
	}
  return 1;
}

void add_poisoning(int x) {return;}

void set_paralyzed(int x, string drow){return;}
