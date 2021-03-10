//Circe 4/23/04
#include <std.h>
#include "/d/dagger/tonovi/town/short.h"

inherit "/d/common/inherit/hitching_post";

void create(){
  ::create();
  set_indoors(1);
//  set_property("light", 2);  light is set in the inherit, this doubled it up *Styx* 3/7/05
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
  set_long("%^BOLD%^%^GREEN%^A Tethering Area%^RESET%^\n"+
     "This area is enclosed on all sides by the high, "+
     "%^BOLD%^%^BLACK%^dark stone walls %^RESET%^of the city.  "+
     "An archway through the %^BOLD%^%^BLACK%^wall %^RESET%^"+
     "to the east leads to the street.  The ground is left unpaved "+
     "and covered with %^GREEN%^patchy grass%^RESET%^.  In the "+
     "corners of the courtyard, several %^ORANGE%^hitching posts "+
     "%^RESET%^have been set into the ground so that horses may "+
     "be left here and not further befoul the city.  The %^CYAN%^"+
     "sky %^RESET%^can be seen above, but the %^BOLD%^%^BLACK%^deep "+
     "shadows %^RESET%^of the walls make this place seem rather dank and dark.\n"
  );
  set_smell("default","The strong scent of horses is almost overpowering.");
  set_listen("default","The neighs of horses fill the air, accompanying "+
     "by occasional stamping.");
  set_exits(([
	"east": RPATH "street1",
  ]));
  set_items( ([
     ({"wall","walls","archway"}) : "The dark stone walls of the city "+
        "rise up high around you, blocking most of the light and making "+
        "this small area seem dark.  An archway through the eastern "+
        "wall leads back to the street.",
     ({"ground","grass","patchy grass"}) : "The grass here is browning "+
        "and grows in widely spaced patches.  It looks as though this was "+
        "meant to be a small courtyard for the horses, but the lack of "+
        "sunlight prevents the grass from being healthy.",
      ({"post","posts","hitching post","hitching posts","tether","tethering post","tethering posts"}) : "There are several posts set up here to tether horses to. They are"+
	" basically long wooden bars that are supported on either end"+
	" that you loop the reins of a horse around to keep them there."+
	" There are four posts all together, one in each corner.",
   ]) );
      set_pre_exit_functions(({"east"}),({"GoThroughDoor"}));

}
