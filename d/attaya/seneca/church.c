#include <std.h>
inherit "/std/church";

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light", 2);
   set_property("indoors", 1);
   set_short("Cathedral of Seneca");
   set_long(
@DESC
This is the %^CYAN%^Cathedral of Seneca%^RESET%^. Colorful rays of light shine into 
the room from the magnificent stained glass windows that surround 
you. Several rows of benches face a pulpit at the front of the 
massive room. The ceiling is a full three stories above you and is 
made of dark stained oak planks. A door to the east leads to the 
tower and another door to the west leads outside to the rear yard 
where ceremonies such as weddings are often held.
DESC
   );
   set_exits( ([
      "out" : "/d/attaya/seneca/cathyard",
      "east" : "/d/attaya/seneca/church2",
      "west" : "/d/attaya/seneca/churchyard",
   ]) );
   set_items(([
      "chamber" : "People come here to pray for resurrection when they die.", 
      "windows" : "The magnificent stained glass windows are almost divine in appearance themselves.  Each one is about thirty feet tall and comprised of thousands of colored glass panels.",
      "pulpit" : "This is the main sermon pulpit.  It is decorated and draped with a blue velvet sheet.",
   ]) );
   set_smell("default","Candles give off an exotic fragrence.");
   set_listen("default", "Organ music sets the solemn mood.");
}

