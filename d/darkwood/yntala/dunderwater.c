//dunderwater.c
#include <std.h>
#include "yntala.h"
inherit IHRMS+"inuw";

void create(){
   if(random(3) == 1){
      set_monsters(({TMONDIR +"shark1.c"}),({1}));
      set_repop(50);
   }
         
::create();
   set_property("indoors",1);
   set_property("light",2);
   set_property("no_sticks",1);
   set_property("no teleport",1);
   set_travel(FRESH_BLAZE);
   set_terrain(DEEP_WATER);
   set_name("%^RESET%^%^CYAN%^An underwater labrinth%^RESET%^");
   set_short("%^RESET%^%^CYAN%^An underwater labrinth%^RESET%^");
   set_long((:TO,"ldesc":));
   set_smell("default","%^BOLD%^%^CYAN%^You can't smell anything.%^RESET%^");
   set_listen("default","%^RESET%^%^BLUE%^All you can hear is the sound of moving water.%^RESET%^");
   set_items(([
      "bubbles":"%^RESET%^%^CYAN%^A few %^BOLD%^%^CYAN%^b%^RESET%^u%^CYAN%^b%^RESET%^b%^CYAN%^l%^RESET%^e%^BOLD%^%^CYAN%^s %^RESET%^%^CYAN%^come up from the cracks in the cave walls.%^RESET%^",
      ({"cave walls","walls"}):"%^RESET%^%^ORANGE%^The natural rock formations of the caves make very narrow passageways that are difficult to manuever.%^RESET%^",
      "cracks":"%^BOLD%^%^BLACK%^The cave walls are riddled with cracks.",
]));
}

string ldesc(string str){
   return("%^RESET%^%^CYAN%^You have entered a shaft in the"
" cavern system that only gives you the choice of going back up"
" from where you came, or deeper into it's depths.  It is %^BOLD%^"
"%^BLACK%^dark %^RESET%^%^CYAN%^and %^BLUE%^cold %^CYAN%^down"
" here, making you wish you were back at the surface. "
" %^BOLD%^%^CYAN%^B%^RESET%^u%^CYAN%^b%^RESET%^b%^CYAN%^l"
"%^RESET%^e%^BOLD%^%^CYAN%^s %^RESET%^%^CYAN%^float up around you"
" as you descend deeper, and the walls seem to be closing in"
".%^RESET%^\n");
} 
