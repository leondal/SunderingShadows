#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"


inherit OBJECT;

void create()
{
    ::create();
}

void special_attack(object ob, object targ, string dam_type)
{
    object EOB, EEOB;
    string limb, tmp;
    int dam, num;
    if(!objectp(ob) || !objectp(targ) || !stringp(dam_type)) 
    {
       TO->remove();
       return;
    }
    EOB = environment(ob);
    if(!objectp(EOB)) 
    {
       TO->remove();
       return;
    }
    EEOB = environment(environment(ob)); 
    if(!objectp(EEOB)) 
    {
       TO->remove();
       return;
    }
    limb = targ->return_target_limb();
    tmp = ob->query_short();

    switch(random(15)) 
    {
        case 0..10:


            switch(dam_type)
            {
                case "acid":
                    tell_object(EOB, "%^BOLD%^%^GREEN%^As you strike "+targ->QCN+" acid splashes from your "+tmp+"%^BOLD%^%^GREEN%^ "+
                    "and soaks "+targ->QO+"!%^RESET%^");
                    
                    tell_object(targ, "%^BOLD%^%^GREEN%^As "+EOB->QCN+" %^BOLD%^%^GREEN%^strikes you with "+EOB->QP + " "+tmp+
                    "%^BOLD%^%^GREEN%^ acid splashes from it, soaking you!%^RESET%^");

                    tell_room(EEOB, "%^BOLD%^%^GREEN%^As "+EOB->QCN+"%^BOLD%^%^GREEN%^ strikes "+targ->QCN+" with "+EOB->QP+ 
                    " " +tmp+" %^BOLD%^%^GREEN%^acid splashes from it, soaking "+targ->QO+"!%^RESET%^", ({EOB, targ}));

                    targ->cause_typed_damage(targ, limb, roll_dice(4,4), "acid");
                    break;
                
                case "cold":

                    tell_object(EOB, "%^BOLD%^%^CYAN%^As you strike "+targ->QCN+" with your "+tmp+" %^BOLD%^%^CYAN%^"+
                    "an %^BOLD%^%^WHITE%^ic%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^cle%^BOLD%^%^CYAN%^ erupts from it "+
                    "and imbeds into "+targ->QP+" flesh!%^RESET%^");

                    tell_object(targ, "%^BOLD%^%^CYAN%^As "+EOB->QCN+"%^BOLD%^%^CYAN%^ strikes you with "+EOB->QP +" "+
                    tmp+"%^BOLD%^%^CYAN%^ an %^BOLD%^%^WHITE%^ic%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^"+
                    "cle%^BOLD%^%^CYAN%^ erupts from it and imbeds into your flesh!%^RESET%^");

                    tell_room(EEOB, "%^BOLD%^%^CYAN%^As "+EOB->QCN+"%^BOLD%^%^CYAN%^ strikes "+targ->QCN+
                    "%^BOLD%^%^CYAN%^ with "+EOB->QP+" " +tmp+"%^BOLD%^%^CYAN%^ an %^BOLD%^%^WHITE%^ic"+
                    "%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^cle%^BOLD%^%^CYAN%^ erupts from it "+
                    "and imbeds into "+targ->QP+" flesh!%^RESET%^", ({EOB, targ}));

                    targ->cause_typed_damage(targ, limb, roll_dice(4, 4), "cold");
                    break;
  
                case "electricity":
            
                    tell_object(EOB, "%^BOLD%^%^YELLOW%^Your "+tmp+"%^BOLD%^%^YELLOW%^ releases a %^BOLD%^%^RED%^JOLT"+
                    "%^BOLD%^%^YELLOW%^ of electricity as you strike "+targ->QCN+"%^BOLD%^%^YELLOW%^ with it, shocking "+
                    targ->QO+"!%^RESET%^");
 
                    tell_object(targ, "%^BOLD%^%^YELLOW%^As "+EOB->QCN+"%^BOLD%^%^YELLOW%^ strikes you with "+EOB->QP+
                    " " +tmp+"%^BOLD%^%^YELLOW%^ a %^BOLD%^%^RED%^JOLT%^BOLD%^%^YELLOW%^ of electricity from it shocks "+
                    "you!%^RESET%^");

                    tell_room(EEOB, "%^BOLD%^%^YELLOW%^As "+EOB->QCN+"%^BOLD%^%^YELLOW%^ strikes "+targ->QCN+" with "+EOB->QP+
                    " " +tmp+"%^BOLD%^%^YELLOW%^ a %^BOLD%^%^RED%^JOLT%^BOLD%^%^YELLOW%^ of electricity is released from it, "+
                    "shocking "+targ->QO+"!%^RESET%^", ({EOB, targ}));

                    targ->cause_typed_damage(targ, limb, roll_dice(4, 4), "electricity");

                    break;
 
                case "fire":
                    
                    tell_object(EOB, "%^BOLD%^%^RED%^A tendril of fl%^BOLD%^%^YELLOW%^a%^BOLD%^%^RED%^m%^BOLD%^%^YELLOW%^e "+
                    "%^BOLD%^%^RED%^erupts from your "+tmp+
                    "%^BOLD%^%^RED%^ as you strike "+targ->QCN+" and lashes at "+targ->QO+"!%^RESET%^");

                    tell_object(targ, "%^BOLD%^%^RED%^A tendril of fl%^BOLD%^%^YELLOW%^a%^BOLD%^%^RED%^m%^BOLD%^%^YELLOW%^e "+
                    "%^BOLD%^%^RED%^erupts from "+EOB->QCN+"%^BOLD%^%^RED%^'s "+tmp+"%^BOLD%^%^RED%^ as "+EOB->QS+
                    " strikes you and lashes you!%^RESET%^");

                    tell_room(EEOB, "%^BOLD%^%^RED%^A tendril of fl%^BOLD%^%^YELLOW%^a%^BOLD%^%^RED%^m%^BOLD%^%^YELLOW%^e "+
                    "%^BOLD%^%^RED%^ erupts from "+EOB->QCN+"%^BOLD%^%^RED%^'s "+tmp+" %^BOLD%^%^RED%^ as "+EOB->QS+
                    "strikes "+targ->QCN+" %^BOLD%^%^RED%^ and lashes at "+targ->QO+"%^BOLD%^%^RED%^!%^RESET%^", ({EOB, targ}));
                    if(!random(30)) POISON_D->ApplyPoison(targ, CROB+"fiery_toxin", TO, "contact");
                    targ->cause_typed_damage(targ, limb, roll_dice(4, 4), "fire");

                    break;
            }
            break;
        case 11..13:
                
            tell_object(EOB, "%^BOLD%^%^BLACK%^As you strike "+targ->QCN+"%^BOLD%^%^BLACK%^ with your "+tmp+
            "%^BOLD%^%^BLACK%^ you gain enough momentum to land another blow!%^RESET%^");
 
            tell_object(targ, "%^BOLD%^%^BLACK%^As "+EOB->QCN+"%^BOLD%^%^BLACK%^ strikes you with "+EOB->QP+
            " " + tmp + "%^BOLD%^%^BLACK%^ "+EOB->QS+ " gains enough momentum to land another blow!%^RESET%^");

            tell_room(EEOB, "%^BOLD%^%^BLACK%^As "+EOB->QCN+"%^BOLD%^%^BLACK%^ strikes "+targ->QCN+" with "+EOB->QP+
            " " + tmp + "%^BOLD%^%^BLACK%^ "+EOB->QS+" gains enough momentum to land another blow!%^RESET%^", ({EOB, targ}));

            EOB->execute_attack();
            break;

        case 14:
 
            tell_object(EOB, "%^BOLD%^%^WHITE%^You manage to position yourself so that you can land "+
            "a d%^BOLD%^%^RED%^e%^BOLD%^%^WHITE%^v%^BOLD%^%^RED%^a%^BOLD%^%^WHITE%^st%^BOLD%^%^RED%^"+
            "i%^BOLD%^%^WHITE%^ng blow on "+targ->QCN+"%^BOLD%^%^WHITE%^ and watch in amazement as your "+
            tmp+"%^BOLD%^%^WHITE%^ covers "+targ->QO+" with "+dam_type+"%^BOLD%^%^WHITE%^!%^RESET%^");
                    
            tell_object(targ, "%^BOLD%^%^WHITE%^As "+ EOB->QCN+"%^BOLD%^%^WHITE%^ lands a d%^BOLD%^%^RED%^e%^BOLD%^"+
            "%^WHITE%^v%^BOLD%^%^RED%^a%^BOLD%^%^WHITE%^st%^BOLD%^%^RED%^i%^BOLD%^%^WHITE%^ng blow "+
            "on you with "+EOB->QP+" " +tmp+"%^BOLD%^%^WHITE%^ you are engulfed by %^RED%^"+dam_type+
            "%^BOLD%^%^WHITE%^!%^RESET%^");

            tell_room(EEOB, "%^BOLD%^%^WHITE%^"+targ->QCN+"%^BOLD%^%^WHITE%^ is engulfed by "+
            "%^BOLD%^%^RED%^"+dam_type+" as "+EOB->QCN+"%^BOLD%^%^WHITE%^ lands a d%^BOLD%^%^RED%^e"+
            "%^BOLD%^%^WHITE%^v%^BOLD%^%^RED%^a%^BOLD%^%^WHITE%^st%^BOLD%^%^RED%^"+
            "i%^BOLD%^%^WHITE%^ng blow on "+targ->QO+"%^BOLD%^%^WHITE%^ with "+EOB->QP+
            " "+tmp+"%^BOLD%^%^WHITE%^!%^RESET%^", ({targ, EOB}));

            targ->cause_typed_damage(targ, limb, roll_dice(2,6), dam_type);
            break;
    }
    TO->remove();
    return;  
}
