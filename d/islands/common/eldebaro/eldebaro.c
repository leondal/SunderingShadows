#include <std.h>
#include "eldebaro.h"

inherit ROOM;

string base_long();

void create()
{
    ::create();
	set_property("light",2);
	set_property("indoors",0);

    set_terrain(BEACH);
	set_travel(FRESH_BLAZE);
   
    set_short("A desert island");

    set_long( (: TO,"base_long" :) );

    set_listen("default", "%^CYAN%^The gently slapping of water echoes all around you "
        "here, as the whirling of sand begins to increase in ferocity.%^RESET%^");
    set_smell("default", "%^YELLOW%^A tranquil odor from the sea assaults you and mixes "
        "with something much fouler.%^RESET%^\n");

    set_exits(([
        "north" : "/d/shadow/virtual/sea/eldebaro.dock",
        "east"  : "/d/shadow/virtual/sea/eldebaro.dock",
        "south" : "/d/shadow/virtual/sea/eldebaro.dock",
        "west"  : "/d/shadow/virtual/sea/eldebaro.dock",
    ]));

    return;
}

void init() 
{
    ::init();

    if(!objectp(TP) || TP->query_true_invis()) { return; }

    do_random_encounters(({ "/d/islands/common/mon/lostsoul.c", 
                            "/d/islands/common/mon/scorpion.c", 
                            "/d/islands/common/mon/crab.c", 
                            "/d/islands/common/mon/drowned.c", 
                            "/d/islands/common/mon/earwig.c"}),random(50),roll_dice(1,4));
    return;
}

string base_long()
{
    string str,extra,room;

    str = "\n%^ORANGE%^A dry arid desert stretches out before you.  This tiny island is not "
          "much more than a spot of sand in the middle of a vast blue ocean.  A few sparse palm "
          "trees dot the sandy landscape.%^RESET%^\n%^YELLOW%^Your footprints are covered by "
          "the winds behind you.\n%^RESET%^";

    if(!objectp(TO)) { return str; }

    room  = base_name(TO);
    room  = replace_string(room,ROOMS"room","");
    extra = "";

    switch(room)
    {
    case "22": case "19": case "4": // north rooms

        extra = "\n%^BOLD%^%^BLUE%^The ocean meets the land to the north.\n";
        break;

    case "37": case "34": case "17": // east rooms

        extra = "\n%^BOLD%^%^BLUE%^The ocean meets the land to the east.\n";
        break;

    case "21": case "6": //south rooms

        extra = "\n%^BOLD%^%^BLUE%^The ocean meets the land to the south.\n";
        break;

    case "28": case "11": case "2": //west rooms

        extra = "\n%^BOLD%^%^BLUE%^The ocean meets the land to the west.\n";
        break;

    case "36": case "30": case "13": // northeast rooms

        extra = "\n%^BOLD%^%^BLUE%^The ocean meets the land to the north and east.\n";
        break;

    case "35": case "18": case "38": // southeast rooms

        extra = "\n%^BOLD%^%^BLUE%^The ocean meets the land to the south and east.\n";
        break;

    case "29": case "12": case "3": //southwest rooms

        extra = "\n%^BOLD%^%^BLUE%^The ocean meets the land to the south and west.\n";
        break;

    case "24": case "7": case "1": //northwest rooms

        extra = "\n%^BOLD%^%^BLUE%^The ocean meets the land to the north and west.\n";
        break;
    }

    if(strlen(extra)) { str = str + extra; }

    return str;
}


