#include <std.h>
#include <objects.h>

inherit ROOM;

void create() 
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
  set_light(2);
  set_indoors(1);
  set_short("Toodles herbal shop");
  set_long("%^RESET%^%^CYAN%^This shop is definatly a stroke of luck for you, "+
	   "Adventurer. It looks like Toodle's here sells %^RESET%^healing potions%^CYAN%^ and "+
	   "%^RESET%^antidotes%^CYAN%^ for poisoning. The shop carries mixed scents of various "+
	   "%^GREEN%^herbs%^RESET%^%^CYAN%^ and potions, and looking at the %^ORANGE%^shelves%^CYAN%^ you see them "+
	   "stocked with many strange things indeed. Typing %^YELLOW%^<list>%^RESET%^%^CYAN%^ will show you "+
	   "what is currently available.\n");
  set_smell("default", "The room smells of many different herbs and potions.");
  set_listen("default", "You can hear things bubbling and the caw of a crow.");
  set_exits( ([
	       "out" : "/d/koenig/town/room11"
	   ]) );
  set_items( ([
	       "shelves" : "You can see many different kinds of herbs, potions, and scrolls."
	   ]) );
}

void reset()
{
  ::reset();
  if(!present("toodles"))
    new("/d/koenig/town/mon/toodles.c")->move(this_object());
}

