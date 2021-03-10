#include <std.h>
#include <objects.h>
#include <money.h>

inherit ROOM;

void create()
{
  ::create();
  set_property("light",1);
  set_property("indoors",1);
  set_short("Telima's Home");
  set("day long",
@HOUSE
You are in Telima's parlor. Three bedrooms can be reached 
from here, and there is another upstairs. You see Telima 
working in the room to the east. Telima takes great pride 
in the simplicity of her home and its comforts, and there 
are people scattered around the room simply talking.
HOUSE
  );
  set_smell("default","The smells here remind you of home.");
  set_listen("default","A fire blazes welcomingly in the fireplace.");
  set_items( ([
     "rooms" : "The rooms are small but definitely comfortable for two people at a time.",
     "room" : "This room is large and has overstuffed furniture scattered throughout, centered in front of the fireplace.",
     "kitchen" : "The kitchen is set up so that everything is within easy reach and quickly accessable."
  ]) );
  set_exits( ([
     "west"    : "/d/darkwood/forest/village/telhome",
     "up"   : "/d/darkwood/forest/village/telroom1",
     "east"   : "/d/darkwood/forest/village/telroom2",
     "north"  : "/d/darkwood/forest/village/telroom3",
     "south"  : "/d/darkwood/forest/village/telroom4"
  ]) );
}
