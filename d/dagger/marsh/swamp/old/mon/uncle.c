//Minor difficulty update - Octothorpe 12/18/09

#include <std.h>
inherit "/std/monster";
#define SHDIR "/d/dagger/marsh/swamp/rooms/"+
int wander;
void init() {
    ::init();
    if(interactive(TP)){ 
         call_out("do_kill",10,TP);
    }
}
void create() {
    ::create();
    set_name("istvan");
    set_id( ({"uncle","istvan","uncle istvan"}) );
    set_hd(30,7);
    set_short("%^RESET%^%^GREEN%^Uncle Istvan, Guardian of the Marsh%^RESET%^");
    set_long("%^BLUE%^"
	"The being that stands before you is a humanoid creature that "
	"appears to be half human, half giant. He stands ready and willing to "
	"drive off anyone who dares enter into the realm of his marshlands. "
	"He is bundled up in raggedy old farmer clothes and is missing half his teeth. "
	"His eyes are filled with black hate."
    );
    set("race", "giant" );
    set_property("magic", 1);
   set_property("add kits",15);
    set_mob_magic_resistance("average");
    set_level(30);
    set_body_type("human");
    set_wielding_limbs(({"right hand","left hand"}));
    set_overall_ac(-14);
    set_alignment(6);
    set_stats("intelligence", 20);
    set_stats("wisdom", 20);
    set_stats("charisma",10);
    set_stats("strength",23);
    set_stats("dexterity", 24);
    set_stats("constitution", 22);
    set_class("fighter");
    set_guild_level("fighter",30);
    add_search_path("/cmds/fighter");
    set_max_hp(650);
    set_hp(query_max_hp());
    set_exp(40000);
    set_max_level(36);
    set_property("full attacks",1);
    new("/d/dagger/marsh/tower/obj/axe.c")->move(TO);
    command("wield axe in left hand");
    set_funcs(({"special","kdit"}));
    set_func_chance(20);   
    add_search_path("/cmds/feats");
    set_monster_feats(({"toughness","improved toughness","damage resistance","improved damage resistance","regeneration"}));	
    set("aggressive","attack_fun");

    set_emotes(1,({
	"%^MAGENTA%^Uncle Istvan says:%^RESET%^ Die you damn maggot!",
    }),1);	
}
void special(object targ) {
        command( "say We 'ate your kine 'round here!");
	command( "say Take dis ya shun of a biyatch!!!");
        TO->force_me("rush "+targ->query_name());
        return 1;
}
void do_kill(object ob){
    if(!TO->query_current_attacker()) return;
    if(objectp(ob) && present(ob,environment(TO))){
        new("/cmds/wizard/_dispel_magic.c")->use_spell(TO,ob,20 + random(15),20 + random(15));
        call_out("do_kill",20,ob);   
    }
}

int attack_fun() {
    object ob;
    if((int)TP->query_level() > 499) return 1;
    if( this_player()->query_ghost() ) return 1;
    TO->force_me("say What the livin hell are you doing in my swamp fool?!?");
    TO->force_me("say Take this you friggin rodent spawn she-runt!!!");
    TO->force_me("rush "+TP->query_name());
    return 1;
}
void heart_beat() {
    string *exits;
    string exitn;	
    int i,j;
    ::heart_beat();
    if(!objectp(TO)) return;

    if((int)TO->query_hp() < 150) {
	TO->add_hp(random(5)+5);
	return;
    } else {
// Thanks to Tristan for example for this.
    if(wander > 20 && query_attackers() == ({})){
        exits = environment(TO)->query_exits();
        i = sizeof(exits);
        j = random(i);
        exitn = (string)environment(TO)->query_exit(exits[j]);
        if(exitn != SHDIR "m44") {
            TO->force_me(exits[j]);
	    wander = 0;
	    return;
	} else {
	    return;
	}
    } else {
        wander = wander + 1;
	return;
    }
  }
}
void set_paralyzed(int time,string message){return 1;}

 void kdit(object targ){
   TO->force_me("knockdown "+targ->query_name());
   return;
}
