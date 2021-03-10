#include <std.h>
inherit OBJECT;
void init() {
    ::init();
    add_action("bury_func","bury");
}
void create() {
    ::create();
    set_id(({"rites","funeral rites"}));
    set_short("Funeral rites");
    set_long("This is the funeral rites of the gods which will allow a "
	"player to bury <target> in the event of lost heartbeats. It "
	"will simply inform the creature it is dead and remove it. You "
	"will not recieve xp for creatures this is used upon but atleast "
	"it remedies the problem. Please remember to inform your local "
	"wizards still of creatures who lose heartbeats.");
    set_weight(1);
    set_value(0);
}
int bury_func(string str) {
object tp;
    object ob;
tp = this_player();
    if(!str) {
	notify_fail("Bury what?\n");
	return 0;
    }
    ob = present(str, environment(tp));
    if(!ob) {
        notify_fail("No "+str+" here!\n");
        return 0;
    }
    if(!living(ob)) {
        notify_fail(ob->query_cap_name()+" is not a living thing!\n");
        return 0;
    }
    if(interactive(ob)) {
	notify_fail("This is not a valid target for burial you idiot!\n");
	return 0;
    }
    if((int)ob->query_hp() < -1) {
        write(
	    "%^RED%^You inform "+ob->query_cap_name()+
	    " that "
	    +ob->query_subjective()+" should be dead!\n"
	    "%^BLUE%^"+ob->query_cap_name()+" agrees and vanishes!%^RESET%^"
	);
	say(
	    "%^RED%^"+TPQCN+" delivers the last rites to "
	    +ob->query_cap_name()+"!\n%^BLUE%^"
	    +ob->query_cap_name()+" vanishes!%^RESET%^"
	,TP);
	ob->remove();
        return 1;
    } else {
	notify_fail("This creature is fine!\n");
	return 0;
    }
}
