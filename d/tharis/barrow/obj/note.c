#include <std.h>
#include "/d/tharis/barrow/short1.h"
inherit OBJECT;
void create() {
    ::create();
    set_name("scroll");
    set_id(({"scroll"}));
    set_short("%^RESET%^%^RED%^plain scroll%^RESET%^");
    set_long("%^RED%^This is nothing more than a plain scroll. "
	"Perhaps you should read it.%^RESET%^");
    set_weight(1);
}
void init() {
    ::init();
    add_action("read_func","read");
}
int read_func(string str) {
    if(!str) {
	notify_fail("Read what?/n");
	return 0;
    }
    if(str != "scroll") {
	notify_fail("Read what?/n");
	return 0;
    }
    write(
	"%^RED%^The scroll reads:\n"
	"%^BLUE%^"
	"	In soctum blaxom veritanu.\n"
	"%^GREEN%^"
	"	Krykothian, I have since found the Drow to be such a\n"
	"	evil and powerful creature to allow devotion and worship\n"
	"	by their race upon myself. Through these vile beings I have\n"
	"	been able to restore the ancient craft which we have practised\n"
	"	within the Abyss for so long. Now I have guided their minds\n"
	"	to construct a Nodeus. Through this they believe I shall\n"
	"	be able to enter to the mortal realm and bring about the\n"
	"	enslavement of all races. The crystal which I granted you\n"
	"	is needed by them to complete the process. You must be quick\n"
	"	to master it's secret to provide freedom from that which\n"
	"	imprisons you. Then be careful as you deliver it to them\n"
	"	as it can also be used in destruction of the Nodeus.\n"
	"%^BOLD%^%^BLACK%^"
	"						Lloth.%^RESET%^"
        "\nThe scroll then crumbles to dust in your hands."
    );
    say(
	"%^RED%^As "+TPQCN+" reads the scroll it crumbles to dust.%^RESET%^"
    ,TP);
    TO->remove();
    return 1;
}		
