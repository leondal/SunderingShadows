#include <std.h>
inherit ROOM;

int triggered, isrunning;
int do_keeper(int mystate);

void create()
{
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(DIRT_ROAD);
  set_property("light", 0);
  set_property("indoors", 1);
  set_short("A Dark Room Beneath the Crypt");
  set_long("%^BOLD%^%^BLACK%^As you travel deeper into the earth below the crypt and graveyard you "+
"begin to question your own sanity. You even begin to wonder what in the "+
"devil's name you are doing down here. Will you ever find your way out of this nightmare?%^RESET%^%^BOLD%^");
  set_exits( ([
     "up" : "/d/koenig/town/crypt6",
     "west" : "/d/koenig/town/crypt11",
]) );
}
void init() {
  ::init();
   if(!objectp(TP)) return;
   if(!userp(TP)) return;
   if(TP->query_true_invis()) return;
   if(triggered) return;
   triggered = 1;
   isrunning = 1;
   call_out("do_keeper",1,0);
}

int do_keeper(int mystate) {
   object thatroom;
   switch(mystate) {
     case 0: tell_room(TO,"%^BOLD%^%^WHITE%^A booming voice surrounds you: %^RED%^You appear to have more courage than I thought, mortal."); break;
     case 1: tell_room(TO,"%^BOLD%^%^BLACK%^You wish you could cut out his tongue and make him SHUT UP.%^RESET%^"); break;
     case 2: tell_room(TO,"%^RESET%^%^RED%^Or maybe even BASH his skull in so you wouldn't have to hear his voice, anymore...%^RESET%^"); break;
     case 3: tell_room(TO,"%^BOLD%^%^WHITE%^He booms: %^BOLD%^%^RED%^No matter. The result will be the same. Your DOOM!"); break;
	 case 4: tell_room(TO,"%^BOLD%^%^WHITE%^He booms: Come and find me, puny mortal.%^"); break;
     case 5: tell_room(TO,"%^BOLD%^%^BLACK%^His hideous laughter pounds through your mind.%^RESET%^"); break;
       isrunning = 0;
       return 1;
     break;
   }
   mystate++;
   call_out("do_keeper",5,mystate);
   return 1;
}

void reset_cinematics() { triggered = 0; }
int is_running() { return isrunning; }
