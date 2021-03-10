//bear exotic mount for systyquah by Bane//
#include <std.h>

inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"bear"}));
  set_name("bear");
  set_short("A great bear");
  set_long("This is a riding bear from Systyquah.");
  set_value(2200);
  set_race("bear");
  set_body_type("quadruped");
  set_max_hp(120);
  set_hp(120);
  set_hd(3,1);
  set_size(3);
  set_max_distance(500);
  set_enter_room(" rides in on a great bear.");
  set_exit_room(" leaves riding a great bear.");
  set_vehicle_short("Bear");
  set_riding_level(12);
}
