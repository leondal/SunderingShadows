#include <std.h>
inherit "/std/room";

void create(){
  	::create();
   set_terrain(ROCKY);
   set_travel(DIRT_ROAD);
  	set_property("light",1);
  	set_short("The road leads to the ocean.");
  	set("day long","%^GREEN%^This road leads toward the ocean through some "+
      	"mountains. Small cliffs rise and fall to either side of the road "+
      	"blocking everything beyond them from view as you travel down the "+
      	"road. Your spirits seem to lift and a smile tugs at your lips.");
  	set("night long","%^BOLD%^%^BLUE%^Small cliffs rise and fall to either "+
      	"side of the road casting shadows across it as you travel down it "+
      	"towards the ocean.");
  	set_smell("default","Crisp air fills your lungs and puts a bounce in your "+
         	"step.");
  	set_listen("default","As you hold your breath you can almost hear the "+
           	"oceans waves crashing on some distant shore.");
  	set_exits(([
		"northeast" : "/d/dagger/road/road1",
     		"south" : "/d/koenig/road/room4"
	]));
}
