#include <std.h>
#include "../gantioch.h"

inherit MONSTER;
object ob;

void create() {
   ::create();
   set_id(({"gnoll","warrior"}));
   set_name("Gnoll Warrior");
   set_id(({"gnoll","warrior","gnoll warrior"}));
   set_short("A ferocius gnoll warrior");
   set_long("%^RESET%^This is a massive, heavily haired and angry gnoll. It stands"+
              " over seven feet in height and looks around hungrily. The creature is"+
              " gripping a long tipped %^BOLD%^%^YELLOW%^spear %^RESET%^and seems ready"+
			  " for battle. The gnoll is adorned with furs and leather armors, painted"+
			  " with some sort of %^RESET%^%^BLUE%^tribal paint %^RESET%^which adds to its"+
			  " feracity. It's %^BOLD%^%^RED%^red eyes %^RESET%^glare at you, and you are"+
			  " sure there is no parlaying with this beast!");
   set_class("fighter");
   set_guild_level("fighter",12);
   set_race("gnoll");
   set_body_type("humanoid");
   set_property("no bows",1);
   set_gender("male");
   set_hd(12,10);
   set_alignment(6);
   set_max_hp(255);
   set_hp(255);
   set_overall_ac(-2);
   set_size(3);
   set("aggressive",18);
   set_exp(12000);
   ob = new(OBJ+"gnollspear");
   set_max_level(12);
   set_wielding_limbs(({"right hand","left hand"}));
   if(random(5)) ob->set_property("monsterweapon", 1);
   ob->move(TO);
   command("wield spear");
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
