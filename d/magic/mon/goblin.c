//goblin.c - updated to use current code by Circe - 8/25/03
#include "summoned_monster.h"

inherit MONSTER;

void create() {
	object ob;
	::create();
	set_name("goblin");
	set_id(({"goblin","monster","vile goblin"}));
	set_race("goblin");
	set_gender("male");
	set_short("A vile goblin");
	set_long(
         "This goblin is a short, brutish looking humanoid with a flat face.  "+
         "His nose seems like it has been smeared across his face just above "+
         "his wide mouth filled with needle-like yellow teeth.  His dull, glazed "+
         "eyes are yellow-red and sparkle occasionally with the delicious thought "+
         "of inflicting pain on others."
      );
	set_level(5);
	set_body_type("human");
	set("aggressive",19);
	set_alignment(3);
	set_size(1);
	set_overall_ac(8);
	set_stats("intelligence",6);
	set_stats("wisdom",4);
	set_stats("strength",13);
	set_stats("charisma",3);
	set_stats("dexterity",16);
	set_stats("constitution",7);
	set_hd(5, 1);
	set_max_hp(query_hp());
	set_wielding_limbs( ({ "right hand", "left hand"}) );
	ob = new(WEAPONDIR+"shortsword");
	ob->set_property("monsterweapon",1);
	ob->move(TO);
	command("wield sword");
	add_money("silver",random(10));
	add_money("copper",random(20));
	set_max_level(10);
	set_exp(150);
	set_hp(random(15)+40);
}

