#include <std.h>
#include <daemons.h>

inherit NPC;

void create(){
::create();
	set_name("shiper");
	set_short("Shiper Cumple, grizzled veteran");
	set_id(({"Shiper","shiper","Shiper Cumple",
		"shiper cumple","veteran","grizzled veteran","woodsman","human"}));
	set_long(
		"%^RESET%^%^GREEN%^"+
		"This grizzled old woodsman wears leathers that have creases "+
		"and cracks that show they have been worn for ages.  The "+
		"woodsman is old, but there still seems to be a liveliness "+
		"to his step and a sinew to his muscle that would lead you "+
		"to believe he is fit and ready for any trouble.  His craggy "+
		"face is lined by age and by the scars of a rough life and his "+
		"hair has grayed so that no trace of the original color exists."+
		"%^RESET%^"
	);
	set_gender("male");
	set_race("human");
	set_hd(30,10);
	set_max_hp(200+random(150));
	set_hp(query_max_hp());
	set_alignment(8);
	set_body_type("humanoid");
	set_size(2);
	set_overall_ac(-7);
	set_class("ranger");
	set_mlevel("ranger",30);
	set_level(30);
	set_property("full attacks",1);
   set_exp(10000);
	command("speech grumble");
	command("speak wizish");
  	set_speed(40);
   set_nwp("hunting",10,500);
//  changing to load from Garrett's improved /daemon/monster_d.c to solve clean_up problems & save memory, more flexibility, easier maintenance, etc. *Styx*  3/23/03
//   "daemon/place_d"->place_in("/d/tharis/conforest/rooms/",TO);
}