#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "You have walked into a small den in one of the elven homes. There"+
   " is a brick fireplace on the eastern wall that has illusory flames"+
   " dancing inside of it, giving off light but no heat. Above the"+
   " fireplace is an oil painting of a deer. In the center of the room"+
   " is a maple coffee table and there is a deep forest green couch next"+
   " to it. On the west wall a large bearskin has been stretched out,"+
   " the head is still attached and it looks quite fierce. To the north"+
   " is another door. Overall the room is rather cozy.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","The wind rustles through the leaves outside.");
   set_items(([
   "fireplace" : "There is a brick fireplace on the east wall. It looks"+
   " fairly real and inviting, but you notice that it gives off no heat"+
   " and the fire is really only a pretty illusion. Having a real"+
   " fireplace in a tree probably wouldn't be such a great idea anyway.",
   ({"fire","flames","illusion","illusory fire"}) : "%^BOLD%^%^RED%^The"+
   " flames dance about almost hypnotically. They are quite pretty and"+
   " seem very real, except that there is no smoke or heat coming from"+
   " the fire, nor do they consume the logs that they dance upon.%^RESET%^",
   ({"table","coffee table","maple table","maple coffee table"}) : "%^RED%^The"+
   " maple coffee table sits in the center of the room. It is an oval"+
   " shape and the wood has been stained dark and varnished so that"+
   " it shines, catching the light of the illusory fire.%^RESET%^",
   ({"couch","green couch","forest green couch"}) : "%^GREEN%^The couch"+
   " is a dark forest green shade. It is quite large and actually curves"+
   " into a semi-circular shape. It could probably hold four humans,"+
   " possibly six elves. It looks very comfortable.%^RESET%^",
   ({"painting","oil painting"}) : "There is a large oil painting set"+
   " in a maple wood frame on the wall above the fireplace. It is a"+
   " picture of a buck running wild through the forest, leaping over a"+
   " fallen log.",
   ({"bearskin","skin","bear","west wall"}) : "There is a large bearskin"+
   " stretched diagonally along the west wall. It is obviously a"+
   " grizzly bear and was probably over nine feet tall when it was"+
   " alive. The head is still attached and it looks quite fierce and"+
   " angry, it was probably a man eater.",
   ]));
   set_door("door",RPATH3+"3one2","north",0);
   set_door("maple door",RPATH3+"3one11","southwest",0);
   set_exits( (["north":RPATH3+"3one2",
      "southwest":RPATH3+"3one11"]) );
}
