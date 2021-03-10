#include <std.h>
#include <daemons.h>

inherit OBJECT;

void init(){
    ::init();
    add_action("read","read");
}

void create(){
    ::create();

    set_name("sign");
    set_id(({"warning sign","sign"}));
    set_short("%^BOLD%^%^RED%^A wooden sign written in blood%^RESET%^");
    set_long(
      "%^RED%^It is a wooden sign.  Somebody has left you a message in some other poor soul's blood."
    );
    set_weight(100000);
    set_value(10000);
}

int read(string str){
    if(!str || str != "sign") return  0;

    tell_room(environment(TO),TPQCN+" reads the warning sign!",TP);
    write("%^BOLD%^%^RED%^Your treasure lies to the north. Enter there, and you will be given safe passage to the healer on the island.  If you would rather die, than I AM WAITING FOR YOU!");
    write("\n\n\%^BOLD%^%^RED%^I have grown tired of you..\n");
    return 1;
}

