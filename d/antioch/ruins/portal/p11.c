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
   " The ridge you're on is almost eight feet wide here, but narrows"+
   " again in both directions. You can see the trail to the north"+
   " curves quickly to the northeast, but whatever might be there is"+
   " lost in a yellowish cloud. To the southwest you can see the ridge"+
   " splits further south again."
   );
   set_exits(([
   "north" : PORTAL+"p12",
   "southwest" : PORTAL+"p10",
   ]));
}
