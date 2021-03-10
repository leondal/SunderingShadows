#include <std.h>
#include "../antioch.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
	set_property("indoors",1);
	set_property("light",2);
	set_short("%^YELLOW%^Eagle's Roost");
	set_long(
	"The tavern is rather dimly lit by oil lamps that line the room."+
	" There are several tables scattered about, some of them are"+
	" occupied, but all are fairly clean. The floor looks as though"+
	" it has actually been swept recently, and perhaps even mopped."+
	" There is a large cedar bar that covers the back end of the"+
	" room. Behind the bar are several kegs and bottles of different"+
	" types of wine and alcohol. Stools are lined up in front of the"+
	" bar and appear to be bolted to the floor. On the back wall"+
	" behind the bar a menu is posted for everyone to read. A dart"+
    " board hangs tightly on the back wall of the bar, and a list"+
    " of those reknown for their skill been posted near the"+
    " entrance.");
	set_smell("default","The smells of beer and wine mingle together.");
	if(query_night() == 1) {
		set_listen("default","Drunken laughter fills the room.");
	}
	else {
		set_listen("default","The customers are fairly quiet and well"+
		" behaved right now.");
	}
	set_items(([
	({"lamp","lamps","oil lamp","oil lamps"}) : "Oil lamps are nailed"+
	" to the walls and are lit to keep the place dimly lit.",
	"floor" : "The floor is fairly clean, it looks as though it has"+
	" been swept and even mopped recently.",
	({"stool","stools"}) : "Stools are carefully spaced out and"+
	" lined up in front of the bar. They have been bolted to the"+
	" floor, probably to prevent drunken customers from throwing them.",
	({"table","tables"}) : "There are several tables scattered about"+
	" the room. Some of them are occupied but there are a couple free.",
	({"chair","chairs"}) : "Wooden chairs are placed around the tables"+
	" for people to sit on.",
	"menu" : "The menu is posted on the back wall behind the bar. You"+
	" can read it if you wish.",
	"bar" : "Along the back of the room is a large cedar bar that is"+
	" kept very clean.",
	({"keg","kegs"}) : "Large kegs, most probably of beer, are stored"+
	" behind the bar.",
	({"wine","wines"}) : "Bottles of various types of wines are"+
	" carefully stored in wine racks behind the bar.",
	({"racks","rack","wine rack","wine racks"}) : "Wooden wine racks"+
	" are kept next to the kegs behind the bar. They are built"+
	" specifically for wine bottles so that they do not break or get"+
	" knocked over.",
	"ceiling" : "Shadows flicker on the ceiling from the oil lamps.",
	]));
	set_exits(([
	"east" : ROOMS+"street24",
	]));
   
}

void reset()
{
    object ob;
	::reset();
    if(!present("dartboard")) {
        ob = new("/d/common/obj/misc/dart_board");
        ob->set_mastery_list("eagles_roost_bar");
        ob->move(TO);
    }
	if(!present("barkeep")) {
		new(MONS+"barkeep")->move(TO);
	}
}

void init()
{
	::init();
	add_action("read","read");
}

int read(string str)
{
	object obj;
	int i;
    string *names;

	obj = present("barkeep");

    if(str == "list" && obj = present("dartboard")) {
        names = obj->query_mastery_list();
        write("The following individuals are recognized as having "+
        "mastered the game of darts.");
        for(i = 0;i < sizeof(names);i++) {
            tell_object(TP,"%^YELLOW%^"+names[i]+"%^RESET%^\n");
        }
        return 1;
    }
	if(!present("barkeep")) {
		write("The menu is smeared with the blood of the bartender!");
		return 1;
	}
	if(str == "menu") {
		say(""+TP->query_cap_name()+" reads over the menu.");
		message("Ninfo","The menu is posted on the back wall and it"+
		" lists these drinks:\n"+
		"%^YELLOW%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~%^RESET%^\n",TP);
		message("Ninfo","\t%^MAGENTA%^Raspberry Tea%^RESET%^	\t\t"+
		" "+(int)obj->get_price("raspberry tea")+" silver pieces\n",TP);
		message("Ninfo","\t%^YELLOW%^Lemonade%^RESET%^ \t\t\t"+
		" "+(int)obj->get_price("lemonade")+" silver pieces\n",TP);
		message("Ninfo","\t%^BOLD%^%^BLACK%^Chocolate Malt%^RESET%^ \t\t\t"+
		""+(int)obj->get_price("chocolate malt")+" silver pieces\n",TP);
		message("Ninfo","\t%^BOLD%^%^BLUE%^Blue Velvet%^RESET%^ \t\t\t"+
		""+(int)obj->get_price("blue velvet")+" silver pieces\n",TP);
		message("Ninfo","\t%^BOLD%^%^GREEN%^Grasshopper%^RESET%^ \t\t\t"+
		""+(int)obj->get_price("grasshopper")+" silver pieces\n",TP);
		message("Ninfo","\t%^RED%^Blackberry Wine%^RESET%^ \t\t"+
		""+(int)obj->get_price("blackberry wine")+" silver pieces\n",TP);
		message("Ninfo","\t%^ORANGE%^Pale Ale%^RESET%^ \t\t\t"+
		" "+(int)obj->get_price("pale ale")+" silver pieces\n",TP);
		message("Ninfo","\t%^BOLD%^Shot of gin%^RESET%^ \t\t\t"+
		""+(int)obj->get_price("shot of gin")+" silver pieces\n",TP);
		message("Ninfo","%^YELLOW%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~"+
		"*~*~*~*~*~*~*~*~*~*~*~*~%^RESET%^\n",TP);
		message("Ninfo","<buy drink_name> gets you a drink.\n",TP);
		return 1;
	}
}

