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
  set_long("%^BOLD%^%^BLUE%^Bed of Privacy%^RESET%^\n"
           "The bed looks big and comfortable...cozy for 2. The curtains "
           "surround the bed enclosing you in privacy and comfort.");
  set_smell("default","The linens smell fresh and clean.");
  set_listen("default","A gentle breeze rustles the curtains.");
  set_items( ([
     "curtains" : "They are warm in color and heavy. One would need to "
                  "draw them in order to leave."
	      ]) );
  }

void init()
{
  object *obs;
  int i, flag;
  obs = all_living(TO);
    for(i=0;<sizeof(obs);i++)
    if(interactive(obs[i])) flag++;
  if(flag > MAXPEOPLE){
    write("%^BOLD%^WHOOPS! This room is in use!%^RESET%^\n");
  return;
  }
  ::init();
  add_action("draw","draw");
  }

int draw(string str)
{
  if(str != "curtains" || str != "curtain")
  tell_room(environment(TP), TPQCN+" draws back the curtains and leaves.",TP);
  tell_object(TP,"You draw back the curtains and leave its privacy.");
  TP->move_player("/d/darkwood/forest/village/room5.c");
  return 1;
}

     

