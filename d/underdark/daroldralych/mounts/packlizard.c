#include <std.h>
inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"packlizard","lizard","heavy lizard","pack lizard"}));
  set_name("packlizard");
  set_short("A heavy packlizard");
  set_long("This darkskinned, dim-witted looking lizard is obviously not for standard riding, as due to its "
"massive size it would be of little use in the narrow tunnels of the underdark.  It would, however, be ideal "
"for travelling the more prominent roads, and its great strength would allow it to carry large loads and "
"caravans for long distances.");
  set_value(125);
  set_race("lizard");
  set_body_type("reptile");
  set_max_hp(30);
  set_hd(5,10);
  set_size(3);
  set_max_distance(1000);
  set_enter_room(" rides in on a large lizard.");
  set_exit_room(" rides in on a large lizard.");
  set_vehicle_short("A large pack lizard");
  set_riding_level(3);
  TO->force_me("message in plods in.");
  TO->force_me("message out plods out $D.");
  set_property("knock unconscious",1);
}
