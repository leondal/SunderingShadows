//	List iblocked parties (whoiblocked)
//	Thorn@Shadowgate
//	12/16/94
//	Admin Commands
//	_whoiblocked.c

#include <security.h>
#include <daemons.h>
#include <std.h>

string *users, *muds;

int blocked_users() {
        int x;
        users = SCREEN_D->list_bad_users();
		write("Users presently blocked over intermud");
		write("-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-\n");
        for(x = 0; x < sizeof(users);x++) {
          write(capitalize(users[x]));
        }
		write("\n-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-\n");
		write("\n");
        return 1;
}

int blocked_muds() {
        int x;

        muds = SCREEN_D->list_bad_muds();
		write("MUD's presently blocked over intermud");
		write("-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-\n");
        for(x = 0; x < sizeof(muds);x++) {
          write(capitalize(muds[x]));
        }
		write("\n-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-=*=-\n");
		write("\n");
        return 1;
}

int cmd_whoiblocked(string str) {
	seteuid(getuid());
	if(!archp(this_player())) return 0;
	if(!str) {
		blocked_muds();
		blocked_users();
		return 1;
	}
	if(str == "users") {
		blocked_users();
		return 1;
	}
	if(str == "muds") {
		blocked_muds();
		return 1;
	}
	return 0;
}
