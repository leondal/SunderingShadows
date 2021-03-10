#include <std.h>
#include "keep.h"
inherit VAULT;

int FOUND;

void create()
{
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",1);
   set_short("A mage's study");
   set_long(
   "You have entered what appears to be the study room of a mage. There are"+
   " bookshelves lining the southern and eastern walls. A large walnut desk"+
   " is on the north wall with a matching chair. There are several candle stubs"+
   " on the desk, along with some parchment and a dried up ink well. A thick wool"+
   " rug is in the center of the room and there is a painting on the western"+
   " wall. One thing you notice is that nothing in the room appears to be aged"+
   " or covered in dust like you might expect."
   );
   set_smell("default","The smell of parchment fills the room.");
   set_listen("default","Everything is fairly quiet here.");
   set_items(([
   "floor" : "The floor is fairly free of dust and there is a large wool rug in"+
   " the center.",
   ({"rug","wool rug"}) : "%^YELLOW%^The wool rug looks incredibly thick and"+
   " soft.",
   ({"desk","walnut desk"}) : "The walnut desk is in excellent condition. There"+
   " are still a few sheets of parchment on top, along with a dried up ink well"+
   " and quill. Several candle stubs that have been burned down to nothing attest"+
   " to the fact that this desk must have gotten some use at one point. There are"+
   " also a couple of drawers on one side of the desk, they probably just hold"+
   " extra parchment and such.",
   "drawers" : "The desk has a few drawers that are closed. They probably just hold"+
   " parchment and other such supplies, but you never know. If you're really curious"+
   " you could always try searching them.",
   ({"chair","walnut chair"}) : "The walnut chair matches the desk perfectly,"+
   " it is padded with thick cushions and must be comfortable to sit on.",
   ({"candle","candle stubs"}) : "There are at least half a dozen candle stubs"+
   " on top of the desk, they've been burned down to nothing.",
   "bookshelves" : "There are two bookshelves here, one on the east and one on"+
   " the south, you can pick one to get a closer look if you want.",
   ({"east bookshelf","eastern bookshelf","bookshelf 1"}) : "The bookshelf along"+
   " the eastern wall is filled with many different types of books. You see"+
   " some ranging from histories of various lands, to theories of weather, books"+
   " on plants and animals, and many other strange subjects.",
   ({"south bookshelf","southern bookshelf","bookshelf 2"}) : "The books on this"+
   " shelf are mostly large leather-bound volumes. There appear to be many maps"+
   " and several books that you assume are of magic, but the runes move"+
   " around too quickly for you to read. One particular black book on the far side of"+
   " one of the top shelves stands out, it is fairly large and is bound entirely"+
   " in black leather with no title on the spine.",
   "books" : "There are many books in the room here, some on the east bookshelf"+
   " and some on the south bookshelf.",
   ({"book","black book"}) : "This book stands out among the rest, it is large"+
   " and bound in black leather with no title displayed on the spine. On closer"+
   " inspection you find that it doesn't really seem to be a book at all, but a"+
   " carefully hidden lever!",
   "lever" : "The black book is actually a carefully concealed lever, perhaps"+
   " you should pull it and see what happens?",
   "painting" : "There is a large and beautiful oil painting on the western wall."+
   " It is of a hedge maze with a large tower in the center of the maze and is"+
   " hung in a beautiful walnut frame.",
   "door" : "There is a sturdy looking walnut door that leads back to the guard"+
   " barracks.",
   ]));
   set_search("drawers",(:TO,"search_drawers":));
   set_exits(([
   "west" : ROOMS+"floor4",
   ]));
   set_door("door",ROOMS+"floor4","west","keep master_key");
}

void init()
{
   ::init();
   add_action("pull","pull");
}

void reset()
{
   ::reset();
   set_exits((["west" : ROOMS+"floor4"]));
   FOUND = 0;
}

void pull(string str)
{
   if(str != "book" && str != "lever")
      return notify_fail("Pull what?\n");
   if(member_array("south",ETP->query_exits()) != -1) {
      tell_object(TP,"You pull the lever and the bookshelf slides shut and closes"+
      " the secret passage.");
      tell_room(ETP,""+TPQCN+" pulls the lever and the bookshelf slides shut and"+
      " closes the secret passage.",TP);
      remove_exit("south");
      "/d/newbie/rooms/keep/floor6"->remove_exit("north");
      tell_room("/d/newbie/rooms/keep/floor6","A section of the wall slides"+
      " across to close the northern passage.");
      return 1;
   }
   else {
      tell_object(TP,"You pull the lever and the bookshelf slides to the right,"+
      " revealing a secret passage leading south.");
      tell_room(ETP,""+TPQCN+" pulls the lever and the bookshelf slides to the right,"+
      " revealing a secret passage leading south.",TP);
      add_exit(ROOMS+"floor6","south");
      "/d/newbie/rooms/keep/floor6"->add_exit(ROOMS+"floor5","north");
      tell_room("/d/newbie/rooms/keep/floor6","The northern wall slides to the"+
      " side to reveal a way out of the passage.");
      return 1;
   }
}

int search_drawers(string str)
{
   if(FOUND == 1) {
      tell_object(TP,"You search through the drawers and find nothing of interest,"+
      " but it does appear as though someone has already searched through here, unless"+
      " the mage was highly disorganized.");
      tell_room(ETP,""+TPQCN+" searches through the drawers but doesn't seem to find anything.",TP);
      return 1;
   }
   tell_object(TP,"You search through the drawers and find a rather oddly shaped"+
   " stone.");
   tell_room(ETP,""+TPQCN+" searches through the drawers and appears to find something.",TP);
   new(OBJ2+"stone")->move(ETP);
   FOUND = 1;
   return 1;
}
