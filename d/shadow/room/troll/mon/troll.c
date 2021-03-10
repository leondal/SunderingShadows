#include <std.h>
inherit MONSTER;
int LEVEL,ATTACKTALK,HP;
int POWER,REGEN;
string TYPE,LONG,MYDIEA,MYDIEB,MYDIEC,TROLLGREET,
HUMANGREETA,HUMANGREETB,HUMANGREETC,EMOTEA,EMOTEB,EMOTEC;
int BURN = 0;
int BURNED = 0;
int set_em_up();


void create() {
    ::create();
    set_em_up();
}

int set_em_up() {
    set_name("troll");
    POWER = POWER + 1;
    set("id", ({ TYPE,"troll "+TYPE }));
    set("short", "Troll "+TYPE);
    set("aggressive","agg_fun");
    set_hd(12 + random(POWER/2) + (POWER/2),3);
    set("long","%^BOLD%^%^GREEN%^"+LONG+"%^RESET%^");
    LEVEL = 12 + random(POWER/2) + (POWER/2);
    set_level(LEVEL);
    set_class("fighter");
    set_guild_level("fighter",LEVEL);
    set_body_type("humanoid");
    set_alignment(9);
    set("race", "troll");
    if(random(10) < 5) {
        set_gender("male");
    } else {
        set_gender("female");
    }
    set_exp(1000 + ((LEVEL - 12)*500) - 500);
    set_ac(4 - random(POWER) - random(POWER/2)) ;
    HP = (LEVEL * 10) + random(POWER*5);
    set_max_hp(HP);
    set_hp(HP);
    set_stats("dexterity",17 + random(POWER/2) + 1);
    set_stats("wisdom",11 + random(POWER/2) + (POWER/2));
    set_stats("intelligence",11 + random(POWER/2) + (POWER/2));
    set_stats("constitution",17 + random(POWER/2) + (POWER/2));
    set_stats("strength",17 + random(POWER/2) + (POWER/2));
    set_stats("charisma",4 + random(POWER/2) + (POWER/2));
    set_funcs(({"attack_fun"}));
    set_func_chance(100);
    POWER = POWER - 1;
    set_emotes(3,({
        "%^BOLD%^%^CYAN%^"
	"Troll "
	+TYPE+
	" says: "
	"%^RESET%^"
	+EMOTEA,
        "%^BOLD%^%^CYAN%^"
	"Troll "
	+TYPE+
	" says: "
	"%^RESET%^"
	+EMOTEB,
        "%^BOLD%^%^CYAN%^"
	"Troll "
	+TYPE+
	" says: "
	"%^RESET%^"
	+EMOTEC,
	"%^BOLD%^%^GREEN%^"
	"Troll "
	+TYPE+
	" mutters gibberish."
	"%^RESET%^",
	"Troll "
	+TYPE+
	" looks around in boredom.",
	"Troll "
	+TYPE+
	" grunts at you.",
	"Troll "
	+TYPE+
	" carefully examines the mine's walls.",
	"Troll "
	+TYPE+
	" smiles a toothy grin.",
	"You feel repulsed looking upon Troll "
	+TYPE+
	".",
    }),0);
}


int attack_fun() {
  int dam,x,HIT;
  object me = this_object();
  object vic = this_object()->query_current_attacker();
  int AC = (int)vic->query_ac();
  dam = random(12)+1;
  x = random (5)+1+POWER;
  HIT = 0;
  if(x > 10) x = 10 - random(3);
  if(((random(20)-10)-2) < AC) {
    HIT = 1; 
    switch(x) {
        case 1:
	    message("vic",
		"%^BOLD%^%^GREEN%^"
		"Troll "
		+TYPE+
		" bonks you on the head!"
		"%^RESET%^"
	    ,vic);
	    message("env",
		"%^BOLD%^%^GREEN%^"
		"Troll "
		+TYPE+
		" bonks "
		+vic->query_cap_name()+
		" on the "
		"head!"
		"%^RESET%^"
	    ,environment(me),vic);
	    dam = dam + (AC/3);
	    if(dam < 5) dam = 5;
        break;

	case 2:
	    message("vic",
		"%^BOLD%^%^CYAN%^"
		"Troll "
		+TYPE+
		" claws violently at your face!"
		"%^RESET%^"
	    ,vic);
	    message("env",
		"%^BOLD%^%^CYAN%^"
		"Troll "
		+TYPE+
		" claws violently at "
		+vic->query_cap_name()+
		"'s face!"
		"%^RESET%^"
	    ,environment(me),vic);
	    dam = dam + (AC/2) + ((int)me->query_level()/3);
	    if(dam < 5) dam = 5;
        break;

	case 3:
	    message("vic",
		"%^BOLD%^%^MAGENTA%^"
		"Troll "
		+TYPE+
		" smashes his clawed fist directly into your forehead!"
		"%^RESET%^"
	    ,vic);
	    message("env",
		"%^BOLD%^%^MAGENTA%^"
		"Troll "
		+TYPE+
		" smashes his clawed fist directly into "
		+vic->query_cap_name()+
		"'s forehead!"
		"%^RESET%^"
	    ,environment(me),vic);
	    dam = dam + (AC) + ((int)me->query_level()/2);
	    if(dam < 5) dam = 5;
        break;

	case 4:
	    message("vic",
		"%^BOLD%^%^ORANGE%^"
		"Troll "
		+TYPE+
		" headbutts you, sending you reeling in pain!"
		"%^RESET%^"
	    ,vic);
	    message("env",
		"%^BOLD%^%^ORANGE%^"
		"Troll "
		+TYPE+
		" headbutts "
		+vic->query_cap_name()+
		", sending "
		+vic->query_subjective()+
		" reeling in pain!"
		"%^RESET%^"
	    ,environment(me),vic);
	    dam = dam + (AC) + ((int)me->query_level()/2) + POWER;
	    vic->set_paralyzed(5,"%^BOLD%^%^ORANGE%^You are still reeling from the blow!%^RESET%^");
	    if(dam < 5) dam = 5;
        break;

	case 5:
	    message("vic",
		"%^BOLD%^%^WHITE%^"
		"Troll "
		+TYPE+
		" lashes deep into your flesh with "
		+me->query_possessive()+
		" razor sharp claws!"
		"%^RESET%^"
	    ,vic);
	    message("env",
		"%^BOLD%^%^WHITE%^"
		"Troll "
		+TYPE+
		" lashes deep into "
		+vic->query_cap_name()+
		"'s flesh with "
		+me->query_possessive()+
		" razor sharp claws!"
		"%^RESET%^"
	    ,environment(me),vic);
	    dam = dam + (AC) + ((int)me->query_level()/2) + POWER + random(5);
            if(dam < 5) dam = 5;
        break;

	case 6:
	    message("vic",
		"%^BOLD%^%^BLUE%^"
		"Troll "
		+TYPE+
		" whirls around and kicks you hard in the chest "
		"with "
		+me->query_possessive()+
		" slimy foot!"
		"%^RESET%^"
	    ,vic);
	    message("env",
		"%^BOLD%^%^BLUE%^"
		"Troll "
		+TYPE+
		" whirls around and kicks "
		+vic->query_cap_name()+
		" hard in the chest with "
		+me->query_possessive()+
		" slimy foot!"
		"%^RESET%^"
	    ,environment(me),vic);
	    dam = dam + ((int)me->query_level()) + POWER;
	    if(dam < 5) dam = 5;
        break;

	case 7:
	    message("vic",
		"%^BOLD%^%^YELLOW%^"
		"Troll "
		+TYPE+
		" mutilates you completly with a staggering blow from "
		+me->query_possessive()+
		" bloody fist!"
		"%^RESET%^"
	    ,vic);
	    message("env",
		"%^BOLD%^%^YELLOW%^"
		"Troll "
		+TYPE+
		" mutilates "
		+vic->query_cap_name()+
		" completly with a staggering blow from "
		+me->query_possessive()+
		" bloody fist!"
		"%^RESET%^"
	    ,environment(me),vic);
	    dam = dam + ((int)me->query_level()) + random(POWER*2);
	    if(dam < 5) dam = 5;
        break;

	case 8:
	    message("vic",
		"%^BOLD%^%^YELLOW%^"
		"Troll "
		+TYPE+
		" destroys you utterly with a devastating blow from "
		+me->query_possessive()+
		" clenched fist!"
		"%^RESET%^"
	    ,vic);
	    message("env",
		"%^BOLD%^%^YELLOW%^"
		"Troll "
		+TYPE+
		" destroys "+vic->query_cap_name()+" utterly "
		" with a devastating blow from "
		+me->query_possessive()+
		" clenched fist!"
		"%^RESET%^"
	    ,environment(me),vic);
	    dam = dam + ((int)me->query_level()) + (POWER*2) + 2;
	    if(dam < 5) dam = 5;
        break;

	case 9:
	    message("vic",
		"%^BOLD%^%^RED%^"
		"Troll "
		+TYPE+
		" guts your torso wide open with "
		+me->query_possessive()+
		" lightning fast claws!"
		"%^RESET%^"
	    ,vic);
	    message("env",
		"%^BOLD%^%^RED%^"
		"Troll "
		+TYPE+
		" guts "
		+vic->query_cap_name()+
		"'s torso wide open with "
		+me->query_possessive()+
		" lightning fast claws!"
		"%^RESET%^"
	    ,environment(me),vic);
	    dam = dam + ((int)me->query_level()) + (POWER*2) + 2;
	    dam = dam + ((int)me->query_stats("strength")/3);
	    if(dam < 5) dam = 5;
        break;

        case 10:
	    message("vic",
		"%^BOLD%^%^RED%^"
		"Troll "
		+TYPE+
		" rends you utterly senseless "
		"with a multiple shredding attack to your face!"
                "%^RESET%^"
	    ,vic);
	    message("env",
		"%^BOLD%^%^RED%^"
		"Troll "
		+TYPE+
		" rends "
		+vic->query_cap_name()+
		" utterly senseless with a multiple shredding "
		"attack to "
		+vic->query_possessive()+
		" face!"
		"%^RESET%^"
	    ,environment(me),vic);
	    dam = dam + ((int)me->query_level()) + (POWER*2) + 5;
	    dam = dam + ((int)me->query_stats("strength")/2);
	    vic->set_paralyzed(8,"%^BOLD%^%^RED%^You have been rended senseless!%^RESET%^"); 
	    if(dam < 5) dam = 5;
        break;
    }    

  } else {

    switch(x) {
        case 1:
	    message("vic",
		"%^BOLD%^%^GREEN%^"
		"Troll "
		+TYPE+
		" barely misses your head!"
		"%^RESET%^"
	    ,vic);
	    message("env",
		"%^BOLD%^%^GREEN%^"
		"Troll "
		+TYPE+
		" barely misses "
	   	+vic->query_cap_name()+
		"'s head!"
		"%^RESET%^"
	    ,environment(me),vic);
	    dam = 0;
        break;

	case 2:
	    message("vic",
		"%^BOLD%^%^CYAN%^"
		"Troll "
		+TYPE+
		" claws at your face but misses!"
		"%^RESET%^"
	    ,vic);
	    message("env",
		"%^BOLD%^%^CYAN%^"
		"Troll "
		+TYPE+
		" claws at "
		+vic->query_cap_name()+
		"'s face but misses!"
		"%^RESET%^"
	    ,environment(me),vic);
	    dam = 0;
        break;

	case 3:
	    message("vic",
		"%^BOLD%^%^MAGENTA%^"
		"Troll "
		+TYPE+
		" tries to smash your forehead and fails!"
		"%^RESET%^"
	    ,vic);
	    message("env",
		"%^BOLD%^%^MAGENTA%^"
		"Troll "
		+TYPE+
		" tries to smash "
		+vic->query_cap_name()+
		"'s forehead but fails!"
		"%^RESET%^"
	    ,environment(me),vic);
	    dam = 0;
        break;

	case 4:
	    message("vic",
		"%^BOLD%^%^ORANGE%^"
		"Troll "
		+TYPE+
		" headbutts you, but no pain comes!"
		"%^RESET%^"
	    ,vic);
	    message("env",
		"%^BOLD%^%^ORANGE%^"
		"Troll "
		+TYPE+
		" headbutts "
		+vic->query_cap_name()+
		", but "
		+vic->query_cap_name()+
		" looks unaffected!"
		"%^RESET%^"
	    ,environment(me),vic);
	    dam = 0;
        break;

	case 5:
	    message("vic",
		"%^BOLD%^%^WHITE%^"
		"Troll "
		+TYPE+
		" lashes out at you and misses by inches!"
		"%^RESET%^"
	    ,vic);
	    message("env",
		"%^BOLD%^%^WHITE%^"
		"Troll "
		+TYPE+
		" lashes out at "
		+vic->query_cap_name()+
		"'s flesh and misses by inches!"
		"%^RESET%^"
	    ,environment(me),vic);
	    dam = 0;
        break;

	case 6:
	    message("vic",
		"%^BOLD%^%^BLUE%^"
		"Troll "
		+TYPE+
		" whirls around and misses a kick aimed at "
		"you with "
		+me->query_possessive()+
		" slimy foot!"
		"%^RESET%^"
	    ,vic);
	    message("env",
		"%^BOLD%^%^BLUE%^"
		"Troll "
		+TYPE+
		" whirls around and misses a kick aimed at "
		+vic->query_cap_name()+
		" with "
		+me->query_possessive()+
		" slimy foot!"
		"%^RESET%^"
	    ,environment(me),vic);
	    dam = 0;
        break;

	case 7:
	    message("vic",
		"%^BOLD%^%^YELLOW%^"
		"Troll "
		+TYPE+
		" trips badly as he tries a crafty move!"
		"%^RESET%^"
	    ,vic);
	    message("env",
		"%^BOLD%^%^YELLOW%^"
		"Troll "
		+TYPE+
		" launches a foolish attack "
		"directed towards "
		+vic->query_cap_name()+
		"!"
		"%^RESET%^"
	    ,environment(me),vic);
	    dam = 0;
        break;

	case 8:
	    message("vic",
		"%^BOLD%^%^YELLOW%^"
		"Troll "
		+TYPE+
		" runs amok around the room!"
		"%^RESET%^"
	    ,vic);
	    message("env",
		"%^BOLD%^%^YELLOW%^"
		"Troll "
		+TYPE+
		" runs amok around "
		+vic->query_cap_name()+
		" but achieves nothing!"
		"%^RESET%^"
	    ,environment(me),vic);
	    dam = 0;
        break;

	case 9:
	    message("vic",
		"%^BOLD%^%^RED%^"
		"Troll "
		+TYPE+
		" tries to gut your "
		"torso wide open "
		"with "
		+me->query_possessive()+
		" lightning fast claws but is unsuccessful!"
		"%^RESET%^"
	    ,vic);
	    message("env",
		"%^BOLD%^%^RED%^"
		"Troll "
		+TYPE+
		" tries to gut "
		+vic->query_cap_name()+
		"'s torso wide open with "
		+me->query_possessive()+
		" lightning fast claws but is unsuccessful!"
		"%^RESET%^"
	    ,environment(me),vic);
	    dam = 0;
        break;

        case 10:
	    message("vic",
		"%^BOLD%^%^RED%^"
		"Troll "
		+TYPE+
		" fails an attack of rending!"
	        "%^RESET%^"
	    ,vic);
	    message("env",
		"%^BOLD%^%^RED%^"
		"Troll "
		+TYPE+
		" fails an attack of rending!"
		"%^RESET%^"
	    ,environment(me),vic);
	    dam = 0;
        break;
    }
  }
  if(HIT == 1) {
        dam = (random(dam)/3) + (random(dam)/3) + (dam/3);
	vic->do_damage("torso",dam);
        HIT = 0;
  }
}

int is_invincible() {
  if(ATTACKTALK == 0) {  
    switch(POWER) {
	case 1:
	    message("env",
		"%^BOLD%^%^GREEN%^"
		"A look of contempt crosses Troll "
		+TYPE+
		"'s ugly face.\n"
		"%^BOLD%^%^CYAN%^"
		"Troll "
		+TYPE+
		" says: %^RESET%^"
		"Sillie murtal...wat I do make bon ban boo madden me!"
	    ,environment(this_object()));
	break;

	case 2:
	    message("env",
		"%^BOLD%^%^GREEN%^"
		"A look of bitter rage fills Troll "
		+TYPE+
		"'s slitted eyes.\n"
		"%^BOLD%^%^CYAN%^"
		"Troll "
		+TYPE+
		" says: %^RESET%^"
		"Dang gum gonna smush brainies splatter matter!"
	    ,environment(this_object()));
	break;		    

	case 3:
	    message("env",
		"%^BOLD%^%^GREEN%^"
		"A scream of fiery rage escapes Troll "
		+TYPE+
		"'s blackened lips!\n"
		"%^BOLD%^%^CYAN%^"
		"Troll "
		+TYPE+
		" says: %^RESET%^"
		"AARRGGHHH...dum bobo...me needed sleepy...now me beat dem nose!"
	    ,environment(this_object()));
	break;

	case 4:
	    message("env",
		"%^BOLD%^%^GREEN%^"
		"Troll "
		+TYPE+
		"whirls around ready for action!\n"
		"%^BOLD%^%^CYAN%^"
		"Troll "
		+TYPE+
		" says: %^RESET%^"
		"You attack me Troll! Now Troll smack you bunny ears off!"
	    ,environment(this_object()));
	break;

	case 5:
	    message("env",
		"%^BOLD%^%^GREEN%^"
		"A knowing smile crosses Troll "
		+TYPE+
		"'s as he welcomes your combatic challenge!\n"
		"%^BOLD%^%^CYAN%^"
		"Troll "
		+TYPE+
		" says: %^RESET%^"
		"My inner power and intelligence shall quickly divide and conquer your skull!"
	    ,environment(this_object()));
	break;
    }
    ATTACKTALK = 1;
  }
  return 0;
}

void die(object ob) {
    string FINALDIE;
    int DIEX;
    DIEX = random(3);
    if(DIEX == 0) FINALDIE = MYDIEA;
    if(DIEX == 1) FINALDIE = MYDIEB;
    if(DIEX == 2) FINALDIE = MYDIEC;
    message("env",
	"%^BOLD%^%^CYAN%^"
	"Troll "
	+TYPE+
	" says: "
	"%^RESET%^"
	+FINALDIE
    ,environment(this_object()));
    ::die();
}

int agg_fun() {
    string FINALMESS;
    string VICRACE;
    int MESSX;
    if(this_player()->query_invis()) return 1;
    VICRACE = (string)this_player()->query_race();
    if(VICRACE == "goblin" || VICRACE == "hobgoblin" || 
	VICRACE == "kobold" || VICRACE == "ogre" ||
	VICRACE == "orc") {
	FINALMESS = TROLLGREET;
    } else {
	MESSX = random(3);
        if(MESSX == 0) FINALMESS = HUMANGREETA;
        if(MESSX == 1) FINALMESS = HUMANGREETB;	 
        if(MESSX == 2) FINALMESS = HUMANGREETC;
    }
    message("player",
	"%^BOLD%^%^CYAN%^"
	"Troll "
	+TYPE+
	" says: "
	"%^RESET%^"
	+FINALMESS	   
    ,this_player());
    return 1;
}

void heart_beat() {
    ::heart_beat();
    if(!this_object()) return;
    if(!environment(this_object())) return;
    if(!this_object()->query_current_attacker() 
	&& this_object()->query_property("burning") > 0) 
		this_object()->remove_property("burning");
    if(((int)this_object()->query_hp() 
	< ((int)this_object()->query_max_hp() - 10)) 
	&& !this_object()->query_property("burning")) {
        if(REGEN == 3) {
            message("env",
	        "%^BOLD%^%^GREEN%^"
	        "Troll "
	        +TYPE+
	        " regenerates!"
	        "%^RESET%^"
	    ,environment(this_object()));
	    this_object()->heal(POWER + 3);
            REGEN = 0;
   	} else {
	    REGEN = REGEN + 1;
        }
    }
        if(this_object()->query_property("burning")) {
            if(BURN == 3) {
	        message("env",
	            "%^BOLD%^%^RED%^"
		    "Troll "
		    +TYPE+
		    " is burned badly from the flames covering "
		    +this_object()->query_possessive()+
		    " body!"
		    "%^RESET%^"
	        ,environment(this_object()));
		this_object()->heal(-(random(5) + 5 - POWER));
                BURN = 0;
                BURNED = BURNED + 1; 
	    } else { 
                BURN = BURN + 1;
            }
            if(random(7) < BURNED) {
		message("env",
		    "%^BOLD%^%^RED%^"
		    "The fire around Troll "
		    +TYPE+
		    "'s body extinguishes!"
		    "%^RESET%^"
		,environment(this_object()));
		this_object()->remove_property("burning");
		BURN = 0;
		BURNED = 0;
		REGEN = 0;
	    }	 
        }
    return;
}
