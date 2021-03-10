#include <std.h>
#include "../elfisland1.h"

inherit MONSTER;
object ob;

void create() {
   ::create();
   set_name("gore");
   set_id(({"half-orc","gore","leader","warrior"}));
   set_short("Gore, Leader of the Raging Horde");
   set_long(
       "The half-orc that stands before you is massive,"+
      " even for the half-orc kind. He stands before you"+
      " gripping his axe tightly in his right hand and clenching"+
      " a clawed left fist. His eyes are blood red"+
      " and his physical dominance over the others in the band is"+
      " very apparent. He dons blood soaked plate armor that covers"+
      " his vitals and a long fairly tattered cloak hangs from his"+
      " back. The confidence of this half-orc is stunning; he seems"+
      " quite ready to deal with anything or anyone."
   );
   set_class("fighter");
   set_guild_level("fighter",15);
// guild level reduced from 20 to 15 - was rushing obscenely hard for a mob designed for a 10-12 area.
   set_race("half-orc");
   set_body_type("humanoid");
   set_property("no bows",1);
   set_gender("male");
   set_hd(20,8);
   set_alignment(6);
   set_max_hp(250);
   set_hp(250);
   set_overall_ac(2);
   set_size(2);
   set("aggressive",30);
   set_exp(10000);
   set_max_level(14);
   set_wielding_limbs(({"right hand","left hand"}));
   ob = new(OBJ+"claw");
   if(random(1)) ob->set_property("monsterweapon", 1);
   ob->move(TO);
   command("wield claw in left hand");
   new(WEAP+"battle_axe")->move(TO);
   command("wield axe in right hand");
   set_property("full attacks",1);
   set_stats("strength",19);
   set_stats("constitution",19);
   set_stats("intelligence",14);
   set_stats("wisdom",12);
   set_stats("charisma",9);
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
