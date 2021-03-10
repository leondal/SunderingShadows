#include <std.h>
#include "../defs.h"
//#define AVA_D "/daemon/avatar_d.c"
inherit "/std/library.c";

void create(){
    ::create();
    // new stuff to make this a working library -Ares
    set_public_library(1);
    set_deposit(200);
    set_library_name("Shadow_Public_Library");

    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("Shadow Library");
    set_long(
        "%^BOLD%^Shadow Library%^RESET%^
%^RESET%^%^WHITE%^This is the %^BLUE%^S%^CYAN%^h%^BLUE%^a%^CYAN%^d%^BLUE%^ow %^BLUE%^City %^BLUE%^Libra%^CYAN%^r%^BLUE%^y%^CYAN%^.%^WHITE%^ There are a few tables and desks just inside the door and there is a large wooden counter running the width of the room. Behind the counter you see rows and rows of %^BLUE%^shelves%^WHITE%^ filled with many %^CYAN%^s%^BLUE%^crol%^CYAN%^l%^CYAN%^s%^BLUE%^.%^WHITE%^ If the librarian is here, she may help you <research> whoever you are interested in.%^RESET%^
"
        );
    set_light(2);
    set_indoors(1);
    set_smell("default","You smell something that must be used to preserve the scrolls.");
    set_listen("default","It's a library, it's supposed to be quiet.");
    set_items(([
                   "shelves":"They are filled with scrolls used to research people.",
                   "scrolls":"These contain the background information on the characters of the realm."
                   ]));
    set_exits(([
                   "east":ROOMS"melistel2",
                   ]));
}

//void reset(){
//    if(!present("librarian")) 
//        find_object_or_load("/d/shadow/mon/librarian")->move(TO);
//}

