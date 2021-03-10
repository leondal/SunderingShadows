#include <std.h>
inherit "/std/armour";
create() {
    ::create();
  set_name("maids uniform");
  set_id(({"uniform","dress","maids uniform"}));
    set_short("Maid's uniform");
    set_long(
    "  You're not entirely sure what the maid who wore this skimpy black outfit was actually hired for."
    "  One with less morals than blessings it would appear from the the cut of the front."
    "  A small lace apron adorns the front and a white lace frill runs along the ends of the sleeves and collar."
    );
  set_weight(10);
  set_value(100);
    set_type("clothing");
     set_limbs(({"torso"}));
}
