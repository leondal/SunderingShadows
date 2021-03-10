//ice dock
//16,30
#include <std.h>
inherit ROOM;

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dockentrance() { return 1; }

void create() {
    set_indoors(1);
    ::create();
    set_light(2);
    set_short("Wintery Sea");
     set_property("no teleport",1);
    set_long(
@OLI
        %^BOLD%^You are on a the Saakrune Sea.%^RESET%^
%^CYAN%^Freezing air blows off a glacial island nearby.
Various size icebergs float in the water.%^RESET%^ 

OLI
        );
        set_exits(([

                "north":"/d/shadow/virtual/15,30.sea",
                "south":"/d/shadow/virtual/17,30.sea",
                "east":"/d/shadow/virtual/16,31.sea",
                "west":"/d/shadow/virtual/16,29.sea",
                "dock":"/d/shadow/virtual/sea/ice.dock"
                ]));
        
        set_smell("default","%^CYAN%^It smells of ice and sea water.");
        set_listen("default","%^RESET%^%^GREEN%^You hear %^CYAN%^ice%^GREEN%^ bumping against the boat.");
}