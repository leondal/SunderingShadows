// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("fissure3");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^BOLD%^%^RED%^Ancient Vault%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^You stand in an abandoned vault. The ceiling has been smashed open by a powerful %^RESET%^%^ORANGE%^earthquake%^BOLD%^%^BLACK%^. ");

    set_smell("default","
Stuff");
    set_listen("default","Stuff");

}