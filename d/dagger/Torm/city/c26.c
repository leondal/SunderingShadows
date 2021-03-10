//changed to use inherit by Circe 4/23/04
#include <std.h>
#include "../tormdefs.h"

#define GHOUSE "/d/player_houses/girruuth/"
// #define TCITY GHOUSE

// inherit whatever;   converting to Girruuth's armor & weapons repair shop *Styx* 12/02
// this will be the forge/smithing room, the rest will be in /d/player_houses/girruuth/

inherit "/d/common/inherit/hitching_post";

void create()  {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
  set_name("Horse stables");
  set_short("Horse stables");
  set_long("This stable seems to be well-used but also well-kept.  "+
     "There are three stalls along the southern wall, each with "+
     "dividing walls above five feet tall - just short enough so that "+
     "the horses may look over them.  These stalls each have closing "+
     "doors, but there are also several hitching posts near the western "+
     "end of the room.  The west and north walls have markings that "+
     "indicate doors might be planned, and it seems obvious that "+
     "additional plans for this stables might be in place."
  );
  set_smell("default", "You smell a strong scent of horse mixed with the earthy scent of hay.");
  set_listen("default", "The neighs of horses fill the air, accompanying by occasional stamping.");
  set_exits(([
	"east":TCITY+"c38",
  ]));
  set_door("stable door",TCITY+"c38","east");
//  set_open("door",0);  set on the other side
  set_search("hay", "You expecting to find something, perhaps a needle?" );
  set_search("piles", "You expecting to find something, perhaps a needle?" );
  set_items( ([
	({ "hay", "piles", "straw" }): "The piles of hay and straw look like they are often spread out in the stables and stalls for food and bedding.  %^ORANGE%^Bundles of hay %^RESET%^also hang from the rafters.",
	({"wall", "walls"}) : "The walls dividing the stables are made of wood interlaced with metal bands for strength.  The outer wall to the south is stone and has openings with grates to keep the horses from sticking their heads out into the street but to allow light and fresh air in.",
      ({"post","posts","hitching post","hitching posts","tether","tethering post","tethering posts"}) : "There are several posts set up here to tether horses to. They are"+
	" basically long wooden bars that are supported on either end"+
	" that you loop the reins of a horse around to keep them there."+
	" There are three posts all together, all in a row.",
   ]) );
      //set_pre_exit_functions(({"east"}),({"GoThroughDoor"}));

}
