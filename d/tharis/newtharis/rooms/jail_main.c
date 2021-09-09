#include <std.h>
#include <daemons.h>

#define SHADOW "gates"
#define CELL "/d/tharis/newtharis/rooms/jail"

#define DESTD "/daemon/destinations_d"
#define ADEST(B,C) "/daemon/destinations_d"->add_waystation("/d/tharis/newtharis/rooms/jail_main",B,C)

inherit "/std/jail_main.c"; 

void create(){
    ::create();
    
    if(!present("jailer"))
        new("/d/tharis/newtharis/mobs/jailer")->move(this_object());
    
    if(!present("golem"))
        new("/d/tharis/newtharis/mobs/bladegolem")->move(this_object());
    if(!present("golem 2"))
        new("/d/tharis/newtharis/mobs/bladegolem")->move(TO);
    
    set_jail_location("tharis");
    DESTD->clear_waystations("/d/tharis/newtharis/rooms/jail_main");
    DESTD->clear_waystations("/d/tharis/newtharis/rooms/jail_main");
    ADEST("/d/tharis/newtharis/rooms/jail_main",1);
    ADEST("/d/tharis/newtharis/rooms/ngate1",2); 

    set_cell(CELL);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
	set_property("light",2);
    set_name("Tharis jail"); 
    set_short("%^MAGENTA%^The Tharis Jail Office%^RESET%^");
    set_long("%^MAGENTA%^The Tharis Jail Office%^RESET%^.\n"+
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
        "east" : "/d/tharis/newtharis/rooms/north6",
		//"up" : "",
        "cell" : CELL,
        "grate" : CELL,
        ]));
    add_invis_exit("grate");
    add_pre_exit_function("grate", "GoThroughDoor");
    set_door("cell door",CELL,"cell","Tharis jail key","lock");
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
        tell_object(this_player(),"You step up to the door and peer into the cell.\n");
        tell_room(environment(this_player()),this_player()->QCN+" steps up to the cell door and peers inside.\n",this_player());
        tell_room(CELL,"You hear footsteps and catch "
                  "a glimpse of movement through the grate in the door.\n",this_player());
        this_player()->force_me("peer grate 1");
        return 1;
    }
}
