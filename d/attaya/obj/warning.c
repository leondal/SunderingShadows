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
    set_short("%^BOLD%^%^RED%^A metal plate sign%^RESET%^");
    set_long(
      "It is a large metal plate that is secured to the rocks with metal chains.  There is a warning written upon it that you may want to read."
    );
    set_weight(100000);
    set_value(10000);
}

int read(string str){
    if(!str || str != "sign") return  0;

    tell_room(environment(TO),TPQCN+" reads the warning sign!",TP);
    write("%^RED%^BEWARE!!!  The jungle path and the areas that lie beyond are wrought with perils.  It is a nightmarish journey that gets more deadly, the deeper you go.  Be warned.  Enter here at your own risk.  Approx level  25+ recomended.  Parties suggested.\n");
    write("\n\n\%^BOLD%^%^BLUE%^The Kinnesaruda don't like visitors on their burial ground.\n");
    return 1;
}

