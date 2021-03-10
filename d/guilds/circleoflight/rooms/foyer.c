#include <std.h>
#include "../defs.h"
inherit CVAULT;

void create(){ 
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("A collonaded hallway");
   set_short("%^RESET%^%^ORANGE%^A collonaded hallway%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^A collonaded hallway%^RESET%^\n"
"You stand within the entrance of a vast building, from which a long hallway leads off to the north.  The %^ORANGE%^st"
"%^RED%^on%^ORANGE%^e roof %^RESET%^soars far above your head, so high that even a giant would walk comfortably here.  "
"Thick, stout columns march down the walls, spanning the length of the walkway in evenly spaced intervals.  At a few "
"points between the buttresses lie tapestries and paintings, their %^MAGENTA%^b%^BOLD%^%^BLUE%^ri%^RESET%^%^CYAN%^gh"
"%^GREEN%^tl%^YELLOW%^y %^RESET%^woven threads and canvas lending a cheery aspect to the otherwise drab hallway.  Between "
"other columns lie open archways bordered by tiered archivolts, all of which seem to lead into %^CYAN%^enclosed %^RESET%^"
"rooms beyond, which seem either entirely empty, or stacked with packed crates and boxes.  It seems whatever is being "
"arranged here, it is not yet complete.%^RESET%^\n");
   set_smell("default","The air is fresh and clean, drifting in from outside.");
   set_listen("default","Even the softest of sounds echo in this vast, open hallway.");
   set_items(([
   ]));
   set_exits(([
     "out":ROOMS"path",
//     "forest" : ROOMS"forest",
// outdoors, druid NPC (rear of building)
// meditation room/library - ID'ing NPC
// religious shrines, some kind of neutral priest NPC to oversee
// armory/combat, gear storage NPC
// one more?
   ]));
    set_door("double doors",ROOMS"path","out",0);
    set_door_description("double doors","%^ORANGE%^This pair of oaken doors fit the massive doorway leading outside, so "
"large that even a giant could pass through unhindered.  Thick metal bars reinforce them in several places, leaving the "
"impression that they would be terribly difficult to damage.%^RESET%^");
}

//aedicula - small internal shrine