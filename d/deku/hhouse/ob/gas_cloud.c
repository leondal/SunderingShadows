#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"

inherit OBJECT;

string effect;
int delay, potency;
string dest;

void create() 
{
    ::create();
    switch(random(2)) 
    {
        case 0:
            effect = "poison";
            set_name("cloud of noxious gas");
            set_id(({"cloud of gas", "gas", "noxious gas", "cloud", "hhousenoxcloud"}));
            set_short("%^BOLD%^%^GREEN%^Cloud of n%^BOLD%^%^YELLOW%^o"+
            "%^BOLD%^%^GREEN%^x%^BOLD%^%^YELLOW%^i%^BOLD%^%^GREEN%^o"+
            "%^BOLD%^%^YELLOW%^u%^BOLD%^%^GREEN%^s gas%^RESET%^");

            set_long("%^BOLD%^%^GREEN%^This massive cloud of noxious "+
            "gas hangs heavily here. It is thick enough that you are unable "+
            "to see through it easily and unstable enough that "+
            "you should not stay within it for very long. It is difficult "+
            "to breath inside the cloud and what little air that you can "+
            "grasp is entirely toxic.%^RESET%^");
            break;
        case 1:
            effect = "lightning";
            set_name("swirling mass of fire and lightning");
            set_id(({"mass", "swirling mass of fire", "swirling mass", 
            "swirling mass of fire and lightning", "swirling mass of lightning", 
            "hhouselightcloud"}));
		
            set_short("%^BOLD%^%^BLACK%^S%^BOLD%^%^WHITE%^w%^BOLD%^%^BLACK%^"+
            "i%^BOLD%^%^WHITE%^r%^BOLD%^%^BLACK%^l%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^"+
            "n%^BOLD%^%^WHITE%^g %^BOLD%^%^BLACK%^m%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^s"+
            "%^BOLD%^%^WHITE%^s%^BOLD%^%^BLACK%^ of %^BOLD%^%^RED%^fire %^BOLD%^%^BLACK%^"+
            "and %^BOLD%^%^YELLOW%^lightning%^RESET%^");

            set_long("%^BOLD%^%^BLACK%^This swirling mass of cloud is very thick and "+
            "almost impenetrable. Flashes of lightning and eruptions of flame pulse out "+
            "from the center of it constantly, as if seeking out life to destroy. "+
            "It is massive and very unstable, capable of causing tremendous amounts of "+
            "damage to anything around it.%^RESET%^");
            break;
	}
    //they will absorb each other and create more powerful versions 
    //potentionally become very deadly - though upon 
    //each movement they will have a slim chance of dissipating 
    potency = 1;
    set_property("no animate",1);
    set_weight(0);
    set_heart_beat(1);
    delay = 15 + random(16);
}

int get() { return 0; }

int set_delay(int x) { delay = x; }

void pick_room()
{
    string *dests, myExit, dest;
    string *myAvoids = ({RROOMS+"23", SFROOMS+"3"});	
    //tell_room(ETO, "Getting to pick_room...");
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!random(10)) potency--;
    if(!random(40) || potency <= 0)
    {
        tell_room(ETO, TO->query_short()+"%^BOLD%^%^GREEN%^ dissipates and breaks apart into harmless vapors!%^RESET%^");
        TO->remove();
        return;
    }
    dests = ETO->query_destinations();
    if(pointerp(dests)) dests -= myAvoids;
    if(!sizeof(dests)) return;
    dest = dests[random(sizeof(dests))];
    myExit = ETO->query_direction(dest);
	
    tell_room(ETO, TO->query_short()+"%^BOLD%^%^BLUE%^ drifts slowly to the "+myExit+", propelled by the chill wind!%^RESET%^");
    TO->move(dest);
    tell_room(ETO, TO->query_short()+"%^BOLD%^%^BLUE%^ drifts in slowly, propelled by the chill wind!%^RESET%^");
    return;
}

void do_my_effect()
{
    object *vics;
    string myEffect;
    int x, tmp, dam;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    vics = all_living(ETO);
    if(!sizeof(vics)) return;
    for(x = 0;x < sizeof(vics);x++)
    {
        if(!objectp(vics[x])) continue;
        if(strsrch(base_name(vics[x]), HHMON) != -1) continue;
        if(vics[x]->query_true_invis()) continue;
        switch(effect)
        {
            case "poison": 
                myEffect = "poison";
                break;
            case "poisonandlightning":
                if(random(2)) myEffect = "poison";
                else myEffect = "lightning";
                break;
            case "lightningandpoison":
                if(random(2)) myEffect = "lightning";
                else myEffect = "poison";
                break;
            case "lightning":
                myEffect = "lightning";
                break;
        }
        switch(myEffect)
        {
            case "poison": 
                tell_object(vics[x], "%^BOLD%^%^GREEN%^You wheeze and gasp, struggling for "+
                "breath, but what you find is toxic gas!%^RESET%^");

                tell_room(ETO, vics[x]->QCN+"%^BOLD%^%^GREEN%^ wheezes and gasps, struggling "+
                "for breath!%^RESET%^", vics[x]);

                POISON_D->ApplyPoison(vics[x], "any", TO, "inhaled");
                continue;
            case "lightning":
                if(!random(3)) continue;
                switch(random(2)) 
                {
                    case 0:
                        tell_object(vics[x], "%^BOLD%^%^RED%^A massive ball of fire erupts from "+
                        TO->query_short()+"%^BOLD%^%^RED%^ and jets toward you!%^RESET%^");

                        tell_room(ETO, "%^BOLD%^%^RED%^A massive ball of fire erupts from "+
                        TO->query_short()+"%^BOLD%^%^RED%^ and jets toward "+vics[x]->QCN+
                        "%^BOLD%^%^RED%^!%^RESET%^", vics[x]);

                        if(vics[x]->reflex_save(20+(potency*5))) 
						{
                            tell_object(vics[x], "%^BOLD%^%^RED%^You quickly move out of the way just "+
                            "in time and the massive ball of fire explodes in the distance!%^RESET%^");
						
                            tell_room(ETO, vics[x]->QCN+"%^BOLD%^%^RED%^ moves out of the way just in "+
                            "time and the massive ball of fire explodes in the distance!%^RESET%^", vics[x]);
                            continue;
                        }
                        tell_object(vics[x], "%^BOLD%^%^RED%^The massive ball of fire slams into you and "+
                        "%^BOLD%^%^YELLOW%^E%^BOLD%^%^RED%^X%^BOLD%^%^YELLOW%^P%^BOLD%^%^RED%^L%^BOLD%^%^YELLOW%^"+
                        "O%^BOLD%^%^RED%^D%^BOLD%^%^YELLOW%^E%^BOLD%^%^RED%^S!%^RESET%^");

                        tell_room(ETO, "%^BOLD%^%^RED%^The massive ball of fire slams into "+vics[x]->QCN+
                        " and %^BOLD%^%^YELLOW%^E%^BOLD%^%^RED%^X%^BOLD%^%^YELLOW%^P%^BOLD%^%^RED%^L%^BOLD%^%^YELLOW%^"+
                        "O%^BOLD%^%^RED%^D%^BOLD%^%^YELLOW%^E%^BOLD%^%^RED%^S!%^RESET%^", vics[x]);
                        tmp = potency;
                        while(tmp--) dam += roll_dice(8, 6);
                        vics[x]->cause_typed_damage(vics[x], 0, dam, "fire");
                        continue;
                    case 1:
                        tell_object(vics[x], "%^BOLD%^%^YELLOW%^A massive bolt of lightning zaps from "+
                        TO->query_short()+"%^BOLD%^%^YELLOW%^ and streaks toward you!%^RESET%^");
					
                        tell_room(ETO, "%^BOLD%^%^YELLOW%^A massive bolt of lightning zaps from "+
                        TO->query_short()+"%^BOLD%^%^YELLOW%^ and streaks toward "+vics[x]->QCN+
                        "%^BOLD%^%^YELLOW%^!%^RESET%^", vics[x]);
			
                        if(vics[x]->reflex_save(12 + (potency*5))) 
                        {
                            tell_object(vics[x], "%^BOLD%^%^YELLOW%^You quickly move out of the way just "+
                            "in time and the massive bolt of lightning slams into something in the distance!%^RESET%^");

                            tell_room(ETO, vics[x]->QCN+"%^BOLD%^%^YELLOW%^ moves out of the way just in "+
                            "time and the massive bolt of lightning slams into something in the distance!%^RESET%^", vics[x]);
                            continue;
                        }
                        tell_object(vics[x], "%^BOLD%^%^YELLOW%^The massive bolt of lightning slams into your "+
                        "chest with a %^BOLD%^%^WHITE%^BRILLIANT%^BOLD%^%^YELLOW%^ flash of %^BOLD%^%^WHITE%^LIGHT"+
                        "%^BOLD%^%^YELLOW%^!%^RESET%^");

                        tell_room(ETO, "%^BOLD%^%^YELLOW%^The massive bolt of lightning slams into "+vics[x]->QCN+
                        "%^BOLD%^%^YELLOW%^'s chest with a %^BOLD%^%^WHITE%^BRILLIANT%^BOLD%^%^YELLOW%^ flash of "+
                        "%^BOLD%^%^WHITE%^LIGHT%^BOLD%^%^YELLOW%^!%^RESET%^", vics[x]);
                        tmp = potency;
                        while(tmp--) dam += roll_dice(8, 8);
                        vics[x]->cause_typed_damage(vics[x], 0, dam, "electricity");
                        continue;
                }
                continue;
        }
    }
    return;
}

string query_effect() { return effect; }

int adjust_potency(int amt) 
{ 
    potency+= amt; 
    if(potency > 4) potency = 4;
    return potency;
}	

int query_potency() { return potency; }
	
void absorb(object targ)
{
    int flag;
    string me, myTarg;
    if(!objectp(targ)) return;
    if(!objectp(TO)) return;
    if(TO->query_property("being_absorbed")) 
    {
        targ->remove_property("being_absorbed");
        return; 
    }
    if(objectp(targ)) 
    {
        me = capitalize(TO->query_short());
        myTarg = capitalize(targ->query_short());
        if(effect == "poison" && (string)targ->query_effect() == "lightning")
        {
            set_name("noxious cloud of fire and lightning");
            set_id(({"noxious cloud", "cloud of fire and lightning", "hhousenoxnlightcloud"}));

            set_short("%^BOLD%^%^GREEN%^N%^BOLD%^%^YELLOW%^o"+
            "%^BOLD%^%^GREEN%^x%^BOLD%^%^YELLOW%^i%^BOLD%^%^GREEN%^o"+
            "%^BOLD%^%^YELLOW%^u%^BOLD%^%^GREEN%^s cloud of %^BOLD%^%^RED%^fire%^BOLD%^%^GREEN%^"+
            " and %^BOLD%^%^YELLOW%^lightning%^RESET%^");

            set_long("%^BOLD%^%^GREEN%^This massive cloud of noxious "+
            "gas hangs heavily here. Flashes of lightning and "+    
            "eruptions of flame pulse outward from the center of it constantly. "+
            "It is thick enough that you are unable to see through it "+
            "easily and has enough destructive power to call a tremendous "+
            "amount of damage to anything around it. It is difficult "+
            "to breath within the cloud and what air you can grasp "+
            "is entirely toxic.%^RESET%^");			
            effect = "poisonandlightning";
        }
        else if(effect == "lightning" && (string)targ->query_effect() == "poison")
        {
            effect = "lightningandpoison";

            set_name("swirling noxious mass of fire and lightning");

            set_id(({"mass", "swirling mass of fire", "swirling mass", 
            "swirling mass of fire and lightning", "swirling mass of lightning", 
            "noxiousmass", "hhouselightcloud"}));
		
            set_short("%^BOLD%^%^BLACK%^S%^BOLD%^%^WHITE%^w%^BOLD%^%^BLACK%^"+
            "i%^BOLD%^%^WHITE%^r%^BOLD%^%^BLACK%^l%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^"+
            "n%^BOLD%^%^WHITE%^g %^BOLD%^%^GREEN%^noxious %^BOLD%^%^BLACK%^m%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^s"+
            "%^BOLD%^%^WHITE%^s%^BOLD%^%^BLACK%^ of %^BOLD%^%^RED%^fire %^BOLD%^%^BLACK%^"+
            "and %^BOLD%^%^YELLOW%^lightning%^RESET%^");

            set_long("%^BOLD%^%^BLACK%^This swirling noxious mass of fire and lightning is very thick and "+
            "almost impenetrable. Flashes of lightning and eruptions of flame pulse out "+
            "from the center of it constantly, as if seeking out life to destroy. "+
            "It is massive and very unstable, capable of causing tremendous amounts of "+
            "damage to anything around it. It is difficult to breath within the mass "+
            "and what air you can grasp is entirely toxic.%^RESET%^");
        }
        else if((string)targ->query_effect() == "lightningandpoison" || 
        (string)targ->query_effect() == "poisonandlightning")
        {
            //makes these clouds dominant - Saide
            me = capitalize(targ->query_short());
            myTarg = capitalize(TO->query_short());
            targ->adjust_potency(potency);
            targ->remove_property("being_absorbed");
            flag = 1;
        }	
        tell_room(ETO, me + "%^BOLD%^%^RED%^ absorbs "+myTarg+
        "%^BOLD%^%^RED%^!! becoming even more powerful!%^RESET%^");
        if(flag)
        {
            TO->remove();
            return;
        }
        else
        {
		
            TO->remove_property("being_absorbed");
            if(objectp(targ)) 
            {
                TO->adjust_potency(targ->query_potency()); 
                targ->remove();
            }
			
        }
    }
    return;
}


						

void heart_beat()
{
    object ob;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    delay--;
    if(!random(5)) 
    {
        do_my_effect();
    }
    if(objectp(ob = present("hhousenoxcloud", ETO)) ||
    objectp(ob = present("hhouselightcloud")) || 
    objectp(ob = present("hhouselightnnoxcloud")) ||
    objectp(ob = present("hhousenoxnlightcloud")) ) 
    {
        if(!TO->query_property("being_absorbed") && ob != TO) 
        {
            ob->set_property("being_absorbed", 1);
            absorb(ob);	
        }
    }	
    if(delay > 0) return;
    delay = 30 + random(31);
    pick_room();
    return;	  
}

