//Redone by Saide - A real Air elmental, anyone?
#include <std.h>
inherit WEAPONLESS;

create() {
  ::create();
  set_name("elemental");
  set_id(({"air","elemental"}));
  set_gender("neuter");
  set_race("elemental");
  set_short("Air elemental");
  set_long("A swirling mass of air.  Dust and dirt particles seem to dance about the "+
  "swirling vortex.  It's just air though, what harm can it do?!");
  set_hd(10,3);
  set("aggressive",16);
  set_size(3);
  set_hp(70 + random(31));
  set_alignment(8);
  set_body_type("elemental");
  set_attacks_num(3);
  set_stats("strength",18);
  set_stats("wisdom",16);
  set_stats("intelligence",15);
  set_stats("dexterity",18);
  set_stats("constitution",14);
  set_stats("charisma",12);
  set_damage(2,4);
  set_exp(query_max_hp() * 10);
  set_overall_ac(2);
  set_property("magic",1);
	set_new_exp(10, "very low");
}
