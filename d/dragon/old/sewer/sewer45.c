#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",1);
    set_property("indoors",1);
    set_short("Sanctuary Sewers");
    set_long("%^RED%^%^BOLD%^
This is a large circular chamber.  Faintly luminescent lichen climgs to
the dark walls, reflecing lightly off the water that occasionally drips
from the ceiling to the tunnel.  There is no other way out of this room
besides the way you came in.
    ");
    set_exits(([
       "north" : "/d/dragon/sewer/sewer44"
    ] ));
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary."
    ] ));
    set_property("no teleport", 1);
    set_smell("default","The rotting smell of waste is very strong in these tunnels.");
}

void reset() {
  ::reset();
  if(!present("behir")) {
    new("/d/dragon/mon/behir")->move(this_object());
  }
}
