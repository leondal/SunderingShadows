//new elemental guardian passive creatures summoned with the elemental
//opportunist feat randomly - Saide, December 2016
#include <std.h>
inherit WEAPONLESS;

#define VALID_ELE_TYPES ({"fire", "cold", "electricity", "acid"})

object myMaster;
string EleType;
int duration;

void create() 
{   
    ::create();   
    set_gender("neuter");    
    set_race("elemental");
    set_body_type("humanoid");
    set_size(1);
    set_base_damage_type("bludgeoning");
    set_exp(1);      
}

void heart_beat()
{
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(myMaster)) return;
    if(pointerp(TO->query_attackers()))
    {
        if(member_array(myMaster, (object *)TO->query_attackers()) != -1) 
        {          
            TO->remove_attacker(myMaster);
            if(objectp(myMaster)) 
            {
                tell_room(ETO, TO->query_short()+"%^BOLD%^%^WHITE%^ ceases attacking "+myMaster->QCN+"!%^RESET%^");
                myMaster->remove_attacker(TO);
            }
        }
    }
    return;
}

/*void burst(object targ)
{
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    return;
	
}*/

void go_away()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    switch(EleType)
    {
        case "fire":
            tell_room(ETO, TO->query_short()+"%^BOLD%^%^RED%^ suddenly burns out in a "+
            "shower of harmless %^YELLOW%^e%^RED%^mb%^YELLOW%^e%^RED%^rs!%^RESET%^");
            break;
        case "cold":
            tell_room(ETO, TO->query_short()+"%^BOLD%^%^WHITE%^ suddenly melts, the liquid "+
            "instantly becoming a harmless st%^BOLD%^%^CYAN%^ea%^BOLD%^%^WHITE%^m!%^RESET%^");
            break;
        case "electricity":
            tell_room(ETO, TO->query_short()+"%^BOLD%^%^BLUE%^ suddenly explodes in an "+
            "impressive light show as the %^BOLD%^%^WHITE%^el%^WHITE%^e%^BLUE%^ctr%^WHITE%^i"+
            "%^BLUE%^c%^WHITE%^i%^BOLD%^%^BLUE%^ty contained within found its way out!%^RESET%^");
            break;
        case "acid":
            tell_room(ETO, TO->query_short()+"%^BOLD%^%^GREEN%^ suddenly evaporates into a "+
            "harmless gr%^RESET%^%^GREEN%^ee%^BOLD%^n mist!%^RESET%^");
            break;
    }
    if(objectp(TO)) TO->remove();
    return;
}

void setup_as(string myType)
{
    if(!stringp(myType)) myType = "fire";
    if(member_array(myType, VALID_ELE_TYPES) == -1) myType = "fire";
    EleType = myType;
    switch(myType)
    {
        case "fire":
            set_spells(({"fireball", "burning hands"}));
            set_name("flaming creature");
            set_id(({"creature", "flaming creature", "guardian", "elemental guardian"}));
            set_short("%^BOLD%^%^RED%^Fl%^YELLOW%^a%^RED%^m%^YELLOW%^i%^RED%^ng "+
            "Cr%^YELLOW%^ea%^RED%^t%^YELLOW%^u%^RED%^r%^YELLOW%^e%^RESET%^");

            set_long("%^BOLD%^%^RED%^Jets of fire erupt from "+
            "this small flaming creature continually. "+
            "Its body seems malleable, as if it were composed of some molten "+
            "material. There are extensions which allow it to walk and others which "+
            "seem to serve as hands, you suppose that each could be considered an "+
            "appendage. Somehow it lives but whatever is "+
            "providing life to it is completely unknown.%^RESET%^");   
            set_resistance_percent("fire", 100);
            break;
        case "cold":
            set_spells(({"cone of cold"}));
            set_name("frozen creature");
            set_id(({"creature", "freezing creature", "guardian", "elemental guardian", "frozen creature"}));
            set_short("%^BOLD%^%^WHITE%^Fr%^BOLD%^%^CYAN%^o%^BOLD%^%^WHITE%^z%^BOLD%^%^CYAN%^"+
            "e%^BOLD%^%^WHITE%^n %^BOLD%^%^WHITE%^Cr%^BOLD%^%^CYAN%^ea%^BOLD%^%^WHITE%^t"+
            "%^BOLD%^%^CYAN%^u%^BOLD%^%^WHITE%^r%^CYAN%^e%^RESET%^");
            
            set_long("%^BOLD%^%^WHITE%^A freezing cold is emanating from "+
            "this small creature continually. Its body seems quite firm, as if it were "+
            "composed from some sold material before being frozen. There are "+
            "extensions which allow it to walk and others which seem to serve "+
            "as hands. You suppose that each could be considered an appendage. "+
            "Somehow it lives but whatever is "+
            "providing life to it is completely unknown.%^RESET%^");    
            set_resistance_percent("cold", 100);
            break;
        case "electricity":
            set_spells(({"lightning bolt"}));            
            set_name("crackling creature");
            set_id(({"creature", "crackling creature", "guardian", "elemental guardian"}));
            
            set_short("%^BOLD%^%^BLUE%^Cr%^BOLD%^%^WHITE%^a%^BLUE%^ckl%^BOLD%^%^WHITE%^"+
            "i%^BLUE%^ng Cr%^BOLD%^%^WHITE%^ea%^BLUE%^t%^BOLD%^%^WHITE%^u"+
            "%^BLUE%^r%^BOLD%^%^WHITE%^e%^RESET%^");
            
            set_long("%^BOLD%^%^BLUE%^A cracking sound emanates from this "+
            "dark creature continually. You quickly realize that there are bolts of "+
            "electricity bouncing around inside of it and flashes of "+
            "almost blinding light are given off from them. Its body "+
            "seems to change as you look upon it, from a solid to an "+
            "almost gaseous form. There are "+
            "extensions which allow it to walk and others which seem to serve "+
            "as hands. You suppose that each could be considered an appendage. "+
            "Somehow it lives but whatever is "+
            "providing life to it is completely unknown.%^RESET%^");       
            set_resistance_percent("electricity", 100);
            break;
        case "acid":
            set_spells(({"acid arrow"}));
            
            set_name("acidic creature");
            set_id(({"creature", "acidic creature", "guardian", "elemental guardian"}));
            
            set_short("%^BOLD%^%^GREEN%^A%^RESET%^%^GREEN%^c%^BOLD%^i"+
            "%^RESET%^%^GREEN%^d%^BOLD%^i%^RESET%^%^GREEN%^c Cr%^BOLD%^"+
            "ea%^RESET%^%^GREEN%^t%^BOLD%^u%^RESET%^%^GREEN%^r%^BOLD%^"+
            "e%^RESET%^");
            
            set_long("%^BOLD%^%^GREEN%^Acid drips continually "+
            "from this small and bizarre creature. Its body "+
            "seems to be made of some amorphous mass that changes "+
            "almost as frequently as the acid that drips from it. There are "+
            "extensions which allow it to walk and others which seem to serve "+
            "as hands. You suppose that each could be considered an appendage. "+
            "Somehow it lives but whatever is "+
            "providing life to it is completely unknown.%^RESET%^");   
            set_resistance_percent("acid", 100);
            break;
    }   
    //set_func_chance(20);
    set_spell_chance(20);    
    call_out("go_away", duration);
    //set_funcs( ({}) );
}

void setup_guardian(object caster, string myType)
{
    int num;

    if(!objectp(caster)) { return; }
    if(!objectp(TO)) { return; }
    num = (int)caster->query_guild_level("monk");
    if(!num) { num = (int)caster->query_lowest_level(); }
    set_level(num);
    set_hd(num, 8);
    set_max_hp(roll_dice(num, 8) + (num*2));
    set_hp(query_max_hp());
    set_stats("intelligence",12);
    set_stats("wisdom",12);
    set_stats("strength",14 + (num/5));
    set_stats("charisma",8);
    set_stats("dexterity",14 + (num/5));
    set_stats("constitution",7);    
    set_attacks_num((num/10)+1);
    set_overall_ac(10-num);
    set_damage(1,(4+(num/8)));
    setup_as(myType);
    duration = (num*4) + 20;
    myMaster = caster;
    return;
}

void go_to_master()
{
    object myTarg;
    if(!objectp(TO)) return;
    if(!objectp(myMaster)) return;
    if(!objectp(myTarg = environment(myMaster))) return;
    switch(EleType)
    {
        case "fire":
            if(objectp(ETO)) tell_room(ETO, TO->query_short()+"%^BOLD%^%^RED%^ vanishes in a puff of smoke!%^RESET%^");
            TO->move(myTarg);
            tell_room(ETO, TO->query_short()+"%^BOLD%^%^RED%^ appears in a sudden puff of smoke!%^RESET%^");            
            break;
        case "cold":
            if(objectp(ETO)) tell_room(ETO, TO->query_short()+"%^BOLD%^%^WHITE%^ vanishes in a brief icy mist!%^RESET%^");
            TO->move(myTarg);
            tell_room(ETO, TO->query_short()+"%^BOLD%^WHITE%^ appears from a sudden icy mist!%^RESET%^");
            break;
        case "electricity":
            if(objectp(ETO)) tell_room(ETO, TO->query_short()+"%^BOLD%^%^BLUE%^ vanishes in a shower of sparks!%^RESET%^");
            TO->move(myTarg);
            tell_room(ETO, TO->query_short()+"%^BOLD%^%^WHITE%^ appears from a sudden shower of sparks!%^RESET%^");
            break;
        case "acid":
            if(objectp(ETO)) tell_room(ETO, TO->query_short()+"%^BOLD%^%^GREEN%^ vanishes in a green hazy fog!%^RESET%^");
            TO->move(myTarg);
            tell_room(ETO, TO->query_short()+"%^BOLD%^%^GREEN%^ appears from a sudden green hazy fog!%^RESET%^");
            break;       
    }
    if(objectp(myMaster)) 
    {
        myMaster->add_protector(TO);
        myMaster->add_follower(TO);
    }
    return;
}
