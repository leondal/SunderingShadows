//Changed Riptide's loading to stop reports of several of him being there
//~Circe~ 6/4/07
#include <std.h>
#include <objects.h>



inherit "/d/attaya/spec/cliff";

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("%^BOLD%^%^BLACK%^Granite pier on the %^RED%^River of Flame");
    set_long("%^BOLD%^%^BLACK%^Granite pier on the %^RED%^River of Flame%^RESET%^
%^RED%^You stand upon a %^BOLD%^%^BLACK%^granite slab%^RESET%^%^RED%^ above a fast moving river of molten metals! Clouds of glowing red sparks and smoke pour past you making you cough and obstructing any view of what lies at the other side of the river.A cliff face begins here and rises into the smoke filled sky. Every now and then, through the smoke, you catch a glimpse of the walls around the crystalline tower of the Black Dawn. The cliff itself is nearly a mile high and quite treacherous. Black steps start here and scale the side of the cliff to a ledgeabout a hundred feet above you.
");

     set_listen("default","The churning river of fire is deafening.");
     set_smell("default","You are forced to cover your nose and mouth as the smoke burns them..");
 
    set_exits(([

       "up" : "/d/attaya/cliff1",

    ] ));
    set_items(([
         "beach" : "The beach is comprised of large boulders and smaller jagged stones, carved by the powerful forces that continue to shape this island.",
         "pier" : "Standing and enduring the oceans torture has seriously compromised the structural integrity of the pier...  In other words...  %^RED%^It would be wise to get off as soon as possible.",
    ] ));
}

void reset(){
   ::reset();
   if(!present("riptide")) 
      new("/d/attaya/mon/riptide2")->move(TO);
}
/*
void init() {
  ::init();
  do_random_encounters(({"/d/attaya/mon/riptide2.c"}),75,1);
}
*/
