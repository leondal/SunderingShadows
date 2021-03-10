#include <std.h>
#include <objects.h>



inherit DOCK;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }
void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("short.");
    set_long("
    long
");

     set_listen("default","The waves pound against the dock coating you in a fine mist of seaspray.");
     set_smell("default","The spray off the ocean burns your nose..");
 
    set_exits(([

       "east" : "/d/islands/common/dock",

    ] ));
    set_items(([
    ] ));
}
