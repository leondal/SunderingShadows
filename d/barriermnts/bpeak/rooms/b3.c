//b3.c
#include <std.h>
#include "../bpeak.h"
inherit IHRMS+"b.c";
int searched;

void create(){
::create();
   set_items(([
   ({"shores","shore","beach"}):"%^RESET%^%^ORANGE%^The sandy shores of the beach are a light orange in color and get %^BOLD%^%^BLACK%^darker %^RESET%^%^ORANGE%^nearer the %^CYAN%^waters %^ORANGE%^edge where the %^BOLD%^%^BLACK%^wet %^RESET%^%^ORANGE%^sands mark the %^CYAN%^tide %^ORANGE%^line.%^RESET%^",
   ({"water","waters","sea","ocean"}):"%^RESET%^%^CYAN%^The waters of the Dagger Sea reach out endless before you.  %^BOLD%^%^WHITE%^White capped %^CYAN%^w%^BOLD%^%^WHITE%^a%^RESET%^v%^CYAN%^e%^BOLD%^%^WHITE%^s %^RESET%^%^CYAN%^gently roll in on the %^ORANGE%^beach, %^CYAN%^while further out that faint outlines of %^ORANGE%^ships masts %^CYAN%^mark the horizon.%^RESET%^",
   "kelp":"%^RESET%^%^GREEN%^The kelp litters the beach and is a dark green color and looks much like long, slimey vines with elongated, thickly ribbed leaves.  Small, rounded bulbs seem to be attached to them in various places.%^RESET%^",
   "waves":"%^%^BOLD%^%^WHITE%^The waves here are maybe about two or three foot in height and crash over the rocks.%^RESET%^",
   ({"shells","seashells"}):"%^RESET%^The %^BOLD%^%^BLACK%^s%^RESET%^e%^BOLD%^%^WHITE%^a%^RESET%^s%^BOLD%^%^WHITE%^h%^BLACK%^e%^RESET%^l%^BOLD%^%^WHITE%^l%^BLACK%^s %^RESET%^litter the beach.  Most of them are broken and lay around this part of the beach in large pieces.",
   ({"crab","crabs"}):"%^BOLD%^%^BLACK%^More commonly known as hermit crabs, these small creatures are tiny and have made their homes in the various %^RESET%^shells %^BOLD%^%^BLACK%^that litter the %^RESET%^%^ORANGE%^beach.  %^BOLD%^%^BLACK%^They scurry across the %^RESET%^%^ORANGE%^sand %^BOLD%^%^BLACK%^and then quickly bury themselves from view.%^RESET%^",
   ({"city","walls","city walls"}):"%^RESET%^The outline of the city of Torm can be seen to the north.",
   ({"sand","sands"}):"%^RESET%^%^ORANGE%^The sand is course and gritty, polished to"
" a dull orange %^RESET%^shine %^ORANGE%^from constantly being turned by the"
" %^BOLD%^%^WHITE%^pounding %^RESET%^%^ORANGE%^of the small %^BOLD%^%^CYAN%^w"
"%^RESET%^%^CYAN%^a%^RESET%^v%^CYAN%^e%^BOLD%^%^CYAN%^s.  %^RESET%^%^ORANGE%^If you"
" look closely enough, you can see that the sand is actually composed of numerous"
" tiny pieces of %^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^WHITE%^c%^BLACK%^k,"
" %^RESET%^glass, %^ORANGE%^and %^RESET%^s%^BOLD%^%^WHITE%^e%^BLACK%^a%^WHITE%^s"
"%^RESET%^h%^BOLD%^%^BLACK%^e%^WHITE%^l%^RESET%^l%^BOLD%^%^WHITE%^s. "
" %^RESET%^%^ORANGE%^Mixed in with the sand are numerous small"
" %^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^WHITE%^c%^BLACK%^k%^RESET%^s"
" %^ORANGE%^that seem to get larger to the south as the beach gets closer to the"
" base of the %^BLUE%^Barrier Mountains. %^RESET%^",
   ({"mountains","mountain","Barrier Mountains","barrier mountains"}):"%^RESET%^%^BLUE%^To the southwest, the craggy peaks of the Barrier Mountains loom in the distance.%^RESET%^",
   ({"ships","masts"}):"%^RESET%^%^ORANGE%^The masts of various trade and fishing ships dot the horizon as they sail in and out of the Dagger Straights towards the seaport of Torm.",
   ({"fields","cornfields"}):"%^YELLOW%^Newly replanted cornfields can be seen through the %^GREEN%^trees %^YELLOW%^to the west.%^RESET%^",
   "rocks":"%^%^BOLD%^%^BLACK%^A few %^RESET%^r%^BOLD%^%^BLACK%^o%^WHITE%^c"
"%^BLACK%^k%^RESET%^s %^BOLD%^%^BLACK%^mix in with the %^RESET%^%^ORANGE%^sands"
" %^BOLD%^%^BLACK%^here, growing in size as the %^RESET%^%^ORANGE%^beach"
" %^BOLD%^%^BLACK%^winds closer to the base of the %^RESET%^%^BLUE%^mountains."
"  %^BOLD%^%^BLACK%^Large %^RESET%^r%^BOLD%^%^BLACK%^o%^WHITE%^c%^BLACK%^k%^RESET%^s"
" %^BOLD%^%^BLACK%^can be seen in the %^CYAN%^w%^RESET%^%^CYAN%^a%^BLUE%^t%^CYAN%^e"
"%^BOLD%^%^CYAN%^r, %^BLACK%^and the %^CYAN%^s%^RESET%^%^CYAN%^%^u%^BLUE%^r"
"%^BOLD%^%^CYAN%^f %^WHITE%^crashes %^BLACK%^over them.",
   "trees":"%^RESET%^%^GREEN%^A thin row of young trees line the beach to the west, just on the edge of where the sand gives way to the earth.  Through their thin branches, newly replanted %^ORANGE%^c%^YELLOW%^o%^RESET%^%^ORANGE%^rn%^YELLOW%^f%^RESET%^%^ORANGE%^ie%^YELLOW%^ld%^RESET%^%^ORANGE%^s %^GREEN%^can be seen.",
   ({"shadow","shadows"}):"%^BOLD%^%^BLACK%^The shadows of the %^RESET%^%^BLUE%^Barrier Mountains %^BOLD%^%^BLACK%^dance along the beach, making the rocks look even darker than they really are.%^RESET%^",
   ]));
   set_exits(([
   "northeast":INRMS+"b2",
   "southwest":INRMS+"t1",
   "northwest":"/d/player_houses/kiervalan/rooms/path",
   ]));
}
string ldesc(string str){
   return("%^RESET%^The %^ORANGE%^beach %^RESET%^begins to turn inland here,"
" gradually becoming more %^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^WHITE%^c%^BLACK%^"
"k%^RESET%^y %^RESET%^towards the south as it winds closer to the base of the"
" %^BLUE%^Barrier Mountains.  %^RESET%^The %^ORANGE%^sand %^RESET%^is"
" %^BOLD%^%^BLACK%^courser, %^RESET%^and the %^BOLD%^%^CYAN%^w%^RESET%^"
"%^CYAN%^a%^BLUE%^v%^CYAN%^e%^BOLD%^%^CYAN%^s %^WHITE%^crash %^RESET%^against a few"
" %^BOLD%^%^BLACK%^jagged rocks %^RESET%^that rest on the %^CYAN%^shoreline."
"  %^RESET%^To the west the outlines of newly replanted %^YELLOW%^c%^RESET%^"
"%^ORANGE%^or%^YELLOW%^nf%^RESET%^%^ORANGE%^ie%^YELLOW%^l%^RESET%^%^ORANGE%^d"
"%^YELLOW%^s %^RESET%^can be seen through the few %^GREEN%^trees %^RESET%^that"
" line the %^ORANGE%^beach.  %^RESET%^To the north, the walls of the"
" %^CYAN%^seaport %^RESET%^city of Torm are becoming increasingly small, looking"
" more like a small line off in the distance than the large city it is.  To the"
" south the %^BLUE%^mountains %^RESET%^are becoming larger and larger, looming over"
" you and casting their %^BOLD%^%^BLACK%^shadows %^RESET%^over everything"
" on this part of the %^ORANGE%^beach.  %^RESET%^Few %^RESET%^s%^BOLD%^"
"%^WHITE%^e%^BLACK%^a%^RESET%^s%^BOLD%^%^WHITE%^h%^BLACK%^e%^WHITE%^l%^RESET%^"
"l%^BOLD%^%^WHITE%^s %^RESET%^remain whole as it is evident that they've been"
" battered against the %^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^WHITE%^c%^BOLD%^"
"%^BLACK%^k%^RESET%^s and broken into the many course pieces that now litter the"
" %^ORANGE%^sand.  A %^ORANGE%^path %^RESET%^leads off to the southwest, heading into"
" the %^BOLD%^%^BLACK%^rocky terrain %^RESET%^towards the %^BLUE%^mountains.%^RESET%^");
}



