#include <std.h>
inherit MONSTER;

void create() {
  ::create();
  set_name("guard");
  set_id( ({ "guard"  }) );
  set_race("human");
  set_gender("male");
  set_short("City guard");
  set_long("This guard seems to be only half-heartedly performing his "
            "duties.  He looks tired and a little pale and his clothing is "
            "somewhat worn and wrinkled as though he doesn't have the energy "
            "to take care of himself.");
	 set("aggressive", 0);
  set_alignment(3);
  set_hd(8,1);
  set_stats("intelligence",10);
  set_stats("wisdom",10);
  set_stats("strength",15);
  set_stats("charisma",10);
  set_stats("dexterity",12);
  set_stats("constitution",10);
  set_max_hp(query_hp());
  new("/d/common/obj/weapon/longsword")->move(TO);
  command("wield longsword");
  new("/d/common/obj/armour/chain")->move(TO);
  command("wear chain");
  add_money("silver",random(10));
  add_money("gold",random(5));
  add_money("copper",random(20));
  set_hp(random(15)+50);
  set_exp(query_max_hp() * 10);
} 
