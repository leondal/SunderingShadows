#include <std.h>
#include "../defs.h"
inherit "/std/bank.c";

string getBankId() { return "juran"; }

void create(){ 
   ::create();
   set_property("light",-1);
   set_property("indoors",1);
   set_terrain(NAT_CAVE);
   set_travel(RUTTED_TRACK);
   set_name("A small side-cavern");
   set_short("A small side-cavern");
   set_smell("default","An odd aroma fills the air, that smells almost like something edible.  Almost.");
   set_listen("default","A constant stream of chatter, screeching, grumbling and general rabble surrounds you.");
   set_long("%^BOLD%^A small side-cavern%^RESET%^\n"
"This small side-cavern is an offshoot of the main cave, with the same rough and jagged stone to shape it.  "
"The stone floor is cold underfoot, and covered with the same %^ORANGE%^grime %^RESET%^as the rest of the "
"area.  Here, however, only a few small scraps of trash are visible, as if an attempt was actually made to "
"clear it up.  Also in stark contrast to the rest of the cavern, is a massive, sturdy door of blackened steel "
"set into the rear wall, that looks surprisingly well made.  A steady stream of creatures scurry in and out of "
"the cavern opening, some entering and leaving clutching bags that clink when moved.  A %^WHITE%^%^BOLD%^large "
"sign%^RESET%^ has been stuck to the wall.\n");

   set_items(([
     ({"cave","cavern","ground"}):"The cavern walls and floor are formed of dull stone, still jagged in many "
"places and probably not shaped by mortal hands.  The floor is cold and hard beneath your feet.",
     ({"door","steel door"}):"A massive door of blackened steel is set into the rear wall of the cave.  It "
"looks very thick and sturdy, with a surprisingly complex lock upon the outside.",
     "sign":"Plastered against the wall is a sign, scrawled with countless runes and symbols in different "
"languages.  They seem to form a list of commands for the bank.  You could probably read %^YELLOW%^read "
"%^RESET%^the sign.",
   ]));
   set_exits(([
     "southwest":ROOMS"cavern6",
   ]));
}

void init(){
   ::init();
   if(interactive(TP) && !random(10) && TP->query_level() < 10)
     write("The %^YELLOW%^sign %^RESET%^stuck to the wall grabs your attention.");
   add_action("read", "read");
}

void reset(){
   ::reset();
   if(!present("bank_guard")) find_object_or_load(MON"bank_guard")->move(TO);
   if(!present("bank_teller")) find_object_or_load(MON"bank_teller")->move(TO);

   switch(random(10)) {
     case 0:
     tell_room(TO,"%^ORANGE%^A small, grubby goblin passes you at a run, taking a swipe at your purse as he "
"goes.  He disappears into the crowd before you can even react.%^RESET%^");
     break;
     case 1:
     tell_room(TO,"%^WHITE%^%^BOLD%^The ogre guard takes a swipe at a scrawny goblin that gets too close.  The "
"goblin yelps and scurries back out of the cavern.%^RESET%^");
     break;
     case 2..3:
     tell_room(TO,"%^BLACK%^%^BOLD%^.%^RESET%^");
     break;
     case 4:
     tell_room(TO,"%^GREEN%^A group of kobolds scurry through the crowd, weaving around the larger creatures "
"and screeching between themselves as they go.%^RESET%^");
     break;
     case 5:
     tell_room(TO,"%^CYAN%^A fight breaks out between several goblins, over something they found in a pile of trash outside.%^RESET%^");
     break;
     case 6..7:
     tell_room(TO,"%^BLUE%^Something wet and slimy drips down on you from the roof above.%^RESET%^");
     break;
     case 8:
     tell_room(TO,"%^YELLOW%^A dying screech of some small creature echoes through the cavern from "
"outside.%^RESET%^");
     break;
     case 9:
     tell_room(TO,"%^RED%^A gang of bugbears shoves past, talking and laughing raucously amongst themselves "
"as the goblins and kobolds scatter out of their way.%^RESET%^");
     break;
   }

}