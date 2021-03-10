//Coded by Lujke
#include <std.h>
#include "../tecqumin.h"
inherit MONSTER;

void create()
{
      ::create();
  	set_name("the battlement");
      set_property("not random monster", 1);
  	set_id(({"battlement"}));
  	set_short("wooden battlement");
      set_gender("neuter");
      set_long("A reinforced wooden battlement");
   	set_race("crenellation");
  	set_body_type("humanoid");
   	set_hp(3000);
   	set_exp(0);
}
