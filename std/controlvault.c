#include <std.h>
#include <move.h>

inherit "/std/random_monsters";
inherit VAULT;

void create()
{
    vault::create();
    random_monsters::create();  
    return;
}

void reset()
{
    vault::reset();
    //random_monsters::reset();
    return;
}

void init()
{
    vault::init();
    return;
}

int clean_up()
{
    if(random_monsters::clean_up()) vault::clean_up();
}