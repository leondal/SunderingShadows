
#include <std.h>
#include "../tunnel.h"

inherit BTUNNEL;

void reset()
{
  ::reset();
  if (sizeof(all_living(TO))== 0)
  {
    if (present("magicmouth"))
    {
      present("magicmouth")->remove(TO);
    }
  }
}

int makemouth(string message)
{
  if (!objectp(TO)){return 0;}
  new(OBJ+"magicmouth.c")->move(TO);
  call_out("makemouth2",2, message);
  return 1;
}

int mouthsay(string str) {
  if (!objectp(TO)){return 0;}
  if (present("magicmouth"))
  {
    tell_room(TO, "%^MAGENTA%^The %^RESET%^magic mouth%^MAGENTA%^ intones"
                 +" sonorously:%^GREEN%^ " + str);

    return 1;
  }
  else 
  makemouth(str);
  return 1;
}

int makemouth2(string str)
{
  tell_room( TO, "The rock walls seem to contort in front of you, grating"
                +" silently into a new shape as a giant pair of smirking"
                +" lips is formed. The mouth favours you with a brief"
                +" grin before starting to speak.");

  call_out("makemouth3",2, str);
  return 1;
}

int makemouth3(string str)
{
  if (!objectp(TO)){return 0;}
  mouthsay(str);
  return 1;
}


