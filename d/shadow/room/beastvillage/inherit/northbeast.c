#include <std.h> 
#include "../defs.h" 
inherit ROOM; 

void create(){ 
   ::create(); 
   set_property("light",2); 
   set_property("indoors",0); 
   set_terrain(NEW_MOUNTS); 
   set_travel(FOOT_PATH);  
   set_name("A narrow path in the mountains"); 
   set_short("%^YELLOW%^A narrow path in the mountains%^RESET%^");
    set_long("%^YELLOW%^A narrow path in the mountains%^RESET%^\n"
"%^RESET%^%^ORANGE%^Following a swiftly flowing mountain %^CYAN%^stream%^ORANGE%^, "
"the trail leads steeply down from the high %^YELLOW%^Charu Mountains "
"%^RESET%^%^ORANGE%^toward a lush and %^BOLD%^%^GREEN%^fertile valley %^RESET%^%^ORANGE%^"
"below. Though steep, the path is wide and free of brambles, likely kept that way by the "
"%^BOLD%^%^CYAN%^spring flooding %^RESET%^%^ORANGE%^that comes with "
"%^BOLD%^%^WHITE%^snowmelt%^RESET%^%^ORANGE%^.  Rocks, stones and water logged pieces "
"of wood line the path to the side where the river traverses, forming a border on one "
"side, while the other sports small %^GREEN%^shrubs %^ORANGE%^and the occasional pine, "
"oak or spruce tree.  Further on you can see a small protected %^GREEN%^valley "
"%^ORANGE%^stretching off to the north.%^RESET%^"); 
   set_smell("default","The clean scent of fresh water fills the air."); 
   set_listen("default","You hear the burble of a fast moving stream."); 

   set_items(([ 
           ({"mountain","mountains" }) : "%^BOLD%^%^WHITE%^All around you "
"stretch the peaks of the Charu Mountains.  Their towering forms casting a "
"shadow upon the narrow path.  Snow capped most of the year, the run off "
"feeds several small streams that work their way down toward a the headwaters "
"that form the Clarkril River.%^RESET%^",

({"valley","plains"}):"%^GREEN%^Down below, where the Charu Mountains give "
"way to the Ynaim Plains, you can see that a small valley opens up to the north. "
"Tucked between the foothills, its difficult to make out any details.%^RESET%^", 

({"shrubs","trees","pine","oak","spruce"}):"%^GREEN%^Trees and shrubs grow along "
"the side of the path, following the slope of the mountain side as it gives sharply "
"away to the plains below.%^RESET%^",

({"rocks","stones","water","stream"}):"%^BOLD%^%^CYAN%^The stream flows swiftly "
"along over a tumble of small rocks that have made their way down from the heights "
"above.  Their smooth rounded shape created by years of tumbling and smoothing "
"effects of the many streams that are created by the snowmelt.%^RESET%^",
   ])); 
}
