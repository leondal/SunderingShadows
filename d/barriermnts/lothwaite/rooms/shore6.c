//shore6.c - Shore of Loch Tearmann.  Circe 9/11/04
#include <std.h>
#include "../lothwaite.h"
inherit LOTHSHORE;

void create(){
   ::create();
   set_long( ::query_long()+"You can see the %^ORANGE%^pier "+
      "%^GREEN%^just to the south of here, where young firbolgs "+
      "seem to come and go at all times of the day.\n");
   add_item("pier","The wooden pier to the south seems to be a "+
      "popular place with the firbolg children of the village.  "+
      "They can often be seen there, fishing and enjoying the "+
      "wind.");
   set_exits(([
      "south" : PATHEXIT"dock"
   ]));
}