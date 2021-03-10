#include <std.h>
#include <terrain.h>
#include "../tunnel.h"
inherit TUNNELS + "mouthroom";


void create() {
  ::create();

  set_exits( ([ "southeast" : TUNNELS + "ugstream" ,
	          "northeast" : TUNNELS + "tun17"]) );
  set_post_exit_functions(({"northeast",}),({"GoThroughDoor",}));

}

int GoThroughDoor()
{
  if (!TP->is_player()||TP->query_true_invis())
  {
    return 1;
  }

  find_object_or_load(TUNNELS + "tun17.c")->enter_room();
  return 1;
}

void reset()
{
  ::reset();
}

void enter_room()
{
  if (!present("magicmouth"))
  {
    mouthsay("Be very careful. You will need to be forewarned and"
            +" forearmed, so I will tell you something important...");
    call_out("enter_room2", 8);
  }
}

void enter_room2()
{
  mouthsay("Be wary of the bad things.");
}
