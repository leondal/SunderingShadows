#include <std.h>
#include "../../gantioch.h"
#include <daemons.h>

inherit VAULT;

int triggered, isrunning;
int do_dragon(int mystate);
int is_running();

void create(){
   ::create();
   set_name("mound14");
   set_property("light",1);
   set_property("no teleport",1);
   set_property("indoors",1);
   set_short("%^BOLD%^%^RED%^Within an Arena%^RESET%^");
   set_terrain(CEMETERY);
   set_travel(FOOT_PATH);
   set_smell("default","\n%^BOLD%^%^BLACK%^You smell old sweat and the dirt around you.%^RESET%^");
   set_listen("default","%^BOLD%^%^RED%^You hear the yips and cheers of the gnolls in the audiance.%^RESET%^");
   set_long("%^BOLD%^%^CYAN%^As walk into this massive chamber, you get the feeling immediately"+
             " that this is a large gladitorial chamber. Tiered %^BOLD%^%^GREEN%^mounds %^BOLD%^%^CYAN%^of earth line the edges of the"+
             " room, acting as seating for the many %^BOLD%^%^RED%^gnolls %^BOLD%^%^CYAN%^which occupy it to observe the actions"+
             " within. To the north there is a massive gate, closing off the area from some sort of"+
             " antechamber ahead.");
   set_items(([
      "mounds" : "%^RESET%^%^RED%^The seats line the whole chamber except the two entrances within it.",
      "gnolls" : "%^RESET%^%^ORANGE%^The many young gnolls surround you, yelping and growling.",
]) );
   set_exits(([
     "north":MOUND"mound13",
     "chamber":MOUND"treasureroom",
   ]));
   // set_pre_exit_functions(({"chamber"}),({"GoThroughDoor"}));
    set_door("gate","/d/antioch/greaterantioch/rooms/mound/mound13","north","somekey");
	set_open("gate",0);
	set_string("gate","open","%^RESET%^%^BLUE%^The massive metal gate rises and you hear barks and snarls coming from the south.");
    set_string("gate","close","%^RESET%^%^BLUE%^The massive metal gate shuts heavily as the chains release the strain.");
    set_door_description("gate","These are two huge solid wooden doors that
come together in the middle. They are bound together with giant dwarven
forged iron bands.");
    lock_difficulty("gate",-2000,"lock");
   set_property("no pocket space",1);
   triggered = 0;
   isrunning = 0;
}

int GoThroughDoor() {
object room;
if(member_array("%^BOLD%^%^CYAN%^Dispatch the Murderer%^RESET%^",TP->query_mini_quests())!=-1)  {
   if(TP->query_paralyzed() || TP->query_bound() ||
TP->query_unconscious()){
    return 0;
    }
    write("%^BOLD%^%^YELLOW%^You realize that this must be the mound in which the man at the keep"+
          " must have been talking about. By his information, many people were taken here in recent"+
          " raids on the newly developing town. I wonder what could have happened to them?");
    room = find_object_or_load(MOUND"treasureroom");
    room->set_property("light",15);
  return 1;
  } else {
	  return 1;
  }
}


void init() {
   ::init();
   if(!objectp(TP)) return;
   if(!userp(TP)) return;
   if(TP->query_true_invis()) return;
   if(triggered) return;
   triggered = 1;
   isrunning = 1;
   call_out("do_boss",1,0);
}

int do_boss(int mystate) {
   object thatroom;
   switch(mystate) {
     case 0:
       tell_room(TO,"%^BOLD%^%^RED%^%^The massive chamber overwhelms you as you enter. The room is %^BOLD%^%^BLACK%^dark%^BOLD%^%^RED%^, with vision difficult. The cheers of the"+
                 " gnolls around you fills the air and you get the idea that this is not a good place. You hear the sounds of chains clinking"+
                 " across the floor as a gate opens, and %^BOLD%^%^YELLOW%^cheers %^BOLD%^%^RED%^erupt as someone obviously enters.\n%^RESET%^");
     break;
     case 1:
       tell_room(TO,"%^BOLD%^%^CYAN%^As your eyes grow accustomed to the %^BLACK%^darkness%^CYAN%^, you make out the form of a"+
       " massive %^BOLD%^RED%^gnoll %^BOLD%^%^CYAN%^standing at the far end of the chamber.\n%^RESET%^");
     break;
     case 2:
       tell_room(TO,"%^BOLD%^%^CYAN%^The massive %^BOLD%^%^RED%^gnoll %^BOLD%^%^CYAN%^approaches slowly as he brings down his massive weapon from his shoulder to his hands.\n");
     break;
     case 3:
       tell_room(TO,"%^BOLD%^%^CYAN%^The %^BOLD%^%^RED%^gnoll %^BOLD%^%^CYAN%^stops suddenly, lifting a hand into the air. The gnolls around you"+
       " burst into %^RESET%^%^RED%^horrible %^BOLD%^%^CYAN%^cheers. The %^BOLD%^%^RED%^gnoll %^BOLD%^%^CYAN%^looks to you and"+
       " says %^BOLD%^%^WHITE%^'%^BOLD%^%^RED%^Welcome to your death, maggots!%^BOLD%^%^CYAN%^'\n%^RESET%^");
     break;
     case 4:
       tell_room(TO,"%^BOLD%^%^CYAN%^The %^BOLD%^%^RED%^gnolls %^BOLD%^%^CYAN%^laugh around you, filling the air.\n%^RESET%^");
     break;
     case 5:
       tell_room(TO,"%^BOLD%^%^CYAN%^The massive %^BOLD%^%^RED%^gnoll %^BOLD%^%^CYAN%^snarls angrily, then rushes forwards with a"+
                 " %^BOLD%^%^WHITE%^bone-chilling %^BOLD%^%^RED%^howl%^BOLD%^%^CYAN%^!!\n%^RESET%^");
       new(MON"gnollchieftain")->move(TO);
       isrunning = 0;
       return 1;
     break;
   }
   mystate++;
   call_out("do_boss",5,mystate);
   return 1;
}

void reset_cinematics() { triggered = 0; }
int is_running() { return isrunning; }

