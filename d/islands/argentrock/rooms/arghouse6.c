#include <std.h>
#include "/d/islands/argentrock/argabbr.h"

inherit VAULT;

int key_avai;

void create() {
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set("short","%^BOLD%^%^RED%^The corridor");
    set("long","%^BOLD%^%^RED%^The corridor
%^RESET%^%^CYAN%^You are walking along a dark corridor. No windows are here but there is a small lantern hanging on the wall as well as some strange paintings. A large %^BOLD%^%^CYAN%^door%^RESET%^%^CYAN%^ is to the west.%^RESET%^
");
    set_property("indoors",1);
    set_property("no teleport",1);
    set_property("light",1);
    set_listen("default","You hear your own footsteps.");
    set_smell("default","You smell some stronger choking smells.");
    set_exits( (["east":PATH+"arghouse7",
                 "west":PATH+"arghouse5"]) );
    set_door("door",PATH+"arghouse5",
             "west","orange key");
    set_locked("door",1);
    set_open("door",0);
    set_string("door","open","The door opens with a loud sound. You're "+
               "afraid that you have awakened anything that lives here.");
    set_string("door","close","The door shuts without a sound.");
    set_string("door","lock","With a 'chin' sound, the door locked.");
    set_string("door","unlock","You unlock the door with the orange key, "+
               "some smoke rises from the key hole.");
    key_avai = 1;
}

int search_key(string str) {
    if(!str) {
        notify_fail("Search what?\n");
        return 0;
    }
    if(str == "cracks") {
        if(present("orange key",TP) || key_avai == 0) {
             say(TPQCN+" finds nothing in the cracks.");
             write("You find nothing in the cracks.");
            return 1;
        }
    new(OBJ+"argokey.c")->move(TP);
     write("You find a strange key.");
     say(TPQCN+" finds a strange key.");
    key_avai = 0;
    return 1;
    }
}
void init() {
    ::init();
    add_action("search_key","search");
}

void reset() {
    ::reset();
    if(key_avai == 0)
    key_avai++;
    set_locked("door",1);
    set_open("door",0);
}

