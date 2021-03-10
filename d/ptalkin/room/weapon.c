#include <std.h>
#include "/d/ptalkin/ptalkin.h"
inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors", 1);
set_short("D'wellars Weapons Shop");
set_long("%^ORANGE%^D'wellars Weapons Shop holds many items.  Swords, daggers, axes and maces to name a few.  D'wellar is standing at a large round whet stone, honing a battle-axe.  A long counter sits at the left wall and armour is laid about waiting for repairs.  Should you need help, <list> will give you the options you require.");
    set_smell("default","You smell hot metal, an burning brasiers.");
	set_listen("default", "%^ORANGE%^You hear the sounds of work nearby");

set_property("no attack", 1);
    set_exits( ([
"out" : PROOM+"room67.c"
        ]) );
    set_items( ([
	"counter" : "A hardwood counter, with weapons on it.",
	"room" : "Large room, weapon parts scattered about the room",
	"armor" : "The weapons you see are in bad repair."
		]));		    	

}
void init(){
    ::init();
if(!present("d'wellar"))
new("/d/ptalkin/mon/d'wellar")->move(TO);


}
