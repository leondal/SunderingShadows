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
   " The ridge turns at a sharp angle to run south here, and you can"+
   " see that it switches again to turn southwest just ahead. The path"+
   " to the east runs straight for a little ways before curving back"+
   " to the southwest."
   );
   set_exits(([
   "west" : PORTAL+"p29",
   "south" : PORTAL+"p31",
   ]));
}
