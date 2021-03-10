// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit ROOM;

void create()
{
    ::create();
    set_name("masq_m2");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("stone building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^RESET%^%^MAGENTA%^Land of %^WHITE%^Mist%^MAGENTA%^ and %^BOLD%^%^CYAN%^Dreams%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^Extravagant and large, the ballroom seems to stretch into a much larger space then the building suggests it might.  To the east a pair of %^RESET%^%^ORANGE%^golden %^BOLD%^%^WHITE%^do"
	"uble doors stands open, leading back into the foyer and the %^RESET%^%^MAGENTA%^portal %^BOLD%^%^WHITE%^that might return attendees to the Realm.  To the west a %^RESET%^%^GREEN%^g%^ORANGE%^a%^RESET%^"
	"r%^GREEN%^d%^BOLD%^%^BLACK%^e%^RESET%^%^GREEN%^n %^BOLD%^%^WHITE%^can be seen, twilight filled and lightly bathed in soft %^RESET%^mist%^BOLD%^%^WHITE%^.  The ballroom itself though is stunning with i"
	"ts %^RESET%^white marble walls %^BOLD%^%^WHITE%^and polished %^RESET%^%^ORANGE%^gold %^BOLD%^%^WHITE%^wood floors.   Huge spheres of %^MAGENTA%^cr%^WHITE%^y%^RESET%^%^MAGENTA%^s%^BOLD%^tal %^BOLD%^%^W"
	"HITE%^hang high above in the vaulted ceiling, their multi colored forms casting varying shades of light down upon the floor.  To the south a wide stage stretches, its raised platform sectioned into tw"
	"o parts.  One a small area where %^RESET%^%^MAGENTA%^musicians %^BOLD%^%^WHITE%^play, the other, larger portion dedicated to the performers that will take the stage throughout to present their stories"
	".  Stretching around the upper half of the room, a recessed %^RESET%^%^MAGENTA%^b%^BOLD%^%^BLACK%^a%^RESET%^l%^MAGENTA%^co%^BOLD%^%^BLACK%^n%^RESET%^%^MAGENTA%^y %^BOLD%^%^WHITE%^can be seen, where se"
	"ating and refreshments can be found. The low railing providing a perfect view of the stage and the ball below.  A sweeping set of stairs leads up to the balcony above.%^RESET%^"
	);

    set_smell("default","
A faint, rich scent of flowers and earth lingers here.");
    set_listen("default","You can hear the pleasant sounds of laughter and conversation.");

    
set_items(([ 
	({ "balcony", "stairs" }) : "%^RESET%^%^MAGENTA%^A sweeping curve of stairs rises up to the back of the ballroom, leading up to a large horseshoe shaped balcony that is recessed back into the wall, leaving the ballroom itself open with high ceilings.  From what you can see of the balcony, it is a sitting area where people can go to relax between songs and performances.%^RESET%^",
	({ "spheres", "ceiling", "crystals", "crystal shards", "shards", "light", "magical light" }) : "%^BOLD%^%^MAGENTA%^Globes of brilliant crystal hang from the ceiling.  Alight with a magic that gives the crystals a purplish glow but which sheds white light down onto the ballroom floor.%^RESET%^",
	({ "walls", "wall", "marble" }) : "%^BOLD%^%^WHITE%^Lined with slabs of pale white marble, the walls of the ballroom rise high overhead into a vaulted ceiling.  The pale marble veined with faint lines of quartz that catches the light and glints in the light shed by the illuminated crystals above.%^RESET%^",
	({ "garden", "mist", "twilight" }) : "%^RESET%^%^GREEN%^Outside a small garden can be seen, a lovely looking marble fountain spilling water over several tiers.  Beyond the garden a hedge maze extends over which a perpetual sense of twilight fills the mist shrouded air.%^RESET%^",
	({ "doors", "double doors", "golden doors" }) : "%^RESET%^%^ORANGE%^Standing open, these doors look to be made from solid gold that has been burnished with a dulling agent to give them an aged look.  Though still stunning from the intricate art that has been molded onto them, the doors do not blaze with reflected light, but rather glow softly.%^RESET%^",
	"musicians" : "%^RESET%^%^MAGENTA%^You can see that part of the stage has been sectioned off for the musicians that keep the ballroom filled with music.  Each musician seems to be capable of several instruments, changing them out with each song so that the melodies never become repetitive.%^RESET%^",
	]));

    set_exits(([ 
		"stairs" : "/d/av_rooms/lurue/masq_m4",
		"east" : "/d/av_rooms/lurue/masq_m1",
		"stage" : "/d/av_rooms/lurue/masq_m3",
		"garden" : "/d/av_rooms/lurue/masq_m5",
	]));

}

void reset(){
   ::reset();
   if(!present("stage")) new("/d/av_rooms/lurue/masq/stage")->move(TO);
}
