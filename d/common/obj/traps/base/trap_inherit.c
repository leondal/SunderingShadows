#include <std.h>
#include "traps.h"
inherit OBJECT;

int MyBaseDc, MyBaseDie, MyBaseNum, TrapSetter, CanDeflect;
string MyDamageType, MyTrapName;
mixed OriginObject;
varargs void do_trap_damage(object who, int save_result, string type);
void create()
{
    ::create();
    MyBaseDc = 1;
    MyBaseDie = 1;
    MyBaseNum = 1;
    MyDamageType = "acid";
    MyTrapName = "acid";
    OriginObject = 0;
    CanDeflect = 0;
    TrapSetter = 0; //1 for a player set trap - which will hopefully knock unconscious
}


void set_can_deflect(int x) { CanDeflect = x; }
int query_can_deflect() { return CanDeflect; }
int query_base_die() { return MyBaseDie; }
int query_base_num() { return MyBaseNum; }
void set_trap_setter(int x)
{
    TrapSetter = x;
}
int query_trap_setter() { return TrapSetter; }

void set_my_die(int x)
{
    if(!intp(x)) return;
    MyBaseDie = x;
}

void set_my_trap_name(string str)
{
    if(!stringp(str)) return;
    MyTrapName = str;
}
string query_my_trap_name() { return MyTrapName; }

void create_trap_kit()
{
    int num;
    string TrapLevel, TL;
    switch(MyBaseDc)
    {
        case 0..15: 
            TrapLevel = "a weak";
            TL = "weak";
            num = 15;   
            break;
        case 16..25:    
            TrapLevel = "an average";
            TL = "average";
            num = 30;   
            break;
        case 26..35:
            TrapLevel = "a strong";
            TL = "strong";
            num = 50;
            break;
        case 36..51:        
            TrapLevel = "an epic";
            TL = "epic";
            num = 70;
            break;
        default:
            TrapLevel = "an epic";
            TL = "epic";
            num = 70;
            break;
    }

    TO->set_name(TL +" "+MyTrapName + " trap kit");
    TO->set_id(({"trap", "trap kit", "kit", TL+" trap kit", 
    MyTrapName + " trap kit", TL + " "+
    MyTrapName + " trap kit", "playersettabletrapkit"}));

    TO->set_short("%^BOLD%^%^WHITE%^"+capitalize(TrapLevel)+
    " %^BOLD%^%^GREEN%^"+MyTrapName+"%^BOLD%^%^WHITE%^ "+
    "trap kit%^RESET%^");
		
    TO->set_long("%^BOLD%^%^WHITE%^This small mechanical "+
    "instrument has been crafted with precise "+
    "detail.  It is etched with markings and several "+
    "buttons and pressure plates are placed methodically "+
    "over it.  This instrument is known as "+TrapLevel+ " " +
    MyTrapName + " trap kit.%^RESET%^");

    TO->set_property("lore difficulty", MyBaseDc);
	
    TO->set_lore("These mechanisms are readily assembled "+
    "trap kits.  They have various creators, and various "+
    "ways of working, though anyone with the proper knowledge "+
    "can set it to leave a nasty suprise for the person "+
    "who happens to stumble upon it later.  Some stories suggest "+
    "they were created by the thieves guild, but the knowledge "+
    "on how to recover them and use them has spread over the "+
    "years, it still takes some knowledge of dungeoneering "+
    "to get much use from one.  "+
    TO->query("lore_string")+"%^RESET%^");	

    if(!intp(MyBaseDie)) MyBaseDie = 6;
    TO->set_base_damage(num, MyBaseDie);
    return;
	
}

void set_my_dc(int x)
{
    if(x < 10) x = 10;
    if(x > 50) x = 50;
    MyBaseDc = x;
    create_trap_kit();
}

int query_dc() { return MyBaseDc; }

//basically want to let avatars have super 
//power traps - that default to a dc of 50 
//future uses are possible - just some modification
//to this function - Saide

void adjust_dc(int x)
{
    MyBaseDc = 50;
}

string query_trap_level() 
{
    string TL; 
    switch(MyBaseDc)
    {
        case 0..15:
            TL = "weak";
            break;
        case 16..25:    
            TL = "average"; 
            break;
        case 26..35:
            TL = "strong";
            break;
        case 36..51:
            TL = "epic";
            break;
        default:
            TL = "epic";
            break;
    }
    return TL;
}

void set_base_damage(int num, int die)
{
    if(!intp(die)) return;
    if(!intp(num)) return;
    if(!MyBaseDie) 
    {
        MyBaseDie = die;
    }
    MyBaseNum = num;
}

int query_damage() { return roll_dice(MyBaseNum, MyBaseDie); }

void set_damage_type(string str)
{
    if(!stringp(str)) return;
    MyDamageType = str;
}

string query_damage_type() { return MyDamageType; }

void set_origin_object(string str)
{
    if(!stringp(str)) return;
    OriginObject = str;
}

mixed query_origin_object() 
{ 
    if(!stringp(OriginObject)) 
    {
        return "out of nowhere";
    }
    return OriginObject; 
}

//assuming that traps are going to use reflex save
//for 1/2 damage - Saide
int do_trap_save(object who)
{
    if(!objectp(TO)) return 0;
    if(!objectp(who)) return 0;
    if("/daemon/saving_throw_d"->reflex_save(who, 0 - (int)TO->query_dc())) return 1;
    return 0;
}

varargs void do_trap_damage(object who, int save_result, string type)
{
    string msg, tlimb;
    int dam, df;
    if(!objectp(TO)) return;
    if(!objectp(who)) return;
    if(!intp(save_result)) return;
    set_property("magic", 1);
    if(!stringp(type)) type = "dam";
    if(TrapSetter == 1) set_property("knock unconscious", 1);
    who->add_attacker(TO);
    who->continue_attack();
    df = (int)TO->query_can_deflect();
    dam = (int)TO->query_damage();
    tlimb = (string)who->return_target_limb();
    if(save_result) dam = dam / 2;
    if(!stringp(msg = TO->query("stun_message"))) 
    {
        msg = "%^BOLD%^%^RED%^You are stunned from the trap!%^RESET%^";
    }
    switch(type)
    {
        case "dam": case "damage":
            if(!df || !"/daemon/combat_d.c"->extra_hit_calcs(TO, who, TO, tlimb)) who->do_damage(tlimb, dam);
            break;
        case "paralyze": case "stun":
            who->set_paralyzed(dam, msg);
            break;
        case "trip": case "tripped":
            dam = dam / 4;
            if(dam < 1) dam = 1;
            if(dam > 15) dam = 15;
            who->set_tripped(dam, msg);				
            break;
        default:
            if(!df || !"/daemon/combat_d.c"->extra_hit_calcs(TO, who, TO, tlimb)) who->cause_typed_damage(who, tlimb, dam, TO->query_damage_type());
            break;
    }
    if(objectp(who))
    {
        who->remove_attacker(TO);
    }
    //if(TrapSetter == 1) remove_property("knock unconscious");
    remove_property("magic");
    return;
}

int isMagic()
{
    int ThisDc;
    ::isMagic();
    if(!objectp(TO)) return 0;
    ThisDc = (int)TO->query_dc();
    switch(ThisDc) 
    {
        case 0..15:
            return 1;
        case 16..25:
            return 2;
        case 26..35:
            return 3;
        case 36..45:
            return 4;
        case 46..51:
            return 5;
        default:
            return 5;
    }
}