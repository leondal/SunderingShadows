// Chernobog (5/1/21)
// Shadow Coliseum

#include <std.h>
#include "../defs.h"
#include <move.h>

#define SCRY_D "/daemon/ic_scry_locate_d"
inherit VAULT;

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
    set_short("%^BOLD%^T%^MAGENTA%^h%^RESET%^%^MAGENTA%^e %^BOLD%^%^WHITE%^M%^MAGENTA%^agist%^RESET%^%^MAGENTA%^rate's %^BOLD%^%^WHITE%^V%^MAGENTA%^iew%^RESET%^%^MAGENTA%^ing %^BOLD%^%^WHITE%^B%^MAGENTA%^o%^RESET%^%^MAGENTA%^x%^WHITE%^");
    set_long("%^RESET%^%^MAGENTA%^This private viewing box is small and intimate in design. Only a pair of %^BOLD%^%^BLACK%^p%^RESET%^l%^BOLD%^%^BLACK%^u%^WHITE%^s%^BLACK%^h se%^RESET%^a%^BOLD%^t%^BLACK%^s %^RESET%^%^MAGENTA%^are present, with a small %^BOLD%^%^BLACK%^t%^RESET%^%^CYAN%^a%^BOLD%^b%^RESET%^%^CYAN%^l%^BOLD%^%^BLACK%^e %^RESET%^%^MAGENTA%^between them to carry sweet meats or other treats while the entertainment of the arena is viewed down below past the protective %^BOLD%^%^GREEN%^a%^CYAN%^u%^GREEN%^r%^CYAN%^a%^RESET%^%^MAGENTA%^. At a corner of the room is a small %^RED%^b%^BOLD%^r%^RESET%^%^RED%^a%^BOLD%^zi%^RESET%^%^RED%^e%^BOLD%^r%^RESET%^%^MAGENTA%^, a thin plume of %^BOLD%^%^BLACK%^l%^RESET%^a%^BOLD%^%^BLACK%^zy sm%^RESET%^o%^BOLD%^%^BLACK%^ke %^RESET%^%^MAGENTA%^twisting sinuously upwards. A %^ORANGE%^mahogany door %^MAGENTA%^stand before the stairwell back to the main concourse.%^WHITE%^\n");
    set_smell("default","A pleasant sandalwood incense wafts about.");
    set_listen("default","The sound of snapping and fluttering pennants whisper on the wind.");
    set_items(([
        ({"brazier","smoke"}) : "%^BOLD%^%^BLACK%^This small %^RESET%^%^RED%^b%^BOLD%^r%^RESET%^%^RED%^a%^BOLD%^zi%^RESET%^%^RED%^e%^BOLD%^r %^BLACK%^sits on a table in the corner of the room. It is s%^RESET%^i%^BOLD%^lv%^RESET%^e%^BOLD%^%^BLACK%^r and oval, with a series of teardrop holes spiraling on the lid. The %^RESET%^w%^BOLD%^i%^RESET%^spy %^BOLD%^%^BLACK%^strands of %^RESET%^sm%^BOLD%^o%^RESET%^ke %^BOLD%^%^BLACK%^rising from it possess a pleasant %^RESET%^%^ORANGE%^sandalwood %^BOLD%^%^BLACK%^scent.%^RESET%^",
        "seats" : "%^BOLD%^%^BLACK%^These chairs are %^RESET%^%^MAGENTA%^pl%^BOLD%^u%^WHITE%^s%^RESET%^%^MAGENTA%^h %^BOLD%^%^BLACK%^and %^RESET%^%^CYAN%^comfortable%^BOLD%^%^BLACK%^, with enough padding that it feels like you are sinking into a cloud. The fabric of the seat and back have been dyed a %^RESET%^%^MAGENTA%^de%^BOLD%^e%^RESET%^%^MAGENTA%^p vio%^BOLD%^l%^WHITE%^e%^RESET%^%^MAGENTA%^t h%^BOLD%^u%^RESET%^%^MAGENTA%^e %^BOLD%^%^BLACK%^on an ebony frame, paired pleasingly with the t%^RESET%^%^CYAN%^a%^BOLD%^b%^RESET%^%^CYAN%^l%^BOLD%^%^BLACK%^e between them.%^RESET%^",
        "table" : "%^BOLD%^%^BLACK%^A %^CYAN%^s%^RESET%^%^CYAN%^m%^BOLD%^oo%^RESET%^%^CYAN%^t%^BOLD%^h g%^RESET%^%^CYAN%^l%^BOLD%^as%^RESET%^%^CYAN%^s %^BOLD%^%^BLACK%^top rests on an ebony frame, pairing neatly with the chairs on either side of it.%^RESET%^",
        "pennants" : "%^BOLD%^%^BLACK%^Triangular pennants stand at attention from f%^RESET%^la%^BOLD%^gpo%^RESET%^le%^BOLD%^%^BLACK%^s jutting up from the far wall of the %^RESET%^%^ORANGE%^coliseum%^BOLD%^%^BLACK%^. Each depicts a different %^WHITE%^s%^RESET%^i%^BOLD%^g%^RESET%^i%^BOLD%^l %^BLACK%^on various %^RESET%^%^MAGENTA%^f%^BOLD%^i%^RED%^el%^ORANGE%^d%^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^, proclaiming the various %^RESET%^%^CYAN%^guilds %^BOLD%^%^BLACK%^and %^RESET%^%^GREEN%^organizations %^BOLD%^%^BLACK%^with a vested interest in the coliseum.%^RESET%^",
        "aura" : "%^BOLD%^%^BLACK%^A vague %^CYAN%^b%^GREEN%^o%^CYAN%^r%^GREEN%^d%^CYAN%^e%^GREEN%^r %^BLACK%^is apparent over the arena, evidence of some %^GREEN%^m%^CYAN%^a%^GREEN%^g%^CYAN%^i%^GREEN%^c %^BLACK%^at play, present to prevent interference to and from the combatants within. If you focus, you can %^WHITE%^look into the arena %^BLACK%^to get a closer look at it. %^RESET%^",
        ]));
    set_exits(([
        "down" : ROOMS"concourse5",
        ]));
    set_door("mahogany door", ROOMS"concourse5", "down", 0);
    set_door_description("mahogany door","%^RESET%^%^ORANGE%^Rich mahogany planks %^BOLD%^%^BLACK%^have been fashioned into this %^RESET%^o%^BOLD%^r%^RESET%^n%^YELLOW%^a%^RESET%^t%^BOLD%^e %^BLACK%^d%^RESET%^o%^BOLD%^o%^RESET%^r%^BOLD%^%^BLACK%^. %^RESET%^Iron panels %^BOLD%^%^BLACK%^reinforce it, creating a solid barrier to the viewing box.%^RESET%^");
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

