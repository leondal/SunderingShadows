#include <std.h>

inherit "/std/room";

void create() {
   ::create();
   set_property("indoors",1);
   set_property("light", -3);
   set_travel(FOOT_PATH);
   set_terrain(ROCKY);
   set_short("Underground Tunnel");
   set_long(
      "%^BOLD%^%^BLACK%^This is a tunnel that is not so complete."+
      " It would appear someone or something has been chipping away at the walls, heading downward."+
      " There are cut pieces of %^RESET%^%^ORANGE%^wood%^BOLD%^%^BLACK%^ set up along the walls to prevent cave in."+
      " Scattered about the ground is rubble from the digging so far. In one corner you"+
      " can spot some tools that you would assume aids whoever digs down here."
   );
   set_listen("default","%^RESET%^%^BLUE%^Every now and then you think you hear something move.");
   set_smell("default","%^RESET%^%^GREEN%^There is no smell.");
}
