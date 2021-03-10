#include <std.h>
#include "short.h"

inherit CITYOUT;

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 1);
    set_short("On the Boardwalk");
    set_long(
      "You have arrived at the end of the boardwalk and at the guard post on the boardwalk leading into the city.  The great city gates here stand open, ready to be closed at a moment's notice in the event that Intruder attempts to take the city.  Though the gates to the south you can see the shining cathedral rising into the sky.  There is a building here, built on the boardwalk, for the guards to take shelter in."
    );
    set_smell("default", "The smell of the salt water rises up from below you, filling your nose.");
    set_listen("default", "You can hear several seagulls somwhere nearby.");
    set_items( ([
	"cathedral" : "This great cathedral was built before the time of Intruder, and is now the only remaining enclave of opposotion to him on this island",
	"boardwalk" : "The boardwalk leads between the mainland and the city proper.  There are some guard posts along it.",
	({"guards", "guard posts", "guard post"}) : "meant to give the city a chance to close down to defend itself, these guards will fight bravely to the death.",
	"building" : "This smaller sized building is here for the guards to stay when not on duty.",
      ]) );
    set_exits( ([
	"north" : "/d/attaya/seneca/boardwalk2",
	"south" : "/d/attaya/seneca/street1",
	"enter" : "/d/attaya/seneca/guardhouse",
      ]) );
}

void reset(){
    ::reset();
    if(!present("street light"))
	new("/d/attaya/seneca/obj/fakelight")->move(TO);
    if(!present("guard 2")){
	new("/d/attaya/seneca/mon/guard1")->move(TO);
	new("/d/attaya/seneca/mon/guard1")->move(TO);
    }
}
