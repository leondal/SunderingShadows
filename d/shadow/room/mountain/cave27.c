//cave27.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_long(
      "%^YELLOW%^Inside Echoes Mountains%^RESET%^\n"+
      "The subtle grandeur of these tunnels has been lost somewhere "+
      "in the %^RED%^decayed "+
      "state %^RESET%^of the %^BOLD%^%^BLACK%^caverns%^RESET%^.  "+
      "What was once the fantastic "+
      "stonework of the dwarves has given way to the squallor of "+
      "the ogres who have taken over "+
      "this lower level of %^YELLOW%^Echoes Mountains%^RESET%^.  The "+
      "carved %^YELLOW%^archways%^RESET%^ and %^BOLD%^%^BLUE%^columns"+
      "%^RESET%^ are now cracked "+
      "and covered in %^GREEN%^mold %^RESET%^and %^GREEN%^moss"+
      "%^RESET%^.  Crude, broken "+
      "%^BOLD%^%^BLACK%^iron sconces %^RESET%^are pounded haphazardly "+
      "into the walls at strange "+
      "intervals, most of them hanging by a single peg and perched "+
      "at an angle.  Few %^ORANGE%^torches "+
      "%^RESET%^are actually in the sconces, however, giving only a "+
      "minimal amount of light.  Broken "+
      "bits of %^BOLD%^%^BLACK%^stone %^RESET%^and small piles of "+
      "rubble line the hall, strewn "+
      "with %^BOLD%^gnawed bones %^RESET%^and %^ORANGE%^rancid "+
      "furs%^RESET%^.  Several large, "+
      "flat rocks have been piled here to make a crude and most "+
      "likely treacherous stairway.  "+
      "They are centered just under a hole high overhead."+
      "\n"
    );
    add_item("stairway","The large, flat gray rocks piled beneath "+
      "the hole form a crude stairway that despite its ramshackle "+
      "state seems to have stood for some time.");
    set_exits(([
        "up" : ROOMS"cave77",
        "south" : ROOMS"cave28"
   	]));
   set_pre_exit_functions( ({"up"}), ({"GoThroughDoor"}) );
   set_listen("default","Grunts and thuds echo through the cave.");
   set_smell("default","The stench of ogres and other vile creatures is "
        "unmistakable.");
}
/*
void reset() {
  ::reset();
  if(!present("ogreX")) {
    new("/d/deku/monster/ogre1")->move(TO);
  }
}
*/
int GoThroughDoor() {
//	if(!userp(TP)) return 1;
	if(avatarp(TP) && TP->query_invis()) return 1;
	if(!random(6)) {
	  tell_room(ETP,TPQCN+" slips and falls trying to climb the pile of rocks.", TP);
	  tell_room(TP,"You slip and fall trying to climb the pile of rocks!\n"
	  "%^ORANGE%^You manage to avoid breaking any bones, but are banged and "
	  "bruised from the fall.");
     TP->do_damage("torso",random(6)+6);
     return 0;
   }
   return 1;
}	
