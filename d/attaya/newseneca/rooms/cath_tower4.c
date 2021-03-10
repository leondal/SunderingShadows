//cath_tower4 - bell tower for new Seneca
//~Circe~ 1/14/08
#include <std.h>
#include "../seneca.h"

inherit STORAGE"cath_tower";

void create(){
   ::create();
   set_long(::query_long()+"\nThe eastern and western windows "+
      "give a good view of the rooftops of Seneca.  The "+
      "crystalline waters of the %^BOLD%^%^CYAN%^ocean %^RESET%^"+
      "are visible in the distance.\n");
   set_exits(([
      "down" : ROOMS"cath_tower3",
      "up" : ROOMS"cath_tower5"
   ]));
   add_item("ocean","%^BOLD%^%^CYAN%^The soothing crystalline "+
      "waters of the ocean are visible out of both windows, "+
      "sending occasional %^WHITE%^glints %^CYAN%^of light "+
      "from their %^WHITE%^white-capped peaks%^CYAN%^.%^RESET%^");
   add_item("rooftops","Looking out of the city, the sky is filled "+
      "with countless rooftops in all shapes, sizes, and colors.  "+
      "It creates a patchwork of images, making it hard to focus "+
      "on any one thing.");
}