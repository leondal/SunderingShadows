//pathway8.c - Path to Lothwaite.  Circe 1/9/04
#include <std.h>
#include "../lothwaite.h"
inherit LOTHPATH;

void create(){
   ::create();
   set_long( ::query_long()+"To the east, you see a high earthen "+
      "rampart topped by a wooden fence.  Just beyond it, you can "+
      "see the tops of thatched roofs.");
   add_item("rampart","The earthen mound seems to form a circle around "+
      "the town to the east.  It is topped by a tall wooden fence that "+
      "ends in spikes.");
   add_item("fence","The wooden fence has been made with planks stood upright "+
      "side by side and bound by iron.  The tops of the fence have been formed "+
      "into spikes, which would make it treacherous to climb.");
   add_item("town","The town to the east has huge buildings that look as though "+
      "they are sized for giants!");
   add_item("roofs","The rooftops of the town to the east are thatched and rise "+
      "to high points to combat the snow the village must see at this altitude.");
   set_exits(([
      "southwest" : PATHEXIT"pathway7",
      "north" : PATHEXIT"pathway9"
   ]));
   slipping();
}
