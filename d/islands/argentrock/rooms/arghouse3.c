#include <std.h>
#include "/d/islands/argentrock/argabbr.h"

inherit VAULT;

int key_avai;

void create() {
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set("short","%^RED%^The corridor");
    set("long","%^RED%^The corridor
%^RESET%^%^CYAN%^You are walking along a dark corridor. No windows are here but there is a small %^BOLD%^%^CYAN%^lantern%^RESET%^%^CYAN%^ hanging on the %^BOLD%^%^CYAN%^wall%^RESET%^%^CYAN%^ as well as some strange paintings. A large %^BOLD%^%^CYAN%^doo%^BLUE%^r%^RESET%^%^CYAN%^ is located towards the west end of the corridor.%^RESET%^
");
    set_property("indoors",1);
    set_property("no teleport",1);
    set_property("light",1);
    set_listen("default","You hear your own footsteps.");
    set_smell("default","You smell some choking smells.");
    set_items( (["lantern":"This is a small lantern which lightens up "+
                 "this dark corridor.",
                 "wall":"The wall is made of the same material as this house is "+
                 "built of, wood. And there are lots of cracks in the wall.",
                 "paintings":"These are some oil paintings about the forest. One "+
                 "of them describes a brave adventurer trapped within the forest.",
                 "door":"You are not sure where the door leads."]) );
    set_exits( (["south":PATH+"arghouse4",
                 "west":PATH+"arghouse2"]) );
    set_door("door",PATH+"arghouse2",
             "west","brown key");
    set_locked("door",1);
    set_open("door",0);
    set_string("door","open","The door opens with a loud sound. You're "+
               "afraid that you have awakened anything that lives here.");
    set_string("door","close","The door shuts without a sound.");
    set_string("door","lock","With a 'chin' sound, the door locked.");
    set_string("door","unlock","You unlock the door, "+
               "some smoke comes out of the key hole.");
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
    if(str == "cracks") {
        if(present("brown key",TP) || key_avai == 0) {
            say(TPQCN+" found nothing in the cracks.");
            write("You found nothing in the cracks.");
            return 1;
        }
    new(OBJ+"argbkey.c")->move(TP);
    write("You found a strange key.");
    say(TPQCN+" found a strange key.");
    key_avai = 0;
    return 1;
    }
}

void reset() {
    ::reset();
    if(key_avai == 0)
    key_avai++;
    set_locked("door",1);
    set_open("door",0);
}
