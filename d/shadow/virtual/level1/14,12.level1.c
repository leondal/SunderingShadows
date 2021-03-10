#include <std.h>

inherit "/d/shadow/virtual/dinherit";

void create(){
   ::create();
   set_short("broken cell");
   set_long(
@OLI
   %^RED%^Broken old cell%^RESET%^
   This cell has had the doors ripped off, but more amazing
is the giant hole that dominates the center of the room.
Looking through the hole you can see that it leads to another
level below.  You wonder what is down there.
OLI
   );
   set_exits(([
   "north":"/d/shadow/virtual/14,11.level1",
   "hole":"/d/shadow/virtual/3,3.level2"
   ]));
}
