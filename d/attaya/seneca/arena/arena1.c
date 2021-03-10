#include <std.h>
#include <arena.h>

inherit ARENA;
void create() {
   ::create();
   set_name("%^BOLD%^%^RED%^The arena floor.%^RESET%^");
   set_short("The Arena at Seneca");
   set_long(
@DESC
You stand at the gate at the northern end of the %^CYAN%^Seneca Coliseum%^RESET%^.  
All around you people scream, cheer, and wave banners from stands 
surrounding the arena floor. The floor itself is a thick layer of 
sand stained with blood and littered with decaying limbs. This is 
an atmosphere of pure energy...
%^RED%^Death hangs heavy in the air.
DESC
   );
   set_property("indoors",0);
   set_property("light",1);
   set_property("no teleport",1);
   set_property("arena",1);
   set_property("deathmove","/d/attaya/seneca/arena/defeat.c");
   set_listen("default","Bravery folk songs are played by a band and people cheer and shout around you!");
   set_smell("default","The smoke from torches burns your nose.");
   set_exits( ([
      "southwest" : "/d/attaya/seneca/arena/arena2.c",
      "southeast" : "/d/attaya/seneca/arena/arena4.c",
      "south" : "/d/attaya/seneca/arena/arena3.c",
   ]) );
}
