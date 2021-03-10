#include <std.h>
inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"rothe","shaggy rothe","large rothe","large shaggy rothe"}));
  set_name("rothe");
  set_short("A large shaggy rothe");
  set_long("This is a rothe, the underdark equivalent of cattle.  It has an appearance closest to that of an "
"ox, with curved horns and cloven hooves.  A thick, dark coat of shaggy fur covers its massive frame.  Its "
"dull eyes show a rather dim intellect even for an animal, and it moves with a slow, lumbering gait.");
  set_value(125);
  set_race("rothe");
  set_body_type("quadruped");
  set_max_hp(50);
  set_hd(3,1);
  set_size(3);
  set_max_distance(1000);
  set_enter_room(" rides in on a shaggy rothe.");
  set_exit_room(" leaves riding a shaggy rothe.");
  set_vehicle_short("A large shaggy rothe");
  set_riding_level(1);
  TO->force_me("message in ambles in.");
  TO->force_me("message out ambles out $D.");
  set_property("knock unconscious",1);
}
