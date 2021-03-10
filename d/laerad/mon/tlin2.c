//Set to inherit from tlininherit.c - Octothorpe 1/7/10
//Coded by the one and only master of monsters...BANE//
// adding id of laeradmon *Styx* 12/20/03, last change 3/99

#include <std.h>
inherit "/d/laerad/mon/tlininherit.c";

void create(){
   ::create();
   set_class("cleric");
   set_mlevel("cleric",19);
   set_guild_level("cleric",19);
   set_hd(19,3);
   set_attack_bonus(7);
   set_diety("shar");
   set_spells(({
	  "cause critical wounds",
	  "call lightning",
      "cause blindness",
	  "flame strike",
	  "limb attack",
	  "blasphemy",
	  "unholy orb",
	  "maw of stone"
   }));
   set_spell_chance(60);
   set_stats("wisdom",18);
}