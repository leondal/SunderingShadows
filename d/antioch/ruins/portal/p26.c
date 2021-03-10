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
   " You're standing on a ridge that travels to the north a little"+
   " ways before quickly turning to the northeast. You can see that it"+
   " must wind back around, for there is a section of cliff not too"+
   " far from you to the east that runs in a snake-like pattern out"+
   " of sight. To the southwest is a small plateau."
   );
   add_item("plateau","There is a plateau to the southwest.");
   set_exits(([
   "north" : PORTAL+"p27",
   "southwest" : PORTAL+"p25",
   ]));
}
