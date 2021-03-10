#include <std.h>
inherit WATER;

void create(){
  ::create();
   set_terrain(DEEP_WATER);
   set_travel(PAVED_ROAD);
  	set_name("pool2");
  	set_property("surface",0);
  	set_property("underwater",0);
  	set_property("light",1);
  	set_property("indoors", 1);
  	set_short("Within a Pool");
  	set_long("%^RESET%^%^CYAN%^"+
  		"You now swim below the surface of the pool. Looking up towards "+
  		"the %^RESET%^surface%^CYAN%^ you see only the bottom of the pool reflected back "+
  		"at you and your own reflection. You could either surface or "+
  		"continue your decent %^BOLD%^downward%^RESET%^%^CYAN%^.%^RESET%^\n");
  	set_smell("default", "It wouldn't be wise to try and smell anything down here.");
  	set_listen("default", "You hear movement through the water.");
  	set_exits( ([
     		"down" : "/d/koenig/town/pool3",
     		"surface" : "/d/koenig/town/pool1"
	]) );
}
void reset(){
  	::reset();
  	if(!present("dragonfish")){
  		new("/d/koenig/town/mon/dragonfish.c")->move(TO);
  		new("/d/koenig/town/mon/dragonfish.c")->move(TO);
  	}
}
