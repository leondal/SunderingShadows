//added terrian hades 1/12/10
#include <std.h>
#include "../vale.h"
inherit ROOM;

void create()
{
   ::create();
   set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
   set_property("indoors",1);
   set_property("light",1);
   set_property("no sticks",1);
   set_short("Behind the Waterfall");
   set_long(
   "%^CYAN%^You are within the cave complex behind the %^BOLD%^waterfall%^RESET%^%^CYAN%^, which you"+
   " can still hear crashing in the eastern distance but the sound"+
   " is a bit fainter now. The room here is dimly lit by a soft"+
   " %^BOLD%^%^GREEN%^phosphorescent%^RESET%^%^CYAN%^ glow coming from the west. It is rather"+
   " %^BOLD%^%^WHITE%^steamy%^RESET%^%^CYAN%^"+
   " in here, the floor is a little slick again and your clothing"+
   " is trying to stick to you.\n"
   );
   set_listen("default",
   "The roar of the waterfall echoes is fainter here.");
   set_smell("default","The air is rather humid here.");
   set_items(([
   ({"walls","ceiling"}) : "%^ORANGE%^The walls and ceiling are very smooth and"+
   " are slightly clammy here.",
   "floor" : "%^ORANGE%^The floor levels out here, to the northeast it inclines"+
   " slightly downard.",
   "waterfall" : "%^BOLD%^%^CYAN%^The waterfall crashes somewhere in the eastern distance.",
   ]));
   set_exits(([
   "northeast" : ROOMS+"waterfall2",
   "west" : ROOMS+"waterfall4",
   ]));
}
 
