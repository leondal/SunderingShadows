//wstreet39 - Circe 11/23/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit ROSA;

void create(){
   ::create();
/*   set_long(::query_long()+"To the east, wide curving %^BOLD%^white stairs "+
      "%^RESET%^edged with %^BOLD%^%^BLACK%^black marble %^RESET%^rise to "+
      "the entrance of the %^BOLD%^Grand Amphitheater%^RESET%^.\n");
Return this description when the bard academy opens
*/
   set_long(::query_long()+"To the east, wide curving %^BOLD%^white stairs "+
      "%^RESET%^edged with %^BOLD%^%^BLACK%^black marble %^RESET%^rise to "+
      "the entrance of the %^BOLD%^Grand Amphitheater%^RESET%^, which is "+
      "closed for construction presently.\n");
   set_exits(([
      "north" : ROOMS"wstreet40",
      "south" : ROOMS"wstreet38",
//      "east" : ROOMS"amphitheater_lobby"
   ]));
   set_door("bronze doors","/d/attaya/newseneca/rooms/amphitheater_lobby","east",0,0);
   set_door_description("bronze doors","%^ORANGE%^Double bronze doors "+
      "set with %^CYAN%^frosted glass panes %^ORANGE%^form the entryway "+
      "to the amphitheater.  Each has an elegant brass handle.%^RESET%^");
   add_item("amphitheater","The %^BOLD%^Grand Amphitheater %^RESET%^is actually "+
      "housed in the same building as the Bard Academy and so has the same "+
      "%^BOLD%^white marble walls%^RESET%^.  The stairs leading to the "+
      "amphitheater entrance have %^BOLD%^white marble tops, %^RESET%^but the "+
      "front of each has been finished with %^BOLD%^%^BLACK%^black marble"+
      "%^RESET%^, creating a unique appearance.  Double doors made of "+
      "%^ORANGE%^bronze %^RESET%^with long %^CYAN%^glass panes %^RESET%^"+
      "are at the top of the stairs.");
   add_item("grand amphitheater","The %^BOLD%^Grand Amphitheater %^RESET%^is actually "+
      "housed in the same building as the Bard Academy and so has the same "+
      "%^BOLD%^white marble walls%^RESET%^.  The stairs leading to the "+
      "amphitheater entrance have %^BOLD%^white marble tops, %^RESET%^but the "+
      "front of each has been finished with %^BOLD%^%^BLACK%^black marble"+
      "%^RESET%^, creating a unique appearance.  Double doors made of "+
      "%^ORANGE%^bronze %^RESET%^with long %^CYAN%^glass panes %^RESET%^"+
      "are at the top of the stairs.");
   add_item("Grand Amphitheater","The %^BOLD%^Grand Amphitheater %^RESET%^is actually "+
      "housed in the same building as the Bard Academy and so has the same "+
      "%^BOLD%^white marble walls%^RESET%^.  The stairs leading to the "+
      "amphitheater entrance have %^BOLD%^white marble tops, %^RESET%^but the "+
      "front of each has been finished with %^BOLD%^%^BLACK%^black marble"+
      "%^RESET%^, creating a unique appearance.  Double doors made of "+
      "%^ORANGE%^bronze %^RESET%^with long %^CYAN%^glass panes %^RESET%^"+
      "are at the top of the stairs.");
}