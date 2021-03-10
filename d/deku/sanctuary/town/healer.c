#include <std.h>
#include "../dragon.h";

inherit BTOWN;

void create() {
   ::create();
   set_light(0);
   set_indoors(1);
   set_short("Ruined building");
   set_long(
      "%^BOLD%^%^BLACK%^The floorboards have pratically been ripped right of the floor here."+
      " The damaged floor looks like it has taken quite a bit of water damage as well as"+
      " just being stomped on with tremendous force. Chunks of rubble that once made up an"+ 
      " inwall shelf have been strewn about the already cluttered floor."+
      " The room was unfurnished except for the long table that is now missing three out four legs."
   );
   
   set_exits(([
      "up" : TOWN+"church"
   ] ));
}