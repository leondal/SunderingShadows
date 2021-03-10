#include <std.h>

inherit OBJECT;

void create(){
    ::create();
    set_name("silver key");
    set_id( ({"silver key", "key", "little silver key", "little key", "cwarmorkey"}) );
    set_short("%^RESET%^%^BOLD%^Little silver key%^RESET%^");
    set_long(
      "This is a small key made of the purest silver.  As you look at it you can almost see a strange sparkle in it.  You have heard that this key opens a door to a great treasure.  You have also heard that it's just a little silver key. There is an inscription on the key."
    );
    set("value", 50000);
    set_weight(1);
}

void init(){
    ::init();
    add_action("read", "read");
}

int read(string str){
    if(!str) return notify_fail("read what?\n");
    if(str != "key") return notify_fail("read what?\n");

    tell_object(TP, "The inscription reads...\n   This key opens a great treasure, known once to the Kinnesaruda and locked away for fear of its power.");
    tell_room(ETP, TPQCN+" reads the inscription on the tiny key.\n", TP);
    return 1;
}
