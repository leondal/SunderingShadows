// Channel Silence Daemon
// Thorn@ShadowGate
// 960528
// /adm/daemon/silence_d

// Removes access to speaking on channels from users
// who are silenced.  Good for breaking up those nasty
// line fights.  Interacts with the chat daemon. -- Thorn

#include <std.h>

string silence_user(string str);
string unsilence_user(string str);
string *list_all_channels();
string *query_silenced();

inherit DAEMON;
string *silenced;


string *query_silenced() { return silenced; }

string silence_user(string str) {
        int x;
        object player;

        if(!player = find_player(str)) return "Player not present";
        if(member_array(str, silenced) != -1) return "Player already"+
        " blocked";
        tell_object(player, wrap("Your access to channels has been "+
        "turned off.  If you have any questions about this, please "+
        "direct your questions to law."));
        silenced += str;
        write_file("/log/silenced", capitalize(str)+" was silenced at"+
        "+ctime(time())+");
        return capitalize(str)+" successfully silenced.";
}

string unsilence_user(string str) {
        int x;
        object player;

        if(!player = find_player(str)) return "Player not present";
        if(member_array(str, silenced) == -1) return "Player already"+
        " unblocked";
        tell_object(player, wrap("Your access to channels has been "+
        "returned."));
        silenced -= str;
        write_file("/log/silenced", capitalize(str)+" was unsilenced at"+
        "+ctime(time())+");
        return capitalize(str)+" successfully unsilenced.";
}

