#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_events(string str) {
    mapping mp;
    string *obs;
    int i;

    if(!archp(previous_object())) return 0;
    if(!mp = (mapping)EVENTS_D->query_events()){
	write("There are no events pending!");
	return 1;
    }
    i = sizeof(obs = keys(mp));
    message("info", "The following events are pending:", this_player());
    while(i--) {
        message("info", arrange_string(obs[i], 30) +
        arrange_string(mp[obs[i]]["function"], 15)+
          ctime(mp[obs[i]]["time"])+" Mud Time", this_player());
    }
    return 1;
}

void help() {
    message("help", "Syntax: <events>\n\n"
      "Gives a list of all pending mud events.",
      this_player()
    );
}
