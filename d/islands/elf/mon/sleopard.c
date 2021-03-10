//snow leopard exotic mount by hades//
#include <std.h>
inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"leopard","snow leopard","animal"}));
  set_name("snow leopard");
  set_short("A snow leopard");
  set_long("This is a large white stripped cat."+
  "  It has soft white fur with black stripes."+
  "  The leopard looks massive and could easily"+
  " knock down a person with a swipe of its paw.");
  set_value(20000);
  set_race("leopard");
  set_body_type("quadruped");
  set_hd(18,6);
  set_max_hp(250);
  set_hp(250);
  set_max_distance(500);
  set_enter_room(" rides in on a large snow leopard.");
  set_exit_room(" leaves riding a large snow leopard.");
  set_vehicle_short("snow leopard");
  set_riding_level(25);
  set_base_damage_type("slashing");
}