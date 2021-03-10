#include <std.h>
#include "../tormdefs.h"
inherit BATH;
void create(){
  ::create();
   set_short("A steaming sauna");
  set_long(
   "  You are standing in a steaming hot room.  There is so much steam that it"+
   " actually makes it a little hard to make things out, and the lighting in"+
   " here is just about nonexistent.  There is a wooden bench that runs around"+
   " the three sides of the room and is fixed to the wall.  The bench has slits"+
   " in the seats so that the sweat does not sit in pools on it.  In the"+
   " northwest corner there is a large brazier of heated rocks with a bucket"+
   " of water next to it and a ladle to dish water onto the rocks with in case"+
   " you want more steam.  People come here to relax and all the steam is said"+
   " to be great for cleaning the skin and opening up your pores, but most"+
   " people find it difficult to stay in here for long periods of time."
  );
  set_exits(([
   "west" : TCITY+"c114",
  ]));
   set_door("door",TCITY+"c114","west","Torm masterkey");
}

void reset()
{
   ::reset();
}
