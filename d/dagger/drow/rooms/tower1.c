// made a little more syntax friendly with Akadi's help and added searches *Styx* 5/26/06

#include <std.h>
#include "/d/dagger/drow/short.h"
inherit ROOM;
void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(STAIRWAY);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^YELLOW%^Inside the bone tower%^RESET%^");
    set_long(
	"%^YELLOW%^You stand within the %^WHITE%^bone %^YELLOW%^tower. "
   "The chamber at its base is circular and about twenty feet "
	"in diameter. The walls are made from %^WHITE%^bones and "
	"skulls%^YELLOW%^. The room is bathed in an eerie %^MAGENTA%^"
	"glowing light%^YELLOW%^. The %^WHITE%^skulls and bones%^YELLOW%^ "
	"seem to be well polished and reflect strange light patterns in "
        "the air. Directly in the center of the room stands a %^RED%^caern "
	"%^YELLOW%^made of %^WHITE%^many skulls%^YELLOW%^.%^RESET%^"
    );
    set_listen("default",
	"The skulls seem to sing out to you!"
    );
    set_smell("default",
	"The smell of sulphur fills the air."
    );
    set_items(([
	"bones and skulls":"The walls are made of many bones and skulls. "
	   "The bones and skulls gleam in the eerie light.",
	"bones":"The bones gleam in the eerie light within the chamber.",
	({"skulls", "skull", "skull 1" }):"%^BOLD%^%^BLACK%^There are many "
	   "skulls, from many different races.  They seem to sing out in a "
	   "cry of sorrow.  Those on the caern draw your attention.%^RESET%^",
	"skull 2":"%^BOLD%^%^BLACK%^The skull looks you over and grins "
	   "evilly.%^RESET%^",
	"caern":"%^RED%^The caern is about two feet high and seems to be made "
	   "mostly from %^WHITE%^elven skulls%^RED%^.",
	"light":"%^MAGENTA%^The chamber is bathed in an eerie light. There "
	   "is no apparent source to explain this light.%^RESET%^",
	({"elven skull", "skull 3" }):"%^RED%^The elven skull looks at you and "
	   "speaks!\n%^YELLOW%^The skull says: Touch the caern for passage.",
	"elven skulls" : "The skulls are mostly elven and you are drawn to "
	   "taking a closer look at some of them.",
	({"drow skulls", "drow skull" }) : "Are you really surprised that "
	   "There aren't any drow skulls?",
    ]));
    set_search("default", "There are several skulls and you feel compelled "
	"to look closer at some of them.");
    set_search("caern", "An elven skull seeems to draw your attention.");
    set_exits(([
    	"out": RPATH "city42"
    ]));
}

void init() {
    ::init();
    add_action("touch_caern","touch");
}
int touch_caern(string str) {
    if(str !="caern") {
        notify_fail("Touch what?");
    return 0;
    }
    message("my_action",
	"%^YELLOW%^You touch the caern and slowly float through the roof "
	"of the chamber!%^RESET%^"
    ,TP);
    message("other_action",
	"%^YELLOW%^"+TPQCN+" touches the caern and floats up through the "
	"ceiling of the chamber!%^RESET%^"
    ,environment(TP),TP);
    TP->move_player( RPATH "tower2");
    return 1;
}
