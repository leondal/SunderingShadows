// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("masq_t5c");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^RED%^A %^MAGENTA%^C%^RESET%^%^GREEN%^o%^MAGENTA%^l%^BOLD%^%^WHITE%^or%^RESET%^%^MAGENTA%^f%^GREEN%^u%^BOLD%^%^MAGENTA%^l %^RED%^Tent%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^The hallway is colorful and created from large stripes of heavy tent canvas dyed a bright shade of %^RESET%^white%^BOLD%^%^WHITE%^.  The floors are lined with soft %^RESET%^rugs %^BOL"
	"D%^%^WHITE%^that make your footsteps quiet and add cushioning to the hard ground upon which the tent is pitched.  All along the hallway, doors to private dressing rooms are set out.  Each with a %^RES"
	"ET%^%^ORANGE%^lock %^BOLD%^%^WHITE%^that can only be opened with a specific %^RESET%^%^ORANGE%^key%^BOLD%^%^WHITE%^. %^RESET%^"
	);

    set_smell("default","
%^RESET%^%^ORANGE%^A %^BOLD%^%^WHITE%^sweet%^RESET%^%^ORANGE%^, %^RESET%^%^MAGENTA%^delicate %^ORANGE%^fragrance graces the air.%^RESET%^");
    set_listen("default","Laughter and merriment echo through the tent.");

    
set_items(([ 
	({ "canvas", "walls", "tent" }) : "%^BOLD%^%^WHITE%^In this hall, the tent panels are all a nice shade of %^RESET%^white%^BOLD%^%^WHITE%^.  Made from heavy canvas, they look to be thick enough to prevent wind or much noise to pass through them.%^RESET%^",
	({ "floor", "carpet", "rug", "rugs" }) : "%^BOLD%^%^WHITE%^The soft, cushioning carpets pad the ground and silence footfalls within the hallway.  Woven like tapestries, there must be several layers of them to make them so comfortable to walk upon.%^RESET%^",
	]));

    set_exits(([ 
		"southeast" : "/d/av_rooms/lurue/masq_t54",
		"north" : "/d/av_rooms/lurue/masq_t5b",
		"south" : "/d/av_rooms/lurue/masq_t55",
		"southwest" : "/d/av_rooms/lurue/masq_t56",
	]));
    set_pre_exit_functions(({"south","southeast","southwest"}),({"room_south","room_southeast","room_southwest"}));
}

void init() {
   ::init();
   add_action("sneaky_fun","sneak");
}

int sneaky_fun(string str) {
   notify_fail("There doesn't seem to be enough cover to sneak around in here.");
   return 0;
}

int room_south(string str) {
   if(!present("masq_key_55",TP) && !avatarp(TP)) {
     tell_object(TP,"You can't seem to pass through the doorway. You will need key 55 to enter here.");
     return 0;
   }
   tell_object(TP,"The key in your hand hums as you pass through the doorway.");
   return 1;
}

int room_southeast(string str) {
   if(!present("masq_key_54",TP) && !avatarp(TP)) {
     tell_object(TP,"You can't seem to pass through the doorway. You will need key 54 to enter here.");
     return 0;
   }
   tell_object(TP,"The key in your hand hums as you pass through the doorway.");
   return 1;
}

int room_southwest(string str) {
   if(!present("masq_key_56",TP) && !avatarp(TP)) {
     tell_object(TP,"You can't seem to pass through the doorway. You will need key 56 to enter here.");
     return 0;
   }
   tell_object(TP,"The key in your hand hums as you pass through the doorway.");
   return 1;
}