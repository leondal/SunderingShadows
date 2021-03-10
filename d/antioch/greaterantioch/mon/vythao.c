#include <std.h>
#include "../gantioch.h"

inherit MONSTER;
object ob;

void create() {
   ::create();
   set_name("vythao");
   set_id(({"wemic","vythao","leader","warrior"}));
   set_short("Vythao, the Merciless");
   set_long(
      "%^RESET%^%^ORANGE%^The wemic that stands before you is massive,"+
      " at least 800 pounds and 8 feet tall. He stands before you"+
      " gripping his massive claymore tightly in his hands. His"+
      " %^BOLD%^%^YELLOW%^cat-like %^RESET%^%^ORANGE%^eyes glare at"+
      " you omniously. His upper torso is covered by full plate and his"+
      " rear portion is barded. His long %^BOLD%^%^BLACK%^black hair%^RESET%^%^ORANGE%^"+
      " is braided and has %^RESET%^%^RED%^feathers%^RESET%^%^ORANGE%^ dangling"+
      " in it decoratively. This wemic looks quite terrifying, and obviously goes"+
      " to great lengths ensure it stays so."
   );
   set_class("fighter");
   set_guild_level("fighter",18);
   set_race("wemic");
   set_body_type("humanoid");
   set_property("no bows",1);
   set_gender("male");
   set_hd(25,8);
   set_alignment(6);
   set_max_hp(300);
   set_hp(300);
   set_overall_ac(-4);
   set_size(3);
   set("aggressive",30);
   set_exp(10000);
   set_max_level(17);
   set_wielding_limbs(({"right hand"}));
   ob = new(OBJ+"vythaoclaymore");
   if(random(1)) ob->set_property("monsterweapon", 1);
   ob->move(TO);
   command("wield claymore in right hand");
   set_property("full attacks",1);
   set_stats("strength",20);
   set_stats("constitution",20);
   set_stats("intelligence",14);
   set_stats("wisdom",12);
   set_stats("charisma",12);
   set_stats("dexterity",15);
   set_func_chance(45);
   set_funcs( ({ "flashit","rushit","rushit"}) );
   add_search_path("/cmds/fighter");
   set_monster_feats(({
      "parry",
	  "powerattack",
	  "shatter",
	  "sunder",
	  "rush"
   }));
}

void rushit(object targ) {
   TO->force_me("rush "+targ->query_name());
}

void flashit(object targ) {
   TO->force_me("flash "+targ->query_name());
}
