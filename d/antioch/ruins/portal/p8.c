#include <std.h>
#include "../ruins.h"
inherit PLANE;

void create()
{
   ::create();
   set_long(
   "%^RED%^A reddish-orange haze is thick in the air here, preventing"+
   " anyone from seeing very far ahead. It seems to be thicker to the"+
   " northwest, where the path rises slightly and also appears to"+
   " widen a bit more. To the south the haze still appears present, but"+
   " less so than here, although that's hard to tell."
   );
   set_listen("default","%^YELLOW%^The crackle of flames seems duller in the thick haze.");
   add_item("haze","%^ORANGE%^There is a reddish-orange haze that hangs"+
   " in this area, preventing anyone from seeing too far ahead.");
   set_exits(([
   "northwest" : PORTAL+"p9",
   "south" : PORTAL+"p7",
   ]));
}

query_weather() { return "%^BOLD%^%^RED%^The haze is thick here.%^RESET%^"; }