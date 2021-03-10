#include <std.h>
inherit MONSTER;

void create() {
    ::create();
	set_name("drunk");
	set_id(({"drunk","old drunk"}));
      set_race("human");
	set_gender("male");
      set_short("Old drunk");
   set_long("This drunk wanders the streets of Tharis mumbling to himself and pleading for handouts.\n");
	set_level(2);
	set_body_type("human");
  	set("aggressive",1);
  	set_alignment(6);
  	set_size(1);
        set_hd(2,1);
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",13);
   	set_stats("charisma",3);
  set_exp(48);
       set_hp(12);
   	set_stats("dexterity",8);
   	set_stats("constitution",7);
   	set_max_mp(0);
   	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
        new("/d/deku/weapons/dagger")->move(TO);
      	command("wield dagger");
	add_money("silver",random(10));
	add_money("copper",random(20));
   set_emotes(5, ({"The drunk gives a sigh and begins to mumble nonsense.",
   "%^MAGENTA%^Drunk mumbles%^RESET%^: Hey you, got some gold to spare?",
   "The drunk rummages about the garbage and refuse.",
   "%^MAGENTA%^Drunk says%^RESET%^: Well if you have no gold to spare how about some copper?",
   "%^MAGENTA%^Drunk mumbles%^RESET%^: Well if you have no money, how about a drink?"}), 0);
}
