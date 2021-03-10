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
   " The ridge turns west here, but you can see it will quickly turn"+
   " to the southwest ahead. The ridge also runs southeast in a fairly"+
   " straight line."
   );
   set_exits(([
   "west" : PORTAL+"p19",
   "southeast" : PORTAL+"p17",
   ]));
}
