#include <std.h>
#include "/d/dagger/marsh/tower/short.h"

inherit "/d/dagger/marsh/tower/mon/reaverB.c";

void create(){
    ::create();
    set_gender("male");
    new( OPATH "gem5.c" )->move(TO);
}
