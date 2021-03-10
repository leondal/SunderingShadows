#include <std.h>

inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"horse","sick looking horse"}));
  set_name("sick looking horse");
  set_short("A sickly looking horse");
  set_long("  This animal looks ratty and uncared for by its owner.  You wonder what kind of beast would let his mount get to this state?");
  set_value(2);
  set_exp(100);
  set_race("horse");
  set_body_type("equine");
  set_max_hp(25);
  set_hd(3,6);
  set_max_distance(500);
  set_enter_room(" rides in on a sickly looking horse.");
  set_exit_room("leaves riding a sickly looking horse.");
  set_vehicle_short("Sickly looking horse");
}
