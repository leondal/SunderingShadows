#include <std.h>
#include "../kildare.h"

inherit ROOM;
void create(){
   ::create();
   set_indoors(0);
   set_property("light",2);
   set_terrain(ROCKY);
   set_travel(FOOT_PATH);
   set_name("A rocky path");
   set_short("A Rocky Path");
   set_long(
@CIRCE
%^BOLD%^%^WHITE%^A Rocky Path
%^RESET%^%^CYAN%^Despite the hard stone of the mountain, a well-worn footpath 
runs along the mountainside here.  It meanders alongside boulders and 
tall evergreens, choosing the path of least resistance as it makes 
its way.  It does not seem to be wide enough for carts or buggies, 
and is barely flat enough to allow proper footing for a horse.  Very 
little grass softens the ground here, but the trees provide some 
protection from the elements.
CIRCE
   );
   set_items(([
      (({"mountain","mountainside","stone"})) : "The slope of the "+
         "mountain is fairly steep, forcing the path to twist and "+
         "turn from side to side rather than climbing straight up "+
         "or down.  The stone of the mountain is a deep gray shot "+
         "through in places with white.",
      (({"trees","evergreens","evergreen trees"})) : "The evergreen "+
         "trees seem unhealthy somehow, several of them missing any "+
         "needles whatsoever.  Their limbs seem like skeletal arms, "+
         "waving black in the breeze.",
      "boulders" : "Massive boulders force the path to twist its way "+
         "down, rising up as shoulders of the mountain itself.",
      "grass" : "Fitful clumps of grass sprout from the rock of the "+
         "mountain sporadically.  They are too short and coarse to "+
         "soft the way at all."
      ]));
   set_smell("default","You smell the clean air of the mountains.");
   set_listen("default","A strong breeze muffles the sounds around you.");
 }
