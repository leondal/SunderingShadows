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
    set_short("%^BOLD%^%^MAGENTA%^The statue of a young woman");
    set_long(
      "It is a snow covered statue nearly thirty feet tall.  A beautiful young girl with delicate features peers sadly out at you from beneath layers of snow and ice.  Her hands are outstretched as if she were reaching out for help.\n A bronze plaque is set in the statues' base."
    );
    set_weight(100000);
    set_value(10000);
}

int read(string str){
    if(!str || str != "plaque") return  0;

    tell_room(environment(TO),TPQCN+" reads over the plaque!",TP);
    write("%^CYAN%^Serenity is far away.  It is but a memory now, long have I tried to remember it, then I longed to forget it as it is something I shall never again possess.  Were it only possible to live ones' life only in the yesterdays, I would lose myself in my happiness.\n");
    return 1;
}

