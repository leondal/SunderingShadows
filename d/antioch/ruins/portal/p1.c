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
   " You're standing on a small plateau on a cliff above a river of"+
   " molten lava. You can see tendrils of the cliff branch out from"+
   " here. One section leads directly north but seems to split not too"+
   " far ahead. To the west is a branch leading northwest, and on the"+
   " east is a section leading to the northeast."
   );
   add_item("plateau","You're standing on a small plateau that"+
   " branches out to the north, northwest, and northeast.");
   set_exits(([
   "north" : PORTAL+"p2",
   "west" : PORTAL+"p15",
   "east" : PORTAL+"p25",
   "south" : PORTAL+"entrance",
   ]));
}
