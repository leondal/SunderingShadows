//General difficulty increase Octothorpe 5/25/09
#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit "/std/monster";
int SHOUT;
void init() {
    ::init();
    if(interactive(TP)){ 
         call_out("do_kill",10,TP);
    }
}
void create() {
    ::create();

    set_property( "no_scry", 1 );
    set_name("render");
    set_id( ({"render","beast","render_beast"}) );
    set_hd(45,9);
   set_property("full attacks",1);
    set_short("%^RESET%^%^RED%^The beast known only as '%^BLUE%^Render%^RED%^'%^RESET%^");
    set_long("%^BLUE%^"
	"The thing that stands before you is a humanoid creature that "
	"appears to be half wolf, half giant. It snarling lips show a jagged row of teeth and "
	"it's gnarled over-sized hands display long steel like nails stretching two inches out "
	"from the tips of it's fingers. It's eyes blaze with a black hatred so intense you have a hard "
	"time staring at them. Much matted hair covers it's sinewy body. The only clothing it wears is a "
	"tattered and torn waist cloak that is covered in dried blood. This can only be the beast known as "
	"'Render', responsible for slaying citizens of the Northern lands for over a decade before it "
	"mysteriously vanished to places unknown. You pray you will live to tell of it's whereabouts to others.%^RESET%^" 
    );
    set("race", "giant" );
    set_body_type("human");
    set_overall_ac(-20);
    set_alignment(9);
    set_stats("intelligence", 25);
    set_stats("wisdom", 25);
    set_stats("charisma",-20);
    set_stats("strength", 30);
    set_stats("dexterity", 30);
    set_stats("constitution", 30);
    set_class("fighter");
    set_guild_level("fighter",45);
    set_property("not random monster", 1); //added by saide in order to prevent these from spawning in alternative worlds
    add_search_path("cmds/fighter");
   set_max_hp(1500);
   set_hp(1500);
    set_exp(120000);
    set_max_level(36);
   set_property("add kits",25);
    set_funcs(({
	   "special",
	   "kdit",
	   "rushit",
	   "shatterit",
	   "sunderit",
	   "parry"
	}));
    set_func_chance(50);      
    set("aggressive","attack_fun");
    set_mob_magic_resistance("average");
    new( OPATH "woodlandarmor.c" )->move(TO);//added the armor because it fits in with the lore of the armor, and he is one of the few powerful enough to plant the armor on
    new( OPATH "storm.c" )->move(TO);
      command("wield sword");
    set_moving( 1 );
    set_speed ( 20 );
    set_monster_feats(({
	   "toughness",
	   "improved toughness",
	   "damage resistance",
	   "improved damage resistance",
	   "regeneration",
	   "powerattack",
	   "shatter",
	   "sunder",
	   "rush",
	   "knockdown"
	}));		
}
void do_kill(object ob){
    string who;
    if(!TO->query_current_attacker()) return;
    if(objectp(ob) && present(ob,environment(TO))){
        who = ob->query_name();
        ("/cmds/spells/d/_dispel_magic.c")->use_spell(TO,who,45,100,"mage");
        call_out("do_kill",20,ob);   
    }
}

void special(object targ) {
        command( "say You are foolish to have released me!");
	command( "say Once I finish you the rest of your world will perish at my hands!");
        TO->force_me("rush "+targ->query_name());
        return 1;
}
int attack_fun() {
    object ob;
    if( !this_player() ) return 1;
    if( this_player()->query_ghost() ) return 1;
    if( (int)this_player()->query_alignment() != 9 ) {
      if(SHOUT == 0) {
       tell_room(ETO, 
	   "%^RESET%^%^BLUE%^The beast known only as '%^RED%^Render%^BLUE%^' shouts: %^RESET%^"
	   "You were foolish to have released me "+TP->query_cap_name()+"! Now prepare to DIE in agony!!!"
	   "%^RESET%^");
       SHOUT = 1;
      }
        TO->force_me("rush "+TP->query_name());
        return 1;
   } else {
        command( 
	    "say Despite the fact we are of same blackened heart, you are weak and shall be slain like the others!"
	);
        TO->force_me("kill "+TP->query_name());
        return 1;
   }
}
void heart_beat() {
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
     if((int)TO->query_hp() < 250) {
	TO->add_hp(random(3)+1);
	return;
    } else {
        return;
    }
}

void set_paralyzed(int time,string message){return 1;}

void kdit(object targ)
{
    if(!objectp(TO)) { return; }
    if(!objectp(targ)) { return; }
    TO->force_me("knockdown "+targ->query_name());
    return;
}

void rushit(object targ)
{
    if(!objectp(TO)) { return; }
    if(!objectp(targ)) { return; }
    TO->force_me("rush "+targ->query_name());
    return;
}

void sunderit(object targ)
{
    if(!objectp(TO)) { return; }
    if(!objectp(targ)) { return; }
    TO->force_me("sunder "+targ->query_name());
    return;
}

void shatterit(object targ)
{
    if(!objectp(TO)) { return; }
    if(!objectp(targ)) { return; }
    TO->force_me("shatter "+targ->query_name());
    return;
}
