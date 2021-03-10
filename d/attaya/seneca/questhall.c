#include <std.h>

inherit "/std/rquestroom";

void create() {
    object ob;
    ::create();

    set_short("Questing Hall.");
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_long(
@DESC
A long corridor leads to two enormous golden gates that stand 
open, beckoning you inside. The marble floors glisten beneath 
a lush red carpet. Light pours into the room from several 
etched and beveled glass panels along the walls of the hallway.
DESC
    );
    set_exits(([
	"out" : "/d/attaya/seneca/questyard",
      ]));
    set_door("door", "/d/attaya/seneca/questyard", "out", 0);
    set_open("door", 1);
    set_locked("door", 0);
/*    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "bulletin board", "quest board", "questing board"}) );
    ob->set_short("Seneca's questing board");
    ob->set_long("Post problems complaints etc.");
    ob->set_id( ({ "board", "bulletin board", "reality board"}) );
    ob->set_board_id("seneca_quests_board");
    ob->set_max_posts(50);
    ob->set_location("/d/attaya/seneca/questhall");
    set_quest_daemon("/daemon/quests_high");
*/
    set_smell("default","A faint hint of incense mingles with the aroma of adventurers.");
    set_listen("default","The murmur of voices is accompanied by the echo of footsteps on marble.");
}

void init() {
   ::init();

}

void reset() {
   ::reset();
}
