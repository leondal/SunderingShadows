// Chernobog (3/6/21)
// Shadow Coliseum

#include <std.h>
#include "../defs.h"
inherit INH+"training";

int searched;

void create(){
    ::create();
    set_long(::query_long()+"\n%^RESET%^");
    set_exits(([
        "south" : ROOMS"training2",
        ]));
    set_search("dummies",(:TO,"search_pile":));
}

void search_pile(){
    if(searched){
        tell_object(TP,"%^BOLD%^%^BLACK%^Some of these dummies are a little damp.%^RESET%^");
        tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+" %^BOLD%^%^BLACK%^slides a few of the dummies aside.%^RESET%^",TP);
        return;
    }
    else{
        tell_object(TP,"%^BOLD%^%^BLACK%^You find a small leather case tucked under one of the dummies.%^RESET%^");
        tell_room(ETP,"%^BOLD%^%^BLACK%^"+TP->QCN+" %^BOLD%^%^BLACK%^pokes around under one of the dummies.%^RESET%^",TP);
        new(OBJ"thief_tools.c")->move(TO);
        searched=1;
        return;
    }
}

void init(){
    ::init();
    add_action("retrieve_fun", "retrieve");
    add_action("return_fun", "return");
}

int retrieve_fun(string str){
    if (!str){
        return 0;
    }
    if (str == "dummy" || str == "testdummy" || str == "test dummy" || str == "practice dummy" || str == "rune"){
        if (present("testdummy")){
            tell_object(TP, "%^BOLD%^%^BLACK%^There is already a training dummy set up in place.%^RESET%^\n");
            return 1;
        }
        tell_object(TP, "%^BOLD%^%^BLACK%^You grab a training dummy and slot it into place.%^RESET%^\n");
        tell_room(TO, "" + TPQCN + " %^BOLD%^%^BLACK%^grabs a training dummy and slots it into place.%^RESET%^\n", TP);
        new(MON"dummy_strong")->move(TO);
        return 1;
    }
    return 0;
}

int return_fun(string str){
    if (!str){
        return 0;
    }
    if (str == "dummy" || str == "testdummy" || str == "test dummy" || str == "practice dummy"){
        object dummyobj;
        if (!present("test dummy")) {
            tell_object(TP, "There is no practice dummy to return!\n");
            return 1;
        }
        tell_object(TP, "%^BOLD%^%^BLACK%^You pick up the training dummy and return it to the pile.%^RESET%^\n");
        tell_room(TO, "" + TPQCN + " %^BOLD%^%^BLACK%^picks up the training dummy and returns it to the pile.%^RESET%^\n", TP);
        dummyobj = present("test dummy");
        if (objectp(dummyobj)){
            dummyobj->move("/d/shadowgate/void");
            dummyobj->remove();
        }
        return 1;
    }
    return 0;
}

