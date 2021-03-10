#include <std.h>
inherit WATER;

void create(){
  	::create();
   set_terrain(DEEP_WATER);
   set_travel(PAVED_ROAD);
  	set_name("pool3");
  	set_property("surface",0);
  	set_property("underwater",0);
  	set_property("light",1);
  	set_property("indoors", 1);
  	set_short("Within a Pool");
  	set_long("%^CYAN%^"+
  		"You find yourself rather surprised that you can still see so "+
  		"well down here in the pools depths and are very thankful for "+
  		"it. Further down you can see underwater %^GREEN%^plants%^CYAN%^, %^ORANGE%^rocks%^CYAN%^, and there "+
  		"are even a few %^MAGENTA%^fish%^CYAN%^ swimming about. There's a rather odd %^BOLD%^archway%^RESET%^%^CYAN%^ "+
  		"made of some strange stonelike material.%^RESET%^\n");
	  set_items( ([
 ({ "plants","rocks","fish"}) : "Colorful fish swim happily through the gorgeous plants here near the bottom of the clear pool. A few rocks poke up from the sandy bottom."
	]) );
  	set_smell("default", "It still isn't wise to try and smell things here.");
  	set_listen("default", "You hear your heart thudding in your "+
  		"ears as you hold your breath.");
  	set_exits( ([
     		"up" : "/d/koenig/town/pool2",
     		"down" : "/d/koenig/town/pool4"
	]) );
}
