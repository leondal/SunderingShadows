#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("A rest area in Aketon");
   set_long("%^GREEN%^A rest area in Aketon%^RESET%^\n"+
   "You have come to the end of a branch in an area that is secluded by"+
   " many large leaves. You can see down to the ground, which is quite a"+
   " ways below you, but you are still only on the first level of the tree."+
   " This area is obviously used for rest and relaxation by the elves. There"+
   " are a few sections of the branches that seem to be perfect benches,"+
   " and many have been draped with silk to make them more comfortable. This"+
   " is a cozy place for the elves to meet and discuss things, listen to"+
   " singing or poetry, or just enjoy some peace and quiet.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","It is pleasantly quiet here.");
   set_items(([
   "silk" : "Several skeins of silk have been draped over branches that"+
   " have been formed into bench-like shapes for easy sitting.",
   "branches" : "Many of the branches come to an end here and have been"+
   " carved into bench-like shapes to allow for easy sitting.",
   ]));
   set_exits( (["southwest":RPATH3+"3one24"]) );
}
