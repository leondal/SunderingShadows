#include <std.h>
#include <daemons.h>
inherit MONSTER;

int dlevel;

create() {
    	::create();
	set_name("orc");
	set_id( ({ "orc" }) );
	set_race("orc");
	set_gender("male");
	set_short("A hardened orc officer");
	set_long("This is an elite officer of the orc regiment.\n");
	dlevel = random(3) + 7;
	set_level(dlevel);
	set_body_type("human");
  	set("aggressive",20);
  	set_alignment(3);
  	set_size(2);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",15);
   	set_stats("charisma",3);
   	set_stats("dexterity",12);
   	set_stats("constitution",15);
	set_hd(dlevel, 10);
   	set_max_hp(20+(dlevel * (random(10) + 3)));
   	set_hp(query_max_hp());
   	set_max_level(9);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        	new("/d/common/obj/weapon/two_hand_sword")->move(TO);
      	command("wield sword in right hand and left hand");
        	new("/d/common/obj/armour/ring")->move(TO);
      	command("wear armor");
	add_money("gold",random(15) * dlevel);
	add_money("silver",random(10) * dlevel);
	//set_exp(dlevel * 30);
   	set_exp(dlevel * 100);
}
