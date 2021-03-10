#include <std.h>
#include "/realms/grazzt/paladin/short1.h"
inherit ROOM;
void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
//    set_property("no teleport", 1);
    set_short("%^CYAN%^Paladin Guild Armor Shop%^RESET%^");
    set_long("%^CYAN%^"
	"%^CYAN%^This is the Paladin Guild Armor Shop. "
	"You're standing in a small room with a %^MAGENTA%^"
	"counter%^CYAN%^ on the "
	"north side. The room is very tidy and is used to "
	"distribute armours of holy quality to the Paladins of "
	"the Order. There is a knight standing behind the "
	"counter ready to serve you.%^RESET%^"
    );
    set_exits( ([
    "southeast" : RPATH "sanctum"
        ]) );
    set_items( ([
        "counter" : "A stone counter used by the knight to "
	"display his wares."
    ]));
}
void init(){
    ::init();
    if(!present("knight"))
	find_object_or_load("/d/shadow/room/city/cguild/mons/pal_clerk")->move(TO);
}
