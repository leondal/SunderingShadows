#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

create() {
  	::create();
  	set_name("giant fly");
  	set_id( ({ "insect", "monster", "vermin", "fly", "giant fly" }) );
  	set_short("A giant fly");
  	set("aggressive", 0);
  	set_level(3);
  	set_hd(2,5);
  	set_long("This is a huge replica of the common house fly.\n");
  	set_body_type("insectoid-winged");
  	set_alignment(5);
  	set_race("insect");
  	set_exp(100);
}
