#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven house of Aketon");
   set_long("%^GREEN%^An elven house of Aketon%^RESET%^\n"+
   "This is apparently a workshop of some sort, quite a change from the"+
   " room to the east. There is a round table off to one side that could"+
   " serve as a dining area or as a work table. You see carving tools"+
   " carefully stored in the cabinets around the room, along with various"+
   " colors of paint in jars along the floor. There are a few blocks of"+
   " wood that are untouched, but apparently will be carved soon. There is"+
   " a curtain that separates this room from the one to the west.");
   set_smell("default","You are assaulted by the many smells of the "
      "forest.");
   set_items(([
   "curtain" : "%^GREEN%^There is a lovely silk curtain that hangs down"+
   " over the doorway to the west, giving the room some privacy.",
   "table" : "There is a small round table that has been pushed off to one"+
   " side of the room. There are two chairs currently next to it with two"+
   " more against the wall that could be used if the table weren't so near"+
   " the wall already. On top of the table are a few blocks of untouched wood.",
   "chairs" : "There are four simple wooden chairs that match the table.",
   ({"wood","wood blocks","blocks of wood"}) : "There are a few blocks of"+
   " uncarved wood here, waiting to become something.",
   "cabinets" : "There are cabinets along the north side of the room that"+
   " hold tools as well as dishes and silverware.",
   "tools" : "There are several various tools that are used to carve wood"+
   " neatly kept in the cabinets. You also notice various paint brushes.",
   ({"paint","jars","paint jars"}) : "There are jars of many different colors"+
   " of paint along the northern wall of the room. They are mostly in earth"+
   " tones, but there are a few other colors as well.",
   ]));
   set_listen("default","You hear the wind rustling through the leaves.");
   set_exits( (["east":RPATH3+"3one29",
      "west":RPATH3+"3one27"]) );
}
