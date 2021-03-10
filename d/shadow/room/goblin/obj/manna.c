#include <std.h>
inherit OBJECT;
void init() {
    ::init();
    add_action("eat_func","eat");
}
void create() {
    ::create();
    set_id(({"manna"}));
    set_short("a piece of manna");
    set_long("This is the small piece of manna which must have fallen from the sky.");
    set_weight(1);
    set_value(1);
    if(clonep(TO)) call_out("remove",20);
}
int eat_func(string str) {
    if(!str) {
	notify_fail("Eat what?\n");
	return 0;
    }
    if(str != "manna") {
	notify_fail("Eat what?\n");
	return 0;
    }
    write("%^CYAN%^A crunchy, yet yummy, snack!%^RESET%^");
    say(
	"%^CYAN%^"+TPQCN+" gulps down a piece of manna!%^RESET%^"
    ,TP);
    TP->add_hp(random(1)+1);
    destruct(TO);
    return 1;
}
int remove() {
    if(!objectp(TO) || !objectp(ETO)) return ::remove();
    tell_room(ETO,"The manna has rotted.");
    return ::remove();
}
