#include <std.h>
#include "../keep.h"
inherit "/std/armour";

void create()
{
  ::create();
  set_name("animal skin robe");
  set_id(({"animal skin robe","robe"}));
  set_short("Animal skin robe");
  set_long("This robe looks to be made up from the hides of "+
    "several different animals. Short furs from the various "+
	"animal skins give the robe a patch-quilt look.");
  set_lore("This animal skin robe is sewn in the manner of the "+
    "ogres.  The wide, uneven stitching suggests that it was "+
    "either an amateur or perhaps not truly one of their number "+
    "who pieced the robe.  A robe such as this is given to an "+
    "ogre upon his coming of age, and it is always made up of "+
    "the skin of animals that the ogre himself has killed and "+
    "eaten...raw.");
  set_property("lore difficulty",4);
  set_size(3);
  set_value(10);
  set_weight(8);
  set_ac(1);
  set_limbs(({"torso"}));
  set_type("clothing");
}
