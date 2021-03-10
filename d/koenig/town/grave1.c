#include <std.h>
inherit VAULT;

void create()
{
  ::create();
   set_terrain(CEMETERY);
   set_travel(DIRT_ROAD);
  set_door("crypt","/d/koenig/town/crypt1.c","crypt","black death key");
  set_door("gate","/d/koenig/town/room8.c","gate","black death key");
  set_open("crypt", 0);
  set_open("gate",1);
  set_locked("crypt",1);
  set_locked("gate",0);
  set_property("magic hold",20);
  set_string("crypt","unlock","%^BLUE%^The tumblers unlock with surprising ease.");
  set_string("crypt","lock","%^BLUE%^You have to struggle with it. It seemed like it "
                            "didn't want to be locked again.");
  set_string("gate","lock","%^BLUE%^You really have to wonder about your sanity "
                           "as you lock your only escape from here.");
  set_string("gate","unlock","%^BLUE%^You struggle with the lock, apparently this "
                             "place doesn't want you to go.");
  set_string("crypt","open","%^BLUE%^A sudden gust of foul air blows into your face "
             "as you crack open the door.From within you hear only true "
             "silence.");
  set_string("crypt","close","%^BLUE%^It seems to assist you.");
  set_string("gate","open","%^BLUE%^It seems to catch on something, but with one "
                           "great heave you it open.");
  set_string("gate","close","%^BOLD%^%^BLACK%^It closes smoothly and without a squeek.");
  set_property("light", 1);
  set_short("The Muileann Graveyard");
  set("day long", "%^RESET%^%^ORANGE%^Good thing the sun is out, this place could be twice as bad if it wasn't. "+
"There are many %^RESET%^headstones%^RESET%^%^ORANGE%^ here, and what appears to be a %^BOLD%^%^BLACK%^crypt%^RESET%^%^ORANGE%^. One thing "+
"you do notice that is peculiar about the place is that it looks like no one has "+
"been buried here for a very LONG time. You can maybe %^RESET%^read%^RESET%^%^ORANGE%^ a few of the "+
"headstones, but you might want to get a closer look at that crypt.");
  set("night long","%^RESET%^%^BLUE%^Adventurer, one may begin to question your %^GREEN%^sanity%^BLUE%^ with you wandering "+
"around in a graveyard at night. Strange things have been known to happen at such "+
"a time, so beware and pray to whatever god you like. You can make out the shape of what you "+
"think may be a %^BOLD%^%^BLACK%^crypt%^RESET%^%^BLUE%^. All about you are the %^RESET%^headstones%^RESET%^%^BLUE%^ of the dead. "+ 
"wonder what they would think of your tip toeing across their graves at "+
"night? %^BOLD%^%^BLACK%^Just something to ponder over, my friend...%^RESET%^\n");
  set_smell("default", "You smell death here.");
  set_listen("default", "You hear the sobbing of a little child here.");
  set_listen("sobbing","The sobbing is that of a small girl child, it comes "
             "from no where and everywhere at once.");
  set_items( ([
     "headstone" : "It is hard to make out but what you do see refers to a "+
                   "little girl who died very young.",
     "crypt" : "There appears to be a picture etched in the stone door.",
     "picture" : "It appears to be a skeleton climbing out of a coffin. "+
                 "Now where have you seen that before?",
      "door" : "There is a keyhole... do you have the key?",
     "coffin" : "Etched on the coffin are the words Crypt Keeper. You are not "+
                "sure you like the sounds of that."
]) );
  set_exits( ([
     "gate" : "/d/koenig/town/room8",
     "crypt" : "/d/koenig/town/crypt1"
]) );
}

void init(){
   ::init();
    if(present("black death key",TP) || present("boy",TP)){
if(!present("spirit"))new("/d/koenig/town/mon/girl2.c")->move(TO);
  }
}
