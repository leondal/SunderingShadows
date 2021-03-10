#include <std.h>
#include "yntala.h"
inherit PIER;

void create(){
::create();

  set_property("light",2);
  set_water_body("river");
  set_terrain(MEADOWLANDS);
  set_travel(FOOT_PATH);
  set_name("%^BOLD%^%^CYAN%^River bank%^RESET%^");
  set_short("%^RESET%^%^ORANGE%^%^At the edge of %^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^i%^BLUE%^v%^CYAN%^e%^BOLD%^%^CYAN%^r%^RESET%^%^");
   set_long((:TO,"ldesc":));
   set_smell("default","%^BOLD%^%^GREEN%^You can smell nothing but freshness.%^RESET%^");
   set_listen("default","%^RESET%^%^CYAN%^You can hear the water flowing by.%^RESET%^");
   set_items(([
      ({"river","water"}):"%^BOLD%^%^CYAN%^The water here is fresh and %^RESET%^c%^CYAN%^l%^BOLD%^%^WHITE%^e%^RESET%^%^CYAN%^a%^RESET%^r, %^BOLD%^%^CYAN%^and seems to move along at a relaxed pace.%^RESET%^",
      "forest":"%^GREEN%^The tall trees of the forest grow right up to the edges of the %^BOLD%^%^CYAN%^w%^RESET%^%^CYAN%^a%^BLUE%^t%^CYAN%^e%^BOLD%^%^CYAN%^r.%^RESET%^",
      "vegetation":"%^BOLD%^%^GREEN%^The vegetation here is thick and lush.%^RESET%^",
      "shadows":"%^BOLD%^%^BLACK%^Shadows from the %^RESET%^%^GREEN%^plants %^BOLD%^%^BLACK%^dance across the %^BOLD%^%^CYAN%^w%^RESET%^%^CYAN%^a%^BLUE%^t%^CYAN%^e%^BOLD%^%^CYAN%^r%^RESET%^.",
      "trees":"%^RESET%^%^GREEN%^The trees here are as tall as the rest you'd find in the forest, and covered with %^BOLD%^%^GREEN%^vi%^RESET%^%^GREEN%^n%^BOLD%^%^GREEN%^es %^RESET%^%^GREEN%^that hang down over the water.%^RESET%^",
]));
}
string ldesc(string str){
   return("%^RESET%^%^ORANGE%^You find yourself on the banks of a"
" %^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^i%^BLUE%^v%^CYAN%^e"
"%^BOLD%^%^CYAN%^r.  %^RESET%^%^ORANGE%^The %^GREEN%^forest"
" %^ORANGE%^comes right up to the edges of the %^CYAN%^serene"
" %^BOLD%^%^CYAN%^water, %^RESET%^%^ORANGE%^and the thick"
" %^GREEN%^vegetation %^ORANGE%^casts %^BOLD%^%^BLACK%^shadows"
" %^RESET%^%^ORANGE%^over the %^RESET%^c%^BOLD%^%^WHITE%^l%^RESET%^"
"e%^BOLD%^%^WHITE%^a%^RESET%^r %^ORANGE%^depths, creating shelter"
" and %^BOLD%^%^BLACK%^shade %^RESET%^%^ORANGE%^for whatever may"
" be living down there.%^RESET%^\n");
} 
