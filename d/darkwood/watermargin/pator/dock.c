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
    set_short("Krugan's Boathouse dock");
	set("long",
@PATOR
You are on a dock outside Krugan's boathouse. You can rent a boat to several places here. For more information you can read the sign. There is nothing further that attracts your attention
PATOR
);

    set_items( (["dock" : "This dock is newly made out of strong wood.",
                 "sign" : "This sign is newly painted, so try reading it !" ]) );
    set_listen("default", "You hear the quiet rippling of the water");
    set_listen("water", "It is rippling very calmly.");
    set_smell("default", "You scent tar and wet wood");
    set_exits(
              (["south" : WATERM_BH+"boathouse3"]) );

}

int read(string str)
{ int x;
  if (str == "sign")
    { write("\n ==-0-==-0-==-0-==-0-==-0-== Pator's boatrental. ==-0-==-0-==-0-==-0-==-0-==\n");
      write("\t\t\t Welcome adventures :\n ");
      write("\t You can travel from here to the following places :\n");
      write("\t 1) Marleen's castle near deku.\t <castle> \n");
      write("\n\t This service is initially free, but there could be fares later !!\n\n");
      write("\t When you want to rent a boat type : rent boat for <destination>\n\n");
      write("\n ==-0-==-0-==-0-==-0-==-0-== Pator's boatrental. ==-0-==-0-==-0-==-0-==-0-==\n");
      return 1;
    }
  else
    { notify_fail("I hope you brought a book !!\n");
      return 0;
    }
}

int jump(string dest)
{
  switch (dest) 
  {
    case "castle" : dest = MCASTLE_BH+"dock.c"; break;
  }
  this_player()->move_player(dest);
  return 1;
}


int transport(string dest)
{ int x,time;
  switch (dest)
    {
    case "castle" : break;
    default : notify_fail("This is not a pssible place to go to !!\n");
              return 0;break;
    }
  time = random(10)+5;
  for (x=0; x < time*1000; x++)
  { 
   switch (x) {
   case 1000 : write("You are moved in a little boat");break;
              }
  }
  jump(dest);
  return 1;
}
      
int rent(string str)
{ int x;
  string dest;
  if (!str) 
    {
      notify_fail("I didn't know you has rent !!!! :)\n");
      return 0;
    }
  else
    { if (sscanf(str,"boat for %s",dest) != 1)
	{ notify_fail("You just typed some rubbish , my friend !!\n");
	  return 0;
	}
      else
	{ x = transport(dest);
          return x;
	}
    }
}




void init()
  {
  ::init();
    add_action("rent","rent");
    add_action("read","read");
  }
