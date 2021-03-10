//Updated to improve mapping and to add Commander's Office. Kismet. 
//Ready to install. Proper path is: /d/antioch/antioch2/rooms/jail_main Kismet. 

#include <std.h> 
#define SHADOW "gates" //why does this say SHADOW? Kismet. 
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
	set_property("light",2);
    set_name("Antioch jail"); 
    set_short("%^BOLD%^%^WHITE%^The Antioch Jail Office%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^The Antioch Jail Office%^RESET%^.\n"+
"This is the jailer's room, where criminals are checked in before being put into a cell. A cluttered desk sits in one corner and several well-worn chairs are scattered around the room. There is a book on the desk with a list of names written in it, as well as a %^BOLD%^%^WHITE%^sign%^RESET%^ that you should %^BOLD%^%^WHITE%^look %^RESET%^at. A narrow stairwell leads down to a sturdy cell door with a small %^BOLD%^%^BLACK%^grate%^RESET%^ in it. During the day, the large window set above the door lets in some much needed light and during the evenings, several magical torches shed a bright light upon the otherwise drab room. The main exit leads east, out to the square, while another narrow staircase leads up onto a small balcony, which houses the commander's office. Towards the back of the room, a few relatively comfy chairs are set up in front of a modest fireplace.");
    set_items(([
        "grate" : "Perhaps the guard won't mind if you peer through the grate to see who is in the cell.",
		({"cell door","cell"}) : "The cell door looks very heavy and extremely sturdy.  There is a grate in it which you could peer through.",
		({"stairwell","stairwells","stairs"}) : "There are two narrow stairwells. One leads down into the cell and the other leads up to the balcony, which houses the office of the commander.",
		"sign" : "The signs tells you to <help jail> to see what may be done here.",
		"balcony" : "The balcony houses the commander's office.",
		"window" : "The window sits high above the doorway, letting in natural light through the oak leaves outside.",
		"fireplace" : "A modest fireplace provides some warmth to the jailers on cold days.",
        ]));
    set_listen("default","You can hear the shuffle of feet and perhaps a low sobbing from one of the cells.");
    set_smell("default","You smell sweat, tobacco and just a whiff of a nauseating stench coming from the cells.");
    set_exits(([
        "east" : "/d/antioch/antioch2/rooms/square",
		"up" : "/d/antioch/antioch2/rooms/commanders_office",
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
        write("You will not fit through there, silly.");
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
