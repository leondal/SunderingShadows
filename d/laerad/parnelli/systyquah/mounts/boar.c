//boar exotic mount for systyquah by Bane//
#include <std.h>

inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"boar"}));
  set_name("boar");
  set_short("A wild boar");
  set_long("This is a riding boar from Systyquah.");
  set_value(1500);
  set_race("boar");
  set_body_type("quadruped");
  set_max_hp(150);
  set_hp(150);
  set_hd(3,1);
  set_max_distance(500);
  set_enter_room(" rides in on a wild boar.");
  set_exit_room(" leaves riding a wild boar.");
  set_vehicle_short("Boar");
  set_riding_level(15);
}
