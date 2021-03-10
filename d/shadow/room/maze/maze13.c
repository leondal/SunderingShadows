inherit "/std/room";
object ob;
create() {
::create();
set_light(2);
set_indoors(1);
set_short("a maze");
set_long("You are in a maze, but you have no clue where you are!");
set_exits( ([ "east" : "/d/shadow/room/maze/maze15.c",
"west" : "/d/shadow/room/maze/maze10.c",
"south" : "/d/shadow/room/maze/maze7.c",
"north" : "/d/shadow/room/maze/maze6.c",
"bush" : "/d/shadow/room/maze/treasure.c",
]) );
set_invis_exits( ({"bush" }));
}

