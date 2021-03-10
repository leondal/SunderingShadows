//Coded by Bane//
#include <daemons.h>
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_terrain(HUT);
    set_travel(DIRT_ROAD);
    set_name("Systyquah's general store");
    set_short("Systyquah's general store");
    set_long(
	"%^BOLD%^Systyquah's general store%^RESET%^
You have walked into a general store.  The stores walls are lined with "+
	"numerous weapons, armors, and other equipment.  There is a desk "+
	"at the northern end of the room where you can <list> or "+
	"<buy> and <sell> items.  There is a troll behind the counter waiting "+
	"to take your request."
    );
    set_property("light",2);
    set_property("indoors",1);
    set_smell("default","The room smells of oil and grease.");
    set_listen("default","You can hear the argument of a few beastly patrons.");
    set_exits( ([
	"southwest":"/d/laerad/parnelli/systyquah/sys040"
    ]) );
    set_property("no attack",1);
 }

void reset(){
    ::reset();
    if(!present("ximiz")){
	new("/d/laerad/mon/ximiz")->move(this_object());
    }
}
