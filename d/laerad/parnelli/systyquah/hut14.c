//Coded by Bane//
#include <daemons.h>
#include <std.h>
inherit ROOM;
void create(){
    ::create();
    set_terrain(HUT);
    set_travel(DIRT_ROAD);
    set_name("Systyquah's component shop");
    set_short("Systyquah's component shop");
    set_long(
	"%^BOLD%^Systyquah's component shop%^RESET%^
You are standing in a magic components shop.  The stores walls are covered "+
	"with various sized bottles filled with everything from brains to "+
	"dragon scales to vampire dust.  There is a desk at the northern "+
	"end of the room where you can <help shop> to get a list of shop "+
	"commands.  There is a troll apprentice mage waiting to help you."
    );
    set_property("light",2);
    set_property("indoors",1);
    set_smell("default","The room smells of incense and strange oils");
    set_listen("default","You can hear the argument of a few beastly patrons.");
    set_exits( ([
	"southeast":"/d/laerad/parnelli/systyquah/sys063"
    ]) );
    set_property("no attack",1);
 }

void reset(){
    ::reset();
    if(!present("hassimith")){
	new("/d/laerad/mon/hassimith")->move(this_object());
    }
}
