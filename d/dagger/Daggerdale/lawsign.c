#include <std.h>
#define LAWS "/d/dagger/Daggerdale/laws.txt"

inherit OBJECT;
void create(){
    ::create();
    
    set_name("A wooden sign");
    set_short("A large oak sign");
    set_long("This sign is made of heavy and old "+
    "oak, the front of it is scrawled with phrases that "+
    "are barely legible.  You should try to read it.");
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
