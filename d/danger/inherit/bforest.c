#include <std.h>
#include "../danger.h"

inherit MINHERIT;

void create(){ 
   ::create();
   set_property("indoors",0);
   set_property("light",1);
   set_terrain(HEAVY_FOREST);
   set_travel(FRESH_BLAZE);
   set_name("%^RESET%^%^GREEN%^In the Great Forest");
   set_short("%^RESET%^%^GREEN%^In The Great Forest");
   set_long((:TO,"long_desc":));
   set("night long",(:TO,"night_desc":));
}

string long_desc() {
return("%^RESET%^%^GREEN%^You are in a large forest. The green"+
" foilage on the ground runs as far as the eye can see. All"+
" around massive %^RESET%^%^RED%^redwood"+
" %^RESET%^%^GREEN%^trees"+
" reach towards the heavens ans their awe inspiring canopies"+
" nearly block out the sun. However, just enough"+ 
" %^RESET%^%^ORANGE%^rays of light%^RESET%^%^GREEN%^"+ 
" pierce the thick canopy to light ground below.");
}
string night_desc() {
return("%^BOLD%^%^BLACK%^You are in a large forest. It is"+
" nearly pitch black as the %^RESET%^moonlight"+
" %^BOLD%^%^BLACK%^is not nearly strong enough to pierce"+
" the thick canopy created by the massive"+
" %^RESET%^%^RED%^redwood%^BOLD%^%^BLACK%^ trees. In the"+
" dead of night, the once majestic trees, almost foreshadow"+
" an unseen danger all around you.");
}