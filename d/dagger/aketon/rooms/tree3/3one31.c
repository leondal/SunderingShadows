#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("Avenue of Magiciana");
   set_long("%^GREEN%^Avenue of Magiciana%^RESET%^\n"+
   "The avenue of the Magiciana comes to an end here in the residential"+
   " section of Aketon. There is a lesser branch that runs to the"+
   " east, and this branch narrows as it turns to the south. To the"+
   " northwest the avenue continues to the main section of this tree."); 
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of the city all around you.");
   set_exits( (["east":RPATH3+"3one32",
      "south":RPATH3+"3one36",
      "northwest":RPATH3+"3one1"]) );
}
