#include <std.h>
#include "mountain.h";

inherit BASE;

void create(){
   ::create();
   set_long(
      "%^BOLD%^%^BLACK%^The path stops its spiral here. The road"+
      " makes its last loop around the wall of the mountain and forms"+
      " a natural bridge over a large canyon, linking with an even taller"+
      " mountain."
   );
   set_exits(([
      "northeast" : MOUNTAIN+"mountain06",
      "bridge" : MOUNTAIN+"mountain08",
   ]));
}