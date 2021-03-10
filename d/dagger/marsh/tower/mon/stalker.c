#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit "std/monster";
 
object owner;
int FLAG,STAB;
void create() {
    :: create();
    set_name("something");
    set_id(({
        "something","shadowthing","stalker"
    }));
    set_long(
        "A shadowy shape of non-existance."
    );
    set_gender("male");
    set_level(25);
    set_hd(25,8);
    set_weight(90);
    set_overall_ac(-15);
    set_body_type("humanoid");
    set_race("human");
    set_class("thief");
    set_guild_level("thief",25);
    set_stats("strength",23);
    set_stats("constitution",23);
    set_stats("dexterity",25);
    set_stats("wisdom",22);
    set_stats("intelligence",24);
    set_stats("charisma",20);
    set_mob_magic_resistance("average");
    set_exp(25000);
    set_max_hp(250);
    set_hp(250);
    set_thief_skill("move silently",99);
    set_thief_skill("hide in shadows",99);
    add_search_path( "cmds/thief" );
    set("aggressive","aggfunc");
    set_invis();  
    new( OPATH "sdagger.c")->move(this_object());
    command("wield dagger in right hand");
    new( OPATH "sdagger.c")->move(this_object());
    command("wield dagger in left hand"); 
    add_money("gold",random(1000));
    set_emotes(1,({
        "%^BLUE%^A shadow leaps from the wall and runs out of the room!%^RESET%^",
	"A feeling of fear washes through you!",
	"You feel as though you are being watched.",
    }),0);	
}
void aggfunc() {
    if(present("death_figure",TP)) {
        if(FLAG == 0) {
	    owner = TP;
            FLAG = 1;
	    STAB = 0;
	    write(
	        "A cold chill runs up your spine."
	    );
        }
    }
}    
void heart_beat() {
    object env;
    ::heart_beat();
    
    if(!objectp(TO)) { return; }
    env = environment(this_object());
    if(!owner) return;
    if(FLAG == 0) return;
    if(owner->query_ghost()) {
	FLAG == 0;
        TO->remove();
        return;
    }
    if(present(owner,env)) {
        if(owner->query_hp() < 60 && STAB == 0) {
	    STAB = 1;
	    TO->force_me("yell Through weakness I strike! Now join my masters in death!");
            TO->force_me("stab "+owner->query_name());
	    return;
        }
        if(random(10) < 3) {
            owner->add_hp(-(random(1)+1));
	    return;
	} else {
            return;
        }
    } else {        
        if(environment(TO) !=environment(owner)) {
            TO->move_object(environment(owner));
      	    return;
        } 
    } 
}
