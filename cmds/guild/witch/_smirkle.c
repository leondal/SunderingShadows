#include <std.h>

inherit DAEMON;

int cmd_smirkle(string str) {
    string whom;
    object ob;

    if(str && sscanf(str, "at %s", whom) == 1) {
       if(!ob=present(lower_case(whom), environment(this_player()))) {
            notify_fail("No one here called "+capitalize(whom)+".\n");
            return 0;
        }
        if(!living(ob)) {
            notify_fail("You look confused.\n");
            return 0;
        }
    }
    if(!ob) message("emote", "You smirkle like only a witch can.",this_player());
    else message("emote", "You smirkle at "+(string)ob->query_cap_name()+".",
      this_player());
    if(!ob)
      message("emote", (string)this_player()->query_cap_name()+
        " smirkles like only a witch can.", environment(this_player()),
        ({ this_player() }));
    else {
        message("emote", (string)this_player()->query_cap_name()+
          " smirkles at you in the way of the witches!", ob);
        message("emote", (string)this_player()->query_cap_name()+
          " smirkles at "+(string)ob->query_cap_name()+" in the way of the witches!",
          environment(this_player()), ({ob, this_player()}));
    }
    return 1;
}
