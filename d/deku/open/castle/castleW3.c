//	/realms/pator/castle/castleW3.c
//	Written by pator@ShadowGate
//	Tue May 9 1995

#include <castle.h>

inherit ROOM;

int mouse_hole() {
	if (present("castle mouse")) {
		message("my_action","When you look at the hole, you don't notice any strange things",this_player());
				     }
        else {
		message("my_action","When you look at the hole, a little mouse notices you and comes out of the hole. Maybe it is hungry, maybe it is just curious !",this_player());
		new(CASTLE+MONSTER+"C_mouse")->move(this_object());
	      }
      return 1;}

int up_tower() {
  message("my_action","You can't get up the tower !! Read the sign !",this_player());
  return 1;
}

int sign_read(string str)
{
  if (!str)
    { notify_fail("You wanna read what ?????");
      return 0;
    }
  else
    { if (!(str=="sign"))
   {
      notify_fail("You read the "+str+" and find it VERY boring !");
      return 0;
    }
      else
	{
      message("my_action","'UNDER CONSTRUCTION '\nBy the Marleen Castle builder :  Pator",this_player());
      return 1;
    }
    }
}

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_light(1);
    set_indoors(1);
    set_short("Near the western tower");
    set_long(
@PATOR
You are in a room near the westerm tower. When you look around you see thick stone walls, further there isn't much to see. For those who want to climb the castletower there is nothing to be pleased about. The staircase is blocked by a pile of rubble. Also a sign tells you :
' UNDER CONSTRUCTION '.
PATOR
    );
set_smell("default","You smell very damp and hot air.");
set_listen("default","You hear not much, but maybe you notice some mouses behind the walls.");
    set_exits(([
       "north" : CASTLE+"castleW4.c",
       "northeast" : CASTLE+"castleW5.c",
       "east"  : CASTLE+"castleW2.c"
    ] ));
    set_items(([
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
       "pile" : "It is a pile of very heavy rubble.",
       "rubble" : "It looks heavy and it is blocking your way up.",
       "sign" : "It says : ' UNDER CONSTRUCTION '"
    ] ));
}
int init() {
       ::init();
       add_action("up_tower","up");
       add_action("sign_read","read");
       return 1;
       }
