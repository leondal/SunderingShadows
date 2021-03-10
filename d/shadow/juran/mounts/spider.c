#include <std.h>
#include <daemons.h>
inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"spider","mount"}));
  set_name("spider");
  set_short("A giant spider");
  set_long("This is a spider that has been grown by drow for the purpose of riding.");
  set_value(1100);
  set_race("spider");
  set_body_type("arachnid");
  set_max_hp(180);
  set_hp(180);
  set_hd(3,1);
  set_max_distance(20);
  set_enter_room(" skitters in on a giant spider.");
  set_exit_room(" leaves riding a giant spider.");
  set_vehicle_short("spider");
  set_riding_level(18);
}
