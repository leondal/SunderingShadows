#include <std.h>
#include "../ruins.h"
inherit PLANE;

void create()
{
   ::create();
   set_long(
   "%^RED%^The sky is a dull red color and smoke hangs in the air,"+
   " preventing you from seeing too far in any direction. The air is hot"+
   " and humid, the ground beneath your feet is scorched and baked."+
   " The ridge widens a little here and to the east, narrowing to the"+
   " northwest. There also seems to be a slight decline to the east,"+
   " but it is hard to tell with almost no landscape to judge by and"+
   " the thick haze hiding everything. The haze seems even thicker here"+
   " for some reason, making it difficult to see what's to the east,"+
   " although you can tell the path curves northeast again just a ways"+
   " ahead."
   );
   set_exits(([
   "northwest" : PORTAL+"p32",
   "east" : PORTAL+"p34",
   ]));
}
