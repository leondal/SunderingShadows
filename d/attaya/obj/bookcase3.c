#include <std.h>
#include <daemons.h>

inherit OBJECT;

void init(){
    ::init();
    add_action("read","read");
}

void create(){
    ::create();

    set_name("bookcase");
    set_id(({"bookcase","case"}));
    set_short("Bookcase loaded with books");
    set_long(
      "A tall oak bookcase holds a variety of books.  You can 'read titles'"
    );
    set_weight(500);
    set_value(100);
}

int read(string str){
    if(!str || str != "titles") return  0;

    tell_room(environment(TO),TPQCN+" reads the book titles!",TP);
    write("\n\%^RED%^Kinnesaruda Journal %^BOLD%^I.");
    write("\n\%^RED%^Kinnesaruda Journal %^BOLD%^II.");
    write("\n\%^RED%^Kinnesaruda Journal %^BOLD%^III.");
    write("\n\%^RED%^Kinnesaruda Journal %^BOLD%^IV.");
    write("\n\%^RED%^Kinnesaruda Journal %^BOLD%^V.");
    write("\n\%^RED%^Kinnesaruda Journal %^BOLD%^VI.");
    write("\n\%^RED%^Kinnesaruda Journal %^BOLD%^VII.");
    write("\n\%^RED%^Kinnesaruda Journal %^BOLD%^VIII.");
    write("\n\%^RED%^Kinnesaruda Journal %^BOLD%^IX.");
    write("\n\%^RED%^Kinnesaruda Journal %^BOLD%^X.");
    write("\n\%^RED%^Kinnesaruda Journal %^BOLD%^XI.");
    write("\n\%^RED%^Kinnesaruda Journal %^BOLD%^XII.");
    write("\n\%^BOLD%^%^BLACK%^Shadowy Implementation %^BOLD%^I.");
    write("\n\%^BOLD%^%^BLACK%^Shadowy Implementation %^BOLD%^II.");
    write("\n\%^BOLD%^%^BLACK%^Shadowy Implementation %^BOLD%^III.");
    write("\n\%^BLUE%^Intruder's Personal Agenda.");
    return 1;
}

