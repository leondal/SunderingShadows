#include <std.h>
#include <move.h>

inherit "/std/random_monsters";
inherit ROOM;

void create()
{
    room::create();
    random_monsters::create();  
}

void reset()
{
    room::reset();
    //random_monsters::reset();
}

void init()
{
    room::init();
}

int clean_up()
{
    if(random_monsters::clean_up()) room::clean_up();
}