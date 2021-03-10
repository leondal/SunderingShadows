#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_id(({"sphere","sphere of air"}));
   set_name("%^CYAN%^Sphere of Air");
    set_short("%^CYAN%^Sphere of Air%^RESET%^");
    set_long("This is a perfectly smooth glass like material sphere. It appears "
  	"to contain a wispy substance trapped within itself. Although "
	"it is made of a very strong substance, it may be possible to smash "
        "it against a hard enough surface."
    );
	    set_lore("Though it is unknown where the Sphere of Air comes from, some say shattering it will release a "
		"fierce - and angry - elemental. Others argue it has a more important purpose, and should not be squandered "
		"in such a way.");
    set_property("lore difficulty",12);
    set_weight(10);
}
void init() {
    ::init();
    add_action("break_func","shatter");
}
int break_func(string str) {
    if( !str || str != "sphere") {
	notify_fail ("Shatter what?\n");
        return 0;
    }
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }
    message ( "my_action",
	"%^BOLD%^%^CYAN%^"+TPQCN+" throws a sphere at the ground, shattering it! An "
	"angry Air Elemental suddenly appears!%^RESET%^"
    ,TP);
    message ( "other_action",
	"%^BOLD%^%^CYAN%^"+TPQCN+" throws a sphere at the ground, shattering it! An "
	"angry Air Elemental suddenly appears!%^RESET%^"
    ,environment(TP),TP);
    new("/d/dagger/drow/mon/airelem.c")->move(environment(TP));
    TO->remove();
    return 1;
}
