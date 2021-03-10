#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit OBJECT;

void create(){
    ::create();
    set_name("statue");
    set_id(({"statue","Statue","bronze statue"}));
    set_short("A large statue");
    set_long("This is a big bronze statue of a large muscular man holding a crystal. He looks like he is awaiting a challenge.");
    set_weight(10000);
    set_value(0);
}

void init(){
    ::init();
    add_action("challenge_me","challenge");
}

int challenge_me(string str){
    if(!str || str != "statue") 
        return notify_fail("Challenge what?");
    tell_room(ETO,"%^BOLD%^A challenge has been issued! The statue comes to life!");
    new(MON+"strength")->move(ETO);
    call_out("remove",1);
    return 1;   
}
