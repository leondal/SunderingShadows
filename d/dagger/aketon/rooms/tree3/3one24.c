#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("A branch of Aketon");
   set_long("%^GREEN%^A branch of Aketon%^RESET%^\n"+
   "You are walking along a large branch on the first level of one of"+
   " Aketon's many large trees. This is a small pathway that leads to a"+
   " rest area up ahead. Directly west is the trunk of the large tree with"+
   " stairs spiraling up and down. Leaves from the surrounding branches"+
   " block off the other areas from view."); 
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear sounds of the city all around you.");
   set_exits( (["northeast":RPATH3+"3one19",
      "west":RPATH3+"3one1"]) );
}
