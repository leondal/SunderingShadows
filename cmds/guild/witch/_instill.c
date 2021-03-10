#include <std.h>

inherit DAEMON;

int cmd_instill(string str) {
    object *inv;
    int i, tmp;

    if(str != "fear") return 0;
    inv = all_inventory(environment(this_player()));
    for(i=0, tmp = sizeof(inv); i<tmp; i++) {
        if((string)inv[i]->query_gender() != "male") continue;
       if(wizardp(inv[i])) continue;
        message("my_action", "You bow to the power of witches!", inv[i]);
        message("other_action",
          inv[i]->query_cap_name()+" bows to the power of witches!",
          environment(this_player()), ({ inv[i] }));
    }
    return 1;
}

void help() {
    message("help", "Syntax: <instill fear>\n\n"
      "Installs a fear of witches into the hearts of all males.",
      this_player()
    );
}
