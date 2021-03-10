//cheetah exotic mount for systyquah by Bane//
#include <std.h>
inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"cheetah"}));
  set_name("cheetah");
  set_short("A wild cheetah");
  set_long("This is a riding cheetah from Systyquah.");
  set_value(2000);
  set_race("cheetah");
  set_body_type("quadruped");
  set_max_hp(150);
  set_hp(150);
  set_hd(3,1);
  set_max_distance(500);
  set_enter_room(" rides in on a wild cheetah.");
  set_exit_room(" leaves riding a wild cheetah.");
  set_vehicle_short("Cheetah");
  set_riding_level(15);
}
