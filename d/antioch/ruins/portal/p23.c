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
   " The ridge curves to the southwest here and you can see that it"+
   " will shortly curve again to the northwest. Straight west of your"+
   " position you can make out a large structure in the center of a"+
   " platform. You notice that the ridge is a little wider here than to"+
   " the north, and seems to grow even wider to the southwest. Smoke and"+
   " haze prevent you from making out any clearer details of what lies"+
   " to the west."
   );
   set_exits(([
   "north" : PORTAL+"p22",
   "southwest" : PORTAL+"p24",
   ]));
}
