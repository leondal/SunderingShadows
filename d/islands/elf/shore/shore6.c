#include <std.h>
#include "../elf.h"
inherit CVAULT;

void create(){
   ::create();
      pick_critters();
   set_repop(35);
   ::create();
   set_terrain(GLACIER);
   set_travel(RUBBLE);
   set_climate("arctic");
   set_name("Ice Shelf");
   set_short("Ice Shelf");
   set_long((:TO,"long_desc":));
   set("night long",(:TO,"night_desc":));
   set_items(([
      (({"ocean","water"})) :
        "The ocean is littered with ice bergs.  If someone was feeling CRAZY they could _dive_ into the wicked cold water.",
      (({"glacier"})) : "The glacier makes its way up the mountain.",
	  (({"ice berg","berg"})) : "Large blocks of ice float in the ocean.",
	   ]));
    set_smell("default","Your nose feels like it is going to freeze.");
    set_listen("default","Gusts of freezing winds drown out all other sounds.");
   set_exits(([ "northeast": ROOMS"shore/shore7", 
    "west": ROOMS"shore/shore5",
    "camp": ROOMS"shore/camp",
     ]));
  set_door("gate",ROOMS"shore/camp","camp","elfkey");
  set_door_description("gate","The gates are made of driftwood and rope.");
}
void reset(){
  ::reset();
  set_locked("gate",0);
  set_open("gate", 0);
  if(!present("sign",TO))
     new(OBJ"sign4")->move(TO);

 }

void pick_critters();

string long_desc(){
  
   return("%^CYAN%^This is an ice shelf that juts out"+
   " over the %^BLUE%^ocean%^CYAN%^.  The %^BLUE%^glacier meets the %^BLUE%^water%^CYAN%^ here "+
   "and breaks apart into the water forming %^BLUE%^ice bergs%^CYAN%^ "+
   "that float away.  There isn't anything growing here."+
   "  It is just snow and ice and a piercing wind. "+
   " One must watch one's footing - a slip could land the "+
   "careless in the %^BLUE%^water%^CYAN%^, which looks deathly cold."+
"\n");
 
}
string night_desc() {
   return("%^BLUE%^This is an ice shelf that juts "+
   "out over the %^CYAN%^ocean%^BLUE%^.  The glacier meets the %^CYAN%^water%^BLUE%^"+
   " here and breaks apart into the water forming %^CYAN%^ice "+
   " bergs%^BLUE%^ that float away.  There isn't anything "+
   "growing here.  It is just snow and ice and a piercing"+
   " wind.  One must watch one's footing - a slip could "+
   "land the careless in the %^CYAN%^water%^BLUE%^, which looks deathly cold."+
"\n");
}

void pick_critters(){
      switch(random(11)) {     
        case 0:  break;
        case 1:  set_monsters( ({MON"tentacle"}),({random(4)+1}));
                 break;
        case 2:  set_monsters( ({MON"worm"}),({random(2)+1}));
                 break;
        case 3:  set_monsters( ({MON"frostgirl"}),({1}));
                 break;
		case 4:  set_monsters( ({MON"tentacle"}),({random(3)+2}));
                 break;
        default: break;  
      }
return;
}
void init(){
  ::init();
  add_action("dive","dive");
}
int dive(){
   write("%^CYAN%^Jump into this water with little hope of survival?  Sure, why not?");
   TP->force_me("emote dives into the %^BOLD%^%^CYAN%^frigid sea%^RESET%^ like a %^BOLD%^%^CYAN%^crazy%^RESET%^ person.");
   TP->move(ROOMS"shore/water");
   return 1;
}