#include <std.h>
inherit MONSTER;
void create(){
  ::create();
  set_name("brown rat");
  set_id(({"rat","brown rat"}));
  set_short("Brown rat");
  set_long(
  "  This small brown rat's fur glistens with health."
   "  It skitters about with a healthy respect for you trying to keep out of your way, unlike a great many other rats you've seen."
  );
  set_hd(1,1);
  set_max_hp(25);
  set_hp(25);
  set_race("rat");
  set_body_type("quadruped");
  set_ac(5);
  set_exp(1);
  set_moving(1);
  set_speed(20);
}
