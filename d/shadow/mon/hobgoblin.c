//hobgoblin.c - updated to use current code by Circe - 8/25/03
#include <std.h>
#include "/d/common/common.h"

inherit MONSTER;

void create() {
	object ob;
	::create();
	set_name("hobgoblin");
	set_id(({"hobgoblin","monster"}));
	set_race("hobgoblin");
	set_gender("male");
	set_short("A smelly hobgoblin");
	set_long(
         "This burly humanoid stands over six and a half feet tall and is "+
         "very solid.  His hide is hairy and has a dark reddish-brown color.  "+
         "His bulbous nose is bright blue, giving him a somewhat strange appearance.  "+
         "His eyes are a milky yellow that matches his teeth very well.  He wears bright "+
         "red garments tinged with black, and he seems quite fearless."
      );
	set_level(7);
	set_body_type("human");
	set("aggressive",19);
	set_alignment(3);
	set_size(2);
	set_overall_ac(10);
	set_stats("intelligence",6);
	set_stats("wisdom",4);
	set_stats("strength",13);
	set_stats("charisma",3);
	set_stats("dexterity",12);
	set_stats("constitution",7);
	set_hd(7, 1);
	set_max_hp(query_hp());
	set_wielding_limbs( ({ "right hand", "left hand"}) );
	ob = new(WEAPONDIR+"shortsword");
	ob->set_property("monsterweapon",1);
	ob->move(TO);
	command("wield sword");
	ob = new(ARMORDIR+"leather");
	ob->set_property("monsterweapon",1);
	ob->move(TO);
	command("wear leather");
	add_money("silver",random(10));
	add_money("gold",random(20));
	set_max_level(10);
	//set_exp(150);
    set_exp(900);
	set_hp(random(15)+40);
}

