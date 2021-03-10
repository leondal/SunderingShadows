#include <std.h>
#include "bpeak.h"
inherit ROOM;


void create(){
::create();
   set_property("light",2);
   set_travel(FOOT_PATH);
   set_terrain(ROCKY);
   set_name("%^RESET%^A rocky path");
   set_short("%^RESET%^A rocky path%^RESET%^");
   set_long((:TO,"ldesc":));
   set_smell("default","%^RESET%^%^CYAN%^The smell of salt water lingers in the air.%^RESET%^");
   set_listen("default","%^RESET%^The gentle sounds of the sea can be heard.");
   set_items(([
   "path":"%^RESET%^%^ORANGE%^The path is rocky at best, and doesn't appear to be very well travelled.%^RESET%^",
   "mountains":"%^RESET%^%^BLUE%^The mountains hover over you to the south and look rather imposing.%^RESET%^",
   "sand":"A few flecks of sand line the path, most likely having been tracked in from the beach to the north.",
   "sea":"%^RESET%^%^CYAN%^A view of the sea can still be seen to the east over the large rocks that line the path.%^RESET%^",
   "rocks":"%^BOLD%^%^BLACK%^Large rocks line the path and litter the area.%^RESET%^",
   ]));
   set_search("default", "%^ORANGE%^It seems pretty bare here.  Just rocks, rocks, and more rocks.%^RESET%^");
}
string ldesc(string str){
   return("%^RESET%^This small %^ORANGE%^path %^RESET%^winds away from the"
" %^ORANGE%^beach %^RESET%^and leads towards the %^BLUE%^mountains %^RESET%^to"
" the south.  The ground is beginning to get %^BOLD%^%^BLACK%^rocky %^RESET%^and"
" the only %^ORANGE%^s%^RESET%^a%^ORANGE%^n%^BOLD%^%^WHITE%^d %^RESET%^present is"
" what has been tracked in from the %^ORANGE%^beach %^RESET%^to the north.  The"
" sounds of the %^CYAN%^sea %^RESET%^can still be heard and you still catch glimpses"
" of it to the east over the %^BOLD%^%^BLACK%^large rocks %^RESET%^that line the"
" path.%^RESET%^\n");
}

