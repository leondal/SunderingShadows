#include <std.h>
#include <daemons.h>
#include "../area_stuff.h"
#define COM "/d/common/obj/armour/"+

inherit OBJECT;

void create()
{
    ::create();
}
void transform(object ob, string form)
{
    object myOb;
    string *myIds, *myBonuses;
    mapping tmp;
    int x;
    
    if(!objectp(ob)) return;
    if(!stringp(form)) return;
    tmp = query_item_bonuses();
    if(mapp(tmp))   
    {
        myBonuses = keys(tmp);
    }
		
    for(x = 0;x < sizeof(myBonuses);x++)
    {
        set_item_bonus(myBonuses[x], 0);
        continue;
    }

    switch(form) 
    {
        case "hide":
            myOb = new(COM"hide");
            myIds = myOb->query_id();
            myIds += ({"dark orange hide", "orange hide"});
            
            ob->set_obvious_short("%^RESET%^%^ORANGE%^dark orange hide armor%^RESET%^");
                
            ob->set_long("%^RESET%^%^ORANGE%^This suit of hide armor is a very dark orange. "+
            "You are completely uncertain of what type of creature it is from, however, there are "+
            "strange bumps visible over the entire surface of it. Some of the bumps are actually "+
            "%^BOLD%^%^RED%^b%^BOLD%^%^BLACK%^a%^BOLD%^%^RED%^rb%^BOLD%^%^BLACK%^e%^BOLD%^%^RED%^d "+
            "%^RESET%^%^ORANGE%^ and sometimes leak out a %^BOLD%^%^GREEN%^foul smelling%^RESET%^%^ORANGE%^ "+
            "liquid that sizzles where ever it touches. The inside of the armor is padded with a thick "+
            "and lighter colored material. Oddly the armor seems flexible, malleable, and quite sturdy, and "+
            "you believe that it would resist almost all damage inflicted upon it. You also realize that "+
            "there is some writing on the inside of it, near the neckline.%^RESET%^");           
            
            ob->set_mystate("hide");
            
            ob->clear_item_bonus();
            ob->set_item_bonus("dexterity", 6);
            ob->set_item_bonus("damage bonus", 4);
            ob->set_item_bonus("stealth", 4);
            break;

        case "chain":
            myOb = new(COM"chain");

            myIds = myOb->query_id();
            myIds += ({"orange chain", "dark orange chain", "orange chainmail", "dark orange chainmail"});
      
            ob->set_obvious_short("%^RESET%^%^ORANGE%^dark orange chain mail%^RESET%^");

            ob->set_long("%^RESET%^%^ORANGE%^This suit of dark orange chain mail seems quite "+
            "dull and unattractive at first glance. You also realize that it is not metallic at all, "+
            "in fact you are unable to determine what type of substance was used to construct it. The "+
            "chains are exceptionally fine and woven close together. The entire armor is flexible and strangely "+
            "seems almost malleable. Strange symbols appear over the entire armor, though they frequently "+
            "move from one location to another and seem to also be constantly changing shapes and forms. "+
            "There is a very thick inner layer to the armor that is made from a "+
            "lighter colored material. You also realize that there is some writing on the inside of it, "+
            "near the neckline.%^RESET%^");
            
            ob->set_mystate("chain");
            ob->clear_item_bonus();            
            ob->set_item_bonus("intelligence", 6);
            ob->set_item_bonus("perception", 4);
            ob->set_item_bonus("spell damage resistance", 15);
            break;
        case "plate":
            myOb = new(COM"fullplate");
 
            myIds = myOb->query_id();
            myIds += ({"orange plate", "dark orange plate", "dark orange full plate"});

            ob->set_obvious_short("%^RESET%^%^ORANGE%^dark orange full plate%^RESET%^");

            ob->set_long("%^RESET%^%^ORANGE%^This thick suit of full plate armor is quite dull. "+
            "It is composed of a dark orange substance, you realize instantly that it is not metallic "+
            "but are unable to determine exactly what it is. There are several solid plates of the "+
            "substance that interlock together to create a solid protective encasing around the "+
            "wearer. The plates interlock in such a way that they allow much more freedom of movement "+
            "than a typical suit of full plate. There are also strange symbols that appear on "+
            "several of the plates for brief moments of time before vanishing and appearing "+
            "in an entirely different location. There is a thick padding on the inside of the armor "+
            "composed of a lighter colored material. You realize that there is writing "+
            "on the inside of it, near the neckline.%^RESET%^");            
            ob->clear_item_bonus();
            
            ob->set_item_bonus("constitution", 6);
            ob->set_item_bonus("attack bonus", 4);
            ob->set_item_bonus("endurance", 4);
            ob->set_mystate("plate");
            break;        
    }
    if(!ob->query_property("enchantment")) ob->set_property("enchantment", 5);    
    ob->set_max_dex_bonus((int)myOb->query_max_dex_bonus());
    ob->set_armor_prof((string)myOb->query_armor_prof());
    ob->set_ac((int)myOb->query_ac());
    ob->set_weight((int)myOb->query_weight());
    if(objectp(myOb)) myOb->remove();
    
    myIds += ({"changeling cover"});
    ob->set_id(myIds);
    if(objectp(TO)) TO->remove();
    return;
}

void clean_me()
{
    if(objectp(TO)) TO->remove();
}

//hide damages all attackers - with acid
//hide reduces damage by 1/2

//elven chain - avoids all damage
//elven chain - causes wearer to attack

//plate - avoids all damage - heals wearer instead
//stuns attackers with sonic - no damage, just stun

int special_attack(object ob, object targ, string form, int damage)
{
    object EOB, EEOB, *vics;
    string limb, tmp;
    int dam, num, x;
    if(!objectp(ob) || !objectp(targ) || !stringp(form)) 
    {
        call_out("clean_me", 1);
        return damage;
    }
    EOB = environment(ob);
    if(!objectp(EOB)) 
    {
        call_out("clean_me", 1);
        return damage;
    }
    EEOB = environment(environment(ob)); 
    if(!objectp(EEOB)) 
    {
        call_out("clean_me", 1);
        return damage;
    }
    limb = targ->return_target_limb();
    tmp = ob->query_obvious_short();
    num = random(10);
    switch(num) 
    {
        case 0..4:
            switch(form)
            {
                case "hide":
                    vics = EOB->query_attackers();
                    if(!sizeof(vics)) 
                    {
                        call_out("clean_me", 1);
                        return damage;
                    }
                    tell_object(EOB, "%^BOLD%^%^GREEN%^Acid splashes out from your "+tmp+"!%^RESET%^");
                    tell_room(EEOB, "%^BOLD%^%^GREEN%^Acid splashes out from "+EOB->QCN+
                    "%^BOLD%^%^GREEN%^'s "+tmp+"!%^RESET%^", EOB);
                    for(x = 0;x < sizeof(vics);x++)
                    {
                        if(!objectp(vics[x])) continue;
                        if(EEOB != environment(vics[x])) continue;
                        if(vics[x]->reflex_save((int)EOB->query_base_character_level())) continue;
                        limb = vics[x]->return_target_limb();
                        tell_object(vics[x], "%^BOLD%^%^GREEN%^Your "+limb+" is soaked by the acid!%^RESET%^");
                        tell_room(EEOB, vics[x]->QCN+"%^BOLD%^%^GREEN%^'s "+limb+" is soaked by the acid!%^RESET%^", vics[x]);
                        vics[x]->cause_typed_damage(vics[x], limb, roll_dice(4,4), "acid");
                        continue;
                    }
                    call_out("clean_me", 1);
                    return damage;
                    break;
                case "chain":
                    tell_object(EOB, "%^BOLD%^%^WHITE%^As "+targ->QCN+"%^BOLD%^%^WHITE%^ strikes at you, "+
                    "you quickly move out of the way, entirely avoiding the blow!%^RESET%^");
                    
                    tell_object(targ, "%^BOLD%^%^WHITE%^As you strike at "+EOB->QCN+"%^BOLD%^%^WHITE%^ "+EOB->QS+" "+
                    "quickly moves out of the way, entirely avoiding the blow!%^RESET%^");
                    
                    tell_room(EEOB, "%^BOLD%^%^WHITE%^As "+targ->QCN+"%^BOLD%^%^WHITE%^ strikes at "+
                    EOB->QCN+"%^BOLD%^%^WHITE%^ "+EOB->QS+" quickly moves out of the way, "+
                    "entirely avoiding the blow!%^RESET%^", ({EOB, targ}));
                    call_out("clean_me", 1);
                    return 0;
                case "plate":
                    tell_object(EOB, "%^BOLD%^%^BLACK%^As "+targ->QCN+"%^BOLD%^%^BLACK%^ connects with you, "+
                    "you feel "+tmp+" absorb the blow and using the energy of it to replenish you!%^RESET%^");
                    
                    tell_object(targ, "%^BOLD%^%^BLACK%^As you connect with "+EOB->QCN+"%^BOLD%^%^BLACK%^ "+
                    "you feel the blow absorbed by "+EOB->QP+" "+tmp+"%^BOLD%^%^BLACK%^ and watch as "+
                    EOB->QS+" seems replenished!%^RESET%^");
                    
                    tell_room(EEOB, "%^BOLD%^%^BLACK%^As "+targ->QCN+"%^BOLD%^%^BLACK%^ connects with "+
                    EOB->QCN+"%^BOLD%^%^BLACK%^, "+EOB->QCN+"%^BOLD%^%^BLACK%^ seems replenished!"+
                    "%^RESET%^", ({targ, EOB}));
                    
                    EOB->heal_me(damage);
                    call_out("clean_me", 1);
                    return (damage*-1);
            }
        case 5..9:
            switch(form)
            {
                case "hide":
                    tell_object(EOB, "%^RESET%^%^ORANGE%^You feel your "+tmp+"%^RESET%^%^ORANGE%^ lessen the "+
                    "impact of "+targ->QCN+"%^RESET%^%^ORANGE%^'s blow!%^RESET%^");

                    tell_object(targ, "%^RESET%^%^ORANGE%^You feel the impact of your blow on "+EOB->QCN+
                    "%^RESET%^%^ORANGE%^ partially absorbed by "+EOB->QP+" "+tmp+"!%^RESET%^");

                    tell_room(EEOB, "%^RESET%^%^ORANGE%^As "+targ->QCN+"%^RESET%^%^ORANGE%^ strikes "+
                    EOB->QCN+"%^RESET%^%^ORANGE%^ the impact of "+targ->QP+" blow is lessened by "+
                    EOB->QCN+"%^RESET%^%^ORANGE%^'s "+tmp+"!%^RESET%^", ({EOB, targ}));

                    call_out("clean_me", 1);
                    return (damage/2);
                
                case "chain":                
                    tell_object(EOB, "%^BOLD%^%^GREEN%^As "+targ->QCN+"%^BOLD%^%^GREEN%^ lands an "+
                    "attack you spot a weakness and launch an attack of your own!%^RESET%^");

                    tell_object(targ, "%^BOLD%^%^GREEN%^As you land an attack on "+EOB->QCN+"%^BOLD%^"+
                    "%^GREEN%^, "+EOB->QS+"%^BOLD%^%^GREEN%^ launches an attack of "+EOB->QP+
                    " own!%^RESET%^");

                    tell_room(EEOB, "%^BOLD%^%^GREEN%^As "+targ->QCN+"%^BOLD%^%^GREEN%^ lands an "+
                    "attack on "+EOB->QCN+"%^BOLD%^%^GREEN%^, "+EOB->QS+" launches an attack of "+EOB->QP+
                    " own!%^RESET%^", ({EOB, targ}));
                   
                    EOB->execute_attack();
                    call_out("clean_me", 1);                    
                    return damage;
 
                case "plate":
                    tell_object(EOB, "%^BOLD%^%^RED%^As "+targ->QCN+"%^BOLD%^%^RED%^ lands a blow "+
                    "on your "+tmp+"%^BOLD%^%^RED%^ a wave of sonic energy erupts outward from it!%^RESET%^");

                    tell_object(targ, "%^BOLD%^%^RED%^As you land a blow on "+EOB->QCN+"%^BOLD%^%^RED%^'s "+
                    " "+tmp+"%^BOLD%^%^RED%^ a wave of sonic energy erupts outward from it!%^RESET%^");

                    tell_room(EEOB, "%^BOLD%^%^RED%^As "+targ->QCN+"%^BOLD%^%^RED%^ lands a blow "+
                    "on "+EOB->QCN+"%^BOLD%^%^RED%^'s "+tmp+"%^BOLD%^%^RED%^ a wave of sonic "+
                    "energy erupts outward from it!%^RESET%^", ({EOB, targ}));
                    
                    vics = EOB->query_attackers();
                    if(!sizeof(vics))
                    {
                        call_out("clean_me", 1);
                        return damage;
                    }                    
                    for(x = 0;x < sizeof(vics);x++)
                    {
                        if(!objectp(vics[x])) continue;
                        if(EEOB != environment(vics[x])) continue;
                        if(vics[x]->reflex_save((int)EOB->query_base_character_level()) || vics[x]->query_property("no paralzye")) continue;
                        tell_object(vics[x], "%^BOLD%^%^CYAN%^You are thrown to the ground by "+
                        "the wave of sonic energy!%^RESET%^");
                        tell_room(EEOB, vics[x]->QCN+"%^BOLD%^%^CYAN%^ is thrown to the ground by "+
                        "the wave of sonic energy!%^RESET%^", ({vics[x]}));
                        vics[x]->set_paralyzed((20 + roll_dice(2,10)), "%^BOLD%^%^CYAN%^You are trying "+
                        "to get to your feet!%^RESET%^");
                        continue;
                    }
                    call_out("clean_me",1);                 
                    return damage;
            }
            break;
    }
    return damage;
}
