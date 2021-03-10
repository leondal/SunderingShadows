#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

create() {
  	::create();
  	set_name("mouse");
  	set_id( ({ "mouse", "monster", "vermin", "field mouse" }) );
  	set_short("A brown field mouse");
  	set("aggressive", 0);
  	set_level(1);
  	set_hd(1,0);
  	set_long("This is a tiny field mouse, doing its part to trash the field.\n");
  	set_body_type("quadruped");
  	set_alignment(5);
  	set_race("mouse");
  	set_exp(50);
}
