//sstreet40 - Circe 11/23/07 for new Seneca
//put a patroling guard in here 12/6/09
#include <std.h>
#include "../seneca.h"

inherit ROSA;
object guard = new("/d/attaya/newseneca/mon/n_guard");

void create(){
   ::create();
   set_long(::query_long()+"This corner is the junction of %^BOLD%^"+
      "%^BLUE%^Azul Avenue %^RESET%^and %^BOLD%^%^MAGENTA%^Lila Way"+
      "%^RESET%^.  To the southeast is a %^BOLD%^building %^RESET%^"+
      "with %^CYAN%^pale blue stucco walls%^RESET%^.\n");
   set_exits(([
      "east" : ROOMS"street2",
      "south" : ROOMS"wstreet40"
   ]));
   add_item("building","Likely a shop of some kind, the building to the "+
      "southeast has very %^CYAN%^soft blue stucco %^RESET%^and is well-kept.  "+
      "A %^ORANGE%^window basket %^RESET%^on western side has been filled "+
      "with %^BOLD%^coir fibers %^RESET%^to support the %^ORANGE%^ora"+
      "%^YELLOW%^n%^RESET%^%^ORANGE%^ge bou%^YELLOW%^g%^RESET%^%^ORANGE%^"+
      "ain%^YELLOW%^v%^RESET%^%^ORANGE%^ill%^YELLOW%^e%^RESET%^%^ORANGE%^"+
      "a%^RESET%^ growing within.");
	  guard->move(TO);
}

void reset(){
   ::reset();
   
   if(!guard){ guard=new("/d/attaya/newseneca/mon/n_guard");
   guard->move(TO);}
   
}
