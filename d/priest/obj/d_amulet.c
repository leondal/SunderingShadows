// Pator@ShadowGate
// April 11 1996
// The Druidic Amulet

#include <std.h>
#include <druids.h>

// Needed inheritables

inherit ARMOUR;
inherit ABILITIES_DIR+"is_allowed.c";
inherit ABILITIES_DIR+"dlevel.c";
inherit ABILITIES_DIR+"is_druid.c";
inherit ABILITIES_DIR+"max_allowed_rank.c";

// Needed constant variables

#define OWNER     TP
#define NAME      TPTN
#define RANK      RANKING[dlevel(OWNER)]
#define D_MATERIAL  AMULET_MATERIAL[RANK]
#define	newbiesec 60
#define midsec	  90
#define highsec	  120
#define INTERVAL  300
#define AMULET_AC 1

// Needed global variables

int force_to_wear;
int rubbed, bonus, time;

// Needed functions

void dest_amulet();
int bonus_sight(string str);
int dest_bonus(int lapse);
int query_force_to_wear();
int query_available();
int make_available();
int make_unavailable();

create() {
        ::create();
        set_id( ({ D_MATERIAL+" amulet", "druidic amulet",
                  "druidic_amulet", "amulet" }) );
        set_short(capitalize(NAME)+
		"'s "+D_MATERIAL+" amulet of Druidic abilities");
        set_name(capitalize(NAME)+
                "'s "+D_MATERIAL+" amulet of Druidic abilities");
        set_long(capitalize(NAME)+
		"'s "+D_MATERIAL+" amulet of Druidic abilities");
        set_value(0);
        set_weight(3*RANK);
        set_ac(AMULET_AC);
        set_type("clothing");
        set_limbs( ({ "neck" }) );
        set_property("keep", NAME);
	  set_wear(
		"Your eyes start twinkling as you wear your Druidic amulet\n");
        set_remove("Nature isn't complete when you don't wear your amulet !\n");
        force_to_wear = 1;
	  make_available();
        }

init() {
     int x;
     ::init();
     if ( (!is_druidic(OWNER)) && (!is_allowed_wizard(OWNER)) )
          { return dest_amulet(); }
     set_short(capitalize(NAME)+"'s "+D_MATERIAL+" amulet of Druidic abilities");
     set_long(capitalize(NAME)+"'s "+D_MATERIAL+" amulet of Druidic abilities");
     if ( RANK <= max_unallowed_rank() ) { force_to_wear = 1; }
     else             { force_to_wear = 0; }
     if ( RANK >= 1) {
          add_action("bonus_sight","rub");
	// The High Level
     if ( RANK >= RANKING["DRUIDMASTER"] ) 
		{ x = bonus_sight("druidic amulet");
		  add_action("test","lvl"); }
     }
     if (force_to_wear && interactive(OWNER) )
          { OWNER->force_me("wear druidic_amulet on neck"); }
     }

void dest_amulet() { TO->destruct(); }	

int bonus_sight(string str) { 
int lvl, lapse;
	if (rubbed) {
		notify_fail("Your sight has been improved already !!\n");
		return 0; }
		// The level of the player
	lvl = (int)OWNER->query_level();
	if ( lvl < 5  ) lvl =  5;
	if ( lvl > 20 )	lvl = 20;
		// After dest_effect how long can't the bonus be used ??
	lapse = INTERVAL;
		// How long is the rubbing effective ??
	switch(lvl) { 
		case  5     : 	bonus = 1;
			      	time = newbiesec * lvl;		break;
		case  6..14 : 	bonus = 2;			
				time = midsec * lvl;		break;
		case 15..20 :	bonus = 3;
				time = highsec * lvl;		break;
		    }
		// Add the bonus
	if (interactive(OWNER))    { OWNER->add_sight_bonus(bonus); }
	if ( RANK <= 5) make_unavailable();
	tell_player(OWNER,
		"Your eyes start to twinkle as you rub your amulet !\n");
		// Set the time to dest_effect
	if ( RANK <= 5 ) { call_out("dest_bonus", time, lapse); }
	return 1;
}

int dest_bonus(int lapse) {
int tmp;
	remove_call_out("dest_bonus");	
	if (lapse) { tmp = lapse; }
	else { tmp = 0; }
	OWNER->add_sight_bonus(-bonus);
	tell_player(OWNER,"Your eyes become dull again !\n");
	call_out("make_available",tmp);
	return 1;
}

int test(string who) {
    object x;
    
    if (!who) { who = (string)TP->query_true_name(); }
    x = find_player(who);
     tell_object(x,"Your rank is : "+dlevel(x));
return 1;
}
int make_unavailable() { rubbed = 1; }
int make_available()   { rubbed = 0; }
	
int query_force_to_wear() { return force_to_wear; }
int query_available()	 { return rubbed;        } 

int help(string str) {
	if(!member_array(str,TP->query_id()))
		{ return 0; }
	else
		{ write("For more information type <dhelp amulet>\n\n");
		  return 1; }
}
