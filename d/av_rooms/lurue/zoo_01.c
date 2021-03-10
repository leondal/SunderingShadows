// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("zoo_01");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("built cave");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^WHITE%^Cloud Corner Zoo%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^This large cave has been designed with a monster's comfort in mind.  There are thick piles of %^RESET%^%^ORANGE%^rush weeds %^BOLD%^%^BLACK%^and many tall piles of %^RESET%^rocks %^BO"
	"LD%^%^BLACK%^for lounging, hiding or otherwise.  The ground is covered in a deep spill of fine %^YELLOW%^sand %^BOLD%^%^BLACK%^that grows deeper the closer it gets to the large %^CYAN%^pool%^BLACK%^. "
	" Across the ceiling, %^RESET%^netting %^BOLD%^%^BLACK%^and %^RESET%^%^GREEN%^vines %^BOLD%^%^BLACK%^have been arranged giving the roof a canopied appearance, that trails down many parts of the wall.  "
	"Arranged around one side of the pool is a thick cluster of %^RESET%^%^GREEN%^trees%^BOLD%^%^BLACK%^, more then enough to give the illusion of a %^GREEN%^forest%^BLACK%^.  And in the center of these yo"
	"u can make out a few strange structures, almost like a %^RESET%^%^ORANGE%^house %^BOLD%^%^BLACK%^with a %^RESET%^%^MAGENTA%^crypt %^BOLD%^%^BLACK%^or %^RESET%^%^BLUE%^graveyard %^BOLD%^%^BLACK%^beside"
	" it.  Yes, this place could serve as a good holding ground for any monster one might want to house.%^RESET%^"
	);

    set_smell("default","
It smells of the great outdoors and of other things living and dead.");
    set_listen("default","You can hear the sound of something moving around in the landscape.");


    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/hub_01",
	]));

}

void reset(){
   ::reset();
   if(!present("hell hound"))
      new("/d/attaya/newseneca/mon/hound_boss")->move(TO);
   if(!present("sea monster"))
      new("/d/attaya/newseneca/mon/seamonster_boss")->move(TO);
   if(!present("hound 2"))
      new("/d/attaya/newseneca/mon/new_hound")->move(TO);
}
