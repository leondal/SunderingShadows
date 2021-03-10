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
   " The ridge runs to the south for a little ways, but you can see it"+
   " curving to the southwest just ahead. You believe it might turn"+
   " northwest from there, because you can vaguely make out some sort"+
   " of structure or something covered in smoke and haze a bit southwest"+
   " of you. The ridge also leads to the northwest, straightening out"+
   " to run north for a little ways."
   );
   set_exits(([
   "northwest" : PORTAL+"p21",
   "south" : PORTAL+"p23",
   ]));
}
