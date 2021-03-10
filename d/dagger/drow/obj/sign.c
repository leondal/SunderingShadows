#include <std.h>
inherit OBJECT;
void init() {
    ::init();
    add_action("read_func","read");
}
void create() {
    ::create();
    set_id(({"sign"}));
    set_short("A wooden sign");
    set_long(
	"This is a wooden sign with a message written in "
	"blood."
    );
    set_weight(100000);
    set_value(0);
}
int read_func(string str) {
    if(!str) {
	notify_fail("Read what?\n");
	return 0;
    }
    if(str != "sign") {
	notify_fail("Read what?\n");
	return 0;
    }
    write(
	"%^BOLD%^%^BLUE%^The sign reads:\n\n"
	"%^RED%^The following Adventurers have fallen to the Drow!"
	"\n\n%^YELLOW%^"
	"       HERO                     MURDERED BY\n%^RESET%^"
	"%^MAGENTA%^"
	"     ~~~~~~~~                 ~~~~~~~~~~~~~~~%^RESET%^\n"
	"     Coyotte                  Grimtooth\n"
	"     Sarge                    Drow Assassin\n"
	"     Dakkon                   Drow Assassin\n"
	"     Dakkon                   Drow Archer\n"
	"     Duncan                   Grimtooth\n"
	"     Sarge                    Grimtooth\n"
	"     Sarge                    Drow Assassin\n"
        "     Duncan                   Drider\n"
	"     Duncan                   Drider\n"
	"     Duncan                   Drow Assassin\n"
	"     Duncan                   Drow Warrior\n"
	"     Duncan                   Grimtooth\n"
    );
    say(
	"%^BLUE%^"+TPQCN+" reads over the sign."
    ,TP);
    return 1;
}
