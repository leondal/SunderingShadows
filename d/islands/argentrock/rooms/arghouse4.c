#include <std.h>
#include "/d/islands/argentrock/argabbr.h"

inherit VAULT;

int count;

void create() {
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set("short","%^RED%^The living room");
    set("long","%^RED%^The living room
%^RESET%^%^CYAN%^This room looks like a living room. A %^BOLD%^%^CYAN%^cou%^RESET%^%^WHITE%^c%^BOLD%^%^CYAN%^h%^RESET%^%^CYAN%^ is sitting against the wall. A %^BOLD%^%^CYAN%^table%^RESET%^%^CYAN%^ and a large %^ORANGE%^c%^ORANGE%^h%^ORANGE%^air%^CYAN%^ are in the middle of the room. Some %^BOLD%^%^CYAN%^vi%^RESET%^%^WHITE%^a%^BOLD%^%^CYAN%^ls%^RESET%^%^CYAN%^ and test %^WHITE%^t%^BOLD%^%^CYAN%^ubes%^RESET%^%^CYAN%^ are scattered on the table, also a burner with a blue flame and some used %^WHITE%^pape%^WHITE%^r%^WHITE%^s%^WHITE%^.%^CYAN%^ You notice some %^ORANGE%^basket%^ORANGE%^s%^CYAN%^ on the floor away from the fireplace.%^RESET%^
");
    set_property("indoors",1);
    set_property("no teleport",1);
    set_property("light",2);
    set_listen("default","You heard the cracking of burning wood in the "+
        "fireplace.");
    set_smell("default","You smell some choking smells.");
    set_items( (["couch":"After so many battles, you really want to sit "+
        "in the couch and take a good rest.",
        "table":"A table made of oak wood. Things are scattered on it.",
        ({"vials","tubes"}):"Some potions left within some of them.",
        "chair":"You are sure the master of the house must like to sit in "+
        "this chair.",
        "burner":"It must be used for some sort of experiment.",
        "papers":"Is that a note? Maybe you should retrieve it.",
         "fireplace":"Some logs are burning in it.",
        "baskets":"You see some spider webs, bloodmoss ... inside these "+
        "baskets. You are not sure what they do."]) );
    set_exits( (["north":PATH+"arghouse3",
        "southwest":PATH+"arghouse8",
        "door":PATH+"argfoyer"]) );
    set_door("door",PATH+"argfoyer", "door",0);
    set_open("door",0);
     set_string("door","open","The door opens with a loud sound.");
    set_string("door","close","Odd, the door shuts without a sound.");

    count = 3;
}

void init() {
    ::init();
    add_action("retrieve_note","retrieve");
}

int retrieve_note(string str) {
    if(!str) {
        notify_fail("Retrieve what?\n");
        return 0;
    }
    if(str == "note") {
        if(count != 0) {
            write("You managed to find a note among the papers.");
            say(TPQCN+" managed to find a note among the papers.");
            new(OBJ+"argnote")->move(TP);
            count--;
            return 1;
        }
    write("There are no more notes here.");
     say(TPQCN+" cannot seem to find a note here.");
    return 1;
    }
}

void reset() {
    ::reset();
    if(count != 3)
    count++;
}
