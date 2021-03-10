#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_id( ({"sign","wooden sign"}) );
    set_name("wooden sign");
    set_short("A large wooden sign");
    set_weight(1000000);
    set_property("no animate", 1);
    set_long("This is a large wooden sign with directions on it.  You could probably read it.");
    set_read(
@STYX
%^RESET%^An arrow pointing west is marked %^BOLD%^%^CYAN%^Shadow-Tabor Ferry%^RESET%^.

Generally westward are the %^BOLD%^%^GREEN%^Meadowlands%^RESET%^.  A path can be found through there, leading southward to the city of Tabor.

%^BOLD%^%^BLUE%^To the north are the Echoes Mountains, where young adventurers might 
wish to seek to further their pursuit of fame and fortune.

%^YELLOW%^The city of Shadow, the nearest major civilization, is to the east.%^RESET%^
   NOTICE!!!  Evil and lesser races are no longer welcomed there and in fact may be attacked and killed on sight.

%^RESET%^Scrawled crudely below, apparently in blood, is another note:  %^RED%^Juran welcomes most of you that those tyrants consider outcasts.  %^RESET%^Another message is added just below in a flowing, elven script.  %^CYAN%^Do not journey there, unless you are prepared for the foul beasts that call that city home!%^RESET%^
STYX
    );
    set_value(0);
}

void init(){
   ::init();
}

