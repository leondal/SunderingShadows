#include <std.h>
#include "/d/islands/common/eldebaro/inherits/eldebaro_in.h"

inherit ROOM;


void create(){
      ::create();
	set_property("light",2);
	set_property("indoors",0);
	set_terrain(BEACH);
	set_travel(FRESH_BLAZE);
      set_short("%^ORANGE%^The Eldebaro Beach%^RESET%^");
      set_long("%^ORANGE%^The sand around you blows gently, irritating your skin "+
	"and eyes, the wet sand beneath your feet squishes as you walk, and the loud "+
	"slapping of sea upon land echoes around you as the water to the south and west makes "+
	"contact with the beach.  However, the relative peace of this island ends "+
	"directly northeast of you.  You stand at a threshold, for the beach upon which "+
	"you stand is the end of this tranquility and the beginning of the hardship "+
	"which is Eldebaro.  Northeast here will mean a trek across the sands of this long "+
	"abandoned island and a journey into an unknown and sandstorm %^RED%^ravaged "+
	"%^RESET%^%^ORANGE%^world.%^RESET%^");

    	set_listen("default", "%^CYAN%^The gently slapping of water echoes all around you "+
	"here, as the whirling of sand begins to increase in ferocity.%^RESET%^");
	set_smell("default", "%^YELLOW%^A tranquil odor from the sea assaults you and mixes "+
	"with something much fouler.%^RESET%^");
}

void init() {
  ::init();
}
