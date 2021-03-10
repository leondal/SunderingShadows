#include <std.h>
inherit WATER;

void create(){
  	::create();
   set_terrain(DEEP_WATER);
   set_travel(PAVED_ROAD);
  	set_name("pool1");
  	set_property("surface",1);
  	set_property("light",1);
  	set_property("indoors", 1);
  	set_short("A Clear Pool");
  	set_long("%^BOLD%^%^CYAN%^"+
  		"You are now swimming across the clear pool's surface. You can't "+
  		"seem to look into its depths, for it only reflects the "+
  		"surroundings. You do get the impression you could "+
                "%^RESET%^dive%^BOLD%^%^CYAN%^ beneath the surface here, however.%^RESET%^\n");
  	set_smell("default", "You smell the freshness of the air and all that surrounds you.");
  	set_listen("default", "The only sound is your splashing.");
  	set_exits( ([
     		"dive" : "/d/koenig/town/pool2"
	]) );
}
