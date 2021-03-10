//updated by Circe 9/10/04
#include "/d/dagger/tonovi/town/short.h"

inherit CITYMAIN;

void create(){
    ::create();
    set_property("light", 2);
    set_short("Guardian Way");
    set_long(
      "%^GREEN%^Guardian Way%^RESET%^\n"+
      "This is the center of %^GREEN%^Guardian Way %^RESET%^where "+
      "it crosses %^BOLD%^%^BLACK%^Ekan Street%^RESET%^.  To the "+
      "south you can see the main crossroads in the distance.  To "+
      "the east and west you can see %^GREEN%^Guardian Way %^RESET%^"+
      "pass in front of the %^BLUE%^soldiers' barracks%^RESET%^.  "+
      "To the north a well-used path leads to the %^BOLD%^%^BLACK%^"+
      "gates%^RESET%^ of the %^ORANGE%^strange encampment%^RESET%^.\n"
    );
    set_items( ([
	"fence" : "This high wooden fence is built to keep some people "+
         "within this strange compound.",
	({"compound","encampment","strange encampment"}) : "Surrounded "+
         "by a high %^ORANGE%^wooden fence%^RESET%^, this strange "+
         "encampment looks nothing like the rest of the city - save "+
         "that %^BLUE%^well-armed guards %^RESET%^patrol there as "+
         "well.  Scattered along the %^GREEN%^ground %^RESET%^within "+
         "the fence are various %^ORANGE%^tents %^RESET%^and flimsy "+
         "looking %^ORANGE%^wooden buildings%^RESET%^, around "+
         "which elves and other slaves work.",
	({"walls","wall","stone","stone walls"}) : "%^BOLD%^%^BLACK%^"+
         "Walls made of black stone mined from veins in the northern "+
         "mountains encircle the city.",
	({"street","ground"}) : "The streets here are made of "+
         "%^BOLD%^%^BLACK%^gray cobblestone%^RESET%^ kept mostly "+
         "clean of refuse, though here and there some recent trash "+
         "has been left by travellers.",
      ({"building","buildings","shops","shop"}) : "The buildings of the city rise "+
         "around you.  There is a mixture of buildings made of "+
         "black, white, and gray stone, as well as the occasional "+
         "wooden building.",
      ({"gate","gates"}) : "The tall wooden gate is topped with "+
         "%^BOLD%^%^BLACK%^iron spikes %^RESET%^and manned by "+
         "several capable-looking guards.",
      "barracks" : "This town seems to be in a constant state of war.  "+
          "Attesting to this fact are the rather nondescript buildings "+
          "that house the common soldiers of the city.  Many "+
          "of them can often be seen entering and leaving there.",
      ]) );
    set_exits( ([
	"east" : RPATH "street15",
	"west" : RPATH "street19",
	"south" : RPATH "street17"
      ]) );
}
/*
void init(){
   ::init();
   add_action("slip_em","slip");
}

int slip_em(string str){
   if(!str){
      tell_object(TP,"Slip where?");
      return 1;
   }
   if(str == "fence" || str == "under fence"){
      tell_object(TP,"You slip under the fence, hoping to go unnoticed.");
      if(!TP->query_invis()){
         tell_room(TO,""+TPQCN+" slips under the fence.");
      }
      TP->move("/d/dagger/tonovi/temp/upper1");
      TP->force_me("look");
      return 1;
   }
   return 0;
} */
