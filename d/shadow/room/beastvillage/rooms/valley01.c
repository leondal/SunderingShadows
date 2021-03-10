#include <std.h>
#include "../defs.h"
inherit ROOM;

void create() {
        ::create();
        set_property("indoors",0);  
        set_property("light",2); 
   set_terrain(NEW_MOUNTS); 
   set_travel(FOOT_PATH); 
        set_name("A ledge beside a waterfall");    
        set_short("%^BOLD%^%^WHITE%^A ledge beside a waterfall%^RESET%^");

        set_long("%^BOLD%^%^WHITE%^A ledge beside a waterfall%^RESET%^\n"
"This ledge is little more then a large pile of rocks and boulders that has "
"tumbled to the side of the waterfall.  From here you can see a lush "
"%^GREEN%^fertile valley%^WHITE%^ in the distance, while further on the "
"%^BLUE%^Clarkril River%^WHITE%^ makes its way over the wide Yniam Plains. "
"Beside you, the waterfall rushes with deafening sound as the water spills "
"down from one tier to the next.  Spray from the falls soaks you through "
"and through, and the swirls of mist obscure your view at times. A few %^GREEN%^vines "
"%^RESET%^creep up the side of the mountain toward a small path at the top, and more "
"lead further downwards...%^RESET%^\n");

        set_smell("default","The clean scent of fresh water fills the air.");
        set_listen("default","The roar of the waterfall is deafening.");

        set_items(([
           ({"ledge","waterfall"}) : "%^BOLD%^%^CYAN%^The waterfall is a "
"massive structure created by a long ago shifting of the mountains. A landslide "
"that once tumbled down from the highest peaks has made a tiered pile of stones "
"that form the various troughs of the waterfall creating a cascade of smaller "
"falls that tumble down into the plains below. One stone off to the side seems "
"to have an odd %^YELLOW%^carving %^CYAN%^into its rough surface.%^RESET%^",

           ({"vines","cliff" }) : "%^BOLD%^%^WHITE%^You think you might be able "
"to climb up the vines and reach the ledge above if you had the right tools or "
"were skilled enough. Alternatively, you could try to descend them to reach the "
"rough stone path you can see below.%^RESET%^ ",

           ({"river"}) : "%^BOLD%^%^CYAN%^Formed by the many streams and "
"snowmelts from the %^WHITE%^Charu Mountains%^CYAN%^, the headwaters of this river are "
"swiftly flowing as they reach this point, pouring over the %^BLUE%^waterfall "
"%^CYAN%^before forming into the wide %^WHITE%^Clarkril River %^CYAN%^you see in the "
"distance. From here you can see all the way across the Yniam Plains to the distant "
"headwaters of the Dagger Straights.%^RESET%^",

           ({"stone","carving"}) : "%^BOLD%^%^CYAN%^One stone off to the side seems "
"to have an odd %^YELLOW%^carving %^CYAN%^into its rough surface.  It forms the "
"sketchy outline of what must be a %^RED%^r%^YELLOW%^a%^RESET%^%^ORANGE%^i%^GREEN%^n"
"%^BOLD%^%^CYAN%^b%^BLUE%^o%^RESET%^%^MAGENTA%^w%^BOLD%^%^CYAN%^, its beams "
"branching out from a %^WHITE%^cloudburst%^CYAN%^.  Beneath it are etched a few "
"letters that spell out %^RESET%^%^MAGENTA%^'%^BOLD%^'%^WHITE%^LURUE%^MAGENTA%^'"
"%^RESET%^%^MAGENTA%^'%^BOLD%^%^CYAN%^.%^RESET%^",

        ]));

   set_climb_exits(([
     "climb":({ROOMS"beast08",15,15,100}),
     "descend":({ROOMS"valley02",15,15,100}),
   ]));
}
