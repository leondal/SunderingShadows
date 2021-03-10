
#include <std.h>
#include "../tunnel.h"

inherit TUNNELS + "mouthroom.c";

void create(){
  ::create();
  set_exits( ([ "north" : TUNNELS + "tun15" ,
	          "south" : TUNNELS + "tun13"]) );
  set_post_exit_functions(({"north",}),({"GoThroughDoor",}));

}

void enter_room(){
    call_out("enter_room2",2);
  
}

void enter_room2(){
  if(!present("magicmouth")){
    mouthsay(": You are doing well! Nearly there, in fact. Go on, press"
          +" ahead, for who knows what adventure awaits you?");
  }
}
int GoThroughDoor()
{
  if (!TP->is_player()||TP->query_true_invis())
  {
    return 1;
  }

  find_object_or_load(TUNNELS + "tun15.c")->enter_room(TP);
  return 1;
}
