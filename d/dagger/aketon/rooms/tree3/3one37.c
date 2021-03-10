#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "You step through the curtain and enter a home (for lack of a better"+
   " word) that is rather unique. There are only walls on two thirds"+
   " of the room, leaving the southeastern wall completely empty. It"+
   " provides a spectacular view if you're not afraid of heights. Near"+
   " the doorway is a large chest with a leather covering that has been"+
   " treated to withstand the elements, doubtlessly it holds whatever"+
   " possessions the owner of this place deems worth saving. There is"+
   " not much in the way of furniture here, a long wooden bench rests"+
   " against the northeast wall and there is a stool perched near the"+
   " southeastern edge.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","The wind rustles through the leaves.");
   set_items(([
   ({"curtain","green curtain"}) : "%^GREEN%^There is a mottled green"+
   " curtain that leads back to the rest of the sane world.",
   "chest" : "There is a large chest against the western wall near the"+
   " door that could easily double as a place to sit. It is covered"+
   " in leather and has been treated to withstand the elements. It"+
   " probably holds clothes and some keepsakes.",
   ({"bench","wooden bench","long bench"}) : "There is a long wooden"+
   " bench against the northeast wall that several people could sit on"+
   " or one person could lay down on.",
   "stool" : "There is a simple wooden stool that is perched near the"+
   " edge of the opening. From there you can sit and enjoy the view"+
   " if you're so inclined.",
   ]));
   set_exits( (["northwest":RPATH3+"3one32"]) );
}
