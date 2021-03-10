// stallion: exotic mount for azha, by Nienne, 10/04 //
#include <std.h>
inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"stallion"}));
  set_name("stallion");
  set_short("%^WHITE%^%^BOLD%^A proud desert stallion%^RESET%^");
  set_long("This tall stallion has the air of a wild creature, with a proud standing, alert eyes and well-toned muscles.  It appears to be a particularly good equine specimen, for those with the skill to ride it.");
  set_value(500);
  set_race("horse");
  set_body_type("equine");
  set_max_hp(120);
  set_hd(3,1);
  set_max_distance(500);
  set_enter_room(" trots in on a proud stallion.");
  set_exit_room(" trots out on a proud stallion.");
  set_vehicle_short("%^WHITE%^%^BOLD%^A proud desert stallion%^RESET%^");
  set_riding_level(12);
  TO->force_me("message in trots in with a proud bearing.");
  TO->force_me("message out trots out $D.");
}
