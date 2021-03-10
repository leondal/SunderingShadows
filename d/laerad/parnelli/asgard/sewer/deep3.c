#include <std.h>
#include "lizard.h"
inherit WATER;

// added by Styx to make searching for corpse random (modified from dw34dd.c)
int search_corpse();
int items;

void create() {
   if(base_name(TO) != "/d/laerad/parnelli/asgard/sewer/deep3") {
      if(!random(3))
   	set_monsters( ({ LMON+"troggy" }), ({ 1 }) );
   }
::create();
set_repop(50);
set_name("Underground Lake");
set_short("Dark and water filled cavern.");
set_terrain(DEEP_WATER);
set_travel(RUTTED_TRACK);
set_long("%^BOLD%^%^BLUE%^You are beneath the surface in an underground lake.  "+
	"Blurry darkness surrounds you in all directions.  You feel your feet "
	"and legs brush against who knows what that is lying around in the "
	"muck.%^RESET%^");
set_property("indoors",1);
//	set_property("surface",0);
//set_property("underwater", 0);
set_property("no teleport",1);
set_property("no invis",1);
set_property("no sticks",1);
set_property("light",1);
set_smell("default","Water fills your nostrils as you get ready to inhale.");
set_listen("default","You hear the water in your ears.");
set_items(([
   "water":"Very cold and dark the water seeps inside your clothing like the kiss of death."
   ]));
set_search("default", "You find a corpse or two in the muck near your feet.");
set_search("muck", "You find a corpse or two in the muck near your feet.");
set_search("corpse", (: "search_corpse" :) );
items = random(2);
}

int search_corpse() {
   if(!items) {
      write("There's nothing of value here, just bones and rotting, half-eaten flesh.");
      return 1;
   }
   switch(random(8)) {
   case 0..1:
      new(LOBJ+"wcloak")->move(TO);
      write("You find a cloak on the corpse!");
      tell_room(TO,TPQCN+" finds a cloak on the corpse.",TP);
      break;
   case 2..3:
      new(LOBJ+"green_key")->move(TO);
      write("You find a key on the corpse!");
      tell_room(TO,TPQCN+" find a key on the corpse.",TP);
      break;
   case 4:
      "/d/common/daemon/randstuff_d"->find_stuff(TO,"kit", random(15)+10);
      write("You find a healing kit on the corpse.  Too bad it didn't save them....");
      tell_room(TO,TPQCN+" finds a healing kit on the corpse.  Too bad it didn't save them....",TP);
      break;
   case 5:
      "/d/common/daemon/randstuff_d"->find_stuff(TO,"stuff");
      write("You find something that might be useful or of value!");
      tell_room(TO,TPQCN+" seems to find something that might be useful or of value.",TP);
      break;
   case 6..7:
	new("/d/common/obj/rand/epants.c")->move(TO);
	write("You find a pair of pants on the corpse that still look new!");
	tell_room(TO,TPQCN+" finds a pair of pants on the corpse.",TP);
	break;
   }
   items = 0;
   return 1;
}

void reset() {
   ::reset();
   if(!random(4))
      items = 1;
}

