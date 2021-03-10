/*Part of combat code is duplicated in this file. A similar duplication was causing problems in weaponless_monsters, 
and I removed it there. If/when this file becomes active, please explore the duplications and see if they should be removed. ~Circe~ 2/12/13*/

//For hand to hand monsters

#include "std.h"
#include "daemons.h"
#include "security.h"

//inherit "/std/spellcaster";
inherit "/adm/failsafe/spellcaster_failsafe.c";


static mapping static_weaponless = ([]);


void set_damage(int num, int dice);
void set_attacks_num(int number);
void set_nat_weapon_type(string type);
void set_attack_limbs(string *limbs);
string *query_attack_limbs();
void set_hit_funcs(mapping stuff);
private int get_hand_damage(string limb, int damage, object attacked);


void create()
{
    static_weaponless = ([]);

    static_weaponless["attack_funcs"] = ([]);
    static_weaponless["num_dice"] = 1;
    static_weaponless["type"] = 4;
    static_weaponless["num_hand"] = 0;
    static_weaponless["weapon_type"] = "bludgeon";
    static_weaponless["attack_limbs"] = ({ "right hand", "left hand" });

    ::create();
}



// not used for shapeshifting, maybe old code somewhere? -Ares
void toggle_polymorphed()
{
   static_weaponless["polymorphed"]?static_weaponless["polymorphed"] = 0:static_weaponless["polymorphed"]=1;
}

int query_polymorphed() { return static_weaponless["polymorphed"];}




int is_weaponless()
{
   if(sizeof(TO->query_wielded()) > 0) return 0;
   return 1;
}


void set_hit_funcs(mapping stuff)
{
    static_weaponless["attack_funcs"] = ([]);
    static_weaponless["attack_funcs"] = stuff;
}


void set_damage(int num, int dice)
{
    static_weaponless["num_dice"] = num;
    static_weaponless["type"] = dice;
}


void set_attacks_num(int number)
{
    static_weaponless["num_hand"] = number;
}


int query_attacks_num()
{
   return static_weaponless["num_hand"];
}


void set_nat_weapon_type(string type)
{
    static_weaponless["weapon_type"] = type;
}


string query_nat_weapon_type() 
{
    return static_weaponless["weapon_type"];
}


void set_attack_limbs(string *limbs)
{
    static_weaponless["attack_limbs"] = limbs;
    //static_weaponless["polymorphed"] = 1;
}


string *query_attack_limbs()
{ 
    return static_weaponless["attack_limbs"];
}


int query_num_natural_attacks()
{
   return sizeof(static_weaponless["attack_limbs"]);
}


string return_attack_limb()
{
    string *limbs;
    limbs = static_weaponless["attack_limbs"];

    return limbs[random(sizeof(limbs))];
}


int query_unarmed_damage()
{
    return roll_dice(static_weaponless["num_dice"],static_weaponless["type"]);
}


int get_hand_damage(string limb1, int damage, object attacked) 
{
    string *attack_limbs = ({});
    mapping attack_funcs = ([]);

    attack_limbs = static_weaponless["attack_limbs"];
    attack_funcs = static_weaponless["attack_funcs"];


    if(!stringp(limb1) || (limb1 == "") || (limb1 == " ") || !sizeof(attack_limbs) || member_array(limb1,attack_limbs) == -1)
    {
        if(!sizeof(attack_limbs)) { return (damage + query_unarmed_damage()); }
        limb1 = attack_limbs[random(sizeof(attack_limbs))];
    }

	if(!attack_funcs || attack_funcs == ([])) 
    {
        return (damage + query_unarmed_damage());
    }
	
    if(!attack_funcs[limb1])
    {
        return (damage + query_unarmed_damage());
    }
	
    if(stringp(attack_funcs[limb1]))
    {
		tell_room(ETO, attack_funcs[limb1], TO);
		return (damage + query_unarmed_damage());
	}
    
    if(functionp(attack_funcs[limb1]) && TO->query_property("shapeshifted"))
    {
        damage += query_unarmed_damage();
        seteuid(UID_SYSTEM);
        damage += call_other((object)TO->query_property("shapeshifted"), (function)attack_funcs[limb1][1], TO, attacked );
		return damage;
	}
	
	if(functionp(attack_funcs[limb1]))
    {
		damage += call_other(TO, (function)attack_funcs[limb1][1], attacked);
		return damage;
	}
    	
	return (damage + query_unarmed_damage());
}