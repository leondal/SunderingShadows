//roadsign1.c - for south of Offestry.  Updated 9/15/03 by Circe
#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_id(({"sign","wooden sign"}));
    set_name("wooden sign");
    set_short("A large wooden sign");
    set_weight(1000000);
    set_property("no animate", 1);
    set_long("This wooden sign bears writing in many different hands.  You could probably read it.");
    set_read(
@STYX
%^BOLD%^%^BLUE%^********************************************************************

An arrow pointing eastward is marked %^BOLD%^%^CYAN%^Shadow-Tabor Ferry%^RESET%^.

A short message is painted in elegant script below the arrow:
         %^BOLD%^%^CYAN%^~%^WHITE%^The city of Tabor welcomes young adventurers!%^CYAN%^~
%^BOLD%^%^CYAN%^~%^WHITE%^You may reach our fair city using the ferry just east of here.%^CYAN%^~
                %^BOLD%^%^CYAN%^~%^WHITE%^We look forward to seeing you!%^CYAN%^~

%^RESET%^A large arrow pointing both northeast and southeast is marked %^BOLD%^%^BLUE%^Shadow%^RESET%^.

Another arrow points north and is marked %^YELLOW%^Offestry%^RESET%^.

The arrow pointing to the west is marked %^BOLD%^%^GREEN%^Meadow Lands%^RESET%^ and there is a
%^BOLD%^%^RED%^mark of warning%^RESET%^ next to it.

%^BOLD%^%^BLUE%^********************************************************************
STYX
    );
    set_value(0);
}

void init(){
	::init();
}

