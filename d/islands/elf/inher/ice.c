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
   set_name("%^%BOLD%^Glacial Crevasse%^RESET%^");
   set_short("%^BOLD%^Glacial Crevasse%^RESET%^");
   set_long((:TO,"long_desc":));
   set("night long",(:TO,"night_desc":));
   set_items(([
      (({"ice"})) :
        "The whole area is nothing but ice.",
      (({"sky"})) : "The sky can barely be seen.  It is nothing but white.",
      (({"ground"})) : "The ground is uneven blocks of jutting ice.",
	  (({"wall","walls"})) : "Steep walls of ice surround the area.",
	  (({"path","pathway"})) : "Calling this a path is generous."+
	  "  It is more of a crack in the glacier that one can squeeze through.",
	   ]));
   set_listen("default",
   "Cracks like thunder echo through the place as the ice shifts.");
   set_smell("default",
   "Your nose is freezing.");
   set_property("wild magic", 50);
}

string long_desc(){
  
   return(query_short()+"\n%^CYAN%^Cracks in the %^BOLD%^glacial ice%^RESET%^%^CYAN%^ form a narrow pathway"+
   " some twenty feet down from the surface.  The %^BOLD%^%^CYAN%^sky%^RESET%^%^CYAN%^ above is whiteout"+
   " and the light below reflects off the ice, leaving a blue tint"+
   " to everything.  The going is extremely difficult as the %^BOLD%^%^CYAN%^ground%^RESET%^%^CYAN%^"+
   " is uneven and slick.  It takes quite a bit of stamina to "+
   "travel through this ice maze.  %^BOLD%^%^CYAN%^Walls%^RESET%^%^CYAN%^ of ice allow only "+
   "for one to see directly in front of them."+
"\n");
 
}
string night_desc() {
   return(query_short()+"\n%^BLUE%^Cracks in the %^CYAN%^glacial ice%^RESET%^%^BLUE%^ form a narrow pathway"+
   " some twenty feet down from the surface.  The %^CYAN%^sky%^RESET%^%^BLUE%^ above is whiteout"+
   " and the light below reflects off the ice, leaving a blue tint"+
   " to everything.  The going is extremely difficult as the %^CYAN%^ground%^RESET%^%^BLUE%^"+
   " is uneven and slick.  It takes quite a bit of stamina to "+
   "travel through this ice maze.  %^CYAN%^Walls%^BLUE%^ of ice allow only "+
   "for one to see directly in front of them."+
"\n");
}

void reset(){
 ::reset();
 switch(random(7)){
      case 0:  tell_room(TO,"%^CYAN%^A gust of wind blows by, chilling your bones.");
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
      case 4:  tell_room(TO,"%^CYAN%^An ice-coated rock "+
	  "falls from the walls...  as if this path was not"+
	  " difficult enough?");
               break;
      case 5:  tell_room(TO,"%^BOLD%^A wave of cold bears "+
	  "down on you.  You blink and your eyelashes freeze "+
	  "together.  It takes an effort to open your eyes.");
               break;	
      case 6:  tell_room(TO,"%^CYAN%^The wind dies down,"+
	  " leaving a cold hush.");
               break;				   }
 return;
}
void pick_critters(){
      switch(random(11)) {     
        case 0:  break;
        case 1:  set_monsters( ({MON"ooze"}),({random(3)+1}));
                 break;
        case 2:  set_monsters( ({MON"worm"}),({random(3)+1}));
                 break;
        case 3:  set_monsters( ({MON"frostgirl"}),({1}));
                 break;
		case 4:  if((string)"/daemon/events_d"->query_time_of_day() == "night") 
		            set_monsters( ({MON"maiden"}),({1}));
                 break;
        case 5..10: break;  //added to cut down on hack fest 
      }
return;
}
