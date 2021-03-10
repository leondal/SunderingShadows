#include <std.h>
inherit OBJECT;
object owned;
void init() {
    ::init();
    if(interactive(TP) && !owned) owned = TPQN;
    add_action("play_fun","play");
    if(TP->query_property("playing") > 0) {
	TP->remove_property("playing");
    }
}
void create() {
    ::create();
    set_name("flute");
    set_id(({"flute","flute of the ancients"}));
    set_short("%^RESET%^%^CYAN%^Flute of the ancients%^RESET%^");
    set_long(
	"%^CYAN%^This is lovely wooden flute carved from wood from the "
	"Lywaneon forests. It was obviously owned by a bard at one time or another "
	"and emits a magical aura. It still seems in excellent condition."
	"%^RESET%^"
    );
    set_weight(5);
    set_value(1000);
}
int play_fun(string str) {
    int x,j,lvl;
if(!TP->is_class("bard")) return 0;
  if(ETO->query_bound() || ETO->query_unconscious()){
  ETO->send_paralyzed_message("info",ETO);
  return 1;
  }
    if((int)TP->query_level() < 25) {
	notify_fail("You are not experienced enough to use this item!\n");
	return 0;
    }
   if((string)TP->query_name() != owned) {
	write("The flute vanishes!");
        TO->remove();
        return 0;
    }    	  
    if(!str) {
	notify_fail("Do you wish to play song of healing, or song of peace?\n");
	return 0;
    }
    if(str != "song of healing" && str != "song of peace") {
	notify_fail("Do you wish to play song of healing, or song of peace?\n");
	return 0;
    }
    if(str == "song of healing") {
	if((int)TP->query_property("playing") > 0) {
	    notify_fail("You are already playing the flute!\n");
	    return 0;
        } 
	write(
	    "%^CYAN%^You decide to play a merry tune!%^RESET%^"
	);
	say(
	    "%^CYAN%^"+TPQCN+" lifts a flute to "
	    +TP->query_possessive()+
	    " lips and begins to play a merry tune!%^RESET%^"
	,TP);
        x = 0;
	lvl = (int)TP->query_level();
        if(lvl > 40) lvl = 40;
	lvl = lvl/2;
        TP->set_property("playing",1);
	for(j=1;j<lvl;j++) {
	    x = x + 10;
            call_out("music",x);
        }
        x = x + 5;
	call_out("endmusic",x);
        return 1;
    }
    if(str == "song of peace") {
	if((int)TP->query_property("playing") > 0) {
	    notify_fail("You are already playing the flute!\n");
	    return 0;
        }  	    
        write("%^CYAN%^"
            "You begin to play a song of peace and traquility!%^RESET%^"
        );
        say("%^CYAN%^"
	    +TPQCN+" begins to play a song of peace and tranquility!%^RESET%^"
	,TP);
	lvl = (int)TP->query_level();
	if(lvl > 40) lvl = 40;
	call_out("peace",50-lvl);
	TP->set_property("playing",1);
        return 1;
    }
}
void music() {
    int i, max, number, main_number;
    object here,*inv;
    if(!objectp(ETO)) return;
    if(!userp(ETO)) return;
    here = ETO;
if(!TP->is_class("bard")) return;
    here = environment(ETO);
    if(!objectp(here)) return;
    tell_room(here,"%^CYAN%^"
        "The wonderful music from the flute fills the air!\n"
        "%^GREEN%^You feel your spirits lifted as it falls upon your ears!"
        "%^RESET%^"
    );
    for(i=0, max = sizeof(inv=all_inventory(here)); i<max; i++) {
        if(!living(inv[i])) continue;
        inv[i]->add_hp(random((int)here->query_level()/9)+1);
    }
    return;
}    	
void endmusic() {
    object here,*inv;
    if(!objectp(ETO)) return;
    if(!userp(ETO)) return;
    here = ETO;
    tell_object(here,"%^CYAN%^"
	"You finish your song and cease playing.%^RESET%^"
    );
    tell_room(environment(here),"%^CYAN%^"
	+here->query_cap_name()+" finishes "
	+here->query_possessive()+" song and ceases playing the flute.%^RESET%^"
    ,here);
    here->remove_property("playing");
    return;
}
void peace() {
    int i;
    object here,*inv;
    if(!objectp(ETO)) return;
    if(!userp(ETO)) return;
    here = ETO;
if(!TP->is_class("bard")) return;
    if(random(70+(int)here->query_level()) < 25) {
	write(
	    "%^RED%^Your song fails to bring peace to the area.%^RESET%^"
 	);
	say(
	    "%^RED%^"+here->query_cap_name()+" song fails to bring peace to the area.%^RESET%^"
	,TP);
	here->remove_property("playing");
	return;
    } else {
	write("%^GREEN%^"
	    "Your song brings peace and tranquility to the area!%^RESET%^"
	);
	say("%^GREEN%^"
	    +here->query_cap_name()+"'s song brings peace and tranquility to the area!%^RESET%^"
	,TP);
        inv = all_inventory(environment(here));
        for(i=0; i<sizeof(inv); i++) {
            if(!living(inv[i])) continue;
            inv[i]->cease_all_attacks();
        }
	here->remove_property("playing");
        return;
    }
}
	
