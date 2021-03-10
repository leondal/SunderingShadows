//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13

#include <std.h>
#include "../valley.h"
inherit WEAPONLESS;

void add_stuff();

void create(){
	::create();
	set_name("gorgon");
	set_id(({"gorgon","monster","bull","magical beast"}));
	set_short("A huge gorgon");
	set_long(
	"The gorgon stomps restlessly in front of you. He is"+
	" basically a bull with thick %^BOLD%^%^BLACK%^black metal"+
	" scales%^RESET%^%^CYAN%^ for a hide. His eyes are an angry"+
	" %^RED%^red%^CYAN%^. He snorts a noxious %^GREEN%^green%^CYAN%^"+
	" vapor from his nose. He is obviously very angry."
	);
	set_race("bull");
	set_gender("male");
	set_body_type("equine");
	set_hd(20,8);
	set_max_level(25);
	set_overall_ac(2);
	set_alignment(8);
	set_max_hp(random(150)+300);
	set_hp(query_max_hp());
	set_level(25);
	set_class("fighter");
	set_mlevel("fighter",20);
	set_stats("strength",20);
	set("aggressive",25);
	set_property("swarm",1);
   set_property("no bows",1);
//	set_exp(15000);
	set_new_exp(20,"normal");
	set_attack_limbs(({"right fore hoof","left fore hoof"}));
	set_attacks_num(2);
	set_base_damage_type("bludgeoning");
	set_damage(2,4);
	set_funcs(({"breath"}));
	set_func_chance(20);
	add_money("copper",random(6000));
	add_money("electrum",random(500));
	add_money("gold",random(300));
	add_money("silver",random(750));
    add_stuff();
}

void add_stuff()
{
	object ob;

	//::reset();
	if(!present("scroll")) {
		if(random(4)) {
			ob=new("/d/magic/scroll");
			ob->set_spell(9);
			ob->move(this_object());
			return 1;
		}
	}
	if(!present("gem")) {
		if(random(6)) {
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
		if(!random(9)) {
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

void breath(object targ)
{
	int i,j;
	object *inven;

	inven = all_living(ETO);
	j = sizeof(inven);

	tell_room(ETO,"%^BOLD%^%^GREEN%^The gorgon snorts and blasts"+
	" the room with a noxious green vapor!");
	for(i=0;i<j;i++) {
		if(!objectp(inven[i])) continue;
		if(inven[i] == TO) continue;

		tell_object(inven[i],"%^BOLD%^%^GREEN%^The vapor surrounds"+
		" you, you try not to breath it in but you can't help it.");
		if(!"daemon/saving_d"->saving_throw(inven[i],"petrification_polymorph")) {
			inven[i]->do_damage("torso",(random(10)+10)*2);
			inven[i]->set_paralyzed((roll_dice(1,4)*8),"The gorgon's"+
			" breath has begun turning you to stone!");
		}
		else {
			inven[i]->do_damage("torso",random(15)+15);
		}
	}
}
