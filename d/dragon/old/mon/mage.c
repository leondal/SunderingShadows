#include <std.h>

inherit "/std/monster.c";

void create() {
    ::create();
	set_name("magician");
        set_id( ({ "mage", "magician","smage","local magician"}));
	set("race", "human");
	set_gender("female");
        set("short","Local Magician");
        set_long("A local magician of the city of Sanctuary.");
	set_level(15);
	set_body_type("human");
	set_class("mage");
        set("aggressive","aggfunc");
  	set_alignment(4);
        set_hd(9,20);
        set_max_hp(130);
        set_hp(130);
        set_guild_level("mage", 14);
  	set_size(2);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",13);
   	set_stats("charisma",3);
   	set_stats("dexterity",8);
   	set_stats("constitution",7);
   	set_max_mp(0);
   	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
 	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	add_money("electrum",random(10));
	add_money("silver",random(10));
	add_money("gold",random(5));
	add_money("copper",random(20));
}

void aggfunc() {
  int PAL = this_player()->query_alignment();
tell_room(ETO, "%^RED%^With a few gestures, the magican mumbles something under her breath.");
  if((PAL == 3) || (PAL == 6) || (PAL == 9)) {
    force_me("say You do not belong here evil one!");
    this_player()->kill_ob(this_object(), 0);
  } else {
  force_me("bow");
  force_me("say Your soul tells me that you are good.");
  }
}
