#include <std.h>
#include "../juran.h"
inherit ROOM;

void create(){
	::create();
	set_property("indoors",1);
    	set_terrain(STONE_BUILDING);
    	set_travel(PAVED_ROAD);
	set_short("The Cut Throat");
	set_long(
		"%^MAGENTA%^You are in a seedy little restaurant %^BOLD%^%^BLACK%^b%^BLACK%^a%^BLACK%^r%^RESET%^%^MAGENTA%^ called the %^BOLD%^%^MAGENTA%^Cut %^MAGENTA%^Th%^RESET%^%^MAGENTA%^r%^BOLD%^%^MAGENTA%^oa%^RESET%^%^MAGENTA%^t%^BOLD%^%^MAGENTA%^.%^RESET%^%^MAGENTA%^ The %^BOLD%^%^ORANGE%^t%^ORANGE%^a%^RESET%^%^ORANGE%^ble%^MAGENTA%^ tops have not been washed thoroughly in some time and the chairs are all over the place some broken, some still serviceable. The room is dimly lit which is probably a good thing since the lighting helps the quality of the food and drink. There is a bar against the north wall with more than a few bar %^BOLD%^%^MAGENTA%^st%^RESET%^%^MAGENTA%^o%^BOLD%^%^MAGENTA%^o%^RESET%^%^MAGENTA%^l%^BOLD%^%^MAGENTA%^s%^RESET%^%^MAGENTA%^ still unbroken against it. In the south a %^BOLD%^%^MAGENTA%^curta%^RESET%^%^MAGENTA%^i%^MAGENTA%^n%^MAGENTA%^ hangs over a section of the wall."
	);
	set_property("light",-2);
	set_smell("default","The bar smells heavily of strong drinks and sweaty men.");
	set_listen("default","You can hear the bar patrons slurring their words.");
	set_items(([
		({"chairs","tables"}) : "Chairs and tables are scattered about "+
			"the room. Most of them are occupied, but a few in the back "+
			"are available and some are broken.",
		({"bar","stools"}) : "There is a large bar on the east side, stretching "+
			"almost the entire length of the room. Tall bar stools are set up "+
			"at intervals along it, and there are a few empty ones.",
		({"man","drunk"}) : "There is an orc passed out, or dead, on the floor "+
			"of the bar. No one really seems to be paying him any "+
			"attention, the waitresses are even stepping over him.  The "+
			"fact no one is paying him any attention means that he has "+
			"nothing left of value on him.  That's what can happen if you "+
			"drink too much.",
		"curtain" : "Unseen breezes move this curtain from time to time.",
		"menu" : "There is a menu on the bar. You can read it to find out what "+
			"is served here."
	]));
	set_exits(([
		"northeast" : JROOMS+"r25",
		"curtain" : JROOMS+"jhit_board",
/*
		"down" : JROOMS+"inn_cellar"
*/
	]));
/*
    	set_invis_exits( ({"down"}) );
    	set_pre_exit_functions(({"down"}),({"allow"}));
*/
}
void reset(){
	::reset();
	if(!present("barmaid"))find_object_or_load(JMONS+"barkeep3")->move(TO);
}
void init() {
  	::init();
	add_action("read_menu","read");
}
int read_menu(string str){
	object obj;
	int i;

	obj = present("barmaid");

	if(str == "menu" && !present("barmaid")) {
		write("The menu is covered in the barkeepers blood and can't be read!");
		return 1;
	}
	if(str == "menu") {
		say(""+TPQCN+" reads over the menu.");
		message("Ninfo","You look over the menu on the bar, it reads:\n",TP);
		message("Ninfo","%^BOLD%^%^MAGENTA%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~%^YELLOW%^\n",TP);
		message("Ninfo","%^YELLOW%^  Muddy Water \t\t"+
		"  "+(int)obj->get_price("muddy water")+"  electrum pieces\n",TP);
		message("Ninfo","%^YELLOW%^  Clean Water \t\t"+
		"  "+(int)obj->get_price("clean water")+" electrum pieces\n",TP);
		message("Ninfo","%^YELLOW%^  Sulfur Fizz \t\t"+
		"  "+(int)obj->get_price("sulfur fizz")+" electrum pieces\n",TP);
		message("Ninfo","%^YELLOW%^  Grin Burn \t\t"+
		"  "+(int)obj->get_price("grin burn")+" electrum pieces\n",TP);
		message("Ninfo","%^YELLOW%^  Blood Wine \t\t"+
		"  "+(int)obj->get_price("blood wine")+" electrum pieces\n",TP);
            message("Ninfo","%^YELLOW%^  Orcish Swill \t\t"+
		"  "+(int)obj->get_price("orcish swill")+" electrum pieces\n",TP);
		message("Ninfo","%^YELLOW%^  Bread \t\t"+
		"  "+(int)obj->get_price("bread")+" electrum pieces\n",TP);
		message("Ninfo","%^YELLOW%^  Halfling Stew \t"+
		"  "+(int)obj->get_price("halfling stew")+" electrum pieces\n",TP);
		message("Ninfo","%^YELLOW%^  Dwarf Kabobs \t\t"+
		"  "+(int)obj->get_price("dwarf kabobs")+" electrum pieces\n",TP);
		message("Ninfo","%^YELLOW%^  Elf Ribs \t\t"+
		"  "+(int)obj->get_price("elf ribs")+" electrum pieces\n",TP);
		message("Ninfo","%^YELLOW%^  Rat Roast \t\t"+
		"  "+(int)obj->get_price("rat roast")+" electrum pieces\n",TP);
		message("Ninfo","%^YELLOW%^  Chocolate Sprite Legs\t"+
		"  "+(int)obj->get_price("sprite legs")+" electrum pieces\n",TP);
		message("Ninfo","%^YELLOW%^  Shroom Salad\t\t"+
		"  "+(int)obj->get_price("shroom salad")+" electrum pieces\n",TP);
		message("Ninfo","%^YELLOW%^  Fried Lizard Legs\t"+
		"  "+(int)obj->get_price("fried lizard legs")+" electrum pieces\n",TP);
		message("Ninfo","%^YELLOW%^  Glowfish Taco\t\t"+
		"  "+(int)obj->get_price("glowfish taco")+" electrum pieces\n",TP);
		message("Ninfo","%^YELLOW%^  Dark Steak\t\t"+
		"  "+(int)obj->get_price("dark steak")+" electrum pieces\n",TP);
		message("Ninfo","%^BOLD%^%^MAGENTA%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~%^RESET%^\n",TP);
		message("Ninfo","<buy dish_name> gets you the item.\n",TP);
		return 1;
	}
}
int allow(){
	object obj;
	string mname;


	obj = present("barmaid");
	mname = obj->query_name();

    	if(mname == "Sherilinn" && avatarp(TP)){
    		tell_room(ETP,"Sherilinn disappears behind the counter.", TP);
    		return 1;
    	}else return 0;
}
