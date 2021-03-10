#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "This is a very bright and airy room. There is a window on both"+
   " the east and west walls that have white curtains with a flower"+
   " pattern hung around them. Several paintings are hung about the"+
   " room as well, with garlands of flowers draped around them. A"+
   " large lilac bush is blooming in the northwest corner, with a small"+
   " dogwood tree stationed in the southeast corner. The center of"+
   " the room is filled with many large and soft pillows with a white"+
   " lambs wool rug underneath them. There is a doorway on the"+
   " northeast that leads to another section of the house.");
   set_smell("default","The scent of lilacs mixes with the forest smells.");
   set_listen("default","The wind rustles through the leaves.");
   set_items(([
   ({"window","windows"}) : "The west and east walls both have a"+
   " very large rectangular window in the center of them. White"+
   " curtains with a pretty flower pattern are hung around them."+
   " The view from the windows is incredible, the ground is very"+
   " far beneath you!",
   ({"curtains","white curtains","flower curtains"}) : "%^BOLD%^The"+
   " curtains are white and flowers have been carefully stitched on."+
   " There are some %^CYAN%^light blue%^WHITE%^ ones and %^MAGENTA%^baby"+
   " pink%^WHITE%^ones, as well as some %^RED%^red%^WHITE%^ and"+
   " %^YELLOW%^yellow%^WHITE%^ ones. They are all very pretty and"+
   " cheerful.%^RESET%^",
   "paintings" : "Paintings of flowers and garden scenes have been hung"+
   " about the room, further brightening this lively place. Around the"+
   " pictures fresh garlands of flowers have been draped, adding a nice"+
   " final touch.",
   ({"garlands","flowers"}) : "Garlands of flowers have been draped"+
   " around the paintings in this room. There are several different"+
   " types, ranging from variously colored bougainvilleas to primroses"+
   " and daisies.",
   ({"bush","lilac","lilac bush"}) : "%^BOLD%^%^MAGENTA%^A very full"+
   " lilac bush is in the northwest corner of the room. It is growing"+
   " from a large ceramic pot and probably won't be able to get too"+
   " much bigger. The blossoms fill the room with a nice fragrance.%^RESET%^",
   ({"tree","dogwood tree"}) : "%^BOLD%^%^GREEN%^A small dogwood tree is"+
   " growing in a pot in the southeastern corner of the room. It has a"+
   " few light green leaves and some delicate %^WHITE%^white"+
   " blossoms%^GREEN%^. It is not very old and will probably grow a"+
   " bit taller, even if it's kept in that pot.", 
   "pillows" : "%^BOLD%^Several pillows of varying shapes and sizes"+
   " are scattered on the rug in the center of the room. Most of them"+
   " are white, but there are a few %^MAGENTA%^pink%^WHITE%^ and"+
   " %^RESET%^%^MAGENTA%^purple%^BOLD%^%^WHITE%^ ones as well. The"+
   " pillows can be used for louning around on while talking to friends,"+
   " or for resting on during meditation.",
   ({"rug","wool rug","white rug","lambs wool rug"}) : "%^BOLD%^A large"+
   " and circular white lambs wool rug is spread out in the center of the"+
   " room. It is very soft and comfortable, and many pillows have been"+
   " placed on top of it.",
   ]));
   set_door("door",RPATH3+"3one17","south",0);
   set_exits( (["northeast":RPATH3+"3one6",
      "south":RPATH3+"3one17"]) );
}
