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
     set_short("This is a dark cleaing.");
        set_long(
@BUILD
%^BOLD%^ You are now in a dark clearing.%^RESET%^
There is a deep pit in the center of this dark clearing.  The various 
minions of Death are surrounding it, chearing and yelling for those
who are fighting within it.  This whole area is charged with energy.
There is a worn sign posted by the edge of the pit.
You also see many fireballs falling from the dark sky.
BUILD
);
        set_exits(([

       "north":"/d/shadow/room/tour/death/hall4.c",
        ]));
        set_items(([
               "road":"A small trail leads out of this section of forest.",
                "sign":"This is a worn sign, you may be able to read it.",
               "trees":"The trees are pine trees, standing high and proud.",
        ]));
        set_smell("default","The smell of Death is in the air.");
     set_listen("default","You can hear the shouts of the crowd and "+
           "the sound of battle raging.");

}

void init(){
::init();
add_action("fight","fight");
add_action("read_sign","read");
}


int read_sign(string str){

    if(str != "sign") return notify_fail("Read what?\n");

        write(
@MELNMARN

%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

%^BOLD%^%^CYAN%^Call forth your enemy from the pit, <fight 'name'>.

%^BOLD%^%^CYAN%^The enemies available are [rat, bat, kobold, drunk].

%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

MELNMARN

    );

    return 1;

}


int fight(string str){
if(!str) {
notify_fail("Pick what?\n");
return 0;
}
if(member_array(str,NEWBIE_MONSTERS) != -1)
new("/d/shadow/mon/"+str)->move(TO);
else {
notify_fail("That thing would grab your head, eat it, and then throw it onto the other side of the mud");
return 0;
}
write("A bolt of fire crashes to the ground, You have summoned a "+str);
tell_room(TO,TPQCN+" summons a "+str,TP);
return 1;
}

void reset(){


  if (!present("quag"))

  new("/d/shadow/room/tour/death/quag.c") -> move(this_object());

}








