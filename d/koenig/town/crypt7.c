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
  set_long("%^BOLD%^%^BLACK%^You are cast back into darkness here. This search for the Crypt Keeper is "+
"beginning to get a bit frustrating. It is still dark, and still spooky, and you find that your patience is also growing a bit thin. "+
"You start to wonder why he doesn't come find you, if he wants to end you so bad.");
  set_exits( ([
     "southeast" : "/d/koenig/town/crypt6",
     "southwest" : "/d/koenig/town/crypt9",
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
     case 0: tell_room(TO,"%^BOLD%^%^WHITE%^A booming voice surrounds you: %^RED%^My patience is almost at an end, mortal."); break;
     case 1: tell_room(TO,"%^BOLD%^%^BLACK%^You can almost hear the sneer in his voice.%^RESET%^"); break;
     case 3: tell_room(TO,"%^BOLD%^%^WHITE%^He booms: %^BOLD%^%^RED%^You better hurry, before I send some of my minions out to gather you up and bring you here!"); break;
	 case 4: tell_room(TO,"%^BOLD%^%^BLACK%^The deep voice reverberates through these halls and through your head, before fading into silence.%^RESET%^"); break;
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
