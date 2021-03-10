#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_short("Outside the clothing shop");
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_long(
@DESC
You are inside the opening to a large tent. Heavy fabric 
drapes over iron supports to make a tunnel of sorts here, 
leading into the %^CYAN%^Clothing Shop%^RESET%^. A few rusty lanterns 
provide dim lighting in here. The ground beneath your feet
is a finely packed dirt. Two grooves are worn into it where 
countless people before you have tread.
DESC
   );
   set_exits(([
      "east" : "/d/attaya/seneca/street3",
      "south" : "/d/attaya/seneca/street7",
      "west" : "/d/attaya/seneca/clothshop",
   ]));
   set_items(([
      "path" : "It is made from trodden dirt.",
   ]));
}
