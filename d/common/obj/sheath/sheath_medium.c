#include <std.h>
#include "/d/common/common.h"

inherit SHEATH_INHERIT ;

mixed query_property(string str) { return ::query_property(str); }

void create(){
  ::create(); 
  remove_property("can_hold");
set_property("can_hold",({ "short blades","medium blades","rapier"}));
  remove_property("can_wear_limbs");
  set_property("can_wear_limbs",({ "waist" , "torso" }));
  remove_property("sheath_size");
  remove_property("original_weight");
  set_property("sheath_size",2);
  set_property("original_weight",2);
  set_name("medium blade sheath");
  set_id(({"sheath", "medium sheath","medium sheaths","medium Sheaths","medium Sheath", "weapsheath"}));


  set_short("A medium sheath");
  set_long("This is a weapons sheath. It is meant to hold a single"+
	" medium-sized bladed weapon, and has adjustable straps to hold"+
	" it on your body. The straps could be easily adjusted to hold the"+
	" sheath in more than one location, allowing easy access for the "+
	"weapon that it holds.");

  set_max_internal_encumbrance(20);
}




