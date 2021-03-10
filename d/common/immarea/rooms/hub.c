#include <std.h>

inherit ROOM;

int is_interactive(object ob) {
  if (interactive(TP)) return 1;
  else return 0;
}

void place_board()
{
    object ob;
    if (present("new avatar board", TO)) 
    {
        return;
    }
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "bulletin board", "new avatar board" }) );
    ob->set_board_id("new_avatar_board");
    ob->set("short", "Avatar board");
    ob->set("long", "A large board where the avatars of the realm may post.");
    ob->set_max_posts(300);
    ob->set_location("/d/common/immarea/rooms/core");
    ob->set_restricted_read();
    ob->set_ooc_board(1);    
}

void create()
{
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
   set_property("no scry",1); // added by Lujke 12 November 2007
    set_property("no teleport",1);
    set_short("Avatar's Lounge");
    set_long(
"%^BOLD%^%^RED%^Transportation hub%^RESET%^
Remember that you can use <goto LOCATION> and remember many spots.
"
    );
    set_exits( ([
      "down" : "/d/shadowgate/adv_main",
      "offestry" :"/d/newbie/rooms/town/square",
      "tabor" : "/d/darkwood/tabor/room/cnchall",
      "juran" :"/d/shadow/juran/city/quest_room", //Added by saide
      "antioch" : "/d/antioch/antioch2/rooms/street2", //Added by saide
      "seneca" : "/d/attaya/newseneca/rooms/inn_entrance", //fixed by ~Circe~ to go to the board
      "torm" : "/d/dagger/Torm/city/c45", //added by saide
      "VOID": "/d/shadowgate/void.c",
      "FREEZER": "/d/shadowgate/freezer.c",
    ]) );
}

