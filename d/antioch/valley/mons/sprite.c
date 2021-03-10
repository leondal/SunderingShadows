//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit VM_WANDER;

void create(){
	::create();
	set_name("sprite");
	set_id(({"sprite","monster","fairy","faerie"}));
	set_short("An adorable sprite");
	set_long(
	"This cute little sprite is barely two feet tall. He has long"+
	" pointed ears and in fact looks much like an elf, having the"+
	" typically delicate elven features. Dainty little wings are on"+
        " his back that are almost transparent. Fine veins of blue and"+
	" purple hues can be traced in the delicate pattern. His"+
	" clothing is made up of many hues of overlapping green,"+
	" creating a rather chaotic scene, but it seems to allow the"+
	" sprite to blend in with the valley. A tiny longsword is"+
	" tucked in a scabbard at his waist and he is wearing a small"+
	" shield."
	);
	set_gender("male");
	set_race("sprite");
	set_body_type("kender");
     set_hd(15,4);
	set_max_level(20);
	set_size(1);
	set_alignment(4);
	set_overall_ac(6);
	set_max_hp(random(50)+50);
	set_hp(query_max_hp());
	set_class("fighter");
     set_mlevel("fighter",15);
	set_level(15);
	set_stats("intelligence",16);
	set_stats("dexterity",20);
	set_wielding_limbs(({"left hand","right hand"}));
	set("aggressive",10);
	set_property("swarm",1);
	add_money("copper",random(6000));
	new(OBJ+"tlongsword")->move(TO);
	command("wield sword");
	new(OBJ+"sshield")->move(TO);
	command("wear shield");
//	set_exp(1570);
	set_new_exp(15,"normal");
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
}
