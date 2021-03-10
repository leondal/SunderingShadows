#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("A balcony of Aketon");
   set_long("%^GREEN%^A balcony of Aketon%^RESET%^\n"+
   "You are standing on a small platform that has a railing running"+
   " around the edges of it to make sure people don't fall off. A"+
   " pretty vine with some large white flowers is wrapped around the"+
   " railing. The balcony provides a beautiful view of the forest to the"+
   " east of Aketon, and you can see another large tree in the distance"+
   " to the north. Two ornately carved wooden benches are here, and"+
   " there is a large harp in the center that the elves like to gather"+
   " around and play. This is a peaceful spot for a nice gathering of"+
   " friends, or even strangers.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","You hear the wind whistling through the leaves.");
   set_smell("flowers","%^BOLD%^The flowers have a light but intoxicating fragrance.");
   set_items(([
   "railing" : "There is a protective railing that surrounds this"+
   " little balcony, mostly preventing any elven children that may not"+
   " be too old from falling off than protection for the adult elves."+
   " A vine of some sort with large white flowers has wrapped itself"+
   " around the top of the balcony.",
   "vine" : "%^GREEN%^A large vine of dark green has wrapped itself"+
   " around the top of the balcony. It has leafy green leaves and"+
   " several large %^BOLD%^%^WHITE%^white flowers%^RESET%^%^GREEN%^ that"+
   " give off a pleasant smell.",
   "flowers" : "%^BOLD%^The flowers are rather large for the tiny vine"+
   " and they have six white petals with a yellow stem in the very"+
   " center. They give off a wonderful fragrance.",
   ({"benches","wooden benches"}) : "There are two wooden benches here"+
   " that have been carefully and exquisitely carved. The bottom part"+
   " of the benches resembles a large leaf, the feet turn into small"+
   " toadstools. The backs of the benches are carved out in the center"+
   " to show a butterfly, and there are flowers engraved on the edges.",
   "harp" : "There is a large harp in the center of the balcony that"+
   " is too big to actually move. It has been magically enchanted to"+
   " withstand the elements, and always seems to be perfectly tuned."+
   " Elves will often gather around this area and one will play the"+
   " harp while the rest relax and enjoy the scenery and good music.",
   ]));
   set_exits( (["southwest":RPATH3+"3one14"]) );
}
