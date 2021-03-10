#include <std.h>
#include "/d/common/common.h"

inherit SHEATH_INHERIT ;

mixed query_property(string str) { return ::query_property(str); }

// Special overload for the huge fragging sheath.
int query_size() {return 3;}

void create(){
  ::create();
  remove_property("can_hold");
  set_property("can_hold",({ "great blades", "giant blades" }));
  remove_property("can_wear_limbs");
  set_property("can_wear_limbs",({ "waist" , "torso" }));
  remove_property("sheath_size");
  remove_property("original_weight");
  set_property("sheath_size",4);
  set_property("original_weight",4);
  set_name("great blade sheath");
  set_id(({"sheath","extra-large sheath", "extra-large sheaths", "great sheath","great sheaths","great Sheaths","great Sheath" , "weapsheath"}));


  set_short("A extra-large sheath");
  set_long(
@GARRETT
This is a weapons sheath. It is meant to hold a single extra-large-sized
bladed weapon, and has adjustable straps to hold it on your body. The
straps could be easily adjusted to hold the sheath in more than one location,
allowing easy access for the weapon that it holds. It appears only a giant could wear such a big sheath, however.
GARRETT
);

  set_max_internal_encumbrance(60);
}
