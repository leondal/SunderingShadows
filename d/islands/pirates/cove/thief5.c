#include <std.h>
#include "../piratedefs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",1);
   set_property("indoors",1);
   set_terrain(BUILT_CAVE);
   set_travel(DIRT_ROAD);
   set_name("Underground tunnel");
   set_short("Underground tunnel");
   set_long("%^BOLD%^Underground tunnel%^RESET%^\n"
"Here at the dead-end of the tunnel, a cramped little store has been hidden.  Very little is kept here, "
"aside from a few vials behind the counter.  The walls are made of %^BLACK%^%^BOLD%^stone and mortar"
"%^RESET%^, and look quite sturdy.  They're a little damp, however, as though %^CYAN%^water%^RESET%^ is "
"leaking from somewhere above, running down the walls.  The tunnel leads back to the west, into the%^BLUE%^ cavern's shadows%^RESET%^.\n");
   set_smell("default","A faint smell of dampness permeates the air around you.");
   set_listen("default","It's particularly quiet here, except for an occasional drip of water.");

   set_items(([
     ({"cavern","walls","roof","stone"}):"The %^BLACK%^%^BOLD%^stone-and-mortar%^RESET%^ walls look quite "
"sturdy, though they're a little damp, as though %^CYAN%^water%^RESET%^ is leaking from somewhere above.",
	({"store","counter","vials"}):"A little counter is set back against the far wall.  Behind it, you can "
"see a small selections of vials for sale, most of which look like various poisons."
    ]));

   set_exits(([
     "west":COVE"thief4"
   ]));
}

void reset(){
   ::reset();
   if(!present("krinten")) 
	find_object_or_load(MON"krinten")->move(TO);
}
