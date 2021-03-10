#include <std.h>

inherit DAEMON;

int cmd_archshout(string str) {
    if(!str) return 0;
    if(!archp(previous_object())) return 0;
    message("my_action", "You shout: "+str, this_player());
    shout(this_player()->query_cap_name()+" shouts: "+str);
    return 1;
}

void help() {
    message("help",
        "Syntax: <archshout [message]>\n\n"
        "Allows an arch to shout without languages."
        "\n\nSee also: broadcast, shout", this_player()
    );
}
