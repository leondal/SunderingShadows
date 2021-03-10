//river3
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"river.c";

void create(){
::create();
   set_exits(([
"east":INRMS+"forest253"
]));
   set_items(([
      ({"river","water"}):"%^BOLD%^%^CYAN%^The water here is fresh, %^RESET%^c%^CYAN%^l%^BOLD%^%^WHITE%^e%^RESET%^%^CYAN%^a%^RESET%^r, %^BOLD%^%^CYAN%^and slightly more shallow than the rest of the river, perhaps you should search it?%^RESET%^",
      "forest":"%^GREEN%^The tall trees of the forest grow right up to the edges of the %^BOLD%^%^CYAN%^w%^RESET%^%^CYAN%^a%^BLUE%^t%^CYAN%^e%^BOLD%^%^CYAN%^r.%^RESET%^",
      "vegetation":"%^BOLD%^%^GREEN%^The vegetation here is thick and lush.%^RESET%^",
      "shadows":"%^BOLD%^%^BLACK%^Shadows from the plants dance across the %^BOLD%^%^CYAN%^w%^RESET%^%^CYAN%^a%^BLUE%^t%^CYAN%^e%^BOLD%^%^CYAN%^r%^RESET%^.",
]));
   set_search("river",(:TO,"search_pile":));
   set_search("water",(:TO,"search_pile":));
}
void reset() {
   ::reset();
   query_exit("west");
   remove_exit("west");
}
void search_pile(){               
   tell_object(TP,"It looks like you can cross the river here.");
   add_exit(INRMS+"rroom","west");
        return ;
}



