#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A Kitchen");
set_long("%^RESET%^%^RED%^OOOOOOOkkkk, this kitchen is almost as bad, if not worse, than the restaraunt in town. Looking around, you notice %^ORANGE%^shelves%^RESET%^%^RED%^ stacked with %^RESET%^%^BOLD%^silver platters%^RESET%^%^RED%^ and %^YELLOW%^golden goblets%^RESET%^%^RED%^. One goblet in particular catches your eye. There is a %^ORANGE%^large table%^RESET%^%^RED%^ here that has many serving dishes being filled with various foods. If you dare, maybe taking a closer look or taste wouldn't be a bad idea. Then again, you never know who it is you might be tasting, huh?%^RESET%^\n");
  set_smell("default", "The rich and exotic smells now turn your stomach.");
  set_listen("default", "There is a lot of commotion here as if everyone is readying a feast fit for a king.");
  set_items( ([
     "shelves" : "There are many silver platters and golden goblets lined and stacked upon these shelves.",
     "platters" : "They are made of purest silver.",
     "goblets" : "They are definatly made of pure gold!",
     "goblet" : "This one goblet is the most unique, it is the only one set with jewels.",
     "jewels" : "So many different ones...sheesh...too bad you cant take it and sell it :(",
     "serving dishes" : "Most contain food while others await to be filled.",
     "foods" : "Well maybe tasting isn't a good idea, as you look you can tell it use to be someone or someones...one serving platter catches your attention and horrorifies you!",
     "platter" : "SWEET LORDS OF LIGHT! They have roasted someone up like one of SANE mind would do a pig...apple in mouth and all..."
]) );
  set_exits( ([
     "north" : "/d/koenig/town/kitchen1",
     "east" : "/d/koenig/town/kitchen4"
]) );
}
void reset()
{
  ::reset();
  if(!present("underling"))
  {
  new("/d/koenig/town/mon/assunder2.c")->move(this_object());
  new("/d/koenig/town/mon/assunder2.c")->move(this_object());
  }
}
