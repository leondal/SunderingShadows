#include <std.h>
#include <daemons.h>
inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"donkey","mount"}));
  set_name("donkey");
  set_short("A donkey");
  set_long("This ia a riding donkey, the most docile of the mounts found here.");
  set_value(500);
  set_race("donkey");
  set_body_type("equine");
  set_max_hp(50);
  set_hp(50);
  set_hd(3,1);
  set_max_distance(20);
  set_enter_room(" rides in on a donkey.");
  set_exit_room(" leaves riding a donkey.");
  set_vehicle_short("donkey");
  set_riding_level(5);
}
