#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "This is a private room in an elven home. There is a closet full"+
   " of clothes against the east wall, with a large dresser next to"+
   " it. On the west wall is a large weaving loom that looks as though"+
   " the product is about half-finished. There is a window on the south"+
   " wall with a rocking chair near it and several instruments are"+
   " neatly lined up along the wall. You notice a small harp, a lute,"+
   " and a set of reed pipes. All the instruments are well taken"+
   " care of and seem to get used regularly.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","The wind rustles through the leaves outside.");
   set_items(([
   "closet" : "There is a large wooden closet along the east wall that"+
   " is filled with some rather eccentric clothing.",
   "dresser" : "There is a dresser next to the closet on the east wall"+
   " that seems to hold more normal clothing, as well as spools of"+
   " dyed material for the loom.",
   ({"loom","weaving","weaving loom"}) : "There is a loom set up along"+
   " the west wall. It appears as though the current project is only"+
   " half finished and you can't quite tell what it is supposed to be"+
   " yet.",
   "window" : "There is a window on the south wall that overlooks"+
   " the edge of the great tree. It is a long ways to the ground from"+
   " here, and this is only the first level!",
   ({"chair","rocking chair"}) : "There is a wooden rocking chair near"+
   " the window on the south wall. It looks comfortable enough and"+
   " there is a woven blanket that can be used as either padding or"+
   " for warmth.",
   "blanket" : "This is a simple blanket that is currently laying"+
   " along the back and seat of the chair for padding.",
   "instruments" : "There are several instruments lined up against the"+
   " south wall. They all appear to be in good shape and seem to be"+
   " frequently used.",
   "harp" : "The small harp is tuned perfectly. It is gilded in gold"+
   " and has tight and slender strings that intricate melodies can"+
   " be played on.",
   "lute" : "There is a wooden lute that appears to be quite old,"+
   " although well cared for. It is kept tuned and well oiled so that"+
   " the wood is kept in good shape.",
   ({"pipes","reed pipes"}) : "These are a pair of simple reed pipes"+
   " that have holes made for different notes. They are bound together"+
   " by some twine.",
   ]));
   set_exits( (["northeast":RPATH3+"3one10"]) );
}
