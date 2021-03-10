#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "You have entered a pleasant living room area of an elven home."+
   " There is a tan L-shaped couch in the middle of the room. A"+
   " cream colored coffee table sits in front of it with a bowl"+
   " filled with colored spheres of glass. The center of the roof"+
   " is flat and a stained glass image of a rainbow lets the light"+
   " come in, making the spheres shine. On the north wall is a"+
   " dragonfly hangs, wrought from stained glass and bronze. In the"+
   " southwest corner of the room is a small piano with a padded bench."+
   " A door leads to the room on the west and a cream silk curtain"+
   " covers the doorway to the south."); 
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","The wind rustles through the leaves outside.");
   set_items(([
   ({"couch","tan couch"}) : "There is a couch made of tan suede"+
   " that sits in the center of the room. It is shaped like a large"+
   " L, and could probably fit eight or more elves comfortably.",
   ({"table","coffee table","cream table"}) : "A wooden coffee table"+
   " has been painted a cream color and sits in front of the couch in"+
   " the center of the room. A bowl of multi-colored spheres sits on"+
   " top of it.",
   ({"bowl","spheres","colored spheres"}) : "%^BOLD%^A crystal bowl"+
   " filled with several differen colored spheres sits on top of the"+
   " coffee table. There are many spheres, each about two inches in"+
   " diameter and appear to have been made from blown glass. They"+
   " are in every color of the rainbow and they catch the light quite"+
   " beautifully.%^RESET%^",
   ({"roof","ceiling","stained glass"}) : "The roof comes to a flat"+
   " point in the very center of it. A rectangular piece of stained"+
   " glass has been placed there, letting natural light fill the room."+
   " The glass is a light blue with the image of a rainbow arching"+
   " across it.",
   ({"dragonfly","north wall"}) : "On the north wall hangs a dragonfly"+
   " made from stained glass and bronze. It has pearly wings and"+
   " an opaque brown body and is very lovely.",
   ({"small piano","piano"}) : "A small piano rests in the southwest"+
   " corner. It seems in fine shape and probably gets quite a bit"+
   " of use, especially during elven gatherings here.",
   ({"bench","padded bench"}) : "A padded bench sits in front of the"+
   " piano.",
   ({"curtain","silk curtain","cream curtain"}) : "A cream silk curtain"+
   " hangs over the doorway to the south, providing some amount of"+
   " privacy and separation.",
   ]));
   set_door("rainbow door",RPATH3+"3two14","northeast",0);
   set_door("door",RPATH3+"3two17","west",0);
   set_exits( (["northeast":RPATH3+"3two14",
      "south":RPATH3+"3two21",
      "west":RPATH3+"3two17"]) );
}
