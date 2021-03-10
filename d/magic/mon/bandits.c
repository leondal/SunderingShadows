#include "summoned_monster.h"

inherit MONSTER;

void create() {
    object ob;
    ::create();
	set_name("bandit");
	set_id( ({ "bandit", "man" }) );
	set("race", "human");
	set_gender("male");
	set("short", "A bandit");
	set("long",
@MELNMARN
You are looking at a rugged, well traveled bandit.
He looks hungry, and blood-thirsty. Watch your back
around these guys. They don't look very trustworthy.
MELNMARN
);
     set_hd(random(5)+1,2);
	set_level(random(5)+1);
	set_body_type("human");
	set_class("fighter");
  	set_alignment(5);
      set_size(2);
   	set_stats("intelligence",random(8)+8);
   	set_stats("wisdom",random(8)+5);
        set_stats("strength",random(4)+12);
   	set_stats("charisma",3);
   	set_stats("dexterity",random(8)+6);
   	set_stats("constitution",random(8)+7);
  	set("aggressive", query_stats("dexterity"));
	set_max_hp(query_hp());
	ob = new(WEAPONDIR+"shortsword");
    ob->move(this_object());
      	command("wield sword");
	ob = new(ARMORDIR+"padded");
    ob->move(this_object());
      	command("wear armor");
	add_money("electrum",random(10));
	add_money("silver",random(10));
	add_money("gold",random(5));
	add_money("copper",random(20));
//	set_speed(30);
//	set_moving(2);

}
