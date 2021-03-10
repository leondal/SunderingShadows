#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "You notice that the inside of the door on the south wall is also"+
   " painted with a large and brightly colored image of a humming"+
   " bird. In the center of the room is a very large white marble"+
   " statue of a prancing unicorn. On the east wall is a large"+
   " butterfly that has been outlined in bronze. On the west wall is"+
   " a window made out of stained glass that shows the image of a"+
   " blue sky with clouds with a red robin flying through the center."+
   " From the ceiling hang a few baskets of flowers, and in the center"+
   " the roof is made of glass, allowing you to stare up at the sky"+
   " and see the branches of the next level far above this one. To"+
   " the north is a white gauze curtain that separates the two rooms.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","The wind rustles through the leaves oustide.");
   set_items(([
   ({"statue","marble statue","unicorn"}) : "%^BOLD%^The center of the"+
   " room is dominated by a five foot tall white marble statue of a"+
   " unicorn. The unicorn's head is held high and his right front"+
   " leg and back left leg are lifted as he prances forward. The"+
   " detail is remarkable and you almost expect him to walk right"+
   " off the marble pedestal he's on.%^RESET%^",
   ({"butterfly","east wall","bronze butterfly"}) : "%^ORANGE%^There"+
   " is a large bronze metalwork of a butterfly. It outlines the body,"+
   " wings, and antennae, with a few stripes and circles for patterns"+
   " on the wings. It spans nearly six feet wide and it is hard to tell"+
   " where the metal was welded to another piece, it is so smooth.%^RESET%^",
   ({"window","stained glass"}) : "%^BOLD%^%^CYAN%^There is a large"+
   " stained glass window on the west wall. It shows the scene of a"+
   " sky with several fluffy %^WHITE%^clouds%^CYAN%^ and a"+
   " %^RED%^red robin%^CYAN%^ flying through the center.%^RESET%^",
   ({"flowers","hanging flowers"}) : "There are baskets of hanging"+
   " flowers that dangle down from the ceiling by chains. Many of"+
   " them are impatients, but there are pansies and marigolds as"+
   " well. They are all bright and pretty, if not very fragrant.",
   ({"ceiling","roof","glass"}) : "The center of the ceiling is made"+
   " of glass, allowing you to see up into the sky to the branches"+
   " on the next level above you.",
   ({"curtain","gauze curtain","white curtain"}) : "%^BOLD%^There is"+
   " a curtain of fine white gauze that hangs inbetween this room and"+
   " the one to the north.%^RESET%^",
   ]));
   set_door("painted door",RPATH3+"3one14","south",0);
   set_exits( (["north":RPATH3+"3one3",
      "south":RPATH3+"3one14"]) );
}
