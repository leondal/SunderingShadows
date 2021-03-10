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
   " The ridge runs straight east for a little ways before curving"+
   " sharply to the south. You can see it snake back and forth a few"+
   " times before it disappears into the thick haze. The path to the"+
   " west continues for a ways before curving to the southwest."
   );
   set_exits(([
   "west" : PORTAL+"p28",
   "east" : PORTAL+"p30",
   ]));
}
