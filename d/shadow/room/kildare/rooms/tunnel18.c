#include "../kildare.h"

inherit TUN;

void create(){
   ::create();
   set_long(::query_long()+"\nA slope leads downward from here "+
      "to the west.  On the wall to the east is an unusual "+
      "painting on square tiles.  Strangely, it seems to be "+
      "arranged out of order.\n");
   add_item("painting","Yup, it's a painting.  If Circe gets "+
      "off her lazy ass, it could be pretty cool.");
   set_exits(([
      "west" : ROOMS"tunnel17"
   ]));
}
