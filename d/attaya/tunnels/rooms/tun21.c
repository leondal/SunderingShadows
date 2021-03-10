#include <std.h>
#include <terrain.h>
#include "../tunnel.h"
inherit BTUNNEL;


void create() {
  ::create();
  set_long ("%^BOLD%^%^BLACK%^This is a narrow tunnel cut through the"
           +" black rock. It is unclear whether this is a crudely"
           +" constructed tunnel or simply a natural fissure, but the"
           +" walls are steep. The ceiling here is lower than other"
           +" tunnels nearby. ");

  set_exits( ([ "northeast" : TUNNELS + "tun20" ]) );
  add_item("ceiling","The ceiling is lower down here, and you can just"
                    +" about make out the shape of a trap door set in"
                    +" it.");
  add_item("trap door","The trap door looks like you could push it open");
}

void init()
{
  ::init();
  add_action("open_trapdoor", "open");
  add_action("open_trapdoor", "push");
  add_action("close_trapdoor", "close");
}

int open_trapdoor(string str)
{
  if (!objectp(TO)||!objectp(TP)){return 0;}
  if (str=="trapdoor" || str=="trap door")
  {
     if ((string)TO->query_exit("up")==TUNNELS + "summoning")
     {
       tell_object(TP, "The trap door is already open!");
       return 1;
     }
     tell_object(TP,"You push the trap door open.");
     tell_room(TO,TPQCN +" pushes a trap door open in the ceiling.",TP);
     add_exit(TUNNELS+"summoning","up");
     tell_room(find_object_or_load(TUNNELS + "summoning"),"A trap door in"
            +" the floor near the east wall swings open");
     find_object_or_load(TUNNELS+"summoning")->add_exit(TUNNELS + "tun21",            
                                                              "down");
     add_item("trap door","The trap door is open. You could close it.");
     return 1;
  }
 
}

int close_trapdoor(string str)
{
  if (!objectp(TO)||!objectp(TP)){return 0;}
  if (str=="trapdoor" || str=="trap door")
  {
     if ((string)TO->query_exit("up")!=TUNNELS + "summoning")
     {
       tell_object(TP, "The trap door is already closed!");
       return 1;
     }
    tell_object(TP,"You close the trap door.");
    tell_room(TO,TPQCN + " closes a trap door in the ceiling.",TP);
    if(query_exit("up")) {remove_exit("up");}
    if (find_object_or_load(TUNNELS+"summoning")->query_exit("down"))
    {
      find_object_or_load(TUNNELS+"summoning")->remove_exit("down");
      tell_room(find_object_or_load(TUNNELS + "summoning"),"The trap door"
            +" swings closed");
    }       
     add_item("trap door","The trap door looks like you could push it"
             +" open");  
     return 1;
   }
}

