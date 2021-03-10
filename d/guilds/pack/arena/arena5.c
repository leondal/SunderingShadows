//Mechanics by Bane, Atmosphere by Vis
#include <std.h>
#include "/d/guilds/pack/short.h"
#include <arena.h>
inherit ARENA;
void create(){
    ::create();
set_short("%^BOLD%^%^RED%^Death Chamber%^RESET%^");
    set_long(
@SEETH
%^MAGENTA%^Illuminati's %^BOLD%^%^RED%^Death Chamber%^RESET%^
%^RED%^You are within a cavern that has been sculpted. The ground is made of black granite that has been smoothed into a flat surface. The walls has many sculptures of great warriors as well as fighting strategies. Here you can test and hone your skills for battle.
SEETH
    );
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_property("arena",1);
    set_property("deathmove", ARENADIR "heal.c");


set_listen("default","%^BLUE%^You hear the sounds of battle throughout the %^BOLD%^%^RED%^Arena");
set_smell("default","%^BOLD%^%^RED%^Death and Decay fills your senses.");
    set_exits( ([
"east" : ARENADIR "arena6.c",
    ]) );
}
