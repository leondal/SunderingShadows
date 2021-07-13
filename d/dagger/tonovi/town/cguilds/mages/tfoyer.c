// Inside the Marble Academy, Tonovi
// tgate.c

#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_name("Inside the Marble Academy, Tonovi");
    set_short("Inside the Marble Academy, Tonovi");
    set_long("Generic description for the Inside of the Marble Academy, Tonovi.");
    set_property("light",2);
    set_property("indoors",1);
    set_smell("default","You can smell some acrid air flowing in "+
        "through the entrance.");
    set_listen("default","You can hear the shuffling of "+
        "the magi who pass through here.");
    set_items( ([
/*
        ({"floor","ground","granite","sparkling granite"}): "The "+
            "floor is made of sparkling granite, giving the room a "+
            "magestic feel, despite the dull gray stone walls.  The "+
            "floor seems astoundingly clean and unworn, obviously "+
            "magically protected.",
        ({"wall","walls","marble"}) : "%^BOLD%^%^BLACK%^The smooth "+
            "walls of the tower are made of fantastic %^BLUE%^blue-"+
            "v%^BLACK%^e%^BLUE%^i%^BLACK%^n%^BLUE%^e%^BLACK%^d marble "+
            "set with %^YELLOW%^lightning bolts %^BLACK%^made of "+
            "%^RESET%^%^CYAN%^la%^BOLD%^%^BLUE%^p%^RESET%^%^CYAN%^is "+
            "%^BOLD%^%^BLUE%^l%^RESET%^%^CYAN%^az%^BOLD%^%^BLUE%^u"+
            "%^RESET%^%^CYAN%^li%^BOLD%^%^BLACK%^.",
        ({"archway","archways"}): "The archways chiselled from the "+
            " stone are intricately carved in an assortment of beasts.  "+
            "There are two archways, one in the north wall, and one "+
            "in the east wall.",
*/
    ]) );
    set_exits( ([
        "north" : "tfloor1",
        "store" : "compstore1",
        "exit"  : "tgate",
    ]) );
}
