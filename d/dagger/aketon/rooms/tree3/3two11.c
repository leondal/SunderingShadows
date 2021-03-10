#include "/d/dagger/aketon/short.h"

inherit VAULT;

int SEARCHED;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "You guess that it has been months at least since anyone was in"+
   " here to take care of the place. There is a very thin layer of"+
   " dust that covers the floor and almost everything in here. There"+
   " is a short bookshelf on the south wall that has a collection of"+
   " geods and semi-precious polished pieces of gemstone on top of it."+
   " The shelves themselves are filled with small statues and other"+
   " little trinkets from various parts of the land, none of them"+
   " overly valuable but they're pretty none the less. There are a"+
   " few beaten journals on the bottom shelves that look pretty old."+
   " On the north side of the room is a walnut desk with a chair."+
   " In the northeast corner is a tiny counter and sink, a table"+
   " with only one chair is on the east side of the room. There is a door"+
   " leading to the southeast.");
   set_smell("default","The room is a little dusty and the slight"+
   " hint of mildew has creeped in.");
   set_listen("default","The wind rustles through the leaves outside.");
   set_items(([
   "dust" : "%^ORANGE%^Dust covers everything in the entire room in"+
   " a light layer.%^RESET%^",
   "bookshelf" : "There is a short walnut bookshelf along the south"+
   " wall of the room. There are several geods and semi-precious stones"+
   " that have been polished sitting on top of it. Most of the other"+
   " shelves are filled with statues and trinkets from various parts"+
   " of the world, most of them are pretty but not very valuable. The"+
   " bottom shelf is filled with some old leather bound journals.",
   ({"stones","geods","statues","trinkets"}) : "Several geods of"+
   " varying colors and semi-precious stones of all sorts are on top"+
   " of the bookshelf. On the shelves are several statues made from"+
   " wood and polished stones, as well as some other trinkets such"+
   " as a wyvern's tooth, bracelets, and a small harmonica.",
   "journals" : "There are several large leather bound journals. Many"+
   " of them were probably passed down from older generations and"+
   " the archaic, twisting elven script is impossible to read. There"+
   " is an empty place where the most recent journal would be.",
   ({"desk","walnut desk"}) : "There is a fairly simple walnut desk"+
   " along the north wall. A feather quill and a dried up ink well"+
   " sit on top of it, as well as a thick layer of dust. There is a"+
   " candle that has been completely burned down to a stub in one"+
   " corner, and there is a small drawer in the center.",
   "chair" : "There is a walnut chair that matches the desk on the"+
   " north side of the room.",
   "drawer" : "There is a small drawer on the underside of the walnut"+
   " desk. Perhaps you could search it.",
   ({"counter","sink"}) : "There is a counter with a sink in the"+
   " northeast corner of the room. Neither have been used in some"+
   " time and dust covers them.",
   "table" : "There is a small but serviceable oak table on the east"+
   " side of the room with one chair near it. Both have been darkly"+
   " stained to better match the rest of the furniture.",
   ]));
   set_door("oak door",RPATH3+"3two10","west","aketon key");
   set_door("door",RPATH3+"3two16","southeast","aketon key");
   set_locked("oak door",1);
   set_locked("door",1);
   set_search("drawer",(:TO,"search_drawer":));
   set_exits( (["southeast":RPATH3+"3two16",
      "west":RPATH3+"3two10"]) );
}

void reset()
{
   ::reset();
   SEARCHED = 0;
}

int search_drawer()
{
   if(SEARCHED == 1) {
      tell_object(TP,"You search the drawer but fail to find anything.");
      tell_room(ETP,""+TPQCN+" searches the drawer but fails to find anything.",TP);
      return 1;
   }
   tell_object(TP,"You search the drawer and find a leather bound"+
   " journal inside!");
   tell_room(ETP,""+TPQCN+" searches the drawer and pulls out a"+
   " leather bound book.",TP);
   new("/d/dagger/aketon/obj/journal")->move(ETP);
   SEARCHED = 1;
   return 1;
}
