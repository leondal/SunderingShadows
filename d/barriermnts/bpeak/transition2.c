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
   set_smell("default","The cool mountain breeze rolls down from the peaks of the Barrier Mountains");
   set_listen("default","%^RESET%^It is quiet.");
   set_items(([
   "path":"%^RESET%^%^ORANGE%^The path is rocky at best, and doesn't appear to be very well travelled.%^RESET%^",
   "mountains":"%^RESET%^%^BLUE%^The mountains hover over you to the south and look rather imposing.%^RESET%^",
   "rocks":"%^BOLD%^%^BLACK%^Large rocks line the path and litter the area.%^RESET%^",
   ]));
   set_search("default", "%^ORANGE%^It seems pretty bare here.  Just rocks, rocks, and more rocks.%^RESET%^");
}
string ldesc(string str){
   return("%^RESET%^The %^ORANGE%^path %^RESET%^seems to get even more"
" %^BOLD%^%^BLACK%^rocky %^RESET%^as it winds closer to the base of the"
" %^BLUE%^mountains.  %^RESET%^To the southwest the %^ORANGE%^path %^RESET%^begins"
" its ascent up the base of the %^BLUE%^mountains %^RESET%^and their many cliffs"
" are now visibly taking form as they hover ominously over the area.  There does"
" not appear to be an easy way into the %^BLUE%^mountains %^RESET%^that you can"
" see.%^RESET%^\n");
}
