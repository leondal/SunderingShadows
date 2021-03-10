#include <std.h>
#include "../defs.h"
inherit ROOM;

void init(){
	::init();
	add_action("buy_map","buy");
	add_action("buy_map","draw");
}

void create() {
    ::create();
    set_property( "light", 2);
    set_property( "indoors", 1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("The Shadow Scribe Service.");
    set_long("%^RESET%^%^CYAN%^You look about you and see an office. "+
"There is a %^ORANGE%^desk%^CYAN%^ with a "+
"chair. On the desk you see %^MAGENTA%^quill%^CYAN%^, "+
"%^RESET%^paper%^CYAN%^, and an %^BOLD%^%^BLACK%^ink well%^RESET%^%^CYAN%^. "+ 
"The walls have shelves on them with books, scrolls, and other "+
"odds and ends. There is a %^BOLD%^sign%^RESET%^%^CYAN%^ "+ 
"on the desk that you may wish to look at.");

    set_smell("default","You smell the odors of pen ink and paper.");
    set_listen("default","You hear the sounds of papers being shuffled.");
    set_exits( ([
      "east" : ROOMS"northcross"
        ]) );
    set_items(([
	"office":"Not a very neat office, but it looks comfortable.",
	"desk":"An oak roll top desk, very rare and well used.",
	"chair":"A wooden, highback chair with cushions nailed onto it.",
	"quill":"A feather quill, for writing.",
	"paper":"A yellowish colored paper, for writing on.",
	"ink":"A jar of black ink, used for writing.",
	"walls":"There are shelves on the walls.",
	"shelves":"There are books and scrolls on the shelves.",
	"books":"They are scattered about the shelves.",
	"scrolls":"They are scattered about the shelves.",
	"drawer":"The drawer has more paper in it.",
    "sign":"%^MAGENTA%^There is a sign written in a flowing script on the desk, it reads:\n\n%^RESET%^"+
	"I can %^YELLOW%^draw%^RESET%^ you a map of Shadow for a small fee. I can also %^YELLOW%^write%^RESET%^ "+
	"for you anything you wish in common, dwarvish, or elven.\n\nTranslating services also available."
	]));
}
  int buy_map(string str){
	int amount;
	amount = 5;
	if(str != "map") return notify_fail("draw what?\n");
    if(!present("scribe")) return notify_fail("Nobody is here to draw you a map.\n");
	if(TP->query_money("gold") < amount)
	return notify_fail("You don't have "+amount+" gold!\n");
	write("The Scribe hands you a map of Shadow.");
        tell_room(ETP,"The Scribe hands "+TPQCN+" a piece of paper.",TP);
	new("/d/shadow/city/obj/citymap")->move(TP);
	return 1;
  }
void reset(){
   ::reset();
   if(!present("scribe")){
     new("/d/shadow/city/mon/scribe.c")->move(TO);
   }
}
