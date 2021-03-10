#include <std.h>
#include "../defs.h"
inherit ROOM;

void create()
{
  ::create();
   set_terrain(HUT);
   set_travel(DIRT_ROAD);
  set_property("indoors",1);
  set_property("light",1);
  set_climate("tropical");
  set_short("%^BOLD%^Within a Ruined Hut%^RESET%^");
  set_long("%^ORANGE%^The trunks from a few straight palm trees have been anchored "+
	"into the ground.  Four corner posts and one slightly taller trunk "+
	"in the middle help support the roof.  Well, what used to be the "+
	"roof at least.  You look up and watch a few clouds float across the "+
	"sky.  The roof, much like the walls, has lost many of its palm "+
	"fronds.  A few old, %^RESET%^dusty %^ORANGE%^clothes are bundled"+
	" along the walls.  It "+
	"looks like they were once used for beds.\n");
  set("night long","%^BLUE%^The trunks from a few straight palm trees have been "+
	"anchored "+
	"into the ground.  Four corner posts and one slightly taller trunk "+
	"in the middle help support the roof.  Well, what used to be the "+
	"roof at least.  %^BOLD%^%^WHITE%^Moonlight%^RESET%^%^BLUE%^"+
	" streams into the hut,  "+
	"providing a soft, gentle light.  The roof, much like the walls, "+
	"has lost many of its palm "+
	"fronds.  A few old, %^RESET%^dusty%^BLUE%^ clothes are bundled"+
	" along the walls.  It "+
	"looks like they were once used for beds.\n");       
  set_smell("default","%^BOLD%^%^BLUE%^Steady breezes from the sea fills your nostrils with salty tasting air.");
  set_listen("default","%^GREEN%^Palm fronds over head flap in the wind.");
  set_items(
    ([
    ({"roof","wall","trunks","posts","post","trunk"}) : "%^GREEN%^The hut seems to "+
	"have been made entirely from palm trees.  Five posts made from palm "+
	"tree trunks support the frame of the hut, while palm fronds have been "+
	"used to form whats left of the walls and roof.",
    ({"clothes","beds"}) : "%^BOLD%^%^BLUE%^Piled along the walls and in the corners are "+
	"several old and dusty clothes.  They seem to be about the right "+
	"shape and size to allow someone to lay on them and provide a bit of "+
	"padding from the sandy floor.  One pile of clothes seems to bulge out "+
	"a bit.",
    "journal" : "%^CYAN%^This looks to be an old, very fragile journal.  Perhaps "+
	"you could read it?"
    ]) );

  set_exits( 
    ([
    "out" : ROOMS+"island5"
    ]) );
  set_search("clothes","You uncover a small, fragile looking "+
	"journal.  Perhaps you could read it?");
  set_search("pile","You uncover a small, fragile looking "+
	"journal.  Perhaps you could read it?");
}

void init()
{
  ::init();
  add_action("read","read");
  add_action("sleep","sleep");
}

void read(string str)
{
  if(!str)
  {
    tell_room(TP,"And what exactly are you trying to read?");
    return 1;
  }
  if(str == "journal" || str == "page one")
  {
    TP->more(OBJ"page1");
    return 1;
  }
  if(str == "page two")
  {
    TP->more(OBJ"page2");
    return 1;
  }
  if(str == "page three")
  {
    TP->more(OBJ"page3");
    return 1;
  }
  if(str == "page four")
  {
    TP->more(OBJ"page4");
    return 1;
  }
  else
  {
  tell_room(TP,"You cant seem to find anything worth reading there.");
  return 1;
  }
}

void sleep()
{
  tell_room(TP,"%^CYAN%^You lay down upon a pile of the clothes and close "+
	"your "+
	"eyes.  Much to your suprise, you quickly find yourself drifting off "+
	"to sleep.");
  tell_room(ETP,"%^CYAN%^"+TPQCN+" settles down upon a pile of clothes and closes "+
	""+TP->query_possessive()+" eyes.",TP);
  TP->set_paralyzed(100, "You are sound asleep and can't move.");  
  call_out("sleep1", 3);
}

void sleep1()
{
  tell_room(TP,"%^CYAN%^Dark images begin to form in your head as your "+
	"consciousness slips further away.  "+
	"Shadow beasts fly around before you, "+
	"monstrous figures, that seem to change shapes almost constantly.\n\n");
  TP->move(ROOMS+"holding");
  tell_room(ETP,"%^CYAN%^"+TPQCN+" suddenly begins to rise up off the ground, "+
	"convulsing in spasms, before slowly fading out of view, disappearing "+
	"from the room.",TP);
  call_out("sleep2", 7);
}

void sleep2()
{
  tell_room(TP,"%^CYAN%^"+
	"Two glowing %^RED%^eyes%^CYAN%^ come at you from the distance.  As "+
	"the shadow draws closer, a gaping maw opens up.  "+
	"%^YELLOW%^Spittle%^RESET%^%^CYAN%^ drools "+
	"out from its mouth, and %^WHITE%^large teeth glisten%^CYAN%^ in the "+
	"light that seems to come from no where.\n\n");
  call_out("sleep3", 7);
}  

void sleep3()
{
  tell_room(TP,"%^CYAN%^"+
	"You try "+
	"to move, but your feet feel like lead...the shadow beast closes in "+
	"on you, the mouth headed straight for you face.  Just as the you can "+
	"smell the hot breath, feel the teeth brush against your cheeks, "+
	"everything goes black.\n\n");
  TP->set_paralyzed(0, "%^GREEN%^You wake up suddenly and look around you.");
    TP->move_player(ROOMS+"void1");
}
