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
    set_id(({"statue","monument"}));
    set_short("%^BOLD%^%^BLUE%^A 40 foot tall statue of Thundercracker");
    set_long(
      "This is an enormous likeness of Thundercracker self proclaimed Lord of Attaya..."
      +"It stands 40 feet tall and has been painstakingly carved in great detail from a single slab of obsidian!  The enormous warrior is wearing thick armor with enormous shoulderplates that make him look even larger, and he is clutching a set of very strange swords."
      +"A gold plaque is set in the pedistal upon which the statue stands."
    );
    set_weight(100000);
    set_value(10000);
}

int read(string str){
    if(!str || str != "plaque") return  0;

    tell_room(environment(TO),TPQCN+" reads the plaque in the pedistal!",TP);
    write("\n%^BOLD%^Thundercracker: Lord of Attaya.\n");
    write("\n%^BLUE%^That is not dead that may eternal lie...  For after a time, even death may die...\n");
    return 1;
}

