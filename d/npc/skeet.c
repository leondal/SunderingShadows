#include <std.h>
#include <daemons.h>

inherit NPC;

void create(){
::create();
	set_name("skeet");
	set_short("Skeet Lefthand, skinner");
	set_id(({"Skeet Lefthand","skeet","Skeet","human","skinner"}));
	set_long(
		"%^RESET%^%^RED%^"+
		"The human smiles and wipes his hand slowly over his leather "+
		"apron.  Sharp knives are safely tucked into the pockets in "+
		"his apron.  The human is dark from his days in the sun and "+
		"his skin leathery with age.  His head is nearly bald and his "+
		"grin is missing more than a few teeth."+
		"%^RESET%^"
	);
	set_gender("male");
	set_race("human");
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
        set_exp(1000);
	command("speech cough");
	command("speak wizish");
  	set_speed(80);
    set_nwp("skinning",20);
//   "daemon/place_d"->place_in("/d/dagger/Daggerdale/streets/",TO);
//  changing to load from Garrett's improved /daemon/monster_d.c to solve clean_up problems & save memory, more flexibility, easier maintenance, etc. *Styx*  3/23/03
}