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
   " The ridge runs to the south, but you can see it quickly turns to"+
   " the southeast up ahead, then is lost in the haze. It also runs"+
   " to the northeast, quickly turning again to the southeast."
   );
   set_exits(([
   "south" : PORTAL+"p21",
   "northeast" : PORTAL+"p19",
   ]));
}
