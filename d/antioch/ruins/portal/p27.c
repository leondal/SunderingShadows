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
   " The ridge curves to the northeast here and appears to run east"+
   " for some ways afterwards. You can tell that it snakes back around,"+
   " disappearing to the southeast somewhere. There is a path to the"+
   " south as well that quickly turns to the southwest and meets with"+
   " a small plateau."
   );
   set_exits(([
   "northeast" : PORTAL+"p28",
   "south" : PORTAL+"p26",
   ]));
}
