#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
#include <magic.h>
#define VALID_NUMS ({666, 66, 13, 1313, 13, 66, 1313, 13, 13, 66, 1313, 13, 66, 1313, 66, 1313, 13, 1313, 66, 66, 66, 13, 1313})
inherit OBJECT;
object myOwner;
int num;

void set_owner(object who) { if(objectp(who)) myOwner = who; }

void create() 
{
    ::create();
    set_name("chaos sphere");
    set_value(0);
    set_weight(10000);	
    set_id(({"sphere", "chaos sphere", "glowing sphere"}));
    set_property("no animate", 1);
    set_property("temporary_item", 1);
    set_short((:TO, "get_my_short":));
    set_long((:TO, "get_my_long":));
}

string get_my_short()
{
    string ret;
    ret = "%^BOLD%^%^WHITE%^a strange gl%^CYAN%^o%^WHITE%^"+
    "w%^CYAN%^i%^WHITE%^ng sph%^CYAN%^e%^WHITE%^r%^CYAN%^e ";
    ret += "%^BOLD%^%^BLACK%^( %^BOLD%^%^WHITE%^flashing "+num+"%^BOLD%^%^BLACK%^ )%^RESET%^";
    return ret; 
}

void extinguish()
{
    if(!objectp(TO)) return;
    if(objectp(ETO))
    {
        tell_room(ETO, TO->query_short()+" %^BOLD%^%^WHITE%^flashes rapidly for "+
        "a few moments before it simply fades away!%^RESET%^");
    }
    TO->remove();
    return;    
}

string get_my_long()
{
    string ret;    
    switch(num)
    {
        case 13:
            ret = "%^BOLD%^%^RED%^This strange sphere is composed of a "+
            "transl%^WHITE%^u%^RED%^c%^WHITE%^e%^RED%^nt and glowing material. "+
            "The outside layer of it is literally boiling... there are "+
            "visible bumps that appear and then fall back in on themselves after "+
            "a brief instant. There is a strange flashing %^WHITE%^"+num+
            "%^RED%^ engraved into the top of it.%^RESET%^";
            break;
        case 666:
            ret = "%^BOLD%^%^GREEN%^This strange sphere is composed of a "+
            "transl%^WHITE%^u%^GREEN%^c%^WHITE%^e%^GREEN%^nt and glowing material. "+
            "The outside layer of it is pulsating a sickly green and you can "+
            "see flashes of light coming from the inside of it. There is a strange "+
            "flashing %^WHITE%^"+num+"%^GREEN%^ engraved into the top of it.%^RESET%^";
            break;
        case 1313:
            ret = "%^BOLD%^%^WHITE%^This strange sphere is composed of a "+
            "transl%^CYAN%^u%^WHITE%^c%^CYAN%^e%^WHITE%^nt and glowing material. "+
            "It is giving off a tremendously cold vapor continually. You realize that "+
            "it is actually frozen. There is a strange flashing %^CYAN%^"+num+
            "%^WHITE%^ engraved into the top of it.%^RESET%^";
            break;
        default:
            ret = "%^BOLD%^%^CYAN%^This strange sphere is composed of a "+
            "transl%^WHITE%^u%^CYAN%^c%^WHITE%^e%^CYAN%^nt and glowing material. "+
            "It is completely smooth, except for the strange flashing %^WHITE%^"+num+
            "%^CYAN%^ engraved into the top of it. There is a very %^BOLD%^%^RED%^"+
            "power magic%^BOLD%^%^CYAN%^ radiating outward from it. It is quite "+
            "tangible and you feel that you will soon be assaulted by it.%^RESET%^";
            break;
    }
    return ret;
}

void sphere_effect()
{
    object *vics;
    int x, dam, total_dam;
    if(!objectp(TO)) return;
    if(!objectp(myOwner) || !objectp(ETO)) 
    {
        extinguish();
        return;
    }
    vics = filter_array(all_living(ETO), "is_non_immortal", FILTERS_D);
    vics -= ({myOwner});
    if(!sizeof(vics)) 
    {
        extinguish();
        return;
    }
    switch(num)
    {
        case 66:
            tell_room(ETO, "%^BOLD%^%^RED%^A wave of magical energy "+
            "erupts from the sphere and washes over everything!%^RESET%^");
            for(x = 0;x < sizeof(vics);x++)
            {
                if(!objectp(vics[x])) continue;
                if((object)vics[x]->query_property("minion") == myOwner) continue;
                dam = roll_dice(10,10);
                tell_object(vics[x], "%^BOLD%^%^RED%^The wave of magical energy "+
                "washes over you!%^RESET%^");    
                if(!interactive(vics[x])) dam *= roll_dice(4,20);                
                if(vics[x]->fort_save(25)) dam = dam/2;        
                vics[x]->cause_typed_damage(vics[x], vics[x]->return_target_limb(), dam, "sonic");
                vics[x]->add_attacker(TO);
                vics[x]->continue_attack(TO);
                if(objectp(vics[x])) { vics[x]->remove_attacker(TO); }
                continue;
            }
            if(!random(4)) 
            {
                extinguish();
                return;
            }
            call_out("sphere_effect", ROUND_LENGTH);
            return;
            break;
        case 13:
            tell_room(ETO, "%^RESET%^%^RED%^Fl%^BOLD%^%^YELLOW%^a%^RESET%^%^RED%^m"+
            "%^BOLD%^%^YELLOW%^e%^RESET%^%^RED%^s from the sphere bathe the entire "+
            "area!%^RESET%^");
            for(x = 0;x < sizeof(vics);x++)
            {
                if(!objectp(vics[x])) continue;
                if((object)vics[x]->query_property("minion") == myOwner) continue;
                dam = roll_dice(26,6);
                tell_object(vics[x], "%^BOLD%^%^RED%^You are burned by the "+
                "fire!%^RESET%^");  
                if(!interactive(vics[x])) dam *= roll_dice(4,20);
                if(vics[x]->fort_save(25)) dam = dam/2;        
                vics[x]->cause_typed_damage(vics[x], vics[x]->return_target_limb(), dam, "fire");
                vics[x]->add_attacker(TO);
                vics[x]->continue_attack(TO);
                if(objectp(vics[x])) { vics[x]->remove_attacker(TO); }
                
                continue;
            }
            if(!random(4)) 
            {
                extinguish();
                return;
            }
            call_out("sphere_effect", ROUND_LENGTH);
            return;
            break;
            //bad mmmkay
        case 666:
            tell_room(ETO, "%^BOLD%^%^GREEN%^An ac%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^d"+
            "%^RESET%^%^GREEN%^i%^BOLD%^%^GREEN%^c mist sprays from the sphere, blanketing "+
            "everything!%^RESET%^");
            total_dam = 0;
            for(x = 0;x < sizeof(vics);x++)
            {
                if(!objectp(vics[x])) continue;
                if((object)vics[x]->query_property("minion") == myOwner) continue;
                dam = roll_dice(12, 12);
                tell_object(vics[x], "%^RESET%^%^GREEN%^You are burned by the "+
                "acid!%^RESET%^");  
                if(!interactive(vics[x])) dam *= roll_dice(4,20);
                if(vics[x]->fort_save(25)) dam = dam/2;        
                total_dam += dam;
                vics[x]->cause_typed_damage(vics[x], vics[x]->return_target_limb(), dam, "acid");
                vics[x]->add_attacker(TO);
                vics[x]->continue_attack(TO);
                if(objectp(vics[x])) { vics[x]->remove_attacker(TO); }
                continue;
            }
            tell_room(ETO, "%^BOLD%^%^YELLOW%^B%^BOLD%^%^WHITE%^o%^BOLD%^%^YELLOW%^lts "+
            "of el%^WHITE%^e%^YELLOW%^ctr%^WHITE%^i%^YELLOW%^c%^WHITE%^i%^YELLOW%^ty "+
            "violently erupt from the sphere!");
            for(x = 0;x < sizeof(vics);x++)
            {
                if(!objectp(vics[x])) continue;
                if((object)vics[x]->query_property("minion") == myOwner) continue;
                dam = roll_dice(12, 12);
                tell_object(vics[x], "%^BOLD%^%^YELLOW%^You are %^BOLD%^%^BLACK%^"+
                "charred%^BOLD%^%^YELLOW%^el%^WHITE%^e%^YELLOW%^ctr%^WHITE%^i%^YELLOW%^c%^WHITE%^i%^YELLOW%^ty!%^RESET%^");  
                if(!interactive(vics[x])) dam *= roll_dice(4,20);
                if(vics[x]->fort_save(25)) dam = dam/2;        
                total_dam += dam;
                vics[x]->cause_typed_damage(vics[x], vics[x]->return_target_limb(), dam, "electricity");
                vics[x]->add_attacker(TO);
                vics[x]->continue_attack(TO);
                if(objectp(vics[x])) { vics[x]->remove_attacker(TO); }
                continue;
            }
            if(objectp(myOwner) && total_dam) 
            {
                tell_room(ETO, myOwner->query_short()+"%^BOLD%^%^WHITE%^ is replenished "+
                "by the sphere!%^RESET%^");
                myOwner->add_hp(total_dam);
            }
            if(!random(8)) 
            {
                extinguish();
                return;
            }
            call_out("sphere_effect", ROUND_LENGTH);
            return;
            break;
        case 1313:
            tell_room(ETO, "%^BOLD%^%^CYAN%^A fr%^WHITE%^ee%^CYAN%^z%^WHITE%^i%^CYAN%^ng "+
            "vapor spews forth from the sphere!%^RESET%^");
            for(x = 0;x < sizeof(vics);x++)
            {
                if(!objectp(vics[x])) continue;
                if((object)vics[x]->query_property("minion") == myOwner) continue;
                dam = roll_dice(14,12);
                tell_object(vics[x], "%^BOLD%^%^WHITE%^You are chilled by the "+
                "vapor!%^RESET%^");  
                if(!interactive(vics[x])) dam *= roll_dice(4,20);
                if(vics[x]->fort_save(25)) dam = dam/2;        
                vics[x]->cause_typed_damage(vics[x], vics[x]->return_target_limb(), dam, "cold");
                vics[x]->add_attacker(TO);
                vics[x]->continue_attack(TO);
                if(objectp(vics[x])) { vics[x]->remove_attacker(TO); }
                continue;
            }
            if(!random(4)) 
            {
                extinguish();
                return;
            }
            call_out("sphere_effect", ROUND_LENGTH);
            return;
            break;
    }
    return;
}

int get_number()
{
    if(!num) num = VALID_NUMS[random(sizeof(VALID_NUMS))];
    call_out("sphere_effect", ROUND_LENGTH);
    return num;
}

int is_invincible() { return 1; }
