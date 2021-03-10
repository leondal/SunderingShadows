//  Governor ibn Shiraz's magical stun staff +3
//  Thorn@ShadowGate
//  970413
//  Azha Area
//  stun_staff.c

#include <std.h>

inherit "/std/weapon";

object old;
object owner;
int duration;

create() {
   ::create();
   set_id(({ "quarterstaff", "magical quarterstaff", "staff" }));
   set_name("quarterstaff");
   set_short("An ornate quarterstaff");
   set_property("enchantment", 3);
   set_long(
@TSARVEN
  This a fairly normal looking bronzewood staff banded with iron.  You notice
some carvings in the Tsarvani style in certain places on the staff for some
decoration.  Although it seems ornamental, this staff is quite solid looking
and would serve well in a fight.
TSARVEN
       );
   set_wc(1,6);
   set_weight(4);
   set_size(1);
   set("value", 50);
   set_type("bludgeoning");
   set_prof_type("staff");
   set_hit((:this_object(), "extra_hit":));
}

int extra_hit(object target) 
{
  if(random(100) >= 30) return 0;
  else if(target->query_paralyzed()) return 0;
  else {
    tell_object(target, "%^BLUE%^You feel yourself feel faint and "+
                "collapse to the ground!");
    tell_room(environment(target), target->query_cap_name()+
              " falls to the ground, stunned temporarily.",
              ({ target }));
    target->set_paralyzed(20);
    return random(3);
  }
  return 0;
}
