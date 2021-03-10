#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("A branch of Aketon");
   set_long("%^GREEN%^A branch of Aketon%^RESET%^\n"+
   "This branch splits off from the main trunk, you can see the pathway"+
   " curve around to the northeast and make a semi-circle up ahead. This"+
   " is the residential section of Aketon and most elves do not take"+
   " kindly to strangers, especially those intruding into their homes."+
   " You can see at least one of the houses just up ahead, but there"+
   " are many leaves on this large branch that block much of the view.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of the city all around you.");
   set_exits( (["northeast":RPATH3+"3one13",
      "south":RPATH3+"3one1"]) );
}
