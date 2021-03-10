//sstreet37 - Circe 11/23/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit ROSA;

void create(){
   ::create();
   set_long(::query_long()+"Here, %^BOLD%^%^MAGENTA%^Rosa Terrace %^RESET%^joins "+
      "%^BOLD%^%^CYAN%^Viento Lane%^RESET%^, the divided thoroughfare "+
      "that runs eastward between the %^BOLD%^Bard Academy %^RESET%^to "+
      "the north and a bustling %^CYAN%^restaurant %^RESET%^with a "+
      "%^GREEN%^s%^RESET%^t%^GREEN%^r%^RESET%^i"+
      "%^GREEN%^p%^RESET%^e%^GREEN%^d %^GREEN%^a%^RESET%^w%^GREEN%^n"+
      "%^RESET%^i%^GREEN%^n%^RESET%^g %^RESET%^on the south side "+
      "of the street.\n");
   set_exits(([
      "north" : ROOMS"wstreet38",
      "south" : ROOMS"wstreet36",
      "east" : ROOMS"viento49"
   ]));
   add_item("academy","%^BOLD%^The northeastern building features a beautiful "+
      "marble facade jutting out from the main building, forming a grand "+
      "entryway.  Stairs lead up to a pair of %^BLACK%^double mahogany "+
      "doors %^WHITE%^that open and close at all hours as aspiring musicians, "+
      "actors, poets, and artists enter and leave.%^RESET%^");
   add_item("bard academy","%^BOLD%^The northeastern building features a beautiful "+
      "marble facade jutting out from the main building, forming a grand "+
      "entryway.  Stairs lead up to a pair of %^BLACK%^double mahogany "+
      "doors %^WHITE%^that open and close at all hours as aspiring musicians, "+
      "actors, poets, and artists enter and leave.%^RESET%^");
   add_item("Bard Academy","%^BOLD%^The northeastern building features a beautiful "+
      "marble facade jutting out from the main building, forming a grand "+
      "entryway.  Stairs lead up to a pair of %^BLACK%^double mahogany "+
      "doors %^WHITE%^that open and close at all hours as aspiring musicians, "+
      "actors, poets, and artists enter and leave.%^RESET%^");
   add_item("restaurant","The building to the southeast is a small restaurant with "+
      "%^BOLD%^cream stucco walls %^RESET%^and a %^GREEN%^s%^RESET%^t%^GREEN%^r%^RESET%^i"+
      "%^GREEN%^p%^RESET%^e%^GREEN%^d %^GREEN%^a%^RESET%^w%^GREEN%^n"+
      "%^RESET%^i%^GREEN%^n%^RESET%^g above a %^RED%^red door%^RESET%^.  "+
      "It appears to be quite popular, as there are always well-dressed "+
      "customers coming and going.");
}