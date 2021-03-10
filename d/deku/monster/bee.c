//added more reasonable hp & exp for quick patch - Styx 8/3/01
#include <std.h>
inherit MONSTER;

void create() {
  ::create();
  set_name("bee");
  set_id(( { "bee", "killer bee"} ));
  set_race("bee");
  set_gender("neuter");
  set_short("Killer bee");
  set_long("Killer bees are 1' long giant bees with a very vicious temper.\n"+
             "Killer bees attack on sight, especially anyone within 30' of\n"+
             "their hive.");
  set_alignment(6);
  set_body_type("insect");
  set("aggressive", 15);
  set_size(1);
  set_hd(5,1);
  set_overall_ac(6);
  set_hp(30);
  set_exp(30);
}
