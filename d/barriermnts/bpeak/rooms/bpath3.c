//bpath3
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit PIER;



void create(){
::create();
   set_property("light",2);
   set_travel(GAME_TRACK);
   set_terrain(ROCKY);
   set_water_body("river");
   set_name("%^RESET%^%^CYAN%^At the bottom of a waterfall%^RESET%^");
   set_short("%^RESET%^%^CYAN%^The bottom of a waterfall%^RESET%^");
   set_long((:TO,"ldesc":));
   set_smell("default","%^RESET%^%^CYAN%^Water is constantly being splashed on you!%^RESET%^");
   set_listen("default","%^BOLD%^%^CYAN%^The roar of the waterfall is deafening%^RESET%^.");
   set_items(([
   ({"waterfall","fall"}):"%^BOLD%^%^CYAN%^The waterfall falls out of an opening in the cliff face about one hundred feet above you, making its way down through the chasm that it created in the ledge there.%^RESET%^",
   "ledge":"%^RESET%^%^ORANGE%^The ledge sticks out about thirty feet from the face of the cliff.  A chasm has been eroded away due to the fall, but a bridge seems to connect the two sides together.%^RESET%^",
   "bridge":"%^RESET%^%^ORANGE%^The bridge connects the two sides of the ledge together and looks to be quite sturdy.  It sets about fifteen feet away from the fall itself, but by the way it glistens you can tell from even here that it is very wet.%^RESET%^",
   "cliff":"The cliff rises to about five hundred feet above you.  It is completely sheer with the exception of a ledge where the bridge is and another ledge above that.  It looks like you might be able to climb up to the first ledge from here.",
   "pool":"%^BOLD%^%^BLUE%^A deep pool of water is here.  The water from the fall constantly pummels into it, splashing everything in the area.%^RESET%^",
   "river":"%^RESET%^%^CYAN%^The river flows out of the pool and into the forest to the south where it disappears from sight.%^RESET%^",
   "forest":"%^RESET%^%^GREEN%^To the south of this area is a forest of large pine trees.  They grow right up to the base of the cliff.%^RESET%^",
   "rocks":"%^BOLD%^%^BLACK%^Large, jagged rocks line the edges of the area here.  They look just like the rocks you would find on the cliff.%^RESET%^",
   ]));
   set_search("default", "%^ORANGE%^Nothing here really looks interesting.%^RESET%^");
   set_exits((["southwest":INRMS+"bpath2"]));
   set_climb_exits((["climb":({INRMS+"bcliff7",20,4,100})]));
}
string ldesc(string str){
   return("%^RESET%^A %^BOLD%^%^CYAN%^waterfall %^RESET%^pours out of the side of"
" the cliff that looms over five hundred feet above this area, forming a"
" %^BOLD%^%^BLUE%^deep pool %^RESET%^of %^CYAN%^water %^RESET%^here.  A"
" %^BOLD%^%^BLUE%^river %^RESET%^feeds off of the %^BOLD%^%^BLUE%^pool"
" %^RESET%^and disappears into the %^GREEN%^forest %^RESET%^to the south.  The"
" %^BOLD%^%^BLACK%^shadow %^RESET%^of the %^ORANGE%^bridge %^RESET%^falls across"
" the %^CYAN%^water, %^RESET%^making it look even %^BOLD%^%^BLACK%^darker"
" %^RESET%^and more foreboding than it probably really is.  Sheer"
" %^BOLD%^%^BLACK%^c%^RESET%^l%^BOLD%^%^WHITE%^i%^BLACK%^f%^RESET%^f%^BOLD%^"
"%^BLACK%^s %^RESET%^rise up on either side of the %^BOLD%^%^BLUE%^pool"
" %^RESET%^as though the %^CYAN%^water %^RESET%^from the %^BOLD%^%^CYAN%^fall"
" %^RESET%^had carved its own path right through the already existing ledge on its"
" way down.  Adding further evidence to this theory are the large, jagged chunks of"
" %^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^BLACK%^c%^RESET%^k%^BOLD%^%^BLACK%^s"
" %^RESET%^that line the edges of this area.  A path leading into the %^GREEN%^forest %^RESET%^heads south from here.%^RESET%^\n");
} 


