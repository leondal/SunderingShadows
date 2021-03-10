

#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_name("portals room");
    set_property("indoors",1);
    set_property("light",3);
    set_property("no teleport",1);
    set_short("Portals to the realm");
    set_long(
@OLI
    This room is bright with the dancing light of the portals. Every open space 
within the room is dancing with portals to transport you to the realms. The blueish
dancing light is both bright and beautiful. Where do you wish to go?
OLI
    );
    
    set_exits(([
        "fighters":"/d/shadow/room/city/cguild/fighter/fighter",
      "churches" : "/d/shadowgate/death/death_exit.c",
        "paladins":"/d/shadow/room/city/cguild/paladin/main",
        "bards":"/d/dagger/tonovi/town/cguilds/bard1",
        "cavaliers":"/d/shadow/room/city/cguild/cavalier/guild2",
        "antipaladins":"/d/shadow/room/city/cguild/antipaladin/anti3",
        "assassins":"/d/laerad/parnelli/cguild/assassin/aguild1",
       "thief":"/d/shadow/room/city/cguild/thief/tguild",
        "mages":"/d/shadow/room/city/cguild/mage/conf",
        "clerics":"/d/shadow/room/city/cguild/cleric/cleric1",
        "rangers":"/d/shadow/room/city/cguild/ranger/rooms/hall1",
        
    ]));
    
}

/*

void reset() {
  object ob;
  ::reset();
  if (!objectp(present("reality board"))) {
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "bulletin board", "reality board" }) );
    ob->set_board_id("avatar_board");
    ob->set("short", "The (old) Avatar's event board");
    ob->set("long", "A large board where the avatars of the realm may post.");
    ob->set_max_posts(100);
    //ob->set_location("/d/dagger/portals");
  }
}
*/
