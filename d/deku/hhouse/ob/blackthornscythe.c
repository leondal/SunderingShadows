#include <std.h>
inherit "/d/common/obj/weapon/scythe.c";
int summoning;
object *MyShadows;
void fade_away();

void create()
{
    ::create();

    set_name("black steel scythe");
   
    set_short("%^BOLD%^%^BLACK%^Bl%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^"+
    "ckth%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^rn's Sh%^BOLD%^%^WHITE%^a"+
    "%^BOLD%^%^BLACK%^d%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^w "+
    "Scyth%^BOLD%^%^WHITE%^e%^RESET%^");

    set_obvious_short("A black steel scythe");

    set_id(({"scythe","steel scythe","black steel scythe",
    "blackthorn scythe","shadow scythe","blackthorns shadow scythe"}));

    set_long("%^BOLD%^%^BLACK%^This weapon is made from a very "+
    "%^RED%^strange%^BOLD%^%^BLACK%^ substance. The %^BLUE%^"+
    "substance%^BOLD%^%^BLACK%^ has been forged into the likeness "+
    "of a common scythe. The %^RED%^bla%^BLUE%^d%^RED%^e"+
    "%^BOLD%^%^BLACK%^ of this scythe is almost %^CYAN%^mist"+
    "%^BOLD%^%^BLACK%^ like, continually swirling and moving "+
    "inside of a %^YELLOW%^golden tinged%^BOLD%^%^BLACK%^ border.  "+
    "Flashes of %^RED%^intense%^BOLD%^%^BLACK%^ fire occasionally "+
    "expl%^YELLOW%^o%^BOLD%^%^BLACK%^de within the "+
    "%^RED%^bla%^BLUE%^d%^RED%^e%^BOLD%^%^BLACK%^ "+
    "and the expl%^YELLOW%^o%^BOLD%^%^BLACK%^si%^YELLOW%^o%^BOLD%^"+
    "%^BLACK%^ns move rapidly outward and collide with the "+
    "golden border, being absorbed by it. A shadow in an open mouthed scream erupts from the blade right after the "+
    "explosions and quickly %^CYAN%^vanishes%^BOLD%^%^BLACK%^ back into "+
    "the misty depths of the blade.  "+
    "%^BOLD%^%^BLACK%^The handle of this scythe is made from a dark "+
    "%^RESET%^%^GREEN%^green%^BOLD%^%^BLACK%^ wood that has "+
    "jagged and %^MAGENTA%^deep%^BOLD%^%^BLACK%^ lines engraved "+
    "in circular patterns all the way along its length.%^RESET%^");
    set_property("lore difficulty",10);
    
    set_lore("This scythe was originally formed for the warrior "+
    "Blackthorn.  It is said that his friend and ally Narameon "+
    "enchanted it for him and in continuing his devious nature "+
    "granted it strange magical properties that perhaps he "+
    "alone could ever identify.  This weapon was lost long ago "+
    "with Blackthorn, it was last in his possession when he "+
    "went on a long adventure and was never again seen.");
    
    set_property("enchantment", 4);
    set_item_bonus("mental resistance", 10);
    set_value(2000);
    set_wield((:TO,"wield_me":));
    //set_unwield((:TO,"unwield_me":));
    set_hit((:TO,"hit_em":));
    MyShadows = ({ });
}

void make_shadow(object who) 
{
    string *classes;
    int x, y;
    object mon;
    if(!objectp(who)) return;
    if(!pointerp(MyShadows)) MyShadows = ({ });
    if(!pointerp(MyShadows)) 
    {
        tell_object(ETO, "%^BOLD%^%^RED%^Error: Something is wrong with your scythe, tell %^B_CYAN%^%^YELLOW%^SAIDE%^RESET%^ THIS MESSAGE");
        return;
    }
    if(sizeof(MyShadows) >= 2) return;
    mon = new("/std/weaponless_monsters");
    x = ((int)who->query_max_hp() / 2);
    //if(x > 400) x = 400;
    if(x > 250) x = 200;
    mon->set_hp(x);

    mon->set_alignment(9);
    mon->set_race("shadow");
    
    x = ((int)who->query_highest_level() / 2);
    if(x > 25) {
        x = 25;
    }
    if(x < 15) {
        x = 15;
    }
    classes = who->query_classes();
    mon->set_new_exp(20, "low");
    for(y = 0;y < sizeof(classes);y++) 
    {
        mon->set_class(classes[y]);
        mon->set_guild_level(classes[y],x);
        mon->set_mlevel(classes[y],x);
    }
    mon->set_damage(2,(x/2));
    mon->set_base_damage_type("slashing");
    mon->set_attacks_num(2);
    mon->set_stats("strength",(int)who->query_stats("strength"));
    mon->set_stats("exceptional_strength",(int)who->query_stats("exceptional_strength"));
    mon->set_stats("constitution",(int)who->query_stats("constitution"));
    mon->set_stats("wisdom",(int)who->query_stats("wisdom"));
    mon->set_stats("intelligence",(int)who->query_stats("intelligence"));
    mon->set_stats("charisma",(int)who->query_stats("charisma"));
    mon->set_stats("dexterity",(int)who->query_stats("dexterity"));
    x = who->query_ac();
    mon->set_overall_ac(x / 2);
    mon->set_short("%^BOLD%^%^BLACK%^A shadow with glowing %^RED%^"+
    "red %^BOLD%^%^BLACK%^eyes%^RESET%^");
    mon->set_id(({"shadow","insane shadow","evil shadow",
    "blackthornshadowguard"}));
    mon->set_name("A shadow");
    mon->set_size((int)who->query_size());
    mon->set_long("%^BOLD%^%^BLACK%^This is the shadow of some "+
    "type of humanoid creature.  It appears almost solid, but "+
    "still seems to lack any substance.  The face of this being "+
    "is set in a sneer and in the place of teeth is an abyssal "+
    "blackness.  Above the sneer, where eyes would be, are two "+
    "glowing, fierce %^RED%^red%^BOLD%^%^BLACK%^ "+
    "eyes.  The rest of this strange shadow seems to continually "+
    "flicker, an affect that subtracts from the little "+
    "substance it does have.%^RESET%^");
    mon->move(environment(who));
    mon->add_attacker(who);
    who->add_attacker(mon);
    who->add_follower(mon);
    mon->set_property("fade_time", time()+180);
    mon->set_property("owned_by",ETO);
    if(who != ETO) MyShadows += ({mon});
    call_out("fade_away", 180, ETO);
    summoning = 0;
}

void fade_away()
{
    int x;
    if(!objectp(TO) || !objectp(ETO)) return;
    if(!pointerp(MyShadows)) 
    {
        log_file("errors/deku", "Something went wrong with a shadow on from "+base_name(TO) + " in possession of "+ETO->query_name()+".");
        return;
    }
    for(x = 0;x < sizeof(MyShadows);x++)
    {
        if(!objectp(MyShadows[x])) 
        {
            MyShadows -= ({MyShadows[x]});
            continue;
        }
        else
        {
            if(MyShadows[x]->query_property("fade_time") >= time()) 
            {
                tell_room(environment(MyShadows[x]), MyShadows[x]->QCN+"%^BOLD%^%^WHITE%^ fades from ex%^BOLD%^%^YELLOW%^is%^BOLD%^%^WHITE%^"+
                "tence!%^RESET%^");
                MyShadows[x]->move("/d/shadow/void");
                if(objectp(MyShadows[x])) MyShadows[x]->remove();
                MyShadows -= ({MyShadows[x]});
                continue;
            }
        }
        continue;
    }
    if(sizeof(MyShadows) >= 1) call_out("fade_away", 180);
    return;
}

void critical_failure() 
{
    tell_room(EETO,"%^BOLD%^%^BLACK%^A bolt of dark energy zaps "+
    "from "+ETOQCN+"%^BOLD%^%^BLACK%^'s scythe and melds with "+
    ETO->QP+" shadow!%^RESET%^",ETO);
    
    tell_object(ETO,"%^BOLD%^%^BLACK%^A bolt of dark energy zaps "+
    "from your scythe and melds with your shadow!%^RESET%^");
    
    call_out("critical_failure_two",2,ETO);    
}

void critical_failure_two(object who) 
{
    if(who != ETO) return;
    if(!objectp(EETO)) return;

    tell_room(EETO,ETOQCN+"%^BOLD%^%^BLACK%^'s shadow stands up "+
    "behind him, an insane sneer dominating its face, and its "+
    "eyes glowing a fierce %^RED%^red%^RESET%^%^BOLD%^%^BLACK%^!"+
    "%^RESET%^",ETO);

    make_shadow(who);
}

void shadow_summon(object who) 
{
    if(!objectp(ETO)) return;
    if(!objectp(who)) return;
    if(!objectp(environment(who))) return;

    tell_room(environment(who),who->QCN+"%^BOLD%^%^BLACK%^'s shadow "+
    "stands up behind him, an intense sneer dominating its face, "+
    "and its eyes glowing a fierce %^RED%^red%^BOLD%^%^BLACK%^!"+
    "%^RESET%^",who);
    make_shadow(who);
}

int hit_em(object targ)
{
    string limb;
    object mon;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!objectp(targ)) return 5;
    if(random(1000) > 500 && random(1000) < 500) 
    { 
        switch(random(20)) 
        {
            case 0:
                tell_object(targ,ETOQCN+"%^RED%^ sinks "+ETO->QP+
                " scythe into your %^BOLD%^%^BLACK%^chest%^RED%^"+
                " with a sickening %^BOLD%^%^GREEN%^hiss!%^RESET%^");
                
                tell_object(ETO,"%^RED%^You sink your scythe "+
                "into "+targ->QCN+"%^RED%^'s %^BOLD%^%^BLACK%^chest"+
                "%^RED%^ with a sickening %^BOLD%^%^GREEN%^hiss!"+
                "%^RESET%^");

                tell_room(EETO,ETOQCN+"%^RED%^ sinks "+ETO->QP+
                " scythe into "+targ->QCN+"%^RED%^'s %^BOLD%^%^BLACK%^"+
                " chest with a sickening %^BOLD%^%^GREEN%^hiss!"+
                "%^RESET%^",({ETO,targ}));
                

                if(!random(100) 
                && (int)ETO->query_size() <= 3
                && !summoning) { 
                    if(mon = present("blackthornshadowguard",EETO)) 
                    {
                        if(to_object(mon->query_property("owned_by")) == ETO) 
                        {
                            return 0;
                        }
                    }
                    summoning = 1;
                    critical_failure();
                }

                return roll_dice(1,6);
                break;
            case 1..18:
                if(targ->query_stoneSkinned() && !random(100)) 
                {
                    tell_object(ETO,"%^BOLD%^%^BLACK%^You slice "+
                    "your scythe through the hardened flesh of "+
                    targ->QCN+"%^BOLD%^%^BLACK%^ and %^RED%^rip"+
                    "%^BOLD%^%^BLACK%^ away parts of the %^BLUE%^magical"+
                    "%^BOLD%^%^BLACK%^ barrier!%^RESET%^");

                    tell_object(targ,ETOQCN+"%^BOLD%^%^BLACK%^ "+
                    "slices "+ETO->QP+" scythe through your hardened "+
                    "flesh and %^RED%^rips%^BOLD%^%^BLACK%^ away "+
                    "parts of the %^BLUE%^magical %^BOLD%^%^BLACK%^ "+
                    "barrier!%^RESET%^");   
                    
                    tell_room(EETO,ETOQCN+"%^BOLD%^%^BLACK%^ "+
                    "slices "+ETO->QP+" scythe through the "+
                    "hardened flesh of "+targ->QCN+"%^BOLD%^%^BLACK%^"+
                    "!%^RESET%^",({ETO,targ}));
                    set_property("magic",1);
                    targ->cause_typed_damage(targ, targ->return_target_limb(),roll_dice(2,4), "slashing");
                    set_property("magic",-1);
                    targ->set_stoneSkinned(((int)targ->query_stoneSkinnned() - (2 + random(3))));
                    return 0;
                    break;
                }
                else 
                {
                    tell_object(ETO,"%^BOLD%^%^BLACK%^You slice "+
                    "your scythe through "+targ->QCN+"%^BOLD%^%^BLACK%^"+
                    "'s flesh!%^RESET%^");
                    
                    tell_object(targ,ETOQCN+"%^BOLD%^%^BLACK%^ "+
                    "slices "+ETO->QP+" scythe through your flesh!"+
                    "%^RESET%^");

                    tell_room(EETO,ETOQCN+"%^BOLD%^%^BLACK%^ slices "+
                    ETO->QP+" scythe through the flesh of "+
                    targ->QCN+"!%^RESET%^",({ETO,targ}));
                    return roll_dice(2,4);
                }
                break;
            case 19:
                limb = ETO->return_target_limb();
                
                tell_object(targ,ETOQCN+"%^BOLD%^%^BLACK%^ slams "+
                "the handle of "+ETO->QP+" scythe into your "+
                "chest and then slices the blade through your "+
                limb+".!%^RESET%^");

                tell_object(ETO,"%^BOLD%^%^BLACK%^You slam the "+
                "handle of your scythe into "+targ->QCN+
                "%^BOLD%^%^BLACK%^'s chest and then slice the "+
                "blade through "+targ->QP+" "+limb+"!%^RESET%^");

                tell_room(EETO,ETOQCN+"%^BOLD%^%^BLACK%^ slams "+
                "the handle of "+ETO->QP+" scythe into "+targ->QCN+
                "%^BOLD%^%^BLACK%^'s chest and then slices the "+
                "blade through "+targ->QP+" "+limb+"!%^RESET%^",
                ({ETO,targ}));

                targ->cause_typed_damage(targ, targ->return_target_limb(),roll_dice(3,4), "slashing");

                if((int)targ->query_size() <= 3 
                && !summoning && sizeof(MyShadows) < 2) 
                { 
                    summoning = 1;
                    tell_room(EETO,"%^BOLD%^%^BLACK%^A bolt of dark "+
                    "energy zaps from "+ETOQCN+"%^BOLD%^%^BLACK%^'s "+
                    "scythe and melds with "+targ->QCN+"%^BOLD%^%^BLACK%^"+
                    "'s shadow!%^RESET%^",({targ,ETO}));

                    tell_object(ETO,"%^BOLD%^%^BLACK%^A bolt of "+
                    "dark energy zaps from your scythe and "+
                    "melds with "+targ->QCN+"%^BOLD%^%^BLACK%^'s "+
                    "shadow!%^RESET%^");

                    tell_object(targ,"%^BOLD%^%^BLACK%^A bolt of "+
                    "dark energy zaps from "+ETOQCN+"%^BOLD%^%^BLACK%^"+
                    "'s scythe and melds with your shadow!%^RESET%^");  

                    call_out("shadow_summon",2,targ);
                }

                break;
        }
    }
}

int wield_me(){
    if((int)ETO->query_highest_level() < 20) 
    {
        tell_object(ETO,"%^BOLD%^%^BLACK%^You scream in %^RED%^"+
        "pain%^BOLD%^%^BLACK%^ as your body is momentarily "+
        "thrown into %^CYAN%^convulsions%^BOLD%^%^BLACK%^, causing "+
        "you to lose your grip on the scythe!%^RESET%^");
        
        if(ETO->query_invis()) 
        {
            tell_room(EETO,ETOQCN+"%^BOLD%^%^BLACK%^ screams out in "+
            "%^RED%^pain%^BOLD%^%^BLACK%^!%^RESET%^",ETO);
        }
        else 
        { 
            tell_room(ETO,ETOQCN+"%^BOLD%^%^BLACK%^ screams out in "+
            "%^RED%^pain%^BOLD%^%^BLACK%^ as "+ETO->QP+" body is "+
            "momentarily thrown into %^CYAN%^convulsions%^BOLD%^"+
            "%^BLACK%^!%^RESET%^",ETO);
        }

        ETO->cause_typed_damage(ETO, "left hand",roll_dice(2,6), "mental");
        ETO->add_attacker(TO);
        ETO->continue_attack();
        if(objectp(ETO)) 
        {
            ETO->remove_attacker(TO);
        }
        return 0;
    }
    tell_object(ETO,"%^BOLD%^%^BLACK%^You scream in %^RED%^"+
    "pain%^BOLD%^%^BLACK%^ as your body is momentarily "+
    "thrown into %^CYAN%^convulsions%^BOLD%^%^BLACK%^ and "+
    "you barely manage to retain your hold on the scythe.%^RESET%^");        
    if(ETO->query_invis()) 
    {
        tell_room(EETO,ETOQCN+"%^BOLD%^%^BLACK%^ screams out in "+
        "%^RED%^pain%^BOLD%^%^BLACK%^!%^RESET%^",ETO);
    }
    else 
    {        
        tell_room(ETO,ETOQCN+"%^BOLD%^%^BLACK%^ screams out in "+
        "%^RED%^pain%^BOLD%^%^BLACK%^ as "+ETO->QP+" body is "+
        "momentarily thrown into %^CYAN%^convulsions%^BOLD%^"+
        "%^BLACK%^!%^RESET%^",ETO);
    }
    ETO->cause_typed_damage(ETO, "left hand",roll_dice(1,6), "mental");
    ETO->add_attacker(TO);
    ETO->continue_attack();
    if(objectp(ETO)) 
    {
        ETO->remove_attacker(TO);
    }
    return 1;
}

object *query_shadows() { return MyShadows; }
