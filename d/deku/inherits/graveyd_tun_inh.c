#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_terrain(ROCKY);
    set_travel(LEDGE);
    set_short("%^YELLOW%^Dark and Narrow Chasm%^RESET%^");
    set_name("dark and narrow chasm");

    set_long("%^YELLOW%^The earth around you has split to "+
    "form this dark and narrow %^RED%^chasm%^YELLOW%^.  The "+
    "walls of the %^RED%^chasm%^YELLOW%^ are perhaps six few feet "+
    "apart and allow for only very limited movement from anyone "+
    "caught between them.  The walls shift and bend to almost "+
    "resemble a vertical and remarkably dry river bed.  The "+
    "curves of the walls provide a natural grip for anyone "+
    "that might find themselves climbing here and several "+
    "%^RED%^jutting ledges%^YELLOW%^ provide a reliable way "+
    "to get a foothold.  The %^RED%^chasm%^YELLOW%^ is obviously "+
    "quite dangerous and you think that it could collapse "+
    "at any moment.%^RESET%^");
        
    set_listen("default","%^BOLD%^The quiet murmor of what almost "+
    "sounds like muffled wails of agony drifts up to you.%^RESET%^");

    set_smell("default","%^RED%^A heavy odor of death slips up "+
    "through the earth beneath you.%^RESET%^");
    
    set_items(( [
        ({"chasm","dark chasm","narrow chasm"}) : "%^RED%^The chasm "+
        "appears to be a natural formation from what was an obvious "+
        "shift and eventual split in the earth.  It is obviously "+
        "quite unstable and the darkness that rises from deep within "+
        "it does nothing to comfort you.%^RESET%^",
        "walls" : "%^YELLOW%^The walls of this chasm are formed "+
        "from dry and crumbling dirt, sand, and occassionally rock."+
        "%^RESET%^",
        ({"ledges","jutting ledges"}) : "%^RED%^The very few "+
        "ledges that appear in this chasm are apparently the "+
        "upperside of larger rocks.  They look sturdy enough."+
        "%^RESET%^",
    ] ));

    set_search("default","You realize that a prolonged search "+
    "here wouldn't be too wise of an idea...");    
}

void reset() {
    ::reset();
}