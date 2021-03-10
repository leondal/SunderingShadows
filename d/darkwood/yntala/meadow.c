#include <std.h>
#include "yntala.h"
inherit CROOM;

void create()
{
   if(base_name(TO) == INRMS +"meadow1")
   {
   set_monsters(({TMONDIR +"centaurc.c",TMONDIR+"centaurc2.c"}),({1,1}));
   set_repop(35);
   }
::create();
   set_property("light",2);
   set_terrain(MEADOWLANDS);
   set_travel(FOOT_PATH);
   set_name("Meadows");
   set_short("%^BOLD%^%^GREEN%^A peaceful meadow%^RESET%^%^");
   set_long((:TO,"ldesc":));
   set_smell("default","%^BOLD%^%^GREEN%^You can smell nothing but freshness.%^RESET%^");
   set_listen("default","You can hear children playing in the distance.");
   set_items(([
      ({"flowers","wildflowers"}):"%^BOLD%^%^GREEN%^Various types of %^YELLOW%^w%^MAGENTA%^i%^RED%^l%^BLUE%^d%^GREEN%^f%^WHITE%^l%^YELLOW%^o%^MAGENTA%^w%^BLUE%^e%^RED%^r%^YELLOW%^s %^GREEN%^grown wildly on the grasslands of the meadow.%^RESET%^",
      "forest":"%^GREEN%^The tall trees of the forest surround this meadow.%^RESET%^",
]));
}
string ldesc(string str){
   return("%^BOLD%^%^GREEN%^The lush green grass of this open"
" meadow is dappled with colorful %^YELLOW%^w%^MAGENTA%^i%^RED"
"%^l%^BLUE%^d%^GREEN%^f%^WHITE%^l%^YELLOW%^o%^MAGENTA%^w%^BLUE"
"%^e%^RED%^r%^YELLOW%^s %^GREEN%^that bend slightly as the"
" %^CYAN%^breeze %^GREEN%^touches them.  Towards the edges of the"
" meadow you can see the %^RESET%^%^GREEN%^forest %^BOLD%^"
"%^GREEN%^that surrounds it, but the natural beauty of this place"
" is so breathtaking that it leaves you with a feeling of nothing"
" but calm serenity.\n");
} 

