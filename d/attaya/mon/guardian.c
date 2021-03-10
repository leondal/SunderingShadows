//Octothorpe (12/12/09)
//Attaya, Guardian of the Temple
//Original by Thundercracker

#include <std.h>
#include "../defs.h"
inherit MONSTER;

void create(){
   object ob;
   ::create();
   set_name("guardian");
   set_id(({"guardian of the temple","undead","guardian"}));
   set_short("%^RESET%^%^RED%^r%^ORANGE%^u%^RED%^st%^ORANGE%^y %^RED%^"+
      "temple guardian%^RESET%^");
   set_long("%^RESET%^%^RED%^This undead warrior is outfitted with "+
      "completely rusted equipment.  Some vestiges of ancient armor "+
	  "cover parts of its torso, but what remains is in no condition "+
	  "to provide any semblance of protection.  The emblem of the "+
	  "Temple of the Black Dawn is noticeable on the disintegrating "+
	  "armor.  The undead's leathery skin also follows the example of "+
	  "the tattered armor, with bits and pieces hanging to and fro "+
	  "over some of the bones.%^RESET%^");
   set_race("undead");
   set_gender("male");
   set_hd(40,16);
   set_size(2);
   set_overall_ac(-9);
   set_class("fighter");
   set_guild_level("fighter",40);
   set_speed(30);
   set_max_hp(350+random(150));
   set_hp(query_max_hp());
   set_wielding_limbs(({"right hand"}));
   set_body_type("human");
   set_property("full attacks",1);
   set_property("no bump",1);
   set_stats("strength",23);
   set_stats("dexterity",16);
   set_stats("constitution",17);
   set_stats("intelligence",3);
   set_stats("wisdom",3);
   set_stats("charisma",3);
   set("aggressive",25);
   set_mob_magic_resistance("low");
   set_exp(17500);
   set_max_level(36);
   set_alignment(9);
   ob = new(OBJ"rusts");
   ob->move(TO);
   ob->set_property("monsterweapon",1);
   command("wear shield");
   ob = new(OBJ"rustb");
   ob->move(TO);
   ob->set_property("monsterweapon",1);
   command("wield blade in left hand");
   add_search_path("/cmds/feats");
   set_monster_feats(({
      "shieldbash",
	  "shieldwall",
	  "deflection",
	  "counter"
	  "powerattack",
	  "shatter",
	  "sunder",
	  "rush"
   }));
   add_search_path("/cmds/fighter");
   set_fighter_style("soldier");
   command("message in shambles in.");
   command("message out shambles to the $D.");
   set_func_chance(40);
   set_funcs(({"rushit","flashit","rushit","flashit","rushit"}));
      set_resistance("negative energy",20);
      set_resistance("positive energy",-20);
}

void rushit(object targ) {
   TO->force_me("rush "+targ->query_name());
}

void flashit(object targ) {
   TO->force_me("flash "+targ->query_name());
}

void die(object ob) {
   tell_room(ETO,"%^BOLD%^The temple guardian collapses into a pile "+
      "of bones and crumbling armor.");
   TO->move("/d/shadowgate/void");
   TO->remove();
}
