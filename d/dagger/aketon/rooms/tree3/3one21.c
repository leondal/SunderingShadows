#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "There is a small bed tucked into the southeast corner, it has"+
   " a quilted blanket on top and a few feather pillows. There is a"+
   " short bookshelf along the south wall that is filled with some"+
   " toys and stuffed animals instead of books, and they are all"+
   " neatly put away. On the north wall is a low window with a flat"+
   " desk in front of it. A small cushioned chair is near the desk."+
   " There are some water colored pictures of the forest surrounding"+
   " Aketon and the various large trees that make up the city on the"+
   " walls. This is obviously the room of a young elven child.");
   set_smell("default","The room smells faintly of something sweet.");
   set_listen("default","The wind rustles through the leaves oustide.");
   set_items(([
   "bed" : "There is a small bed tucked into the southeast corner of"+
   " the room. It is covered in a beautiful quilt and has two"+
   " feathered pillows.",
   "quilt" : "A beautiful quilt covers the bed in the southeast"+
   " corner of the room. It is well made and has varying intricate"+
   " patterns. It appears soft and warm.",
   ({"bookshelf","book shelf","short bookshelf"}) : "There is a short"+
   " bookshelf only two and a half feet in height along the south wall"+
   " of the room. It is filled with toys and games instead of books,"+
   " however.",
   "toys" : "All of the toys are carefully put away on the bookshelf,"+
   " quite unlike the room of a normal human child.",
   "window" : "%^BOLD%^%^CYAN%^There is a low window on the north wall"+
   " that even a dwarf could easily see out of. It shows the forest"+
   " to the north and east of Aketon, and in the distance to the north"+
   " you can see another of the great trees that the city is built in.%^RESET%^",
   "desk" : "There is a flat oak desk on the north wall in front of the"+
   " window. A small oak chair sits next to it, and both are obviously"+
   " made for the small stature of a child.",
   ({"chair","cushioned chair"}) : "There is a small padded oak chair"+
   " that sits near the desk on the north wall.",
   "pictures" : "%^BOLD%^%^GREEN%^Several water colored pictures of"+
   " the forest surrounding Aketon, as well as the larger trees that"+
   " make up the city, hang on the walls here. The artwork is decent"+
   " but not of the typical elven standard, and was probably done by"+
   " the child that lives in this room.%^RESET%^",
   ]));
   set_door("oak door",RPATH3+"3one20","west",0);
   set_exits( (["west":RPATH3+"3one20"]) );
}
