#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_id(({"note","crumpled note"}));
    set_name("note");
    set_short("A crumpled note");
    set_long("This is a piece of paper, lined with creases.  A few lines of text are "+
        "scrawled across it.");
    set_weight(0);
    set_value(0);
}

void init() {
    ::init();
    add_action("read_fun","read");
}

int read_fun(string str){
    if(! str) return notify_fail("Read what?");
    if(str != "note") return notify_fail("You can't read that!");
    if (TP->query_stats("intelligence")<10) return notify_fail("You can't make sense of the scrawled writing.\n");
    tell_object(TP,"\n%^RED%^Birds of the feather flock together\nTaking a bite out"+
        " of the beef\nThe cackle for the canters has some flash ken\nSticky"+
        " the jam will be\nBest wash it away\n\n");

    if (TP->is_class("thief") || TP->is_class("assassin") || TP->is_class("bard")){
        tell_object(TP,"%^RED%^Roughly translated from thieves' cant, it means:\n\nIn Shadow"+
            " there is fence behind the Bestiary.  Flash the sign of a thief to "+
            "gain entrance.  Be careful in Shadow, for thieves get the gallows there.");
    }
    else {
        tell_object(TP,"Whatever the hell that means.");
    }
    return 1;
}

