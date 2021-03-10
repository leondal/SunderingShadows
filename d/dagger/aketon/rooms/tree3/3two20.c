#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("A balcony of Aketon");
   set_long("%^GREEN%^A balcony of Aketon%^RESET%^\n"+
   "You are standing on a wide circular platform that has been built"+
   " on top of the end of this large branch. There is no railing to"+
   " block the view here and you can see out over the tree tops of the"+
   " great forest that surrounds Aketon. The view is spectacular and"+
   " everything seems peaceful. There is a round table that is in the"+
   " center of the platform with two half-circle benches that are"+
   " around it. This is a nice gathering spot for the elves, and you"+
   " notice marks on the floor where the table and benches have been"+
   " moved to the edges so that the elves can dance in the center.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","The wind whispers through the leaves.");
   set_items(([
   ({"table","round table"}) : "There is a round wooden table in the"+
   " center of the platform, it is surrounded by two half-circle benches"+
   " and holds room for about eight elves.",
   "benches" : "There are two wooden benches that are curved into a"+
   " half-circle shape. They fit around the wooden table in the center"+
   " of the platform.",
   ]));
   set_exits( (["northwest":RPATH3+"3two15"]) );
}
