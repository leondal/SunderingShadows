#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "You are standing in a secluded study. You get the impression that"+
   " this room is cut off from everything else somehow. The walls are"+
   " very thick and there is no window in the room. There is a desk"+
   " tucked into the southwest corner, and bookshelves run along the"+
   " western wall. The books on the shelves seem to be mostly about"+
   " wildlife and many other animals. On the east half of the room"+
   " is a large collection of pelts that are all carefully labeled."+
   " The pelt of a snow leopard is spread out on the east wall. A"+
   " thick rug covers the middle of the room.");
   set_smell("default","The room smells of animal pelts.");
   set_listen("default","The room is absolutely silent.");
   set_items(([
   ({"desk","maple desk"}) : "%^RED%^The desk is made of maple wood"+
   " and is tucked into the southwest corner. There is a candle on top"+
   " of it that has gotten a lot of use. It is a small but tidy desk"+
   " and there are several charcoal sketches of different animals in"+
   " a neat pile.",
   ({"shelves","bookshelves","books"}) : "The bookshelves are along"+
   " the west wall. All the books seem to be about nature, mostly"+
   " concerning wildlife and various types of animals and species in"+
   " all kinds of climates.",
   "pelts" : "There are quite a lot of pelts on the east side of the"+
   " room. They are all carefully labeled, and they are probably even"+
   " organized somehow. It looks as though most of the pelts are older,"+
   " probably they weren't taken until the animal had died of natural"+
   " causes.",
   ({"snow leopard","leopard","pelt","leopard pelt","east wall"}) : "%^BOLD%^On"+
   " the east wall the pelt of a snow leopard has been stretched out."+
   " It is thick and beautiful, a snowy white with black spots every"+
   " so often. The animal is supposed to blend into the snow very well,"+
   " but how one of its pelts got down here is unknown.",
   "rug" : "There is a large square rug in the center of the room. It"+
   " is well woven and very worn. The pattern is simply squares within"+
   " squares of varying colors, mostly shades of brown and green.",
   ]));
   set_door("door",RPATH3+"3one5","south",0);
   set_exits( (["south":RPATH3+"3one5"]) );
}
