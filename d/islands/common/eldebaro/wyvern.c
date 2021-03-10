#include <std.h>
#include <daemons.h>
#include "area_stuff.h"
inherit CROOM;

void create()
{
    ::create();
	set_property("light",2);
	set_property("indoors",0);
    set_property("no teleport", 1);
    set_property("scry proof", 1);
    set_climate("arctic");
    set_name("Inside an ebon chamber");
    set_short("%^BOLD%^%^BLACK%^Inside a %^BOLD%^%^CYAN%^fr%^BOLD%^%^WHITE%^i%^BOLD%^%^CYAN%^g"+
    "%^BOLD%^%^WHITE%^i%^BOLD%^%^CYAN%^d%^BOLD%^%^BLACK%^ ebon chamber%^RESET%^");
    set_had_players(1);
    
    set_long("A wyvern perch... players shouldn't be here..");
    
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);

    return;
}
