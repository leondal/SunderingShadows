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
   " The ridge begins to incline slightly to the north and the haze"+
   " seems much thicker here, preventing you from seeing very far ahead."+
   " The haze is less dense to the south and you can see the ridge"+
   " curve slightly to the southwest."
   );
   add_item("haze","%^ORANGE%^There is a reddish-orange haze that hangs"+
   " in this area, preventing anyone from seeing too far ahead.");
   set_exits(([
   "north" : PORTAL+"p8",
   "southwest" : PORTAL+"p6",
   ]));
}
