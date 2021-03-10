#include <std.h>
#include "../tharis.h"
inherit STORAGE"sewer";

int gate;

void create(){
   ::create();
   set_long(::query_long()+" There is a large %^RESET%^%^BLUE%^gate%^BOLD%^%^BLACK%^ to the north.%^RESET%^\n");
   set_exits(([
      "north" : SEWERS"sewer14",
      "south" : SEWERS"sewer12",
   ]));

    set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
    set_items(([
        "gate":"%^BOLD%^%^BLACK%^The large iron gate is rusted beyond use but still it stands in your way."
    ]));
}

void init(){
        ::init();
        add_action("filter_say","say");
        add_action("stop_open","open");
}

int filter_say(string str){
        if(!str) return 0;
        if(gate == 1) return 0;
        if(strsrch(str,"friend") == -1) return 0;

        call_out("fix_gate",1);
        return 0;
}

void fix_gate(){
        tell_room(TO,"As the words are said the iron gate that barred your passage opens!");
        gate = 1;
}

void reset(){
        ::reset();
        gate = 0;
}

int GoThroughDoor(){
        if(!gate){
                tell_room(TO,""+TPQCN+" runs into the iron gate!",TP);
                write("You run into the iron gate!");
                return 0;
        }
        return 1;
}

int stop_open(string str){
    if(!str) return notify_fail("Open what?\n");
        if(str != "gate") return notify_fail("Open what?\n");
        write("You struggle with the magically sealed gate.");
        tell_room(TO,TPQCN+" struggles with the magically sealed gate!",TP);
        return 1;
}