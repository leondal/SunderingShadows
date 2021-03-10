//      This file was initially created  using the _build command line
//      room maker. Coded by Melnmarn@ShadowGate. Please leave this
//      header intact.



#include <std.h>

inherit ROOM;

void create(){
object ob;
    ::create();
        set_property("indoors",0);
        set_property("light",2);
     set_short("This is the begining of a long hall.");
        set_long(
@BUILD
%^BOLD%^You continue down the long hall%^RESET%^
This is a small clearing, a small stream runs down the west side.  You
can see blast of magic and the flash of steal to the east.  To the south 
is a dense stand of trees, you feel the evil flowing from them.
There is a large sign posted here. "%^RED%^ READ %^RESET%^ %^BLUE%^THE %^RESET%^ %^YELLOW%^SIGN%^RESET%^"
Lying under the sign is a skeleton, it seems to be grasping a book.
BUILD
 
);




        set_exits(([
        "east":"/d/shadow/room/tour/death/newbie1.c",

      "south":"/d/shadow/room/tour/death/croom.c",
       "north":"/d/shadow/room/tour/death/hall3.c",
        ]));
        set_items(([
             "skeleton":"This is a dried up skeleton of a human, "+
                  "it is holding what appears to be a journal.",
             "book":"This a a dusty tome, it is being held be the skeleton.",
               "trees":"The trees are pine trees, standing high and proud.",
        ]));
     set_smell("default","You can smell the cold steam.");
     set_listen("default","You can hear the sound of swords and fighting.");


ob = new( "std/sign");
ob->set_id( ({ "sign", "Danger sign"}) );
ob->set_sign_id("DANGER");

ob->set_location("/d/shadow/room/tour/death/hall4.c");
ob->set("short", "Danger Sign");
ob->set("long", "Do not go east unless your willing to fight.\n");
}


void init() {
     ::init();
     add_action("read_sign", "read");
}
 
int read_sign(string str) {
if(str != "sign") return 0;
write("Do not go east unless you would like to fight....\n");
say((string)this_player()->query_cap_name()+" read the sign.\n");
return 1;
}

