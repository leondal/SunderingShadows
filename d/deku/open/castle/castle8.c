//	castle8.c
//	Written by Pator@ShadowGate
//	Wed May 3  1995

#include <castle.h>

inherit ROOM;

int get_it(string str)
{
  if (!str) 
      {  notify_fail("You try to get something for nothing from somewhere ??\n");
	return 0;
     }
  else
     { if ( str == "candlestick" )
	{ if ((int)this_player()->query_level() > 6)
	  { 
            message("my_action","Naaah...... don't bother "+(string)this_player()->query_cap_name()+" ! This is no weapon for you !!!\n",this_player());
	    
            message("other_action","The candelstick is a newbie weapon so "+(string)this_player()->query_cap_name()+" fails utterly in lifting it !\n",environment(this_player()));
	    return 1;
	 }
	 else { return 0; }
	}
       else { return 0; }
       }
}

void create() {
    ::create();
   set_terrain(GARDEN);
   set_travel(FOOT_PATH);
	set_author("pator");
    set_light(2);
    set_indoors(0);
    set_short("In the castleyard.");
    set_long(
@CASTLEYARD
 You are in the hallway between the large castleyard and the dining
room. The dining room is to the north and the yard to the south. You 
notice that you are underneath the queen's balcony.
CASTLEYARD
    );
set_smell("default", "You smell nothing special.");
set_listen("default","You hear sounds from the yard.");
    set_exits(([
       "south" : CASTLE+"castle7",
       "north" : CASTLE+"castleE10"
    ] ));
    set_items(([
       "grass" : "The grass grows between the stones and makes the yard look very unpreserved !",
       "stones" : "The stones make up the yard, but grass is growing between them."
    ] ));
}

void init(){
    ::init();
    add_action("get_it", "get");
}

void reset(){
    ::reset();
    if(!present("candlestick"))
      new(CASTLE+OBJECTS+"candlestick")->move(TO);
}
