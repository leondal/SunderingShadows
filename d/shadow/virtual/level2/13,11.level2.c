#include <std.h>

inherit "/d/shadow/virtual/dinherit";

void create(){
   ::create();
   set_short("broken cell");
   set_long(
@OLI
   %^RED%^Broken old cell%^RESET%^
   This room was obviously the means that was
finally used to escape the dungeon. There is a
weakly supported tunnel to the surface here.
OLI
   );
   set_exits(([
   "east":"/d/shadow/virtual/14,11.level2",
   "tunnel":"/d/shadow/virtual/25,25.desert"
   ]));
}
