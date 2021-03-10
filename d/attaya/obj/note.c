#include <std.h>
#include <daemons.h>

inherit OBJECT;

void init(){
    ::init();
    add_action("read","read");
}

void create(){
    ::create();

    set_name("note");
    set_id(({"note","paper"}));
    set_short("A note");
    set_long(
      "It is a note written on a piece of parchment."
    );
    set_weight(2);
    set_value(5);
}

int read(string str){
    if(!str || str != "note") return  0;

    tell_room(environment(TO),TPQCN+" reads the note.",TP);
    write("\n\n\%^RED%^Those chandeliers in the library are close enough to jump to from the highest level.  \n");
    return 1;
}

