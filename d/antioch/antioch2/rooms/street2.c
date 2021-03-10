#include <std.h>
#include <daemons.h>
#include "../antioch.h"
inherit CVAULT;

void create()
{
   object ob;
        set_monsters( ({ "/d/antioch/antioch2/mons/patrol_guard", }), ({ roll_dice(1, 4) + 1, }), );
	::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
	set_property("indoors",0);
	set_property("light",2);
	set_short("A cobbled street");
	set_long(
            "%^WHITE%^You are at the intersection of %^BOLD%^%^GREEN%^P%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^n%^RESET%^%^GREEN%^e%^WHITE%^ and %^ORANGE%^C%^BOLD%^%^ORANGE%^r%^RESET%^%^ORANGE%^esce%^BOLD%^%^ORANGE%^n%^RESET%^%^ORANGE%^t. %^GREEN%^%^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ %^GREEN%^s%^BOLD%^%^GREEN%^t%^RESET%^%^GREEN%^reet%^WHITE%^ runs up to the northwest and you can see at least one shop along it. %^BOLD%^%^ORANGE%^C%^RESET%^%^ORANGE%^re%^BOLD%^%^ORANGE%^s%^RESET%^%^ORANGE%^c%^BOLD%^%^ORANGE%^e%^RESET%^%^ORANGE%^n%^BOLD%^%^ORANGE%^t%^RESET%^ %^ORANGE%^street%^WHITE%^ runs to the northeast and there is also a shop in that direction. Immediately to the west appears to be a Healer, there is a %^ORANGE%^sig%^BOLD%^%^ORANGE%^n%^RESET%^%^WHITE%^ with the Healer's symbol engraved on it hanging outside the door. To the east is the entrance to the guard %^BOLD%^%^BLACK%^t%^BLACK%^o%^BLACK%^w%^BLACK%^er%^RESET%^%^WHITE%^ and you can hear the guards talkingand laughing inside."
	);
	set_smell("default","You smell a light scent of herbs mingled"+
	" with the guards' sweat.");
	set_listen("default","You hear the chatter of guards.");
	set_items(([
	"sign" : "There is a wooden sign here with the symbol of"+
	" a Healer engraved on it. It hangs in front of little hut"+
	" on the west.",
	({"street","cobblestones","cobbles","road","path"}) : "The"+
	" street is paved with cobblestones.",
	({"tower","guard tower"}) : "This is a great stone guard"+
	" tower.",
	"street sign" : "You are at the intersection of %^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ and"+
	" %^BOLD%^%^ORANGE%^C%^RESET%^%^ORANGE%^re%^BOLD%^%^ORANGE%^s%^RESET%^%^ORANGE%^c%^BOLD%^%^ORANGE%^e%^RESET%^%^ORANGE%^n%^BOLD%^%^ORANGE%^t%^RESET%^ %^ORANGE%^street%^WHITE%^. %^BOLD%^%^BLACK%^P%^RESET%^%^GREEN%^ine %^GREEN%^str%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^t%^RESET%^ runs along the northwest and %^ORANGE%^Crescent%^RESET%^"+
	" runs up to the northeast.",
	]));
	set_exits(([
	"south" : ROOMS+"street1",
	"west" : ROOMS+"healer",
	"east" : ROOMS+"gtower",
	"northwest" : ROOMS+"street3",
	"northeast" : ROOMS+"street17",
	]));
   ob = new("std/bboard");
   ob->set_name("board");
   ob->set_id(({"board","bulletin board","antioch board","Antioch board"}));
   ob->set_board_id("union_board");
   ob->set_short("Arcane Bulletin Board");
   ob->set_long("This is a large board where people can discuss relevant issues about the town.");
   ob->set_max_posts(30);
   ob->set_queue(1);
   ob->set_location(ROOMS+"street2");
}

void reset() {
	::reset();
	if(!present("street_light")) new(OBJ+"street_light")->move(TO);
	if(query_night() == 1) return;
	else if(!present("citizen")) {
             switch(random(4)) {
			case 0:
				new(MONS+"citizen1")->move(TO);
				break;
			case 1:
				new(MONS+"citizen2")->move(TO);
				break;
			case 2:
				new(MONS+"citizen3")->move(TO);
				break;
			case 3:
				new(MONS+"citizen4")->move(TO);
				break;
		}
	}
}

void init() {
   ::init();
}
