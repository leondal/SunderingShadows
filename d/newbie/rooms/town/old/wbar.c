#include <std.h>
#include "../../newbie.h"
inherit ROOM;

void create()
{
	::create();
	set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
	set_short("The Dancing Ogre");
	set_long(
	"You are standing in a bar known as the Dancing Ogre, which is on the west side of"+
	" the town. It is a rather lively establishment, and it looks like there's quite a"+
	" crowd in here already. There are still a couple tables empty if you want to sit"+
	" down, as well as a few seats open at the bar. The place looks like it's seen its"+
	" fair share of bar fights, but isn't too much worse off. There is at least an"+
	" attempt to keep the place clean, though the bar patrons don't help. You can see at"+
	" least one man passed out on the floor already.  There is a curtain across"
    " part of the back wall.  A dark stained %^GREEN%^board%^RESET%^"+
    " hangs on the wall near the door and next to it is a %^RED%^"+
    "dartboard%^RESET%^ carved from a thicker and lighter colored "+
    "wood.  You see menu on the wall behind the bar that"+
	" tells you what is served here."
	);
	set_property("light",2);
	set_smell("default","The bar smells heavily of strong drinks and sweaty men.");
	set_listen("default","You can hear the bar patrons slurring their words.");
	set_items(([
	({"chairs","tables"}) : "Chairs and tables are scattered about the room. Most of them"+
	" are occupied, but a few in the back are available.",
	({"bar","stools"}) : "There is a large bar on the east side, stretching almost the"+
	" entire length of the room. Tall bar stools are set up at intervals along it, and"+
	" there are a few empty ones.",
	({"man","drunk"}) : "There is a man passed out on the floor of the bar. No one really"+
	" seems to be paying him any attention, the waitresses are even stepping over him."+
	" That's what can happen if you drink too much.",
	"menu" : "There is a menu on the bar. You can read it to find out what is served here.",
   ({"curtain", "back wall"}) : "There doesn't seem to be a window to warrant a "
   "curtain there.  Maybe it conceals another room.",
   ({"board","dark stained board","stained board"}) : "This board "+
   "appears to be a hastily written list or exclaimation of something.",
	]));
	set_exits(([
	"west" : MAINTOWN"wstreet4",
	"south" : MAINTOWN"wroad2",
	"curtain" : MAINTOWN"fencer",
	]));
	set_invis_exits( ({"curtain"}) );
}

void init()
{
	::init();
	add_action("read_menu","read");
}

void reset()
{
    object ob;
	::reset();
	if(!present("barkeep")) {
		new(MON"barkeep2")->move(TO);
	}
    if(!present("dartboard")) {
        ob = new("/d/common/obj/misc/dart_board");
        ob->set_mastery_list("dancing_ogre_bar");
        ob->move(TO);
    }
}

int read_menu(string str)
{
	object obj;
	int i, x;
    string *names;

	obj = present("barkeep");

    if((str == "board" || str == "dark board" || str == "stained board") 
    && obj = present("dartboard")) {
        write("If ya master the game of darts here, sign yer name!");
        names = obj->query_mastery_list();
        if(!sizeof(names)) {
            tell_object(TP,"There are currently no names written down.");
            return 1;
        }
        for(x = 0;x < sizeof(names);x++) {
            tell_object(TP,"["+(x+1)+"] %^RED%^"+names[x]+"%^RESET%^\n");
        }
        return 1;
    } 

	if(str == "menu" && !present("barkeep")) {
		write("The menu is covered in the barkeepers blood and can't be read!");
		return 1;
	}
	if(str == "menu") {
		say(""+TPQCN+" reads over the menu.");
		message("Ninfo","You look over the menu on the bar, it reads:\n",TP);
		message("Ninfo","%^BOLD%^%^MAGENTA%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~%^YELLOW%^\n",TP);
		message("Ninfo","%^YELLOW%^\tWater \t\t"+
		"  "+(int)obj->get_price("water")+" silver pieces\n",TP);
		message("Ninfo","%^YELLOW%^\tTea \t\t"+
		"  "+(int)obj->get_price("tea")+" silver pieces\n",TP);
		message("Ninfo","%^YELLOW%^\tSoda \t\t"+
		"  "+(int)obj->get_price("soda")+" silver pieces\n",TP);
		message("Ninfo","%^YELLOW%^\tMulled Wine \t"+
		"  "+(int)obj->get_price("mulled wine")+" silver pieces\n",TP);
		message("Ninfo","%^YELLOW%^\tSpiced Wine \t"+
		" "+(int)obj->get_price("spiced wine")+" silver pieces\n",TP);
		message("Ninfo","%^YELLOW%^\tAle \t\t"+
		"  "+(int)obj->get_price("ale")+" silver pieces\n",TP);
		message("Ninfo","%^YELLOW%^\tBread \t\t"+
		"  "+(int)obj->get_price("bread")+" silver pieces\n",TP);
		message("Ninfo","%^YELLOW%^\tStew \t\t"+
		"  "+(int)obj->get_price("stew")+" silver pieces\n",TP);
		message("Ninfo","%^YELLOW%^\tPork Chops \t"+
		"  "+(int)obj->get_price("pork chops")+" silver pieces\n",TP);
		message("Ninfo","%^YELLOW%^\tRibs \t\t"+
		"  "+(int)obj->get_price("ribs")+" silver pieces\n",TP);
		message("Ninfo","%^YELLOW%^\tPot Roast \t"+
		" "+(int)obj->get_price("pot roast")+" silver pieces\n",TP);
		message("Ninfo","%^YELLOW%^\tPeach Cobbler \t"+
		"  "+(int)obj->get_price("peach cobbler")+" silver pieces\n",TP);
		message("Ninfo","%^BOLD%^%^MAGENTA%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~%^RESET%^\n",TP);
		message("Ninfo","<buy dish_name> gets you the item.\n",TP);
		return 1;
	}
}
