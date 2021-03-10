//hiddentunnel.c - tunnels for Kildare Glen expansion ~Circe~ 10/2/07
#include <std.h>
#include "../kildare.h"

inherit ROOM;

void create(){
   ::create();
   set_indoors(1);
   set_property("light",-2);
   set_terrain(BUILT_TUNNEL);
   set_travel(RUTTED_TRACK);
   set_name("A roughly carved tunnel");
   set_short("%^BOLD%^%^BLACK%^A roughly carved tunnel%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Narrower than the other tunnels, this "+
      "passageway seems to have gone largely unnoticed by the "+
      "%^RESET%^various denizens %^BOLD%^%^BLACK%^who dwell nearby.  "+
      "The walls here are even rougher, covered with small %^RESET%^"+
      "%^BLUE%^depressions %^BOLD%^%^BLACK%^and %^RESET%^raised "+
      "places %^BOLD%^%^BLACK%^just sharp enough to cut anyone who "+
      "unwittingly brushes against them.  Thankfully, the %^GREEN%^"+
      "foul stench %^BLACK%^seems lighter here, and an occasional "+
      "breath of %^RESET%^%^CYAN%^fresh air %^BOLD%^%^BLACK%^winds "+
      "its way from some hidden hole in the %^RESET%^%^RED%^mountainside"+
      "%^BOLD%^%^BLACK%^.  The area feels deserted and strangely "+
      "quiet after the racket from the wider tunnels.  Oddly, "+
      "it almost feels as if %^RESET%^%^RED%^unseen e%^RESET%^y%^RED%^"+
      "es %^BOLD%^%^BLACK%^are watching you.\n");
   set_smell("default","The stench of dead animals and bird droppings is somewhat more bearable here.");
   set_listen("default","Every noise reverberates through the tunnels.");
   set_items(([
      ({"depressions","raised places","wall","walls"}) : "The depressions and corresponding "+
         "raised places form mock mountains and valleys all along the "+
         "walls.  The wall seems to lie in wait for some hapless person to "+
         "brush against it.",
      ({"floor","tunnel"}) : "The floor of this tunnel is uneven, and it "+
         "looks to have been carved by unskilled hands working quickly.  "+
         "It features several ridges ready to catch an unwary toe."
   ]));
   set_property("no peer",1);
}