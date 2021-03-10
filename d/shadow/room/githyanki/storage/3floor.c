//Third Floor Template - Githyanki Fortress - LoKi - 12-02-2008


#include <std.h>
#include "../githyanki.h"

inherit CVAULT;

object ob;

void init() {
    ::init();
    add_action("whisper_func","listen");
    add_action("pray_func","pray");
    add_action("memorize_func","memorize");
    add_action("focus_func","focus");
}


void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_property("light",2);
    set_name("Depths of the Fortress");
    set_short("%^RESET%^%^BOLD%^%^BLACK%^De%^RESET%^%^WHITE%^p%^RESET%^%^BOLD%^%^BLACK%^ths of the For%^RESET%^%^WHITE%^t%^RESET%^%^BOLD%^%^BLACK%^ress%^RESET%^");
    set_long("%^RESET%^%^BOLD%^%^BLACK%^The walls here are roughly hewn from the depths of the god-isle. There is no real seperation between walls and floor, and you have to step carefully to avoid random outcroppings of rock. You are unsure where the light is coming from in these hallways as there are no lanterns and the dark rock doesn't produce any light. The whispers here are louder, begging you to listen\n\n%^RESET%^");
    set_smell("default","%^RESET%^%^ORANGE%^You smell nothing.%^RESET%^");
    set_listen("default","%^BLACK%^%^BOLD%^You hear loud whispers...%^RESET%^");

    set_items
    (([
        ({"floor", "walls", "wall", "ground"}) : "%^RESET%^%^BOLD%^%^BLACK%^The ground and walls here are roughly carved from the stone%^RESET%^",
    ]));
}

int whisper_func(string str) {

    switch(random(10)) {
        case 1:
           tell_object(TP,"%^RESET%^%^BOLD%^I am Menagra, Lord of the banished... Praise me!!!\n\n%^RESET%^");
           tell_room(ETP,"%^RESET%^%^CYAN%^"+TP->QCN+"%^RESET%^%^CYAN%^ stops to listen...%^RESET%^.",TP);
           return 1;
        break;

        case 2:
           tell_object(TP,"%^RESET%^%^BOLD%^I will never die! I will take on the whole of creation!\n\n%^RESET%^");
           tell_room(ETP,"%^RESET%^%^CYAN%^"+TP->QCN+"%^RESET%^%^CYAN%^ stops to listen...%^RESET%^.",TP);
           return 1;
        break;

        case 3:
           tell_object(TP,"%^RESET%^%^BOLD%^My promises to the lords of Belkar... Mean nothing!\n\n%^RESET%^");
           tell_room(ETP,"%^RESET%^%^CYAN%^"+TP->QCN+"%^RESET%^%^CYAN%^ stops to listen...%^RESET%^.",TP);
           return 1;
        break;

        case 4:
           tell_object(TP,"%^RESET%^%^BOLD%^My forces are countless, my power is unstoppable\n\n%^RESET%^");
           tell_room(ETP,"%^RESET%^%^CYAN%^"+TP->QCN+"%^RESET%^%^CYAN%^ stops to listen...%^RESET%^.",TP);
           return 1;
        break;

        case 5:
           tell_object(TP,"%^RESET%^%^BOLD%^You send a thousand Inevitables.. I will send back each piece one by one\n\n%^RESET%^");
           tell_room(ETP,"%^RESET%^%^CYAN%^"+TP->QCN+"%^RESET%^%^CYAN%^ stops to listen...%^RESET%^.",TP);
           return 1;
        break;

        case 6:
           tell_object(TP,"%^RESET%^%^BOLD%^How could they have defeated the horde? I will destroy them!\n\n%^RESET%^");
           tell_room(ETP,"%^RESET%^%^CYAN%^"+TP->QCN+"%^RESET%^%^CYAN%^ stops to listen...%^RESET%^",TP);
           return 1;
        break;

        case 7:
           tell_object(TP,"%^RESET%^%^BOLD%^I was Menagra\n\n%^RESET%^.");
           tell_room(ETP,"%^RESET%^%^CYAN%^"+TP->QCN+"%^RESET%^%^CYAN%^ stops to listen...%^RESET%^",TP);
           return 1;
        break;

        default:
           tell_object(TP,"%^BLACK%^%^BOLD%^You hear can't make out the voices...%^RESET%^");
           tell_room(ETP,"%^RESET%^%^CYAN%^"+TP->QCN+"%^RESET%^%^CYAN%^ stops to listen...%^RESET%^",TP);
           return 1;
        break;

    }
}

int memorize_func(string str){
    tell_object(TP,"%^RED%^%^BOLD%^You can't focus on your reading with all the whispers..%^RESET%^");
    tell_room(ETP,"%^RESET%^%^RED%^"+TP->QCN+"%^RESET%^%^RED%^ opens "+TP->QP+" book, then closes it in anger%^RESET%^",TP);
    return 1;
}

int pray_func(string str){
    tell_object(TP,"%^RED%^%^BOLD%^You can't focus on your symbol with all the whispers..%^RESET%^");
    tell_room(ETP,"%^RESET%^%^RED%^"+TP->QCN+"%^RESET%^%^RED%^ focuses on "+TP->QP+" symbol, then drops it in anger%^RESET%^",TP);
    return 1;
}

int focus_func(string str){
    tell_object(TP,"%^RED%^%^BOLD%^You can't focus on your thoughts with all the whispers..%^RESET%^");
    tell_room(ETP,"%^RESET%^%^RED%^"+TP->QCN+"%^RESET%^%^RED%^ holds "+TP->QP+" crystal, then drops it in anger%^RESET%^",TP);
    return 1;
}
