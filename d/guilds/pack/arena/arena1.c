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
%^RED%^You stand before the entrance to the Arena. You can see the whole battlefield from here. The ground is made of black granite, which conceals many blood spots. Here you can test and train your skills among your family.
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
"north" : ARENADIR "arena3.c",
    ]) );
}
