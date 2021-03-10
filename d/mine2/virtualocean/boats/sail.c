#include <std.h>
inherit MONSTER;

int count;

void create(){
        ::create();
        call_out("start_wonder",1);
        }
void start_wonder(){
        environment(TO)->init();
        }
