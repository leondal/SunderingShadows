#include <std.h>
#include <daemons.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
::create();
   set_terrain(BARREN);
   set_travel(DIRT_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("Gates of Antioch");
	set_long(
	"%^WHITE%^Gates %^ORANGE%^o%^WHITE%^f %^WHITE%^Ant%^ORANGE%^i%^WHITE%^och%^RESET%^
%^ORANGE%^T%^ORANGE%^h%^WHITE%^e %^ORANGE%^g%^WHITE%^at%^ORANGE%^e%^WHITE%^s %^WHITE%^of %^WHITE%^An%^ORANGE%^t%^WHITE%^io%^ORANGE%^c%^WHITE%^h%^WHITE%^ rise up before you. They are made of hard steel that has been welded together and is very thick, it would be almost impossible to break them. They are also huge, spanning over twelve feet into the air and are easily fifteen feet across, joined to great stone %^BLUE%^po%^WHITE%^s%^BLUE%^ts%^WHITE%^ that are connected to a great stone %^BLUE%^wall%^WHITE%^ on the south and to the guard %^ORANGE%^t%^WHITE%^o%^ORANGE%^w%^WHITE%^er%^WHITE%^ on the north. There is a guard tower to the north and guards peer down at you, ready for anything. Beyond the gates you can see a %^ORANGE%^b%^WHITE%^arracks%^WHITE%^ and the start of a %^BLUE%^s%^BLUE%^t%^BLUE%^ree%^BLUE%^t%^WHITE%^ that runs further to the north.%^RESET%^"
	);
	set("night long",
	"%^BLUE%^Gates %^ORANGE%^o%^BLUE%^f %^BLUE%^Ant%^ORANGE%^i%^BLUE%^och%^RESET%^
%^BLUE%^Before you are the %^BLUE%^ga%^ORANGE%^t%^BLUE%^e%^ORANGE%^s %^ORANGE%^o%^BLUE%^f %^BLUE%^Anti%^ORANGE%^o%^BLUE%^ch%^ORANGE%^,%^BLUE%^ massively impressive. They've been built to last against almost anything and are joined to large stone %^BLUE%^po%^ORANGE%^s%^ORANGE%^t%^ORANGE%^s%^BLUE%^.%^BLUE%^ To the south the posts are attached to a great stone %^WHITE%^wa%^BLUE%^l%^WHITE%^l%^BLUE%^ that seems to surround the city and the northern one is joined to the guard %^WHITE%^tower.%^BLUE%^ Yellow light spills forth from the guard tower and watchful guards look you over. Past the gates you can see a barracks beyond the start of a cobbled %^BLUE%^stre%^WHITE%^e%^WHITE%^t%^WHITE%^.%^BLUE%^ To your east is the path back to the Antioch ruins.%^RESET%^"
	);
	set_smell("default","You can smell the sweat of hard working"+
	" guards.");
	set_listen("default","The chatter of the men in the guard"+
	" tower drifts down to you.");
	set_items(([
	({"gate","gates","gates of antioch","Gates of Antioch","gates of Antioch"}) : "These enormous iron gates are quite impressive,"+
	" they look like they would keep just about anything out.",
	"barracks" : "You can see a barracks beyond the gates to the"+
	" west.",
	({"tower","guard tower"}) : "The guard tower is a large stone"+
	" structure.",
	({"post","stone post"}) : "The gates are joined to massive"+
	" stone posts. The southern post is attached to a great stone"+
	" wall and the northern one is joined to the guard tower.",
	({"great wall","wall","stone wall"}) : "There is a great stone"+
	" wall that looks as though it encompasses the city.",
	({"trail","road","path","street","cobbles"}) : "The street"+
	" is paved with cobblestones.",
	]));
	set_exits(([
	"east" : ROOMS+"trail6",
	"west" : ROOMS+"street1",
	]));
	set_pre_exit_functions(({"west"}),({"go_west"}));
}

void reset()
{
	::reset();
        if(!present("guard")) {
		new(MONS+"paladin")->move(TO);
		new(MONS+"kyra")->move(TO);
        }
}

int go_west()
{
	object obj, shape;
      string race;
	if(!interactive(TP)) return 1;
	if(present("guard") && !TP->query_invis()) {
      if((string)TP->query_name() == "vethor" || (string)TP->query_name() == "spungold") {
         if(present("kyra")) {
            obj = present("kyra");
            obj->force_me("say Due to your crimes against this city, "+TPQCN+", you are no longer welcome here.");
            return 0;
         }
         write("The guard will not let you pass.");
         return 0;
      }
		if(ALIGN->is_evil(TP)) {
			if(present("kyra")) {
				obj = present("kyra");
				obj->force_me("say Weren't you listening? Evil is not welcome here!");
				return 0;
			}
			write("The guard will not let you pass.");
			return 0;
		}
		else if(member_array(TP->query_name(),KILLING_D->query_evil_bounties()) != -1) {
			if(present("kyra")) {
				obj = present("kyra");
				obj->force_me("say We've heard of you and your evil deeds, "+TPQCN+","+
				" if you don't leave at once I will call the guards to collect that"+
				" bounty.");
				obj->call_out("bounty_collection",12,TP);
				return 0;
			}
			write("The guard will not let you pass.");
			return 0;
		}
		else if(member_array(TP->query_name(),KILLING_D->query_bounties()) != -1) {
			if(present("kyra")) {
				obj = present("kyra");
				obj->force_me("say Law breakers are not welcome here, now leave before"+
				" I call the guards to come arrest you!");
				obj->call_out("bounty_collection",8,TP);
				return 0;
			}
			write("The guard will not let you pass.");
			return 0;
		}
		else if((string)TP->query_diety() == "jarmila") {
			return 1;
		}

		race = TP->query_race();
              if(objectp(shape = TP->query_property("shapeshifted"))) race = (string)shape->query_shape_race();
              if(objectp(shape = TP->query_property("altered"))) race = (string)shape->query_shape_race();

		if(race == "drow" || race == "ogre" || race == "half-ogre" || race == "goblin" || race == "orc" || race == "half-orc" || race ==  "hobgoblin" || race == "ogre-mage" || race == "gnoll" || race == "half-drow" || race == "kobold" || race == "bugbear" || race == "minotaur" || race == "yuan-ti") {
			if(present("kyra")) {
				obj = present("kyra");
				obj->force_me("say Haven't I already told you that "+TP->query_race()+" are not welcome in this city?");
				return 0;
			}
			write("The guard will not let you pass.");
			return 0;
		}
		if(race == "dragon") {
			if(present("kyra")) {
				obj = present("kyra");
				obj->force_me("say I stand by my vows. You may not pass!");
				return 0;
			}
			write("The guard will not let you pass.");
			return 0;
		}
		if(race == "elf" && (string)TP->query("subrace") == "fey'ri" && !TP->query_property("altered")) {
			if(present("kyra")) {
				obj = present("kyra");
				obj->force_me("say Haven't I already told you that "+TP->query_race()+" are not welcome in this city?");
				return 0;
			}
			write("The guard will not let you pass.");
			return 0;
		}
	}
	return 1;
}

void set_dir(string str)
{
	object obj;

	if(!present("kyra")) return;
	obj = present("kyra");
	if(str == "west") {
		obj->set_direction("west");
	}
	else if(str == "east") {
		obj->set_direction("east");
	}
}

void say_goodbye(string str)
{
	object obj;

	if(!present("kyra")) return;
	else {
		obj = present("kyra");
		obj->set_direction("east");
		return;
	}
}
