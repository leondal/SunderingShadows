#include <std.h>
inherit ROOM;
void init() {
    ::init();
    add_action("touch_func","touch");
}
void create() {
    ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^BLUE%^City street%^RESET%^");
    set_long(
        "%^BLUE%^The city street is made of %^MAGENTA%^cobblestones "
	"%^BLUE%^winding through "
        "the existing structures around you. The wind blows back your "
        "hair as you wander through the city pathways."
        " The city presses up against the northwestern edges of the lake "
        "here. To the north and to the west the lake prevents further "
        "travel. To the south is the %^RESET%^chain link fence%^BLUE%^ "
	"which "
        "leads across a bridge and into the cavern wall. The chain link "
        "fence is more of a tunnel than a compound at this point and "
        "likely is used to transport "
        "slaves from the compound into the slave mines.%^RESET%^"
        "\n%^YELLOW%^%^BOLD%^A large %^BLUE%^black "
        "pillar%^YELLOW%^ stands before you.%^RESET%^"
    );
    set_listen("default",
        "The pillar seems to emenate a clicking sound."
    );
    set_smell("default",
        "The smell of death and decay surrounds you."
    );
    set_items(([
        "cobblestone":"There are numerous cobblestones lining the city "
        "pathways.",
        "cobblestones":"The city pathway is made up of various colored "
        "cobblestones which must have been mined in the caverns near here.",
        "fence":"The fence has no means to get in or out from it.",
        "cavern":"The opening in the cavern wall leads to the slave mines.",
        "bridge":"The chain link tunnel leads across a bridge to the cavern "
        "opening.",
        "pillar":"%^GREEN%^The pillar stands 10 feet high and is perfectly "
        "smooth and round. It appears to have no function but it is warm "
        "to touch and is covered in strange runes.%^RESET%^",
        "runes":"%^RED%^The blazing %^BOLD%^red runes%^RESET%^%^RED%^ "
        "are undecipherable and have no apparent use.",
        "lake":"The lake is deep, dark and black and there is no way in "
        "hell your jumping in there!",
        "street":"The street is made up of cobblestones and winds through "
        "the buildings.",
        "pathway":"The pathway winds through the city and is made up of "
        "cobblestones.",
        "buildings":"There are buildings lining the city streets."
    ]));
    set_exits(([
        "east":"/d/dagger/drow/rooms/city29"
    ]));
/*
Removed after talking to Styx, decided he would be better on Danger. 6/7/05
    new("/d/dagger/drow/mon/shadow")->move(this_object());
*/
}
int touch_func(string str) {
    if(!str) {
	notify_fail("Touch what?\n");
	return 0;
    }
    if(str != "runes") {
	notify_fail("Touch what?\n");
	return 0;
    }
    if(!present("mask",TP)) {
	write(
	    "%^RED%^You touch the runes and feel a slight vibration "
	    "within the pillar.%^RESET%^"
	);
	say(
	    "%^RED%^"+TPQCN+" touches the runes.%^RESET%^"
	,TP);
        return 1;
    } else {
	write(
	    "%^RED%^You touch the runes and feel the mask tremble!\n"
	    "%^BLUE%^Suddenly you appear elsewhere!%^RESET%^"
	);
	say("%^RED%^"
	    +TPQCN+
	    " touches the pillar and slowly disintegrates!\n"
	    "%^BOLD%^%^GREEN%^Death has taken "+TPQCN+" from our "
	    "midst!%^RESET%^"
	,TP);
	TP->move_player("/d/tharis/barrow/rooms/pit");
	return 1;
    }
}
void clean_up(){return 1;}
