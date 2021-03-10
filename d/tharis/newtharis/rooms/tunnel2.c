#include <std.h>
#include "../tharis.h"
inherit STORAGE"tunnel.c";

void create(){
   ::create();
// asylum's now offscreen & no direct exit to slums anymoar!
/*   set_long(::query_long()+"\n%^RESET%^%^BOLD%^A rough message has been written in chalk on the wall near the ladder up.%^RESET%^ \n");
   add_item(({"chalk","chalk message","message"}),"\n  %^RESET%^%^BOLD%^The days of storms and madness pass\n"+
   "  %^RESET%^%^BOLD%^Yet the halls of aslyum fill\n"+
   "  %^RESET%^%^BOLD%^Save any brothers from Shar's grasp\n"+
   "  %^RESET%^%^BOLD%^If only for the thrill\n");
*/
   set_exits(([
//      "up" : ROOMS"slum2",
      "west" : ROOMS"tunnel1",
      "east" : ROOMS"tunnel3",
   ]));
}
