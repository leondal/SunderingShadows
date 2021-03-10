#include <std.h>
#include <daemons.h>

inherit NPC;

void create(){
::create();
	set_name("ookla");
	set_short("Ookla the old gnoll");
	set_id(({"Ookla","ookla","gnoll","old gnoll"}));
	set_long(
		"%^RESET%^%^RED%^"+
		"This gnoll is old and weathered.  His fur is gray in "+
		"many places.  He wears skins and a leather apron with "+
		"sharp knives tucked into the pockets.  The apron is stained "+
		"with new and old blood."+
		"%^RESET%^"
	);
	set_gender("male");
	set_race("gnoll");
	set_hd(30,10);
	set_max_hp(200+random(150));
	set_hp(query_max_hp());
	set_alignment(6);
	set_size(2);
	set_overall_ac(-7);
	set_class("ranger");
	set_mlevel("ranger",30);
	set_level(30);
	set_property("full attacks",1);
   set_exp(100);
	command("speech growl");
	command("speak wizish");
  	set_speed(40);
   set_nwp("skinning",20);
  set_nwp("tracking",20);
// adding to monster_d.c placement *Styx* 3/5/05
//   "daemon/place_d"->place_in("/d/shadow/juran/city/",TO);
}
