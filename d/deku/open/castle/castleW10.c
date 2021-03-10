//	/realms/pator/castle/castleW2.c
//	Written by pator@ShadowGate
//	Tue May 9  1995

#include <std.h>
#include <objects.h>

inherit ROOM;

string CASTLE ="/d/deku/open/castle/";

void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_light(1);
    set_indoors(1);
    set_short("Outside the guardquarters");
    set_long(
@HALL
You are in the northwestern tower. When you look around you see thick
stone walls, further there isn't much to see. For those who want to climb
the castle's tower there is nothing to be pleased about. The staircase is blocked by a pile of rubble. There is a sign on the rubble that says: 'UNDER CONSTRUCTION'
HALL
);
set_smell("default","You smell something horrible from the east.");
set_listen("default","You hear sounds from above");
    set_exits(([
       "east" : CASTLE+"castleW11.c",
       "southwest" : CASTLE+"castleW8.c"
    ] ));
    set_items(([
       "wall" : "The walls are made from stone and are very thick.",
       "walls" : "The walls are made from stone and are very thick.",
       "mess" : "You see what the word tells you : a M E S S !!",
       "pile" : "It is a pile of very heavy rubble.",
       "rubble" : "It looks heavy and it is blocking your way up.",
       "sign" : "It says : ' UNDER CONSTRUCTION '"
    ] ));
}
int up_tower() {
  message("my_action","You can't get up the tower !! Read the sign
!",this_player());
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
      message("my_action","'UNDER CONSTRUCTION '\nBy the Marleen Castle builder
:  Pator",this_player());
      return 1;
    }

    }
}

void init() 
{
       ::init();
       add_action("up_tower","up");
       add_action("sign_read","read");
       }
