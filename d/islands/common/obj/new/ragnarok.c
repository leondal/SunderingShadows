//Coded by Bane//
//Revamped by Ares
#include <std.h>
#include <daemons.h>

inherit "/d/common/obj/weapon/bastard.c";

int COUNTER,FLAG;
string owner;


void create()
{
    ::create();
    set_id(({"sword","bastard sword","ragnarok","Ragnarok"}));
    set_name("%^RED%^Ragnarok");

    set_obvious_short("%^BOLD%^%^BLACK%^an %^RED%^ominous%^BLACK%^ sword as black as co%^RED%^a%^BLACK%^l%^RESET%^");

    set_short("%^BOLD%^%^BLACK%^R%^RESET%^%^RED%^a%^BOLD%^g%^BLACK%^n%^RESET%^%^RED%^a"
        "%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^o%^BOLD%^%^RED%^k%^BLACK%^ - Destroyer of Worlds%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^An %^RED%^a%^BLACK%^st%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^"
       "n%^RED%^i%^BLACK%^sh%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^ng %^RESET%^%^RED%^a%^BOLD%^"
       "u%^RESET%^%^RED%^r%^BOLD%^a %^BLACK%^of terrible %^RED%^po%^RESET%^%^RED%^w%^BOLD%^"
       "er %^BLACK%^radiates from this r%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^m%^RED%^a%^BLACK%^"
       "rk%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^bl%^RESET%^%^RED%^e %^BOLD%^%^BLACK%^sw%^RED%^o"
       "%^BLACK%^rd. Its double-edged coal black blade is wrought with %^RED%^gl%^RESET%^"
       "%^RED%^o%^BOLD%^w%^RESET%^%^RED%^i%^BOLD%^ng %^RESET%^%^RED%^d%^BOLD%^e%^BLACK%^m"
       "%^RED%^o%^BLACK%^n%^RESET%^%^RED%^i%^BOLD%^c r%^RESET%^%^RED%^u%^BOLD%^%^BLACK%^"
       "n%^RESET%^%^RED%^e%^BOLD%^s %^BLACK%^that p%^RESET%^%^RED%^u%^BOLD%^%^BLACK%^ls"
       "%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^te and cr%^RED%^a%^BLACK%^ckl%^RED%^e%^BLACK%^ "
       "as if in anticipation of %^RED%^violence%^BLACK%^. Traveling up the center of the "
       "blade is the %^RED%^cr%^RESET%^%^RED%^i%^BOLD%^ms%^RESET%^%^RED%^o%^BOLD%^n "
       "%^BLACK%^line of the %^RESET%^%^RED%^blood %^BOLD%^%^BLACK%^groove, ve%^RED%^i"
       "%^BLACK%^ns of it branching off throughout the flat on both sides. The blade flows "
       "smoothly into the j%^RED%^a%^BOLD%^%^BLACK%^gg%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^d "
       "gu%^RED%^a%^BOLD%^%^BLACK%^rd which has been forged in the semblance of a %^RESET%^"
       "%^RED%^l%^BOLD%^ee%^RESET%^%^RED%^r%^BOLD%^i%^RESET%^%^RED%^n%^BOLD%^g d%^RESET%^"
       "%^RED%^e%^BOLD%^%^BLACK%^m%^RESET%^%^RED%^o%^BOLD%^n%^RESET%^%^RED%^i%^BLACK%^"
       "%^BOLD%^c v%^RED%^i%^BLACK%^s%^RED%^a%^BLACK%^g%^RED%^e%^BLACK%^. A smoky black "
       "essence wafts from its empty eyes and fanged maw. Cool %^RESET%^%^RED%^d%^BOLD%^e"
       "%^RESET%^%^RED%^m%^BOLD%^o%^RESET%^%^RED%^nsk%^BOLD%^i%^RESET%^%^RED%^n %^BLACK%^"
       "%^BOLD%^h%^RED%^i%^BLACK%^d%^RED%^e%^BLACK%^ wraps the hilt providing a "
       "comfortable grip. Resting at the bottom of the hilt, a fractured obs%^WHITE%^i"
       "%^BLACK%^d%^RESET%^i%^BOLD%^%^BLACK%^an orb makes up the pommel, a faint "
       "%^RESET%^%^RED%^red l%^BOLD%^i%^RESET%^%^RED%^ght %^BOLD%^burning %^BLACK%^from "
       "between the web of cracks.%^RESET%^");

    set_lore("This is rumored to be the most destructive weapon ever created. The story goes"
        " the sword was born with the world and its destiny is linked with the end"
        " of the world. The exact metal or maker is not known, but the sword was first"
        " seen in the possession of a demon known as Qualtatoh. Rumors say Klauth"
        " banished the demon from the prime material plane and took the sword as trophy.");

    set_weight(6);
    set_value(1000000);

    set_property("no curse",1);
    set_property("enchantment",7);

    set_property("master weapon",1);

    set_item_bonus("attack bonus",7);
    set_item_bonus("damage bonus",7);

    set_weapon_prof("exotic");

    set_hit((:TO,"strike":));
    set_wield((:TO,"extra_wield":));
    set_unwield((:TO,"removeme":));

    set_heart_beat(1);

    set_property("quest required","%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
}


int extra_wield()
{
    object obj;

    if((string)ETO->query_true_name() != owner && !ETO->query_true_invis())
    {
        tell_object(ETO,"%^BOLD%^The sword begins to vibrate uncontrollably and shakes "
            "free of your grasp!%^RESET%^");
        tell_room(EETO,"%^BOLD%^The sword vibrates out of "+ETO->QCN+"'s hand!%^RESET%^",ETO);
        TO->move(EETO);
        if(obj = present(owner,ETO))
        {
            tell_object(obj,"%^GREEN%^The sword recognizes you as its owner and "
                "skitters across to your hand!%^RESET%^");
            tell_room(environment(obj),"%^GREEN%^The sword skitters across "
                "to "+obj->QCN+"'s hand!",obj);
            TO->move(obj);
            if(obj->query_bound())
            {
                tell_object(obj,"%^YELLOW%^The sword slashes through your bonds!%^RESET%^");
                tell_room(environment(obj),"%^YELLOW%^The sword slashes through "+obj->QCN+"'s "
                    "bonds!%^RESET%^",obj);
                obj->set_bound(0);
            }
        }
        return 0;
    }

    if((int)ETO->query_lowest_level() < 35)
    {
        tell_object(ETO,"%^BOLD%^%^RED%^The sword glows with a demonic light and heats in "
            "your hand.%^RESET%^");
        tell_room(EETO,"%^BOLD%^%^RED%^The sword held by "+ETO->QCN+" begins to glow "
            "with a eerie demonic light!",ETO);
        tell_object(ETO,"%^RED%^A painful voice grates in your mind: %^RESET%^You can "
            "never possess Ragnarok mortal.  YOU ARE WEAK!%^RESET%^");
        tell_room(EETO,"%^BOLD%^"+ETO->QCN+" suddenly stills as "+ETO->QP+" expression "
            "goes blank.%^RESET%^",ETO);
        tell_object(ETO,"%^BOLD%^%^CYAN%^A surge of energy shoots up your arm from "
            "the hilt of the sword and to the base of your skull!%^RESET%^");
        tell_room(EETO,"%^RED%^"+ETO->QCN+" gasps as "+ETO->QP+" body jolts in "
            "agonizing pain!%^RESET%^",ETO);
        tell_object(ETO,"%^BOLD%^%^RED%^Your head throbs with a blinding pain and "
            "you collapse to the ground vomiting!%^RESET%^");
        tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETO->QCN+" collapses to the ground and "
            "starts to vomit uncontrollably!%^RESET%^",ETO);
        tell_object(ETO,"%^BOLD%^The sword is jolted from your hand!%^RESET%^");
        tell_room(EETO,"%^BOLD%^The sword is jolted from "+ETO->QCN+"'s hand!%^RESET%^",ETO);
        ETO->set_paralyzed(25,"%^RED%^You are vomiting too hard to move!%^RESET%^");
        ETO->set_blind(1);
        TO->move(EETO);
        return 0;
    }

    tell_object(ETO,"%^BOLD%^%^BLACK%^The power of the %^RED%^demonic%^BOLD%^%^BLACK%^ "
        "sword surges into your veins, swelling the muscles of your arm and filling you "
        "with an unnatural strength!");
    tell_object(ETO,"%^RED%^You can feel your eyes change and your vision is tinted "
        "a deep red as the essense of the lower planes seeps into your very soul!");
    tell_room(EETO,"%^BOLD%^%^RED%^"+ETO->QCN+"'s muscles swell and "+ETO->QP+" eyes "
        "flash red as "+ETO->QS+" grips the hilt of the blade!",ETO);
    ETO->set_property("evil item",1);
    ETO->set_property("master weapon",1);
    return 1;
}


int removeme()
{
    tell_object(ETO,"%^BOLD%^%^BLUE%^The sword hums for a moment and then grows cool "
        "to the touch as you release the hilt.");
    tell_object(ETO,"%^BOLD%^%^RED%^You blink your eyes as the eerie red "
        "light seeps from your vision.");
    tell_room(EETO,"%^BOLD%^%^GREEN%^"+ETO->QCN+"'s muscles return to normal and the "
        "%^BOLD%^%^RED%^light%^BOLD%^%^GREEN%^ fades from "+ETO->QP+" eyes as "+ETO->QS+" "
        "releases the hilt of the sword.",ETO);
    ETO->set_property("evil item",-1);
    ETO->set_property("master weapon",-1);
    return 1;
}


int strike(object targ)  // It's intentional that more than one special is possible at once
{
    int rand;
    rand = roll_dice(1,10);

    if(!objectp(targ)) { return 0; }
    if(!objectp(ETO))  { return 0; }
    if(!objectp(EETO)) { return 0; }
    if(roll_dice(1,100) > 50) { COUNTER += 2; return roll_dice(1,4); }

    if(rand > 0 && rand < 5) // between 1 and 4 or 40%
    {
        tell_object(ETO,"%^BLUE%^Unholy energy crackles along the blade as you "
            "cleave through "+targ->QCN+"!%^RESET%^");
        tell_object(targ,"%^BLUE%^Unholy energy crackles along the blade "
            "as "+ETO->QCN+" cleaves through you!%^RESET%^");
        tell_room(EETO,"%^BLUE%^Unholy energy crackles along the blade "
            "as "+ETO->QCN+" cleaves through "+targ->QCN+"!%^RESET%^",({ETO,targ}));
        targ->do_damage("torso",roll_dice(3,12));
        COUNTER--;
    }

    if(rand > 2 && rand < 6) // between 3 and 5 or 30%
    {
        tell_object(ETO,"%^BOLD%^%^BLACK%^The %^RED%^o%^BLACK%^rb on the hilt of "
            "the bl%^RED%^a%^BLACK%^de pulsates as it slices through the air causing "
            "the ground to %^RESET%^%^RED%^shudder %^BOLD%^%^BLACK%^and %^RESET%^%^RED%^"
            "crack %^BOLD%^%^BLACK%^beneath "+targ->QCN+"!%^RESET%^");
        tell_object(targ,"%^BOLD%^%^BLACK%^The %^RED%^o%^BLACK%^rb on the hilt of the "
            "bl%^RED%^a%^BLACK%^de pulsates as it slices through the air causing the "
            "ground to %^RESET%^%^RED%^shudder %^BOLD%^%^BLACK%^and %^RESET%^%^RED%^"
            "crack %^BOLD%^%^BLACK%^beneath you!%^RESET%^");
        tell_room(EETO,"%^BOLD%^%^BLACK%^The %^RED%^o%^BLACK%^rb on the hilt of "+ETO->QCN+"'s "
            "bl%^RED%^a%^BLACK%^de pulsates as it slices through the air causing the "
            "ground to %^RESET%^%^RED%^shudder %^BOLD%^%^BLACK%^and %^RESET%^%^RED%^crack "
            "%^BOLD%^%^BLACK%^beneath "+targ->QCN+"!%^RESET%^",({ETO,targ}));
        targ->do_damage("torso",roll_dice(5,10));
        COUNTER--;
    }

    if(rand > 4 && rand < 7) // between 4 and 6 or 20%
    {
        tell_object(ETO,"%^BOLD%^%^RED%^The crackling runes on the %^BLACK%^bl%^RED%^a%^BLACK%^de "
            "%^RED%^flare as it makes contact with "+targ->QCN+" blasting "+targ->QO+" to the "
            "ground!%^RESET%^");
        tell_object(targ,"%^BOLD%^%^RED%^The crackling %^BLACK%^bl%^RED%^a%^BLACK%^de%^RED%^ "
            "wielded by "+ETO->QCN+" flares as it strikes you, blasting you to the ground "
            "with terrifying force!%^RESET%^");
        tell_room(EETO,"%^BOLD%^%^RED%^"+ETO->QCN+"'s crackling %^BLACK%^bl%^RED%^a%^BLACK%^de "
            "%^RED%^flares as it strikes "+targ->QCN+", blasting "+targ->QO+" to the ground "
            "with terrifying force!%^RESET%^",({ETO,targ}));
        targ->set_paralyzed(roll_dice(1,10) + 10, "%^ORANGE%^You are struggling to stand up!%^RESET%^");
        COUNTER--;

    }

    if(rand > 6 && rand < 10) // between 7 and 9 or 20%
    {
        tell_object(ETO,"%^RED%^Striking with unnatural speed you become a "
            "barely discernable maelstrom of violence!%^RESET%^");
        tell_room(EETO,"%^RED%^"+ETO->QCN+"'s body seems to blur before you "
            "as "+ETO->QP+" becomes a barely discernable maelstrom of violence!%^RESET%^",ETO);
        if(sizeof(ETO->query_attackers())) { ETO->execute_attack(); }
        COUNTER--;
    }

    if(rand == 10 && COUNTER > 999) // 10 and counter 1000 or higher
    {
        int i;
        object *living;
        mapping info;
        living = all_living(EETO);
        info = ([ "living"  : living,
                  "eto"     : ETO,
                  "count"   : 0,
                  "special" : ({}),
                  "delay"   : 0,
                  "targ"    : targ,
                  "eeto"    : EETO,
                ]);
        for(i=0;i<sizeof(living);i++)
        {
            living[i]->set_paralyzed(0);
            living[i]->cease_all_attacks();
        }
        call_out("ragnarok_em",2,info);
        COUNTER = 0;
    }

    else if(rand == 10 && COUNTER <= 999) // Blind/Stun if 10 and the counter is not 1000 or higher
    {
        tell_object(ETO,"%^RED%^The demonic eyes of the sword %^BOLD%^blaze%^RESET%^%^RED%^ "
            "with %^BOLD%^%^BLACK%^unholy l%^RED%^i%^BLACK%^ght%^RESET%^%^RED%^ "
            "and "+targ->QCN+" is suddenly %^BOLD%^immolated %^RESET%^%^RED%^by "
            "%^BOLD%^%^BLACK%^crackling black flames%^RESET%^%^RED%^!%^RESET%^");
        tell_object(targ,"%^RED%^The demonic eyes of the sword wielded by "+ETO->QCN+" %^BOLD%^blaze "
            "%^RESET%^%^RED%^with %^BOLD%^%^BLACK%^unholy l%^RED%^i%^BLACK%^ght%^RESET%^%^RED%^ "
            "and the whole world %^BLACK%^%^BOLD%^fades %^RESET%^%^RED%^into a %^BOLD%^%^BLACK%^black "
            "void of searing pain%^RESET%^%^RED%^!%^RESET%^");
        tell_room(EETO,"%^RED%^The demonic eyes of "+ETO->QCN+"'s sword %^BOLD%^blaze%^RESET%^%^RED%^ "
            "with %^BOLD%^%^BLACK%^unholy l%^RED%^i%^BLACK%^ght%^RESET%^%^RED%^ and "+targ->QCN+" is "
            "suddenly %^BOLD%^immolated %^RESET%^%^RED%^by %^BOLD%^%^BLACK%^crackling black "
            "flames%^RESET%^%^RED%^!%^RESET%^",({ETO,targ}));
        targ->set_paralyzed(roll_dice(1,20) + 16, "%^BOLD%^BLACK%^You are overcome by the seering pain!%^RESET%^");
        if(!targ->fort_save(ETO->query_base_character_level())) { targ->set_temporary_blinded(2); }
    }

    return 0;
}


int query_counter()
{
    return COUNTER;
}


void set_counter(int num)
{
    COUNTER = num;
}


void init()
{
    ::init();
    if(!owner || owner == "")
    {
        if(interactive(ETO) && !ETO->query_true_invis())
        {
            owner = ETO->query_true_name();
        }
    }
    if((string)TO->query_weapon_prof() != "exotic") TO->set_weapon_prof("exotic"); // changing to exotic kthx - Nienne.
}


void heart_beat()
{
    if(!objectp(ETO)) { return; }
    if(interactive(ETO) && present("ragnarok 2",ETO))
    {
        tell_object(ETO,"%^RED%^The two swords tremble when brought "
            "together.  In a flash, they merge together into a single "
            "blade!");
        TO->remove();
    }
}


string query_owner() { return owner; }


int ragnarok_em(mapping info)
{
    int i,delay,count;
    object *living,*special,eto,targ,eeto;

    living  = info["living"];
    special = info["special"];
    eto     = info["eto"];
    count   = info["count"];
    eeto    = info["eeto"];
    targ    = info["targ"];
    delay   = info["delay"];

    if(!pointerp(living)) { return 0; }
    if(!objectp(eto))	  { return 0; }
    if(!objectp(eeto))    { return 0; }

    if(!FLAG)
    {
        for(i=0;i<sizeof(living);i++)
        {
            if(!objectp(living[i])) continue;
            if(living[i]->query_property("no paralyze"))
            {
                special += ({ living[i] });
            }
        }
        if(sizeof(special))
        {
            for(i=0;i<sizeof(special);i++)
            {
                if(!objectp(special[i])) continue;
                special[i]->remove_property("no paralyze");
            }
        }

        for(i=0;i<sizeof(living);i++)
        {
            if(!objectp(living[i])) continue;
            if(interactive(living[i]) && !living[i]->query_true_invis())
            {
                living[i]->force_me("cls");
            }
            living[i]->cease_all_attacks();
            living[i]->set_paralyzed(1000,"%^ORANGE%^The violent shaking of the ground makes it "
                "impossible to stand!%^RESET%^");
        }

        tell_object(eto,"%^BOLD%^%^BLACK%^The sword in your hand suddenly blazes to "
            "life, a cr%^RED%^a%^BLACK%^ckl%^RED%^i%^BLACK%^ng %^RED%^cr%^RESET%^%^RED"
            "%^i%^BOLD%^ms%^RESET%^%^RED%^o%^BOLD%^n energy %^BLACK%^suffusing the blade "
            "that sends a %^RED%^shockwave%^BLACK%^ throughout the room hurling those "
            "around you to the ground!. The earth below %^RED%^trembles %^BLACK%^and %^RED%^"
            "cracks%^BLACK%^ as the fractured obsidian orb on the swords pommel pulsates "
            "spilling its %^RED%^unh%^BLACK%^o%^RED%^ly p%^BLACK%^o%^RED%^w%^BLACK%^e%^RED%^r "
            "%^BLACK%^into the air around it.%^RESET%^");

        tell_room(eeto,"%^BOLD%^%^BLACK%^The sword in "+eto->QCN+"'s hand suddenly blazes to life, "
            "a cr%^RED%^a%^BLACK%^ckl%^RED%^i%^BLACK%^ng %^RED%^cr%^RESET%^%^RED%^i%^BOLD%^ms%^RESET%^"
            "%^RED%^o%^BOLD%^n energy %^BLACK%^suffusing the blade that sends a %^RED%^shockwave%^BLACK%^ "
            "throughout the room hurling you to the ground!. The earth below %^RED%^trembles %^BLACK%^and "
            "%^RED%^cracks%^BLACK%^ as the fractured obsidian orb on the swords pommel pulsates spilling "
            "its %^RED%^unh%^BLACK%^o%^RED%^ly p%^BLACK%^o%^RED%^w%^BLACK%^e%^RED%^r %^BLACK%^into the air "
            "around it.%^RESET%^",eto);

        info = ([ "living"  : living,
                  "eto"     : eto,
                  "count"   : 1,
                  "special" : special,
                  "delay"   : 5,
                  "targ"    : targ,
                  "eeto"    : eeto,
                ]);
        FLAG = 1;
        call_out("ragnarok_em",15,info);
        return 0;
    }

    switch(count)
    {
    case 1:

        tell_room(eeto,"%^BOLD%^%^RED%^The eyes of the sword suddenly blaze to life "
            "and an ab%^BLACK%^y%^RED%^ssal howl blasts from its fanged maw shattering "
            "the very fabric of the plane around you like so much glass to reveal the "
            "roiling ma%^BLACK%^e%^RED%^lstr%^BLACK%^o%^RED%^m of what can only be "
            "the%^BLACK%^ Abyss%^RED%^!%^RESET%^");// yes, eto left out intentionally
        tell_em("%^RED%^A tremble passes through the ground beneath "
            "your feet and the air around you takes on a crimson hue as the world "
            "itself seems to groan in protest.%^RESET%^");
        info["count"] = 2;
        call_out("ragnarok_em",15,info);
        return 0;

    case 2:

        tell_object(eto,"%^RED%^Your eyes gleam with %^BOLD%^%^BLACK%^m%^RED%^a%^BLACK%^l%^RESET%^%^RED%^"
            "e%^BOLD%^%^BLACK%^v%^RED%^o%^BLACK%^l%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^nt "
            "%^RED%^e%^BLACK%^n%^RED%^e%^BLACK%^rg%^RED%^y%^RESET%^%^RED%^ as you point the "
            "%^BOLD%^%^BLACK%^unh%^RED%^o%^BLACK%^ly bl%^RED%^a%^BLACK%^de%^RESET%^%^RED%^ "
            "at "+targ->QCN+" and a beam of %^RED%^crimson energy %^RESET%^%^RED%^screams "
            "forth to tear through "+targ->QP+" body!%^RESET%^");
        if(!objectp(targ)) { return 0; }
        tell_object(targ,"%^RED%^"+eto->QCN+"'s eyes gleam with %^BOLD%^%^BLACK%^m%^RED%^a"
            "%^BLACK%^l%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^v%^RED%^o%^BLACK%^l%^RESET%^%^RED%^"
            "e%^BOLD%^%^BLACK%^nt %^RED%^e%^BLACK%^n%^RED%^e%^BLACK%^rg%^RED%^y%^RESET%^%^RED%^ "
            "as "+eto->QP+" points the %^BOLD%^%^BLACK%^unh%^RED%^o%^BLACK%^ly bl%^RED%^a%^BLACK%^"
            "de%^RESET%^%^RED%^ at you and a beam of %^RED%^crimson energy %^RESET%^%^RED%^screams "
            "forth to tear through your body!%^RESET%^");
        tell_room(eeto,"%^RED%^"+eto->QCN+"'s eyes gleam with %^BOLD%^%^BLACK%^m%^RED%^a%^BLACK%^l"
            "%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^v%^RED%^o%^BLACK%^l%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^"
            "nt %^RED%^e%^BLACK%^n%^RED%^e%^BLACK%^rg%^RED%^y%^RESET%^%^RED%^ "
            "as "+eto->QP+" points the %^BOLD%^%^BLACK%^unh%^RED%^o%^BLACK%^ly bl%^RED%^a%^BLACK%^"
            "de%^RESET%^%^RED%^ at "+targ->QCN+" and a beam of %^RED%^crimson energy %^RESET%^%^RED%^"
            "screams forth to tear through "+targ->QP+" body!%^RESET%^",({eto,targ}));
        info["count"] = 3;
        call_out("ragnarok_em",15,info);
        return 0;

    case 3:

        if(!targ->query_property("no death") && !FEATS_D->usable_feat(targ,"death ward"))
        {
            tell_object(eto,"%^BOLD%^%^BLACK%^You feel a dark hunger overcome you as the power of the "
                "sword tears through "+targ->QCN+", flaying "+targ->QP+" soul from "+targ->QP+" body "
                "and sending it tumbling into the Abyss!%^RESET%^");
            if(!objectp(targ)) { return 0; }
            tell_object(targ," %^BOLD%^%^BLACK%^You watch in horror as the beam collides with your "
                "body, piercing to your very soul and flaying it free of its mortal vessel. All becomes "
                "pain as you tumble from your body into the depths of the Abyss, the howling of countless "
                "demons all around as you descend into their waiting talons!%^RESET%^");
            tell_room(eeto,"%^BOLD%^%^BLACK%^You watch in horrified awe as the beam collides "
                "with "+targ->QCN+"'s body and flays the smokey essence of "+targ->QP+" soul from its "
                "mortal vessel sending it tumbling into the Abyss!%^RESET%^",({eto,targ}));
            ETO->set_property("magic",1);
            if(objectp(targ)) targ->do_damage("torso",roll_dice(10000,10000));
            ETO->set_property("magic",-1);
            if(objectp(targ)) targ->die();
        }
        else
        {
            tell_object(eto,"%^RED%^You feel a dark hunger overcome you as the power of the sword "
                "tears through "+targ->QCN+" flaying at "+targ->QP+" very soul!%^RESET%^%^RED%^");
            if(!objectp(targ)) { return 0; }
            tell_object(targ,"%^RED%^You watch in horror as the beam collides with your body, "
                "piercing to your very soul and flaying at the very fabric of your essence!%^RESET%^");
            tell_room(eeto,"%^RED%^You watch in horrified awe as the beam collides "
                "with "+targ->QCN+"'s body the unholy power flaying at "+targ->QP+" very "
                "soul!%^RESET%^",({eto,targ}));
            targ->set_hp(targ->query_max_hp()/10);//a rare special that gives world emotes should knock the target on their a$$ if not outright kill them. -Ts
        }
        info["count"] = 4;
        call_out("ragnarok_em",15,info);
        return 0;

    case 4:

        tell_room(eto,"%^BOLD%^%^RED%^The fractured pieces of the world slowly flow back "
            "into the air, reforming the barrier between planes and leaving only the crackle "
            "of latent demonic energy as a reminder of the breach.%^RESET%^");
        tell_em("%^RED%^The crimson hue fades from the air and the ground "
            "beneath you settles..you feel that something terrible has happened...%^RESET%^");

        for(i=0;i<sizeof(living);i++)
        {
            if(!objectp(living[i])) { continue; }
            living[i]->set_paralyzed(0);
        }
        for(i=0;i<sizeof(special);i++)
        {
            if(!objectp(special[i])) { continue; }
            special[i]->set_property("no paralyze", 1);
        }
    }
    return 0;
}


void tell_em(string str)
{
    int i;
    object *users;
    users = children("/std/user.c");
    for(i=0;i<sizeof(users);i++)
    {
        if(!objectp(users[i])) continue;
        if(!interactive(users[i])) { continue; }
        tell_object(users[i],str);
    }
    return;
}
