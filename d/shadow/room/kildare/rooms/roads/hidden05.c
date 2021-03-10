//hidden05.c
#include <std.h>
#include "../../kildare.h"

inherit ROOM;
void create(){
   ::create();
   set_indoors(0);
   set_property("light",2);
   set_terrain(HILLS);
   set_travel(FOOT_PATH);
   set_name("path through the grass");
   set_short("Path through the Grass");
   set_long(
      "%^BOLD%^%^GREEN%^Hidden deep within the tall grass covering the "+
      "foothills, this tiny path seems to be largely unused.  Small "+
      "stones running alongside it differentiate it from the rest of "+
      "the grassy foothills, the only indication that this is indeed "+
      "a path.  Though it couldn't be seen from the main trail itself, "+
      "a small copse of trees rises to the northwest."
   );
   set_items(([
      "grass" : "The tall, lush grass growing in the foothills here "+
         "is soft and vibrant green.  Small stones laid out in the "+
         "grass are the only thing that distinguishes the path.",
      (({"stones","small stones"})) : "The small gray stones seem "+
         "worn and rounded by a river.  They are about the size of a "+
         "human fist, and are laid out in the tall grass, marking "+
         "the path.",
      (({"grove","copse","trees"})) : "The small grove of trees to the "+
         "northwest looks to be deciduous rather than evergreens as"+
         "there are further up the mountain."
      ]));
   set_smell("default","You smell the clean air of the foothills.");
   set_listen("default","Occasional bird calls drift in on the breeze.");
   set_exits(([
      "trail" : ROADS"wroad22",
      "west" : ROADS"hidden06"
      ]));
}
