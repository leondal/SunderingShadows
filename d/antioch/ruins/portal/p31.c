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
   " The ridge turns quickly to the southwest here and you can see it"+
   " curve again almost immediately to the southeast. You can barely"+
   " make out some sort of structure that is cloaked in haze not far"+
   " southeast of your position. The ridge also leads to the north"+
   " where it makes a very sharp turn to the west."
   );
   set_exits(([
   "north" : PORTAL+"p30",
   "southwest" : PORTAL+"p32",
   ]));
}
