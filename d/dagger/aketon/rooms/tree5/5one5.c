//updated by Circe 10/04
#include "/d/dagger/aketon/short.h"

inherit TREEOUT;

void create() {
   ::create();
   set_short("A room of Aketon");
   set_long("%^GREEN%^A room of Aketon%^RESET%^
Nothing right now.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","You hear sounds of the city all around you.");
   set_exits( (["southwest":RPATH5+"5one10"]) );
}
