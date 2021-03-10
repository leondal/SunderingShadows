#include <std.h>

inherit ROOM;

object ob;

void create() {
    ::create();
    set_property("no teleport", 1);
    set_short("%^BOLD%^Someplace you don't belong any more.  Please leave immediately.");
//    set_short("%^BOLD%^The abyss of souls.");
   set_property("indoors",1);
    set_property("light",2);
    set_long("This used to be the abyss of souls but is now retired.  Please leave now!");
/* was - removing room from use now that ooc boards are avail. remote
    set_long(
      "%^BOLD%^%^MAGENTA%^   You look behind you, and see that the door you just entered is a small portal standing free in the air, on a small circular stone formation.  You are now standing on an outcropping of those stones, and as you look around you, you see the eternal nothing.  It is said that even in space, you can see the stars.  Here there is nothing, as you tumble through the endless void."+
"\n   As you stand on the stones, suddenly small points of light appear in the distance, and start to float towards you.  As they get closer, you can see that they are vaguely human.  You then recognise them as the lost souls of those people who have had their existances here terminated.  They float around you in this dawnless hell."
    );
*/
    set_items(([
	"portal" : "The portal sits just above the stones.  Through it you can see the world that you just left",
	"stones" : "This great rock formation floats in this endless void, tumbling and rolling through the nothing.",
	({"souls", "spirits", "lights"}) : "These are the lost souls of those that have been rid, that refuse to leave the realm.  They have been banished here to this endless hell for the rest of eternity",
      ]));
    set_exits(([
	"up" : "/d/shadowgate/adv_main",
//      "portal" : "/d/shadowgate/ombud_hall",
      ]));
/*
ob = new(BBOARD);
ob->set_name("board");
ob->set_id(({"board", "rid board"}));
ob->set_board_id("Ridboard");
ob->set_max_posts(100);
     ob->set_location("/d/shadowgate/abyss");
ob->set_short("The board of riddings");
ob->set_long("This board is here for riddings to be posted, and if warranted, the reason why.  Players who wish to post here, please keep it pertinent\n");
*/
}
