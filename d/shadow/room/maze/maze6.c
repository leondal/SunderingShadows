inherit "/std/room";
object ob;
create() {
::create();
set_light(2);
set_indoors(1);
set_short("a maze");
set_long("You are in a maze, but you have no clue where you are!");
set_exits( ([ "east" : "/d/shadow/room/maze/maze8.c",
"west" : "/d/shadow/room/maze/maze11.c",
"south" : "/d/shadow/room/maze/maze4.c",
"north" : "/d/shadow/room/maze/maze3.c",
]) );
}

