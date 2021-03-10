//pathway22.c - Path through Lothwaite.  Circe 2/26/04
#include <std.h>
#include "../lothwaite.h"
inherit TOWNPATH;

void create(){
   ::create();
   set_long( ::query_long()+"  To the northwest, you see a crossroads where "+
      "the path goes several directions.  Here, a large building stands just "+
      "south of the path.\n");
   add_item("building","This large building looks to be a healer from "+
      "the dried herbs hanging on the door.  A puff of smoke rises "+
      "from the tall round chimney in the center of the roof.");
   set_exits(([
      "northwest" : PATHEXIT"pathway20",
      "east" : PATHEXIT"pathway23",
      "south" : PATHEXIT"healer",
   ]));
}