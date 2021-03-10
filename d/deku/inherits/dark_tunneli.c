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
    set_short("%^BOLD%^A Dark Tunnel%^RESET%^");
    set_name("a dark tunnel");
    
    set_long("A dark tunnel");
          
    set_listen("default","%^BOLD%^Screams of agony pierce the "+
    "darkness.%^RESET%^");
    
    set_smell("default","%^RED%^A heavy odor of death hangs in "+
    "the air here.%^RESET%^");
    
    set_items(( [
       
    ] ));

    //set_search("default","%^RED%^The floor of the chamber is "+
    //"packed and nothing else appears to house any secrets.%^RESET%^");
    
}

void reset() {
    ::reset();
}