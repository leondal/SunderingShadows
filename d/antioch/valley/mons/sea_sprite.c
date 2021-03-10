//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13


#include <std.h>
#include "../valley.h"
inherit SM_WANDER;

void create(){
	::create();
	set_name("sea sprite");
	set_id(({"sea sprite","sprite","monster","fey"}));
	set_short("A shy sea sprite");
	set_long(
	"The shy little sprite is rather cute. She has a very"+
	" cheerful face with round, rosy cheeks. Her eyes are wide"+
	" and rather fish-like, but innocent as a child's. Her hair"+
	" looks like seaweed and probably allows her to blend in"+
	" better underwater. A set of gills can be seen on her neck,"+
	" they allow her to breath in air as well as water. Her skin"+
	" is a light blue shade and she has webbing between her toes"+
	" and fingers. She is wearing a pair of eelskin jerkins and"+
	" several little sea-shell trinkets."
	);
	set_gender("female");
	set_race("sprite");
	set_body_type("kender");
	set_hd(10,5);
	set_max_level(20);
	set_overall_ac(6);
	set_alignment(8);
	set_max_hp(random(20)+50);
	set_hp(query_max_hp());
	set_size(1);
	set_level(15);
//	set_exp(1450);
	set_new_exp(10,"normal");
	set_class("fighter");
	set_mlevel("fighter",10);
	set_stats("dexterity",19);
	add_money("copper",random(5000));
	add_money("copper",random(2000));
	add_money("electrum",random(400));
	add_money("silver",random(500));
	set_property("swarm",1);
	if(!random(5)) {
		new(OBJ+"ornaments")->move(TO);
		command("wearall");
	}
	if(!random(6)) {
		new(OBJ+"sprite_bow")->move(TO);
	}
	new(OBJ+"sspear")->move(TO);
	command("wield spear");
	new(OBJ+"sprite_arrows")->move(TO);
}

//invis at will\\

void init()
{
	object ob;

	::init();
	if(ALIGN->is_evil(TP) && !TP->query_invis()) {
		kill_ob(TP,1);
		return 1;
	}
}

void reset()
{
	::reset();
	if(!present("gem")) {
		if(!random(2)) {
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
