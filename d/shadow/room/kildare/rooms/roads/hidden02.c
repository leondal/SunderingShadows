//hidden02.c
#include <std.h>
#include "../../kildare.h"

inherit ROOM;
void create(){
   ::create();
   set_indoors(0);
   set_property("light",2);
   set_terrain(ROCKY);
   set_travel(FOOT_PATH);
   set_name("abandoned trail");
   set_short("Abandoned Trail");
   set_long(
      "This short spur off the narrow trail seems to lead nowhere at first.  "+
      "The boulders are close all around, standing a towering twenty feet tall "+
      "here.  There are so many so close together that this places feels more "+
      "like a canyon than a mountain trail.  The main trail opens back up through "+
      "a tiny break in the boulders to the west, while there seems to be "+
      "another small opening to the north."
   );
   set_items(([
      (({"boulder","boulders"})) : "%^BOLD%^%^BLACK%^The boulders here are "+
         "huge, some reaching well over fifteen feet tall.  Their height "+
         "creates large shadows on the ground in between them even during "+
         "the brightest daylight, and creates an abyssal blackness at night.",
      ]));
   set_smell("default","You smell the clean air of the mountains.");
   set_listen("default","It is blessedly quiet in here after the roaring wind of the mountainside.");
   set_exits(([
      "north" : ROADS"hidden03",
      "trail" : ROADS"wroad13"
   ]));

}
