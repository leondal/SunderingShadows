#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "You are standing in an elven bedroom, or at least, what serves as"+
   " a bedroom. There is no bed here, merely two comfortable chairs"+
   " towards the back of the room that sit on either side of the window"+
   " on the west wall. Since elves do not truly sleep, some of the"+
   " older ones have given up the luxury of a bed. The chairs appear"+
   " comfortable enough, they are made out of a dark walnut and have"+
   " pretty designs carved in the wood, as well as matching cushions"+
   " that have been embroidered with some very fine needlepoint. There"+
   " are wine colored curtains around the window, which faces out to"+
   " overlook the forest. There are shelves filled with books along"+
   " the south wall and there is a wooden closet with fine clothes"+
   " on the north wall. The doorway is framed with some needlepoint"+
   " tapestries.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear the wind whistling through the leaves outside.");
   set_items(([
   ({"chair","chairs","walnut chairs","cushions"}) : "There are two"+
   " matching walnut chairs that face out the window on the west wall."+
   " There are ornate carvings of flowers and vines in the wood, and the"+
   " arms of the chairs end in three petals. The chairs are padded"+
   " with velvet burgundy cushions that have a fine piece of needlework"+
   " sewn in the center. The needlework shows a beautiful garden scene"+
   " with a few butterflies fluttering around a fountain.",
   ({"curtains","wine curtains"}) : "%^MAGENTA%^The curtains are wine"+
   " colored and they nicely frame the window.",
   ({"shelves","books","bookshelves","book shelves"}) : "There is a set"+
   " of bookshelves along the south wall that is filled with many books."+
   " Most of them appear rather uninteresting and quite ancient.",
   ({"closet","wooden closet"}) : "There is a wooden closet along the"+
   " north wall that holds a fine selection of both men and women's"+
   " clothing.",
   "clothes" : "The clothes are of very fine quality, but they are not"+
   " too fancy. You can see both men and women's clothing in there.",
   "window" : "The window gives you an exquisite view of the surrounding"+
   " forest, but for some it is a little too high up.",
   ({"tapestries","needlepoint tapestries"}) : "Two matching tapestries"+
   " frame the doorway. They have a deep wine border and the tapestries"+
   " match perfectly. They depict two purple roses, one on either side,"+
   " and are complete to the tiniest detail. You can see the thorns and"+
   " even the veins of the leaves and petals. It is truly magnificent work.",
   "door" : "The door is made of cedar wood and it leads to the east."+
   " Two needlepoint tapestries are draped elegantly on either side of"+
   " the door.",
   ]));
   set_door("door",RPATH3+"3one34","east",0);
   set_exits( (["east":RPATH3+"3one34"]) );
}
