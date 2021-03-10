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
   " The ridge runs straight east for a little ways before curving back"+
   " to the south, you can see it snake again to the southwest and then"+
   " back to the southeast where it disappears in the thick haze. The"+
   " path also runs to the southwest, quickly turning south again."
   );
   set_exits(([
   "southwest" : PORTAL+"p27",
   "east" : PORTAL+"p29",
   ]));
}
