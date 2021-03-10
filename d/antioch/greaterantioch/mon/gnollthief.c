#include <std.h>
#include "../gantioch.h"

inherit MONSTER;
object ob;

void create() {
   ::create();
   set_id(({"gnoll","warrior"}));
   set_name("Gnoll Thief");
   set_id(({"gnoll","thief","gnoll thief"}));
   set_short("A stealthy gnoll thief");
   set_long("%^RESET%^This is a massive, heavily haired and angry gnoll. It stands"+
              " over seven feet in height and looks around hungrily. The creature is"+
              " gripping a long tipped %^BOLD%^%^YELLOW%^spear %^RESET%^and seems ready"+
			  " for battle. The gnoll is adorned with furs and leather armors, painted"+
			  " with some sort of %^RESET%^%^BLUE%^tribal paint %^RESET%^which adds to its"+
			  " feracity. It's %^BOLD%^%^RED%^red eyes %^RESET%^glare at you, and you are"+
			  " sure there is no parlaying with this beast!");
   set_class("thief");
   set_guild_level("thief",12);
   set_race("gnoll");
   set_body_type("humanoid");
   set_property("no bows",1);
   set_gender("male");
   set_hd(12,6);
   set_alignment(6);
   set_max_hp(201);
   set_hp(201);
   set_overall_ac(-5);
   set_size(3);
   set("aggressive",18);
   set_exp(13000);
   ob = new(OBJ+"gnollspear2");
   set_max_level(12);
   set_wielding_limbs(({"right hand","left hand"}));
   if(random(5)) ob->set_property("monsterweapon", 1);
   ob->move(TO);
   command("wield spear");
   command("hide_in_shadows");
   set_property("full attacks",1);
   set_stats("strength",20);
   set_stats("constitution",20);
   set_stats("intelligence",14);
   set_stats("wisdom",12);
   set_stats("charisma",12);
   set_stats("dexterity",21);
   set_func_chance(45);
   set_funcs( ({ "stabit","stabit"}) );
   add_search_path("/cmds/thief");
   set_monster_feats(({
      "combat reflexes",
	  "scramble",
	  "dodge",
	  "evasion",
   }));
}

void stabit(object targ) {
   TO->force_me("stab "+targ->query_name());
}
