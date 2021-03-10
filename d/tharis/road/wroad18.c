//wroad stuff

#include <std.h>

inherit "/d/tharis/road/wroad2";

void create(){
        ::create();
        set_exits(([
                "north":"/d/darkwood/yntala/rooms/forest31",
                "southeast":"/d/tharis/road/wroad17",
                "west":"/d/tharis/road/wroad19"
                ]));
        set_items(([]));
}
