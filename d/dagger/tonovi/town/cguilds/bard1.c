#include <std.h>
#include "/d/dagger/tonovi/town/short.h"

inherit ROOM;
object ob;

void create(){
    ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 1);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
    set_short("Bard's hall");
    set_long(
      "%^BOLD%^As you enter this hall you are surprised by the amount of the room that is covered with the tools of the bard's trade.  The walls are covered with many instruments, old and new, familiar and strange.  Also adorning the walls are copies of poems, from the greatest of all time to those just given passing glances."
    );
    set_smell("default", "You can smell powerful wine on the air.");
    set_listen("default", "The sounds of the greatest bards of all time practicing their art fills the air.");
    set_items( ([
	"instruments" : "You can see all kinds of instruments, from the new to the old, the familiar to the strange.",
	"poems" : "Many parchments showing the greatest poems of all time paper the walls.",
      ]) );
    set_exits( ([
	"out" : RPATH "hotelpiano",
	"east" : RPATH "cguilds/store",
      ]) );
/* removing now that ooc/guild boards are now avail. via remote command.  *Styx* 10/5/02
    ob = new(BBOARD);
    ob->set_name("board");
    ob->set_id( ({"board", "bard board"}) );
    ob->set_board_id("bardboard");
    ob->set_max_posts(30);
    ob->set_location("/d/dagger/tonovi/town/cguilds/bard1");
    ob->set_short("Bard's board");
    ob->set_long("Board for the bards.");
*/
}
