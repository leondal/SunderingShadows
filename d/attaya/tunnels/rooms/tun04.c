
#include <std.h>
#include "../tunnel.h"

inherit TUNNELS + "mouthroom.c";

void create(){
    ::create();
      set_exits( ([ "south" : TUNNELS + "tun03" ,
	"northeast" : TUNNELS + "tun05"]) );

}

void enter_room()
{
  if (!present("magicmouth"))
  {
    mouthsay("This next room to the northeast is very deadly. Enter at"
            +" your own risk and ensure your mortal affairs are in"
            +" order.");

    call_out("enter2",8);
  }
}

void enter2()
{
  mouthsay("Or, you could go back the other way. Yes, yes, that would"
          +" probably be best - go back while you still can! Only death"
          +" awaits you up ahead!");
}