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
   " You're standing on a ridge that stretches out, forking to the"+
   " northwest and northeast in the near distance. The ridge is only"+
   " perhaps six feet wide and on either side is a long fall into"+
   " molten lava. Directly south is a small plateau."
   );
   add_item("plateau","There is a plateau directly south of you.");
   set_exits(([
   "north" : PORTAL+"p3",
   "south" : PORTAL+"p1",
   ]));
}
