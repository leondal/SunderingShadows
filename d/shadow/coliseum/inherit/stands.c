// Chernobog (3/6/21)
// Shadow Coliseum

#include <std.h>
#include <move.h>
#include "../defs.h"
inherit ROOM;

#define SCRY_D "/daemon/ic_scry_locate_d"

object scry_object;
int send_living_name(object targ);
int long_look_room(object dest);

void create(){
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light", 2);
    set_property("indoors", 0);
    set_name("Shadow Coliseum");
    set_short("%^BOLD%^C%^ORANGE%^olis%^RESET%^%^ORANGE%^eum %^BOLD%^%^WHITE%^S%^ORANGE%^tan%^RESET%^%^ORANGE%^ds%^WHITE%^");
    set_long("%^RESET%^%^ORANGE%^Rows of smooth %^BOLD%^%^WHITE%^m%^RESET%^a%^BOLD%^rb%^RESET%^l%^BOLD%^e be%^RESET%^n%^BOLD%^ch%^RESET%^e%^BOLD%^s %^RESET%^%^ORANGE%^ascend and descend here, from the high backs of the coliseum down to the retaining wall surrounding the arena below. Brackets of seats are picked out by lines of stairs and pathways between. To the far northeastern corner of the stand rests the %^BOLD%^%^BLACK%^private viewing box %^RESET%^%^ORANGE%^of the magistrate, bedecked in the %^MAGENTA%^l%^YELLOW%^i%^WHITE%^v%^RESET%^e%^ORANGE%^r%^MAGENTA%^y %^ORANGE%^of %^MAGENTA%^Shadow%^ORANGE%^. Around the upper rim of the coliseum, %^BOLD%^%^GREEN%^pe%^MAGENTA%^nn%^RED%^an%^ORANGE%^ts %^RESET%^%^ORANGE%^stand out to flutter in the breeze to declare the various guilds and organizations within the city. A faint outline can be seen over the arena, an %^BOLD%^%^GREEN%^a%^CYAN%^u%^GREEN%^r%^CYAN%^a %^RESET%^%^ORANGE%^of %^BOLD%^%^CYAN%^p%^GREEN%^o%^CYAN%^w%^GREEN%^e%^CYAN%^r%^GREEN%^f%^CYAN%^u%^GREEN%^l m%^CYAN%^a%^GREEN%^g%^CYAN%^i%^GREEN%^c%^CYAN%^k%^GREEN%^s %^RESET%^%^ORANGE%^protecting those on the stands from errant dangers as well as protecting those within from the %^RED%^ire %^ORANGE%^of the crowds.%^WHITE%^");
    set_smell("default","The occasional breeze hints at large groups of people.");
    set_listen("default","The pennants flitter and snap in the breeze.");
    set_items(([
        ({"box","magistrate box"}) : "%^BOLD%^%^BLACK%^These box seats are isolated from the common seats surrounding the %^RESET%^%^ORANGE%^coliseum%^BOLD%^%^BLACK%^. It is draped in %^RESET%^%^MAGENTA%^sil%^BOLD%^%^WHITE%^k%^MAGENTA%^e%^RESET%^%^MAGENTA%^n cl%^BOLD%^%^WHITE%^o%^MAGENTA%^t%^RESET%^%^MAGENTA%^h %^BOLD%^%^BLACK%^and marked by the symbol of Shadow, three interconnected rings of %^ORANGE%^g%^WHITE%^o%^ORANGE%^ld%^BLACK%^, s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r, and %^RESET%^%^ORANGE%^copper%^BOLD%^%^BLACK%^. It is an intimate location, with room for only the magistrate and a couple guests.%^RESET%^",
        "pennants" : "%^BOLD%^%^BLACK%^Triangular pennants stand at attention from f%^RESET%^la%^BOLD%^gpo%^RESET%^le%^BOLD%^%^BLACK%^s jutting up from the far wall of the %^RESET%^%^ORANGE%^coliseum%^BOLD%^%^BLACK%^. Each depicts a different %^WHITE%^s%^RESET%^i%^BOLD%^g%^RESET%^i%^BOLD%^l %^BLACK%^on various %^RESET%^%^MAGENTA%^f%^BOLD%^i%^RED%^el%^ORANGE%^d%^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^, proclaiming the various %^RESET%^%^CYAN%^guilds %^BOLD%^%^BLACK%^and %^RESET%^%^GREEN%^organizations %^BOLD%^%^BLACK%^with a vested interest in the coliseum.%^RESET%^",
        "benches" : "%^BOLD%^W%^RESET%^h%^BOLD%^it%^RESET%^e m%^BOLD%^arb%^RESET%^l%^BOLD%^e %^BLACK%^benches wrap around the arena in gentle curves, partitioned into sections by stairs and paths between.%^RESET%^",
        "arena" : "%^BOLD%^%^BLACK%^The arena is comprised of a large %^RESET%^%^ORANGE%^circular patch %^BOLD%^%^BLACK%^of %^RESET%^%^ORANGE%^packed sand %^BOLD%^%^BLACK%^surrounded by tall walls of %^RESET%^stone%^BOLD%^%^BLACK%^. There is an archway leading off to the northeast, though anything beyond the entrance is cloaked in shadow and obscured. A faint %^CYAN%^s%^GREEN%^h%^CYAN%^i%^GREEN%^m%^CYAN%^m%^GREEN%^e%^CYAN%^r%^GREEN%^i%^CYAN%^n%^GREEN%^g a%^CYAN%^u%^GREEN%^r%^CYAN%^a %^BLACK%^seems to hover above the arena proper.%^RESET%^",
        "aura" : "%^BOLD%^%^BLACK%^A vague %^CYAN%^b%^GREEN%^o%^CYAN%^r%^GREEN%^d%^CYAN%^e%^GREEN%^r %^BLACK%^is apparent over the arena, evidence of some %^GREEN%^m%^CYAN%^a%^GREEN%^g%^CYAN%^i%^GREEN%^c %^BLACK%^at play, present to prevent interference to and from the combatants within. If you focus, you can %^WHITE%^look into the arena %^BLACK%^to get a closer look at it. %^RESET%^",
        ]));
}

void reset(){
    ::reset();
    if(!present("street_light", TO)) new(OBJ+"glowstone")->move(TO);
}


void init(){
    ::init();
    add_action("look_em","look");
}

int look_em(string str) {
    if(str != "into the arena") return 0;
    if(TP->query_blind() || TP->query_blindfolded() || TP->query_unconscious()){
        write("You cannot do that in your current state!");
        return 1;
    }
    write("%^BOLD%^%^BLACK%^You look carefully within the arena and study what lies within: %^RESET%^");
    long_look_room(find_object_or_load("/d/shadow/coliseum/room/arena.c"));
    return 1;
}

int long_look_room(object dest){
    object *inv;
    int i,j;
    message("room_description","\n%^BOLD%^%^CYAN%^[A] %^RESET%^"+(string)dest->query_long()+"", TP);
    inv = all_inventory(dest);
    if(sizeof(inv)< 1) return 1;
    for(i=0;i<sizeof(inv);i++){
     	if(!objectp(inv[i])) continue;
     	if(inv[i]->query_invis()) continue;
    	if(!inv[i]->is_detectable()) continue;
    	TO->send_living_name(inv[i]);
    }
    return 1;
}

int send_living_name(object targ){
	string known, str;
	int i,j;
	
    if(targ->is_monster()){
	    str = targ->query_short();
	    message("living_item", "%^CYAN%^%^BOLD%^[%^GREEN%^A%^CYAN%^] %^RED%^"+str,TP);
        return 1;
    }
    if(objectp(TP) && TP->knownAs(targ->query_true_name())){
	    known = TP->knownAs(targ->query_true_name());
    }
    str = targ->getWholeDescriptivePhrase();
    if(known){
        str = capitalize(known)+", "+str;
    }
    if(str){
        message("living_item", "%^CYAN%^%^BOLD%^[%^GREEN%^A%^CYAN%^] %^RED%^"+str, TP);
    }
    known = 0;
    return 1;
}

