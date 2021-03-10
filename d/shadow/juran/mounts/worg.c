#include <std.h>
#include <daemons.h>
inherit "/std/riding_animal";

void create(){
  	::create();
  	set_id(({"worg","wolf","steed","mount"}));
  	set_name("worg");
  	set_short("%^RESET%^%^RED%^A powerful worg");
  	set_long(
		"%^RESET%^%^ORANGE%^"+
		"This is a large wolf creature that has been trained "+
		"as a mount.  The beast looks barely trained and his "+
		"large canine teeth look capable of doing great damage."+
		"%^RESET%^"
  	);
   set_riding_level(15);
  	set_level(10);
  	set_value(1000);
  	set_race("worg");
  	set_stats("strength",14);
  	set_gender("male");
  	set_body_type("quadruped");
  	set_size(2);
  set_max_hp(150);
  set_hp(150);
  	set_hd(10,2);
  	set_hp(75);
  	set_exp(100);
  	set_max_distance(20);
  	set_enter_room("prowls in riding a worg");
  	set_exit_room("leaves riding a worg.");
  	set_vehicle_short("worg");
}
