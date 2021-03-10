//Coded by Bane//
#include <std.h>
inherit ROOM;
// object ob;
void create(){
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(RUINS);
    set_travel(RUBBLE);
    set_name("Abandoned castle");
    set_short("An old abandoned castle hall");
    set_long(
	"You have stepped into and old castle banquet hall.  The room spans "+
        "hundreds of yards but it looks as though it hasn't been used in "+
	"centuries.  The walls are cracked and falling apart.  Pillars reach "+
	"up towards a broken glass ceiling.  A chilly wind blows in from the "+
	"shattered ceiling.  An old fountain sits in the middle of the room.  "+
	"Moss and fungus cover most of it although a tiny stream of water still "+
	"trickles from the spout."
    );
//  set_property("no teleport",1);  getting rid of the board and protection *Styx* 4/3/03
//    set_property("no attack",1);
//    set_property("no steal",1);
    set_smell("default","A fresh breeze passes through the castle.");
    set_listen("default","You can hear the water trickling into a pool at the bottom of the fountain.");
    set_exits( ([
	"south":"/d/shadow/guilds/angels/tmp/entryway",
	"north":"/d/shadow/guilds/angels/tmp/hall2",
//	"down":"/d/shadow/guilds/angels/tmp/arenaa",
	"up":"/d/shadow/guilds/angels/tmp/hall4",
	"west":"/d/shadow/guilds/angels/tmp/hall3",
    ]) );
/* getting rid of the board, this isn't a guild area any more
    ob= new(BBOARD);
   set_property("arena",1);
    set_property("deathmove","/d/shadow/guilds/angels/tmp/heal");
*/
}

/*
void init(){
    ::init();
    add_action("go_down","down");
    if((string)TP->query_guild() == "Fallen Angel"){
    set_name("Fallen Angels guild hall");
    set_short("Fallen Angels guild hall");
    set_long(
        "You stand in an open banquet hall.  The room spans hundreds "+
        "of yards in all directions.  Large stone pillars reach up "+
        "to the ceiling.  The top of the room appears to be a dome "+
        "made from glass, incredibly the dome reaches hundreds of yards "+
        "apparently held up by a magical force.  A wonderful view of "+
        "the sky can be seen through this gigantic window of a ceiling.  "+
        "A huge fountain dominates the center of the hall pouring what "+
        "seems like thousands of gallons of water from its spout.  "+
        "Beautiful plants and trees grow along the walls giving the "+
        "fortress a little life."
    );
    ob->set_name("board");
    ob->set_board_id("angel2guild");
    ob->set_location("/d/shadow/guilds/angels/tmp/hall1");
    ob->set_id(({"board","guild board"}));
    ob->set_max_posts(30);
    ob->set_short("Fallen Angels guild board");
    ob->set_long("The Fallen Angels guild board for all you warriors to brag
about your conquests, triumphs, victories, assassinations, feats, and
anything else you are proud to share with your guild.");
    } else {
    set_name("Abandoned castle");
    set_short("An old abandoned castle hall");
    set_long(
	"You have stepped into and old castle banquet hall.  The room spans "+
	"hundreds of yards but it looks as though it hasnt been used in "+
	"centuries.  The walls are cracked and falling apart.  Pillars reach "+
	"up towards a broken glass ceiling.  A chilly wind blows in from the "+
	"shattered ceiling.  An old fountain sits in the middle of the room.  "+
	"Moss and fungus cover most of it although a tiny stream of water still "+
	"trickles from the spout."
    );
    ob->set_name("board");
    ob->set_board_id("angel2guild");
    ob->set_location("/d/shadow/guilds/angels/tmp/hall1");
    ob->set_id(({"board","guild board"}));
    ob->set_max_posts(30);
    ob->set_short("An old broken board");
    ob->set_long("This is an old busted up board.  Probably used by the former tenants of this castle.");
    }
}
void go_down(string str){
    if((string)TP->query_guild() != "Fallen Angel"){
	write("It appears that the room down there is filled with sewage.");
	write("You decide not to continue down there.");
	return 1;
    }
}
*/
