#include <std.h>
#include "../area_stuff.h"
inherit GUARDSMAN;

void create()
{
    ::create();
    NPCCRE->build_me(TO);
    add_id(({"oasis guard"}));
    set_nogo(({ELROOMSE+"14"}));
    set_speed(20);
}

int is_eldebaro_monster(object ob)
{
    if(!objectp(ob)) return 0;
    if(ob->id("eldebarocreature")) return 1;
    return 0;
}

void check_my_environment()
{
    object *vics;
    int x;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    vics = filter_array(all_living(ETO), "is_eldebaro_monster", TO);
    vics -= TO->query_attackers();
    if(!sizeof(vics)) return;
    for(x = 0;x < sizeof(vics);x++)
    {
        TO->force_me("kill "+vics[x]->query_name());
        continue;
    }
    return;    
}

void init()
{
    ::init();
    check_my_environment();
    return;
}

void heart_beat()
{
    ::heart_beat();
    if(!objectp(TO)) return;
    check_my_environment();
    return;
}