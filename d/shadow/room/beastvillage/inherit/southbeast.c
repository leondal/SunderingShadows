#include <std.h> 
#include "../defs.h" 
inherit ROOM; 

void create(){ 
   ::create(); 
   set_property("light",2); 
   set_property("indoors",0); 
   set_terrain(NEW_MOUNTS); 
   set_travel(FOOT_PATH); 
   set_name("A sloping trail"); 
   set_short("%^RESET%^%^ORANGE%^A sloping trail%^RESET%^");
   set_long("%^RESET%^A sloping trail\n"
"%^RESET%^%^ORANGE%^Here a steeply sloping trail makes its way down "
"the edge of the %^YELLOW%^Charu Mountains %^RESET%^%^ORANGE%^toward an open "
"%^GREEN%^grassy area %^ORANGE%^spotted by a few %^GREEN%^trees%^ORANGE%^.  From "
"your perch this high up, it would look almost as if the grassy land might once "
"have been a large %^CYAN%^lake%^ORANGE%^, but the water has long since dried up "
"and left little more then a large concave bowl of grass.  To the north, beyond "
"a quickly flowing %^BOLD%^%^CYAN%^river%^RESET%^%^ORANGE%^, you can make out "
"the sight of a %^BOLD%^%^GREEN%^fertile valley %^RESET%^%^ORANGE%^opening up "
"between two mountains.%^RESET%^"); 
   set_smell("default","The air is crisp and clean here."); 
   set_listen("default","The sounds of nature are all around you."); 

   set_items(([ 
({"mountain","mountains" }) : "%^BOLD%^%^WHITE%^All around you "
"stretch the peaks of the Charu Mountains.  Their towering forms casting a "
"shadow upon the narrow path.  Snow capped most of the year, the run off "
"feeds several small streams that work their way down toward a the headwaters "
"that form the Clarkril River.%^RESET%^",

({"valley","plains"}):"%^GREEN%^Down below, where the Charu Mountains give "
"way to the Yniam Plains, you can see that a small valley opens up to the north. "
"Tucked between the foothills, its difficult to make out any details.%^RESET%^", 

({"grassy area","bowl","lake"}):"%^GREEN%^A large open area of grass spans to the "
"south where this trail leads.  From the advantage of height, it seems that this "
"concave area was likely once a large lake that has since dried up.  But where "
"did all that water go?%^RESET%^", 

({"trees","holes"}):"%^GREEN%^From this vantage point you can make out where trees "
"have tumbled over and where holes in the ground have opened when their roots were "
"torn free.  The dark gaping holes look like unhealed wounds upon the smooth grass "
"covered area. %^RESET%^",

({"river"}):"%^BOLD%^%^BLUE%^In the distance you can see a swiftly flowing river "
"making its way across the Yniam Plains.  Fed by a nearby waterfall, the river is "
"created by several smaller mountain streams that come together from the snowmelt "
"further up the mountains.%^RESET%^",
   ])); 
} 
