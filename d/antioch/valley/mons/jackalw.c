//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit WEAPONLESS;

int gaze = 0;

void create(){
	::create();
	set_name("jackalwere");
	set_id(({"jackalwere","jackal","were jackal","monster","magical beast"}));
	set_short("A tricky jackalwere");
	set_long(
	"The creature before you is a jackalwere, a hybrid between"+
	" a jackal and a human. The beast stands erect and is covered"+
	" with the furr of a jackal and bulging muscles. His hands"+
	" and feet are closer to that of a man except for their"+
	" large claws. The face of the beast is mostly a jackal"+
	" but the eyes have an eerie human intelligence."
	);
	set_race("jackalwere");
	set_body_type("fhuman");
	set_hd(20,5);
	set_max_level(22);
	set_size(2);
	set_overall_ac(4);
	set_max_hp(random(25)+70);
	set_hp(query_max_hp());
//	set_exp(18000);
	set_new_exp(20,"normal");
	set_alignment(9);
	set_property("weapon resistance",2);
   set_property("no bows",1);
	set("aggressive",25);
	set_property("swarm",1);
	add_limb("left claws","left hand",0,0,0);
	add_limb("right claws","right hand",0,0,0);
	set_attack_limbs(({"left claws","right claws"}));
	set_attacks_num(2);
	set_base_damage_type("slashing");
	set_damage(2,4);
	set_level(20);
	set_class("fighter");
	set_mlevel("fighter",20);
	set_stats("dexterity",20);
	set_stats("strength",19);
	set_funcs(({"gaze"}));
	set_func_chance(10);
	add_money("copper",random(9000)+1000);
	add_money("copper",random(800)+200);
   if(!random(3)) {
     new(OBJ+"hematite_ring")->move(TO);
      command("wear ring");
   }
}

void gaze(object targ)
{
	if(gaze) {
		return 1;
	}
	else {
		if(!"/daemon/saving_throw_d.c"->will_save(targ,-15)){
			tell_object(targ,"%^BOLD%^The jackalwere gazes deeply"+
			" into your eyes and you fall fast asleep.");
			tell_room(ETO,"%^BOLD%^The jackalwere gazes into"+
			" "+targ->query_cap_name()+"'s eyes and"+
			" "+targ->query_subjective()+" falls fast asleep.",targ);
			targ->set_paralyzed(random(50)+100,"You are fast asleep!");
		}
		else {
			tell_object(targ,"%^BOLD%^The jackalwere fixes you with"+
			" his magical gaze but you manage to stay awake!");
			tell_room(ETO,"%^BOLD%^The jackalwere gazes at"+
			" "+targ->query_cap_name()+".",targ);
		}
		gaze = 1;
	}
}

void reset()
{
	::reset();
	if(!present("gem")) {
		if(random(4)) {
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
	if(!present("jewelry")) {
		if(!random(5)) {
			switch(random(200)) {
				case 0..100:
					new(OBJ+"jewelry")->move(TO);
					break;
				case 101..175:
					new(OBJ+"jewelry")->move(TO);
					new(OBJ+"jewelry")->move(TO);
					break;
				case 176..200:
					new(OBJ+"jewelry")->move(TO);
					new(OBJ+"jewelry")->move(TO);
					new(OBJ+"jewelry")->move(TO);
					break;
			}
		}
	}
}
