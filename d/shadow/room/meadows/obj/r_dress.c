#include <std.h>
inherit "/std/armour";

void create()
{
   ::create();
   "/d/shadow/room/meadows/obj/d_dress"->create_dress(TO);
   set_wear((:TO,"wearme":));
   set_size(random(3)+1);
}

int wearme()
{
   if((string)TP->query_gender() != "female") {
      notify_fail("This dress was made for a woman!\n");
      return 0;
   }
   return 1;
}
