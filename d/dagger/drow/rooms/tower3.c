#include <std.h>
inherit ROOM;

int found;
void create() {
    ::create();
   set_terrain(STONE_BUILDING);
   set_travel(STAIRWAY);
    set_property("light",1);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_short("Conference room");
    set_long(
      	"%^BLACK%^%^BLUE%^Somehow you climb the shadows themselves and "
	"emerge into a cold bare stone room. A large "
	"%^GREEN%^wooden%^BLUE%^ desk made of old oak stands in the center "
	"of the room. A chair is located behind the desk. "
      	"Standing next to the desk is a %^WHITE%^statue%^BLUE%^ carved "
	"from black obsidian.%^RESET%^"
    );
    set_listen("default",
	"Occasionally, off in the distance, you hear laughter and loud "
	"booming sounds."
    );
    set_smell("default",
     	"It smells of burning oil here."
    );
    set_items(([
    	"desk":"%^BOLD%^%^GREEN%^The desk is made of old oaken wood "
	"and is covered in papers.%^RESET%^",    
	"papers":"The papers have complex formulas on some, others have lists "
	"of drowish names. A last scrap buried under the rest of the papers "
	"is titled `mortal appointments'.",
	"chair":"The chair is made of old oaken wood. The armrests end in "
	"large skulls.",
	"skulls":"The eyes of the skull grin at you.",
        "eyes":"%^BOLD%^%^BLACK%^As you gain upon the eyes you hear a shout "
	"ring out, `syve'%^RESET%^",
	"statue":"%^BLUE%^The statue is made in the likeness of "
	"%^RED%^Grazzt%^BLUE%^.%^RESET%^"
    ]));
    set_exits(([
	"up":"/d/dagger/drow/rooms/fakeroom",
	"down":"/d/dagger/drow/rooms/tower2"
    ]));
    set_search("desk", (: "block_func" :) );
}

int wizonly() {
    if (!TP || TP->query_npc()) return 0;
    if(!wizardp(TP)) {
	notify_fail(
	"%^BOLD%^%^RED%^Grazzt tells you: %^RESET%^I would rather "
	"you keep out of my workroom. ;)"
    );
    return 0;
    }
    return 1;
}

void reset() {
    ::reset();
    if(!present("chest")) {
	new("/d/dagger/drow/obj/chest")->move(TO);    
    }
    if(!present("emisary")) {
	new("/d/dagger/drow/mon/emisary")->move(TO);
/* was bugging with bad argument to env. (TP wouldn't be valid)  *Styx* 11/16/03
	message("environment",
	  "%^RED%^%^BOLD%^You hear a loud angry shout and The drow emisary is "
	  "suddenly thrown down into the room!%^RESET%^"
	,environment(TP));
*/
    tell_room(TO, "%^RED%^%^BOLD%^You hear a loud angry shout and The drow emisary is "
	  "suddenly thrown down into the room!%^RESET%^");
    }
  found = 0;
}

void init() {
    ::init();
// changing to use set_search.. *Styx*  11/16/03
//    add_action("block_func","search");
}

int block_func(string str) {
//    if(!TP) return 0;
    if(str != "desk") {
	write("You don't find anything in the "+str+".");
	return 1;
    }
    if(present("drow emisary")){
	write("%^RED%^The drow emisary will not let you search the desk!%^RESET%^");
	return 1;
    }
    if(found) {
	write("The desk appears to have been cleaned out already.");
        return 1;
    }
    write("%^RED%^After searching the desk you find a wand!%^RESET%^" );
    new("/d/dagger/drow/obj/wowand")->move(TP);
    found = 1;
    return 1;
}
