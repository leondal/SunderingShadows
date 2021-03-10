#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
inherit WEAPONLESS;

void create() 
{
    object ob;
    ::create();
    set_name("spectral spider");
    set_id(({"spider", "spectral spider", "glowing spider"}));

    set_short("%^BOLD%^%^WHITE%^Sp%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^"+
    "ctr%^BOLD%^%^CYAN%^a%^BOLD%^%^WHITE%^l Sp%^BOLD%^%^CYAN%^i%^BOLD%^"+
    "%^WHITE%^d%^BOLD%^%^CYAN%^e%^BOLD%^%^WHITE%^r%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This monstrous arachnid is almost "+
    "twelve feet in diamater. It has a massive abdomen with "+
    "what looks like a diamond shaped symbol in a dull "+
    "%^BOLD%^%^BLACK%^black%^BOLD%^%^WHITE%^ color. Most of its "+
    "body is a burnt %^RESET%^%^ORANGE%^orange%^BOLD%^%^WHITE%^ "+
    "that has been outlined by a strange haze. There are many wounds "+
    "visible on its body, leaking much of its insides onto the floor "+
    "beneath its eight legs. Most of its appendages, including its "+
    "head look as if they have half rotted away, with sections of "+
    "cuticle missing from its exoskeleton. The eys of this "+
    "creature are a %^BOLD%^%^RED%^deep red%^BOLD%^%^WHITE%^ "+
    "and they, unfortunately, portray a measure of intelligence."+
    "%^RESET%^");

    set_gender("female");
    set_race("arachnid");
    set_property("undead", 1);
    set_body_type("arachnid");
    set_alignment(9);
    set_size(3);
    set_hd(32,5);
    set("aggressive", 30);
    
    set_stats("strength",17);
    set_stats("intelligence",9);
    set_stats("wisdom",9);
    set_stats("dexterity",17);
    set_stats("charisma",8);
    set_stats("constitution",12);
    
    set_hp(470 + random(115));
    set_max_hp(query_hp());
    set_new_exp(28, "normal");
    set_attacks_num(3);
    set_base_damage_type("piercing");
    set_base_damage_type("piercing");
    set_damage(3, 6);
    set_property("natural poisoner", 1);
    set_property("natural poison", "shadow essence");
    set_property("poison chance", 8);
    set_funcs(({"soul_theft", "spin", "soul_theft", "spin"}));
    set_func_chance(35); 
    set_property("death effects", "splash");
    set_overall_ac(-12);
}

void soul_theft(object targ)
{
    string me;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    if(!objectp(ETO)) return;
    me = TO->query_short();

    tell_room(ETO, me+ "%^BOLD%^%^RED%^ rears back, raising ts "+
    "front legs off the ground, and begins chanting in a primitive "+
    "drow tongue:%^BOLD%^%^CYAN%^ 'Belbau uns'aa quortek dosst'%^RESET%^");

    tell_object(targ, "%^BOLD%^%^BLACK%^You feel something %^BOLD%^%^RED%^"+
    "TUGGING%^BOLD%^%^RED%^ at your very soul!%^RESET%^");

    if(targ->will_save(26)) 
    {
        tell_object(targ, "%^BOLD%^%^WHITE%^You are able to resist the tugging and "+
        me+"%^BOLD%^%^WHITE%^ becomes enraged!%^RESET%^");
		
        tell_room(ETO, targ->QCN+"%^BOLD%^%^WHITE%^ looks quite disturbed as "+me+
        "%^BOLD%^%^WHITE%^ becomes enraged!%^RESET%^", targ);
		
        set_property("damage bonus", 2);
        return;
    }   
    tell_object(targ, "%^BOLD%^%^RED%^An immense, immeasurable pain floors you "+   
    "as you feel a portion of your very %^BOLD%^%^YELLOW%^S%^BOLD%^%^GREEN%^O"+ 
    "%^BOLD%^%^YELLOW%^U%^BOLD%^%^GREEN%^L%^BOLD%^%^RED%^ ripped away!%^RESET%^");

    targ->set_tripped(2, "%^BOLD%^%^RED%^You struggle to regain your composure!%^RESET%^");

    tell_room(ETO, targ->QCN+"%^BOLD%^%^RED%^ suddenly falls to the floor, screaming "+
    "in pain!%^RESET%^", targ);

    targ->cause_typed_damage(targ, 0, roll_dice(10,12), "mental");
	
    return;
}

void spin(object targ)
{
    object web, webroom;
    string me;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    if(!objectp(ETO)) return;
    me = TO->query_short();

    tell_object(targ, me+"%^BOLD%^%^GREEN%^ launches a monstrous "+
    "mass of %^BOLD%^%^CYAN%^glowing%^BOLD%^%^GREEN%^ web at you!%^RESET%^");
	
    tell_room(ETO, me+"%^BOLD%^%^GREEN%^ launches a monstrous mass "+
    "of %^BOLD%^%^CYAN%^glowing %^BOLD%^%^GREEN%^ web at "+
    targ->QCN+"%^BOLD%^%^GREEN%^!%^RESET%^", targ);

    if(targ->reflex_save(26)) 
    {
        tell_object(targ, "%^BOLD%^%^GREEN%^You evade the mass of web "+
        "just in time and it quickly melts away into nothing!%^RESET%^");
	
        tell_room(ETO, targ->QCN+"%^BOLD%^%^GREEN%^ evades the mass of "+
        "web just in time and it quickly melts away into nothing!%^RESET%^", targ);
        return;
    }
    tell_object(targ, "%^BOLD%^%^GREEN%^The %^BOLD%^%^CYAN%^glowing %^BOLD%^%^GREEN%^"+
    "web envelopes you, trapping you within its sticky mass!%^RESET%^");

    tell_room(ETO, targ->QCN+"%^BOLD%^%^GREEN%^ is enveloped by the "+
    "%^BOLD%^%^CYAN%^glowing%^BOLD%^%^GREEN%^ web, trapped within "+
    "its sticky mass!%^RESET%^", targ);

    webroom = new(HHOB+"web_room");
    web = new(HHOB+"spider_web");
    web->set_web_room(webroom);
    webroom->set_web(web);
    webroom->set_origin(ETO);
    targ->move(webroom);
    web->move(ETO);
    return;
}
