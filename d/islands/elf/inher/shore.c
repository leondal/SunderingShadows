//GLACIER PATH
#include <std.h>
#include "../elf.h"
inherit CROOM;

void pick_critters();

void create(){
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
 
}

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
   " here and breaks apart into the water forming %^CYAN%^ice"+
   " bergs%^BLUE%^ that float away.  There isn't anything "+
   "growing here.  It is just snow and ice and a piercing"+
   " wind.  One must watch one's footing - a slip could "+
   "land the careless in the %^CYAN%^water%^BLUE%^, which looks deathly cold."+
"\n");
}

void reset(){
 ::reset();
 switch(random(7)){
      case 0:  tell_room(TO,"%^CYAN%^A gust of wind blows by chilling your bones.");
               break;
      case 1:  tell_room(TO,"%^CYAN%^You hear strange whispering"+
	  " in your ear but look and nothing is there.");
               break;
      case 2:  tell_room(TO,"%^CYAN%^A thunderous crack rumbles"+
	  " through the area as a large block of ice breaks.");
               break;
      case 3:  tell_room(TO,"%^BOLD%^Sheets of snow fall from the"+
	  " sky, freezing your face.");
               break;
      case 4:  tell_room(TO,"%^CYAN%^Some strange splashing comes from the water.");
               break;
      case 5:  tell_room(TO,"%^BOLD%^There is a crack and a splash "+
	  "as a berg of ice cavs into the sea.");
               break;	
      case 6:  tell_room(TO,"%^CYAN%^The wind dies down,"+
	  " leaving a cold hush.");
               break;				   }
 return;
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
        default: break;  //added to cut down on hack fest 
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
