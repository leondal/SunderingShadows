//sstreet38 - Circe 11/23/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit ROSA;

void create(){
   ::create();
   set_long(::query_long()+"The smooth %^BOLD%^stone walls %^RESET%^of the "+
      "%^BOLD%^Bard Academy %^RESET%^rise to the east, with %^CYAN%^windows "+
      "%^RESET%^spread in various places along its three story height.\n");
   set_exits(([
      "north" : ROOMS"wstreet39",
      "south" : ROOMS"wstreet37"
   ]));
   add_item("academy","%^BOLD%^All you can see of the Bard Academy from here "+
      "is the smooth stone wall to the east.  Rows of %^CYAN%^windows "+
      "%^WHITE%^can be seen on each of the three levels.%^RESET%^");
   add_item("bard academy","%^BOLD%^All you can see of the Bard Academy from here "+
      "is the smooth stone wall to the east.  Rows of %^CYAN%^windows "+
      "%^WHITE%^can be seen on each of the three levels.%^RESET%^");
   add_item("Bard Academy","%^BOLD%^All you can see of the Bard Academy from here "+
      "is the smooth stone wall to the east.  Rows of %^CYAN%^windows "+
      "%^WHITE%^can be seen on each of the three levels.%^RESET%^");
}