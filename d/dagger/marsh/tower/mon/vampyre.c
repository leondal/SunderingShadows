#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit WEAPONLESS;
int CYCLE,xx;
void create() {
    :: create();
    set_name("vampyre");
    set_id(({
        "vampyre","my_vampyre","slatulzzk"
    }));
    set_living_name("my_vampyre");
    set_short("%^RESET%^%^RED%^Slatulzzk, Greater vampyre%^RESET%^");
    set_long(
        "This is one of the rare vampyric beings of the Shadowgate realms "
	"to which immense horror is attributed. Many eons ago wizards "
	"of great power unlocked secrets which mortals were not to "
	"know and see. Out of this disturbance of great evil, three "
	"such vile beings were formed from the possessed soul of the "
	"Magicon Brothers, a trio of "
	"unsurpassed magical prowess. The first two of the ungodly "
	"and undead forms were hunted "
	"down after years of the lands being ravished by them in "
	"the unending hunger which possesses these beings. "
	"The third, however, mysteriously vanished and it was "
	"attributed to Vecna, Arch-Mage of Dyrivon for destroying it. "
	"Mysteriously, Vecna also disappeared within a few years of his "
	"claim of defeating the last of the trio and many feared "
	"that soon Vecna would emerge in the same form as the "
	"Vampyres. Much talk and preparation "
	"was made for this event, however, it never came to pass "
	"and the rulers of the times felt it better "
	"to not know the answer this time..."
    );
    set_gender("male");
    set_level(30);
    set_hd(30,9);
    set_size(3);
    set_weight(100);
    set_attacks_num(2);
    set_damage(8,8);
    set_base_damage_type("slashing");
    set_attack_limbs(({"right hand","left hand"}));
    set_overall_ac(-15);
    set_property("no bump",1);
    set("aggressive",50);
    set_body_type("humanoid");
    set_race("undead");
    set_property("undead",1);
    set_class("fighter");
    set_guild_level("fighter",30);
    set_stats("strength",30);
    set_stats("constitution",30);
    set_stats("dexterity",30);
    set_stats("wisdom",30);
    set_stats("intelligence",27);
    set_stats("charisma",-20);
    set_alignment(9);
    set_mob_magic_resistance("average");
    set_exp(28000);
    set_max_level(36);
    set_max_hp(500);
    set_hp(500);
    add_money("gold",random(5000)+1000);
    new( OPATH "ring.c" )->move(TO);
    CYCLE = 0;
   new("/d/shadow/obj/clothing/silkgloves")->move(TO);
    command("wear gloves");
    set_emotes(1,({
        "%^BLUE%^Vampyre grins to you evilly!%^RESET%^",
	"%^RED%^Vampyre shifts from view briefly!",
	"The Vampyre casts a spell of healing!",
        "%^MAGENTA%^Vampyre says: %^RESET%^Vecna will have a use for your soul!",
    }),1);
    set_funcs(({"special"}));
    set_func_chance(60);
    set_resistance("negative energy",15);
    set_resistance("positive energy",-15);
}
int special() {
    object ob = this_object();
    object targ = ob->query_current_attacker();
    string PLACE;
    object here;
    object PLACE1 = RPATH "a10";
    object PLACE2 = RPATH "b3";
    object PLACE3 = RPATH "a12";
    object PLACE4 = RPATH "b5";
    object PLACE5 = RPATH "b2";
    object *inv;
    int i,max;
    xx=random(3)+1;
    switch(xx) {
    case 1:
    say("%^BOLD%^%^GREEN%^"
	"The Vampyre's body turns into gas!%^RESET%^"
    );
    if(CYCLE == 0) {
        say(
	    "%^MAGENTA%^Vampyre says:%^RESET%^ Foolish mortal! Leave me to feed or die!\n"
	    "%^YELLOW%^The swirling gaseous form drifts to the southwest!"
        );
        find_object_or_load( RPATH "a10" );
        TO->move_player( RPATH "a10","southwest");
        for(i=0;i<10;i++) {
      	    new( MPATH "bat.c" )->move(PLACE1);
        }
    }
    if(CYCLE == 1) {
        say(
	    "%^MAGENTA%^Vampyre says:%^RESET%^ You are either vastly stupid or have a deathwish!\n"
	    "%^YELLOW%^The swirling gaseous form drifts through the ceiling!"
        );
        find_object_or_load( RPATH "b3" );
        here = environment(TO);
        TO->move_player( RPATH "b3","through the ceiling");
        message("info",
            "%^BOLD%^%^RED%^Suddenly, burning hot oil comes rushing through "
	    "the hole in the ceiling!%^RESET%^"
        ,PLACE1);
        inv = all_inventory(here);
	max = sizeof(inv);
        for(i=0;i<max;i++) {
            if(!living(inv[i])) continue;
            inv[i]->set_paralyzed(5+random(6),
		"You are paralyzed from pain."
	    );
            tell_room(environment(inv[i]),
		"%^BOLD%^%^RED%^"
		+inv[i]->query_cap_name()+" is badly burned by the flaming oil!"
            ,inv[i]);
            tell_object(inv[i],
		"%^RESET%^%^RED%^You scream in pain as the oil burns your skin!%^RESET%^"
	    );
            inv[i]->do_damage("torso", random(40/2) + 6);
        }
    }
    if(CYCLE == 2) {
        say(
	    "%^MAGENTA%^Vampyre says:%^RESET%^ Vecna fought me like this as well, but in vain. You cannot "
	    "defeat me...only join me as Vecna's servant in undeath!\n"
	    "%^YELLOW%^The swirling gaseous form drifts through the north wall!"
        );
        say(
	    "%^BOLD%^%^BLUE%^The Vampyre summons a krykoth as he drifts away!%^RESET%^"
        );
        new( MPATH "krykoth.c" )->move(PLACE2);
        find_object_or_load( RPATH "stair1" );
        TO->move_player( RPATH "stair1","through the north wall");
    }
    if(CYCLE == 3) {
	say(
	    "%^MAGENTA%^Vampyre says:%^RESET%^ BAH! I tire of this boring game! Next time we meet I will own your soul!\n"
	    "%^YELLOW%^The swirling gaseous form drifts to the south!"
        );
        new( "/d/dagger/drow/temple/obj/jewel.c" )->move(TO);
        force_me("press facet");
        force_me("drop jewel");
        find_object_or_load( RPATH "a12" );
        TO->move_player( RPATH "a12","south");
    }
    if(CYCLE == 4) {
	  say(
	    "%^MAGENTA%^Vampyre says:%^RESET%^ You are either vastly stupid or have a deathwish!\n"
	    "%^YELLOW%^The swirling gaseous form drifts through the ceiling!"
        );
        find_object_or_load( RPATH "b5" );
        here = environment(TO);
        TO->move_player( RPATH "b5","through the ceiling");
        message("info",
            "%^BOLD%^%^RED%^Suddenly, burning hot oil comes rushing through "
	    "the hole in the ceiling!%^RESET%^"
        ,PLACE3);
        inv = all_inventory(here);
        max = sizeof(inv);
        for(i=0;i<max;i++) {
            if(!living(inv[i])) continue;
            inv[i]->set_paralyzed(5+random(6),
		"You are paralyzed from pain."
	    );
            tell_room(environment(inv[i]),
		"%^BOLD%^%^RED%^"
		+inv[i]->query_cap_name()+" is badly burned by the flaming oil!"
            ,inv[i]);
            tell_object(inv[i],
		"%^RESET%^%^RED%^You scream in pain as the oil burns your skin!%^RESET%^"
	    );
            inv[i]->do_damage("torso", random(40/2) + 6);
        }
    }
    if(CYCLE == 5) {
        say(
	    "%^MAGENTA%^Vampyre says:%^RESET%^ I have told Vecna of your arrival...he is awake "
	    "and awaits you. Save your energy. You will need it more against him than me!\n"
	    "%^YELLOW%^The swirling gaseous form drifts through the north wall!"
        );
        say(
	    "%^BOLD%^%^BLUE%^The Vampyre summons a krykoth as he drifts away!%^RESET%^"
        );
        new( MPATH "krykoth.c" )->move(PLACE4);
        find_object_or_load( RPATH "b2" );
        TO->move_player( RPATH "b2","through the north wall");
        for(i=0;i<10;i++) {
      	   new( MPATH "bat.c" )->move(PLACE5);
        }
    }
    if(CYCLE == 6) {
        say(
	   "%^MAGENTA%^Vampyre says:%^RESET%^ I obviously have let you live too long. We won't make that mistake this time around. Let us "
	   "begin the game again! Shall we then...?\n"
	   "%^YELLOW%^The swirling gaseous form drifts through the floor!"
        );
	TO->add_hp(200);
        TO->move_player( RPATH "a13","through the floor");
    }
    CYCLE = CYCLE + 1;
    if(CYCLE > 6) CYCLE = 0;
    return 1;
    case 2:
        say("%^BOLD%^%^GREEN%^"
	    "The Vampyre casts a spell of summoning!%^RESET%^"
        );
        if(!present("bat",environment(TO))) {
           for(i=0;i<8;i++) {
	       say("A bat appears beside Vampyre!");
      	       new( MPATH "bat.c" )->move(ETO);
           }
	} else {
 	       say("A bat appears beside Vampyre!");
      	       new( MPATH "bat.c" )->move(ETO);
	}
    return 1;
    case 3:
    tell_object(targ,
        "%^BOLD%^%^RED%^The Vampyre sinks it's bloody fangs into your neck!"
	"%^RESET%^"
    );
    tell_room(environment(targ),
        "%^BOLD%^%^RED%^The Vampyre sinks it's bloody fangs into "
        +targ->query_cap_name()+"'s neck!%^RESET%^"
    ,targ);
    targ->do_damage("head",roll_dice(8,8));
    targ->set_paralyzed(28,"%^RED%^You are paralyzed from the venom!");
    return 1;
    }
}
void set_paralyzed(int time,string message){return 1;}
void heart_beat() {
   int i,max;
    object here,*inv;
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    here = ETO;
    for(i=0, max = sizeof(inv=all_inventory(here)); i<max; i++) {
	if(living(inv[i]) && !userp(inv[i]) && (string)inv[i]->query_race() == "snake") {
	    tell_room(ETO,
	        "%^GREEN%^"+inv[i]->query_cap_name()+" runs in fear!%^RESET%^"
	    );
	    inv[i]->remove();
        }
    }
    if(TO->query_hp() < 150) {
        tell_room(environment(TO),
	    "%^GREEN%^Vampyre regenerates!%^RESET%^"
	);
	TO->add_hp(random(3));
	return;
    } else {
       return;
    }
}
void die(object ob) {
    force_me("yell Even with death I shall continue to arise for vengeance!");
    message("environment",
	"%^BOLD%^%^BLUE%^The Vampyre breaths as it dies: %^RESET%^"
	"It was I who showed Vecna the darkest way, despite the knowledge "
	"that his inner self would rise above me in undeath to be my master. You too "
	"will know undeath. We have waited long for you to join us.\n%^RED%^The "
	"Vampyre crumples to the ground and lies still.%^RESET%^"
    ,environment(TO));
    :: die(ob);
}

int is_vampire()
{
    return 1;
}
