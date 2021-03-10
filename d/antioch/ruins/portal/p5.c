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
   " The slender ridge you're on leads to the northwest and you see it"+
   " curve to the northeast just ahead. Southeast the ridge continues,"+
   " forking south and northeast in the distance."
   );
   set_exits(([
   "northwest" : PORTAL+"p6",
   "southeast" : PORTAL+"p4",
   ]));
}
