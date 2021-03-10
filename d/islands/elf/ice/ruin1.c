//ruin with hidden elf gate
#include "elf.h"
#include <std.h>

inherit ROOM;

void create() {
        ::create();
    set_terrain(ICE);
    set_travel(SLICK_FLOOR);
	set_climate("arctic");
        set_name("ruined watch tower");
        set_short("ruined watch tower");
        set_long("%^CYAN%^This looks to have once been a "+
		"watch tower of some sort.  Now the "+
		"structure lays in ruins.  The walls "+
		"still stand but the roof was long ago "+
		"completely collapsed by %^BOLD%^snow%^RESET%^. %^CYAN%^ Only a"+
		" few rocks stick out, the rest is buried in the snow.%^RESET%^");
		set_smell("default","It smells of snow and winter.");
		set_listen("default","You hear the sound of cold wind rushing through the mountains.");
        set_items(([
                "snow" : "You can't tell what is buried under the snow.",
                "rocks" :"These rocks look to be the remains of a wall.",
				({"boulder","symbols"}) : "This looks to be some"+
				" kind of magic device.  Perhaps one could read "+
				"the symbols for a chance to activate it.",
        ]));
        set_exits(([

                "down"  : ROOMS"ice11",
        ]));
        set_search("room","You dig through the snow and find"+
	 " a strange boulder covered with odd symbols."); 
}
void init(){
  ::init();
  add_action("touch","touch");
  add_action("read_symbols","read");
}
int read_symbols(string str) {
   if(str != "symbols") {
   return 0;
   }
   if( (string)TP->query_race() != "elf"
    && TP->query_skill("academics")+roll_dice(1,20) < 45 ){
      tell_object(TP,"%^CYAN%^The symbols are only gibberish."+
	  "  Perhaps you are just not good enough at academics.");
      tell_room(ETP,"%^CYAN%^"+TPQCN+" reads the symbols.",TP);
      return 1;
   }
   tell_object(TP,"%^CYAN%^To use the portal: touch "+
   "it with the pasque flower on your person.");
   tell_room(ETP,"%^CYAN%^"+TPQCN+" reads the symbols.",TP);
   return 1;
}

void touch(string str){
  if(str != "stone" && str != "portal"){ 
    tell_object(TP,"Touch what, the stone?");
	return 1;
	}
	
  if(!present("pasque flower",TP)){
   tell_object(TP,"You try to activate the stone but nothing happens.");
   return 1;
   } 
   tell_object(TP,"%^CYAN%^Your flower seems to resonate with the stone."+
   "  The world spins and you find yourself standing in a different location.");
   tell_room(TO,"%^CYAN%^The stone glows and "+TP->QCN+" vanishes.",TP);
   TP->move(ROOMS"planar");
   "/d/islands/elf/ice/planar"->set_place("/d/tharis/elftrail/rooms/hidden1");
   return 1;
}
void reset(){
::reset();
if (!present("greater frost spirit"))
  new(MON"gf_girl")->move(TO);
 }
