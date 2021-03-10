#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();
    set_short("%^RED%^A tower in the forest.%^RESET%^");
    set_long(TO->query_long()+"  %^BOLD%^%^BLACK%^A massive tower "+
    "rests in the forest here, its structure shooting up "+
    "far overhead.%^RESET%^");
    set_exits(([
       "enter" : "/d/deku/open/stair1",
       "west" : F_ROOMS"36-15",
       "east" : F_ROOMS"34-15",
       "south" : F_ROOMS"35-14",
       "north" : F_ROOMS"35-16",
       "northwest" : F_ROOMS"36-16",
       "southwest" : F_ROOMS"36-14",
       "southeast" : F_ROOMS"34-14",
       "northeast" : F_ROOMS"34-16"       
    ] ));
    set_pre_exit_functions(({"enter"}),({"go_enter"}));
    
}

void reset() {
    ::reset();
    if(!present("guard")) {
        new("/d/deku/monster/guard1")->move(this_object());
        return 1;
    }
}

int go_enter() {
    object ob;
    if(present("guard")) {
        write("%^MAGENTA%^Brunwick says: %^RESET%^Foolish mortal, you cannot enter.");
        write("               For your foolishness you must pay!");
        say("%^MAGENTA%^Brunwick says: %^RESET%^foolish mortal, you cannot enter.");
        say("              For "+this_player()->query_cap_name()+" foolishness, everyone must pay!");
        if(ob=present("guard",this_object()))ob->kill_ob(this_player(),1);
        return 0;
    }
    return 1;
}