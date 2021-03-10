//bcliff4
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit ROOM;




void create(){
::create();
   set_property("light",2);
   set_travel(GAME_TRACK);
   set_terrain(ROCKY);
   set_name("%^RESET%^The bottom of a %^BOLD%^%^BLACK%^c%^RESET%^l%^BOLD%^%^WHITE%^i%^BLACK%^f%^%RESET%^f");
   set_short("%^RESET%^The bottom of a %^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^WHITE%^c%^BLACK%^k%^RESET%^y c%^BOLD%^%^WHITE%^l%^BLACK%^i%^RESET%^f%^BOLD%^%^BLACK%^f%^RESET%^");
   set_long((:TO,"ldesc":));
   set_smell("default","%^RESET%^%^GREEN%^The scent of pine from the forest below wafts up here.%^RESET%^");
   set_listen("default","%^BOLD%^%^BLUE%^The roar of a nearby waterfall can be heard%^RESET%^.");
   set_items(([
   "cliff":"%^BOLD%^%^BLACK%^The cliff towers more than four hundred feet above you and gives off an eerie feeling.",
   "shadow":"%^BOLD%^%^BLACK%^The shadow of the cliff falls over the ravine below.%^RESET%^",
   "rocks":"Large rocks line the path, making it difficult to maneuver around here.  Some are merely a few feet in diameter, while others stand to nearly six feet tall.",
   "path":"%^RESET%^%^ORANGE%^The path is worn out and looks to be seldom used.  In fact, it down right looks abandoned.%^RESET%^",
   ({"trees","pine trees","tree","pines"}):"%^RESET%^%^GREEN%^A few pine trees cling to life here as they attempt to grow amongst the rocks.  Their needles are weak and the branches fairly bare, but somehow they still grow to be quite tall.%^RESET%^",
   "valley":"%^RESET%^%^GREEN%^The valley is filled with a lush forest that grows around a winding river.%^RESET%^",
   "forest":"%^RESET%^%^GREEN%^The forest grows around a winding river and looks to be quite healthy and peaceful.%^RESET%^",
   "river":"%^BOLD%^%^BLUE%^A river winds its way through the base of the valley.%^RESET%^",
   ]));
   set_exits((["south":INRMS+"bcliff5"]));
   set_climb_exits((["descend":({INRMS+"bcliff3",20,4,100})
]));

}
string ldesc(string str){
   return("%^RESET%^As you climb to the crest of the steepest part of the path,"
" a grand view spans out before you.  To the south is a deep %^GREEN%^valley"
" %^RESET%^nestled between the %^BLUE%^mountains %^RESET%^and is filled with a"
" %^GREEN%^forest %^RESET%^that grows around a %^BOLD%^%^BLUE%^winding river."
"%^RESET%^  The cliff still hovers above you and it casts a %^BOLD%^%^BLACK%^shadow"
" %^RESET%^across the forest below.  The path continues a bit to the south before"
" it turns back west, following the edge of the cliff as it leads further up the"
" mountainside.%^RESET%^\n");
} 

