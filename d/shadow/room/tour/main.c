//      This file was initially created  using the _build command line
//      room maker. Coded by Melnmarn@ShadowGate. Please leave this
//      header intact.



#include <std.h>

inherit ROOM;

void create(){
    ::create();
        set_property("indoors",0);
        set_property("light",2);
        set_short("This is a small hill in Shadow.");
        set_long(
@BUILD
%^BOLD%^You Are now on a small Hill in Shadow%^RESET%^
 You stand on a small hill, you see a grand battle taking place above
and around you.  It seems a Grand Paladin is facing down Death in a
monumental struggle to save the souls of the damned.
There are others around you preparing themselves to join
the battle, on whose side you can not tell.
 The time for choices is now, you may join with the Grand Paladin
and help save the poor souls or join with Death and destroy them.
 Be forewarned once the choice is made there will be no turning back.
 Go toward the north into the open plains to find and help the
Grand Paladin.
 Go toward the south into the dark forest to find and help Death.
BUILD
);
        set_exits(([
       "north":"/d/shadow/room/tour/grnd_paladin/hall1.c",
       "south":"/d/shadow/room/tour/death/hall1.c",

        ]));
        set_items(([
               "road":"A small trail leads out of this section of forest.",
               "trees":"The trees are pine trees, standing high and proud.",
        ]));
        set_smell("default","The air smells of ash and battle.");
     set_listen("default","You can hear the sounds of battle all around you.");

}

void init() {
     ::init();
 add_action("leave","leave");

}

int leave(string str)
{
write("You leave for the main square.\n");
say( (string)this_player()->query_cap_name()+"leaves.\n");
TP->move_player("/d/shadowgate/adv_main.c");
return 1;
}



