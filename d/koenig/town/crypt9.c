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
  set_long("%^BOLD%^%^BLACK%^This place seems rather endless, cold, and dark. It seems to try and suck "+
"the very courage from you, to make you whimper in fear, and give up without "+
"a fight.%^RESET%^");
  set_exits( ([
     "northeast" : "/d/koenig/town/crypt7",
     "southeast" : "/d/koenig/town/crypt8",
]) );
}

void init()
{
  ::init();
do_random_encounters( ({"/d/koenig/town/mon/topi.c"}),60,3);
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
	 case 0: tell_room(TO,"%^BOLD%^%^BLACK%^Demonic, horrifying laughter bounces off the narrow walls.%^RESET%^"); break;
     case 1: tell_room(TO,"%^BOLD%^%^WHITE%^A booming voice surrounds you: %^RED%^You seem to be having trouble finding me, mortal. Shall I give you a hint?"); break;
     case 2: tell_room(TO,"%^BOLD%^%^WHITE%^He cackles madly: %^BOLD%^%^RED%^Here it is!"); break;
     case 3: tell_room(TO,"%^BOLD%^%^WHITE%^He booms: %^BOLD%^%^RED%^My secrets... are well guarded!"); break;
	 case 4: tell_room(TO,"%^BOLD%^%^BLACK%^He laughs again at his own joke, which you happened to find decidedly unfunny.%^RESET%^"); break;
	 case 5: tell_room(TO,"%^BOLD%^%^WHITE%^He booms: %^BOLD%^%^RED%^I doubt that helped you very much, pathetic mortal!"); break;
	 case 6: tell_room(TO,"%^BOLD%^%^BLACK%^He laughs long and hard before the voice cuts off, leaving you to the oppressive silence.%^RESET%^"); break;
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