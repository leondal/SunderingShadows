//elk exotic mount by hades//
#include <std.h>
inherit "/std/riding_animal";

void create(){
  ::create();
  set_id(({"elk","riding elk"}));
  set_name("elk");
  set_short("elk");
  set_long("This elk is a rather large creature "+
  "covered with thick fur.  These creatures are"+
  " quite large and nearly impossible to train.");
  set_value(20000);
  set_race("elk");
  set_body_type("quadruped");
  set_hd(18,6);
  set_max_hp(250);
  set_hp(250);
  set_max_distance(500);
  set_enter_room(" rides in on an elk.");
  set_exit_room(" leaves riding an elk.");
  set_vehicle_short("elk");
  set_riding_level(25);
  set_base_damage_type("bludgeoning");
}