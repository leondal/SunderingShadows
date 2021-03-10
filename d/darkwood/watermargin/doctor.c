//	Doctor's Office
//	Thorn@Shadowgate
//	11/15/94
//	Darkwood Forest Area
//	doctor.c

#include <std.h>
#include <rooms.h>

inherit ROOM;

void create() {
    ::create();
    set_light(1);
    set_indoors(1);
    set_short("Doctor's Office");
	set_long(
@THORN

	You enter the Doctor's small home and are asked to sit down
by his assistant.  This is a small, but well kept little office
where you see medical books and astrological tables scattered
around.  The Doctor is over by his desk, looking over a 
manuscript of some ancient scientist or of a new dissection
performed in one of the great universities.	 There is a list
on the wall that details some of the services of the doctor
which he will provide for cash.

THORN
);
    set_exits(
              (["south" : "/d/darkwood/watermargin/street1"]) );

}

void reset() {
	::reset();
	if(!present("doctor")) {
		new("/d/darkwood/mon/doctor")->move(this_object());
	}
}

void init() {
	::init();
	add_action("read", "read");
}

int read(string str) {
	if(!str) return 0;
	write(
@LIST

	The Doctor will provide the following services:
	
	First aid		5 silver
	Minor Healing	1 gold, 1 silver
	Major Healing	2 gold, 3 silver
	Surgery			5 gold
	Fortunes		3 copper
	
LIST
	);
}
