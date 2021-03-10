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
   " The ridge turns southwest here, you can tell it runs straight south"+
   " for a ways before turning to the southeast. To the east the ridge"+
   " quickly turns to the southeast, running off into the distance."
   );
   set_exits(([
   "southwest" : PORTAL+"p20",
   "east" : PORTAL+"p18",
   ]));
}
