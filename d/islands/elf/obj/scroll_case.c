#include <std.h>
inherit "/d/common/obj/misc/scroll_case";

void create(){
    ::create();
    fill();
}
void fill(){
    int x;
        for(int i = 0; i < 10; i++)
    {
        new("/d/common/obj/misc/parchment")->move(TO);
    }
}
