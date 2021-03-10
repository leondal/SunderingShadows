//	/std/castle.c
//	from the Nightmare mudlib
//	standard castle object for high mortals' homes
//	created by Descarte of Borg 30 january 1993

#include <std.h>
#include <dirs.h>

inherit OBJECT;

void create() { seteuid(getuid()); }

void init() {
    add_action("enter", "enter");
}

void init_castle() {
    move("LOCATION");
    set_name("CASTLE_NAME");
    set_id( ({ "CASTLE_NAME" }) );
    set("short", 0);
    set("long", "LONG");
    environment(this_object())->set_no_clean(1);
}

int enter(string str) {
    if(!id(str)) {
	notify_fail("Enter what?\n");
	return 0;
    }
    this_player()->move_player( CASTLES_DIRS+"/NOBODY/homeroom",
	"into the CASTLE_NAME");
    return 1;
}

int get() { return 0; }

int drop() { return 1; }

string affect_environment() { return "SHORT"; }

void clean_up() { return; }
