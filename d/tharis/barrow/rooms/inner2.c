#include <std.h>
#include "/d/tharis/barrow/short1.h"
inherit ROOM;

int portal;

void init() {
    ::init();
    add_action("tell_func","tell");
}
void create() {
    ::create();
   set_terrain(BUILT_CAVE);
   set_travel(FOOT_PATH);
    set_property("light",1);
    set_property("indoors",1);
    set_short( (:TO,"shrt_fun" :) );
    set_long( (:TO,"lng_fun" :) );
    set_smell("default",
        "The smell of the old musty earth lingers in the stale air."
    );

    set_items(([
        "dirt":"The whole chamber is made from dirt.",
        "torches":"The torches flicker and provide little light.",
        "walls":"The walls are made of dirt and have a few flickering "
        "torches in them.",
        "ceiling":"The ceiling is made of dirt.",
        "floor":"The floor is made of dirt."
    ]));
    set_exits(([
        "up": RPATH "inner1"
    ]));
    set_pre_exit_functions(({"up"}),({"exit_fun"}));
    portal = 0;
}
string lng_fun(string str) {
    if(random(2) < 1) {
        str = 
            "The chamber is a small and cramped hole within "
            "the mound. The dirt floor and walls are bare. There appears "
            "to be no place to go from this small chamber but up through "
            "ceiling. The ceiling has an opening that is filled with a "
            "strange wispy fog substance. There are "
            "a few flickering torches "
            "on the walls. ";
    } else {
        str =
            "The chamber is merely a "
            "dirt room. Several "
            "flickering torches hang from the walls. "
            "The dirt floor and walls are bare. There appears "
            "to be no place to go from this small chamber but up through "
            "ceiling. The ceiling has an opening that is filled with a "
            "strange wispy fog substance.";
    }
    return str;
}
string shrt_fun(string str) {
    if(random(2) < 1) {
        str = 
            "A Small Dirt Chamber";
    } else {
        str =
            "A Cramped Dirt Chamber";
    }
    return str;
}

int exit_fun() {
    if(TP->query_true_invis()) return 1;
    write("You suddenly feel the need to leave "
          "the cramped dirt chamber and climb up through the "
          "ceiling."
    );
    tell_room(TO,""+TPQCN+" suddenly disappears through the fog!"
    ,TP);
    return 1;
}       
int tell_func(string str) {
    if(!str) {
        notify_fail("Tell what?\n");
        return 0;
    }
    write(
        "A Voice replies: "
        "You will not be talking to your "
        "friends ever again if you stay in here! Muahhaha!!!"
    ); 
    tell_room(TO,
        ""+TPQCN+" gets a concerned and twisted look on his "
        "face."
    );
    return 1;
}    
void reset() {
    ::reset();
    if (portal ==1){
        tell_room(TO,
        "%^BOLD%^%^RED%^Suddenly, for no apparent reason, you feel "
        "dizzy and ill!"
        );
        set_exits(([
            "up": RPATH "inner1"
        ]));
    }
    if (sizeof(query_exits())>1 && portal ==0){
        portal = 1;
    }
}
