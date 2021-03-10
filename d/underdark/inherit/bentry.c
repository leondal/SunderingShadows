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
      "%^BOLD%^%^BLACK%^The %^RESET%^light%^BOLD%^%^BLACK%^ from the surface is just above you."+
      " The path is rocky and full of rubble. It would appear the path is footworn."+
      " You also gather from the clues that while not used commonly, it has not"+
      " been too long since someone or something has come through here."+
      " The walls of the tunnel are sometimes jagged and at other times smooth."+
      " The air is what could be described as stuffy, but otherwise without smell."+
      " The tunnel curves up in one direction and heads deeper down underground in the other direction."
   );
   set_listen("default","%^RESET%^%^BLUE%^Every now and then you think you hear something move.");
   set_smell("default","%^RESET%^%^GREEN%^There is no smell.");
}
