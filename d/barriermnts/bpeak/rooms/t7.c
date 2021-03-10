//t7.c
#include <std.h>
#include "../bpeak.h"
inherit ROOM;


void create(){
::create();
   set_property("light",2);
   set_travel(FOOT_PATH);
   set_terrain(ROCKY);
   set_name("%^RESET%^At the base of the mountains");
   set_short("%^RESET%^A path along the base of the mountains%^RESET%^");
   set_long((:TO,"ldesc":));
   set_smell("default","The cool mountain breeze rolls down from the peaks of the Barrier Mountains");
   set_listen("default","%^RESET%^Strange sounds echo down from the mountains.");
   set_items(([
   "path":"%^RESET%^%^ORANGE%^The path is rocky at best, and doesn't appear to be very well travelled.%^RESET%^",
   "mountains":"%^RESET%^%^BLUE%^The mountains hover over you and look rather imposing.%^RESET%^",
   "rocks":"%^BOLD%^%^BLACK%^Large rocks line the path and litter the area.%^RESET%^",
   "cliffs":"%^RESET%^%^BLUE%^Large cliffs rise high into the sky.  Their faces are sheer and look impossible to climb.%^RESET%^",
   "trees":"%^RESET%^%^GREEN%^The trees here are tall and scraggly.%^RESET%^",
   "ravine":"This ravine is small and narrow.",
   ]));
   set_search("default", "%^ORANGE%^It seems pretty bare here.  Just rocks, rocks, and more rocks.%^RESET%^");
   set_exits(([
"south":INRMS+"bcliff","north":INRMS+"t6"
]));
}
string ldesc(string str){
   return("%^RESET%^Here lays the base of the great %^BLUE%^Barrier Mountains."
"  %^RESET%^Large %^BOLD%^%^BLACK%^cliffs %^RESET%^jut into the sky with more"
" %^BLUE%^mountains %^RESET%^rising behind them.  A small %^ORANGE%^ravine"
" %^RESET%^lies between the two nearest %^BLUE%^mountains %^RESET%^and the"
" %^ORANGE%^path %^RESET%^continues to wind its way up through it, hugging the"
" western cliff face tightly.  %^BOLD%^%^BLACK%^Rocks %^RESET%^lie everywhere and"
" further up the %^ORANGE%^path %^RESET%^you can see a few scraggly"
" %^GREEN%^pine trees %^RESET%^clinging to life in the mountainous"
" terrain.%^RESET%^\n");
}
