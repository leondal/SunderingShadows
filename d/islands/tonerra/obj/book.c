#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit OBJECT;

void create(){
    ::create();
    set_name("book");
    set_id(({"book","Book","old tome","tome"}));
    set_short("An old tome");
    set_long("This is a very old looking book. There is dust on the cover and the book looks like it has rarely been opened. You wonder if you could learn anything by reading it.");
    set_weight(1000);     //altered by Lujke 13/11/07 to deal with a bug where the guardian didn't
                         // appear if the player had picked the book up.
    set_value(0);
}

void init(){
    ::init();
    add_action("read_me","read");
}

int read_me(string str){
    if(!str || (str != "book" && str!="tome") )
        return 0;
    tell_room(ETO,"%^BOLD%^As the book opens, a guardian appears!");
    new(MON+"wisdom")->move(ETO);
    call_out("remove",1);
    return 1;   
}
