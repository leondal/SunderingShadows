//bunderwater.c
#include <std.h>
#include "yntala.h"
inherit IHRMS+"inuw";

void create(){
    
::create();
   set_property("indoors",1);
   set_property("light",2);
   set_property("no_sticks",1);
   set_property("no teleport",1);
   set_travel(FRESH_BLAZE);
   set_terrain(DEEP_WATER);
   set_name("%^RESET%^%^CYAN%^An underwater labyrinth%^RESET%^");
   set_short("%^RESET%^%^CYAN%^An underwater labyrinth%^RESET%^");
   set_long((:TO,"ldesc":));
   set_smell("default","%^BOLD%^%^CYAN%^You can't smell anything.%^RESET%^");
   set_listen("default","%^RESET%^%^BLUE%^All you can hear is the sound of moving water.%^RESET%^");
   set_items(([
      "bubbles":"%^RESET%^%^CYAN%^A few %^BOLD%^%^CYAN%^b%^RESET%^u%^CYAN%^b%^RESET%^b%^CYAN%^l%^RESET%^e%^BOLD%^%^CYAN%^s %^RESET%^%^CYAN%^come up from the cracks in the cave walls.%^RESET%^",
      ({"cave walls","walls"}):"%^RESET%^%^ORANGE%^The natural rock formations of the caves make very narrow passageways that are difficult to manuever.%^RESET%^",
      "cracks":"%^BOLD%^%^BLACK%^The cave walls are riddled with cracks.",
"icicles":"The icicles are about four inches long each, and hang menacingly from the ceiling.",
]));
}
string ldesc(string str){
   return("%^RESET%^%^BLUE%^You know you've hit the deepest"
" depths of the cavern system now.  The water is %^RESET%^ice"
" cold %^BLUE%^and you swear you can actually see icicles hanging"
" from the ceiling of the cavern.  The %^BOLD%^%^CYAN%^b%^RESET%^"
"u%^CYAN%^b%^RESET%^b%^CYAN%^l%^RESET%^e%^BOLD%^%^CYAN%^s"
" %^RESET%^%^BLUE%^here seem to not move at all.  You get an"
" %^BOLD%^%^BLACK%^eerie %^RESET%^%^BLUE%^feeling from being down"
" here, as it seems even the fish don't come down here often."
"%^RESET%^\n");
} 
