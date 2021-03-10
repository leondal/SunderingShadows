#include <std.h>
inherit WEAPON;

void create() {
  ::create();
  set_name("staff");
  set_id(({ "staff", "wizard's staff" }));
  set_short("A wizard's staff");
  set_long(
"This small but sturdy weapon looks ancient and mystic. It is sturdy enough\n"+
"to do some good damage.");
  set_weight(3);
  set_value(4000);
  set_wc(1,6);
  set_hit((: this_object(), "special" :));
  set_type("blunt");
   set_prof_type("staff");
}

void blunt(object ob) {
  int hit;
  hit=random(15);
  if(hit > random(100)) {
    write("%^GREEN%^Your wizard's staff hits of it's own accord!%^RESET%^");
    tell_room(environment(TP), "%^GREEN%^"+TPQCN+"'s staff hits "+ob->query_cap_name()+" of it's own accord!%^RESET%^", ({ TP, ob}));
    tell_object(ob, "%^GREEN%^"+TPQCN+"'s staff hits you of it's own accord!%^RESET%^");
    return random(20);
  }
}
