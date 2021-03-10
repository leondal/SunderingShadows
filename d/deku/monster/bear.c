//added more reasonable hp & exp for quick patch - Styx 8/3/01
#include <std.h>

inherit WEAPONLESS ;

create() {
    ::create();
	set_name("bear");
	set_id( ({ "bear" }) );
	set_race("bear");
	set_gender("male");
	set_short("Black Bear");
 set_long("This is a large black bear.  He doesn't like strangers.");
	set_body_type("quadruped");
 set("aggressive",5);
 set_alignment(3);
 set_size(2);
 set_hd(8,1);
 set_stats("intelligence",6);
 set_stats("wisdom",4);
 set_stats("strength",16);
 set_stats("charisma",3);
 set_stats("dexterity",10);
 set_stats("constitution",11);
 set_max_hp(query_hp());
	set_overall_ac(4);
 set_hp(50);
 set_exp(50);
}
