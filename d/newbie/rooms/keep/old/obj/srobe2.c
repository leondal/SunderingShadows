//updated to more current code - Circe 5/21/07
#include <std.h>
#include "../keep.h"
inherit "/std/armour";

void create(){
  ::create();
  set_name("shaman robe");
  set_id(({"shaman robe","robe","shaman's robe","shamans robe"}));
  set_short("Shaman's robe");
  set_long("%^BLUE%^This small, dark blue robe is lined with "+
     "many tiny pockets, all of which reek with an awful stench.  "+
     "Small talismans have been sewn into the fabric, everything "+
     "from rat skulls to dried chicken feet adding to the clamour "+
     "the robe produces when moved.");
  set_lore("The small size and strange construction of this robe "+
     "suggests that it was crafted for the unusual creatures "+
     "known as the xvarts.  They are often led by a shaman, who "+
     "is wiser and possesses some small knowledge of magic.  The "+
     "pockets are used to hold small amounts of components.");
  set_property("lore difficulty",7);
  set_size(1);
  set_value(10);
  set_weight(10);
  set_ac(1);
  set_limbs(({"torso"}));
  set_type("clothing");
  set_wear((:TO,"wear_me":));
  set_remove((:TO,"remove_me":));
}

int wear_me(){
  tell_object(ETO,"%^ORANGE%^The tiny bones and skulls rattle together "+
	"as you put on the robe.");
  tell_room(EETO,"%^ORANGE%^As "+ETO->QCN+" puts on the "+
	"robe, tiny bones and skulls rattle together.",ETO);
  return 1;
}

int remove_me(){
  tell_object(ETO,"%^BOLD%^%^YELLOW%^You finaly get some peace and quiet "+
	"as you slip out of the robe.");
  tell_room(EETO,"%^BOLD%^%^YELLOW%^As "+ETO->query_cap_name()+" slides "+
	"out of the robe, the constant clatter from the small "+
	"bones finally ends.",ETO);
  return 1;
}
