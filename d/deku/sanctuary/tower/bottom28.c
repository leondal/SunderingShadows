#include <std.h>
#include "../dragon.h";

inherit BBVAULT;

void create() {
   ::create();
   set_long(
      "%^BOLD%^%^BLACK%^This little room has only a few things in"+
      " it. There is a large chair pulled up to the back of a small"+
      " desk. To the east side of the room is a bookshelf and a painting"+
      " on the west wall."
   );
   set_items( ([
      "chair" : "This is a large soft chair.",
      "desk" : "The desk has a stack of papers and a quill laying in an ink jar.",
      "papers" : "There is a stack of papers laying on the table. You are unable to tell if there is anything important there at first glance.",
      "painting" : "This is a painting of a beautiful landscape, despite all the water damage of this bottom level, the painting seems intact",
      "bookshelf" : "The bookshelf is full of books with numerous topics.",
      "walls" : "The walls are cold, bare, and typical of an abandoned structure, except the %^BOLD%^%^BLACK%^wall above the painting%^RESET%^.",
      ({"above painting","above the painting","wall above the painting"}) : "The wall above the painting seems hollow, like a chute, when you inspect it. Perhaps further exploration of the tower will reveal its purpose?",
   ]) );
   set_exits( ([
      "door" : TOWER+"bottom21",
   ]) );
   set_door("door",TOWER+"bottom21","door","cellar key");
   set_search("painting", "Your attention is drawn to the wall above the painting.");
}

void reset() {
   ::reset();
   if(!present("greater warrior")) {
   new(MON+"g_undead")->move(TO);
   }
}
