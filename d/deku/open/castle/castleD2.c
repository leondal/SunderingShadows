//	/realms/pator/castle/castlecD2.c
//	Written by pator@ShadowGate
//	Tue May 2 1995

#include <castle.h>

inherit ROOM;


int sit_down()
{
 if (!(present("svilluulla")))
	{
	new(CASTLE+MONSTERS+"/C_demon")->move(this_object());	
	return 1;
	}
  else
	{
	return 0;
	}
}

void init() 
  {
  ::init();
  add_action("sit_down","sit"); 
  }

void reset() 
    {
    ::reset();
    if (!(present("svilluulla")))
	new(CASTLE+MONSTERS+"C_demon")->move(this_object());
    }

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(FOOT_PATH);
    set_light(1);
    set_indoors(1);
    set_short("In the dungeon");
    set_long(
@PATOR
You stand inside the dungeon. Here the convicted were often left to die.
The men who must have lied here were not to be envied !!
PATOR
    );
    set_smell("default","You smell very damp and unpleasant air.");
    set_exits((["down" : CASTLE+"castleD3.c",
		"southwest" : CASTLE+"castleD1.c" ]));
    set_items(([
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
       "equipment" : "This equipment is old,broken but still looks evil.",
    ] ));
}


