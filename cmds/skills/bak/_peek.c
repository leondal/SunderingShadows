//      /bin/user/_peek.c
//      from the Nightmare mudlib
//      to sneak a peek instead of be seen looking
//      written by Descartes of Borg 27 may 1993
 
#include <std.h>

inherit DAEMON;
 
int cmd_peek(string str) {
    object ob;
 
    if(!str) {
        notify_fail("Peek at what?\n");
        return 0;
    }
    str = lower_case(str);
    if(sscanf(str, "at %s", str) != 1) {
        notify_fail("Peek at what?\n");
        return 0;
    }
    if(this_player()->query_disabled()) return 1;
    this_player()->set_disabled();
    ob = environment(this_player());
    if(effective_light(this_player()) < 0) {
        write("It is too dark.");
        return 1;
    }
    if(total_light(this_player()) < 1) write("It is dark.\n");
    if(ob->id(str)) 
        write((string)ob->query_long(str));
    else if(ob = present(str, this_player()))
        write((string)ob->query_long(str));
    else if(ob = present(str, environment(this_player()))) 
        write((string)ob->query_long(str));
    else {
        write("You do not notice that here.");
        return 1;
    }
    if(random(150) > (int)this_player()->query_skill("stealth")) {
        if(living(ob)) {
          say(this_player()->query_cap_name()+" glances at "+ob->query_cap_name()+" slyly.", ob);
          tell_object(ob, this_player()->query_cap_name()+" glances at you slyly.");
        }
        else
          say(this_player()->query_cap_name()+" looks over the "+str+".");
    }
    else this_player()->add_skill_points("stealth", 1);
    return 1;
}

void help() {
    write("Syntax: <peek at [object]>\n\n"
      "Allows you to sneak a peek at an object, perhaps without "
      "others knowing about it.\n"
    );
}
