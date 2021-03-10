#include <std.h>
#include <arena.h>
inherit ARENA;
void create() {
   ::create();
   set_name("%^BOLD%^%^RED%^The arena floor.%^RESET%^");
   set_short("The Arena at Seneca");
   set_long(
@DESC
This is the center of the arena floor. Burning embers appear as 
falling stars as they drift from the torches above the stands and 
are swept into the arena. The floor beneath you is stained with 
blood and littered with decaying limbs. 
%^RED%^Death hangs heavy in the air.
DESC
   );
//A large circle of stakes draped with scorched skeletal remains lies to the south at the center of the arena floor.
   set_property("indoors",0);
   set_property("light",1);
   set_property("no teleport",1);
   set_property("arena",1);
   set_property("deathmove","/d/attaya/seneca/arena/defeat.c");
   set_listen("default","Bravery folk songs are played by a band and people cheer and shout around you!");
   set_smell("default","The smoke from torches burns your nose.");
   set_exits( ([
      "north" : "/d/attaya/seneca/arena/arena3.c",
      "west" : "/d/attaya/seneca/arena/arena5.c",
      "east" : "/d/attaya/seneca/arena/arena7.c",
   ]) );
}
