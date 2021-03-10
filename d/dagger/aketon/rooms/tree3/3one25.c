#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "This is the cozy greeting room of an elven home. There is a plush"+
   " green couch near the center with a beautiful koa wood coffee"+
   " table in the middle of the room. There are two wooden chairs that"+
   " are nicely padded with green velvet cushions. There is a row of"+
   " bookshelves along the northern wall, and a large tapestry of a"+
   " centaur takes up the entire southern wall. There is a doorway"+
   " to the east.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","The wind rustles through the leaves outside.");
   set_items(([
   ({"wooden door","door"}) : "There is a large door to the southwest"+
   " that leads back to a branch of Aketon.",
   ({"green couch","couch","plush couch"}) : "%^GREEN%^There is a large"+
   " green couch that faces to the south, it is not quite centered in"+
   " the room, but placed in the center is a koa coffee table.",
   ({"coffee table","koa table","table"}) : "The coffee table is made"+
   " out of one large slab of a huge koa tree. The wood itself is very"+
   " rare, and the coffee table is very beautiful. You can see the"+
   " different shades of the rings of the tree, showing its great age."+
   " It has been carefully varnished, and the bark has even been left"+
   " on the edges, though it too has been varnished.",
   "chairs" : "There are two chairs that sit across from the couch. They"+
   " are made from black walnut wood and have green velvet cushions.",
   "bookshelves" : "There is a large row of bookshelves along the north"+
   " wall. Most of them seem to be about the woods, you notice some"+
   " books on rangers, and many on centaurs and other such magical"+
   " creatures. You also notice several magical runes inscribed on either"+
   " end of the bookshelf, and realize that trying to get a closer look"+
   " at one of the books would probably be a bad idea.",
   ({"tapestry","centaur tapestry","southern wall"}) : "There is a large"+
   " tapestry that takes up the full length of the southern wall. It"+
   " depicts a centaur standing in the forest, taking careful aim with"+
   " his bow at something outside of the tapestry. It is of excellent"+
   " quality and detail.",
   ]));
   set_door("door",RPATH3+"3one32","southwest",0);
   set_exits( (["east":RPATH3+"3one26",
      "southwest":RPATH3+"3one32"]) );
}
