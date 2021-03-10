#include <std.h>

inherit DAEMON;

int cmd_coven(string str) {
    if(this_player()->query_mp() < 50) {
	notify_fail("Too low on magic power.\n");
	return 0;
    }
    if(environment(this_player())->query_property("no teleport")) {
        notify_fail("A magic force prevents your teleportation.\n");
        return 0;
    }
    this_player()->move_player("/realms/descartes/witch/room/lounge");
    this_player()->add_mp(-150);
/* Yes, this code intentionally allows negative exp on a player */
    return 1;
}

void help() {
    message("help", "Syntax: <coven>\n\n"
      "An emergency power to bring you home to the coven.",
      this_player()
    );
}
