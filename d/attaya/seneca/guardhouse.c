#include <std.h>
#include "short.h"

inherit CITYOUT;

void create(){
    ::create();
    set_short("guard outpost");
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",3);
    set_long(
      "You are in the west gate guard outpost.  The room is divided by multiple short walls and several guards sit in the small cubicles between.\n  A central office behind a glass window seems to support the regional guard commander but he is out at the moment."
    );
    set_listen("default", "Guards talk amongst themselves");
    set_exits(([
	"out" : "/d/attaya/seneca/boardwalk3",
      ]));
    set_items(([
      ]));


}
void reset(){
    ::reset();
    if(!present("guard 4"))
	new("d/attaya/seneca/mon/guard1")->move(this_object());
    if(!present("guard 4"))
	new("d/attaya/seneca/mon/guard1")->move(this_object());
    if(!present("guard 4"))
	new("d/attaya/seneca/mon/guard1")->move(this_object());
}
