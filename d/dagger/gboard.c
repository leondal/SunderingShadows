#include <std.h>

inherit ROOM;

void create(){
    object ob;
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no teleport",1);
    set_short("Guild Discussion Hall");
    set_long(
       "This room is meant for the discussion of the various guild ideas and directions. Before posting be familiar with the newguild rules and ideas."
    );
    set_smell("default", "You smell the fresh scent of summer flowers.");
    set_listen("default", "You hear a light hum in the background.");
    set_exits( ([
      "arena" : "/realms/obsidian/rooms/arena1",
   "lounge":"/d/dagger/avalounge",
      "alliancehall":"/d/guilds/alliance/hall/main",
      "consortiumhall":"/d/guilds/consortium/hall/main",
      "raidershall":"/d/guilds/raiders/hall/main",
      "fisthall":"/d/guilds/fist/hall/hall3",
      "kindredhall":"/d/guilds/kindred/rooms/atree",
      "regentshall":"/d/guilds/regents/rooms/hall2",
    ]) );
    set_invis_exits(({"arena"}));
   set_pre_exit_functions( ({"arena"}),({"GoThroughDoor"}) );
ob = new("std/bboard");
ob->set_name("board");
ob->set_id( ({ "board", "bulletin board", "reality board" }) );
ob->set_board_id("guild_board");
   ob->set("short","The Guild discussion board");
   ob->set("long","A large board where the guilds are to be discussed.");
ob->set_max_posts(100);
ob->set_location("/d/dagger/gboard.c");
    ob = new("/d/magic/obj/mirror");
    ob->move(TO);
}
int GoThroughDoor(){
   if(avatarp(TP)) return 1;
   write("What?");
   return 0;
}
