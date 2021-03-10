//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
//Minor tweaks to difficulty and XP to make trails on par with Yntala - Octothorpe 12/26/09

#include <std.h>
#include "../valley.h"
inherit F_WANDER;

void create(){
      object ob;
	::create();
	set_name("heucuva");
	set_id(({"heucuva","undead","monster","spirit","skeletal figure","figure"}));
	set_short("A skeletal figure");
	set_long(
	"Tattered robes cover most of the heucuva's body, barely"+
	" concealing the skeletal form beneath. A skull can be"+
	" seen from beneath the dirty cloth, eye sockets empty and"+
	" the mouth grinning evilly."
	);
	set_gender("male");
	set_race("spirit");
	set_body_type("human");
	set_size(2);
	set_property("undead",1);
	set_hd(20,6);
	set_max_level(15);
	set_alignment(9);
	set_overall_ac(-3);
	set_level(14);
	set_class("fighter");
	set_mlevel("fighter",20);
	set_max_hp(random(20)+140);
	set_hp(query_max_hp());
	set("aggressive",25);
	set_property("swarm",1);
	set_property("weapon resistance",1);
	add_money("silver",random(2000));
//        set_exp(9500);
	set_new_exp(20,"normal");
	new(OBJ+"tcloak")->move(TO);
	command("wear cloak");
	new(OBJ+"trobes")->move(TO);
	command("wear robes");
	set_attack_limbs(({"right hand","left hand"}));
	set_attacks_num(2);
	set_base_damage_type("slashing");
	set_damage(1,8);
	set_hit_funcs(([
		"right hand":(:TO,"con_drain":),
		"left hand":(:TO,"dex_drain":)
	]));
    if(!random(15)) {
      ob = new("/d/common/obj/brewing/herb_special_inherit");
      ob->set_herb_name("bone dust");
      ob->move(TO);
    }
      set_resistance("negative energy",10);
      set_resistance("positive energy",-10);
}

int con_drain(object targ)
{
	if(!random(3)) {
	    if(!targ->query_stat_bonus("constitution")) return 1;
	    if((int)targ->query_stat_bonus("constitution") < -1) return 0;
		if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-11)){
			tell_object(targ,"%^BOLD%^%^RED%^You feel weaker after"+
			" the heucuva's touch.");
			tell_room(ETO,"%^BOLD%^%^RED%^"+targ->query_cap_name()+""+
			" looks a little weak.",targ);
			targ->add_stat_bonus("constitution",-1);
			return 1;
		}
		else {
			return 1;
		}
		return 1;
	}
}

int dex_drain(object targ)
{
	if(!random(3)) {
	    if(!targ->query_stat_bonus("dexterity")) return 1;	
	    if((int)targ->query_stat_bonus("dexterity") < -1) return 0;
		if(!"/daemon/saving_throw_d.c"->reflex_save(targ,-11)){
			tell_object(targ,"%^YELLOW%^You feel a little less"+
			" agile after the heucuva's touch.");
			tell_room(ETO,"%^YELLOW%^"+targ->query_cap_name()+""+
			" seems a little out of it.",targ);
			targ->add_stat_bonus("dexterity",-1);
			return 1;
		}
		else {
			return 1;
		}
		return 1;
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
