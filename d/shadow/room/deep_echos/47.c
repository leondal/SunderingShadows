//47.c  pit with beasty
#include <std.h>
#include "deep_echo.h"
inherit VAULT;
int open = 0;

void create(){
    ::create();
    set_indoors(1);
    set_terrain(NAT_CAVE);
    set_travel(RUTTED_TRACK);
    set_property("light",1);
    set_name("Bloody Chamber");
    set_short("Bloody Chamber");
    set_long(
      "%^RED%^%^BOLD%^Sacrificial Pit%^RESET%^\n"+
	  "%^RED%^"+
      "This cave end appears to be some kind of "+
	  "sick sacrificial pit.  The walls floor and"+
	  " ceiling are stained with blood.  On the "+
	  "floor there is a statue of a wolf with a "+
	  "fearsome look on it's face.  The pit in "+
	  "the center of the room is filled with "+
	  "warm blood.  Several metal poles with "+
	  "glowing red orbs line the blood pit.  "+
	  "There is a large cage against the back wall."
      "\n");
	      set_items(([
      (({"floor"})) : 
	  "The floor is stained with blood.  "+
	  "There is a pool of blood in the center of the room",
      (({"pit"})) : "The pit is filled with blood."+
	  "  One can only imagine how it is kept full",
      (({"statue","wolf"})) :
	  "The wolf is stained with blood, it looks rabid",  
	  (({"pole","orb","poles"})) :
	  "metal poles with glowing red"+
	  " orbs cast a reddened light on this room", 
      (({"cage"})) : 
	  "some beast is shut in the cage."+
	  "  Perhaps you could free it.",]));
   set_exits(([ "west" : ROOMS"44" ]));
   set_listen("default","you hear the churning of blood.");
   set_smell("default","it smells fresh blood");
   set_door("gate",ROOMS"44","west","key");
   set_locked("gate",1);
   set_door_description("gate","The gate is made of"+
	  " rusted iron bars.  It is lodged into the "+
	  "cavern and is locked with a simple lock.");
}
void init(){
   ::init();

   add_action("open_cage","free");
}
void reset(){
  ::reset();
  open =0;
}
int open_cage(string str){
   if (!str) 
      return 0;

   if (TP->query_bound() || TP->query_paralyzed()) {
      TP->send_paralyzed_message("info",TP);
      return 1;
   }

   if (str != "beast") 
      return notify_fail("free what?\n");
   if( open != 0) return notify_fail("The cage is already open.\n");
   
   new(MOBS"beast")->move(TO);
   tell_room(TO, TPQCN+" opens the cage . . .  and a raging beast escapes!");  
   open =1;
   	      set_items(([
      (({"floor"})) : 
	  "The floor is stained with blood.  "+
	  "There is a pool of blood in the center of the room",
      (({"pit"})) : "The pit is filled with blood."+
	  "  One can only imagine how it is kept full",
      (({"statue","wolf"})) :
	  "The wolf is stained with blood, it looks rabid",  
	  (({"pole","orb","poles"})) :
	  "metal poles with glowing red"+
	  " orbs cast a reddened light on this room", 
      (({"cage"})) : 
	  "Someone has freed the beast from the cage.",]));
   return 1;
}
