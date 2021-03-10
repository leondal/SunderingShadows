//Elven leaders home -- Yves
#include <std.h>
#include "../argabbr.h"
inherit INH+"indoors";

void create(){
    ::create();
    set_long((:TO,"long_desc":)); 
    set_smell("default","Fresh breaths of the forest restore you.");
    set_listen("default","You hear gusts of wind blow through the "
        "forest."
    );
    add_item(
        ({"shelves", "clothing", "items","shelf"}),
            "%^ORANGE%^These shelves are made from the same %^RESET%^gray wood%^ORANGE%^ as the "
            "%^CYAN%^windscreens%^ORANGE%^ and %^BOLD%^%^BLACK%^hook%^RESET%^%^ORANGE%^ on to the top of them and hang down. "
            "An assortment of %^RED%^clothing%^ORANGE%^ and other personal %^BLUE%^items%^ORANGE%^ are "
            "stored here.%^RESET%^"
    );
    add_item(
        "hammock",
            "A large hammock hangs from the %^ORANGE%^branches%^RESET%^, while not as "
            "%^RED%^stable%^RESET%^ as a normal bed, they are easy to set up and move "
            "around."
    );
    set_exits(([
        "north" : PATH+"platform23",
    ]));
}

string long_desc(){
    return get_base_desc()
        +"A few shelves hang from the %^CYAN%^windscreens%^ORANGE%^ and contain %^RED%^clothing%^ORANGE%^ "
        "and a few personal %^BLUE%^items%^ORANGE%^. A large %^RESET%^hammock%^ORANGE%^ also hangs from the "
        "branches and looks big enough for two %^MAGENTA%^elven%^ORANGE%^ sized people.%^RESET%^";
}

void reset(){
    ::reset();
    if(!present("ivesa")) {
        new(MON+"wife.c")->move(TO);
    }
}

