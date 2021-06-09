//Had to create a special will_work function to include the crossbow without //letting it hold all staves since they use staff prof for non-lrange use.
//Styx 8/3/01

#include <std.h>
#include "/d/common/common.h"

inherit SHEATH_INHERIT;

mixed query_property(string str) { return ::query_property(str); }

void create(){
  ::create();
  remove_property("can_hold");
  set_property("can_hold",({ "giant axe", "giant clublike", "giant hammer", "large hammer", "crossbow", "large clublike", "large axe" }));
  remove_property("can_wear_limbs");
  set_property("can_wear_limbs",({ "waist" , "torso" }));
  remove_property("sheath_size");
  remove_property("original_weight");
  set_property("sheath_size",4);
  set_property("original_weight",4);
  set_name("giant weapon holster");
  set_id(({"holster", "giant holster", "Giant holster", "weapsheath" }));
  set_short("A giant weapon holster");
  set_long(
@STYX
This is a holster suitable for giant sized axes, hammers, clubs, and similar weapons.  A foot-wide strip of leather forms an open-bottomed sheath so it will hold most any length handle as long as the head is large enough to keep the weapon from slipping all the way through.  It has a wide, flexible leather pad at the top that folds over to protect the wearer from the head of the weapon and help steady it, as well as adjustable straps for your back.
STYX
);
set_max_internal_encumbrance(50);
}

int will_work(object ths, object tht) {
  string trash;
  string *allowed;

  allowed = tht->query_property("can_hold");

  // Allow for explicit cases first...

  if (member_array(ths->query_prof_type(),allowed) != -1) return 1;
  if (member_array(ths->query_lr_prof_type(),allowed) != -1) return 1;

  // Then screen out obvious rejects...

  if (member_array(ths->query_basic_prof_type(),allowed) == -1)
    return 0;

  // Then take a good guess at axes. :P Note other code should stop greataxes
  // from going into size-1 holsters. :P

  if (sscanf(ths->query_prof_type(),"%s axe",trash) == 1) {
    if ((member_array("bludgeoning", allowed) != -1) ||
	(member_array("bludgeoning", allowed) != -1) )
      return 1;
    else
      return 0;
  }  else if ((string)ths->query_prof_type() == "polearm")
      return 0;
  else if (((string)ths->query_prof_type() == "whip") ||
	   (string)ths->query_prof_type() == "drider whip")
    return 0;

  return 1;
}
