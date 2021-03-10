//General store -- Yves
#include <std.h>
#include <daemons.h>
#include "../argabbr.h"
inherit INH+"indoors";


void create(){
    ::create();
    set_long((:TO,"long_desc":)); 
    set_smell("default",
        "The scent of various spices overpower those of the forest."
    );
    set_listen("default",
        "It is suprisingly quiet as many of the elves come and go for "
        "provisions."
    );
    add_item(
        ({"piles","shelving","hammocks"}),
            "%^ORANGE%^These %^CYAN%^windscreens%^ORANGE%^, pieces of shelving and %^RESET%^hammocks%^ORANGE%^ are "
            "being issued to the %^MAGENTA%^elven%^ORANGE%^ refugees for use in building "
            "their %^RED%^shelters%^ORANGE%^.%^RESET%^"
    );
    add_item(
        ({"wall","shelves","supplies"}), 
            "%^ORANGE%^These shelves are made from the same %^RESET%^gray wood%^ORANGE%^ as the "
            "%^CYAN%^windscreens%^ORANGE%^ and %^BOLD%^%^BLACK%^hook%^RESET%^%^ORANGE%^ on to the top of them and hang down. "
            "They are packed full of common %^BLUE%^supplies%^ORANGE%^ and cover most of "
            "the %^CYAN%^wall%^ORANGE%^ space rendering the see through aspect of the "
            "%^CYAN%^windscreens%^ORANGE%^ here virtually useless."
    );
    set_exits(([
        "west" : PATH+"platform23",
    ]));
}

string long_desc(){
    return get_base_desc()
        +"Many %^CYAN%^windscreens%^ORANGE%^, pieces of shelving and %^RESET%^hammocks%^ORANGE%^ are arranged "
        "in neat %^BOLD%^%^WHITE%^piles%^RESET%^%^ORANGE%^ in the corners of the room and are being issued "
        "to the %^MAGENTA%^elven%^ORANGE%^ refugees as they come and go. Nearly every inch of "
        "the %^CYAN%^wall%^ORANGE%^ space is covered in shelves that are packed full of "
        "common %^BLUE%^supplies%^ORANGE%^.%^RESET%^"
        "\n\n<help shop> will show you a list of commands to use here.\n";
}

void reset(){
    ::reset();
    if(!present("shopkeeper")) {
        new(MON+"shopkeep")->move(TO);
    }
}
