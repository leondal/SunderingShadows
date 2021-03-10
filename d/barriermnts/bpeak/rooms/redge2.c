//redge2.c
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit ROOM;

void create(){
::create();
   set_property("indoors",1);
   set_travel(FOOT_PATH);
   set_terrain(NAT_CAVE);
   set_name("%^BOLD%^%^BLACK%^Just on the other side of the river%^RESET%^");
   set_short("%^RESET%^The other side of the river");
   set_property("no teleport",1);
   set_smell("default","%^BLUE%^The moisture hangs in the air here.");
   set_listen("default","%^BOLD%^%^BLUE%^The sound of rushing water is almost deafening.");
   set_long("%^RESET%^%^BLUE%^This side of the river is eerily quiet."
"  A %^RESET%^light filters %^BLUE%^down through the hole in the ceiling and"
" %^BOLD%^%^WHITE%^illuminates %^RESET%^%^BLUE%^the large pile of things here."
"  %^RESET%^Bones %^BLUE%^litter the floor in haphazard piles with little to no care"
" as to the cleanliness of the cavern.  The walls of the cave are steep"
" and jagged, making it impossible to climb them.  The only feasible exit looks to"
" be back over the river.%^RESET%^ \n"); 
   set_items((["river":"%^BOLD%^%^BLUE%^The river here is a natural underground river whose source is unknown.  It moves through here at a frantic pace and you wonder if it would be wise to try to cross it.%^RESET%^",
   "treasure":"It looks as though whatever dwells above may use this area to dump their loot through the hole in the ceiling.  The treasure piled in this room looks useless.%^RESET%^",
   "hole":"%^RESET%^%^BLUE%^A hole is in the ceiling here.  %^RESET%^Light %^BLUE%^filters in through it and %^BOLD%^%^WHITE%^illuminates %^RESET%^%^BLUE%^the stash of treasures here.%^RESET%^",
   "bones":"%^BOLD%^%^WHITE%^Bones lay strewn about in haphazard piles.  Large bite marks can be seen in most of them, but no flesh remains at all.%^RESET%^", 
   ]));
   set_search("default","The pile of treasure here looks useless.  Nothing more than a pile of nonsense that glitters in the light.%^RESET%^");
   set_exits((["river":INRMS+"criver"]));
   //set_storage(1);
   //restore_room();
}
void reset() {
  ::reset();
  if(!present("ogre")){
     new(TMONDIR+"axlhaina.c")->move(TO);
  }
}