//gate to Ashta' Rathai
#include <std.h>
#include "elf.h"
#include <daemons.h>
#include <magic.h>
inherit VAULT;


void create(){
    ::create();
    set_terrain(ICE);
    set_travel(SLICK_FLOOR);
    set_property("light",3);
    set_climate("arctic");
    set_name("Gate");
    set_short("Gate");
    set_long(
     "%^BOLD%^%^CYAN%^This place is situated on top of a cloud-covered mountain%^RESET%^%^CYAN%^.%^BOLD%^%^CYAN%^  "+
	 "One can feel bitter cold intensifed by dampened garments%^RESET%^%^CYAN%^.%^BOLD%^%^CYAN%^  "+
	 "Continuing on, one finds two large and beautiful gates%^RESET%^%^CYAN%^.%^BOLD%^%^CYAN%^  "+
	 " They are connected to eight-foot-high walls on both sides%^RESET%^%^CYAN%^.%^BOLD%^%^CYAN%^  The "+
	 "walls are white, and head off into the mist in either direction%^RESET%^%^CYAN%^.%^BOLD%^%^CYAN%^  "+
	 "There is a golden plaque on the gate%^RESET%^%^CYAN%^.%^BOLD%^%^CYAN%^\n");
	set_items(([
      (({"mountain"})) :
        "The mountain is shrouded in mist.",
	  (({"plaque"})) :
        "The gate has the word Ashta'Rathai written in elven.",
      (({"gates","gate"})) : "The gates are iron.  Upon them are swirling patterns of "+
     "gold and silver.  There is a large iron ring to open each "+
	 "gate.  They are large and covered in ice."+
	 "  One could knock on the gate.\nThere is a plaque on it.",
      (({"wall","walls"})) : "The ice-covered walls are white.  "+
	  "They have cloud-like etchings drawn into them.",
	   ]));
   set_exits(([ "north" : ROOMS"gate1", 
      "south" : ROOMS"ice/ice1",
	  "east" : ROOMS"church",]));
   set_listen("default","Cold wind chills one's ears.");
   set_smell("default",
   "Your nose and mouth burn with every breath of cold air.");
   set_door("gate",ROOMS"gate1","north","elfkey");
   set_locked("gate",1);
   set_door_description("gate","The gates are iron.  Upon them are swirling patterns of "+
     "gold and silver.  There is a large iron ring to open each "+
	 "gate.  They are large and covered in ice. "+
	 " These cold rings could be used to _knock_  \nThere is a plaque on it.");
  set_post_exit_functions(({"north"}),({"go_east"}));
}
void reset(){
  ::reset();
  set_locked("gate",1);
  set_open("gate", 0);
  if(!present("sign"))
   new(OBJ"sign")->move(TO);
 }
 
 int knock(string str){
   object gk;
        if(str != "gate"){  write("Maybe you should "+
                "try <knock gate>.\n");
				return 0;
				}
        tell_room(ETP,"You see "+TPQCN+" step up to the great gates and "+
                "begin knocking with one of the knockers.",TP);
        tell_object(TP,"You step up to the great gates and"+
		" begin to knock with "+
         "one of the rings.");
    gk = find_object_or_load(MON"gatekeeper");
  if(!present("gatekeeper"))
      gk->move(TO);
    gk->start_grumble();
        return 1;

}
int KnockDoor(string str){
 knock(str);
 :: KnockDoor(str);
 return 1;
 }
 void init()
{
        ::init();
        add_action("sneak","sneak");
}

void sneak(string str)
{
        if(str == "north" || str == "n") {
                tell_object(TP,"You can't seem to sneak through that doorway.");
                return 1;
        }
}

int go_east()
{
   object myspl, obx;
   if(!objectp(TP)) return 1;
   if(TP->query_true_invis()) return 1;
   if(ALIGN->is_evil(TP)) {
       tell_object(TP,"%^RED%^You feel a pain so horrible rip through your body that"+
       " you can't stifle the scream that swells within your throat!");
       tell_room(ROOMS"gate","%^RED%^"+TP->QCN+
			    " screams in agony as "+
				TP->query_subjective()+" walks through the gate.",TP);
       tell_room(ROOMS"gate1","%^RED%^"+TP->QCN+
				" screams in agony as "+TP->QS+
				" exits through the gate.",TP);
				TP->cause_typed_damage(TP,0,random(100)+50,"divine");
  
				
        }
        return 1;
}
