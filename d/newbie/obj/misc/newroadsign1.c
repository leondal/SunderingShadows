//roadsign1.c - for south of Offestry.  Updated 9/15/03 by Circe - /d/newbie/obj/misc/newroadsign1.c updated with map by Titania 4/5/21 for SuS
#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_id(({"sign","wooden sign"}));
    set_name("wooden sign");
    set_short("A large wooden sign");
    set_weight(1000000);
    set_property("no animate", 1);
    set_long("This worn wooden sign displays a map of the area. You can look at it, if you wish.");
    set_value(0);
}

void init(){
  ::init();
  add_action("look","look");
}

int look(string str){
    if(!str || (str != "at map" && str != "map" && str != "sign" && str != "at sign")) return 0;
    TP->more("/d/common/text/lowbie_map");
    return 1;
}

