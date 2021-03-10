#include <std.h>
#include <daemons.h>

inherit NPC;

void create(){
::create();
	set_name("thrance");
	set_short("Thrance Urilson, skinner");
	set_id(({"Thrance Urilson","thrance","Thrance","dwarf","skinner"}));
	set_long(
		"%^RESET%^%^RED%^"+
		"The dwarf wears breeches and a leather apron.  Stuck "+
		"in the pockets of the apron you can see the handles of "+
		"many different knives.  The dwarf smells of blood and "+
		"his chest hair and beard have bits of dried blood and "+
		"fatty material from the skins he has produced.  The "+
		"dwarf smells of an abbatoir."+
		"%^RESET%^"
	);
	set_gender("male");
	set_race("dwarf");
	set_hd(30,10);
	set_max_hp(200+random(250));
	set_hp(query_max_hp());
	set_alignment(8);
	set_body_type("human");
	set_size(1);
	set_overall_ac(-7);
	set_class("fighter");
	set_mlevel("fighter",30);
	set_level(30);
	set_property("full attacks",1);
   set_exp(100);
	command("speech grate");
	command("speak wizish");
  	set_speed(40);
   set_nwp("skinning",10,500);
//  changing to load from Garrett's improved /daemon/monster_d.c to solve clean_up problems & save memory, more flexibility, easier maintenance, etc. *Styx*  3/23/03
//   "daemon/place_d"->place_in("/d/tharis/conforest/rooms/",TO);
}