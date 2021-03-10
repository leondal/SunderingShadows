//Coded by Bane//
#include <daemons.h>

#include <std.h>
#include "/d/laerad/laerad.h"

inherit ASGARD;

void create(){
    ::create();
/*
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
    set_name("Asgard's general store");
    set_short("Asgard's general store");
    set_long(
	"%^BOLD%^Asgard's general store%^RESET%^
You have walked into a general store.  The stores walls are lined with "+
	"numerous weapons, armors, and other equipment.  There is a desk "+
	"at the northern end of the room where you can <list> or "+
	"<buy> and <sell> items.  There is a clerk behind the counter waiting "+
	"to take your request."
    );
    set_property("light",2);
    set_property("indoors",1);
    set_smell("default","The room smells of oil and grease.");
    set_listen("default","You can hear the chatter of a few customers.");
*/
   set_long(::query_long()+"\nThe ruined remains of the shelves here hint "
      "that this used to be a store of some kind.  Unfortunately, nothing "
      "of use has been left behind.\n");
    set_exits( ([
	"east":"/d/laerad/parnelli/asgard/as71"
    ]) );
/*
    set_property("no attack",1);
    set_property("no bump",1);
*/
 }
/*
void reset(){
    ::reset();
    if(!present("magnus")){
	new("/d/laerad/mon/magnus")->move(this_object());
    }

}
*/