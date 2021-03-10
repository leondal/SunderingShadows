//updated by Circe 9/10/04
//Updated by Chernobog (1/6/21)

#include "/d/dagger/tonovi/town/short.h"
#include <daemons.h>
inherit "/std/rquestroom.c";

void create(){
    object ob;
    ::create();
    set_property("light", 2);
    set_short("Main Street");
    set_long(
        "%^BOLD%^%^GREEN%^Main Street%^RESET%^\n"+
        "You are on the main street through Tonovi.  It runs "+
        "east and west through the heart of the city.  In the "+
        "middle of the city it crosses %^BOLD%^%^BLACK%^Ekan "+
        "Street%^RESET%^, which travels north and south.\n\n"+
        "Here along the street you can see %^BOLD%^shops %^RESET%^"+
        "to the north and south, and the street continues to the "+
        "west and east.  %^ORANGE%^Signs %^RESET%^hangs over each "+
        "of the doors to the north and south."
    );
    set_items(([
        "signs" : "Two buildings have a door opening into "+
            "the street here, and each features a wooden sign you could "+
            "read.",
        ({"north sign","weapon shop sign"}) : ({"The sign on the shop to "+
            "the north is rather plain, being made of simple wood left "+
            "unstained but painted with a message you could read.",
            "%^BOLD%^%^GREEN%^Tonovi Weapon Shop%^RESET%^","common"}),
        ({"south sign","hotel sign"}) : ({"The sign on the building to "+
            "the south is quite ornate.  The wood is painted "+
            "%^BOLD%^%^BLACK%^black %^RESET%^with a %^YELLOW%^golden "+
            "border%^RESET%^.  In the center is a message you could read.",
            "%^YELLOW%^T%^RESET%^%^ORANGE%^h%^BOLD%^e T%^RESET%^%^ORANGE%^o%^BOLD%^"+
            "%^BLACK%^no%^RESET%^%^ORANGE%^v%^BOLD%^i H%^RESET%^%^ORANGE%^o%^BOLD%^"+
            "%^BLACK%^t%^RESET%^%^ORANGE%^e%^BOLD%^l%^RESET%^","common"}),
        ({"walls","wall","stone","stone walls"}) : "%^BOLD%^%^BLACK%^"+
            "Walls made of black stone mined from veins in the northern "+
            "mountains encircle the city.",
        ({"street","ground"}) : "The streets here are made of "+
            "%^BOLD%^%^BLACK%^gray cobblestone%^RESET%^ kept mostly "+
            "clean of refuse, though here and there some recent trash "+
            "has been left by travellers.",
        ({"building","buildings"}) : "The buildings of the city rise "+
            "around you.  There is a mixture of buildings made of "+
            "black, white, and gray stone, as well as the occasional "+
            "wooden building.",
        ({"shops","shop"}) : "There are two shops here.  The one to "+
            "the north is a squat stone building that features a tall "+
            "brick chimney with smoke constantly pouring forth.  To "+
            "the south stands a tall building of beautiful architecture "+
            "that often has people moving in and out.",
        "hotel" : "%^RESET%^%^CYAN%^The hotel stands tall and dignified among the "+
            "surrounding buildings. %^BOLD%^%^BLACK%^Da%^RESET%^r%^BOLD%^%^BLACK%^k "+
            "gr%^RESET%^a%^BOLD%^%^BLACK%^y and b%^RESET%^l%^BOLD%^%^BLACK%^ack st"+
            "%^RESET%^o%^BOLD%^%^BLACK%^nes %^RESET%^%^CYAN%^have been mortared in an "+
            "impressive display, almost giving the impression of a %^RED%^military "+
            "installation%^CYAN%^, complete with %^BOLD%^%^BLACK%^c%^RESET%^r%^BOLD%^e"+
            "%^BLACK%^n%^RESET%^u%^BOLD%^l%^BLACK%^a%^RESET%^t%^BOLD%^i%^BLACK%^o"+
            "%^RESET%^n%^BOLD%^s %^RESET%^%^CYAN%^at the crown of the building. "+
            "Doorways and archways have been picked out with %^ORANGE%^g%^BOLD%^o"+
            "%^WHITE%^l%^ORANGE%^de%^RESET%^%^ORANGE%^n a%^BOLD%^c%^WHITE%^c%^ORANGE%^"+
            "ent%^RESET%^%^ORANGE%^s%^CYAN%^, a color scheme that has been applied to "+
            "the %^YELLOW%^h%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^e"+
            "%^BOLD%^l s%^BLACK%^i%^RESET%^%^ORANGE%^g%^BOLD%^n %^RESET%^%^CYAN%^as "+
            "well.%^RESET%^",
    ]));
    set_exits(([
        "east" : RPATH "street3",
        "west" : RPATH "street6",
        "north" : RPATH "weapon",
        "south" : "/d/dagger/tonovi/town/hotel/room/foyer"
    ]));

    ob = new("/std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "bulletin board", "tonovi board", "Tonovi board" }));
    ob->set_board_id("union_board");
    ob->set_short("Arcane Notice Board");
    ob->set_long("A sturdy wooden frame supports a cork noticeboard here, "+
        "upon the outer wall of the hotel, to allow businesses to advertise "+
        "and citizens and adventurers to communicate about events.");
    ob->set_max_posts(50);
    ob->set_location(RPATH"street5");
}

void reset(){
    ::reset();
    if(!present("tonovi_light")) new("/d/dagger/tonovi/obj/tonovi_light.c")->move(TO);
}

void init(){
    ::init();
}

