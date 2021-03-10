// camel: exotic mount for azha, by Nienne, 10/04 //
#include <std.h>
inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"camel"}));
  set_name("camel");
  set_short("%^RESET%^%^ORANGE%^A desert camel%^RESET%^");
  set_long("This docile-looking creature has a single hump, and cloven hooves.  Its large brown eyes stare balefully around, and it moves rather slowly.");
  set_value(1000);
  set_race("camel");
  set_body_type("quadruped");
  set_max_hp(80);
  set_hd(3,1);
  set_max_distance(400);
  set_enter_room(" plods in on a camel.");
  set_exit_room(" plods out on a camel.");
  set_vehicle_short("%^RESET%^%^ORANGE%^A desert camel%^RESET%^");
  set_riding_level(8);
  TO->force_me("message in ambles in.");
  TO->force_me("message out ambles out $D.");
}
