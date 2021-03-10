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
   " The slender ridge you're on forks to the northwest and seems to"+
   " continue in that direction for some distance. There is another"+
   " fork leading to the northeast that you can see curves not too"+
   " far ahead. South of here you can see a plateau in the distance."
   );
   add_item("plateau","There is a plateau directly south of you.");
   set_exits(([
   "northwest" : PORTAL+"p4",
   "northeast" : PORTAL+"p10",
   "south" : PORTAL+"p2",
   ]));
}
