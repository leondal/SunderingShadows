#include <std.h>
#include "/d/common/common.h"

inherit SHEATH_INHERIT ;

mixed query_property(string str) { return ::query_property(str); }
int query_size() {
  int possible_size;
  possible_size = ::query_size();
  if (possible_size == 1)
    return 2;
  else
    return possible_size;
}

void create(){
  ::create(); 
  remove_property("can_hold");
set_property("can_hold",({ "medium blades", "large blades","double bladed sword" }));
  remove_property("can_wear_limbs");
  set_property("can_wear_limbs",({ "waist" , "torso" }));
  remove_property("sheath_size");
  remove_property("original_weight");
  set_property("sheath_size",3);
  set_property("original_weight",4);
  set_name("large blade sheath");
    set_id(({"sheath", "large sheath","large sheaths","large Sheaths","large Sheath", "weapsheath" }));


  set_short("A large sheath");
  set_long("This is a weapons sheath. It is meant to hold a single "+
	"large-sized bladed weapon, and has adjustable straps to hold "+
	"it on your body. The straps could be easily adjusted to hold "+
	"the sheath in more than one location, allowing easy access for"+
	" the weapon that it holds. This sheath would be likely impossible"+
	" for one of the smaller races to wear.");

  set_max_internal_encumbrance(30);
}




