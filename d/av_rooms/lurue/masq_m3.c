// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit ROOM;

void create()
{
    ::create();
    set_name("masq_m3");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^RESET%^%^MAGENTA%^Land of %^WHITE%^Mist%^MAGENTA%^ and %^BOLD%^%^CYAN%^Dreams%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^Sectioned into two parts, the %^RESET%^%^MAGENTA%^musician's section %^BOLD%^%^WHITE%^is small and quartered off with %^RESET%^%^ORANGE%^gold poles %^BOLD%^%^WHITE%^and %^RESET%^%^MAG"
	"ENTA%^purple ropes%^BOLD%^%^WHITE%^.  The majority of the stage is, however, left open for the evening's performers.  Designed to be seen by both those in the %^RESET%^%^ORANGE%^ballroom %^BOLD%^%^WHI"
	"TE%^and the %^RESET%^%^MAGENTA%^balcony%^BOLD%^%^WHITE%^ above, magic causes the performer to be seen to their best advantage no matter where the watcher might be standing.  Further, sitting off to th"
	"e side, a small %^RESET%^%^ORANGE%^f%^RESET%^u%^GREEN%^r%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^y %^BOLD%^%^WHITE%^creature, much like a %^RESET%^rabbit %^BOLD%^%^WHITE%^with %^RESET%^%^ORANGE%^antlers%^"
	"BOLD%^%^WHITE%^, sits resting.  As odd as he is, there must be something important about him though you can't imagine what beyond his strange appearance.\n%^RESET%^"
//"  Beside his seat a %^RESET%^%^MAGENTA%^sign %^BOLD%^%^WHITE%^has been set, perhaps you should %^RESET%^%^MAGENTA%^read %^BOLD%^%^WHITE%^it. %^RESET%^"
	);

    set_smell("default","A faint, rich scent of flowers and earth lingers here.");
    set_listen("default","You can hear the pleasant sounds of laughter and conversation.");

    
set_items(([ 
        ({ "musicians", "rope", "poles", "pole", "ropes" }) : "%^RESET%^%^MAGENTA%^You can see that part of the stage has been sectioned off for the musicians that keep the ballroom filled with music.  Each musician seems to be capable of several instruments, changing them out with each song so that the melodies never become repetitive.  While there is only a simple set of golden poles with a large purple rope strung between them, you imagine that it would be frowned upon to go over and disturb these "
"professional performers.%^RESET%^",
        ({ "balcony", "ballroom" }) : "%^BOLD%^%^WHITE%^The ballroom is a large and spacious affair, much larger then seems possible.  Circling it and set into the walls, a dark balcony wraps all the way around the room, giving an intimate place to sit and relax, watch your performance or the dancers below.%^RESET%^",
        ({ "stage", "platform" }) : "%^ORANGE%^The stage that you stand on is huge and made of polished wood that gleams in the light.  A whole troop of performers could put on a full scale play here and still have room left over.  There's more then enough room for anything you plan to do and you're certain that everyone in the ballroom and balcony will be able to have a clear view.%^RESET%^",
//        "sign" : ({"%^BOLD%^%^MAGENTA%^You're certain there is something important on this sign, you probably should read it.%^RESET%^","%^ORANGE%^The feystag will translate your speech so all viewers can understand it. Just %^YELLOW%^<translate>%^RESET%^%^ORANGE%^ before you begin, and %^YELLOW%^<translateoff>%^RESET%^%^ORANGE%^ when you are done. Please note that all you say and do upon this stage is visible to any spectators in the ballroom or upon the balcony.","wizish"}),
	]));

    set_exits(([ 
		"ballroom" : "/d/av_rooms/lurue/masq_m2",
	]));

}

void reset(){
   object scry_object;
   ::reset();
   if(!present("StageListenerM2")){
      scry_object = new("/d/av_rooms/lurue/masq/stagelistenerm2");
      scry_object->set_caster("/d/av_rooms/lurue/masq_m2.c");
      scry_object->set_target("/d/av_rooms/lurue/masq_m3.c");
      scry_object->move(TO);
   }
   if(!present("StageListenerM4")){
      scry_object = new("/d/av_rooms/lurue/masq/stagelistenerm4");
      scry_object->set_caster("/d/av_rooms/lurue/masq_m4.c");
      scry_object->set_target("/d/av_rooms/lurue/masq_m3.c");
      scry_object->move(TO);
   }
}
