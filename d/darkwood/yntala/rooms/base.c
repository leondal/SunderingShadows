//base
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
   set_name("%^RESET%^The base of a grand pyramid");
   set_short("%^RESET%^The base of a great pyramid%^RESET%^");
   set_smell("default","The humidity is sickening as the air here is almost to thick to breath.");
   set_listen("default","Whispers and soft hisses seem to float on the breeze here, giving off an overall uneasy feeling.");
   set_long((:TO,"ldesc":));
   set_items(([
   "vines":"%^GREEN%^There are vines everywhere.  They hang down from the surrounding trees, blocking this area from view.  They even climb up the sides of the crumbling pyramid so thickly that it may be possible to climb them if you had some tools to help you.",
   "rocks":"Small pieces of the pyramid have crumbled due to age and now lay in small piles at the base of the pyramid.",
   ({"pyramid","building"}):"This building is huge.  It has four sides that each slant up to meet at a point in the center top of the building.  Large granite slabs make up the building, but they appear to be crumbling and broken due to age.  The vines that climb the sides may be the only things holding it together.  Near the top, you can just make out what looks to be a hole leading into the building.",
]));
   set_exits((["out":INRMS+"forest238"]));
   set_climb_exits((["climb":({INRMS+"top",15,4,100})
]));
}
string ldesc(string str){
   return("%^RESET%^You have moved through the %^GREEN%^vines %^RESET%^that concealed this area from view"
" and now stand before a large pyramid type building.   The %^GREEN%^trees %^RESET%^have been cleared away"
" and you are simply amazed that you did not see this structure from the %^ORANGE%^path.  %^RESET%^Perhaps"
" the %^GREEN%^forest %^RESET%^was thicker than originally anticipated.  The pyramid appears to be an ancient"
" structure and is composed entirely of large slabs of granite that have been tightly fitted together."
"  %^GREEN%^Vines %^RESET%^snake their way up the sides of the pyramid and perhaps are some of the few"
" things holding the crumbling slabs together.  At the base of the pyramid, pieces of rock have fallen off"
" of the structure and lay in small heaps, making it difficult to maneuver around them.%^RESET%^");
} 

