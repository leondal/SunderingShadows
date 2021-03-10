//underwater ruined house
#include <std.h>
#include "../elf.h"
inherit WATER;
int items = 1; //has items


void create(){
   ::create();
   set_terrain(DEEP_WATER);
   set_travel(RUBBLE);
   set_climate("arctic");
   set_name("Sunken House");
   set_short("%^BOLD%^%^CYAN%^Sunken House%^RESET%^");
   set_long((:TO,"long_desc":));
   set("night long",(:TO,"night_desc":));
   set_items(([
     (({"stone","metal"})) : "The ocean claimed all but the stone and metal of this house long ago.",
	   
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
      "%^CYAN%^This is a ruined stone house at"+
      " the bottom of the sea.  All the organic"+
      " bits of the house were claimed by the sea"+
      " long ago.   Only stone and rusted metal "+
      "bits remain.  The years of being in the "+
      "sea have covered everything in a fine gray mud."+
"\n");
 
}
string night_desc() {
   return(query_short() + "\n"+
      "%^BLUE%^At night there is barely any light on this"+
   " ruined house.  The building is in a terrible state like an "+
   "earthquake destroyed it.  The years of being under water"+
   " have covered everything in mud.."+
"\n");
}

void reset(){
 ::reset();
 switch(random(9)){
      case 0:  tell_room(TO,"%^CYAN%^Near freezing water chills your bones.");
               break;
      case 1:  tell_room(TO,"%^CYAN%^A ghostly woman appears and crouches down like something might crush her.  She vanishes shortly after.");
               break;
      case 2:  tell_room(TO,"%^CYAN%^A thunderous crack rumbles"+
	  " through the area as a large block of ice breaks above.");
              break;
      case 3:  tell_room(TO,"%^BOLD%^Several odd fish swim past.");
               break;
      case 4:  tell_room(TO,"%^CYAN%^A ghost appears bending over what used to be a kitchen then fades away.");
               break;
      case 5:  tell_room(TO,"%^BOLD%^A translucent ghost of a woman walks across the house then vanishes.");
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
      obj = new(MON"skele");
      obj->move(TO);
      obj->kill_ob(TP);
   }
      return 1;
}