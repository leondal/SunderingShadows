/***********************************
The evals for the waystation magic of Lujke's

* // eval return "/daemon/destinations_d.c"->query_waystations("/d/shadow/room/city/jail_main")
* // eval return "/daemon/destinations_d.c"->clear_waystations("/d/shadow/room/city/jail_main")
* // eval return "/daemon/destinations_d.c"->generate_waystations("/d/shadow/room/city/jail_main", 5, 3)

* eval return "/daemon/destinations_d.c"->generate_waystations("/d/shadow/room/city/jail_main", 5, 4)
Result = 0

/d/darkwood/camps/obj  eval return "/daemon/destinations_d.c"->query_waystations("/d/shadow/room/city/jail_main")
Result = ([ "/d/shadow/room/city/eroad3" : 6, "/d/shadow/room/city/eroad6"
: 5, "/d/shadow/room/city/eroad10" : 4, "/d/guilds/consortium/hall/main" :
3, "/d/shadow/room/city/eroad14" : 3, "/d/shadow/room/city/eroad18" : 2,
"/d/darkwood/room/road1" : 2, "/d/shadow/room/city/gs_store" : 5,
"/d/shadow/room/city/cguild/cleric/cleric1" : 4,
"/d/shadow/room/city/cguild/paladin/fountain" : 4,
"/d/shadow/room/city/cguild/mage/floor3" : 4,
"/d/shadow/room/city/cguild/mage/gate" : 3, "/d/shadow/room/city/barroad2"
: 5, "/d/shadow/room/city/smroad" : 2, "/d/shadow/room/city/whome" : 4,
"/d/player_stores/poffices/shadow_br" : 3, "/d/shadow/room/city/moffice" :
6, "/d/shadow/room/city/eseltower" : 4, "/d/shadow/room/city/jail_main" :
1, "/d/darkwood/yntala/rooms/forestpath" : 6, "/d/darkwood/room/road17" :
3, "/d/shadow/room/main/garrison4" : 6, "/d/tharis/conforest/rooms/path8" :
6, "/d/tharis/conforest/rooms/path4" : 5, "/d/shadow/room/city/netower" :
6, "/d/shadow/room/city/stable" : 6, "/d/shadow/room/city/entower" : 5,
"/d/darkwood/room/backroom" : 5, "/d/shadow/room/city/troopb5" : 6,
"/d/shadow/room/city/druids/park1_2" : 3, "/d/shadow/room/city/troopb2" :
3, "/d/shadow/room/city/arch2" : 3, "/d/darkwood/room/road5" : 4,
"/d/shadow/room/city/lsswtower" : 3, "/d/shadow/room/city/innroad2" : 6,
"/d/darkwood/room/road21" : 5, "/d/shadow/room/city/lssetower" : 3,
"/d/shadow/room/city/wtower" : 5, "/d/shadow/room/city/arch6" : 4,
"/d/shadow/room/city/wroad3" : 6, "/d/shadow/room/city/wroad6" : 5,
"/d/shadow/room/city/wroad18" : 2, "/d/shadow/room/city/wroad14" : 3,
"/d/shadow/room/city/wroad10" : 4 ])
*************************************************/

// monster_party(int) set in CROOM

#include <std.h>
#include "/d/common/common.h"

#define CITYLAW "shadow law"

inherit "/std/guardsman.c";

int horn,flag,count=0; // used to keep the horn from spamming

void set_guard_stuff();
void hairColor();
void eyeColor();
void doHeight();
void doWeight();
void blow_horn(object watchman);

void create() {
    string rank;
    ::create();
    will_open_doors(1);
    set_nogo(({"/d/shadow/room/pass/pass3", "/d/shadow/room/village/mainroad3",
"/d/darkwood/room/road3", "/d/shadow/virtual/desert/25,1.desert"}));
    set_name("Shadow Guard");
    set_id(({"Shadow Guard","shadow guard","human","guard", CITYLAW}));
    set_short("A tall human");
    set_gender(random(2)?"male":"female");
    hairColor();
    eyeColor();
    set_race("human");
    set_hd(15+roll_dice(3,4),1);
    set_hp(roll_dice(query_hd(),15));
    set_class("fighter");
	add_search_path("/cmds/fighter");
	set_fighter_style("soldier");
    set_property("full attacks",1);
    set_property("magic resistance",random(30)+10);
    rank = set_ranks(([
        18 : "rookie",
        20 : "sergeant",
        24 : "lieutenant",
        28 : "captain",
        30 : "Commander",
    ]));
	add_attack_bonus(7);
	add_damage_bonus(7);
	set_monster_feats(({
	    "parry",
		"powerattack",
		"shatter",
		"sunder",
		"rush",
		"damage resistance",
		"improved damage resistance",
		"improved toughness",
		"regeneration",
		"toughness",
		"expertise",
		"knockdown"
    }));
	set_funcs(({
	    "rushit",
		"flashit",
		"shatterit",
		"sunderit",
		"rushit",
		"kdit",
		"kdit"
	}));
	set_func_chance(35);
    add_id(rank);
    add_id(capitalize(rank));
    set_short("%^RESET%^%^BLUE%^A "+query("hair")+" haired, "+query("eye")+" eyed"
	" "+query_gender()+" human in a %^CYAN%^Shadow watch uniform");
    set_ac(5 - roll_dice(3,6));
    set_detecting_invis(random(2));
    set_exp(1);
    set_long("This "+query_gender()+" guard wears the standard uniform of "
	"the Shadow watch, with an insignia indicating a rank of "+rank+".  "
        "Vigilant in "+QP+" duties, "+QS+" patrols the streets "
        "of Shadow to enforce the law and protect citizens and officials.  "
	"The Shadow watch is made up of both citizens and hired mercenaries.  "
	"The citizens may lack the battle experience of the mercenaries "
	"but they are determined to defend their city and uphold the laws."
    );
    if(rank == "Commander" || rank == "captain") {
	RANDGEAR->armor_me(TO, "armorpl", 20, 1, 75);
        } else {
	RANDGEAR->armor_me(TO, "armornp", 20, 2, 75);
    }
    new("/d/common/obj/armour/coif")->move(TO);
        command("wear coif");
    switch(random(4)) {
	case 0:
            RANDGEAR->arm_me(TO, "edgedm", 30, 2, 75);
            RANDGEAR->arm_me(TO, "edgeds", 30, 2, 75);
	    break;
	case 1:
            RANDGEAR->arm_me(TO, "edgedl", 30, 2, 75);
	    break;
	case 2:
            RANDGEAR->arm_me(TO, "bluntm", 30, 2, 75);
            RANDGEAR->arm_me(TO, "blunts", 30, 2, 75);
	    break;
	case 3:
            RANDGEAR->armor_me(TO, "shield", 30, 1, 75);
            RANDGEAR->arm_me(TO, "tool", 30, 2, 75);
	    break;
    }
    set_guard_stuff();
}

void set_guard_stuff() {
    set_jail_location("/d/shadow/city/room/jail_main");
    set_guarding("Shadow");
    set_bad_races(({ "drow", "half-drow", "goblin", "hobgoblin", "kobold", "ogre", "orc", "gnoll", "bugbear", "minotaur", "fey'ri", "dragon", "ratkin", "wererat","troll" }));
    set_race_action("capture");
    set_race_messages(([
                           "drow"      : "Arg, its a drow, sound the horn, stop it before it starts killing children.",
                           "half-drow" : "Stop the bastard half-drow, any drow blood is bad.",
                           "goblin"    : "Stop that miserable little goblin, and look around for more.",
                           "hobgoblin" : "Careful folks, it's a hobgoblin, I'll take care of it.",
                           "kobold"    : "Dog faced rat!  Get that kobold!!",
                           "ogre"      : "Gods help us, its an ogre, how did it get past the gate?",
                           "ratkin"    : "Sound the alarms! Underworld invasion! May the gods help us!",
                           "gnoll"     : "It's a gnoll fellas, get it!",
                           "bugbear"   : "A bugbear - it's gonna be mean but let's get it.",
                           "orc"       : "Don't let the orc escape!  You know it's spying for an invasion.",
                           ]));
    ARREST_MSG        = "%^BOLD%^%^CYAN%^Stop in the name of the law!";
    CAPTURE_MSG       = "%^BOLD%^You are under arrest you criminal!";
    RACE_CAPTURE_MSG  = "%^BOLD%^You'll be put on display for entering the city!";
    EXPEL_MSG         = "%^BOLD%^Off with you scum, don't set foot in Shadow again!";
    KILL_MSG          = "%^BOLD%^For the crime of invading the city, you die now!";
    JAIL_MSG          = "%^BOLD%^Off to jail you go for your crimes!";
    return;
}

// had to override to capture unshifted fey'ri & shifted dragons; race list won't work on these. N, 1/14.
int is_bad_race(object live){
    object myshape;
    if(!objectp(live)) { return 0; }
    if(live->query_true_invis()) { return 0; }
    if(live->query_invis() && !detecting_invis()) { return 0; }
    if(live->query_unconscious()) { return 0; }
    if(live->id("wild_world_monster")) { return 1; }
    if(query_bad_race(live)) { return 1; }
    if((string)live->query_race() == "elf") { // un-altered fey'ri in natural demonic form
      if((string)live->query("subrace") == "fey'ri" && !live->query_property("altered")) return 1;
    }
    if(objectp(myshape = live->query_property("shapeshifted"))) {
      if((string)myshape->query_shape_race() == "dragon") return 1;
    }
    else return 0;
}

void do_special_combat_actions() {
   blow_horn(TO);
}

void hairColor() {
  switch (random(6)) {
    case 0:        set("hair","blonde");        break;
    case 1:        set("hair","red");           break;
    case 2:        set("hair","sandy");        break;
    case 3:        set("hair","black");         break;
    case 4:        set("hair","gray");          break;
    case 5:        set("hair","brown");         break;
  }
}

void eyeColor() {
  switch (random(5)) {
    case 0:        set("eye","blue");         break;
    case 1:        set("eye","gray");         break;
    case 2:        set("eye","green");        break;
    case 3:        set("eye","brown");        break;
    case 4:        set("eye","azure");        break;
  }
}

void doHeight() {
    int feet, halves;
    int height = 63+random(20);
    feet = height/12;
    halves = "";
    if (height%12) {
        halves = (height%12<4)?"":((height%12<9)?" and a half":"");
        if (height%12>8) {
            height++;
        }
    }
    set("height",""+feet+halves);
}

void doWeight() { set("weight",(140+random(140))); }

int isMagic() { return ::isMagic() + detecting_invis(); }

void blow_horn(object ob) {
    if(!objectp(ob)) { return; }
    if(horn) { return; }
    broadcast_area("/d/shadow/room/city", "%^BOLD%^%^YELLOW%^The warning horn blows alerting the city guards.");
    tell_room("/realms/styx/workroom","The Shadow horn is blowing.");
    horn = 1;
}

void heart_beat() {
	int i;
    ::heart_beat();
    if(!objectp(TO)) { return; }
	if(TO->query_unconscious()) { return; }
    if(sizeof(query_attackers()))
	{
		count++;
		if(count == 3)
		{
			TO->force_me("flash");
			count = 0;
		}
		if(!flag)
		{
			flag = 1;
			TO->force_me("rush attacker");
			for(i=2;i<25;i++)
			{
				TO->force_me("rush attacker "+i+"");
			}
		}
	}
	else
	{
		horn = 0;
		flag = 0;
		count = 0;
	}
	return;
}

// need this for the witnessed command in the MAH *Styx* 3/27/06
int isWatch() {
    return 1;
}

void kdit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("knockdown "+targ->query_name());
}

void flashit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("flash "+targ->query_name());
}

void rushit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("rush "+targ->query_name());
}

void sunderit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("sunder "+targ->query_name());
}

void shatterit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("shatter "+targ->query_name());
}
