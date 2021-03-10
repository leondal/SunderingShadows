//hobgoblincaptain.c - updated to use current code by Circe - 8/25/03
#include <std.h>
#include "/d/common/common.h"

inherit MONSTER;

void create() {
	object ob;
	::create();
	set_name("hobgoblin captain");
	set_id(({"hobgoblin","captain","hobgoblin captain","monster"}));
	set_race("hobgoblin");
	set_gender("male");
	set_short("A fierce hobgoblin captain");
	set_long(
         "This burly humanoid stands over six and a half feet tall and is "+
         "very solid.  His hide is hairy and has a dark reddish-brown color.  "+
         "His bulbous nose is bright blue, giving him a somewhat strange appearance.  "+
         "His eyes are a milky yellow that matches his teeth very well.  He wears bright "+
         "red garments tinged with black, and he seems quite fearless.  This hobgoblin "+
         "is stockier than his kin, and he has a disturbing intelligence in his eyes "+
         "that marks him as a leader of his people."
      );
	set_level(10);
	set_body_type("human");
	set("aggressive",19);
	set_alignment(3);
	set_size(2);
	set_overall_ac(10);
	set_stats("intelligence",14);
	set_stats("wisdom",8);
	set_stats("strength",16);
	set_stats("charisma",3);
	set_stats("dexterity",14);
	set_stats("constitution",15);
	set_hd(10, 1);
	set_max_hp(query_hp());
	set_wielding_limbs( ({ "right hand", "left hand"}) );
	ob = new(WEAPONDIR+"shortsword");
	ob->set_property("monsterweapon",1);
	ob->move(TO);
	command("wield sword");
	ob = new(ARMORDIR+"chain");
	ob->set_property("monsterweapon",1);
	ob->move(TO);
	command("wear chain");
	add_money("silver",random(10));
	add_money("gold",random(20));
	set_max_level(10);
	//set_exp(200);
    set_exp(1200);
	set_hp(random(20)+50);
}
