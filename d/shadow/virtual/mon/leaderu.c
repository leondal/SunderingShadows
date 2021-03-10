#include <std.h>

inherit MONSTER;

void create(){
	int num;
	::create();
   set_body_type("human");
	set_class("fighter");
	set_hd(12+random(8),6);
   set_hp( (query_hd()*6)+random(20) );
	set_property("full attacks",1);
	set_mob_magic_resistance("average");
   set_stats("strength",19);
   set_stats("dexterity",18);
   set_stats("wisdom",18);
   set_stats("charisma",6);
   set_overall_ac(0);
	set_gender("male");
   set_max_level(20);
   set_moving(1);
   set_speed(50);
   set_property("swarm", 1);
	set_long("This is the spectre of a warrior who once traveled these passages.");
       set_wielding_limbs(({"right hand","left hand"}));
	set_size(1);
	num = random(5);
	switch(num){
		case 0:
			set_name("kobold spectre");
			set_short("kobold spectre");
			set_id(({"kobold","spectre","kobold spectre","Spectre","Kobold spectre"}));
			set_race("kobold");
			new("/d/shadow/virtual/mon/kclaws")->move(TO);
			command("wield claws");
			new("/d/shadow/virtual/mon/kbracelet")->move(TO);
			command("wear bracelet");
			break;
		case 1:
			set_name("gnome spectre");
			set_short("gnome spectre");
			set_id(({"gnome","spectre","gnome spectre","Spectre","Gnome spectre"}));
			set_race("gnome");
			new("/d/shadow/virtual/mon/gpick")->move(TO);
			command("wield pick");
			break;
		case 2:
			set_name("halfling spectre");
			set_short("halfling spectre");
			set_id(({"halfling","spectre","halfling spectre","Spectre","Halfling Spectre"}));
			set_race("halfling");
			new("/d/shadow/virtual/mon/hdagger")->move(TO);
			command("wield dagger");
			break;
		case 3:
/*                        set_name("dwarf spectre");
			set_short("dwarf spectre");
			set_id(({"dwarf","spectre","dwarf spectre","Spectre","Dwarf Spectre"}));
			set_race("dwarf");
			new("/d/shadow/virtual/mon/dhammer")->move(TO);
			command("wield hammer");
			break;
                case 4: */
			set_name("goblin spectre");
			set_short("Goblin Spectre");
			set_race("goblin");
			set_id(({"goblin","spectre","goblin spectre"}));
			new("/d/shadow/virtual/mon/ggirdle")->move(TO);
			command("wear girdle");
			new("/d/shadow/room/goblin/obj/lsword")->move(TO);
			command("wield sword");
    		break;
	 }
}
