//	/bin/high_mortal/_message.c
//	from the Nightmare mudlib
//	movement message changing
//	created by Descartes of Borg 09 december 1992

#include <std.h>
#include <daemons.h>

inherit DAEMON;

void profile_stuff(object tp,string profile,string type,string str);

int cmd_message(string str)
{
    string what, msg,profile;
    object desc;
    desc = new(DESC_D);

    if(!objectp(TP)) { return 0; }

    profile = TP->query("relationship_profile");

    if(!str)
    {
	    notify_fail("Which message? What is the message?\n");
	    return 0;
    }

    if(sscanf(str, "%s %s", what, msg) != 2)
    {
	    notify_fail("Correct syntax: <message in|out MESSAGE>\n");
	    return 0;
    }

    if(what != "in" && what != "out")
    {
	    notify_fail("You may only set your messages in and out.\n");
	    return 0;
    }

    if(what == "in")
    {
        this_player()->setenv("MIN", "$N "+msg);
        desc->set_profile_stuff(msg,"message in",TP);
        if(profile) { profile_stuff(TP,profile,"in",msg); }
    }
    else if(strsrch(msg,"$D") != -1)
    {
        TP->setenv("MOUT","$N "+msg+"");
        desc->set_profile_stuff(msg,"message out",TP);
        if(profile) { profile_stuff(TP,profile,"out",msg); }
        return 1;
    }
    else
    {
        TP->setenv("MOUT","$N "+msg+" $D");
        desc->set_profile_stuff(msg,"message out",TP);
        if(profile) { profile_stuff(TP,profile,"out",msg); }
    }

    return 1;
}

// used to help keep track of message in/out between profiles
// messages are hard to track otherwise, because of they way they're stored
void profile_stuff(object tp,string profile,string type,string str)
{
    mapping message_map;
    if(!objectp(tp)) { return; }
    if(!profile) { return; }
    if(!str) { return; }

    message_map = tp->query("message_map");
    if(!mapp(message_map) || !message_map || !sizeof(keys(message_map)))
    {
        message_map = ([]);
    }

    if(!mapp(message_map[profile])) { message_map[profile] = ([]); }

    message_map[profile] += ([ type : str ]);

    tp->set("message_map",message_map);
    return;
}


void help() {
    write("Syntax: <message [in | out] [msg]>\n\n"+
   "Changes your messages when you enter and exit a room.\n"+
	"The in message makes other players see :\n"+
	"    Your_name msg. when you enter a room, whereas the out:\n"+
   "    Your_name msg direction. when you leave.\n"+
   "If you wish to have the direction in a spot other than the end, you may place"+
   " a $D in the msg where you would like it to go instead, otherwise it will"+
   " default to being at the end. Example:\n"+
   "    <message out> walks $D with a swagger.\n"+
   "    Others would see: Yourname walks direction with a swagger.\n\n"+
   "See also: review\n");
}
