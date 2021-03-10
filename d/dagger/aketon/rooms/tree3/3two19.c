#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "The walls of this simple home have been made from the branches of the"+
   " living oak wherein this abode is found. Carefully fashioned with"+
   " the use of natural magic, the limbs are joined together seamlessly"+
   " in a warm display of rich dark browns and light airy bronzes. Leaves"+
   " from the tree further enhance the beauty with each season, ranging"+
   " from brilliant %^BOLD%^%^GREEN%^spring green%^RESET%^ to the deep"+
   " %^BOLD%^%^RED%^reds%^RESET%^ and %^YELLOW%^golds%^RESET%^ of autumn,"+
   " forming a canopy above to block out the elements of the year. A"+
   " charmingly made, woven reed rug covers the floor, dyed in a swirling"+
   " pattern of green, carmine and ocher. The furniture that fills this"+
   " room is of a simple design, keeping with the warm inviting feeling"+
   " that permeates the whole of the house. At the far end of the room"+
   " is a cot, covered in an elegant %^GREEN%^forest green%^RESET%^ bed"+
   " spread and %^BOLD%^white pillows%^RESET%^, while across the room a"+
   " table with a few chairs offers an inviting place to rest and enjoy"+
   " a selection from the fruit basket atop it. At the foot of the cot is"+
   " an ornately carved chest made from a rare %^YELLOW%^golden wood%^RESET%^"+
   " which seems almost magical in nature as its carvings of the"+
   " %^BOLD%^%^MAGENTA%^rising dawn%^RESET%^ seem to almost %^YELLOW%^glow%^RESET%^."+
   " Against the near wall, to your side, is a beautifully carved oak"+
   " bookshelf on which there are a number of books and scrolls.");
   set_smell("default","You are calmed by the rich splendor of forest smells.");
   set_listen("default","The wind rustles through the leaves outside.");
   set_door("redwood door",RPATH3+"3two14","north","kaarells_key");
   set_locked("redwood door",1);
   set_door("door",RPATH3+"3two22","south","kaarells_key");
   set_exits( (["north":RPATH3+"3two14",
      "southeast":RPATH3+"3two23",
      "south":RPATH3+"3two22"]) );
}
