//Coded by Bane//
#include <std.h>
inherit ROOM;

void create(){
    object ob;
    ::create();
    set_name("Clerics guild");
    set_short("Clerics guild");
    set_long(
	"You are in the clerics sanctum.  This hall beneath the church "+
	"serves as a guild meeting hall for all the realms healers.  "+
	"The room is rather large and bright even though it is underground.  "+
	"Many statues of godlike figures adorn the room.  Massive pillars "+
	"decorated flawlessly hold up the ceiling.  The floor tiles are "+
	"made from granite, each one looks like it took ages to finish.  "+
	"Torches line the walls bathing the room in a brilliant light."
    );
    set_property("indoors",1);
    set_property("light",2);
//    set_property("no teleport",1);  // no more safe havens
    set_listen("default","You can hear the faint prayers of other priests.");
    set_smell("default","The smell of incense is strong.");
    set_exits( ([
	"up":"/d/shadow/room/city/church",
	"east":"/d/shadow/room/city/cguild/cleric/cleric2",
    ]) );
/*  removing because now avail. remotely *Styx* 10/5/02
    ob= new(BBOARD);
    ob->set_name("board");
    ob->set_id( ({ "board","guild board" }) );
    ob->set_board_id("cguild");
    ob->set_max_posts(35);
    ob->set_location("/d/shadow/room/city/cguild/cleric/cleric1");
    ob->set_short("The Clerics board");
    ob->set_long("This is the Clerics board. Post helpful things for your fellow clerics to gain wisdom from. ");
    ob->set_ooc_board(1);
*/
}
