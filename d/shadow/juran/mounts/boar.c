#include <std.h>
#include <daemons.h>
inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"boar","mount"}));
  set_name("boar");
  set_short("A wild boar");
  set_long("This boar has been tamed down enough for smaller races to ride.");
  set_value(700);
  set_race("boar");
  set_body_type("quadruped");
  set_max_hp(120);
  set_hp(120);
  set_hd(3,1);
  set_max_distance(20);
  set_enter_room(" rides in on a wild boar.");
  set_exit_room(" leaves riding a wild boar.");
  set_vehicle_short("boar");
  set_riding_level(12);
}