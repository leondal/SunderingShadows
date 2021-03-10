#include <std.h>
#define LAWS "/d/shadow/obj/laws.txt"

inherit OBJECT;



void create(){
    ::create();
    
    set_name("A large rough hewn sign");
    set_short("A large roughly hewn wooden sign");
    set_long("This large sign is made of heavy wood.  It has a very heavy board with words etched into it.  You could perhaps read it");
    set_weight(100000);
    set_id(({"sign","law sign"}));
    set("read",(:"sign_read":));
}

int sign_read(string str){
    if(id(str)){
        TP->more(LAWS);
        return 1;
    
    }
    return 0;
}
