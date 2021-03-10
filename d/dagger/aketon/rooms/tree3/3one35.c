#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "You are standing in the living room of an elven home. The floors"+
   " and walls are made of a very light oak and the room is more of"+
   " an octagon than anything else. There is a large pine table in"+
   " the center, surrounded by six matching pine chairs. In the"+
   " middle of the table is a vase of lilies that seem to further"+
   " brighten up this large room. A trellis of white roses stretches"+
   " along the east and west walls, and you can see a rectangle of rich"+
   " soil in a box on the floor that the roses grow out of. A curtain"+
   " of white silk hangs over the doorway to the southeast.");
   set_smell("default","The scent of roses is light and pleasant.");
   set_listen("default","The wind rustles through the leaves.");
   set_items(([
   ({"table","pine table"}) : "There is a large, circular table made"+
   " of light pine wood in the center of the room. Six matching chairs"+
   " surround it and there is a vase of lilies on its center.",
   ({"chairs","pine chairs"}) : "There are six matching pine chairs that"+
   " surround the table in the center of the room. They all have high"+
   " backs and appear comfortable enough, even though they aren't"+
   " cushioned.",
   "vase" : "There is a simple crystal vase that grows larger as it"+
   " reaches upwards and is in a squarish shape. It holds several"+
   " beautiful white lilies.",
   "lilies" : "%^BOLD%^The lilies are the purest white and are quite"+
   " large and very lovely. They stand out proudly on the center of"+
   " the table, and brighten the room even more.",
   ({"roses","white roses"}) : "%^BOLD%^Several miniature roses grow"+
   " from rectangles of soil that are along the west and east walls,"+
   " they have carefully climbed their way up a long trellis and"+
   " are very beautiful.",
   ({"walls","west wall","east wall","trellis"}) : "There is a trellis"+
   " along the west and east walls that miniature white roses have"+
   " grown along.",
   ({"curtain","silk curtain","white curtain","white silk curtain"}) : "%^BOLD%^A"+
   " curtain of fine white silk hangs across the doorway to the southeast.",
   "pine door" : "The door is made of light pine wood and it leads"+
   " back out to the main branches of the third tree of Aketon.",
   ]));
   set_door("pine door",RPATH3+"3one30","north",0);
   set_exits( (["north":RPATH3+"3one30",
      "southeast":RPATH3+"3one39"]) );
}
