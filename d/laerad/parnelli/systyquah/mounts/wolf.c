//wolf exotic mount for systyquah by Bane//
#include <std.h>

inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"wolf"}));
  set_name("wolf");
  set_short("A large wolf");
  set_long("This is a riding wolf from Systyquah.");
  set_value(1500);
  set_race("wolf");
  set_body_type("quadruped");
  set_max_hp(120);
  set_hp(120);
  set_hd(3,1);
  set_max_distance(500);
  set_enter_room(" rides in on a large wolf.");
  set_exit_room(" leaves riding a large wolf.");
  set_vehicle_short("Wolf");
  set_riding_level(12);
}
