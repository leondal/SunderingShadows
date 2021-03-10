#include <std.h>
inherit ROOM;
void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("%^BLUE%^City street%^RESET%^");
    set_long(
	"%^BLUE%^The city street is made of cobblestones winding through "
	"the existing structures around you. The "
	"%^CYAN%^wind%^BLUE%^ blows back your "
	"hair as you wander through the city pathways."
	" Before you to the north lies the gateway through the temple "
	"walls. The gates are open but "
	"a %^RED%^%^BOLD%^shimmering energy field%^RESET%^%^BLUE%^ "
	"hangs across the gates open surface in the air. "
	"This %^RED%^%^BOLD%^field%^RESET%^%^BLUE%^ seems to be humming."
	" The %^RED%^temple%^BLUE%^ is hard to make out visually "
	"through the gate but it appears to be constructed entirely of "
	"black obsidian stone. An opening into the temple can be seen "
	"from here, and a large %^RED%^red banner%^BLUE%^ hangs above the "
	"opening.%^RESET%^"
        "%^BLUE%^%^BOLD%^\nA large statue of the demonqueen spider known "
	"as %^BLACK%^Lloth%^BLUE%^ sits atop of the temple.%^RESET%^"
    );
    set_listen("default",
	"The energy field before you hums loudly."
    );
    set_smell("default",
	"The smell of blood hangs thick in the air."
    );
    set_items(([
	"cobblestone":"There are numerous cobblestones lining the city "
	"pathways.",
	"banner":"The banner bears the symbol of Lloth upon it.",
	"cobblestones":"The city pathway is made up of various colored "
	"cobblestones which must have been mined in the caverns near here.",
	"temple":"The temple cannot be seen very clearly from here because "
	"of the field. You get the feeling that something inside it is "
   "aware of your presence here.",
	"statue":"The statue of Lloth appears to be watching you carefully.",
	"field":"The field would have to be passed through to go north "
	"and most likely would inflict tremendous damage to you.",
	"gate":"The gates stand open, but a field of energy is laying "
	"cross them.",
	"street":"The street is made up of cobblestones and winds through "
	"the buildings.",
	"pathway":"The pathway winds through the city and is made up of "
	"cobblestones.",
	"buildings":"There are buildings lining the city streets."
    ]));
    set_exits(([
	"west":"/d/dagger/drow/rooms/city17",
"north" : "/d/dagger/drow/rooms/court8",
	"east":"/d/dagger/drow/rooms/city19"
    ]));
    set_pre_exit_functions(({"north"}),({"field"}));
}
int field() {
    message("my_action",
	"%^RED%^%^BOLD%^As you pass through the energy field, you scream "
	"out in pain as the field burns with a searing heat into your "
	"very soul!%^RESET%^"
    ,TP);
    message("other_action",
	"%^RED%^%^BOLD%^As "+TPQCN+" passes through the enrgy field, they "
	"scream in agony and appear to be burned by the field."
	"%^RESET%^"
    ,environment(TP),TP);
    TP->do_damage("torso",roll_dice(10,10));
    return 1;
}
void reset() {
    ::reset();
    if(!present("drow")) {
        new("/d/dagger/drow/mon/drows")->move(TO);
	new("/d/dagger/drow/mon/drows")->move(TO);
	new("/d/dagger/drow/mon/drows")->move(TO);
	new("/d/dagger/drow/mon/drowcap")->move(TO);
	message("environment",
            "%^BLUE%^A troop of drow enter to guard the temple "
	    "gate.%^RESET%^"        ,TO);
    }
}
