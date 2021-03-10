//      /bin/dev/_dest.c
//      from the Nightmare Mudlib
//      The immortal's destruct command
//      created by Descartes of Borg 03 july 1993

#include <std.h>

inherit DAEMON;

int cmd_dest(string str) {
    int i;
    object *inv;
    object ob;
    string msg, tmp;

    if(!str) {
        notify_fail("Dest what?\n");
        return 0;
    }
    if(str == "all") {
        i = sizeof(inv = all_inventory(environment(this_player())));
        while(i--) {
            if(interactive(inv[i])) continue;
            msg = (string)this_player()->query_mdest();
            if(tmp = (string)inv[i]->query_short())
              msg = replace_string(msg, "$O", tmp);
            else msg = replace_string(msg, "$O", tmp = (string)inv[i]->query_name());
            write("Object "+tmp+" destructed.");
            if(!TP->query_invis()) tell_room(ETP,msg+"\n",TP);
            inv[i]->remove();
            if(inv[i]) destruct(inv[i]);
        }
        return 1;
    }
    if(!(ob = present(lower_case(str), this_player()))  &&
      !(ob = present(lower_case(str), environment(this_player()))) &&
      !(ob = parse_objects(this_player(), lower_case(str))) &&
      !(ob = parse_objects(environment(this_player()), lower_case(str))) &&
      !(ob = to_object(lower_case(str)))) {
        notify_fail("Cannot find: "+str+".\n");
        return 0;
    }
    if(interactive(ob) && !archp(this_player())) {
        notify_fail("You are not permitted to do that.\n");
        return 0;
    }
    write("You dest "+ob->query_short()+".");
    msg = (string)this_player()->query_mdest();
    if(tmp = (string)ob->query_short())
      msg = replace_string(msg, "$O", tmp);
    else msg = replace_string(msg, "$O", (string)ob->query_name());
     msg = replace_string(msg, "$N", this_player()->query_cap_name());
     if(!TP->query_invis()) tell_room(ETP,msg+"\n",TP);
    ob->remove();
    if(ob) destruct(ob);
    return 1;
}

void help() {
   message("help", "Syntax: <dest [object]>\n\nThis command destroys the "
           "object named.  \"dest all\" destroys all the items in your "
           "inventory.  See \"help format\" for how to denote objects.",
           this_player());
   message("help", "See also: I, format, dref, clean", this_player());
}
