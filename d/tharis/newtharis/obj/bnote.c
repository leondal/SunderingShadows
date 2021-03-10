#include <std.h>
#include "../tharis.h"
inherit OBJECT;
void init(){
        ::init();
        add_action("read_note","read");
}
void create() {
    ::create();
    set_id( ({"paper","note"}) );
    set_name("note");
   set_short("A note");
    set_weight(0);
    set_long("This is a note. It needs to be read.");
    set_value(0);
}
int read_note(string str){
        if(!str) notify_fail("Read what?");
        if("note" != str) return 0;
        this_player()->more(OBJ"NOTE");
        return 1;
}
