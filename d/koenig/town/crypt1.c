#include <std.h>
inherit VAULT;

int triggered, isrunning;
int do_keeper(int mystate);
int blocked;
int sealed;
int closed;

void init() {
  ::init();
  add_action("open", "open");
  closed = query_open("door");
  sealed = query_locked("door");
  if(closed == 1) {
    set_open("door",0);
    set_locked("door",1);
    "/d/koenig/town/grave1"->set_open("crypt",0);
    "/d/koenig/town/grave1"->set_locked("crypt",1);
    tell_room(environment(TP),"%^BOLD%^%^RED%^The door begins to creak as it closes sealing you in.%^RESET%^\n");
    return 1;
  }
   if(!objectp(TP)) return;
   if(!userp(TP)) return;
   if(TP->query_true_invis()) return;
   if(triggered) return;
   triggered = 1;
   isrunning = 1;
   call_out("do_keeper",1,0);
}


void create() {
  ::create();
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
  set_door("door","/d/koenig/town/grave1","door","life angel key");
  set_open("door",1);
  set_locked("door",0);
  set_property("magic hold",20);
  set_property("no teleport",1);
  set_string("door","unlock","%^BOLD%^%^WHITE%^When you unlock the door you catch a faint "    
             "whiff of fresh air from the outside.\n");
  set_string("door","open","%^BOLD%^%^WHITE%^The door opens so slowly and your desire to be "
             "out of this place is so strong, it's almost painful.\n");
  set_property("light", 0);
  set_property("indoors",1);
  set_short("An Old Crypt");
  set_long("%^BOLD%^%^BLACK%^You are alone in a cold, dark crypt. The stone walls are covered in %^RESET%^%^GREEN%^lichen%^BOLD%^%^BLACK%^, and it seems to be slowly eating away at the rocks. "+
  "There are some %^RESET%^%^ORANGE%^coffins%^BOLD%^%^BLACK%^ strewn about the place, but otherwise there is not very much to see here in this %^RESET%^damp%^BOLD%^%^BLACK%^ and %^RESET%^%^GREEN%^decaying%^BOLD%^%^BLACK%^ place.%^RESET%^\n");
  set_smell("default","You smell stale air, dust, and old corpses.");
  set_listen("default","You hear a BOOMING voice then utter silence.");
  set_items( ([
     ({"room", "floor"}) : "There isn't much to see here, and I wouldn't waste time looking around. But, hmmm, one of the coffins here has no dust....",
     "door" : "There appears to be some kind of etching on it, maybe you should look at it.",
     "etching" : "It appears to be a picture of an angel returning life to a child.",
    "coffin" : (: this_object(), "coffin" :), 
    ]) );
    set_search("default","You certainly notice the coffins and that one of them "
       "has no dust on it.");
    set_search("coffins", "One of them has no dust on it and looks like it's "
       "been opened recently.");
  set_exits( ([
     "door" : "/d/koenig/town/grave1"
  ]) );
}

int do_keeper(int mystate) {
   object thatroom;
   switch(mystate) {
     case 0: tell_room(TO,"%^BOLD%^%^WHITE%^A booming voice surrounds you: %^RED%^You foolish mortal! You have entered the place of your DOOM!"); break;
     case 1: tell_room(TO,"%^BOLD%^%^BLACK%^Deafening, demonic laughter rings through your head.%^RESET%^"); break;
     case 2: tell_room(TO,"%^BOLD%^%^WHITE%^The voice continues: %^RED%^In case you have not yet figured out who this is, let me tell you. I am the Crypt Keeper! "+
	 "If you wish to make it out of here alive you will need to find me."); break;
     case 3: tell_room(TO,"%^BOLD%^%^WHITE%^He booms: %^BOLD%^%^RED%^And then you will have to defeat me!"); break;
	 case 4: tell_room(TO,"%^BOLD%^%^BLACK%^Manical laughter shakes the very foundations of the crypt.%^RESET%^"); break;
     case 5: tell_room(TO,"%^BOLD%^%^WHITE%^The voice booms out: %^RED%^I am waiting for you, mortal, and already my patience grows thin."); break;
     case 6: tell_room(TO,"%^BOLD%^%^BLACK%^Suddenly, silence fills the cramped chamber...%^RESET%^"); break;
       isrunning = 0;
       return 1;
     break;
   }
   mystate++;
   call_out("do_keeper",5,mystate);
   return 1;
}


void reset() {
  ::reset();
  remove_exit("down");
  blocked = 0;
}

int open(string str) {
  if(!str || str != "coffin") {
  notify_fail("Open what?\n");
  return 0;
}
write("You open the coffin and find stairs leading down.");
say(this_player()->query_cap_name()+ " opens the coffin and finds stairs leading downward.", this_player());
  add_exit("/d/koenig/town/crypt2","down");
  blocked = 1;
  return 1;
}
string coffin(string str) {
  if(blocked) return "It is closed.";
  else return "It sits on a large pier in the middle of the crypt.";
}


void reset_cinematics() { triggered = 0; }
int is_running() { return isrunning; }
