#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("Patio of an elven home");
   set_long("%^GREEN%^Patio of an elven home%^RESET%^\n"+
   "You are standing on the patio of an elven home. A wooden porch"+
   " has been built across the branches and you have quite a good"+
   " view from up here, but there is no railing so you must be"+
   " careful not to fall. A large branch full of leaves arches over"+
   " the doorway to the southwest, giving half of the patio some shade"+
   " during the heat of the day. There always seems to be a wind"+
   " blowing through here, rustling the leaves and your clothing."+
   " This is quite a nice spot if you're not afraid of heights.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","The wind rustles through the leaves.");
   set_items(([
   "porch" : "The porch has been built of wood across the more slender"+
   " branches of the tree. It seems sturdy enough and will probably"+
   " hold, provided you aren't a giant.",
   "branch" : "A branch arches over the southwest doorway, it is covered"+
   " in many leaves and it provides half of the porch area with a lot"+
   " of shade during the day.",
   ]));
   set_exits( (["southwest":RPATH3+"3one12"]) );
}
