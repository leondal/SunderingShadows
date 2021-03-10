//Indoor room inherit -- Yves
#include <std.h>
#include "../argabbr.h"
inherit ROOM;

string get_base_desc();

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_name("home");
    set_short("A small elven home in the trees of Argentrock Forest"
    );
    set_items(([
        ({"platform", "branch", "floor"}): 
            "%^ORANGE%^A large branch emerges from the tree and forms the floor of "
            "the home.%^RESET%^",
        
        ({"windscreens", "screens"}):
            "%^CYAN%^These are made from a %^ORANGE%^wooden%^CYAN%^ frame with %^BOLD%^%^BLACK%^hooks%^RESET%^%^CYAN%^ along the top "
            "edge for hanging from %^ORANGE%^branches%^CYAN%^. The %^RESET%^fabric%^CYAN%^ stretched across "
            "the %^ORANGE%^frame%^CYAN%^ is %^BOLD%^%^WHITE%^sheer%^RESET%^%^CYAN%^ on one side and %^RED%^solid%^CYAN%^ on the other "
            "creating a one way window.%^RESET%^",
        
        ({"trunk", "tree", "trees"}):
            "%^ORANGE%^You cannot identify what kind of trees this is. It is "
            "like nothing you have ever seen before, with a diameter of "
            "at least twenty feet and a %^RESET%^cool gray color%^ORANGE%^ with smooth "
            "bark.%^RESET%^",
        
        ({"leaves", "branches", "above"}):
            "%^BOLD%^%^GREEN%^The leaves of the %^RESET%^%^ORANGE%^branches%^BOLD%^%^GREEN%^ above have grown %^BLACK%^abnormally large%^GREEN%^ "
            "and thick. They form a roof over the %^RESET%^%^ORANGE%^platform%^BOLD%^%^GREEN%^, keeping the "
            "%^RESET%^%^RED%^weather%^BOLD%^%^GREEN%^ out and helping to maintain a constant room "
            "tempature inside the home.",
    ]));
}

string get_base_desc(){
    return "%^BOLD%^%^GREEN%^A small elven home in the trees of " 
        "Argentrock Forest%^RESET%^\n%^ORANGE%^You are standing in " 
        "a makeshift %^MAGENTA%^elven%^ORANGE%^ home high up in the "
        "%^GREEN%^trees%^ORANGE%^. Emerging proudly from the trunk of "
        "the great %^GREEN%^tree%^ORANGE%^ is a large branch that "
        "seems to have %^GREEN%^grown%^ORANGE%^ for the very "
        "purpose of being a floor. Several %^CYAN%^windscreens%^ORANGE%^, "
        "that reach to the branches above, have been positioned along the "
        "edges to protect the inhabitants from the %^BLUE%^chill%^ORANGE%^, "
        "as well as provide privacy. The %^GREEN%^leaves%^ORANGE%^ of "
        "the branches here have grown especially thick too and do an "
        "excellent job of keeping out the %^RED%^weather%^ORANGE%^. ";
}
