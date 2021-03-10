//      /bin/dev/_dest.c
//      from the Nightmare Mudlib
//      The immortal's destruct command
//      created by Descartes of Borg 03 july 1993

#include <std.h>
#include <daemons.h>
inherit DAEMON;

int cmd_iupdate(string str)
{
    int i;
    object *inv;
    object ob;
    string msg, tmp;

    if(!str) 
    {
        tell_object(TP, "What are you trying to add to the auto update daemon?");
        return 1;
    }
    if(!objectp(ob = present(str, TP)) && !objectp(ob = present(str, ETP)))
    {
        tell_object(TP, "There is no such "+str+" present in your inventory "+
        "or your immediate environment.");
        return 1;
    }
    if(userp(ob) || living(ob) || ob->is_room())
    {
        tell_object(TP, "The auto update daemon does not work with users, rooms, or living creatures. Try something else.");
        return 1;
    }
    UPDATED_ITEM_D->register_item_for_update(ob, TP);
    return 1;   
}

void help()
{
    message("help", "Syntax: <iupdate [object]>\n\nThis command either "+
    "add the file name of the targetted object to the auto update daemon "+
    "or adjusts the time to the current time. This command will automatically "+
    "update player items which have been significantly changed on login.",
    this_player());
}
