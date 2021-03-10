#include <std.h>
#include "/d/common/common.h"

inherit SHEATH_INHERIT;

mixed query_property(string str) { return ::query_property(str); }

void create(){
  ::create();
  remove_property("can_hold");
  set_property("can_hold",({"axe","mace","flail","club","hammer","whip","rod", "wand"}));
  remove_property("can_wear_limbs");
  set_property("can_wear_limbs",({ "waist" , "torso" }));
  remove_property("sheath_size");
  remove_property("original_weight");
  set_property("sheath_size",2);
  set_property("original_weight",2);
  set_name("medium weapon holster");
  set_id(({"holster", "medium holster", "Medium holster", "weapsheath" }));
  set_short("A medium weapon holster");
  set_long(
@STYX
This is a holster suitable for a variety of medium sized weapons.  A six-inch wide strip of leather forms an open-bottomed sheath for the handle, making it suitable for weapons such as axes, hammers, and others with a straight handle or head larger than the handle.  It has a wide, flexible leather pad at the top which folds over to protect the wearer from the head of the weapon.  The pad can also be flipped up to cradle the coils of a whip while the handle rests in the holster part.  It has adjustable strap, giving a number of options for how to wear it.
STYX
);
  set_max_internal_encumbrance(20);
}
