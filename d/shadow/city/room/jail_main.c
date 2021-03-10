#include <std.h>
#define SHADOW "westwall5"
#define CELL "/d/shadow/city/room/jail"

#define DESTD "/daemon/destinations_d"
#define ADEST(B,C) "/daemon/destinations_d"->add_waystation("/d/shadow/city/room/jail_main",B,C)

inherit "/std/jail_main.c";

void create(){
    ::create();
    set_jail_location("Shadow");
    DESTD->clear_waystations("/d/shadow/city/room/jail_main");
    DESTD->clear_waystations("/d/shadow/room/city/jail_main");
    ADEST("/d/shadow/city/room/jail_main",1);

    ADEST("/d/shadow/city/room/melisteld",2);
    ADEST("/d/shadow/city/room/westwall1",2);

    ADEST("/d/shadow/city/room/shadway1",3);
    ADEST("/d/shadow/city/room/shadwaya",3);
    ADEST("/d/shadow/city/room/melistel1",3);
    ADEST("/d/shadow/city/room/3coinspatio",3);

    ADEST("/d/shadow/city/room/northgate",4);
    ADEST("/d/shadow/city/room/eastwall1",4);
    ADEST("/d/shadow/city/room/eastwall5",4);
    ADEST("/d/shadow/city/room/eastgate",4);
    ADEST("/d/shadow/city/room/crossways4",4);

    set_cell(CELL);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("Shadow jail");
    set_short("The Shadow jail office");
    set_long("%^CYAN%^%^BOLD%^The Shadow jail office%^RESET%^
%^RESET%^%^CYAN%^This is the jailers' room where the criminals are checked in before being put into a cell. A cluttered desk sits in one corner and several well-worn chairs are scattered around the room. From the boot heel prints on the desk and the position of a couple of the chairs, it looks like the guards put their feet up and sleep in the chairs from time to time. The %^BOLD%^%^ORANGE%^cell %^ORANGE%^d%^RESET%^%^ORANGE%^o%^ORANGE%^o%^BOLD%^%^ORANGE%^r%^RESET%^%^CYAN%^ look sturdy enough they probably don't need to worry about escapes though. There is a %^BOLD%^%^ORANGE%^grate%^RESET%^%^CYAN%^ down by it. An %^BOLD%^%^ORANGE%^a%^RESET%^%^ORANGE%^r%^BOLD%^%^ORANGE%^chway%^RESET%^%^CYAN%^ to the east leads to gallows. A few sooty oil lamps light the room barely enough to create shadows that just add to the oppressiveness. There is a book on the desk with a list of names scratched in it.%^RESET%^"
        );
    set_items(([
                   "grate" : "Perhaps the guard won't mind if you peer through the "
                   "grate to see who is in the cell.",
                   ]));
    set_listen("default","You can hear the rats scurrying around.");
    set_smell("default","A nauseating smell emanates from the cells.");
    set_exits(([
                   "south" : "/d/shadow/city/room/westwall5",
                   "cell" : CELL,
                   "grate" : CELL,
                   "east" : "/d/shadow/city/room/gallows",
                   ]));
    add_invis_exit("grate");
    add_pre_exit_function("grate", "GoThroughDoor");
    set_door("cell door",CELL,"cell","Shadow jail key","lock");
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
    if(!present("Shadow jailer"))
        new("/d/shadow/mon/jailer")->move(TO);
    if(!present("shadow guard"))
        new("/d/shadow/city/mon/city_guard")->move(TO);
    if(!present("shadow guard 2"))
        new("/d/shadow/city/mon/city_guard")->move(TO);
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
      	tell_room(ETP,TPQCN+" steps up to the cell door and peers
inside.\n",TP);
      	tell_room(CELL,"You hear footsteps and catch "
                  "a glimpse of movement through the grate in the door.\n",TP);
      	TP->force_me("peer grate 1");
        return 1;
    }
}
