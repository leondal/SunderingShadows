#include <std.h>;
inherit "/std/weapon";

void create() {
  ::create();
  set_name("Staff");
  set_id(({ "staff", "long staff" }));
  set_short("A Long Staff");
  set_long("The warped wood of this staff lends it an Arcane sense.");
  set_type("bludgeoning");
  set_wc(1,6);
  set_hit((: this_object(), "big_hit" :));
  set_weight(3);
  set_value(500);
   set_prof_type("staff");
}

int big_hit() {
  write("%^BOLD%^%^BLUE%^Your staff smashes you opponent!%^RESET%^");
  say("%^BOLD%^%^BLUE%^"+TPQCN+"'s staff smashes "+TP->query_possessive()+" opponent!%^RESET%^");
  return random(5);
}
