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
trees here are thinner then in the deep forest to the south and west. 
Yet here there are trees. To the east the land turns to scrub and then 
to desert or mountains. The road shows signs of heavy wagon travel along 
with many mounted units traveling both north and south.
OLI
   );
   set_listen("default","The winds create a rustling in the heavy underbrush of this young forest.");
   set_smell("default","The fresh smells of underbrush reach your nose.");

   set_items(([
              "ruts":"These ruts come from the travel of heavy wagons followed by heavy rains.",
              "underbrush":"This is heavy grasses, small bushes and some brambles.",
              ]));
   set_exits(([
              "west":"/d/shadow/room/pass/road7",
              "southeast":"/d/shadow/room/pass/road9",
      ]));
}

