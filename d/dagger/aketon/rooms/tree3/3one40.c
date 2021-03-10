#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "You have walked into a rather extravagantly decorated elven home."+
   " In the center of the room are two small white couches that are"+
   " angled in a V shape that faces the door. There is a white marble"+
   " coffee table between the couches and a beautiful rug rests"+
   " beneath it. Along the walls are fixed porcelain plates with"+
   " delicate artwork that has been painted on them. The room is quite"+
   " large and beyond the couches is a large oak dining table that"+
   " has eight seats and place settings are already out. In the center"+
   " of the table is a large gold candelabra with beeswax candles. There"+
   " is another door to the south.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest");
   set_listen("default","The wind rustles through the leaves outside.");
   set_items(([
   ({"couches","white couches"}) : "%^BOLD%^There are two couches that"+
   " face the entrance, both look as though they would fit two elves"+
   " comfortably, perhaps three if they got along very well. Even though"+
   " they are white, they're absolutely spotless. They also look quite"+
   " comfortable.",
   ({"coffee table","marble table","white table","marble coffee table"}) : "%^BOLD%^A"+
   " large white marble coffee table rests between the two couches. It"+
   " is rectangular in shape and looks rather heavy, it's amazing they"+
   " got it up all those stairs!",
   "rug" : "There is a beautiful rug that is underneath the coffee"+
   " table. It has a dark blue background and has peach roses that"+
   " ring the edges. It is very elegant.",
   ({"porcelain plates","plates","walls"}) : "%^BOLD%^There are several"+
   " porcelain plates attached to the walls about the room. Each has"+
   " been carefully painted with delicate brush strokes. You see one"+
   " with a red dragon breathing fire on it, another shows the rare"+
   " quotal serpent, a third has a white unicorn standing on a field"+
   " of green, while the fourth shows a mountain in the background"+
   " with a lake in the forefront reflecting back the image of the"+
   " mountain. Each is done in so much detail that it's incredible.",
   ({"table","dining table"}) : "There is a large dining table in the"+
   " back of the room that has seats for eight. Place mats, dishes, and"+
   " silverware are already laid out. There is a large candelabra in"+
   " the center of the table.",
   "chairs" : "Eight matching chairs with high backs and white cushions"+
   " surround the table.",
   "candelabra" : "%^YELLOW%^There is a beautiful golden candelabra"+
   " in the center of the dining table. It holds eight white beeswax"+
   " candles, none of which have ever been burned.",
   ({"candles","beeswax candles"}) : "%^BOLD%^Eight beeswax candles"+
   " are in the candelabra. They are all a pure white with white wicks"+
   " that have never been near a flame.",
   ({"doors","double doors"}) : "There is a large pair of double doors"+
   " directly south of here that lead into an elven home.",
   "door" : "There is an oak door to the south that leads further into"+
   " the elven home.",
   ]));
   set_door("double doors",RPATH3+"3one36","north",0);
   set_door("door",RPATH3+"3one42","south",0);
   set_exits( (["north":RPATH3+"3one36",
      "south":RPATH3+"3one42"]) );
}
