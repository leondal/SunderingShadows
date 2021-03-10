//Healer room -- Yves
#include <std.h>
#include "../argabbr.h"
inherit HEALER;

void create(){
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_name("home");
    set_short("A small elven home in the trees of Argentrock Forest");
    set_long((:TO,"long_desc":)); 
    set_smell("default",
        "Fresh breaths of the forest combine with herbs and poultices."
    );
    set_listen("default",
        "You hear the groans of the wounded and sickly coughing quite "
        "often."
    );
    set_items(([
        ({"platform","branch","floor"}): 
            "%^ORANGE%^A large branch emerges from the tree and forms the floor of "
            "the home.%^RESET%^",
        
        ({"windscreens","screens"}):
            "%^CYAN%^These are made from a %^ORANGE%^wooden%^CYAN%^ frame with %^BOLD%^%^BLACK%^hooks%^RESET%^%^CYAN%^ along the top "
            "edge for hanging from %^ORANGE%^branches%^CYAN%^. The %^RESET%^fabric%^CYAN%^ stretched across "
            "the %^ORANGE%^frame%^CYAN%^ is %^BOLD%^%^WHITE%^sheer%^RESET%^%^CYAN%^ on one side and %^RED%^solid%^CYAN%^ on the other "
            "creating a one way window.%^RESET%^",
        
        ({"trunk","tree","trees"}):
            "%^ORANGE%^You cannot identify what kind of trees this is. It is "
            "like nothing you have ever seen before, with a diameter of "
            "at least twenty feet and a %^RESET%^cool gray color%^ORANGE%^ with smooth "
            "bark.%^RESET%^",
        
        ({"leaves","branches","above"}):
            "%^BOLD%^%^GREEN%^The leaves of the %^RESET%^%^ORANGE%^branches%^BOLD%^%^GREEN%^ above have grown %^BLACK%^abnormally large%^GREEN%^ "
            "and thick. They form a roof over the %^RESET%^%^ORANGE%^platform%^BOLD%^%^GREEN%^, keeping the "
            "%^RESET%^%^RED%^weather%^BOLD%^%^GREEN%^ out and helping to maintain a constant room "
            "tempature inside the home.",
        
        ({"hammocks","beds","hammock","bed"}):
            "Dozens of hammocks hang from the %^ORANGE%^branches%^RESET%^ very close to "
            "each other, while not as %^RED%^stable%^RESET%^ as a normal bed they are "
            "easy to set up and move around.",
        
        ({"shelving","shelf","shelves"}):
            "%^ORANGE%^These shelves are made from the same %^RESET%^gray wood%^ORANGE%^ as the "
            "%^CYAN%^windscreens%^ORANGE%^ and %^BOLD%^%^BLACK%^hook%^RESET%^%^ORANGE%^ on to the top of them and hang down. "
            "Various %^BLUE%^beakers%^ORANGE%^ and %^CYAN%^containers%^ORANGE%^ of medicinal ingredients and "
            "%^BOLD%^%^WHITE%^equipment%^RESET%^%^ORANGE%^ are stored here.%^RESET%^",
        
        ({"beakers","containers","herbs","chemicals","equipment"}):
            "%^ORANGE%^The %^BLUE%^beakers%^ORANGE%^ contain such thing as %^RESET%^vinegars%^ORANGE%^, %^RED%^wines%^ORANGE%^, %^BOLD%^%^BLACK%^oils%^RESET%^%^ORANGE%^, "
            "and %^BLUE%^water%^ORANGE%^. You may be able to recognize some of the more "
            "common items in the %^CYAN%^containers%^ORANGE%^ such as %^YELLOW%^wax%^RESET%^%^ORANGE%^, bark, %^BOLD%^%^BLACK%^dung%^RESET%^%^ORANGE%^, and "
            "%^GREEN%^dried leaves%^ORANGE%^ but it is impossible to tell what any of it is "
            "for certain as they are stoppered.",
        
        "table":
            "%^ORANGE%^One lone %^RESET%^gray wooden table%^ORANGE%^ is here and it barely fits "
            "as is. It is just big enough to be used as an exam table as "
            "well as a work bench for brewing %^BLUE%^potions%^ORANGE%^ and fixing up "
            "%^RED%^dressings%^ORANGE%^.%^RESET%^"
    ]));
    set_exits(([
        "south":PATH+"platform23",
    ]));
    set_name("Hasas");
    set_cl_price(20);
    set_cs_price(45);
    set_cc_price(100);
    set_np_price(150);
    set_cb_price(150);
    set_bp_price(30);
}

string long_desc(){
    return find_object_or_load(INH+"indoors")->get_base_desc()+
        "Dozens of %^RESET%^hammocks%^ORANGE%^ hang from the branches where the sick and "
        "injured can recover, or where less fortunate can find a %^RESET%^bed.%^ORANGE%^ "
        "Shelving has been built into a couple of the %^CYAN%^windscreens%^ORANGE%^ where "
        "there are %^BLUE%^beakers%^ORANGE%^ and %^CYAN%^containers%^ORANGE%^ of various medicinal %^GREEN%^herbs%^ORANGE%^ and "
        "%^BOLD%^%^BLACK%^chemicals%^RESET%^%^ORANGE%^ as well as medical %^BOLD%^%^WHITE%^equipment%^RESET%^%^ORANGE%^. All of the extra "
        "hammocks and equipment make it extremely %^RED%^cramped%^ORANGE%^ in here and "
        "there is only enough space for a %^RESET%^small table%^ORANGE%^ for the healer to "
        "do his work on.";
}

void reset(){
    ::reset();
    if(!present("healer")) {
        new(MON+"healer.c")->move(TO);
    }
}
