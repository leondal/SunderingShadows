#include <std.h>
#include <move.h>
#include "../lothwaite.h"

inherit ROOM;

void create(){
   ::create();
   set_name("A Hidden Alcove");
   set_short("%^BOLD%^%^BLACK%^A Hidden Alcove%^RESET%^");
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
   set_indoors(1);
   set_property("light",1);
   set_property("no teleport",1);
   set_property("no sticks",1);
   set_long("%^RESET%^%^BLUE%^This hidden alcove is cleverly "+
      "designed to block light - and sight - from the outter "+
      "passageway.  The walls here are %^BOLD%^%^BLACK%^rough "+
      "%^RESET%^%^BLUE%^and unfinished, making it clear that "+
      "it was not built by the firbolgs.  Whatever lives here "+
      "is likely lurking without their knowledge or permission.  "+
      "The %^ORANGE%^walls %^BLUE%^curve slightly, making it "+
      "seem the tunnel was dug by hand...although the marks "+
      "upon them suggest it was most likely claws instead.%^RESET%^\n");
   set_items(([
      ({"walls","stone walls","wall","stone"}) : "%^BLUE%^The walls of this "+
         "caverns are rough.  Like the other tunnels, they are "+
         "shot through with %^BOLD%^%^BLACK%^v"+
         "%^YELLOW%^e%^BLACK%^i%^YELLOW%^n%^BLACK%^s %^RESET%^"+
         "%^BLUE%^of %^BOLD%^%^BLACK%^black %^RESET%^%^BLUE%^and "+
         "%^YELLOW%^gold%^RESET%^%^BLUE%^.  These walls curve "+
         "and are rugged, suggesting that something other than "+
         "the firbolgs dug them.",
      ({"veins","black","gold","veins of black and gold"}) : "%^BLUE%^"+
         "The %^BOLD%^%^BLACK%^dark gray stone %^RESET%^%^BLUE%^ of the "+
         "walls is shot through with web-like %^BOLD%^%^BLACK%^v"+
         "%^YELLOW%^e%^BLACK%^i%^YELLOW%^n%^BLACK%^s %^RESET%^"+
         "%^BLUE%^of %^BOLD%^%^BLACK%^black %^RESET%^%^BLUE%^and "+
         "%^YELLOW%^gold%^RESET%^%^BLUE%^.  The %^YELLOW%^gold %^RESET%^"+
         "%^BLUE%^looks as though it were melted and poured along the "+
         "walls, while the %^BOLD%^%^BLACK%^black %^RESET%^%^BLUE%^"+
         "almost looks to be a hidden force trying to break through the "+
         "stone.",
   ]));
   set_listen("default","Your footsteps echo loudly down the deserted corridor.");
   set_smell("default","The cool breath of a tomb is the only smell in the air.");
   set_exits(([
      "out" : PATHEXIT"b33",
      "east" : PATHEXIT"hidden2"
   ]));
 }