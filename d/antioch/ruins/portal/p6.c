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
   " The ridge seems slightly wider here and it continues to the"+
   " northeast and southeast."
   );
   set_exits(([
   "northeast" : PORTAL+"p7",
   "southeast" : PORTAL+"p5",
   ]));
}
