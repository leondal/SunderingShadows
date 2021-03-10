#include <std.h>
#include "/d/dagger/drow/short.h"
inherit "/std/monster";
void init() {
    ::init();
   if(interactive(TP) && !wizardp(TP)){
         call_out("do_kill",10,TP);
   }
}
void create() {
    ::create();

    set_property("no_paralyze", 1);
    set_property( "no_scry", 1 );
    set_name("grimtooth");
    set_id( ({"grimtooth"}) );
    set_hd(54,7);
    set_short("%^RESET%^%^RED%^Grimtooth%^RESET%^");
    set_long("%^BLUE%^"
        "Grimtooth the Assassin, the long-lost butcher of ages past. "
        "Grimtooth was known as "
        "the elven slayer. He was formed by the mingling of a female High"
        "Drow Priest with a male powerful wolfwere. "
        "He single-handedly brought the elven race "
        "to near extinction. There were less than one-hundred elves left "
        "alive when, for no explainable reason, Grimtooth simply vanished."
        "Now you know why - he became a living shadow assassin! "
        "His appearance on "
        "the plane of mortals is a grave event indeed - there is no way "
        "to know how high the body count will be this time around. ");
    set("race", "drow" );
    set_gender( "male" );
    set_body_type("human");
    set_overall_ac(-18);
    set_alignment(9);
    set_speed(40);
    set_stats("intelligence", 23);
    set_stats("wisdom", 25);
    set_stats("charisma",10);
    set_stats("strength", 28);
    set_stats("dexterity", 30);
    set_stats("constitution", 30);
    set_class("fighter");
    set_class("thief");
    set_mlevel("thief",60);
    set_class("assassin");
    set_guild_level("fighter",60);
    set_thief_skill("move silently",95);
    set_skill("stealth",95);
    set_thief_skill("hide in shadows",95);
    add_search_path("/cmds/assassin");
     set_scrambling(1);
    set_invis();
    set_max_hp(500);
    set_hp(500);
    set_exp(100000);
    set_mob_magic_resistance("average");
    set_funcs(({"dart"}));
    set_func_chance(25);
   set_property("full attacks",1);
    set("aggressive","attack_fun");
    set_emotes(19, ({
        "%^BOLD%^%^CYAN%^Grimtooth says:%^RESET%^%^RED%^ I long for blood!"
        "%^RESET%^",
        "%^RED%^"
        "Grimtooth cackles madly. "
        "%^RESET%^",
        "Grimtooth says: You will die like the rest of the elven scum!",
        "%^BOLD%^%^BLUE%^"
        "Grimtooth looks at you as the butcher looks at the turkey. "
        "%^RESET%^",
        "%^RED%^Grimtooth screams: %^RESET%^I will stain your soul until "
	"it sleeps again!"
	"%^RESET%^",
	"%^RED%^Grimtooth screams: %^RESET%^`So tear me open, but beware! "
	"There are things inside without a care!\n%^BLUE%^%^BOLD%^"
	"Grimtooth slices deep searching for your heart!%^RESET%^",
	"%^BOLD%^%^YELLOW%^Grimtooth growls: %^RESET%^I'm on a holiday"
	"...A hooligan's holiday!",
	"%^BOLD%^%^GREEN%^Grimtooth says: %^RESET%^Everybody wants a "
	"piece of the action...I'm here to give it to you.",
	"%^GREEN%^Grimtooth yells: %^RESET%^DIE ALREADY! "
	"What the hell?!?",
	"%^GREEN%^%^BOLD%^Grimtooth whispers to you: %^RESET%^"
	"You think I'm bad...wait till you meet Chronic!",
        "%^BOLD%^%^RED%^Grimtooth says: %^RESET%^The game is vicious"
	"...early retirement...you die young...you awake in yet another "
	"hundred years."}), 1);
   /* if(!random(2)) { */
   /*     new( OPATH "gcutlass.c" )->move(TO); */
   /* } */
   /* else { */
   /*  new(OPATH"blsword.c")->move(TO); */
   /* } */
   command("wield sword");
   new( OPATH "blsword.c" )->move(TO);
   command("wield sword");
   if(!random(2)) {
    new( OPATH "thood.c" )->move(TO);
    command("wear hood");
   }
   new( OPATH "mask.c" )->move(TO);
   if(!random(2)) {
    new("/d/laerad/obj/bracers6.c")->move(TO);
    command("wear bracers");
   }
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
	command( "say Thats it "+targ->query_cap_name()+"!! YOU DIE NOW!!!");
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

int attack_fun() {
    object ob;
    if( !this_player() ) return 1;
    if( !userp(this_player()) ) return 1;
    if( (string)this_player()->query_name() == "grazzt") return 1;
    if( this_player()->query_ghost() ) return 1;
    if( (string)this_player()->query_race() == "drow" ) return 1;
    if( (int)this_player()->query_alignment() != 9 ) {
        command(
	    "say It is the likes of you who bring "
            "ruin to my people!"
	);
        command(
	    "say Oh Lloth! Heed my call and "
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
    mod = 5;
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
	    "Someone plunges his dagger into your head!"
	    "%^RESET%^"
	);
	say("%^RED%^"
	    "Someone plunges his dagger into "
	    +targ->query_cap_name()+
	    "'s head!%^RESET%^"
	,TP);
	targ->do_damage("head",random(5)+mod);
	write("%^RED%^"
	    "Someone plunges his dagger into your head!"
	    "%^RESET%^"
	);
	say("%^RED%^"
	    "Someone plunges his dagger into "
	    +targ->query_cap_name()+
	    "'s head!%^RESET%^"
	,TP);
	targ->do_damage("head",random(5)+mod);
	write("%^RED%^"
	    "Someone plunges his dagger into your head!"
	    "%^RESET%^"
	);
	say("%^RED%^"
	    "Someone plunges his dagger into "
	    +targ->query_cap_name()+
	    "'s head!%^RESET%^"
	,TP);
	targ->do_damage("head",random(5)+mod);
	write("%^RED%^"
	    "Someone plunges his dagger into your head!"
	    "%^RESET%^"
	);
	say("%^RED%^"
	    "Someone plunges his dagger into "
	    +targ->query_cap_name()+
	    "'s head!%^RESET%^"
	,TP);
	targ->do_damage("head",random(10)+mod);
	write("%^RED%^"
	    "Someone plunges his dagger into your head!"
	    "%^RESET%^"
	);
	say("%^RED%^"
	    "Someone plunges his dagger into "
	    +targ->query_cap_name()+
	    "'s head!%^RESET%^"
	,TP);
	targ->do_damage("head",random(15)+mod);
	write("%^RED%^"
	    "Someone plunges his dagger into your head!"
	    "%^RESET%^"
	);
	say("%^RED%^"
	    "Someone plunges his dagger into "
	    +targ->query_cap_name()+
	    "'s head!%^RESET%^"
	,TP);
	targ->do_damage("head",random(8)+mod);
        command( "tell grazzt Buahahahha...i just stabbed "+TPQCN+"! ;)");
        new( OPATH "blood.c" )->move(environment(TO));
        command( "kill "+targ->query_name() );
        TP->add_follower(TO);
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
        }
    } else {
        command( "say Submit or die scum!" );
    }
}
void set_paralyzed(int time,string message){return 1;}
void die(object ob) {
    message("environment",
	"%^BOLD%^%^BLUE%^Grimtooth's soul departs back to the Abyss!"
	"%^RESET%^"
    ,environment(TO));
    ::die();
}
