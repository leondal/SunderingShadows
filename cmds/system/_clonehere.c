//      /bin/system/_clone.c
//      from the Nightmare Mudlib
//      clones objects into the game
//      created by Sulam 911219
//      largely rewritten for Nightmare by Descartes of Borg 930809

#include <std.h>

inherit DAEMON;

int cmd_clonehere(string str) {
    object ob;
    mixed res;
    string msg, tmp;

    if(member_group(geteuid(previous_object()), "ambassador")) return 0;
    if(!str) {
        notify_fail("Clone what file?\n");
        return 0;
    }
    seteuid(getuid(previous_object()));
    if(res = catch(ob = new(str = resolv_path((string)this_player()->get_path(),
      str))))
        write(str+": "+res);
    if(!ob) return 1;
    if(ob->move(ETP) || !ob->get())
      ob->move(environment(this_player()));
    write(file_name(ob)+": cloned.");
    if(hiddenp(this_player()) || this_player()->query_invis())
      return 1;
    msg = (string)this_player()->query_mclone();
    if(tmp = (string)ob->query_short())
      msg = replace_string(msg, "$O", tmp);
    else msg = replace_string(msg, "$O", (string)ob->query_name());
     msg = replace_string(msg, "$N", this_player()->query_cap_name());
    say(msg+"\n");
    return 1;
}

void help() {
   message("help", "Syntax: <clone [filename]>\n\nClones an object into your"
           " inventory if it is an object which can be gotten, otherwise it "
           "moves it into your environment.", this_player());
}
