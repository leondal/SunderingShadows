#include "pvillage.h"
inherit OBJECT;

int nummer;
string filer;
int current_page;

void create(){
    ::create();
    set_name("note");
    set_id( ({ "note" }) );
    set_short("A note");
    set_long(
	"\nYou look at the note, the header reads:\n"
	"\n        Architect Instructions!\n"
	"Maybe you should read it."
    );
    set_weight(0);

}

init() {
    add_action("read_note","read");
}

int read_note(string str)
{
	if ((!str) || (str != "note")) return notify_fail("Read what??\n");
	write("%^BOLD%^%^GREEN%^Greetings!");
	write("%^BOLD%^%^BLUE%^----------");
	write("%^BOLD%^%^GREEN%^Since our architect is an old wizard, he only understands certain");
	write("%^BOLD%^%^GREEN%^key phrases.\n");
	write("%^BOLD%^%^CYAN%^If you are going to build a new house.");
	write("%^BOLD%^%^BLUE%^-----------------------------------------------------------------------");
	write("%^YELLOW%^house <in the direction the house should lie>  \n");
	write("%^BOLD%^%^CYAN%^If you are making or modifying one of your rooms.");
	write("%^BOLD%^%^BLUE%^-----------------------------------------------------------------------");
	write("%^RESET%^%^YELLOW%^addroom <direction>  %^CYAN%^Will add a new room in that direction, if possible.");
	write("%^YELLOW%^describe  %^CYAN%^Will enable you to change the description of the room.");
	write("%^YELLOW%^done  %^CYAN%^This is when you are finished with the Architect.");
	write("%^BOLD%^%^BLUE%^-----------------------------------------------------------------------");
	return 1;
}

get(str) {
    ::get();
	if( str == "note") return 1;
	return 0;
}

drop() {
	say("A note blows away in the wind...");
	write("A note blows away in the wind...");
	destruct(this_object()); 
	return 1;
}

