//Added an extra id, to deal with a conflict with summoned monsters. Lujke 14 March 08
#include <std.h>
#include "../elfisland1.h"

inherit MONSTER;
object ob;

void create() {
   ::create();
   set_name("bandit");
   set_id(({"orc","bandit","orc bandit", "xxguardorcxx"}));
   set_short("Orc bandit");
   set_long(
       "This is an orc bandit apart of the camp that calls itself the"+
       " Raging Horde. They are a group of orcs that tend to try to invade"+
       " the nearby elven town and ambush lone travelers on the road."
   );
   set_class("fighter");
   set_guild_level("fighter",15);
   set_class("thief");
   set_guild_level("thief",12);
   set_mlevel("fighter",15);
   set_mlevel("thief",12);
   set_race("orc");
   set_body_type("humanoid");
   set_gender("male");
   set_property("no bows",1);
   set_hd(15,4);
   set_alignment(6);
   set_max_hp(175);
   set_hp(175);
   set_overall_ac(4);
   set_size(2);
   set("aggressive",17);
   set_exp(3500);
   set_max_level(14);
   set_wielding_limbs(({"right hand","left hand"}));
   ob = new(WEAP+"double_bladed_sword");
   if(random(10)) ob->set_property("monsterweapon", 1);
   ob->move(TO);
   ob = new(OBJ+"Mchain+1");
	if(random(3)){
		ob->set_property("monsterweapon",1);
	}
   ob->move(TO);
   command("wear chain");
   command("wield sword");
   set_property("full attacks",1);
   set_stats("strength",17);
   set_stats("constitution",14);
   set_stats("intelligence",11);
   set_stats("wisdom",9);
   set_stats("charisma",9);
   set_stats("dexterity",17);
   add_search_path("/cmds/thief");
   add_search_path("/cmds/fighter");
   set_scrambling(1);
   set_funcs( ({"rushit","flashit","flashit","flashit"}) );
   set_func_chance(25);
   set_monster_feats(({
      "parry",
      "powerattack",
	  "shatter",
	  "sunder",
	  "rush",
	  "dodge",
      "mobility",
	  "evasion",
	  "scramble",
	  "combat reflexes"
    }));     
}

void rushit(object targ) {
  TO->force_me("rush "+targ->query_name());
}

void flashit(object targ) {
  TO->force_me("flash "+targ->query_name());
}
