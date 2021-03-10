
#include <std.h>
#include "lizard.h"
inherit WATER;

void create() {
   if(base_name(TO) != "/d/laerad/parnelli/asgard/sewer/deep2") {
     if(!random(10))
   	set_monsters( ({ LMON+"troggy" }), ({ 1 }) );
   }
::create();
set_repop(50);
set_name("Underground Lake");
  	set_terrain(DEEP_WATER);
  	set_travel(RUTTED_TRACK);
set("short","Dark and water filled cavern.");
set("long","%^BOLD%^%^BLUE%^You are beneath the surface in an underground lake.  "+
        "Blurry darkness surrounds you in all directions.  %^RESET%^");
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
 }
