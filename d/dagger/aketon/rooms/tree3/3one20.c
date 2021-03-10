#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "This is a pretty elven home. There is a light blue couch along the"+
   " north wall with an ash coffee table in front of it. On the south"+
   " wall is a round dining table with four chairs around it. A bowl"+
   " of fruit rests in the middle of the table. Around the walls of"+
   " the room are hung several pictures of pressed flowers. A chest is"+
   " against the northeast wall and appears to hold clothing. There is"+
   " an oak door leading to the room to the east.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_listen("default","The wind rustles through the leaves oustide.");
   set_items(([
   ({"couch","blue couch","light blue couch"}) : "%^BOLD%^%^CYAN%^A"+
   " light blue couch rests along the north wall. It is well padded"+
   " and has two matching blue pillows, one on either end. It could"+
   " hold three elves comfortably.%^RESET%^",
   ({"coffee table","ash table"}) : "%^BOLD%^There is an ash coffee"+
   " table in front of the couch. You can see some faint rings on"+
   " the top that mark how old the tree it was cut from was. It has"+
   " been treated with some polish to make it scratch and stain"+
   " resistant.%^RESET%^",
   ({"table","round table","dining table"}) : "There is a round oak"+
   " dining table on the south side of the room. Four chairs are spread"+
   " around it and there is a bowl of fruit in the center of the table.",
   "chairs" : "Four oak chairs are seated around the dining table.",
   ({"bowl","fruit bowl","fruit"}) : "There is a pottery bowl that is"+
   " filled with various types of ripe fruit in the center of the"+
   " dining table.",
   ({"flowers","pictures","walls"}) : "Several pictures are scattered"+
   " about the walls. They all have nice frames and have a flower or"+
   " group of flowers pressed between two panes of glass. You notice"+
   " a rose, a daffodil, several daisies, and an iris.",
   "chest" : "There is a large wooden chest in the northeast corner"+
   " of the room that holds some clothes.",
   ]));
   set_door("door",RPATH3+"3one14","northwest",0);
   set_door("oak door",RPATH3+"3one21","east",0);
   set_exits( (["east":RPATH3+"3one21",
      "northwest":RPATH3+"3one14"]) );
}
