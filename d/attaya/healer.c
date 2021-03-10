//  Made READABLE By FireDragon
//

#include <std.h>
#include <objects.h>
#include <money.h>
#include <move.h>

inherit HEALER;


void create() 
{
   ::create();
  set_light(3);
   set_property("training",1);
  set_indoors(1);
  set_short("%^CYAN%^%^BOLD%^Attaya Surgery");
 set_long("%^BOLD%^%^CYAN%^This shop is set up more like a black magic shop than a healer, yet the sign on the door claims that Ironklaw can heal your wounds. All around you are numerous shelves of creepy stuff. A metal chair, complete with binding straps and arms that can only be described as torture devices sits in the center of the room...
A %^BLUE%^list%^CYAN%^ on the wall offers healing choices and services.
");
  set_smell("default", "The strong odor of herbs and balms turns your "
                       "stomach.");
  set_listen("default", "A mysterious hum seems to eminate from the walls "
);
  set_exits( ([
	"south" : "/d/attaya/seneca1"
           ] ));
   set_name("Ironklaw");
}




void reset()
{
  ::reset();
    if(!present("healer")) 
      new("/d/attaya/mon/healer.c")->move(TO);
}


