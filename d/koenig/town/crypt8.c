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
     "northeast" : "/d/koenig/town/crypt6",
     "northwest" : "/d/koenig/town/crypt9",
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
	 case 4: tell_room(TO,"%^BOLD%^%^BLACK%^Another gloomy room. You feel the oppressive weight of this earthen tomb bearing down on you.%^RESET%^"); break;
     case 0: tell_room(TO,"%^BOLD%^%^BLACK%^As if on queue, the Crypt Keeper's voice rings out again in your head:%^RESET%^"); break;
     case 1: tell_room(TO,"%^BOLD%^%^WHITE%^His booming voice surrounds you: %^RED%^YES, mortal, GIVE UP! Give your soul to ME!"); break;
     case 2: tell_room(TO,"%^BOLD%^%^BLACK%^His insane laughter shakes the walls, almost knocking you off your feet!%^RESET%^"); break;
	 case 3: tell_room(TO,"%^BOLD%^%^WHITE%^He booms: %^BOLD%^%^RED%^Pitiful mortal, you cannot even find me, let alone KILL me! Your quest is HOPELESS!"); break;
     case 4: tell_room(TO,"%^BOLD%^%^BLACK%^You start to wonder if perhaps he is right...%^RESET%^"); break;
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