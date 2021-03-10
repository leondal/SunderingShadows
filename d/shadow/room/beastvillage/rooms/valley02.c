#include <std.h>
#include "../defs.h"
inherit ROOM;

void create() {
   ::create();
   set_property("indoors",0);  
   set_property("light",2); 
   set_terrain(NEW_MOUNTS); 
   set_travel(FOOT_PATH); 
   set_name("A rough stone path beside a waterfall");    
   set_short("%^BOLD%^%^WHITE%^A rough stone path beside a waterfall%^RESET%^");

   set_long("%^BOLD%^%^WHITE%^A rough stone path beside a waterfall%^RESET%^\n"
"This rugged pathway seems to have fallen into place naturally, with rocks "
"and boulders tumbled haphazardly into place beside the waterfall.  You seem to "
"have descended into a lush, %^GREEN%^fertile valley%^WHITE%^ hemmed on all sides "
"by mountain ridges, while further on the %^BLUE%^Clarkril River%^WHITE%^ weaves "
"between the stone outcroppings and is lost to view.  Beside you, the waterfall "
"rushes with deafening sound as the water spills down from one tier to the next.  "
"Spray from the falls soaks you through and through, and the swirls of mist obscure "
"your view at times. A few %^GREEN%^vines %^RESET%^creep up the side of the mountain "
"toward a ledge above, while the path itself leads away from the falls and into the "
"forest.%^RESET%^\n");

   set_smell("default","The clean scent of fresh water fills the air.");
   set_listen("default","The roar of the waterfall is deafening.");

   set_items(([
           ({"ledge","waterfall","path"}) : "%^BOLD%^%^CYAN%^The waterfall is a "
"massive structure created by a long ago shifting of the mountains.  A landslide "
"that once tumbled down from the highest peaks has made a tiered pile of stones "
"that form the various troughs of the waterfall creating a cascade of smaller "
"falls that tumble down into the plains below.  Even the rugged path you stand "
"upon was probably caused by this disruption.  It leads down and away from the "
"spray of the tumbling water.%^RESET%^",

           ({"vines","cliff" }) : "%^BOLD%^%^WHITE%^You think you might be able "
"to climb up the vines and reach the ledge above if you had the right tools or "
"were skilled enough.%^RESET%^ ",

           ({"river"}) : "%^BOLD%^%^CYAN%^Formed by the many streams and "
"snowmelts from the %^WHITE%^Charu Mountains%^CYAN%^, the headwaters of this river "
"pour over the %^BLUE%^waterfall %^CYAN%^above, before calming further down "
"the valley to form the wide %^WHITE%^Clarkril River %^CYAN%^you can see "
"below. It weaves away between mountain ridges that rise up around you, "
"impeding much further view of its course.%^RESET%^",

        ]));

   set_exits(([ 
     "northeast":ROOMS"valley03",
   ])); 
   set_climb_exits((["climb":({ROOMS"valley01",15,15,100})]));
}
