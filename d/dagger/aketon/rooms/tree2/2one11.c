#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("Avenue of Preistoka");
   set_long("%^GREEN%^Avenue of Preistoka%^RESET%^
Nothing now.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","You hear sounds of the city all around you.");
   set_exits( (["northeast":RPATH1+"1one60",
      "southwest":RPATH2+"2one15"]) );
}
