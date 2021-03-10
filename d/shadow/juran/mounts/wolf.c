#include <std.h>
#include <daemons.h>
inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"wolf","mount"}));
  set_name("wolf");
  set_short("A wolf");
  set_long("This wolf is fierce looking, but docile enough for a rider.");
  set_value(1500);
  set_race("wolf");
  set_body_type("quadruped");
  set_max_hp(120);
  set_hp(120);
  set_hd(3,1);
  set_max_distance(20);
  set_enter_room(" rides in on a wolf.");
  set_exit_room(" leaves riding a wolf.");
  set_vehicle_short("wolf");
  set_riding_level(12);
}
