//	Krugan's Boathouse
//	Pator@Shadowgate
//	04/06/95
//	Darkwood Forest Area
//	boathouse1.c

#include <boathouse.h>

inherit ROOM;


void create() {
    ::create();
    set_light(2);
    set_indoors(0);
    set_short("Krugan's Boathouse");
	set("day long",
@PATOR
You are on a ramshackle wooden bridge crossing a stream towards Krugan's 
boathouse.  When you look at the wood you see that a repair wouldn't harm the 
bridge to much.  As you realize that you decide to walk a bit faster.  You notice that the big wooden doors are open.  Also a sign can be seen from here.
PATOR
);

set("night long",
@PATOR
You are on a ramshackle wooden bridge towards Krugan's boathouse.
You can't make out the features of the bridge, but it doesn't feel stable.  When  you realize that you decide to walk a bit faster.  You can make out a sign.
PATOR
);
    set_items( (["bridge" : "You don't feel like looking for too long !!!",
                 "sign" : "This sign is newly painted, so try reading it !" ]) );
    set_listen("default", "You hear the quiet rippling of the water");
    set_listen("water", "It is rippling very calmly.");
    set_smell("default", "You scent tar and wet wood");
    set_exits(
              (["east" : WATERMARGIN+"street1",
		"west" : WATERM_BH+"boathouse2"]) );

}

int read(string str)
{ int x;
  if (str == "sign")
    { write("\n\t ==-0-==-0-==-0-== Krugan's boathouse. ==-0-==-0-==-0-==\n");
      write("\t Welcome adventures :\n ");
      write("You can travel from here to the following places :\n");
      write("\t 1) Marleen's castle near deku.\n");
      write("\nThis service is initially free, but there could be fares later !!\n\n");
      return 1;
    }
  else
    { notify_fail("I hope you brought a book !!\n");
      return 0;
    }
}
      

void init()
  {
  ::init();
    add_action("read","read");
  }
