#include <std.h>
inherit OBJECT;
void init(){
        ::init();
        add_action("read_note","read");
}
void create() {
    ::create();
    set_id( ({"paper","notice"}) );
    set_name("notice");
    set("short", "A notice.");
    set_weight(0);
    set("long", "This is a notice. It needs to be read.");
    set_value(0);
}
int read_note(string str){
        if(!str) notify_fail("Read what?");
        if("notice" != str) return 0;
        this_player()->more("/d/tharis/obj/NOTICE");
        return 1;
}
