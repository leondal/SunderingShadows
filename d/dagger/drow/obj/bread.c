#include <std.h>
inherit OBJECT;
void init() {
    ::init();
    add_action("eat_func","eat");
}
void create() {
    ::create();
    set_id(({"bread","crumb"}));
    set_short("bread crumb");
   set_name("bread crumb");
    set_long("This is the small piece of Elven Waybread.");
    set_weight(2);
    set_value(1);
}
int eat_func(string str) {
    if(!str) {
	notify_fail("Eat what?\n");
	return 0;
    }
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }

    if(str != "bread" && str != "crumb") {
	notify_fail("Eat what?\n");
	return 0;
    }
    write("%^CYAN%^A tasty, yet mystical, snack!%^RESET%^");
    say(
	"%^CYAN%^"+TPQCN+" wolfs down a piece of bread!%^RESET%^"
    ,TP);
    TP->add_hp(random(2)+1);
    TO->remove();
    return 1;
}
