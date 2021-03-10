#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light",0);
    set_property("indoors",1);
    set_terrain(ROCKY);
    set_travel(LEDGE);
    set_short("%^YELLOW%^A Sandstone Burial Chamber^RESET%^");
    set_name("a sandstone burial chamber");
    
    set_long("");
          
    set_listen("default","%^BOLD%^Screams of agony erupt from all "+
    "around you!%^RESET%^");

    set_smell("default","%^RED%^A heavy odor of death hangs in "+
    "the air here.%^RESET%^");
    
    set_items(( [

    ] ));

    //set_search("default","Perhaps something of interest "+
    //"could have fallen to the ground?");
    
}

void reset() {
    ::reset();
}