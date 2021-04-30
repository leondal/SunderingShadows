//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
//Minor tweaks to difficulty and XP to make trails on par with Yntala - Octothorpe 12/26/09

#include <std.h>
#include "../valley.h"
inherit F_WANDER;

int stench = 0;

void add_stuff();

void create(){
	::create();
	set_name("ghast");
	set_id(({"ghast","undead","monster"}));
	set_short("A putrid ghast");
	set_long(
	"The ghast looks much like a ghoul, a grotesquely disfigured"+
	" being that must once have been human. Long claws, sharp"+
	" teeth, yellow eyes, and pale skin that hangs from the bones"+
	" mark this beast as an undead. Tattered raiment barely"+
	" clings to this creature and is spattered with blood."+
	" Were it not for the horrible stench rising from the ghast"+
	" it would be hard to tell the creature from a ghoul."
	);
	set_property("undead",1);
	set_hd(15,5);
	set_max_level(14);
	set_overall_ac(0);
	set_body_type("human");
	set_race("ghast");
	set_gender("male");
	set_alignment(9);
	set_size(2);
	set_max_hp(random(40)+100);
	set_hp(query_max_hp());
	set_class("fighter");
	set_mlevel("fighter",10);
	set_level(15);
	set_stats("dexterity",13);
	set_stats("charisma",1);
//        set_exp(9500);
	set_new_exp(10,"normal");
	set_attack_limbs(({"mouth","right hand","left hand"}));
	set_attacks_num(3);
	set_base_damage_type("slashing");
	set_damage(2,3);
	add_money("copper",random(500));
	add_money("gold",random(50));
	set_property("swarm",1);
	set("aggressive",25);
    set_sight_bonus(2);
      set_resistance("negative energy",10);
      set_resistance("positive energy",-10);
	set_hit_funcs((["mouth":(:TO,"bite":)]));
	set_funcs(({"stench","paralyze"}));
	set_func_chance(10);
    add_stuff();
}

int bite(object targ)
{
	targ->do_damage("torso",random(8)+1);
	return 1;
}

void stench(object targ)
{
	int i,j;
	object *inven;

	inven = all_living(ETO);
	j = sizeof(inven);

	if(stench) {
		return 1;
	}
	else {
		for(i=0;i<j;i++) {
			if(!objectp(inven[i])) continue;
			if(inven[i] == TO) continue;

			if("/daemon/saving_throw_d.c"->fort_save(targ,-12)){
				tell_object(inven[i],"The stench of the ghast causes"+
				" you to retch it is so horrible.");
				inven[i]->add_attack_bonus(-1);
			}
			else {
				tell_object(inven[i],"You can barely keep from"+
				" retching as you smell the ghast's carrion stench.");
			}
		}
	stench = 1;
	}
}

void paralyze(object targ)
{
	if(!random(150)) {
		if("/daemon/saving_throw_d.c"->fort_save(targ,-14)){
			tell_object(targ,"%^ORANGE%^The cold touch of the ghast"+
			" causes you to become paralyzed!");
			tell_room(ETO,"%^ORANGE%^The ghast reaches out and"+
			" touches "+targ->query_cap_name()+".",targ);
			targ->set_paralyzed(random(50)+50,"You are paralyzed!");
		}
		else {
			tell_object(targ,"%^BOLD%^You grit your teeth and manage"+
			" to withstand the cold touch of the ghast.");
			tell_room(ETO,"%^ORANGE%^The ghast reaches out and"+
			" touches "+targ->query_cap_name()+".",targ);
		}
	}
}

void add_stuff()
{
	object ob;

	//::reset();
	if(!present("scroll")) {
		if(random(2)) {
			ob=new("/d/magic/scroll");
			ob->set_spell(10);
			ob->move(this_object());
		}
	}
	if(!present("gem")) {
		if(random(2)) {
			switch(random(400)) {
				case 0..300:
					new(OBJ+"gem")->move(TO);
					break;
				case 301..350:
					new(OBJ+"gem")->move(TO);
					new(OBJ+"gem")->move(TO);
					break;
				case 351..375:
					new(OBJ+"gem")->move(TO);
					new(OBJ+"gem")->move(TO);
					new(OBJ+"gem")->move(TO);
					break;
				case 376..400:
					new(OBJ+"gem")->move(TO);
					new(OBJ+"gem")->move(TO);
					new(OBJ+"gem")->move(TO);
					new(OBJ+"gem")->move(TO);
					break;
			}
		}
	}
}
