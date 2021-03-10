//Goodies cache for use in argpath.c -- Yves 2/15/18
#include <std.h>
#include "../argabbr.h"
#include "../rand.h"
inherit ROOM;

int weapons,mundane;

void create(){
    weapons = 0;
    mundane = 0;
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_name("cache");
    set_short("%^BOLD%^%^GREEN%^A hidden cache in the foliage of Argentrock "
        "Forest%^RESET%^");
    set_property("indoors",1);
    set_property("light",0);
    set_property("no teleport",1);
    set_long((:TO,"long_desc":));
    set_items(([
        ({"root","roots","chamber","floor","wall","walls"}):
            "%^ORANGE%^This %^RED%^chamber%^ORANGE%^ is nestled in a hollow "
            "amongst the %^CYAN%^roots%^ORANGE%^ of one of the great "
            "%^GREEN%^trees%^ORANGE%^ and has a packed dirt floor.%^RESET%^",

        ({"shelving", "shelves"}):
            "%^BOLD%^%^BLACK%^These shelves are made of a strange gray wood "
            "and hook onto the %^RESET%^%^CYAN%^roots%^BOLD%^%^BLACK%^ of the "
            "%^RESET%^%^CYAN%^walls%^BOLD%^%^BLACK%^ of the %^RESET%^%^RED%^"
            "chamber%^BOLD%^%^BLACK%^. They might contain something of use"
            "%^RESET%^",

        ({"weapon racks","racks","rack","weapon rack"}):
            "%^BOLD%^%^BLACK%^These weapon racks are made of a strange gray "
            "wood and hook onto the %^RESET%^%^CYAN%^roots%^BOLD%^%^BLACK%^ of "
            "the %^RESET%^%^CYAN%^walls%^BOLD%^%^BLACK%^ of the "
            "%^RESET%^%^RED%^chamber%^BOLD%^%^BLACK%^. They might "
            "contain something of use.%^RESET%^"
    ]));
    //Get set_search (/std/room/senses.c) to support arrays
    set_search("shelving",(:TO,"search_func":));
    set_search("shelves",(:TO,"search_func":));
    set_search("rack",(:TO,"search_func":));
    set_search("racks",(:TO,"search_func":));
    set_search("weapon rack",(:TO,"search_func":));
    set_search("weapon racks",(:TO,"search_func":));
    set_search("weapons",(:TO,"search_func":));
    set_smell("default","The air in here is stale and humid.");
    set_listen("default","The sounds of the forest are muffled.");
}

string long_desc(){
    return
      "%^BOLD%^%^GREEN%^A hidden cache in the foliage of Argentrock Forest%^RESET%^\n"
      "%^ORANGE%^You are standing in a cramped %^RED%^chamber%^ORANGE%^ hidden "
      "underneath the %^GREEN%^foliage%^ORANGE%^ of the forest. The "
      "%^RED%^chamber%^ORANGE%^ has been hollowed out inside the "
      "%^CYAN%^root%^ORANGE%^ system of one of the great trees, and the "
      "support of the %^CYAN%^roots%^ORANGE%^ keep the %^RED%^chamber%^ORANGE%^ "
      "from collapsing upon itself. Nearly every inch of %^CYAN%^wall%^ORANGE%^ "
      "space has been covered in %^BOLD%^%^BLACK%^shelving%^RESET%^%^ORANGE%^ "
      "and %^BOLD%^%^BLACK%^weapon racks%^RESET%^%^ORANGE%^, the floor is "
      "packed dirt and completely bare.%^RESET%^";
}

void init(){
    ::init();
    add_action("no_quit","quit");
}
int no_quit(string str){
    write("You are not allowed to quit here!");
    TP->force_me("up");
    if(base_name(ETP) != PATH+"cache")
        TP->force_me("quit");
    return 1;
}


string search_func(string str){
    if(str == "shelving" || str == "shelves"){
        if(mundane){
            tell_object(TP,
                "You don't find anything of worth."
            );
            tell_room(TO,
                ""+TPQCN+" searches around the shelves.",TP
            );
            return 0;
        }
        mundane = 1;
            switch(random(3)){
        case 0:
            tell_object(TP,
                "%^CYAN%^You find something amongst the shelves!%^RESET%^"
            );
            tell_room(TO,
                "%^CYAN%^"+TPQCN+" finds something amongst the shelves!%^RESET%^",TP
            );
            new(OBJ+MUNDANE[random(sizeof(MUNDANE))])->move(TO);
        break;
        case 1:
            tell_object(TP,
                "%^CYAN%^You find something amongst the shelves!%^RESET%^"
            );
            tell_room(TO,
                "%^CYAN%^"+TPQCN+" finds something amongst the shelves!%^RESET%^",TP
            );
            RANDSTUFF->find_stuff(TO,"random");
        break;
        case 2:
            tell_object(TP,
                "You don't find anything of worth."
            );
            tell_room(TO,
                ""+TPQCN+" searches around the shelves.",TP
            );
        break;
        }
        return 1;
    }

    if( str == "weapon racks" ||
        str == "racks" ||
        str == "rack" ||
        str == "weapon rack" ||
        str == "weapons"){
        if(weapons){
            tell_object(TP,
                "You don't find anything of worth."
            );
            tell_room(TO,
                ""+TPQCN+" searches around the weapon racks.",TP
            );
            return 0;
        }
        weapons = 1;
            switch (random(3)){
        case 0:
            tell_object(TP,
                "%^CYAN%^You find something amongst the weapon racks!%^RESET%^"
            );
            tell_room(TO,
                "%^CYAN%^"+TPQCN+" finds something amongst the weapon racks!%^RESET%^",TP
            );
            new(OBJ+WEAPONS[random(sizeof(WEAPONS))])->move(TO);
        break;
        case 1:
            tell_object(TP,
                "%^CYAN%^You find something amongst the weapon racks!%^RESET%^"
            );
            tell_room(TO,
                "%^CYAN%^"+TPQCN+" finds something amongst the weapon racks!%^RESET%^",TP
            );
            RANDGEAR->arm_me(TO,COMWEAP[random(sizeof(COMWEAP))]);

        break;
        case 2:
            tell_object(TP,
                "You don't find anything of worth."
            );
            tell_room(TO,
                ""+TPQCN+" searches around the weapon racks.",TP
            );
        break;
        }
        return 1;
    }
}

