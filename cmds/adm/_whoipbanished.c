#include <std.h>
#include <security.h>
#include <daemons.h>

inherit DAEMON;

int cmd_whoipbanished(string str) {
    string res;
    string *sites;

    if(!archp(previous_object())) return 0;
    seteuid(UID_BANISH);
    if(res=catch(sites = (string *)call_other(BANISH_D, "query_blocked"))) {
        write("Error in checking sites: "+res+"\n");
        seteuid(getuid());
        return 1;
    }
    seteuid(getuid());
    sites = sort_array(sites, "order_sites", this_object());
    if(str) {
        if(member_array(str, sites) == -1)
          write("Site \""+str+"\" is not currently being restricted by ip address..\n");
        else write("Site \""+str+"\" is currently not allowed to connect (at all!).\n");
    }
    else {
        write("These sites are not allowed to even enter a character name.:\n");
        this_player()->more(explode(format_page(sites, 4), "\n"));
    }
    return 1;
}

int order_sites(string alpha, string beta) {
    string *a, *b;
    int i, x, y;

    a = explode(alpha, ".");
    b = explode(beta, ".");
    for(i=0; i<sizeof(a) && i<sizeof(b); i++) {
      if(!(x = atoi(a[i]))) return -1;
      if(!(y = atoi(b[i]))) return 1;
      if(x > y) return 1;
      if(y > x) return -1;
    }
    if(sizeof(a) < sizeof(b)) return -1;
    else return (sizeof(a) > sizeof(b));
}

void help() {
    write("Syntax: <whoipbanished ([site])>\n\n"
      "Without an argument, it lists all sites which are banished from completing the login.\n"
      "Given an argument, it will confirm if that site can connect and login.\n"
      "Sites must be in ip numeric format.\n\nSee also:\n"
      "register, unregister, banish, unbanish, whobanished, letin, unletin\n"
      "wholetin, watch, unwatch, whowatched, ipbanish, unipbanish.\n"
    );
}
