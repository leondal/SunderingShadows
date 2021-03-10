#include <std.h>

inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"horse","animal"}));
  set_name("horse");
  set_short("A horse");
  set_long("This is a riding horse.");
  set_value(500);
  set_race("horse");
  set_body_type("equine");
  set_max_hp(80);
  set_hd(1,6);
  set_max_distance(500);
  set_enter_room(" rides in.");
  set_exit_room("leaves riding a horse.");
  set_vehicle_short("Horse");
  set_riding_level(8);
}
