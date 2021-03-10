#include <std.h>
#include "../tunnel.h"

inherit TUNNELS + "mouthroom";


void create(){
  ::create();
  set_exits(([
                "north":TUNNELS + "tun05",
                "south":TUNNELS + "deadend",
      ]));

  set_door("metal door",TUNNELS + "deadend","south",0);

  set_door_description("metal door","%^BOLD%^%^BLACK%^A solid door of "
                                   +"%^RESET%^impenetrable-looking"
                                   +" %^BOLD%^%^BLACK%^black"
                                   +" iron%^RESET%^");
  
  set_lock_description("metal door","lock","%^MAGENTA%^A %^BOLD%^"
                      +"%^YELLOW%^complex%^RESET%^%^MAGENTA%^,"
                      +" tricksy-looking five tumbler"
                      +" lock arrangement");

  lock_difficulty("metal door",50,"lock");

}

GoThroughDoor()
{

  int hold = ::GoThroughDoor();
  if (hold == 0)
  {
    return 0;
  }

  if (!TP->is_player()||TP->query_true_invis())
  {
    return 1;
  }

  find_object_or_load(TUNNELS+"deadend")->slam_door();
  slam_door();
  return 1;
}

int slam_door()
{
  call_out("slam_door2",1);
}

int slam_door2()
{
  tell_room(TO,"%^BOLD%^%^BLUE%^The%^RESET%^ solid metal door %^BOLD%^"
              +"%^BLUE%^slams suddenly shut with a loud %^BOLD%^"
              +"%^YELLOW%^CLANG%^BLUE%^, sealing the way south."
              +"%^RESET%^");

  set_open("metal door",0);
  set_locked("metal door",1,"lock");
}

void enter_from_north()
{
  mouthsay("Now this time, I hope you will take me seriously. The next"
          +" room is very dangerous. Really. You would be much better"
          +" going back and finding another way.");
}