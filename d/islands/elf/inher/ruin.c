//underwater ruined road
#include <std.h>
#include "../elf.h"
inherit WATER;
int items = 1; //has items

void pick_critters();

void create(){
   pick_critters();
   set_repop(35);
   ::create();
   set_terrain(DEEP_WATER);
   set_travel(RUBBLE);
   set_climate("arctic");
   set_name("Underwater Ruin");
   set_short("%^BOLD%^%^CYAN%^Underwater Ruin%^RESET%^");
   set_long((:TO,"long_desc":));
   set("night long",(:TO,"night_desc":));
   set_items(([
     (({"ocean","water"})) :
        "The ocean is littered with ice bergs.  You could _swim_ to the surface but the currents are rather wild.",
	  (({"ice berg","berg"})) : "Large blocks of ice float in the ocean.",
	   
     (({"mud","road"})) : "The ground is a gray mud.  Perhaps you could _search_ mud?.",
	   ]));
    set_smell("default","Near freezing water fills your nose.");
    set_listen("default","You hear swooshing of water currents.");
    set_property("wild magic", 60);
    set_search("default","Where do you want to search?  The mud maybe?");
    set_search("mud",(:TO,"search_mud":));  
}

string long_desc(){
  
   return(query_short() + "\n"+
      "%^CYAN%^This is a ruined road on the sea floor."+
   "  The ocean swirls all around and above are ice bergs "+
   "floating on the water surface.  The road is little more "+
   "than dislodged bricks mixed with gray mud of the sea floor."+
"\n");
 
}
string night_desc() {
   return(query_short() + "\n"+
      "%^BLUE%^At night there is barely any light on this"+
   " ruined road.  The road is in a terrible state like an "+
   "earthquake destroyed it.  The years of being under water"+
   " and sediment make it more of a muddy ruin than a road."+
"\n");
}

void reset(){
 ::reset();
 switch(random(9)){
      case 0:  tell_room(TO,"%^CYAN%^Near freezing water chills your bones.");
               break;
      case 1:  tell_room(TO,"%^CYAN%^You hear a swoosh as water currents flow past you.");
               break;
      case 2:  tell_room(TO,"%^CYAN%^A thunderous crack rumbles"+
	  " through the area as a large block of ice breaks above.");
              break;
      case 3:  tell_room(TO,"%^BOLD%^Several odd fish swim past.");
               break;
      case 4:  tell_room(TO,"%^CYAN%^Some strange creature moves along the ocean floor.");
               break;
      case 5:  tell_room(TO,"%^BOLD%^There is a crack and a splash "+
	  "as a berg of ice cavs into the sea.");
               break;	
      case 6:  tell_room(TO,"%^CYAN%^Several bubbles pop up from the ruins.");
               break;		
      case 7:  tell_room(TO,"%^CYAN%^Your feet feel numb as if they were going to freeze into the mud.");
               break;		
      case 8:  tell_room(TO,"%^BOLD%^Several ice crystals form in the water and begin to float upward.");
               break;	             
               	   }
 return;
}
void pick_critters(){
      switch(random(10)) {     
        case 0:  break;
        case 1:  set_monsters( ({MON"crab"}),({random(4)+1}));
                 break;
        case 2:  set_monsters( ({MON"lobster"}),({random(2)+1}));
                 break;
        case 3:  set_monsters( ({MON"rev"}),({1}));
                 break;
		  case 4:  set_monsters( ({MON"stingray"}),({random(3)+2}));
                 break;
        case 5:  set_monsters( ({MON"stingray",MON"crab",MON"lobster"}),({random(3)+1,random(2)+1,random(2)+1}));
                 break;
        default: break;  
      }
return;
}
int search_mud(string str){
     object obj;
     if (!items) {
     tell_object(TP,"It seems like someone has"+
      " searched around here already.");
      return 1;}
      if(!random(2)){
     obj = new("/d/antioch/valley/obj/gem");
     obj->move(TO);
     tell_object(TP,"%^CYAN%^Fortune smiles upon you "+
      "and you find a gem.");
     items=0;
   }
   else{
      tell_room(TO,"%^RED%^"+TPQCN+
      " searches the mud and disturbs a long dead corpse who rises in anger.");
      tell_object(TP,"%^RED%^You search the mud and disturb the resting place of a long dead human.");
      obj = new(MON"rev");
      obj->move(TO);
      obj->kill_ob(TP);
   }
      return 1;
}
void init(){
  ::init();
  add_action("swim_em","swim");
}
int swim_em(){
   write("%^CYAN%^You swim towards the surface and get pushed by the currents until you are able to grab hold of the ice and pull yourself on top of it.");
   TP->force_me("emote swims towards the surface and the currents pull them out of sight.");
   TP->move(ROOMS"shore/flow"+roll_dice(1,5));
   return 1;
}
