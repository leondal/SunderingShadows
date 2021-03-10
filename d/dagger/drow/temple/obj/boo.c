#include <std.h>
inherit OBJECT;
void init() {
    ::init();
     add_action("eat_func","burn");
}
void create() {
    ::create();
    set_id(({"bread","crumb"}));
    set_short("bread crumb");
    set_long("This is the small piece of Elven Waybread.");
    set_weight(1);
    set_value(1);
}
int eat_func(string str) {
object OB;
if(OB = present(str,this_player())) { 
OB->remove();
return 1;
}
    if(!str) {
	notify_fail("Burn what?\n");
	return 0;
    }
    if(str != "bread" && str != "crumb") {
	notify_fail("Eat what?\n");
	return 0;
    }
    write("%^CYAN%^A tasty, yet mystical, snack!%^RESET%^");
    say(
	"%^CYAN%^"+TPQCN+" wolfs down a piece of bread!%^RESET%^"
    ,TP);
    TP->add_hp(random(4)+1);
    TO->remove();
    return 1;
}
