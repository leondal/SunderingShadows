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
   set_short("Seneca Scribe's Office");
   set_long(
@DESC
Walking into the %^CYAN%^Scribe's Office%^RESET%^, you are immediately
surrounded by shelves that line the walls and containers 
of supplies. There are a few tables covered with partially-
finished requests. There is a desk kept spotlessly clean
directly in front of the door with the scribe sitting behind 
it. As you walk in, he looks up, smiles, and says 'Hello, how 
may I help you?'.
DESC
   );
   set_items(([
      "shelves":"The shelves are filled with writing materials and finished papers.",
      "papers":"There appears to be all kinds of written records here.",
   ]));
   set_exits( ([
      "east" : "/d/attaya/seneca/road10",
   ]) );
}

void reset(){
   ::reset();
   if(!present("antral"))
      new("/d/attaya/seneca/mon/antral")->move(TO);
}
