#include <std.h>
#define QN query_name()
inherit "/d/common/obj/weapon/battle_axe";
mapping AttackedRaces;

void create() 
{
    ::create();
    set_name("gleaming black battle axe");

    set_id(({"axe", "battle axe", "black axe", "black battle axe", 
    "oblivion"}));
	
    set_obvious_short("%^BOLD%^%^BLACK%^%^BOLD%^%^WHITE%^g%^BOLD%^%^BLACK%^"+
    "l%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^m"+
    "%^BOLD%^%^BLACK%^i%^BOLD%^%^WHITE%^n%^BOLD%^%^BLACK%^g black "+
    "axe%^RESET%^");
			
    set_short("%^BOLD%^%^BLACK%^O%^BOLD%^%^WHITE%^b%^BOLD%^%^BLACK%^l"+
    "%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^v%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^"+
    "o%^BOLD%^%^WHITE%^n%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This battle axe is forged from a solid "+
    "%^BOLD%^%^BLACK%^%^BOLD%^%^WHITE%^g%^BOLD%^%^BLACK%^"+
    "l%^BOLD%^%^WHITE%^e%^BOLD%^%^BLACK%^a%^BOLD%^%^WHITE%^m"+
    "%^BOLD%^%^BLACK%^i%^BOLD%^%^WHITE%^n%^BOLD%^%^BLACK%^g %^BOLD%^%^WHITE%^"+
    "black metal. It looks as if it was forged from a single piece of material. "+
    "The head of it has a blade on either side that has "+
    "been honed down to an almost razor fine %^BOLD%^%^RED%^edge%^BOLD%^"+
    "%^WHITE%^ and each is quite %^BOLD%^%^BLUE%^serrated%^BOLD%^%^WHITE%^. "+
    "The handle has been wrapped with a thick %^RESET%^%^ORANGE%^gold%^BOLD%^"+
    "%^WHITE%^ wire that is in striking contrast to the rest of the axe. "+
    "There are strange %^BOLD%^%^RED%^markings%^BOLD%^%^WHITE%^ down the "+
    "length of the axe that seem to %^BOLD%^%^YELLOW%^fl%^BOLD%^%^WHITE%^i%^BOLD%^%^YELLOW%^"+
    "ck%^BOLD%^%^WHITE%^e%^BOLD%^%^YELLOW%^r%^BOLD%^%^WHITE%^ and fade on their own, before "+
    "reappearing in a different spot. The bottom of the handle mushrooms out and splits "+
    "open into a gaping %^BOLD%^%^RED%^maw%^BOLD%^%^WHITE%^ with rows of what look "+
    "remarkably like %^BOLD%^%^YELLOW%^jagged teeth%^BOLD%^"+
    "%^WHITE%^ lining the %^BOLD%^%^RED%^maw%^BOLD%^%^WHITE%^.%^RESET%^");

    set_value(15000);
    set_property("lore difficulty", 40);

    set_lore("%^BOLD%^%^BLACK%^The legends surrounding this weapon are "+
    "ancient. It is rumored that it was forged by Aur'us Devar sometime before "+
    "he left his mortal shell. One legend that still lingers "+
    "suggests that it grows in power against particular races as it fights "+
    "more of them. The same story goes on to mention that its power "+
    "eventually twists into a seething hatred for that particular race, "+
    "erupting into a dazzling display of power.%^RESET%^");

    //lowered enchantmented - removed negative energy resistance bonus - Saide, April 2017
    set_property("enchantment",4);
    set_item_bonus("strength", 4);
    //set_item_bonus("negative energy resistance", 10);
    set_wield((:TO,"wield_me":));
    set_unwield((:TO,"unwield_me":));
    //set_item_bonus("damage bonus", 3);
    set_hit((:TO,"special":));
    AttackedRaces = ([]);
}

void add_attacked_race(string race)
{
    if(!stringp(race)) return;
    if(!mapp(AttackedRaces)) AttackedRaces = ([]);
    if(member_array(race, keys(AttackedRaces)) != -1)
    {
        AttackedRaces[race]++;
        return;
    }
    AttackedRaces += ([race : 1]);
    return;
}

void remove_attacked_race(string race)
{
    if(!stringp(race)) return;
    if(!mapp(AttackedRaces)) 	
    {
        AttackedRaces = ([]);
        return;
    }
    map_delete(AttackedRaces, race);
    return;
}

int query_race_attacked(string race)
{
    if(!stringp(race)) return 0;
    if(!mapp(AttackedRaces)) 
    {
        AttackedRaces = ([]);
        return 0;
    }
    return AttackedRaces[race];
}

void init()
{
    ::init();
	//add_action("observe_orb", "observe");
}

int wield_me()
{
    if(ETO->query_highest_level() < 25) 
    {
        tell_object(ETO, "%^BOLD%^%^RED%^The axe refuses to submit to "+
        "you!%^RESET%^");
        return 0;
    }
    tell_object(ETO, "%^BOLD%^%^WHITE%^You feel an immense power "+
    "envelope you as you grip the handle of the axe!%^RESET%^");
    return 1;
}

int unwield_me()
{
    tell_object(ETO, "%^BOLD%^%^WHITE%^You feel the immense power "+
    "fade away, leaving a vast emptiness in its place!%^RESET%^");
    return 1;
}

int special(object targ) 
{
    string tlim, tRace;
    int dam, tmp;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(EETO)) return 0;
    if(!objectp(targ)) return 0;
    tRace = (string)targ->query_race();
    add_attacked_race(tRace);	
    tmp = query_race_attacked(tRace);
    if(tmp > 40)
    {
        remove_attacked_race(tRace);
        tmp = 40;
    }
    if(random(1000) < 350 || tmp == 40) 
    {
        tlim = targ->return_target_limb();
        switch(tmp)
        {
            case 0..10:
                dam = roll_dice(1, 8);

                tell_object(ETO, "%^BOLD%^%^WHITE%^Your "+TO->QN+" slices deep into "+
                targ->QCN+"%^BOLD%^%^WHITE%^'s "+tlim+", absorbing %^BOLD%^%^RED%^"+
                "life%^BOLD%^%^WHITE%^ from the wound!%^RESET%^");		
			
                tell_object(targ, ETOQCN+"%^BOLD%^%^WHITE%^'s "+TO->QN+" slices deep "+
                "into your "+tlim+", sucking away at some of your "+
                "%^BOLD%^%^RED%^lifeforce%^BOLD%^%^WHITE%^!%^RESET%^");
	
                tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^'s "+TO->QN+" slices deep "+
                "into "+targ->QCN+"%^BOLD%^%^WHITE%^'s "+tlim+"!%^RESET%^", ({ETO, targ}));
	
                targ->cause_typed_damage(targ, tlim, dam, "negative energy");
                return 0;

            case 11..30:
                dam = roll_dice(2, 6);

                tell_object(ETO, "%^BOLD%^%^GREEN%^Your "+TO->QN+" sinks into "+
                targ->QCN+"%^BOLD%^%^GREEN%^'s "+tlim+" with a %^BOLD%^%^WHITE%^"+
                "sickening thud%^BOLD%^%^GREEN%^, absorbing %^BOLD%^%^RED%^life"+
                "%^BOLD%^%^GREEN%^ from the wound!%^RESET%^");
					
                tell_object(targ, ETOQCN+"%^BOLD%^%^GREEN%^'s "+TO->QN+" sinks into "+
                "your "+tlim+" with a %^BOLD%^%^WHITE%^"+
                "sickening thud%^BOLD%^%^GREEN%^, sucking away at your "+
                "%^BOLD%^%^RED%^lifeforce%^BOLD%^%^GREEN%^!%^RESET%^");

                tell_room(EETO, ETOQCN+"%^BOLD%^%^GREEN%^'s "+TO->QN+" sinks into "+
                targ->QCN+"%^BOLD%^%^GREEN%^'s "+tlim+" with a %^BOLD%^%^WHITE%^"+
                "sickening thud%^BOLD%^%^GREEN%^!%^RESET%^", ({targ, ETO}));

                ETO->set_property("noMissChance", 1);
                targ->cause_typed_damage(targ, tlim, dam, "negative energy");
                ETO->set_property("noMissChance", -1);
                return 0;

            case 31..39:
				dam = roll_dice(2, 4);
			
                tell_object(ETO, "%^BOLD%^%^RED%^Your "+TO->QN+"%^BOLD%^%^RED%^ is buried "+
                "deep in "+targ->QCN+"%^BOLD%^%^RED%^'s "+tlim+" and sucks away "+
                "%^BOLD%^%^CYAN%^life%^BOLD%^%^RED%^ from the wound!%^RESET%^");

                tell_object(targ, ETOQCN+"%^BOLD%^%^RED%^'s "+TO->QN+"%^BOLD%^%^RED%^ buries "+
                "deep in your "+tlim+" and begins eating away at your %^BOLD%^%^CYAN%^"+
                "lifeforce%^BOLD%^%^RED%^!%^RESET%^");

                targ->set_paralyzed(5, "%^BOLD%^%^RED%^The searing pain from the "+TO->QN+
                " eating at your lifeforce is all that you can think about!%^RESET%^");
	
                tell_room(EETO, ETOQCN+"%^BOLD%^%^RED%^'s "+TO->QN+"%^BOLD%^%^RED%^ buries "+
                "deep into "+targ->QCN+"%^BOLD%^%^RED%^'s "+tlim+"!%^RESET%^", ({targ, ETO}));

                ETO->set_property("noMissChance", 1);
                ETO->set_property("magic", 1);
                targ->cause_typed_damage(targ, tlim, dam, "negative energy");
                ETO->set_property("magic", -1);
                ETO->set_property("noMissChance", -1);
                return 0;
			
            case 40:
                dam = roll_dice(2, 4);
                if(!random(1000)) dam = roll_dice(2,50);
				
                tell_object(ETO, "%^BOLD%^%^BLACK%^Your "+TO->QN+"%^BOLD%^%^BLACK%^ "+
                "emits a horrible %^BOLD%^%^RED%^SHRIEKING%^BOLD%^%^BLACK%^ as it "+		
                "sinks into "+targ->QCN+"%^BOLD%^%^BLACK%^!%^RESET%^");

                tell_object(targ, ETOQCN+"%^BOLD%^%^BLACK%^'s "+TO->QN+" emits a "+
                "horrible %^BOLD%^%^RED%^SHRIEKING%^BOLD%^%^BLACK%^ as it "+
                "sinks into you!%^RESET%^");

                tell_object(targ, "%^BOLD%^%^RED%^A voice thunders inside your head"+
                "%^RESET%^: I HATE YOUR KIN!!!! DIE!!!! DIE!!! DIE!!!!%^RESET%^");

                tell_room(EETO, ETOQCN+"%^BOLD%^%^BLACK%^'s "+TO->QN+" emits a "+
                "horrible %^BOLD%^%^RED%^SHRIEKING%^BOLD%^%^BLACK%^ as it "+
                "sinks into "+targ->QCN+"%^BOLD%^%^BLACK%^!%^RESET%^", ({targ, ETO}));

                ETO->set_property("noMissChance", 1);
                ETO->set_property("magic", 1);
                targ->cause_typed_damage(targ, tlim, dam, "negative energy");
                ETO->set_property("magic", -1);
                ETO->set_property("noMissChance", -1);

                tell_object(ETO, "%^BOLD%^%^RED%^A voice thunders inside your head"+
                "%^RESET%^: DON'T STOP HITTING "+targ->QO+" yet!%^RESET%^");
			
                tell_object(ETO, "%^BOLD%^%^WHITE%^Your "+TO->QN+" invigorates you, refreshing "+
                "your life, as it forces you to swing again!%^RESET%^");							
                ETO->heal(dam);
                ETO->execute_attack();
                return 0;
        }
    }
    return 0;
}
