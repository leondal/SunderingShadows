#include <std.h>
#include "/d/islands/argentrock/argabbr.h"

inherit VAULT;

int key_avai;

void create() {
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
   set_property("indoors", 1);
    set("short","Foyer of a mysterious house");
    set("long","%^BOLD%^%^GREEN%^Foyer of a mysterious house%^RESET%^
You see a mysterious wooden %^ORANGE%^house %^WHITE%^standing right there. There are several %^CYAN%^windows%^WHITE%^. Some smoke comes out of the %^MAGENTA%^chimney %^WHITE%^on top of the house. There is a very dim light coming out of a large %^ORANGE%^window%^WHITE%^. The entrance %^ORANGE%^doorway %^WHITE%^is in front of you. 
"); 
    set_property("light",2);
    set_property("no teleport",1);
    set_smell("default","Some choking smell fills your nose.");
     set_listen("default","It is extraordinarily quiet here, seems all "+
         "living things avoid this place.");
    set_items( (["foyer":"This is quite a large foyer.",
        "windows":"There are several windows here.",
        "house":"This is a wooden house, you wonder who is living here.",
        "chimney":"The chimney is dark and gives out some smoke.",
        "window":"With the help of the dim light you notice a small "+
            "crack in the window frame.",
        ({"door","doorway"}):"The doorway leading into the house."]) );
    set_door("door",PATH+"arghouse4",
        "door","grey key");
    set_locked("door",1);
    set_open("door",0);
     set_string("door","open","The door opens with a loud sound. You're "+
         "afraid that you have awakened anything that lives here.");
    set_string("door","close","The door shuts without a sound.");
    set_string("door","lock","With a 'chin' sound, the door locked.");
    set_string("door","unlock","You unlock the door with the grey key, "+
         "some smoke escapes from the key hole.");
    set_exits( (["door":PATH+"arghouse4",
        "path":PATH+"argpath19"]) );
    key_avai = 1;
}

void init() {
    ::init();
    add_action("search_key","search");
}

int search_key(string str) {
    if(!str) {
        notify_fail("Search what?\n");
        return 0;
    }
    if(str == "crack") {
        if(present("grey key",TP) || key_avai == 0) {
            say(TPQCN+" decided there is nothing else here.");
             write("You decide there is nothing here.");
            return 1;
        }
    new("/d/islands/argentrock/obj/arggkey.c")->move(TP);
    write("You found a strange key.");
    say(TPQCN+" found a strange key.");
    key_avai = 0;
    return 1;
    }
}

void reset() {
    ::reset();
	if(!present("gobo")) 
	  new(MON+"gobo")->move(TO);
    if(key_avai == 0)
    key_avai++;
    set_locked("door",1);
    set_open("door",0);
}
