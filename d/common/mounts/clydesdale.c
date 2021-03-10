// clydesdale: new large mount for antioch, by Nienne, 11/04 //
#include <std.h>
inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"clydesdale","workhorse","horse"}));
  set_name("clydesdale");
  set_short("A large clydesdale workhorse");
  set_long("This horse is one of the largest you've ever seen, of sturdy build and obviously bred for strong, heavy work.  Despite its size and build, it looks very docile.");
  set_value(125);
  set_race("clydesdale");
  set_body_type("quadruped");
  set_max_hp(50);
  set_hp(50);
  set_hd(3,2);
  set_size(3);
  set_max_distance(500);
  set_enter_room(" rides in.");
  set_exit_room(" leaves riding a great workhorse.");
  set_vehicle_short("A large clydesdale workhorse");
  set_riding_level(5);
}
