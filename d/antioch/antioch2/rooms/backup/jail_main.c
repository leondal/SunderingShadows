#include <std.h>
#define SHADOW "gates"
#define CELL "/d/antioch/antioch2/rooms/jail"

#define DESTD "/daemon/destinations_d"
#define ADEST(B,C) "/daemon/destinations_d"->add_waystation("/d/antioch/antioch2/rooms/jail_main",B,C)

inherit "/std/jail_main.c";

void create(){
    ::create();
    if(!present("jailer"))
        new("/d/antioch/antioch2/mons/jailer")->move(TO);
    if(!present("guard"))
        new("/d/antioch/antioch2/mons/patrol_guard")->move(TO);
    if(!present("guard 2"))
        new("/d/antioch/antioch2/mons/patrol_guard")->move(TO);
    set_jail_location("antioch");
    DESTD->clear_waystations("/d/antioch/antioch2/rooms/jail_main");
    DESTD->clear_waystations("/d/antioch/antioch2/rooms/jail_main");
    ADEST("/d/antioch/antioch2/rooms/jail_main",1);
    ADEST("/d/antioch/antioch2/rooms/gates",2);

    set_cell(CELL);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("Antioch jail");
    set_short("The Antioch jail office");
    set_long("The Antioch jail office
This is the jailers' room where the criminals are checked in before being put
into a cell. A cluttered desk sits in one corner and several well-worn chairs
are scattered around the room. From the boot heel prints on the desk and the
position of a couple of the chairs, it looks like the guards put their feet up
and sleep in the chairs from time to time. The cell door look sturdy enough
they probably don't need to worry about escapes though. There is a grate down
by it. A few sooty oil lamps light the room barely enough to create shadows
that just add to the oppressiveness. There is a book on the desk with a list of
names scratched in it. A doorway south leads back to the barracks.");
    set_items(([
                   "grate" : "Perhaps the guard won't mind if you peer through the "
                   "grate to see who is in the cell.",
                   ]));
    set_listen("default","You can hear the rats scurrying around.");
    set_smell("default","A nauseating smell emanates from the cells.");
    set_exits(([
                   "south" : "/d/antioch/antioch2/rooms/barracks",
                   "cell" : CELL,
                   "grate" : CELL,
                   ]));
    add_invis_exit("grate");
    add_pre_exit_function("grate", "GoThroughDoor");
    set_door("cell door",CELL,"cell","Antioch jail key","lock");
    set_open("cell door",0);
    set_locked("cell door", 1, "lock");
    lock_difficulty("cell door",-90, "lock");
    set_lock_description("cell door", "lock",
                         "This lock is sandwiched between two very heavy "
                         "metal plates to prevent tampering.  The mechanism appears to be "
                         "not only complex but require a very sturdy key to get the pieces "
                         "to even move.");
    set_door_description("cell door", "This is a door made of three inch "
                         "thick oaken boards.  It has a section cut out and replaced with a "
                         "grate of inch diameter iron bars so that some air can still get to "
                         "the prisoners.");
    set_string("cell door","open","The cell door creaks loudly as it "
               "swings open.");
    set_string("cell door","close","An ominous thud echoes off the walls "
               "as the heavy cell door slams shut solidly.");

}

void init() {
    ::init();
    add_action("peer_out", "peer");
}

void reset() {
    ::reset();

}

int GoThroughDoor() {
    if(query_verb() == "grate") {
        write("You won't fit through there silly.");
        return 0;
    }
// need this to allow normal GoThroughDoor for the regular door exits
    return ::GoThroughDoor();
}

int peer_out(string str) {
    if(!str) {
        tell_object(TP,"Peer where?");
        return 1;
    }
    if(str == "grate" || str == "through grate"){
        tell_object(TP,"You step up to the door and peer into the cell.\n");
        tell_room(ETP,TPQCN+" steps up to the cell door and peers inside.\n",TP);
        tell_room(CELL,"You hear footsteps and catch "
                  "a glimpse of movement through the grate in the door.\n",TP);
        TP->force_me("peer grate 1");
        return 1;
    }
}
