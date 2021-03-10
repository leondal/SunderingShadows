//removed references to old gods ~Circe~ 7/30/19
#include <std.h>
#include <daemons.h>

inherit "/d/common/obj/armour/shield.c"; 
int charges;
int beating;
int damage;
int count = 1200;

void create(){
    ::create();
    set_name("A polished silver shield");
    set_id(({ "shield", "silver shield", "heart of talos", "polished shield", "polished silver shield" }));
    set_obvious_short("%^BOLD%^%^WHITE%^A polished silver shield%^RESET%^");

    set_short("%^BOLD%^%^BLACK%^The H%^YELLOW%^e%^BOLD%^%^WHITE%^a%^YELLOW%^r%^BOLD%^%^BLACK%^t of N%^YELLOW%^i%^BOLD%^%^WHITE%^l%^YELLOW%^i%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^h%^RESET%^");

    set_long("%^RESET%^This beautiful shield is made from what appears to be %^BOLD%^pure silver%^RESET%^. It has been polished to the point where it reflects almost any light into a d%^MAGENTA%^a%^BOLD%^%^WHITE%^zzl%^MAGENTA%^i%^BOLD%^%^WHITE%^ng %^RESET%^display of %^BOLD%^g%^YELLOW%^o%^BOLD%^%^WHITE%^ld%^YELLOW%^e%^BOLD%^%^WHITE%^n %^RESET%^color. It is almost oval in shape and its edge is lined with a more tarnished, almost %^BOLD%^%^BLACK%^bl%^CYAN%^a%^BOLD%^%^BLACK%^ck metal%^RESET%^. There are thick %^BOLD%^%^BLACK%^leather straps %^RESET%^on the back of it serving as a means of strapping or wrapping it around your arm while you hold the cumbersome handle that has been added into the center of its back. You also notice a small emblem near the top of it, hidden from view except from the one holding it. This emblem is in the shape of single, wilted %^BOLD%^%^WHITE%^ca%^RESET%^l%^BOLD%^l%^RESET%^a %^BOLD%^li%^RESET%^l%^BOLD%^y%^RESET%^ being held in a %^BOLD%^skeletal hand %^RESET%^superimposed on an engorged %^RED%^h%^BOLD%^e%^RESET%^%^RED%^art.%^RESET%^");

    set_lore("%^BOLD%^%^WHITE%^Legend suggest that this remarkable shield was crafted by a blacksmith of some renown who used to frequent the town of Verbobone. It was originally crafted and polished for a priest of Jarmila and at one point it was said to have an entirely different emblem emblazoned on it. During a battle of some significance against a priest of Nilith, one which was reportedly witnessed by Aorus Devar, it changed dramatically as the priest was holding it. Some say that Aorus Devar was somehow involved with its current enchantments, but none are for certain. What is known is that shortly after the remarkable battle both priests disappeared.%^RESET%^");
    
    set_size(-1);
    set_weight(12);
    set_value(10000);
    set_property("no curse", 1);
    set_property("enchantment", 5);
    set_item_bonus("shieldMiss", 40);
    set_item_bonus("electricity resistance", 35);
    set_item_bonus("spell damage resistance", 20);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
    set_struck((:TO, "strike_func":));
    set_heart_beat(1);	
    beating = 0;
    charges = 0;
}

void heart_beat()
{
    string targ_name;
    int tmp_dam;
    if(!objectp(TO->query_worn()))
    {
        return;
    }
    if(!objectp(ETO)) 
    {
        return;
    }
    if(!living(ETO))
    {
        return;
    }
    switch(beating)
    {
        case 0:
            if(random(10000) > 9997)
            {
                tell_object(ETO, "%^YELLOW%^A loud rumbling issues from your shield "+
                "and a strange sensation travels up the length of your arm "+
                "- you feel as though the shield itself has a beating heart!%^RESET%^");
                beating = 1;
                if(objectp(EETO))
                {
                    tell_room(EETO, "%^YELLOW%^A loud rumbling issues from "+ETOQCN+
                    "'s shield!%^RESET%^", ({ETO}));
                }
                count = 1200;
                return;
            }
        case 1: 
            if(random(10000) > 9995)
            {
                if(count > 0) 
                {
                    count--;
                }
                else
                {
                    tell_object(ETO, "%^YELLOW%^The rumbling from your shield slowly "+
                    "subsides and then fades away.... its beating heart stopped "+
                    "for now...");
                    tell_object(ETO, "%^RED%^A voice whispers to "+
                    "you: %^RESET%^%^WHITE%^"+
                    "this is not over.... %^RESET%^");
                    beating = 0;
                    return;
                }
            }
    }
    if(beating)
    {	
        if(random(10000) > 9950) 
        {
            if((int)EETO->query_property("indoors") == 1) 
            {
                return;
            }
            if((string)WEATHER_D->Check_Weather(ETO) == "%^BOLD%^%^CYAN%^It is clear.")
            {
                return;
            }
	
            tell_object(ETO, "%^YELLOW%^Your eyes are suddenly drawn to the skies "+
            "%^YELLOW%^overhead as a massive B%^BOLD%^%^WHITE%^O%^YELLOW%^L"+
            "%^BOLD%^%^WHITE%^T%^YELLOW%^ of "+
            "l%^BOLD%^%^WHITE%^i%^YELLOW%^ghtn%^BOLD%^%^WHITE%^i%^YELLOW%^ng "+
            "descends upon you!%^RESET%^");
            if(ETO->query_invis()) 
            {
                targ_name = "some unseen object";				
            }	
            else
            {
                targ_name = ETOQCN;
            }
            if(objectp(EETO))
            {
                tell_room(EETO, "%^YELLOW%^Your eyes are suddenly drawn to the skies "+
                "overhead as a massive B%^BOLD%^%^WHITE%^O%^YELLOW%^L"+
                "%^BOLD%^%^WHITE%^T%^YELLOW%^ of "+
                "l%^BOLD%^%^WHITE%^i%^YELLOW%^ghtn%^BOLD%^%^WHITE%^i%^YELLOW%^ng "+
                "descends and strikes "+
                targ_name + "!%^RESET%^", ({ETO}));
            }
            tell_object(ETO, "%^YELLOW%^Power floods your body and you "+
            "SCR%^BOLD%^%^RED%^EA%^YELLOW%^M in as the lightning "+
            "courses through your veins!%^RESET%^");
            tell_room(EETO, "%^YELLOW%^"+ETOQCN+" SCR%^BOLD%^%^RED%^EA%^YELLOW%^MS "+
            "as the lightning flows through "+ETO->QP+" body!%^RESET%^", ({ETO}));
            tmp_dam = roll_dice(4,10);
            damage += tmp_dam;
            charges += 2 + random(5);
            if(charges > 50)
            {
                charges = 50;
            }		
            tell_object(ETO, "%^BOLD%^%^YELLOW%^M%^BOLD%^%^CYAN%^i%^YELLOW%^r%^CYAN%^"+
            "a%^YELLOW%^c%^CYAN%^u%^YELLOW%^l%^CYAN%^ou%^YELLOW%^sly you find yourself "+
            "refreshed by the lightning!%^RESET%^");
            ETO->heal(tmp_dam);
            return;		
        }
    }		
}

int wearme()
{
    tell_object(ETO, "%^BOLD%^%^WHITE%^You feel several strange sensations "+
    "course throughout your body as you wear the shield.%^RESET%^");
	return 1;
}
	
int removeme()
{
    tell_object(ETO, "%^BOLD%^%^WHITE%^You feel dramatically at ease as "+
    "the strange sensations stop.%^RESET%^");
	return 1;
}

int strike_func(int mydamage, object what, object who)
{
    int dam, x;
    object *foes;
    if(!objectp(who)) return damage;
    if(!objectp(ETO)) return damage;
   
    if(!random(3) || !charges) return damage;
    
    if(damage >= 150)
    {
        tell_object(ETO, "%^BOLD%^%^WHITE%^As "+who->QCN+"%^BOLD%^%^WHITE%^ connects "+
        "with your shield a %^BOLD%^%^BLACK%^D%^BOLD%^%^GREEN%^EA%^BOLD%^%^BLACK%^F"+
        "%^BOLD%^%^GREEN%^E%^BOLD%^%^BLACK%^N%^BOLD%^%^GREEN%^I%^BOLD%^%^BLACK%^NG "+
        "B%^BOLD%^%^GREEN%^OO%^BOLD%^%^BLACK%^M %^BOLD%^%^WHITE%^erupts from it "+
        "and w%^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^sh%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^"+
        "s over your foes in a dramatic discharge of %^BOLD%^%^YELLOW%^E%^BOLD%^%^BLACK%^"+
        "L%^BOLD%^%^YELLOW%^E%^BOLD%^%^WHITE%^CTR%^BOLD%^%^YELLOW%^I%^BOLD%^%^BLACK%^C%^BOLD%^"+
        "%^YELLOW%^I%^BOLD%^%^BLACK%^TY%^BOLD%^%^WHITE%^!%^RESET%^");
        
        foes = ETO->query_attackers();
        
        dam = damage/sizeof(foes);
        if(dam > 150)
        {
            if(!random(4)) dam = dam * 2;
            else dam = 150;
        }
        if(dam < 40) dam = 40;        
        damage = 0;
        
        tell_object(who, "%^BOLD%^%^WHITE%^As you connect "+
        "with "+ETO->QCN+"%^BOLD%^%^WHITE%^'s shield a %^BOLD%^%^BLACK%^"+
        "D%^BOLD%^%^GREEN%^EA%^BOLD%^%^BLACK%^F"+
        "%^BOLD%^%^GREEN%^E%^BOLD%^%^BLACK%^N%^BOLD%^%^GREEN%^I%^BOLD%^%^BLACK%^NG "+
        "B%^BOLD%^%^GREEN%^OO%^BOLD%^%^BLACK%^M %^BOLD%^%^WHITE%^erupts from it "+
        "in a dramatic discharge of %^BOLD%^%^YELLOW%^E%^BOLD%^%^BLACK%^"+
        "L%^BOLD%^%^YELLOW%^E%^BOLD%^%^WHITE%^CTR%^BOLD%^%^YELLOW%^I%^BOLD%^%^BLACK%^C%^BOLD%^"+
        "%^YELLOW%^I%^BOLD%^%^BLACK%^TY%^BOLD%^%^WHITE%^!%^RESET%^");
        
        
        tell_room(EETO, "%^BOLD%^%^WHITE%^As "+who+QCN+"%^BOLD%^%^WHITE%^ connects "+
        "with "+ETO->QCN+"%^BOLD%^%^WHITE%^'s shield a %^BOLD%^%^BLACK%^"+
        "D%^BOLD%^%^GREEN%^EA%^BOLD%^%^BLACK%^F"+
        "%^BOLD%^%^GREEN%^E%^BOLD%^%^BLACK%^N%^BOLD%^%^GREEN%^I%^BOLD%^%^BLACK%^NG "+
        "B%^BOLD%^%^GREEN%^OO%^BOLD%^%^BLACK%^M %^BOLD%^%^WHITE%^erupts from it "+
        "in a dramatic discharge of %^BOLD%^%^YELLOW%^E%^BOLD%^%^BLACK%^"+
        "L%^BOLD%^%^YELLOW%^E%^BOLD%^%^WHITE%^CTR%^BOLD%^%^YELLOW%^I%^BOLD%^%^BLACK%^C%^BOLD%^"+
        "%^YELLOW%^I%^BOLD%^%^BLACK%^TY%^BOLD%^%^WHITE%^!%^RESET%^", ({ETO, who}));
        
        for(x = 0;x < sizeof(foes);x++)
        {
            if(!objectp(foes[x])) continue;
            if(environment(foes[x]) != EETO) continue;
            
            tell_object(foes[x], "%^BOLD%^%^YELLOW%^You are zapped by a "+
            "ball of %^BOLD%^%^YELLOW%^E%^BOLD%^%^BLACK%^"+
            "L%^BOLD%^%^YELLOW%^E%^BOLD%^%^WHITE%^CTR%^BOLD%^%^YELLOW%^I%^BOLD%^%^BLACK%^C%^BOLD%^"+
            "%^YELLOW%^I%^BOLD%^%^BLACK%^TY%^BOLD%^%^WHITE%^!%^RESET%^");
            
            tell_room(EETO, foes[x]->QCN+ "%^BOLD%^%^YELLOW%^ is zapped by a "+
            "ball of %^BOLD%^%^YELLOW%^E%^BOLD%^%^BLACK%^"+
            "L%^BOLD%^%^YELLOW%^E%^BOLD%^%^WHITE%^CTR%^BOLD%^%^YELLOW%^I%^BOLD%^%^BLACK%^C%^BOLD%^"+
            "%^YELLOW%^I%^BOLD%^%^BLACK%^TY%^BOLD%^%^WHITE%^!%^RESET%^", foes[x]);
            
            if(foes[x] == who) foes[x]->cause_typed_damage(foes[x], "torso", dam, "electricity");
            else foes[x]->cause_typed_damage(foes[x], "torso", (dam/2), "electricity");
            continue;            
        }
        charges -= 5;
        if(charges < 0) charges = 0;
        return mydamage;
    }
    switch(random(40))
    {
        case 0..36:
            tell_object(ETO, "%^BOLD%^%^YELLOW%^As "+who->QCN+"%^BOLD%^%^YELLOW%^ strikes your "+
            "shield a %^BOLD%^%^WHITE%^B%^BOLD%^%^BLACK%^O%^BOLD%^%^WHITE%^L%^BOLD%^%^BLACK%^T"+
            "%^BOLD%^%^YELLOW%^ of electricity %^BOLD%^%^RED%^B%^BOLD%^%^WHITE%^U%^BOLD%^%^RED%^"+
            "RSTS%^BOLD%^%^YELLOW%^ forth from it and %^BOLD%^%^GREEN%^ZAPS%^BOLD%^%^YELLOW%^ "+
            who->QO+"%^BOLD%^%^YELLOW%^!%^RESET%^");
            
            
            tell_object(who, "%^BOLD%^%^YELLOW%^As you strike "+ETOQCN+
            "%^BOLD%^%^YELLOW%^'s shield a %^BOLD%^%^WHITE%^B%^BOLD%^%^BLACK%^O%^BOLD%^%^WHITE%^L%^BOLD%^%^BLACK%^T"+
            "%^BOLD%^%^YELLOW%^ of electricity %^BOLD%^%^RED%^B%^BOLD%^%^WHITE%^U%^BOLD%^%^RED%^"+
            "RSTS%^BOLD%^%^YELLOW%^ forth from it and %^BOLD%^%^GREEN%^ZAPS%^BOLD%^%^YELLOW%^ "+
            "you!%^RESET%^");
            
            tell_room(EETO, "%^BOLD%^%^YELLOW%^As "+who->QCN+"%^BOLD%^%^YELLOW%^ strikes "+ETOQCN+
            "%^BOLD%^%^YELLOW%^'s shield a %^BOLD%^%^WHITE%^B%^BOLD%^%^BLACK%^O%^BOLD%^%^WHITE%^L%^BOLD%^%^BLACK%^T"+
            "%^BOLD%^%^YELLOW%^ of electricity %^BOLD%^%^RED%^B%^BOLD%^%^WHITE%^U%^BOLD%^%^RED%^"+
            "RSTS%^BOLD%^%^YELLOW%^ forth from it and %^BOLD%^%^GREEN%^ZAPS%^BOLD%^%^YELLOW%^ "+
            who->QO+"%^BOLD%^%^YELLOW%^!%^RESET%^", ({ETO, who}));
            
            dam = roll_dice(3, 6);
            damage += dam;
            who->cause_typed_damage(who, "torso", dam, "electricity");
            if(!random(2)) charges -= 1 + random(3);
            if(charges < 0) charges = 0;
            return mydamage;
            break;
            
        case 37..39:
        
            tell_object(ETO, "%^BOLD%^%^BLACK%^As "+who->QCN+"%^BOLD%^%^BLACK%^ strikes your "+
            "shield "+who->QS+"%^BOLD%^%^BLACK%^ is V%^BOLD%^%^YELLOW%^I%^BOLD%^%^RED%^O%^BOLD%^"+
            "%^GREEN%^L%^BOLD%^%^MAGENTA%^E%^BOLD%^%^WHITE%^N%^BOLD%^%^BLACK%^T%^BOLD%^%^YELLOW%^L"+
            "%^BOLD%^%^RED%^Y%^BOLD%^%^BLACK%^ sh%^BOLD%^%^CYAN%^o%^BOLD%^%^BLACK%^cked!%^RESET%^");
            
            tell_object(who, "%^BOLD%^%^BLACK%^As you%^BOLD%^%^BLACK%^ strike "+ETOQCN+
            "%^BOLD%^%^BLACK%^'s shield you are V%^BOLD%^%^YELLOW%^I%^BOLD%^%^RED%^O%^BOLD%^"+
            "%^GREEN%^L%^BOLD%^%^MAGENTA%^E%^BOLD%^%^WHITE%^N%^BOLD%^%^BLACK%^T%^BOLD%^%^YELLOW%^L"+
            "%^BOLD%^%^RED%^Y%^BOLD%^%^BLACK%^ sh%^BOLD%^%^CYAN%^o%^BOLD%^%^BLACK%^cked!%^RESET%^");
            
            tell_room(EETO, "%^BOLD%^%^BLACK%^As "+who->QCN+" %^BOLD%^%^BLACK%^ strikes "+ETOQCN+
            "%^BOLD%^%^BLACK%^'s shield "+who->QS+" is V%^BOLD%^%^YELLOW%^I%^BOLD%^%^RED%^O%^BOLD%^"+
            "%^GREEN%^L%^BOLD%^%^MAGENTA%^E%^BOLD%^%^WHITE%^N%^BOLD%^%^BLACK%^T%^BOLD%^%^YELLOW%^L"+
            "%^BOLD%^%^RED%^Y%^BOLD%^%^BLACK%^ sh%^BOLD%^%^CYAN%^o%^BOLD%^%^BLACK%^cked!%^RESET%^", ({ETO, who}));          
            
            dam = roll_dice(6,6);
            damage += dam;
            who->cause_typed_damage(who, "torso", dam, "electricity");
            if(!random(2)) charges -= 1 + random(3);
            if(charges < 0) charges = 0;
            return mydamage;
            break;        
    }
    return damage;
}
