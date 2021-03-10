inherit "/std/room";
create() {
::create();
set_light(2);
set_indoors(1);
set_short("Zeeks closet");
set_long("This is where Zeek keeps things that he doesn't really use.");
set_exits( ([ "out" : "/d/shadow/room/beach/homes/zeek1.c",
]) );
}
