// removed tool and sorrow staff from the carried profs. Nienne, 08/07.
#include <std.h>
#include <move.h>
#include "/d/common/common.h"

#define CM TO->query_property("call_myself")

inherit SHEATH_INHERIT;

mixed query_property(string str) { return ::query_property(str); }

void create(){
  ::create(); 
  remove_property("can_hold");
  set_property("can_hold",({ "staff", "spear" }));
  remove_property("can_wear_limbs");
  set_property("can_wear_limbs",({ "waist" , "torso" }));
  remove_property("sheath_size");
  remove_property("original_weight");
  set_property("sheath_size",2);
  set_property("original_weight",2);
  set_name("medium weapon sleeve");
  set_id(({"casing", "sleeve", "medium weapon sleeve", "medium sleeve", "weapon sleeve", "weapsheath" }));
  set_short("A medium weapon sleeve");
  set_long(
@STYX
This is a sleeve-type case suitable for weapons such as staves and spears.  It is a long tube made of sturdy leather with a closed bottom that keeps the weapon from sliding all the way through.  Meant to hold a single weapon, it has adjustable straps to hold it on your body.  The straps could be easily adjusted to hold it in more than one location, allowing easy access for the weapon it holds.
STYX
);
  set_max_internal_encumbrance(20);
}
