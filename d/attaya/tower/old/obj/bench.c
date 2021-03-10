#include <std.h>
#include <daemons.h>

inherit OBJECT;

void init(){
    ::init();
    add_action("read","read");
}

void create(){
    ::create();

    set_name("Statue");
    set_id(({"statue","fountain"}));
    set_short("%^BOLD%^%^BLUE%^A statue fountain");
    set_long(
      "It is a statue of a woman drawing water.  Water pours from a bucket over her head into a well at her side.  Her face looks so very lifelike and it is hard to imagine that anyone could've carved this!"
      +"A silver plaque is set in the statues' base."
    );
    set_weight(100000);
    set_value(10000);
}

int read(string str){
    if(!str || str != "plaque") return  0;

    tell_room(environment(TO),TPQCN+" reads over the plaque!",TP);
    write("\n\n\t\%^BOLD%^Woman drawing water from a well and pouring it back in.  Work of T. Maxibar III.\n");
    return 1;
}

