#include <std.h>
inherit OBJECT;
void init() {
    ::init();
    add_action("readpage_fun","read");
}
void create() {
    ::create();
    set_name("tablet");
    set_id(({"tablet"}));
    set_short("%^RESET%^%^MAGENTA%^Tablet of the Magius%^RESET%^");
    set_long(
	"%^MAGENTA%^This is stone tablet covered with writing across it."
	"%^RESET%^"
    );
    set_weight(5);
    set_value(250);
}
int readpage_fun(string str) {
    if(!str) {
	notify_fail("Read what?\n");
	return 0;
    }
    if(str != "tablet" && str != "note") {
	notify_fail("Read what?\n");
	return 0;
    }
if(!TP->is_class("mage") && !TP->is_class("sorcerer")) {
	write("You cannot understand what is written on the tablet.\n");
	return 1;
    }
    if((int)TP->query_level() < 25) {
	write("You lack the knowledge to read the tablet.\n");
	return 1;
    }
    write("%^RED%^The note scratched into the tablet reads:\n"
	"\n%^BOLD%^%^BLUE%^"
	"To Nicodemus, my most trusted friend...\n"
	"     As this curse I have foolishly created upon myself\n"
	"slowly sets in, I am doing everything within my power\n"
	"to insure I will be as weak as possible once the final\n"
	"transformation occurs. To this end I leave my Rod of the "
	"Magius to you to safeguard from me. Your knowledge of the\n"
	"planar shift will allow you to escape my grasp for an\n"
	"eternity. It, as you know, is a weapon of such terrific\n"
	"power that you must not only guard it from my Arch-Lich\n"
	"form but from any who would use it wrongly or not be able\n"
	"to keep it from me should I escape the crypt I shall lock\n"
	"myself into. To fully enable you to deal with guarding it\n"
	"I now will detail the knowledge of the working of the Rod.\n"
	"Once you have studied these words and committed them to\n"
	"memory, then hide this tablet with my Dragon who will\n"
	"guard it well. Then even in the event of your death\n"
	"atleast the instructions will be separate from the Rod.\n"
	"                                  Yours within undeath,\n"
	"                                  Vecna Crowley.\n"
	"\n"
	"Thy workings of thus Rod of the Magius...\n"
	"     To enable thus rod to release the fiery energy\n"
	"upon contact within thy fighting, command it to 'blast'.\n"
	"     To enable thus rod to gain energy for itself within\n"
	"thy fighting, command it to 'charge'.\n"
	"     If thou art within immense danger while combating thy\n"
	"foe, then command it to 'escape'.\n"
	"     If thou art wish to immobilize thy foe with the power\n"
	"of thus snaketh, command it to 'entangle'.\n"
	"     If thou art wish to heal thyself with the power that\n"
	"lies stored within thus rod, command it to 'absorb'.\n"
	"     If thou art wish to transfer the death energy of\n"
	"any being's dead remains before you to thy body, command\n"
	"it to 'consume'.\n"
	"     If thou art wish to expel the energy within thus rod\n"
	"at thy foe, command it to 'expend'.\n%^RESET%^"
    );
    say("%^RED%^"+TPQCN+" looks over a tablet of writing for a "+
       "few minutes.%^RESET%^",TP);
    return 1;
}

	
