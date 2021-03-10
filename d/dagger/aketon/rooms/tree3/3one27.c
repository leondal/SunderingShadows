#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven house of Aketon");
   set_long("%^GREEN%^An elven house of Aketon%^RESET%^\n"+
   "This is a slightly smaller room than the one you just came from, and"+
   " it is apparently the bedroom. It has a beautiful meadow scene painted"+
   " around the walls and floor of the room, and on the wooden ceiling is"+
   " a scene of the sky at twilight. The bed is in the center of the room"+
   " and it is covered in green and brown blankets. The owner of this house"+
   " sure likes earth tones.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_items(([
   "ceiling" : "The ceiling is a real ceiling now, made of wood. It has"+
   " been painted with a beautiful scene of the sky at twilight.",
   "walls" : "The walls have been painted with a lovely scene of a simple"+
   " meadow, it extends down to cover the floor and is very realistic.",
   "bed" : "There is a large bed in the center of the room that is covered"+
   " in many green and brown blankets, it almost looks like a giant tree"+
   " that has fallen onto its side.",
   "curtain" : "%^GREEN%^There is a lovely silk curtain that hangs down"+
   " over the doorway to the east, giving this room some privacy.",
   ]));
   set_listen("default","You hear the wind rustling through the leaves.");
   set_exits( (["east":RPATH3+"3one28"]) );
}
