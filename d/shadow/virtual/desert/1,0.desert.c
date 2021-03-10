//road1

#include <std.h>

inherit ROOM;

void create(){
   ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(RUTTED_TRACK);

   set_indoors(0);
   set_light(2);
   
   set_short("Rutted road");
   set_long(
@OLI
   %^MAGENTA%^Twisting Rutted Road%^RESET%^
   This is a rutted road twisting to the north and east away from Shadow
or south and west toward Shadow. The road is fairly well traveled. The
landscape around you changes quickly it heads now toward more scrub and 
very light forest. The road shows signs of heavy wagon travel along with 
many mounted units traveling both north and south. To the east the light 
forest spreads out before you.
OLI
   );
   set_listen("default","The winds create a rustling in the heavy underbrush of this young forest.");
   set_smell("default","The fresh smells of underbrush reach your nose.");

   set_items(([
              "ruts":"These ruts come from the travel of heavy wagons followed by heavy rains.",
              "underbrush":"This is heavy grasses, small bushes and some brambles.",
              ]));
   set_exits(([
              "west":"/d/shadow/room/pass/road18",
              "east":"/d/shadow/virtual/desert/1,1.desert",
              "north":"/d/shadow/virtual/desert/0,0.desert",
              "south":"/d/shadow/virtual/desert/2,0.desert",
      ]));
}

int is_virtual(){ 
   return 1;
}
