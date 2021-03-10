//Set to inherit from tlininherit.c - Octothorpe 1/7/10
//Coded by the one and only master of monsters...BANE//
// adding id of laeradmon *Styx* 12/20/03, last change 10/31/98

#include <std.h>
inherit "/d/laerad/mon/tlininherit.c";

void create(){
   ::create();
   set("aggressive",21);
   set_class("cleric");
   set_guild_level("cleric",22);
   set_hd(18,3);
   set_spells(({
	  "cause critical wounds",
	  "call lightning",
      "cause blindness",
	  "flame strike",
	  "limb attack",
	  "blasphemy",
	  "unholy orb",
	  "maw of stone",
	  "earthquake"
   }));
   set_spell_chance(80);
   set_exp(12500);
   set_stats("wisdom",19);
}
