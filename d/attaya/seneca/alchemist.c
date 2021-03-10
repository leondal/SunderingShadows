#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   object ob;
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light", 2);
   set_property("indoors", 1);
   set_short("Seneca Alchemist");
   set_long(
@DESC
You have entered the %^CYAN%^Seneca Alchemist%^RESET%^. There are many 
strange items stored on shelves and in containers all 
around the store. If the alchemist is here, she will 
be happy to help you.
DESC
   );
   set_exits( ([
      "east" : "/d/attaya/seneca/road11",
   ]) );
}

void reset(){
   ::reset();
   if(!present("pardima"))
      new("/d/attaya/seneca/mon/pardima.c")->move(TO);
}
