#include "/d/dagger/drow/short.h"
#include <std.h>
inherit ROOM;
int npc_drow_present();
void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("Elite warrior's training hall");
    set_long(
    	"%^BLACK%^%^BLUE%^You clamber up the ladder to the second level of the "
	"%^MAGENTA%^regal building%^BLUE%^ and come into a training "
	"hall of some kind. Weapons are strewn about the room and there is "
	"much %^RED%^dried blood%^BLUE%^ on the walls and floor. "
	"A large mural of Lloth is painted on one of the walls here.%^RESET%^"
    );
    set_listen("default",
	"The sound of slain slaves seem to echo from the dried blood."
    );
    set_smell("default",
	"A musty smell fills the room."
    );
    set_items(([
	"ladder":"%^BOLD%^%^GREEN%^The ladder leads to the first level "
	"of the building.%^RESET%^",                                                                        	
	"weapons":"%^MAGENTA%^The weapons are useless and broken and "
	"most likely are granted to slaves to use when fighting the "
	"elite drow in training sessions.",
	"blood":"The blood of slaves killed in training sessions.",
	"mural":"%^RED%^The mural depicts the demonqueen Lloth in "
	"spider form. It's numerous eyes seem to follow your every "
	"move. Perhaps you should take a closer look.%^RESET%^"
    ]));
    set_exits(([
	"down": RPATH "elite2"
    ]));
}
void reset() {
    ::reset();
    if(!present("drow")) {
	new( MPATH "elite")->move(TO);
	new( MPATH "elite")->move(TO);
	new( MPATH "elite")->move(TO);
	new( MPATH "elite")->move(TO);
    }
}
void init() {
    ::init();
    add_action("block_func","search");
}

int block_func(string str) {
    if(!TP) return 0;
    if(!str) return 0;
    if(str != "mural") return 0;
    if(npc_drow_present()){
      write("%^RED%^The drow will not let you touch the mural!%^RESET%^");
      return 1;
    }

    write("%^RED%^After searching the mural you find a glyph!%^RESET%^");
    new( OPATH "glyph")->move(TP);
    return 1;
}

int npc_drow_present(){
    object *peo;
    int i;

    peo = all_living(TO);
    if(sizeof(peo) <= 0) return 0;
    for(i = 0;i<sizeof(peo);i++){
      if(!peo[i]->id("drow"))
        continue;
      if(interactive(peo[i]))
        continue;
      return 1;
    }
    return 0;
}
