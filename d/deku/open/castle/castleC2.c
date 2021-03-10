//	/realms/pator/castle/castlec2.c
//	Written by pator@ShadowGate
//	Tue May 2 1995

#include <castle.h>

 int found;

inherit VAULT;

string connecting = CASTLE+"castleC1";

int scroll_search(string str)
{ 
  object ob;
 if (str == "coal" && !found)
    {
      if (present("blackened key",this_player()))
	  { 
	   tell_player(this_player(),"You find a broche.\n");
            ob->new(CASTLE+"object/broche");
	    ob->move(this_player());
            found = 1;
	    return 1;
	  }
       else
	  { 
	    notify_fail("You get dirty hands, but find nothing");
	  }
    }
    return 0;
}

void init() 
  {
  object ob;
  ::init();
  set_open("door",0);
  set_locked("door",0);
  connecting->set_open("door",0);
  connecting->set_locked("door",0);
  ob = find_object(connecting);
  tell_room(ob,"The door slams shut as "+(string)this_player()->query_cap_name()+" walks through it !!",({}));
  tell_room(environment(this_player()),"The door slams shut as "+(string)this_player()->query_cap_name()+" walks through it !!",({ this_player() }));
  tell_player(this_player(),"The door slams shut as you walk through it !!");
  add_action("scroll_search","search");
  }

void reset() 
    {
    ::reset();
      found = 0;
    }

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_light(1);
    set_indoors(1);
    set_short("Inside the coal room");
    set_long(
@PATOR
You are inside the castle coal room. Here the coal is stored and when you look around you see that there is more coal than you'll ever use in your life.
You see a hadge in the roof. It is far to high up to get too, but you are sure
that the coalman dumps the coal through it ! 
PATOR
    );
    set_smell("default","You smell the foods lying around here.");
    set_exits((["out" : CASTLE+"castleC1.c" ]));
    set_invis_exits(({"out"}));
    set_items(([
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
       "coal" : "The coal is lying here so the cook can cook the food. It is very black and you wonder if it hides something",
       "hadge" : "It is high up, but also closed from the outside"
    ] ));
       set_door("door",connecting,"out","blackened key");
       set_string("open","door","The door opens with a horrible sound !!\n");
}



