#include <std.h>

#include "/d/dagger/road/short.h"
inherit ROOM;
void search_leaves(string str);
int troll_wait;
int items;

void create(){
items = 2;
  ::create();
   set_terrain(HUT);
   set_travel(DIRT_ROAD);
  set_property("light", 2);
  set_property("indoors", 1);
  set_short("The Hut.");
  set("day long",
@GIL
This is the inside of the ramshackle hut.
You know if you were any stupider you'd be in jail.
If I were you I'd be long gone by now.
Since this is the HOME of a Monster!
A crude bed made of a huge pile of leaves lies in one corner
and a heap of curious items are piled in the other.
GIL
);
  set("night long",
@GIL
This is the inside of the ramshackle hut.
If I were you I'd be long gone by now.
Since this is the HOME of a Monster!
A crude bed made of a huge pile of leaves lies in one corner
and a heap of curious items are piled in the other.
GIL
);
set_smell("default", "You can smell the scent of the Hut's owner.");
set_listen("default", "You can hear the river splashing against the rocks
outside.");
  set_items(([
"bed" : "This is a HUGE pile of leaves...hmm it seems to be moving...you could search it and see what it is maybe.",
"hut" : "It's a ramshackle hut throw together under the bridge.",
"items" : "Hmm, they look like junk.",
"heap" : "It certainly draws your interest, perhaps if you search it?",
   "leaves" : "They are moving slightly...search leaves to find out what's there.",
]));

  set_exits(([
"out" : RPATH "bridge2",
]));
set_search("heap",(: this_object(), "do_trash" :));
set_search("items",(: this_object(), "do_trash" :));
troll_wait = 0;
}

void init() {
  ::init();
  add_action("search_leaves", "search");
}
void do_trash(string str) {
    object ob;
    string temp;
  
   if(!random(25) && troll_wait != 1) {
      troll_wait = 1;
      tell_object(TP,"You search through the items but do so a bit too loudly and a troll bursts forth from a pile of leaves!!!");
      tell_room(ETP,""+TPQCN+" searches through the items and makes enough noise to disturb the troll sleeping in the leaves!",TP);
      new(MPATH"btroll")->move(TO);
      return 1;
   }
    if((items > 0) && (random(20) > 16)) {
    write("%^BOLD%^You find something!");
    items--;
   if(random(10) > 4) {
temp = OPATH "necklace.c";
    ob = new(temp);
    ob->move(this_player());
    write("%^RED%^You dig out "+ob->query_short()+" from the heap!");
    return 1;
  }
   else {
      switch(random(4)) {
         case 0:
            ob = new(OPATH"Mcoif");
            break;
         case 1:
         ob = new(OPATH"Mhammer+1");
            break;
         case 2:
            ob = new(OPATH"Mshield+1");
            break;
         case 3:
            ob = new(OPATH"studded+1");
            break;
      }
      ob->move(TP);
      write("%^RED%^You dig out "+ob->query_short()+" from the heap!");
      return 1;
   }
}
    if((items < 1) && (random(10) > 7)) {
    write("%^GREEN%^You decide there is nothing more to find.");
    return 1;
  }
    write("%^BOLD%^%^BLUE%^You find nothing odd.");
    return 1;  
}
  int search_leaves(string str)
{

  object leaves;
  if(str != "leaves" || troll_wait != 0)
  return 0;
    if(present("troll"))
    {
      tell_object(TP,"Don't you think one was enough? \n");
   tell_room(ETP,TPQCN+" has lost "+TP->query_possessive()+" mind, "+TP->query_subjective()+" is searching the leaves for another Troll! RUN AAAWWAAAYYY!!",TP);
     return 1;
}
  troll_wait = 1;
new(MPATH "btroll.c")->move(this_object());
   tell_object(TP, "A Bridge Troll growls and bursts from the pile of leaves!!!");
  tell_room(environment(TP),TPQCN+" searches the leaves!",TP);
  return 1;
}

void reset()
{
  ::reset();
  if(troll_wait != 0)
    troll_wait--;
}
