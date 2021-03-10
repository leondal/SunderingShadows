//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit WEAPONLESS;

void create(){
      object ob;
	::create();
	set_name("owlbear");
	set_id(({"owlbear","monster","owl","bear","magical beast"}));
	set_short("An enormous owlbear");
	set_long(
	"Very well named, this beast looks exactly like a cross"+
	" between an owl and a bear. It has the furr and body of"+
	" a bear with the claws and head of an owl. The beast is"+
	" huge and it looks rather crazed and deadly. Its yellow"+
	" beak is sharp and the creature would probably love to have"+
	" you as a snack."
	);
	set_race("owlbear");
	set_gender("male");
	set_body_type("quadruped");
	set_hd(10,10);
	set_max_level(25);
	set_size(3);
	set_alignment(8);
	add_limb("beak","head",0,0,0);
	add_limb("tail","torso",0,0,0);
	add_limb("right claw","right forepaw",0,0,0);
	add_limb("left claw","left forepaw",0,0,0);
	set_overall_ac(5);
	set_max_hp(random(50)+100);
	set_hp(query_max_hp());
	set_attack_limbs(({"beak","right claw","left claw"}));
	set_attacks_num(3);
	set_base_damage_type("slashing");
	set_damage(1,6);
	set_level(20);
	set_class("fighter");
	set_mlevel("fighter",10);
	set_stats("intelligence",5);
	set_stats("strength",20);
	set("aggressive",25);
	set_property("swarm",1);
   set_property("no bows",1);
//	set_exp(15400);
	set_new_exp(10,"normal");
	set_funcs(({"hug"}));
	set_func_chance(20);
	add_money("silver",random(400));
	add_money("copper",random(12000));
	add_money("copper",random(600));
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("fur");
      ob->move(TO);
    }
}

void hug(object targ)
{
	int roll,ac;

	roll = random(20);
	ac = targ->query_ac();
	if(roll > 10-ac) {
		tell_object(targ,"%^ORANGE%^The owlbear pulls you into a ferocious hug.");
		tell_room(ETO,"%^ORANGE%^The owlbear pulls "+targ->query_cap_name()+""+
		" into a ferocious hug.",targ);
		targ->do_damage("torso",random(10)+2);
	}
	else {
		tell_object(targ,"%^ORANGE%^The owlbear takes a swipe"+
		" at you and misses.");
		tell_room(ETO,"%^ORANGE%^The owlbear takes a swipe at"+
		" "+targ->query_cap_name()+" and misses.",targ);
	}
}

void reset()
{
	::reset();
	if(!present("gem")) {
		if(!random(4)) {
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
                                case 376..399:  // was 400, outside range *Styx* 12/05
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
                                case 176..199:   // was 200, outside of range *Styx* 12/05
					new(OBJ+"jewelry")->move(TO);
					new(OBJ+"jewelry")->move(TO);
					new(OBJ+"jewelry")->move(TO);
					break;
			}
		}
	}
}
