#include <std.h>
#define FULLNOTE "/d/dagger/marsh/tower/obj/fullnote.c"

inherit OBJECT;

void create(){
    ::create();
    set_name("scrap of paper");
    set_short("scrap of paper 2");
    set_id( ({"scrap", "scrap of paper", "DGpaperscrap2"}) );
    set_long(
       "This scrap of paper has some strange writing that you can't make out.  It looks like it is the corner of a sheet of parchment that was ripped into at least 4 pieces.  Maybe if you can <connect> all 4 pieces, you can figure out what's written on them."
    );
    set_weight(1);
    set("value", 1);
}

void init(){
    ::init();
    add_action("connect", "connect");
}

int connect(string str){
    object ob1,ob2,ob3,ob4;
    if(!str) return notify_fail("Connect what?\n");
    if(str != "scraps") return notify_fail("Connect what?\n");

    if(!ob1 = present("DGpaperscrap1", TP)) {
      tell_object(TP, "You need all 4 scraps.");
      return 1;
    }
    if(!ob2 = present("DGpaperscrap2", TP)) {
      tell_object(TP, "You need all 4 scraps.");
      return 1;
    }
    if(!ob3 = present("DGpaperscrap3", TP)) {
      tell_object(TP, "You need all 4 scraps.");
      return 1;
    }
    if(!ob4 = present("DGpaperscrap4", TP)) {
      tell_object(TP, "You need all 4 scraps.");
      return 1;
    }

    new(FULLNOTE)->move(TP);
    tell_object(TP, "As you puzzle the scraps together, they suddenly connect magically, leaving you with one piece of paper!");
    ob1->remove();
    ob2->remove();
    ob3->remove();
    ob4->remove();
    return 1;
}
