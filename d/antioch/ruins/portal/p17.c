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
   " You're standing on a ridge that runs northwest and southeast. Just"+
   " ahead to the northwest you can see the path turn to the west, but"+
   " it fades from sight quickly in the haze."
   );
   set_exits(([
   "northwest" : PORTAL+"p18",
   "southeast" : PORTAL+"p16",
   ]));
}
