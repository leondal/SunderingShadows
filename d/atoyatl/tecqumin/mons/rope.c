//Coded by Lujke
#include <std.h>
#include "../tecqumin.h"
inherit MONSTER;

void create()
{
      ::create();
  	set_name("support rope");
  	set_id(({"rope","support rope"}));
  	set_short("a short support rope");
  	set_long("A short rope supporting the hatch in the platform\n");
  	set_race("rope");
  	set_body_type("humanoid");
      set_property("not random monster", 1);
  	set_hd(1,1);
  	set_size(1);
  	set_overall_ac(-31);
}
