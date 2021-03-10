#include <std.h>
#include "../defs.h"
inherit CROOM;
void pick_critters();

void create()
{

	pick_critters();
   	set_repop(35);
   	::create();
		set_terrain(BARREN);
   	set_travel(PAVED_ROAD);
   	set_property("no teleport",1);
   	set_property("no scry",1);
  	set_property("indoors",1);
	set_property("no sticks",1);
  	set_property("light",2);
  	set_short("%^BOLD%^Swirling Shadows%^RESET%^");
  	set_long("%^BLUE%^Your head spins as you survey your surroundings.  "+
		"You stamp your foot down, trying to figure out exactly what it "+
		"is that holds your weight up.  You can not see any kind of floor "+
		"beneath your feet, nor any walls or ceilings.  For that matter, you"+
		" don't really see anything at all.  Everything around you is black, "+
		"but not dark.  Shadows dance around you in a swirl, despite the "+
		"lack of any natural light source that you can see, much less any "+
		"solid objects to cast the shadows.  The only other thing you can "+
		"really see are %^RESET%^%^BOLD%^shimmering patches of mist.  "+
		"%^RESET%^%^BLUE%^You seem to be able to will yourself in most "+
		"any direction, walking along your invisible floor.%^RESET%^\n");
  	set_smell("default","%^CYAN%^The mist seems to tickle your nose.");
  	set_listen("default","%^GREEN%^The silence is almost deafening.");
  	set_items(
    	([
    	"shadows" : "%^BLUE%^The shadows seem to shift and spin madly about "+
		"you.%^RESET%^",
    	"mist" : "%^BOLD%^The mist seems to glow as it floats around you."
    	]) );
}
void pick_critters() {
      switch(random(9)){
case 0:  set_monsters(({MON"shadearcher"}),({random(3)+1}));
break;
case 1:  set_monsters(({MON"shadow"}),({random(2)+1}));
break;
case 2:  set_monsters(({MON"smastiff"}),({random(3)+2}));
break;
case 3:  set_monsters(({MON"shadow",MON"shadearcher"}),({random(2),random(3+1)}));
break;
case 4:  set_monsters(({MON"shadow",MON"smastiff"}),({1,1}));
break;
case 5:  set_monsters(({MON"shadearcher",MON"smastiff"}),({1,random(2)}));
break;
         case 6..8: break;
      }
}
