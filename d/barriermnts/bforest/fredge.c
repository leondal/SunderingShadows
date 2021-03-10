//bpath2
#include <std.h>
#include <rooms.h>
#include "bforest.h"
inherit PIER;


void create(){
::create();
   set_property("light",2);
   set_travel(RUTTED_TRACK);
   set_terrain(LIGHT_FOREST);
   set_water_body("river");
   set_name("%^RESET%^%^GREEN%^Along the banks of a slow moving river%^RESET%^");
   set_short("%^RESET%^%^GREEN%^Along the banks of a slow moving river%^RESET%^");
   set_long((:TO,"ldesc":));
   set("night long","%^RESET%^%^GREEN%^The %^ORANGE%^path %^GREEN%^opens up here, into a part of the forest that"
" seems to be a very peaceful area, most likely because of the lazy %^BOLD%^%^CYAN%^river"
" %^RESET%^%^GREEN%^that slowly snakes its way between the trees.  The huge, %^BLUE%^blue mountains"
" %^GREEN%^that surround this forest can still be seen above the treeline in all directions, making"
" this feel like a truly secluded spot.  %^ORANGE%^Pine cones %^GREEN%^litter the ground along with"
" pine needles and a few leaves from the low growing vegetation.  Birds sing above you and a few"
" forest animals can be seen moving through nearby paths.  The occassional large"
" %^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^WHITE%^c%^BLACK%^k %^RESET%^%^GREEN%^sets at the river"
" edge, creating the perfect spot to sit, relax and enjoy both the %^RESET%^starry night %^RESET%^%^GREEN%^and"
" %^CYAN%^cool mountain air.%^RESET%^\n");
  set_smell("default","You smell dank vegetation.%^RESET%^");
   set_smell("default","%^RESET%^%^GREEN%^The fresh scent of pine drifts along the breeze.%^RESET%^");
   set_listen("default","%^BOLD%^The song of birds fills the air%^RESET%^.");
   set_items(([
   ({"water","river"}):"%^RESET%^%^CYAN%^The river is fed by the waterfall that cascades down the cliffs to the north of this forest.  The river moves at a slow, relaxed pace and is teaming with fish.%^RESET%^",
   ({"trees","forest"}):"%^RESET%^%^GREEN%^This part of the forest is composed of large pine trees that tower above many other kinds of shorter trees, including oak, maple and the occassion willow. The forest floor is rich with various bushes, ferns, vines and the occassional bramble.%^RESET%^",
   ({"pine cones","cones"}):"%^RESET%^%^ORANGE%^Pine cones of various sizes litter the forest floor.%^RESET%^",
   ({"rock","rocks"}):"%^BOLD%^%^WHITE%^A few rocks line the edge of the river, making an excellent place to sit and relax.",
    "mountains":"%^RESET%^%^BLUE%^Tall, blue mountains loom above the forest in all directions.",
   ]));
   set_search("default", "%^ORANGE%^Nothing here really looks interesting.%^RESET%^");
   set_max_fishing(4);
   set_chance(17);
   set_max_catch(6);
   set_fish( ([ "Issaquah Trout": 10, "Big Kahuna": 5 ]) );
}
string ldesc(string str){
   return("%^RESET%^%^GREEN%^The %^ORANGE%^path %^GREEN%^opens up here, into a part of the forest that"
" seems to be a very peaceful area, most likely because of the lazy %^BOLD%^%^CYAN%^river"
" %^RESET%^%^GREEN%^that slowly snakes its way between the trees.  The huge, %^BLUE%^blue mountains"
" %^GREEN%^that surround this forest can still be seen above the treeline in all directions, making"
" this feel like a truly secluded spot.  %^ORANGE%^Pine cones %^GREEN%^litter the ground along with"
" pine needles and a few leaves from the low growing vegetation.  Birds sing above you and a few"
" forest animals can be seen moving through nearby paths.  The occassional large"
" %^BOLD%^%^BLACK%^r%^RESET%^o%^BOLD%^%^WHITE%^c%^BLACK%^k %^RESET%^%^GREEN%^sets at the river"
" edge, creating the perfect spot to sit, relax and soak up both the %^YELLOW%^sun %^RESET%^%^GREEN%^and"
" %^CYAN%^cool mountain air.%^RESET%^\n");
}
