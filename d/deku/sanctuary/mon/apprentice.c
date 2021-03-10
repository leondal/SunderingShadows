#include <std.h>
#include "../dragon.h";

inherit MONSTER;

void create() {
   ::create();
   set_name("apprentice");
   set_id(({"apprentice","mage","tower apprentice"}));
   set_short("Tower apprentice");
   set_long(
      "All the apprentices in this tower are male. They all appear to be in the early to mid twenties. The colors of robes varies from red, to blue, to black. They appear to be well kept and very loyal to the tower.");
   set_race("human");
   set_gender("male");
   set_hd(13,2);
   set_class("mage");
   set_guild_level("mage",13);
   set_alignment(3);
   set_max_hp(189);
   set_hp(189);
   set_overall_ac(-2);
   set_mob_magic_resistance("average");
   set_size(2);
   set("aggressive",30);
   set_exp(15000);
   set_stats("strength",15);
   set_stats("intelligence",16);
   set_stats("constitution",14);
   set_stats("wisdom",12);
   set_stats("dexterity",13);
   set_stats("charisma",11);
   set_spells(({
      "fireball",
      "lightning bolt",
      "cone of cold",
      "scorcher",
   }));
   set_spell_chance(100);
   set_max_level(23);
}
