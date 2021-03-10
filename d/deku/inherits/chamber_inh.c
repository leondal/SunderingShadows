#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit CROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_terrain(ROCKY);
    set_travel(LEDGE);
    set_short("%^YELLOW%^A Sandstone Chamber%^RESET%^");
    set_name("a sandstone chamber");
    
    set_long("%^BOLD%^%^BLACK%^The %^MAGENTA%^floor%^BOLD%^%^BLACK%^ "+
    "of this massive chamber is made from dirt that has been "+
    "packed down and made hard over a course of many years.  "+
    "However, dirt alone does not construct the %^MAGENTA%^"+
    "floor%^BOLD%^%^BLACK%^, as what appears to be fragments of "+
    "and even whole %^BOLD%^%^WHITE%^bones%^BOLD%^%^BLACK%^ peek "+
    "up from the mixture, their strange %^BOLD%^%^WHITE%^white gleam"+
    "%^BOLD%^%^BLACK%^ offering you a startling hint at "+
    "the intent of the chamber you now find yourself "+
    "in.  The %^MAGENTA%^ceiling%^BOLD%^%^BLACK%^ hangs overhead "+
    "approximately twenty feet and is formed from a seemingly "+
    "unreliable mixture of sandstone and packed dirt.  An "+
    "unnatural %^BLUE%^chill%^BOLD%^%^BLACK%^ "+
    "hangs in the air and sends a sudden jolt of cold shivers "+
    "coursing through your body.%^RESET%^");
    
          
    set_listen("default","%^BOLD%^Screams of agony erupt from all "+
    "around you!%^RESET%^");

    set_smell("default","%^RED%^A heavy odor of death hangs in "+
    "the air here.%^RESET%^");
    
    set_items(( [
        ({"floor","packed floor","dirt floor"}) : "%^MAGENTA%^"+
        "The packed dirt floor of this chamber, is, to your horror, "+
        "composed partly of fragments and even entire bones."+
        "%^RESET%^",
        ({"bones","bone fragments"}) : "%^BOLD%^%^WHITE%^The bones "+
        "and bone fragments which peek up from the floor "+
        "offer a disturbing %^RESET%^white gleam%^BOLD%^.%^RESET%^",
        ({"gleam","white gleam"}) : "%^BOLD%^%^WHITE%^The bones "+
        "which grant this gleam serve to testify that the chamber "+
        "you now find yourself in is some type of strange burial "+
        "chamber.%^RESET%^",
        ({"ceiling","dirt ceiling"}) : "%^MAGENTA%^The "+
        "ceiling is approximately twenty feet overhead and "+
        "constructed from an unreliable mixture of dirt and "+
        "sandstone.%^RESET%^",
        ({"chill","unnatural chill"}) : "%^BLUE%^The chill "+
        "that hangs in the air is a strangely unnatural "+
        "one, each time it touches your flesh your body "+
        "is assaulted by a new wave of shivers.%^RESET%^",
    ] ));

    set_search("default","%^RED%^The floor of the chamber is "+
    "packed and nothing else appears to house any secrets.%^RESET%^");
    
}

void reset() {
    ::reset();
}