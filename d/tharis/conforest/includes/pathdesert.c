#include <std.h>
#include "../defs.h"
inherit ROOM;

void create()
{
  ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(FOOT_PATH);
  set_property("indoors",0);
  set_property("light",1);
  set_short("%^BOLD%^A Path Through The Forest%^RESET%^");
  set_long("You are walking along a narrow path through "+
	"the forest.  Your surroundings seem rather calm "+
	"and peaceful, and the wildlife flourishes around you.  "+
	"As the path continues to the northeast, you notice that the "+
	"air becomes a bit drier and the trees thin out a bit.  "+
	"To the southwest, it looks as if the forest becomes thicker, "+
	"with the trees creeping closer towards the path.");
  set_smell("default","The crisp, fresh scent of pine fills the air.");
  set_listen("default","The trees creak as they sway in the wind.");
  set_items(
    ([
    ({"tree","trees","pine","oak"}):"Huge, sprawling oak trees fight "+
        "for space amongst the tall pine trees.",
    "path":"This small dirt path is rather easy to follow, given it is "+
        "the only part not covered in pine needles."
    ]) );
}
