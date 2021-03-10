//	New command "followers" to query who is following a player. Nienne, 09/08.
#include <std.h>
inherit DAEMON;

int cmd_followers(string str) {
    object *followers;
    int i;
    string mymsg;

    if (str) {
        notify_fail("Correct syntax: <followers>\n");
        return 0;
    }
    if (TP->query_bound()) {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    followers = TP->query_followers();
    for(i=0;i<sizeof(followers);i++) {
      if(followers[i]->query_true_invis()) {
        followers -= ({followers[i]});
        i--;
      }
    }
    if(!sizeof(followers)) {
      tell_object(TP,"%^BOLD%^%^RED%^Noone is following you right now.%^RESET%^");
      return 1;
    }
    if(sizeof(followers) == 1) {
      tell_object(TP,"%^BOLD%^%^RED%^Only %^RESET%^"+followers[0]->QCN+" %^BOLD%^%^RED%^is following you.%^RESET%^");
      return 1;
    }
    mymsg = "%^BOLD%^%^RED%^Following you are: %^RESET%^";
    for(i=0;i<sizeof(followers);i++) {
      mymsg += (string)followers[i]->QCN;
      if((i+1) < sizeof(followers)) mymsg += ", ";
    }
    mymsg += ".";
    tell_object(TP,mymsg);
    return 1;
}

void help() {
    write("
%^CYAN%^NAME%^RESET%^

followers - list who is following you

%^CYAN%^DESCRIPTION%^RESET%^

This command will list what is following you. These entities will move between rooms as you move.

%^CYAN%^SEE ALSO%^RESET%^

follower, follow, unfollow, ditch, party
");
}
