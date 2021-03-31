//Added feats and new descript - Octothorpe 12/18/09
//Updated for inclusion to Demongate - Octothorpe 5/25/09
//May Grimmy have mercy on the poor sods that log out in the
//room outside of Vecna

#include <std.h>
#include "/d/dagger/drow/short.h"
inherit MONSTER;

void init() {
    ::init();
    //add_action("limb_fun","con");
    add_action("limb_fun","grin");
    add_action("limb_fun","pat");
    add_action("limb_fun","throw");
    add_action("limb_fun","bump");
    add_action("limb_fun","stab");
    add_action("limb_fun","rush");
    //add_action("limb_fun","say");
   if(interactive(TP) && !wizardp(TP)){
         call_out("do_kill",10,TP);
    }
}
void create() {
    object ob;
    object ob1;
    ::create();
    set_name("grimtooth");
    set_id( ({"grimtooth"}) );
    set_hd(40,8);
    set_short("%^BOLD%^%^BLACK%^Grimtooth%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This powerful monstrosity is known as "+
	   "a draegloth, a result of the profane copulation of a drow "+
	   "female and a demon.  The draegloth reaches to a height of "+
	   "nearly eight feet, and is powerfully built with a mass of "+
	   "corded muscles.  Its drow heritage is apparent with ebony "+
	   "skin, and long, ragged %^WHITE%^white %^BOLD%^%^BLACK%^hair "+
	   "which covers nearly half of its body.  The demonic head is "+
	   "elongated into a lupine snout bearing a mouth full of sharp "+
	   "teeth.  Two sets of extended arms lead to four deadly claws "+
	   "that look more than capable of rending through hardened steel.");
    set_race("draegloth");
    set_gender("male");
    set_body_type("human");
    set_overall_ac(-18);
    set_alignment(9);
    set_speed(40);
      set_property("no steal", 1);
   set_property("no dominate", 1);
   set_property("no hold", 1);
   set_property("no paralyze", 1);
    set_property( "no_scry",1);
    set_property("demongate flying",1);
    set_stats("intelligence",23);
    set_stats("wisdom",25);
    set_stats("charisma",10);
    set_stats("strength",28);
    set_stats("dexterity",30);
    set_stats("constitution",30);
    set_class("fighter");
    set_class("thief");
	set_mlevel("fighter",45);
    set_mlevel("thief",45);
	set_guild_level("thief",45);
	set_guild_level("fighter",45);
    set_thief_skill("move silently",95);
	add_search_path("/cmds/thief");
	add_search_path("/cmds/fighter");
	add_search_path("/cmds/feats");
    set_scrambling(1);
    set_invis();
    set_max_hp(3000);
    set_hp(query_max_hp());
    set_exp(100000);
    set_mob_magic_resistance("average");
    set_property("add kits",20);
    set_funcs(({"dart","crit","kdit"}));
    set_func_chance(40);
    set_property("full attacks",1);
	add_attack_bonus(10);
	add_damage_bonus(10);
    set("aggressive","attack_fun");
	command("speech %^BLUE%^growl");
   if(!random(2)) {
   new("/d/dagger/marsh/tower/obj/shadowbracers.c")->move(TO);
   command("wear bracers");
   }
   ob = ("/d/dagger/marsh/tower/obj/shclaws.c")->move(TO);
   command("wield claw");
   ob1 = ("/d/dagger/marsh/tower/obj/shclaws2.c")->move(TO);
   command("wield blerg");
   if(!random(2)) {
    new( OPATH "thood.c" )->move(TO);
    command("wear hood");
   }
    set_monster_feats(({
	  "dodge",
      "mobility",
	  "evasion",
	  "combat reflexes",
	  "toughness",
	  "improved toughness",
	  "damage resistance",
	  "improved damage resistance",
	  "regeneration",
	  "parry"
    }));
    set_property("cast and attack",1);
    set_property("function and attack",1);
}

void do_kill(object ob){
    string who;
    if(!TO->query_current_attacker()) return;
    if(objectp(ob) && present(ob,environment(TO))){
        who = ob->query_name();
        new("/cmds/spells/d/_dispel_magic.c")->use_spell(TO,who,50,100,"mage");
        call_out("do_kill",20,ob);
    }
}

void dart(object targ) {
    command( "say I *hate* you! Why the hell... dammit you're still here!");
	command( "say Thats it "+targ->QCN+"!! YOU DIE NOW!!!");
        message( "info","%^RED%^"
            "Grimtooth whirls around slashing you deep across the face!\n"
            "As your own blood flows into your eyes blinding you, you\n"
	    "feel Grimtooth's forehead smash into your skull!%^RESET%^"
	,targ );
        message( "info","%^RED%^"
            "Grimtooth whirls around slashing "
	    +targ->query_cap_name()+
	    " deep across the face!\n"
            "As "
	    +targ->query_cap_name()+
	    "'s blood flows, Grimtooth smashes\n"
	    "his forehead into "
	    +targ->query_cap_name()+
	    "'s skull!%^RESET%^"
        ,environment(targ), targ );
        targ->do_damage("head",roll_dice(10,8));
        targ->set_paralyzed(random(30)+10,"%^RED%^You are still reeling "
	    "from the blow!%^RESET%^");
        return 1;
}
int limb_fun(string str) {
    object targ;
    targ = this_player();
    if((string)targ->query_name() == "grazzt") {
        command( "grin grazzt" );
        return 1;
    } else {
        command( "say Don't screw with me "+
            this_player()->query_cap_name()+". ");
        message( "info","%^RED%^"
            "Grimtooth whirls around slashing you deep across the face!\n"
            "As your own blood flows into your eyes blinding you, you\n"
	    "feel Grimtooth's forehead smash into your skull!%^RESET%^"
	,targ );
        message( "info","%^RED%^"
            "Grimtooth whirls around slashing "
	    +this_player()->query_cap_name()+
	    " deep across the face!\n"
            "As "
	    +this_player()->query_cap_name()+
	    "'s blood flows, Grimtooth smashes\n"
	    "his forehead into "
	    +this_player()->query_cap_name()+
	    "'s skull!%^RESET%^"
        ,environment(targ), targ );
        targ->do_damage("head",roll_dice(10,6));
        targ->set_paralyzed(random(30)+10,"%^RED%^You are still reeling "
	    "from the blow!%^RESET%^");
        return 1;
    }
}
int attack_fun() {
    object ob;
    if( !this_player() ) return 1;
    if( !userp(this_player()) ) return 1;
    if( (string)this_player()->query_name() == "grazzt") return 1;
    if( (string)this_player()->query_name() == "octothorpe") return 1;
    if( this_player()->query_ghost() ) return 1;
    if( (string)this_player()->query_race() == "drow" ) return 1;
    if( (int)this_player()->query_alignment() != 9 ) {
        command(
	    "say It is the likes of you who bring "
            "ruin to my people!"
	);
        command(
	    "say Oh gods of darkness! Heed my call and "
            "give me the power to strike down "
            +(string)this_player()->query_cap_name()+
	    "!"
	);
        call_out("stab",1,TP);
        write(
	    "%^RED%^Your blood spills out onto the ground!%^RESET%^"
	);
        set_invis();
        return 1;
   } else {
        command(
	    "say You are not allowed to roam the "
            "lands free from drowish slavery!"
	);
        call_out("sic_em",1,TP);
        return 1;
   }
}
void heart_beat() {
    ::heart_beat();

    if(!objectp(TO)) return;
    if(!objectp(ETP)) return;
    if(present("corpse",environment(this_object())))
        if(!query_current_attacker() ) {
            command("get all from corpse");
            command("grin");
            message("environment",
                "%^RED%^Suddenly, Grimtooth "
                "decides to offer the corpse!%^RESET%^"
            ,environment(this_object()));
            command("offerall");
            command("offerall");
            command("chuckle");
            set_invis();
        }
    return;
}
void stab(object targ) {
    int mod;
    mod = 3;
/*
if(TP->is_class("mage")) mod = 2;
        write("%^BOLD%^%^RED%^"
	    "Someone executes an assassin like stab upon you!"
	    "%^RESET%^"
	);
	say("%^BOLD%^%^RED%^"
	    "Someone executes an assassin like stab upon "
	    +targ->query_cap_name()+
	    "!%^RESET%^"
	,TP);
	write("%^RED%^"
	    "Someone plunges his claws into your head!"
	    "%^RESET%^"
	);
	say("%^RED%^"
	    "Someone plunges his claws into "
	    +targ->query_cap_name()+
	    "'s head!%^RESET%^"
	,TP);
	targ->do_damage("head",random(25)*mod);
	write("%^RED%^"
	    "Someone plunges his claws into your head!"
	    "%^RESET%^"
	);
	say("%^RED%^"
	    "Someone plunges his claws into "
	    +targ->query_cap_name()+
	    "'s head!%^RESET%^"
	,TP);
	targ->do_damage("head",random(25)*mod);
	write("%^RED%^"
	    "Someone plunges his claws into your head!"
	    "%^RESET%^"
	);
	say("%^RED%^"
	    "Someone plunges his claws into "
	    +targ->query_cap_name()+
	    "'s head!%^RESET%^"
	,TP);
	targ->do_damage("head",random(25)*mod);
	write("%^RED%^"
	    "Someone plunges his claws into your head!"
	    "%^RESET%^"
	);
	say("%^RED%^"
	    "Someone plunges his claws into "
	    +targ->query_cap_name()+
	    "'s head!%^RESET%^"
	,TP);
	targ->do_damage("head",random(25)*mod);
	write("%^RED%^"
	    "Someone plunges his claws into your head!"
	    "%^RESET%^"
	);
	say("%^RED%^"
	    "Someone plunges his claws into "
	    +targ->query_cap_name()+
	    "'s head!%^RESET%^"
	,TP);
	targ->do_damage("head",random(25)*mod);
	write("%^RED%^"
	    "Someone plunges his claws into your head!"
	    "%^RESET%^"
	);
	say("%^RED%^"
	    "Someone plunges his claws into "
	    +targ->query_cap_name()+
	    "'s head!%^RESET%^"
	,TP);
	targ->do_damage("head",random(30)*mod);
        command( "tell octothorpe Buahahahha...i just stabbed "+TPQCN+"! ;)");
        new( OPATH "blood.c" )->move(environment(TO));
        command( "kill "+targ->query_name() );
        TP->add_follower(TO);
*/
}
void sic_em(object targ) {
    if((string)TO->query_current_attacker() != targ) {
        if(random(10) < 7) {
            command( "kill "+targ->query_name() );
        } else {
	    command(
		"say Hmm...Wait here "
		+targ->query_cap_name()+"."
	    );
	    command(
		"say I will return shortly to execute you!"
	    );
            command("east");
	    command("north");
	    command("west");
	    command("south");
	    command("up");
	    command("down");
        }
    } else {
        command( "say Submit or die scum!" );
    }
}

void kdit(object targ){
   TO->force_me("knockdown "+targ->query_name());
   return;
}

void crit(object targ){
   TO->force_me("crit "+targ->query_name());
   return;
}

void set_paralyzed(int time,string message){return 1;}
void die(object ob) {
    message("environment",
	"%^BOLD%^%^BLUE%^Grimtooth's soul departs back to the Abyss!"
	"%^RESET%^"
    ,environment(TO));
    message("info",
	"%^BOLD%^%^RED%^The demons of the Abyss cackle as Grimtooth's "
        "soul is banished from the realms!%^RESET%^"
    ,users());
    ::die();
}
