#include <std.h>

inherit ROOM;

#define MAXPEOPLE 2

int flag;

void create()
{
  ::create();
  set_property("light",1);
  set_property("indoors",1);
  set_short("Bed of Privacy");
  set_long("%^BOLD%^%^BLUE%^Bedroom%^RESET%^\n"
           "There is a bed here that looks big and comfortable. "
           "Just right for 2 people. Curtains cover the rooms only"
           "window and the doors automaticly lock once the room has "
           "2 occupants so that they may retain their privacy and can "
           "rest.");
  set_smell("default","The linens smell fresh and clean.");
  set_listen("default","A gentle breeze rustles the curtains.");
  set_items( ([
     "curtains" : "They are warm in color and blow gently in the breeze."
	      ]) );
  set_exits( ([
     "south" : "/d/darkwood/forest/village/telparlor"
	       ]) );
  }

void init()
{
  object *obs;
  int i, flag;
  obs = all_living(TO);
    for(i=0;i<sizeof(obs);i++)
    if(interactive(obs[i])) flag++;
  if(flag > MAXPEOPLE){
    write("%^BOLD%^WHOOPS! This room is in use!%^RESET%^\n");
  return;
  }
  ::init();
  }


     

