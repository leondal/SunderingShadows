//tyrg exotic mount for systyquah by Bane//
#include <std.h>

inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"tyrg"}));
  set_name("tyrg");
  set_short("A sleek tyrg");
  set_long("This is a riding tyrg from Systyquah.");
  set_value(2000);
  set_race("tyrg");
  set_body_type("quadruped");
  set_max_hp(150);
  set_hp(150);
  set_hd(4,1);
  set_max_distance(500);
  set_enter_room(" rides in on a sleek tyrg.");
  set_exit_room(" leaves riding a sleek tyrg.");
  set_vehicle_short("Tyrg");
  set_riding_level(15);
}
