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
%^RESET%^%^CYAN%^This rocky footpath just above the foothills of the Echoes 
Mountains seems to have been formed in part by nature.  To the north 
and east, the Charu Mountains rise high over head, while to the west, 
the Echoes Mountains loom.  Where the two join, paths much like this 
one can be seen running down toward what looks to be a proper road 
below.  Tall evergreen trees line the path, and it occasionally 
moves to one side of the other to avoid a large boulder sticking 
out from the rock of the mountains.  Short, coarse grass grows in 
clumps here, providing a small measure of padding for those walking 
along the path.
CIRCE
   );
   set_items(([
      (({"mountain","mountainside","stone"})) : "The slope of the "+
         "mountain is fairly steep, forcing the path to twist and "+
         "turn from side to side rather than climbing straight up "+
         "or down.  The stone of the mountain is a deep gray shot "+
         "through in places with white.",
      (({"trees","evergreens","evergreen trees"})) : "The evergreen "+
         "trees grow tall and green here, though it looks as though "+
         "those farther up the slope of the Echoes Mountains have been "+
         "afflicted by some sort of blight.",
      (({"boulders","boulder"})) : "Massive boulders force the path to twist its way "+
         "down, rising up as shoulders of the mountain itself.",
      "grass" : "Clumps of short, coarse grass are fairly plentiful here, "+
         "sprouting periodically from the rock.",
      (({"Charu","Charu Mountains","charu mountains"})) : "The Charu "+
         "mountains stand tall and proud to the north and east.  Peering "+
         "between peaks to the east, you can see what looks like a road.",
      (({"Echoes","Echoes Mountains","echoes mountains"})) : "The "+
         "mountains you are travelling in rise high to the northwest.  "+
         "That way, the trees seem somehow blighted, and it seems you "+
         "can almost see faint wisps of smoke from high in the peaks."
      ]));
   set_smell("default","You smell the clean air of the mountains.");
   set_listen("default","You can hear the sound of wind blowing along the mountainside.");
 }
