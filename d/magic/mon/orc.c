//orc.c - updated to use current code by Circe - 8/27/03
#include "summoned_monster.h"
inherit MONSTER;

void create(){
	object ob;
	::create();
	set_name("orc");
	set_id(({"orc","Orc","old orc","monster"}));
	set_short("An old Orc");
	set_long(
         "This aged creature looks like a primative human except for his "+
         "mottled gray skin, low forehead, and the two tusks jutting up from "+
         "his lower jaw.  His lupine ears are covered with long, coarse hairs, "+
         "and his unfocused eyes are a milky red.  His threadbare clothing was "+
         "originally brightly colored, but has now been riddled with holes and "+
         "stained beyond recognition.  Despite his age, he still seems ready enough "+
         "to use the battle axe he carries."
	);
	set_race("orc");
	set_gender("male");
	set_body_type("human");
	set_hd(6,0);
	set_overall_ac(6);
	set_size(2);
	set_stats("strength",12);
	set_stats("intelligence",8);
	set_stats("dexterity",10);
	set_stats("charisma",2);
	set_stats("constitution",10);
	set_stats("wisdom",5);
	set_money("silver",random(100));
	set_class("fighter");
	set_max_hp(50);
	set_hp(50);
	set_exp(50);
	set("aggressive",5);
	set_wielding_limbs(({"right hand","left hand"}));
	ob = new(CWEAP"battle_axe.c");
	ob->set_property("monsterweapon",1);
	ob->move(TO);
	command("wield axe in left hand");
   set_max_level(10);
}

