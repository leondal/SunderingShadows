#include <std.h>
#include <daemons.h>

inherit NPC;

void create(){
::create();
	set_name("skinkpuss");
	set_short("Skinkpuss, goblin forager");
	set_id(({"skinkpuss","Skinkpuss","goblin","forager","goblin forager"}));
	set_long(
		"%^RESET%^%^ORANGE%^"+
		"Skinkpuss is a smallish goblin with one of the ugliest faces "+
		"you have ever seen.  His eyes are always darting "+
		"around watching everything in a very nervous, paranoid fashion.  The "+
		"little beast's grubby tunic is covered in pockets and patches "+
		"and from almost every patch there is a small dead animal or "+
		"insect hanging half in, half out."+
		"%^RESET%^"
	);
	set_gender("male");
	set_race("goblin");
	set_hd(30,10);
	set_max_hp(200+random(250));
	set_hp(query_max_hp());
	set_alignment(6);
	set_size(1);
	set_overall_ac(-7);
	set_class("fighter");
	set_mlevel("fighter",30);
	set_level(30);
	set_property("full attacks",1);
   set_exp(100);
	command("speech squeak");
	command("speak wizish");
  	set_speed(40);
   set_nwp("forage",20);
   set_nwp("hunting",20);
// adding to monster_d.c placement *Styx* 3/5/05
//   "daemon/place_d"->place_in("/d/shadow/juran/city/",TO);
}