#include <std.h> 
#include "../defs.h" 
inherit ROOM; 

void create(){ 
   ::create(); 
   set_property("light",2); 
   set_property("indoors",0); 
   set_terrain(NEW_MOUNTS); 
   set_travel(FOOT_PATH);  
   set_name("A gravely shore"); 
   set_short("%^RESET%^%^ORANGE%^A gravely shore%^RESET%^"); 
   set_long("%^RESET%^%^ORANGE%^A gravely shore%^RESET%^\n"
"%^BOLD%^%^WHITE%^Here the path levels and widens out to form a %^RESET%^gravely "
"shore %^BOLD%^%^WHITE%^where a river cuts swiftly across the sharply descending path. "
"The torrent broken only by a series of large, flat stones that appear to be the tops "
"of boulders evenly spaced across the river.  Water %^CYAN%^rushes %^WHITE%^quickly "
"around these stones before tumbling from a ledge a scant few feet away, forming a "
"multi-tiered %^BLUE%^waterfall %^WHITE%^where more boulders cluster together to form "
"troughs and pools before allowing the water to fall to another tier.%^RESET%^"); 
   set_smell("default","The clean scent of fresh water fills the air."); 
   set_listen("default","The roar of the waterfall is deafening."); 

   set_items(([ 
           ({"mountain","mountains" }) : "%^BOLD%^%^WHITE%^All around you "
"stretch the peaks of the Charu Mountains.  Their towering forms casting a "
"shadow upon the narrow path.  Snow capped most of the year, the run off "
"feeds several small streams that work their way down toward a the headwaters "
"that form the Clarkril River.%^RESET%^",

	   ({"stream","headwater","streams"}) : "%^BOLD%^%^CYAN%^The swiftly "
"flowing headwaters of the Clarkril River start here.  Formed by several "
"mountain streams, the wide pool of water collects here and then flows "
"over a cliff and down into the Yniam Plains below.%^RESET%^",

           ({"ledge","waterfall" }) : "%^BOLD%^%^CYAN%^The waterfall is a "
"massive structure created by a long ago shifting of the mountains.  A landslide "
"that once tumbled down from the highest peaks has made a tiered pile of stones "
"that form the various troughs of the waterfall creating a cascade of smaller "
"falls that tumble down into the plains below.%^RESET%^",

           ({"stone","stones" }) : "%^BOLD%^%^WHITE%^Stepping stones cross the "
"swiftly flowing headwaters, forming a bridge of sorts to cross from one shore "
"to the other.  Each stone sticks up out of the water far enough to avoid being "
"completely engulfed in the water.  %^RESET%^",
   ])); 
} 
