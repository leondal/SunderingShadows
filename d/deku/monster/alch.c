#include <std.h>

inherit MONSTER;

void create() {
   object obj, money;
   ::create();
   set_name("cora");
   set_id(({"Cora","cora","alchemist"}));
   set_short("Cora, the Alchemist");
   set("aggressive", 18);
   set_long("Cora was once a mighty alchemist, but is now under Vexia's "
       "control.  She creates the chemicals that make Vexia look younger.");
   set_gender("female");
   set_alignment(6);
   set_race("human");
   set_hd(10,1);
   set_stats("strength",16);
   set_stats("dexterity",12);
   set_stats("constitution",13);
   set_stats("wisdom",11);
   set_stats("intelligence",17);
   set_stats("charisma",12);
   set_property("no bump", 1);
   set_class("mage");
   set_mlevel("mage", 10);
   set_guild_level("mage",10);
   set_spell_chance(90);
   set_spells(({"lightning bolt","acid arrow","magic missile", "lightning bolt"}));
   set_hp(82 + random(31));
   set_exp(query_max_hp() * 11);
   obj = new("/d/common/obj/misc/schest");
   obj->move(TO);  // moving until after all the stuff gets put in it, etc. 11/11/02
   obj->set_key("chestkey");
   money = new("/std/obj/coins");
   money->set_money("gold",random(100)+75);
   money->set_money("electrum",random(200)+25);
   money->set_money("silver",random(400)+50);
   money->set_money("copper",random(1000)+300);
   money->move(obj);
   switch(random(3)) {
      case 0:
         new("/d/newbie/obj/misc/gem")->move(obj);
      case 1:
         new("/d/newbie/obj/misc/gem")->move(obj);
      case 2:
         new("/d/newbie/obj/misc/gem")->move(obj);
         break;
   }
   obj->toggle_closed();
   obj->set_lock("locked");
   obj->set_lock_difficulty(35);
   obj->move(TO);  // moved to after all the stuff gets put in it, etc. 11/11/02
	set_new_exp(10, "very low");
}
