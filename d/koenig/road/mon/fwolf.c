#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

create(){
  	::create();
  	set_name("shewolf");
  	set_id( ({"wolf", "the wolf", "a wolf"}) );
  	set_short("a she-wolf");
  	set_long("They say the female in any species is the one to look out for!");
  	set_race("wolf");
  	set_gender("female");
  	set_body_type("quadruped");
  	set_hd(3);
  	set_overall_ac(7);
  	set_alignment(5);
  	set_size(1);
  	set_max_hp(40);
  	set_hp(40);
  	set_exp(120);
  	set("aggressive", 12);
}
