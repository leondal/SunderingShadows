#include <std.h>
#include <daemons.h>
#include "../area_stuff.h"

//incendiary cloud, ice storm, fire storm, and storm of vengeance spells when released - code something so that 
//interact with one another
#define VALID_TYPES ({"frozen", "burning", "raging", "smoky"})
inherit OBJECT;
string type, fail, broken_orb;


void make_type(string str)
{
    if(!objectp(TO)) return;
    if(!stringp(str)) return;
    if(str == "random" || member_array(str, VALID_TYPES) == -1)
    {
        type = VALID_TYPES[random(sizeof(VALID_TYPES))];
    }
    else type = str;
    set_name("a weightless "+type+" orb");
    set_value(10000);
    set_weight(0);
    
    set_id(({"orb", "weightless orb", type +" orb", "weightless "+type+" orb"}));
    
    set_property("no animate", 1);
    
    switch(type)
    {
        case "frozen":
            set_short("%^BOLD%^%^WHITE%^Fr%^CYAN%^o%^BOLD%^%^WHITE%^z"+
            "%^CYAN%^e%^BOLD%^%^WHITE%^n w%^CYAN%^ei%^BOLD%^%^WHITE%^ghtl"+
            "%^CYAN%^e%^BOLD%^%^WHITE%^ss %^CYAN%^o%^BOLD%^%^WHITE%^rb%^RESET%^");
            
            set_long("%^BOLD%^%^WHITE%^This small orb is a flawless circle. "+
            "It is cool to the touch but nothing like you would suspect from looking "+
            "inside of it. Glancing into it you can "+
            "make out snow and ice continually assaulting a barren and alien landscape. "+
            "It is weightless, almost as light as air, and is completely smooth. You are "+
            "not sure how fragile it is or even what purpose it might serve. However, there "+
            "is an immense power radiating out from it that is felt without any effort at "+
            "all on your part.%^RESET%^");
            break;
        case "burning":
            set_short("%^BOLD%^%^RED%^B%^YELLOW%^u%^BOLD%^%^RED%^rn%^YELLOW%^i"+
            "%^BOLD%^%^RED%^ng w%^YELLOW%^ei%^BOLD%^%^RED%^ghtl%^YELLOW%^e"+
            "%^BOLD%^%^RED%^ss %^YELLOW%^o%^BOLD%^%^RED%^rb%^RESET%^");
            
            set_long("%^BOLD%^%^RED%^This small orb is a flawless circle. "+
            "It is slightly warm to the touch but nothing like you would suspect from "+
            "looking inside of it. Glancing into it you can make out "+
            "balls of fire and chunks of magma laying waste to a barren and alien landscape. "+
            "It is weightless, almost as light as air, and is completely smooth. You are "+
            "not sure how fragile it is or even what purpose it might serve. However, there "+
            "is an immense power radiating out from it that is felt without any effort at "+
            "all on your part.%^RESET%^");
            break;
        case "raging":
            set_short("%^BOLD%^%^BLACK%^R%^WHITE%^a%^BOLD%^%^BLACK%^g%^CYAN%^i%^BOLD%^%^BLACK%^"+
            "ng w%^WHITE%^ei%^BOLD%^%^BLACK%^ghtl%^CYAN%^e%^BOLD%^%^BLACK%^ss %^WHITE%^o"+
            "%^BOLD%^%^BLACK%^rb%^RESET%^");
            
            set_long("%^BOLD%^%^BLACK%^This small orb is a flawless circle. "+
            "It vibrates, hums, and crackles with static electricity when touched, but nothing like "+
            "you would suspect from looking inside of it. Glancing into it you can make out "+
            "a storm of %^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^p%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^c%^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^"+
            "l%^BOLD%^%^BLACK%^y%^BOLD%^%^WHITE%^p%^BOLD%^%^BLACK%^t%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^c "+
            "proporations besieging a barren and alien landscape. It is weightless, almost "+
            "as light as air, and is completely smooth. You are not sure how fragile "+
            "it is or even what purpose it might serve. However, there is an immense "+
            "power radiating out from it that is felt without any effort at all on your "+
            "part.%^RESET%^");
            break;
        case "smoky":
            set_short("%^BOLD%^%^WHITE%^Sm%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^k%^BOLD%^%^BLACK%^y "+
            "%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^rb%^RESET%^");
            
            set_long("%^BOLD%^%^WHITE%^This small orb is a flawless circle. "+
            "It shakes violently in your hands and is slightly warm to the touch, but nothing like "+
            "you would suspect looking inside of it. Glancing into it you can make out "+
            "%^BOLD%^%^RED%^fire%^BOLD%^%^WHITE%^ and a very thick, acidic smoke enveloping "+
            "a barren and alien landscape that seems to visibly shudder at the assault. It is weightless, almost "+
            "as light as air, and is completely smooth. You are not sure how fragile "+
            "it is or even what purpose it might serve. However, there is an immense power "+
            "radiating out from it that is felt without any effort at all on your "+
            "part.%^RESET%^");
            break;
    }
    set_property("lore difficulty", 25);
    set_lore("%^BOLD%^%^WHITE%^You hold in your hands one of the orbs that served "+
    "as a key to some of the upper wards of Castle Freeholm. The Castle is Ancient and has been "+
    "mostly just a rumor that was disregarded by most people as nothing more than a myth, at least "+
    "until now. The Castle was said to house the King and Queen of Storm Giants, Asantra and Kayan "+
    "Freeholm. Kayan was not known for his kindness, in fact he was known almost exclusively for his "+
    "paranoid brutality. These orbs were used to unlock some of the lesser wards in the upper portion of "+
    "castle, which was said to be on what is now known as Eldebaro. Apparently the castle was warded quite "+
    "ferociously against potential intruders. Some years ago a large portion of the island as well as the "+
    "castle sank into the ocean, most people assumed it all destroyed. However, in recent years some cult has "+
    "been taking it upon themselves to see it risen again. Legend suggest that it was this same cult that was "+
    "responsible for sinking the castle and the island in the first place. An even older Legend suggests that the time of the "+
    "return of the Storm Giants was foretold long before the castle even sank and that Kayan had taken great "+
    "steps to protect the castle, to ward it in such a way that not even time would erode it. The power of "+
    "Kayan was believed greater than anything else in all the realms at the time anyway. However, you "+
    "have no idea how accurate any of these legends are, afterall, maybe they are simply myths. You do recall "+
    "another that suggest someone could <%^CYAN%^release%^BOLD%^%^WHITE%^> the power contained "+
    "within the orb and another that suggests no two orbs that are alike should ever come into contact with "+
    "one another.%^RESET%^");
    broken_orb = 0;
    set_heart_beat(1);
}

string query_orb_type() { return type; }
int is_eldebaro_orb_broke() { return broken_orb; }
int is_eldebaro_orb_key() { return 1; }
int set_orb_failure(int x) { fail = x; }
int query_orb_failure() { return fail; }

int filter_orbs(object ob)
{
    if(!objectp(ob)) return 0;
    return ob->is_eldebaro_orb_key();
}

void create() 
{
    ::create();
    if(!stringp(type))
    make_type("random");
}

void init()
{
    ::init();   
    add_action("release_act", "release");
}

void set_broken_desc()
{
    set_long("%^BOLD%^%^WHITE%^This small orb is a flawless circle. "+
    "Glancing into it you can make out "+
    "a barren and alien landscape, that is void of all life and seems to be "+
    "slowly fading away. It is weightless, almost "+
    "as light as air, and is completely smooth. You are not sure how fragile "+
    "it is or even what purpose it might serve. However, it seems quite "+
    "mundane.%^RESET%^");
    
     set_lore("%^BOLD%^%^WHITE%^You hold in your hands one of the orbs that served "+
    "as a key to some of the upper wards of Castle Freeholm. The Castle is Ancient and has been "+
    "mostly just a rumor that was disregarded by most people as nothing more than a myth, at least "+
    "until now. The Castle was said to house the King and Queen of Storm Giants, Asantra and Kayan "+
    "Freeholm. Kayan was not known for his kindness, in fact he was known almost exclusively for his "+
    "paranoid brutality. These orbs were used to unlock some of the lesser wards in the upper portion of "+
    "castle, which was said to be on what is now known as Eldebaro. Apparently the castle was warded quite "+
    "ferociously against potential intruders. Some years ago a large portion of the island as well as the "+
    "castle sank into the ocean, most people assumed it all destroyed. However, in recent years some cult has "+
    "been taking it upon themselves to see it risen again. Legend suggest that it was this same cult that was "+
    "responsible for sinking the castle and the island in the first place. An even older Legend suggests that the time of the "+
    "return of the Storm Giants was foretold long before the castle even sank and that Kayan had taken great "+
    "steps to protect the castle, to ward it in such a way that not even time would erode it. The power of "+
    "Kayan was believed greater than anything else in all the realms at the time anyway. However, you "+
    "have no idea how accurate any of these legends are, afterall, maybe they are simply myths. You do recall "+
    "another that suggest someone could <%^CYAN%^release%^BOLD%^%^WHITE%^> the power contained "+
    "within the orb, though this one appears empty, and another that suggests no two orbs that "+
    "are alike should ever come into contact with "+
    "one another.%^RESET%^");    
}


int do_orb_release_two()
{
    object cast_by, cast_at, *vics;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(broken_orb) return 0;
    if(!living(ETO) && !fail) 
    {
        if(!ETO->is_room()) return 0;
        tell_room(ETO, "%^BOLD%^%^BLACK%^The orb vibrates and hums for a brief moment before settling back down.%^RESET%^");
        return 1;
    }
    if(fail)
    {
        if(living(ETO)) 
        { 
            cast_by = ETO; 
            vics = filter_array(all_living(EETO), "is_non_immortal_player", FILTERS_D); 
            if(!sizeof(vics)) return 0; 
            else cast_at = vics[random(sizeof(vics))]; 
        }
        else if(living(EETO)) 
        { 
            cast_by = EETO; 
            vics = filter_array(all_living(environment(EETO)), "is_non_immortal_player", FILTERS_D); 
            if(!sizeof(vics)) return 0; 
            else cast_at = vics[random(sizeof(vics))]; 
        }
        else if(ETO->is_room()) 
        { 
            cast_by = ETO; 
            vics = filter_array(all_living(ETO), "is_non_immortal_player", FILTERS_D);
            if(!sizeof(vics)) return 0; 
            else cast_at = vics[random(sizeof(vics))]; 
        }
    }
    else { cast_by = ETO; cast_at = 0; }
    switch(type)
    {
        case "frozen":
            tell_object(ETO, "%^BOLD%^%^WHITE%^The orb splits open with a loud CRAAACCCKKKK!! and the world around you is "+
            "pelted with an %^BOLD%^%^CYAN%^ICE STORM%^BOLD%^%^WHITE%^!%^RESET%^");
            tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^'s "+TO->query_short()+" %^BOLD%^%^WHITE%^ splits open with a loud CRAAACCCKKK!! "+
            "and the world around you is pelted with an %^BOLD%^%^CYAN%^ICE STORM%^BOLD%^%^WHITE%^!%^RESET%^", ETO);
            
            new("/cmds/spells/i/_ice_storm")->use_spell(cast_by, cast_at, 35, 100, "mage");
            
            set_broken_desc();
            broken_orb = 1;
            break;
        case "burning":
            tell_object(ETO, "%^BOLD%^%^RED%^The orb bursts open with a loud ROOAAAARRRR!!! and the world around you is "+
            "engulfed with a %^BOLD%^%^YELLOW%^FIRE STORM%^BOLD%^%^RED%^!%^RESET%^");
            
            tell_room(EETO, ETOQCN+"%^BOLD%^%^RED%^'s "+TO->query_short()+" %^BOLD%^%^RED%^ bursts open with a loud ROOOAAAARRRR!! and the world "+
            "around you is engulfed with a %^BOLD%^%^YELLOW%^FIRE STORM%^BOLD%^%^RED%^!%^RESET%^", ETO);
            
            new("/cmds/spells/f/_fire_storm")->use_spell(cast_by, cast_at, 35, 100, "cleric");
            set_broken_desc();
            broken_orb = 1;
            
            break;
        case "raging":
            tell_object(ETO, "%^BOLD%^%^BLACK%^The orb tears open with a defeaning BOOOOOOMMMMMM!!! and the world around you "+
            "is assaulted by a %^BOLD%^%^WHITE%^STORM OF VENGEANCE%^BOLD%^%^BLACK%^!%^RESET%^");
            
            tell_room(EETO, ETOQCN+"%^BOLD%^%^BLACK%^'s "+TO->query_short()+"%^BOLD%^%^BLACK%^ tears open with a loud BOOOOOMMMMM!! and the "+
            "world around you is assaulted by a %^BOLD%^%^WHITE%^STORM OF VENGEANCE%^BOLD%^%^BLACK%^!%^RESET%^", ETO);
            
            new("/cmds/spells/s/_storm_of_vengeance")->use_spell(cast_by, cast_at, 35, 100, "druid");
            
            set_broken_desc();
            broken_orb = 1;            
          
            break;
        case "smoky":
            
            tell_object(ETO, "%^BOLD%^%^WHITE%^The orb rips open with an immense and violent CRAAAACCCCKKK!! and the world around you "+
            "is enveloped by an %^BOLD%^%^GREEN%^INCENDIARY CLOUD%^BOLD%^%^WHITE%^!%^RESET%^");
            
            tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^'s "+TO->query_short()+"%^BOLD%^%^WHITE%^ rips open with an immense and violet "+
            "CRAAAACCCCKKK!! and the world around you is enveloped by an %^BOLD%^%^GREEN%^INCENDIARY CLOUD%^BOLD%^%^WHITE%^!%^RESET%^", ETO);
            
            new("/cmds/spells/i/_incendiary_cloud")->use_spell(cast_by, cast_at, 35, 100, "mage");
            
            set_broken_desc();
            broken_orb = 1;           
            break;
    }
    return 1;
}

int do_orb_release()
{
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    tell_object(ETO, "%^BOLD%^%^WHITE%^You concentrate carefully on the orb, seeking to release "+
    "whatever havoc might be contained within it!%^RESET%^");
    ETO->set_paralyzed(12, "%^BOLD%^%^WHITE%^You are concentrating on the orb!%^RESET%^");
    if(objectp(EETO))
    {
        tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^ seems to be concentrating carefully on "+ETO->QP+
        " "+TO->query_short()+"%^BOLD%^%^WHITE%^!%^RESET%^", ETO);
    }
    call_out("do_orb_release_two", 8);
    return 1;
}

int release_act(string str)
{
    object ob;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!living(ETO)) return 0;
    if(!stringp(str)) return 0;
    if(!objectp(ob = present(str, ETO))) return 0;
    if(!ob->is_eldebaro_orb_key()) return 0;
    if(ob->is_eldebaro_orb_broke()) return 0;
    if (ETO->query_bound() || ETO->query_unconscious() || ETO->query_paralyzed()) 
    {
        ETO->send_paralyzed_message("info",ETO);
        return 1;
    }
    ob->do_orb_release();
    return 1;    
}

void heart_beat()
{
    object *inv, *failed_orbs;
    int x;

    if(!objectp(ETO)) return;
    if(broken_orb) { set_heart_beat(0); return; }
    if(living(ETO))
    {
        inv = filter_array(deep_inventory(ETO), "filter_orbs", TO);
        inv -= ({TO});
        x = sizeof(inv);
        if(!x) return;
        if(x)
        {
            failed_orbs = ({});
            for(x = 0;x < sizeof(inv);x++)
            {
                
                if((string)inv[x]->query_orb_type() == type && (!(int)inv[x]->is_eldebaro_orb_broke() && !broken_orb)) 
                {
                   tell_object(ETO, "%^BOLD%^%^BLACK%^You get an immediate sense of dread as "+TO->query_short()+
                    " begins interacting with "+inv[x]->query_short()+"!%^RESET%^");
                    
                    tell_room(EETO, "%^BOLD%^%^BLACK%^The "+TO->query_short()+"%^BOLD%^%^BLACK%^ held by "+ETOQCN+"%^BOLD%^%^BLACK%^"+
                    " begins interacting with something!%^RESET%^", ETO);
                    inv[x]->set_orb_failure(1);
                    TO->set_orb_failure(1);
                    failed_orbs += ({TO, inv[x]});
                    continue;
                }
            }
            tell_object(ETO, "failed orbs = "+identify(failed_orbs));
            failed_orbs = distinct_array(failed_orbs);
            if(sizeof(failed_orbs)) failed_orbs->do_orb_release_two();
            return;
        }
    }
    return;
}

