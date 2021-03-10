#include <std.h>
#include <daemons.h>

inherit OBJECT;


void create(){
    ::create();

    set_name("table");
    set_id(({"table","glass table"}));
    set_short("A glass table");
    set_long(
      "A thick glass tabletop rests upon a wrought iron base.  The base is exquisite and is quite ornate.  The table is about 8 feet in length and 3 feet in width with incredible weight in it's 1 inch thick glass surface."
    );
    set_weight(1000);
    set_value(10000);
}
