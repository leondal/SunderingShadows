#include <std.h>

inherit DAEMON;

int cmd_worship(string str) {
    if(lower_case(str) != "lasher") return 0;
    message("other_action", (string)this_player()->query_cap_name() +
      " begins to worship "+(string)this_player()->query_possessive()+
      " necklace.", this_player());
    this_player()->more("/realms/zaknaifen/witch/help");
    return 1;
}

void help() {
    message("help", "Syntax: <worship necklace>\n\n"
      "This command allows the witch to find out about her powers.",
      this_player()
    );
}
