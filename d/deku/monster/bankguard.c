#include <std.h>
inherit MONSTER;
void create() {
  ::create();
   set_name("guard");
   set_id( ({ "guard"  }) );
   set_race("human");
   set_gender("male");
   set_short("Bank guard");
   set_long("This human is always watching you.");
   set("aggressive", 0);
   set_alignment(3);
   set_stats("intelligence",10);
   set_stats("wisdom",10);
   set_stats("strength",13);
   set_stats("charisma",12);
   set_stats("dexterity",12);
   set_stats("constitution",12);
   set_hd(6,1);
   set_max_hp(query_hp());
   new("/d/common/obj/weapon/longsword")->move(TO);
   command("wield sword"); 
   add_money("silver",random(10));
   add_money("gold",random(5));
   add_money("copper",random(20));
}
