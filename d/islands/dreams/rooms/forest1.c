#include <std.h>
#include "../defs.h"
inherit ROOM;

void create()
{
  ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(FOOT_PATH);
   set_property("no teleport",1);
   set_property("no scry",1);
  set_property("indoors",0);
  set_property("light",2);
  set_short("%^GREEN%^A Secluded Forest%^RESET%^");
  set_long("%^GREEN%^A gentle breeze cools your skin as you watch a "+
	"hawk soar overhead.  Pine trees sway back and forth, "+
	"creaking softly from time to time.  Pine straw litters "+
	"the ground except along a small %^ORANGE%^dirt path%^GREEN%^"+
	" which leads "+
	"north of here.  As the %^YELLOW%^sun%^RESET%^%^GREEN%^"+
	" warms your body, you feel "+
	"calm and relaxed.  A shimmering %^BOLD%^green%^RESET%^%^GREEN%^"+
	" portal hovers "+
	"bit off the ground to the south.  A soft hum seems "+
	"come from the portal, which looks grossly out of place "+
	"in these woods.");
  set_smell("default","%^YELLOW%^The air here smells crisp and clean.");
  set_listen("default","%^GREEN%^The pine trees creak softly while swaying "+
	"in the wind.");
  set_items(
    ([
    ({"tree","trees","pine tree","pine trees"}) : "%^GREEN%^These trees "+
	"tower above your head, the shortest being over 40 feet "+
	"tall.  A pair of squirrels scurry after each other, "+
	"jumping along the upper branches.",
    ({"pine straw","ground","path"}) : "%^BOLD%^%^GREEN%^Worn from recent use, "+
	"a small dirt path cuts through the pine straw, heading "+
	"north.",
    "portal" : "%^BOLD%^%^GREEN%^A green portal shimmers a few inches above the "+
	"ground.  It stretches up about 7 feet, and stands a few "+
	"feet wide."
    ]));
  set_exits( 
    ([
    "north" : ROOMS+"forest2",
    "green" : ROOMS+"pedestal.c"
    ]) );
}

