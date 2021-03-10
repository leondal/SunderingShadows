#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_short("Balcony of an elven home");
   set_long("%^GREEN%^Balcony of an elven home%^RESET%^\n"+
   "You have walked out onto the balcony of an elven home. A flowing"+
   " railing of oak rings the edges, preventing anyone from falling off."+
   " The view from up here is incredible, you can look out over the"+
   " vast forest to the south, and to the west you see another of the"+
   " large trees that make up the city of Aketon. You notice that"+
   " you are quite high up here on the second level of the tree,"+
   " and yet the tree climbs higher still. There are some wind chimes"+
   " hanging on a nearby branch that create a nice melody when the wind"+
   " blows. A tile table sits out here with four chairs around it. The"+
   " image on the tiles is that of a flower covered hill with a rainbow"+
   " in the background of the sky. A potted yellow rose bush is to the"+
   " south of the doorway and is in full bloom. The roses give off such"+
   " a wonderful fragrance.");
   set_smell("default","The scent of roses fills the air.");
   set_listen("default","The wind chimes tinkle merrily in the breeze.");
   set_smell("roses","%^YELLOW%^The roses smell divine.%^RESET%^");
   set_items(([
   "railing" : "There is a flowing oak railing that circles the"+
   " perimeter of the balcony. The wood has been carved out into a"+
   " ripple on the top for a smooth effect. It appears sturdy enough"+
   " but you probably wouldn't want to test it with your full weight.",
   ({"chimes","wind chimes"}) : "There is a set of brass wind chimes"+
   " hanging from a nearby branch. There are different sized cylinders"+
   " that make different pitched noises when they clank together,"+
   " meshing into a beautiful melody. From the center hangs a"+
   " a brass dragonfly that rings the higher notes.",
   ({"table","tile table"}) : "The table on the north side of the"+
   " balcony has a top that is covered in painted tiles. The tiles"+
   " show the image of a large hill that is covered in flowers. There"+
   " are several clouds above, and in the background of the sky you"+
   " notice a rainbow.",
   ({"rose","rose bush","yellow rose","roses"}) : "%^YELLOW%^The"+
   " rose bush that is growing from a large ceramic pot on the south"+
   " side near the doorway is most certainly in full bloom. The roses"+
   " are quite large and give off a wonderful fragrance.%^RESET%^",
   ]));
   set_door("door",RPATH3+"3two18","east",0);
   set_exits( (["east":RPATH3+"3two18"]) );
}
