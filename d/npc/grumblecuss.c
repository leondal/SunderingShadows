#include <std.h>
#include <daemons.h>

inherit NPC;

void create(){
::create();
	set_name("grumblecuss");
	set_short("Grumblecuss, goblin rider");
	set_id(({"Grumblecuss","grumblecuss","goblin","forager","goblin rider"}));
	set_long(
		"%^RESET%^%^ORANGE%^"+
		"Grumblecuss is a large goblin that is wearing ragtag "+
		"armor and carry a small spear that he holds like a lance.  "+
		"The goblin is riding a worg."+
		"%^RESET%^"
	);
	set_gender("male");
	set_race("goblin");
	set_hd(30,10);
	set_max_hp(200+random(250));
	set_hp(query_max_hp());
	set_alignment(6);
  	call_out("do_worg",1);
	set_size(1);
	set_overall_ac(-7);
   set_class("fighter");
   set_mlevel("fighter", 30);
   add_search_path("/cmds/fighter");
	set_property("full attacks",1);
   set_exp(100);
	command("speech grunt");
	command("speak wizish");
  	set_speed(40);
   set_nwp("riding",20);
// adding to monster_d.c placement *Styx* 3/5/05
//   "daemon/place_d"->place_in("/d/shadow/juran/city/",TO);
}

void do_worg() {
   	object bike;
   	if(!objectp(ETO)) return;
   	bike = new("/d/shadow/juran/mons/worg");
   	bike->set_owner(TO);
   	bike->move(ETO);
   	command("mount worg");
}