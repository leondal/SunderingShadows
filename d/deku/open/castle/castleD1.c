//	/realms/pator/castle/castlecD1.c
//	Written by pator@ShadowGate
//	Tue May 2 1995

#include <castle.h>

inherit ROOM;

int found;

void init() 
  {
  ::init();
  write("As you enter this you room, you feel a cold shiver goin' down your spine !\n");
  write("How very odd this is, because the room is very hot !!\n");
   add_action("search_fun","search");
  }

void reset() 
    {
    ::reset();
   found = 0;
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
You stand inside the dungeon. Because there are no real knights left this room hasn't been used for a long time. All you see are some wooden benches
and some old torture equipment. When you look at it closely you see that it
it can't be used anymore for torturing, but they still radiate the evil that was done with it.
PATOR
    );
    set_smell("default","You smell very damp and unpleasant air.");
    set_exits((["up" : CASTLE+"castleE4.c",
		"northeast" : CASTLE+"castleD2.c" ]));
    set_items(([
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
       "equipment" : "This equipment is old,broken but still looks evil.",
    ] ));
}

int search_fun(string str){
  object ob;
  if(str || found) return 0;
   else{
     ob=new("/d/magic/scroll");
     ob->set_spell_name("hold person");
     ob->move(TO);
     found = 1;
     return 1;
   }
}
