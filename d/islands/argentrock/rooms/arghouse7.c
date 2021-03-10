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
%^RESET%^%^CYAN%^You are walking along a dark corridor. No windows are here but there is a small %^WHITE%^la%^BOLD%^%^WHITE%^n%^RESET%^%^WHITE%^ter%^BOLD%^%^WHITE%^n%^RESET%^%^CYAN%^ hanging on the %^BOLD%^%^CYAN%^wal%^BLUE%^l%^RESET%^%^CYAN%^ as well as some strange %^BLUE%^paint%^BOLD%^%^BLUE%^i%^BLUE%^n%^RESET%^%^BLUE%^gs.%^CYAN%^ A large door is to the southwest.%^RESET%^
");
    set_smell("default","You smell some stronger choking smells.");
    set_property("indoors",1);
    set_property("no teleport",1);
    set_property("light",1);
    set_listen("default","You hear your own footsteps.");
    set_exits( (["east":PATH+"arghouse8",
                 "southwest":PATH+"arghouse11",
                 "west":PATH+"arghouse6"]) );
    set_door("door",PATH+"arghouse11",
             "southwest","white key");
    set_locked("door",1);
    set_open("door",0);
    set_door_description("door","%^RESET%^%^CYAN%^There are %^BOLD%^%^BLUE%^g%^CYAN%^aps%^RESET%^%^CYAN%^ between the door frame and the wall.%^RESET%^
");
    set_string("door","open","The door opens with a loud sound. You're "+
               "afraid that you have awakened anything that lives here.");
    set_string("door","close","The door shuts without a sound.");
    set_string("door","lock","With a 'chin' sound, the door locked.");
    set_string("door","unlock","You unlock the door with the white key, "+
               "some smoke rises from the key hole.");
    set_items( (["lantern":"This is a small lantern which lightens up "+
                 "this dark corridor.",
                 "wall":"The wall is made of the same material that this house "+
                 "is built of, wood. And there are lots of cracks in the wall.",
                 "paintings":"These are some oil paintings about the forest. One "+
                 "of them describes a brave adventurer trapped within the forest.",
                 "gaps":"The gaps are wide enough to hide something in it.",
                    ]) );
    key_avai = 1;
}

int search_key(string str) {
    if(!str) {
        notify_fail("Search what?\n");
        return 0;
    }
    if(str == "gaps") {
        if(present("white key",TP) || key_avai == 0) {
             say(TPQCN+" finds nothing in the cracks.");
             write("You find nothing in the cracks.");
            return 1;
        }
    new(OBJ+"argwkey.c")->move(TP);
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

