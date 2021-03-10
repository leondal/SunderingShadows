//      /bin/ambassador/_goto.c
//      from the Nightmare Mudlib
//      teleports a person to another location
//      created by Descartes of Borg 930906

#include <std.h>

inherit DAEMON;

int cmd_goto(string str)
{
    object ob;
    mixed location;
    string room, *rooms;

    if(!str)
    {
        location = (string)this_player()->getenv("marked");
	    if(!location) location = (string)this_player()->getenv("start");
	    this_player()->move_player(location);
	    return 1;
    }

    if(str == "home")
    {
        if(wizardp(TP) || TP->query_position() == "dm") location = "/realms/"+TP->query_true_name()+"/workroom";
        else if(avatarp(TP)) location = "/d/avrooms/"+TPQN+".c";
        if(!objectp(room = find_object_or_load(location)))
        {
            tell_object(TP,"You don't seem to have a home.");
            return 1;
        }
        else
        {
            TP->move_player(room);
            return 1;
        }
    }

    if(str == "arena")
    {
        TP->move_player("/realms/obsidian/rooms/arena1");
        return 1;
    }

    if(TP->query_rem_rooms())
    {
        if(member_array(str,keys(TP->query_rem_rooms())) != -1)
        {
            tell_object(TP,"You go to the location remembered as "+str+"!\n");
            rooms = TP->query_rem_rooms();
            TP->move_player(rooms[str]);
            return 1;
        }
    }

    if((ob = find_living(lower_case(str))) && (!ob->query_invis() || !archp(ob)) && ob=environment(ob))
    {
        if(ob == environment(this_player()))
        {
            tell_object(TP, "You are already in that location.");
            return 1;
        }
    }

    if(ob && ob->query_invis() && wizardp(ob) && !archp(this_player()))
    {
        tell_object(TP, "You can find no such user.");
        return 1;
    }

    if(!ob) str = resolv_path((string)this_player()->get_path(), str);
    this_player()->move_player((ob ? ob : str), "");
    return 1;
}


void help()
{
    message("help",
      "Syntax: <goto [living thing|file]>\n"
      "        <goto remembered location>\n"
      "        <goto home>\n"
      "        <goto arena>\n\n"
      "This command will move you to where the living thing is if it can "
      "be found, otherwise it will search for the file named and try to "
      "move you into that file.\n\nSee also: home, move, trans.",
      this_player()
    );
    return 1;
}
