//sstreet48 - Circe 11/23/07 for new Seneca
//7-21-10 added some guards by hades
#include <std.h>
#include "../seneca.h"

inherit VERDE;

void create(){
   ::create();
   set_long(::query_long()+"This is the junction of %^GREEN%^Verde "+
      "Esplanade %^RESET%^and %^YELLOW%^Sol Boulevard%^RESET%^.  To "+
      "the north, the double lanes of the main thoroughfare travel "+
      "between a %^BOLD%^bell tower %^RESET%^on the west and a humble "+
      "%^ORANGE%^adobe building %^RESET%^to the east.\n");
   set_exits(([
      "east" : ROOMS"sstreet27",
      "west" : ROOMS"sstreet28",
      "north" : ROOMS"skyline47"
   ]));
   add_item("bell tower","The bell tower of the cathedral to the "+
      "northwest towers over the city, casting a long shadow along "+
      "the road.  The bell is impossible to see from here, despite "+
      "the open archways you can see housing it.");
   add_item("tower","The bell tower of the cathedral to the "+
      "northwest towers over the city, casting a long shadow along "+
      "the road.  The bell is impossible to see from here, despite "+
      "the open archways you can see housing it.");
   add_item("building","The building to the northeast looks somewhat out "+
      "of place, being made of humble adobe while the buildings "+
      "around it are so much more grand.  Perhaps it is a shop of "+
      "some sort - or maybe a home?");
}

void reset(){
  ::reset();
  if(!present("Seneca Guard 2"))
     new("/d/attaya/newseneca/mon/city_guard")->move(TO);
  if(!present("psion"))new("/d/attaya/newseneca/mon/psi_guard")->move(TO);
}
