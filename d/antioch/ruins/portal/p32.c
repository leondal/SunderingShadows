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
   " The ridge is quite curvy in this area, you can see it curve to"+
   " the northeast where it quickly makes another turn. It also curves"+
   " to the southeast here and you can see that it runs east for a"+
   " little ways at least."
   );
   set_exits(([
   "northeast" : PORTAL+"p31",
   "southeast" : PORTAL+"p33",
   ]));
}
