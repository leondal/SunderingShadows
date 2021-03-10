#include <std.h>
#include "/d/shadow/room/goblin/short.h"

inherit ROOM;
int FLAG;
#define PLACE1 "/d/darkwood/tabor/road/road1";
#define PLACE2 "/d/darkwood/tabor/road/road1";
#define PLACE3 "/d/darkwood/tabor/road/road2";
#define PLACE5 "/d/darkwood/tabor/road/road3";

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(DIRT_ROAD);
    set_indoors(1);
    set_property("no castle", 1);
    set_property("light", 2);
    set_short("%^BLUE%^Goblin King's chamber%^RESET%^");
    set_long( "%^BLUE%^"
        "The chamber here is a large goblin throne room. A %^RED%^"
	"throne%^BLUE%^ made "
	"of %^RESET%^skulls%^BLUE%^ "
	"sits in the center of the chamber. On the wall to the "
	"north is a %^MAGENTA%^large banner%^BLUE%^"
	". Behind the %^MAGENTA%^banner%^BLUE%^ "
	"sits a %^ORANGE%^large bronze "
	"gong%^BLUE%^. There are openings leading east and west from here. The openings "
	"are covered by %^GREEN%^curtains%^BLUE%^."
        "%^RESET%^"
    );
    set_smell("default","It smells of dirty goblins.");
    set_listen("default","You hear the occasional goblin shouting somewhere in "
	"the stronghold.");
    set_items(([
        "torches":"The flickering torches provide some light.",
        "walls":"The walls are made of stone.",
	"banner":"The banner bears the symbol of the Goblin army of Chaos.",
	"throne":"The throne is a chair crafted out of skulls.",
	"gong":"The gong is a large bronze disc held by wooden poles. It glows with "
	"an eerie light.",
	"curtains":"The curtains cover the openings to the east and the west.",
	"openings":"Two openings are located on the east and west walls."
    ]));
    set_exits(([
        "south": RPATH "inner5",
    "north": RPATH "inner10",
	"west": RPATH "inner7",
	"east": RPATH "inner9",
    ]));
    set_invis_exits(({"north"}));
}

void reset() {
    ::reset();
    FLAG = 0;
    if(!random(2))
    if(!present("goblin")) {
      new( MPATH "royal.c" )->move(TO);
      new( MPATH "royal.c" )->move(TO);
      new( MPATH "king.c" )->move(TO);
      if(!random(3))
        new( MPATH "royal.c" )->move(TO);
      if(!random(5))
        new( MPATH "royal.c" )->move(TO);
    }
}

void init() {
    ::init();
    add_action("strike","strike");
}

int strike(string str) {
    object ob1,ob2,ob3,ob4,ob5;
    if(!str) {
	notify_fail("Strike what?\n");
	return 0;
    }
    if(str != "gong") {
	notify_fail("Strike what?\n");
	return 0;
    }
   if(present("goblin")) {
	notify_fail("The goblin will not let you touch the gong!\n");
	return 0;
    }
    if(FLAG == 1) {
	notify_fail("You strike the gong with a dull thud.");
	return 0;
    }
    if(!present("sceptre",TP)) {
	notify_fail("You strike the gong with a dull thud.");
	return 0;
    }
    write("%^ORANGE%^"
	"You strike the gong with a solid blow from your sceptre.\n"
	"%^YELLOW%^The gong rings out and flashes briefly with a "
	"%^RED%^red%^YELLOW%^ glow.%^RESET%^"
    );
    say("%^ORANGE%^"
	+TPQCN+" strikes the gong with a solid blow from "
	+TP->query_possessive()+
	" sceptre.\n"
	"%^YELLOW%^The gong rings out and flashes briefly with a "
	"%^RED%^red%^YELLOW%^ glow.%^RESET%^"
    ,TP);

    // Suggestion, add invasion in the observable world;
    return 1;
    message("invasion",
	"%^BOLD%^%^GREEN%^A strange gong rings out across the lands.\n"
	"%^ORANGE%^Goblin "
	"raiders have received orders to depart for invasion!"
	"%^RESET%^"
    ,users());
    ob1 = PLACE1;
    new( MPATH "raider.c")->move(ob1);
    ob2 = PLACE2;
    new( MPATH "raider.c")->move(ob2);
    ob3 = PLACE3;
    if(!random(2))
      new( MPATH "raider.c")->move(ob3);
    ob5 = PLACE5;
    new( MPATH "raider.c")->move(ob5);
    FLAG = 1;

    ob1 = new("/d/common/obj/special/alt_world_creator.c");

    ob1->alt_world_perimeters(
    (["alt world borders" : ({"/d/darkwood/tabor/road/road4", "/d/shadow/virtual/river/tabor.dock", "/d/shadow/room/forest/road58", "/d/koenig/streams/path18"}),
    "alt world monsters" : (["/d/shadow/room/goblin/mon/archer.c" : 1 + random(2),
    "/d/shadow/room/goblin/mon/soldier.c" : 1 + random(2),
    "/d/shadow/room/goblin/mon/raider.c" : 1 + random(2),
    "/d/shadow/room/goblin/mon/footman.c" : 1 + random(2),]),
    "alt world monster chance" : 20 + random(20),
    "alt allow normal monsters" : 1,
    "alt world ends at" : 3600,
    "start room" : "/d/darkwood/tabor/room/math1", "low level" : 6, "high level" : 12,
    "invite msg" : "%^BOLD%^%^WHITE%^You are invited to participate in a Phased event, "+
    "'%^BOLD%^%^BLACK%^Goblin Invasion of Tabor%^BOLD%^%^WHITE%^'. You will be in an alternative version of "+
    "Tabor that is being over run by %^BOLD%^%^RED%^Goblins%^BOLD%^%^WHITE%^. Only other online users who are "+
    "an appropriate level will be inside the world with you. There will be borders which you cannot move beyond. "+
    "This particular event will last for approximately one real life hour. If you die within the event if "+
    "there is no one inside who can ressurect you, then you will be out of it. Can you live to tell the tale?\n\n"+
    "If you wish to participate then simply "+
    "type '%^BOLD%^%^CYAN%^yes%^BOLD%^%^WHITE%^' or '%^BOLD%^%^CYAN%^y%^BOLD%^%^WHITE%^'. If you do not wish to participate "+
    "you may type '%^BOLD%^%^CYAN%^no%^BOLD%^%^WHITE%^' or '%^BOLD%^%^CYAN%^n%^BOLD%^%^WHITE%^'. You have approximately "+
    "four minutes to accept this invitation. After all players have responded the event will start and you will be moved into the alternative "+
    "version of Tabor.%^RESET%^", "accept msg" : "%^BOLD%^%^WHITE%^You have accepted the invitation for the phased event '%^BOLD%^%^BLACK%^"+
    "Goblin Invasion of Tabor%^BOLD%^%^WHITE%^'. The event will start momentarily.%^RESET%^", "decline msg" : "%^BOLD%^%^WHITE%^"+
    "You have declined the invitation for the phased event '%^BOLD%^%^BLACK%^Goblin Invasion of Tabor%^BOLD%^%^WHITE%^'.%^RESET%^",
    "start msg" : "%^BOLD%^%^CYAN%^The timed phased event '%^BOLD%^%^BLACK%^Goblin Invasion of Tabor%^BOLD%^%^CYAN%^' "+
    "is now starting! You are now within a version of Tabor that is being over-run by goblins... do you have "+
    "what it takes to survive? Or will you be slaughted and left to rot?%^RESET%^"]));

    ob1->alt_world("tabor invasion");
    return 1;
}
