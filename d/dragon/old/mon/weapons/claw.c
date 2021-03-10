#include <std.h>
inherit WEAPON;

void create() {
	::create();
	set_name("dragon claw");
	set_id(({"claw","dragon claw"}));
   set_property("monsterweapon",1);
   set_type("slashing");
   set("short","claws");
   set("long","claws from the corpse of Cathardon.");
	set_wc(1,10);
	set_large_wc(1,10);
	set_hit((:TO,"hit":));
}

int hit(object target) {
	object dragon = environment(TO);
	
     if(((string)dragon->query_cap_name() == "Cathardon")) {
		dragon->set_rake(target);
	}
	return 0;
}

