#include "pvillage.h"
inherit OBJECT;

int current_page;
string pages;

void create(){
    ::create();
    set_name("book");
    set_id( ({ "book" }) );
    set_short("A book");
    set_long(
	"\nYou look at the book, the title is:\n"
	"\n%^BOLD%^%^CYAN%^        Construction rules!\n\n%^RESET%^"
	"Maybe you should open it and read the pages."
    );
    set_weight(1000000);
    current_page = 0;

}

init() {
    add_action("open","open");
    add_action("close","close");
    add_action("read_book","read");
}

int open(string str) {
    if ((!str) || (str != "book"))
	return notify_fail("Open what?");
    current_page = 1;
    write("Ok.\n");
    say(call_other(this_player(), "query_name", 0) +
	" opens the book.\n");
    return 1;
}

int close(string str)
{
    if ((!str) || (str != "book"))
	return notify_fail("Close what?");
    if (current_page == 0) {
	write("It is already closed.\n");
	return 1;
    }
    current_page = 0;
    write("Ok.\n");
    say(call_other(this_player(), "query_name", 0) +
	" closed the book.\n");
    return 1;
}

void read_book(string str)
{
    string s,rest,path;
    int p;

    sscanf(str,"%s %d",s,p);
    if ((str != "page") && (s != "page"))
      {
        notify_fail("try : read page <nr>\n");
	return 0;}
    if (current_page == 0) {
	write("It is closed.\n");
	return 1;
    }
    if (!p) {
      write("Which page?\n");
      return 1;
    }
    if (p > 5) {    
      write("That page doesn't exist!\n");
      return 1;
    }
    switch (p){
	case 1:
      		TP->more(MAIN+"housebook/page1");
		break;
	case 2:
      		TP->more(MAIN+"housebook/page2");
		break;
	case 3:
      		TP->more(MAIN+"housebook/page3");
		break;
	case 4:
      		TP->more(MAIN+"housebook/page4");
		break;
	case 5:
      		TP->more(MAIN+"housebook/page5");
		break;
	default : break;
    }
    current_page = p;
    p = current_page;
      say(TPQCN+" reads page " + current_page + ".\n",TP);
	write("%^CYAN%^\n		Page " + current_page + ".\n");

    return 1;
}

