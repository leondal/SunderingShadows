//      This file was initially created  using the _build command line
//      room maker. Coded by Melnmarn@ShadowGate. Please leave this
//      header intact.



#include <std.h>
#define NEWBIE_MONSTERS ({"rat","bat","kobold","drunk"})
inherit ROOM;

void create(){
    ::create();
        set_property("indoors",0);
        set_property("light",2);
     set_short("This is the begining of a long hall.");
        set_long(
@BUILD
%^BOLD%^ You are now in the fighting room for newbies%^RESET%^
There is a large glass arena that you could fight things in
, if you would like to fight a monster type <fight monster_name>.
You also see many fireballs falling from the dark sky.
BUILD
);

        set_exits(([



       "north":"/d/shadow/room/tour/hall4.c",
        ]));
        set_items(([
               "road":"A small trail leads out of this section of forest.",
               "trees":"The trees are pine trees, standing high and proud.",
        ]));
        set_smell("default","You can smell the pine trees.");
     set_listen("default","You can hear the birds and forest animals moving about.");

}

void init(){
::init();
add_action("fight","fight");
}

int fight(string str){
if(!str) {
notify_fail("Pick what?\n");
return 0;
}
if(member_array(str,NEWBIE_MONSTERS) != -1)
new("/d/shadow/mon/"+str)->move(TO);
else {
write("That thing would grab your head, eat it, and then throw it onto");
notify_fail("the other side of the mud.\n");
return 0;
}
write("A bolt of fire crashes to the ground, You have summoned a "+str);
tell_room(TO,TPQCN+" summons a "+str,TP);
return 1;
}



















