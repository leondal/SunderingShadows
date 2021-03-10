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
   " You're standing on a ridge that stretches out to the southeast"+
   " and northwest where it curves to the west in the distance." 
   );
   set_exits(([
   "northwest" : PORTAL+"p17",
   "southeast" : PORTAL+"p15",
   ]));
}
