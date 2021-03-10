#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

create() {
  	::create();
  	set_name("insect");
  	set_id( ({ "insect", "monster", "vermin", "fly" }) );
  	set_short("An insect");
  	set("aggressive", 0);
  	set_level(1);
  	set_hd(1,0);
  	set_long("This is a tiny winged insect, ruining the crops.\n");
  	set_body_type("insectoid-winged");
  	set_alignment(5);
  	set_race("insect");
  	set_exp(50);
}
