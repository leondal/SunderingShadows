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
or south and west toward Shadow. The road is fairly well traveled. Here 
the trees still grow fairly thick. You know that to the north they will
thin out into scrub and eventually into either desert further west or
mountains to the north. The road shows signs of heavy wagon travel along
with many mounted units traveling both north and south.
OLI
   );
   set_listen("default","The birds are chirping around you as the trees rustle in the wind.");
   set_smell("default","The forest smells are about you, as are some of the smells of the animals that have passed.");

   set_items(([
              "ruts":"These ruts come from the travel of heavy wagons followed by heavy rains.",
              ]));
   set_exits(([
              "west":"/d/shadow/room/pass/road4",
              "east":"/d/shadow/room/pass/road6",
      ]));
}
