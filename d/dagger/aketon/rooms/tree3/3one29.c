#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven house of Aketon");
   set_long("%^GREEN%^An elven house of Aketon%^RESET%^\n"+
   "You are standing in an elven home, but it is decorated like a forest."+
   " The walls are painted murals of trees and a few larger potted plants"+
   " are set around the edges of the room. You notice green and brown"+
   " silk pillows in sections of the room, they blend in well with the"+
   " painted walls and floor so are hard to see. The ceiling is actually"+
   " just a network of smaller branches that has been carefully reinforced"+
   " with some extra leaves in places to keep the weather out. It keeps the"+
   " room nice and cool.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear the wind rustling through the leaves.");
   set_items(([
   ({"walls","floor"}) : "The walls and floor are painted in the likeness"+
   " of a forest, and it is sometimes hard to tell that they are walls and"+
   " that you're not actually in the middle of the woods somewhere.",
   "ceiling" : "The ceiling is actually just a weaving of some of the smaller"+
   " branches of the large tree, with reinforcement in some areas with larger"+
   " leaves to prevent bad weather from getting in.",
   ({"pillows","silk pillows"}) : "There are silk pillows in greens and browns"+
   " positioned around the room for people to lay down or sit on. They blend"+
   " in well with the walls and floor.",
   ({"plants","potted plants"}) : "There are growing plants in large pots in"+
   " the corners of the room, adding to the feeling of a real forest.",
   "green door" : "%^GREEN%^The door to the west is painted a green that"+
   " exactly matches the surrounding leaves on the branches.%^RESET%^",
   ]));
   set_door("green door",RPATH3+"3one30","east",0);
   set_exits( (["east":RPATH3+"3one30",
      "west":RPATH3+"3one28"]) );
}
