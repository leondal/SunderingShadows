//top
#include <std.h>
#include <rooms.h>
#include "../yntala.h"
inherit ROOM;

void create(){
::create();
   set_property("outdoors",0);
   set_property("light",0);
   set_property("no teleport",1);
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_name("%^RESET%^The top of a grand pyramid");
   set_short("%^RESET%^The top of a great pyramid%^RESET%^");
   set_listen("default","Whispers and soft hisses seem to float on the breeze here, giving off an overall uneasy feeling.");
   set_long((:TO,"ldesc":));
   set_items(([
   "vines":"%^GREEN%^The vines here are thick.  They climb all over the pyramid and seem to be the only thing still holding it together.",
   ({"pyramid","building"}):"This building is huge.  It has four sides that each slant up to meet at a point"
" in the center top of the building.  Large granite slabs make up the building, but they appear to be crumbling"
" and broken due to age.  The vines that climb the sides may be the only things holding it together.  Near the top,"
" you can just make out what looks to be a hole leading into the building.",
   "hole":"%^BOLD%^%^BLACK%^The hole is dark and forboding.  You can probably enter it, but it doesn't give off any pleasant feelings.",
   "forest":"%^GREEN%^The forest spreads out in all directions beneath you.  To the northeast you can make out a city in the distance, and another to the northwest and southeast.  The forest looks dark and foreboding even from the vantage point up here.",
]));
   set_exits((["hole":INRMS+"shaft1","down":INRMS+"base"]));
}
string ldesc(string str){
   return("%^RESET%^This is the top of a large pyramid structure.  The view of the surrounding %^GREEN%^forest"
" %^RESET%^pans out in all directions.  The structure here is surprisingly devoid of any sort of life form."
"  In fact, the only thing really visible besides the thick masses of %^GREEN%^vines %^RESET%^is the"
" %^BOLD%^%^BLACK%^dark hole %^RESET%^that leads down into the depths of the pyramid.%^RESET%^");
} 

