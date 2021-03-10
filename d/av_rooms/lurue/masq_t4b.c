// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("masq_t4b");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("wood building");
    set_travel("slick floor");
    set_climate("temperate");

    set_short("%^BOLD%^%^RED%^A %^MAGENTA%^C%^RESET%^%^GREEN%^o%^MAGENTA%^l%^BOLD%^%^WHITE%^or%^RESET%^%^MAGENTA%^f%^GREEN%^u%^BOLD%^%^MAGENTA%^l %^RED%^Tent%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^The hallway is colorful and created from large stripes of heavy tent canvas dyed a bright shade of %^RESET%^%^MAGENTA%^magenta%^BOLD%^%^WHITE%^.  The floors are lined with soft %^RESE"
	"T%^%^MAGENTA%^rugs %^BOLD%^%^WHITE%^that make your footsteps quiet and add cushioning to the hard ground upon which the tent is pitched.  All along the hallway, doors to private dressing rooms are set"
	" out.  Each with a %^RESET%^%^ORANGE%^lock %^BOLD%^%^WHITE%^that can only be opened with a specific %^RESET%^%^ORANGE%^key%^BOLD%^%^WHITE%^. %^RESET%^"
	);

    set_smell("default","
%^RESET%^%^ORANGE%^A %^BOLD%^%^WHITE%^sweet%^RESET%^%^ORANGE%^, %^RESET%^%^MAGENTA%^delicate %^ORANGE%^fragrance graces the air.%^RESET%^");
    set_listen("default","Laughter and merriment echo through the tent.");


    set_exits(([ 
		"northeast" : "/d/av_rooms/lurue/masq_t43",
		"south" : "/d/av_rooms/lurue/masq_t4a",
		"north" : "/d/av_rooms/lurue/masq_t4c",
		"west" : "/d/av_rooms/lurue/masq_t48",
		"east" : "/d/av_rooms/lurue/masq_t42",
		"northwest" : "/d/av_rooms/lurue/masq_t47",
	]));
    set_pre_exit_functions(({"west","northwest","east","northeast"}),({"room_west","room_northwest","room_east","room_northeast"}));
}

void init() {
   ::init();
   add_action("sneaky_fun","sneak");
}

int sneaky_fun(string str) {
   notify_fail("There doesn't seem to be enough cover to sneak around in here.");
   return 0;
}

int room_west(string str) {
   if(!present("masq_key_48",TP) && !avatarp(TP)) {
     tell_object(TP,"You can't seem to pass through the doorway. You will need key 48 to enter here.");
     return 0;
   }
   tell_object(TP,"The key in your hand hums as you pass through the doorway.");
   return 1;
}

int room_northwest(string str) {
   if(!present("masq_key_47",TP) && !avatarp(TP)) {
     tell_object(TP,"You can't seem to pass through the doorway. You will need key 47 to enter here.");
     return 0;
   }
   tell_object(TP,"The key in your hand hums as you pass through the doorway.");
   return 1;
}

int room_east(string str) {
   if(!present("masq_key_42",TP) && !avatarp(TP)) {
     tell_object(TP,"You can't seem to pass through the doorway. You will need key 42 to enter here.");
     return 0;
   }
   tell_object(TP,"The key in your hand hums as you pass through the doorway.");
   return 1;
}

int room_northeast(string str) {
   if(!present("masq_key_43",TP) && !avatarp(TP)) {
     tell_object(TP,"You can't seem to pass through the doorway. You will need key 43 to enter here.");
     return 0;
   }
   tell_object(TP,"The key in your hand hums as you pass through the doorway.");
   return 1;
}