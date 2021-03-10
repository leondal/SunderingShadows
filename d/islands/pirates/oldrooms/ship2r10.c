#include <std.h>
#include "../piratedefs.h"

inherit CROOM;

void create(){
    set_repop(40);  // putting this up here to limit them loading the first time even
    set_monsters(({MON"pirateguard", MON"piratecaptain"}),({2, 1}));
::create();
set_property("indoors",1);
set_property("light",1);
    set_terrain(WOOD_BUILDING);
    set_travel(RUBBLE);

set_short("Captain's Quarters");

set_long("%^BOLD%^Captain's Quarters%^RESET%^\n"+
         "You have gone to the stern of the ship. "+
          "You have found the pirate captain's quarters. "+
         "This place is as spacious as a ship would allow. "+
          "This place is filled with filthy bones and half eaten food "+
          "litter the ground. The stench gives you the "+
         "urge to vomit.\n"
        );

set_smell("default","You smell rotting food and other indecipherable smells");
set_listen("default","You can hear the rumbling of someone's stomach.");
set_items(([
          "food":"DISGUSTING...uck..you're not gonna want to eat for week after this view."
         ]));
    set_exits(([ "north":CAVES"ship2r7",  ]));
}

void reset(){
 ::reset();
/* changing to have CROOM handle controlling them & limit repops  *Styx*  11/25/02
 if(!present("captain") && !random(3)){
   find_object_or_load(MON+"piratecaptain")->move(TO);
 }
 if(!present("guard")){
   new(MON+"pirateguard")->move(TO);
 }
 if(!present("guard 2")){
   new(MON+"pirateguard")->move(TO);
 }
*/
}
