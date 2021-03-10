#include <std.h>
#include "../piratedefs.h"
inherit MONSTER;

void create() {
   ::create();
   set_name("Pirate crewman");
   set_id(({ "crewman","crew","pirate" }));
   set_short("Pirate crewman");
   set_long("This is one of the pirate ship's crewmen.  Wearing sturdy-looking leather armor that includes a "
"vest, breeches, cloak, and boots, it looks like he stays ready for a fight, even though he has tasks around "
"the boat to attend to.");
   set_hd(20,1);
   set_stats("strength",10);
   set_stats("intelligence",18);
   set_stats("dexterity",15);
   set_gender("male");
   set_alignment(6);
   switch(random(10)) {
     case 0..4:
     set_race("human");
     set_size(2);
     break;
     case 5..7:
     set_race("half-elf");
     set_size(2);
     break;
     case 8:
     set_race("halfling");
     set_size(1);
     break;
     case 9:
     set_race("half-orc");
     set_size(2);
     break;
   }
   set("aggressive",20);
   set_hp(110);
   set_max_hp(110);
   add_money("silver", random(200)+20);
   set_ac(0);
   set_body_type("human");
   set_class("mage");
   set_mlevel("mage",10);
   set_guild_level("mage",10);
   add_search_path("/cmds/mage");
   new(OBJ"longdagger")->move(TO);
   command("wield dagger in left hand");
   new(OBJ"longdagger")->move(TO);
   command("wield dagger in right hand");
   set_spells(({"lightning bolt","lightning bolt","magic missile","chill touch","dispel magic"}));
   set_spell_chance(60);
   set_exp(1500);
   TO->set_blinking(1);
}
