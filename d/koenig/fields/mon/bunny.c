#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

create() {
  	::create();
  	set_name("bunny");
  	set_id( ({ "bunny", "monster", "vermin", "rabbit" }) );
  	set_short("A cute bunny");
  	set("aggressive", 0);
  	set_level(1);
  	set_hd(1,1);
  	set_long("This is a small white rabbit, eating corn.\n");
  	set_body_type("quadruped");
  	set_alignment(5);
  	set_race("bunny");
      set_exp(50);
}
