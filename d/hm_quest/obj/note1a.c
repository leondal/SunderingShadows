// changed to direct to yntala, as shadow city was not viable for evil races. Nienne, 2/05
#include <std.h>
inherit OBJECT;
void init(){
        ::init();
}

void create() {
    ::create();
    set_id( ({"paper","note"}) );
    set_name("note");
    set("short", "a piece of paper");
    set_weight(0);
//    set("long", "The first item you seek is not far at all.\n"+
//                        "Right in this city -- look in the walls.");
    set("long", "Search in the corner of a grand, dark forest,\n"+
                   "past the wolves and yuan-ti is found the first chest.");
    set_value(0);
}
