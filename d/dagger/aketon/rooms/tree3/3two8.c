#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "The walls of this house have been carved with various images of"+
   " animals and plants and then painted for a beautiful effect."+
   " There is a bright sunburst on this side of the door as well,"+
   " but this one has been brushed with golden paint. A woven rug"+
   " greens and blues has been stretched out across the middle of the"+
   " floor and has animal designs running around the edges of it."+
   " An enormous cushion of dark green is on the north side of the"+
   " room with a dainty willow coffee table to the right of it that"+
   " appears to serve as an eating table judging by the basket of"+
   " fruit and glasses that have been left on it. On the south side"+
   " of the room is a large mahogany bookshelf filled with religious"+
   " tomes and myths, mostly devoted to the woodland gods and goddesses."+
   " There is a large sunstone on one shelf that has been carved with"+
   " the image of a rising sun. A door to the east leads to the"+
   " next room.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","The wind rustles through the leaves outside.");
   set_items(([
   ({"walls","carvings"}) : "The walls are carved with various images"+
   " of plants and animals. Birds soar through the upper reaches of"+
   " the walls with white clouds etched out, while the other animals"+
   " mostly run along the wall near the floor, with bushes and plants"+
   " growing upwards. Some of the birds have rested in trees that reach"+
   " almost to the ceiling. All the carved images have been painted"+
   " and the entire effect is dazzling.",
   ({"rug","woven rug"}) : "A rectangular rug stretches across the"+
   " center of the room. It is mostly colored in greens and blues"+
   " and has animal images running around the borders.",
   ({"cushion","green cushion"}) : "%^GREEN%^An enormous and plush"+
   " green cushion takes up a fair bit of the north side of the room."+
   " It is almost as large as a small bed, and someone could recline"+
   " there quite easily.%^RESET%^",
   ({"coffee table","willow table"}) : "A dainty willow coffee table"+
   " that is a bit on the short side sits next to the large green"+
   " cushion. It is apparently used as a dining table, for it has a"+
   " basket of fruit on top as well as a couple of glasses.",
   ({"basket","fruit","fruit basket"}) : "A basket of seasonal fruit"+
   " sits on top of the coffee table.",
   "glasses" : "There are several empty glasses sitting on the coffee"+
   " table.",
   "bookshelf" : "A large bookshelf takes up the south wall of the room."+
   " It appears to contain many religious tomes and myths, mostly of"+
   " the woodland gods and goddesses. You notice several sections on"+
   " Mielikki, Eldath, and Silvanus in particular, as well as a couple"+
   " books on Grumbar. There is a large section about Lathander towards"+
   " the top that seems to be more recent and has been left a fair"+
   " amount of room for expansion. In the middle of one of those shelves"+
   " is a large sunstone that has been carved with the image of a"+
   " rising sun.",
   "books" : "The books are large and very thick and you get the"+
   " feeling that you had better not disturb them. Many of the books"+
   " are religious and some are myths about many of the woodland gods"+
   " and goddesses. You notice several sections on Mielikki, Eldath,"+
   " and Silvanus in particular, as well as a couple books on Grumbar."+
   " There is a large section about Lathander towards the top that"+
   " seems to be more recent and has been left a fair amount of room"+
   " for expansion.",
   "sunstone" : "%^YELLOW%^There is a very large yellow sunstone"+
   " on the center of one of the bookshelves. It has been carved with"+
   " the image of a sun rising over the forest, with delicate rays"+
   " of light spreading out from it. It is very beautiful.%^RESET%^",
   ]));
   set_door("sunburst door",RPATH3+"3two10","southwest",0);
   set_door("door",RPATH3+"3two9","east",0);
   set_exits( (["east":RPATH3+"3two9",
      "southwest":RPATH3+"3two10"]) );
}
