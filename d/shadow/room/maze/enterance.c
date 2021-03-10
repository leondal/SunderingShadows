inherit "/std/room";
create() {
::create();
set_light(2);
set_indoors(1);
set_short("enterance to maze.");
set_long("If you agree to enter the maze, you are on your own.  Exits may change day to day, to make it more of a chalenge to get the treasure"
">  \n IMMORTALS ARE NOT RESPONSIBLE if you get lost, and can not get out, you are responsible for yourself.");
set_exits( ([ "north" : "/d/shadow/room/maze/maze1.c",
"south" : "/d/shadow/room/",
]) );
}
