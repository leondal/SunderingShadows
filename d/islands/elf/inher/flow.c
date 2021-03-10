//ice above sea
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
   set_name("Ice Flow");
   set_short("%^BOLD%^%^CYAN%^Ice Flow%^RESET%^");
   set_long((:TO,"long_desc":));
   set("night long",(:TO,"night_desc":));
   set_items(([
      (({"sea","water"})) :
        "The ocean is littered with ice bergs.  If someone was feeling CRAZY they could _dive_ into the wicked cold water.",
      (({"glacier"})) : "The glacier makes its way from the mountain to the north into the sea where you are now.",
	  (({"ice berg","berg"})) : "Large blocks of ice float in the sea.",
	   ]));
    set_smell("default","Your nose feels like it is going to freeze.");
    set_listen("default","Gusts of freezing winds drown out all other sounds.");
 
}

string long_desc(){
  
   return(query_short() + "\n"+
   "%^CYAN%^This is an ice flow that floats out over "+
   "the sea.  The footing is not solid.  There are many gaps "+
   "to fall into the ice cold water below.  A ship might be "+
   "able to squeeze through the blocks of ice but could also "+
   "easily be crushed if it suddenly freezes.  The glacier"+
   " flows into the sea from the north.  There are leveral large ice bergs here."+
"\n");
 
}
string night_desc() {
   return(query_short() + "\n"+
   "%^BLUE%^This is an ice flow that floats out over "+
   "the sea.  The footing is not solid.  There are many gaps "+
   "to fall into the ice cold water below.  A ship might be "+
   "able to squeeze through the blocks of ice but could also "+
   "easily be crushed if it suddenly freezes.  The glacier"+
   " flows into the sea from the north.  There are leveral large ice bergs here."+
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
               break;				   
    }
 return;
}
void pick_critters(){
      switch(random(8)) {     
        case 0:  break;
        case 2:  set_monsters( ({MON"sprite"}),({1}));
                 break;
        case 3:  set_monsters( ({MON"frostgirl"}),({1}));
                 break;
		case 4:  set_monsters( ({MON"penguin"}),({random(3)+2}));
                 break;
        default: break;  
      }
return;
}
void init(){
  ::init();
  slippy();
}
void slippy() { 
    if(!userp(TP)) return;
    if(avatarp(TP) && TP->query_invis() || TP->query_property("flying")) return; 
    if(!"/daemon/saving_throw_d.c"->reflex_save(TP,-40)) 
     { 
         tell_object(TP,"%^BLUE%^You sink quickly and disappear into the water!"); 
         tell_room(TO,"%^BLUE%^"+TPQCN+" sinks quickly into the water and disappears!",TP); 
 		 TP->cause_typed_damage(TP,0,roll_dice(1,8+20),"cold"); 
         TP->move(ROOMS"/shore/ruin"+(string)roll_dice(1,10)); 
         return 0; 
     } 
     write("%^CYAN%^You are glad you catch yourself before falling into the sea."); 
 return;    
}