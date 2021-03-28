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
    ob->set("short", "The Avatar's event board");
    ob->set("long", "A large board where the avatars of the realm may post.");
    ob->set_max_posts(300);
    ob->set_location("/d/dagger/avalounge");
    //added by Styx 6/02 just in case a mortal ends up in the room
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
@OLI
    You are in a large glowing sphere.  In the middle of a sphere rests a
    large board where you can post your ideas and read the ideas of others.
    There are some %^BOLD%^buttons%^RESET%^ to push on the wall along with 
    a %^BOLD%^lever%^RESET%^ and %^BOLD%^cord%^RESET%^ to pull.
OLI
   
    );
    set_items( ([
	"buttons" : "It looks like if you <push button 1> you would "
	  "get a strange stick and if you <push button 2> you would get a "
          "brass ring. If you <push button 3> you would get a prof cleaner, "
         " if you <push button 4> you would get a cloning wand, and if you "
         "<push button 5> you will get an undercommon wand. If you "
         "<push button 6> you will get an id adder.",
 	"lever" : "It looks like you need to pull the lever to get the dark ring.",
 	"cord" : "It looks like you need to pull the cord to get an awesome universal remote.",
    ]) );
    set_smell("default", "You smell the fresh scent of summer flowers.");
    set_listen("default", "You hear a light hum in the background.");
    set_exits( ([
        "shadow" : "/d/shadow/city/room/plaza", //Updated to new Shadow by Titania
        "scourge" : "/d/dagger/tonovi/1path1.c", 
        "rhap" : "/d/darkwood/room/road7.c", 
        "tonovi" : "/d/dagger/tonovi/town/street5.c", 
        "dagger" : "/d/dagger/nurval/room/village", 
        "deku" : "/d/deku/town/road5.c", 
        "down" : "/d/shadow/city/room/plaza",
        "newbietown" :"/d/newbie/rooms/town/square",
        "Sjail":"/d/shadow/room/city/jail_main",
//      "arena" : "/realms/obsidian/rooms/arena1",
//      "fenceroom" : "/realms/garrett/fenceroom",
        "east" : "/d/dagger/avaboard2",
        "north"  :  "/d/dagger/stdsboard",
        "southwest" : "/d/dagger/spawn_room",
        "northwest" : "/d/dagger/wiz_store2",
        "tabor" : "/d/darkwood/tabor/room/cnchall",
        "south" : "/d/dagger/planroom",
        "portals" :"/d/dagger/portals",
        "lib":"/d/dagger/lib_room",
        "juran" :"/d/shadow/juran/city/quest_room", //Added by saide
        "boards":"/d/dagger/boards_portal",
        "antioch" : "/d/antioch/antioch2/rooms/street2", //Added by saide
        "seneca" : "/d/attaya/newseneca/rooms/inn_entrance", //fixed by ~Circe~ to go to the board
        "torm" : "/d/dagger/Torm/city/c45", //added by saide
        "garretthome": "/realms/garrett/workroom", // added by Garrett ot give workroom access.
        "VOID": "/d/shadowgate/void.c",
        "FREEZER": "/d/shadowgate/freezer.c",
        "dummy" : "/d/dagger/dummyroom.c", // added by Chernobog
    ]) );
}

void reset() 
{
    ::reset();
    place_board();
}

void init(){
    ::init();
    if((string)TP->query_position() == "builder") {
	    write("Sorry, but you aren't allowed in there as a builder.");
	    TP->move("/d/common/immortals/builderlounge");
	    return 1;
    }
    add_action("push","push");
    add_action("pull","pull");
}

int push(string str) {
    if(!str) {
        write("You might want to <push button #>.");
        return 1;
    }
    if(str == "button 1") { 
        new("/d/common/immortals/wand")->move(TP);
        write("You receive a strange stick.");
        return 1;
    }
    if(str == "button 2") {
        new("/d/common/obj/special/ambassador_ring")->move(TP);
        write("You receive a cool brass ring and might want to <review commands>.");
        return 1;
    }
    if(str == "button 3") { 
        new("/d/common/immortals/prof_clearer.c")->move(TP);
        write("You receive a strange device used to reset profs.");
        return 1;
    }
    if (str == "button 4"){
        new("/d/common/immortals/clone_wand")->move(TP);
        write("You receive a wand that seems a lot like a lot of other wands.");
        return 1;
    }
   if (str == "button 5"){
      new("/d/common/immortals/undercommon_wand")->move(TP);
      write("You receive a wand for granting undercommon to players.");
      return 1;
   }
    if (str =="button 6"){
        new("/d/common/immortals/id_adder")->move(TP);
        write("You receive a nifty id adder, for adding new ids to mobs. "
            +" You can <read adder> for instructions.");
        return 1;
    }
    return 0;
}

int pull(string str) {
    if(!str) {
        write("You might want to <pull lever/cord>.");
        return 1;
    }
    if(str == "lever") { 
      new("/realms/crystal/obj/cube")->move(TP);
      write("You receive a strange and magical cube.");
      return 1;
   }
   if(str == "cord") {
        new("/d/common/immortals/universalremote")->move(TP);
        write("You receive the AWESOME new universal remote!");
        return 1;
    }
    return 0;
}

