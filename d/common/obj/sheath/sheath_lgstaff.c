//Had to add a check for lrweapon with the weight check for the 
//put_into and sheath_into.  The lrweapon code increases the query_size 
//to lrweapons to force them to two handed for larger races, which made
//the size 3 bow not fit in a size 3 sheath when a large PC was holding it.
//Garrett identified the problem, fix by Styx  8/3/01 into the inherit file
//Note - Putting the fix here created problems with the variables for MOVE, etc.
//not being available.
//Added will_work function with line to allow the lrweapon recurved bows to 
//work since they don't use the staff prof.
//"death scythe" added by Circe to accommodate the Scythe of Death 
//from Dagger marsh 6/30/05

// changed large spear to just spear - cythera 8/05

#include <std.h>
#include "/d/common/common.h"

inherit SHEATH_INHERIT;

mixed query_property(string str) { return ::query_property(str); }

void create(){
  ::create(); 
  remove_property("can_hold");
set_property("can_hold",({ "staff", "spear", "polearm", "large tool",
  "fork", "scythe", "long bow", "short bow", "recurved bow", "death scythe" }));
//actually, they would hold bows because of their staff prof for non-lr use
  remove_property("can_wear_limbs");
  set_property("can_wear_limbs",({ "waist" , "torso" }));
  remove_property("sheath_size");
  remove_property("original_weight");
  set_property("sheath_size",3);
  set_property("original_weight",4);
  set_name("large weapon sleeve");
  set_id(({"sleeve", "large weapon sleeve", "large sleeve", "weapon sleeve", "weapsheath" }));
  set_short("A large weapon sleeve");
  set_long(
@STYX
This is a sleeve-type casing suitable for long weapons such as staves, large spears, and polearms.  It is a long tube made of sturdy leather with a closed bottom that keeps the weapon from sliding all the way through.  It also has a couple of hooks along the side that can cradle a bow or, of course, a bow could be unstrung and slipped inside the sleeve.  Meant to hold a single weapon, it has adjustable straps to hold it on your body.  The straps could be easily adjusted to hold it in more than one location
STYX
);

  set_max_internal_encumbrance(20);
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
