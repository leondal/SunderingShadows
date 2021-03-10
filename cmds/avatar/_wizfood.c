#include <std.h>

inherit DAEMON;

int cmd_wizfood(string str) {
    object ob;

    if(!str) ob = this_player();
    else ob = find_living(str);
    if(!ob) {
	notify_fail(capitalize(str) +": not found\n");
	return 0;
    }
    write("You give food and water to "+ob->query_cap_name()+".\n");
    if(ob != this_player()) tell_object(ob, "You are given food and water by "+this_player()->query_cap_name()+".\n");
    if ((int)ob->query_stuffed() < ((int)ob->query_formula()/1) )
	ob->add_stuffed(((int)ob->query_formula()/250));
    if ((int)ob->query_quenched() < ((int)ob->query_formula()/1) )
	ob->add_quenched(((int)ob->query_formula()/250));
    return 1;
}

int help() {
    write( @EndText
      Syntax: wizfood <user>
      Effect: Feeds and gives the user water.
      Warning: Do not heal players unless you are a law arch.
EndText
    );
    return 1;
}
