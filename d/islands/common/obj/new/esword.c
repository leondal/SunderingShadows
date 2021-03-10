#include <std.h>
#include <daemons.h>

inherit "/d/common/obj/weapon/scimitar";

int hit_func, wield_func, unwield_func, elec;


void create()
{
    ::create();
    set_id(({ "scimitar","sword","scimitar sword","sword of the elements","element sword","scimitar of the elements","element scimitar"}));

    set_name("%^RESET%^%^CYAN%^Scimitar of the elements%^RESET%^");

    set_short("%^RESET%^%^CYAN%^Scimitar of the elements%^RESET%^");

    set_obvious_short("%^BOLD%^%^WHITE%^A beautifully crafted scimitar%^RESET%^");

    set_long("This beautifully crafted scimitar could have been made by nothing less than a %^MAGENTA%^master %^RESET%^of his"
        " trade. The %^BOLD%^%^WHITE%^elongated blade %^RESET%^has an %^CYAN%^elegant curve %^RESET%^that gives"
        " it a smooth, sexy appearance, while the %^BOLD%^%^WHITE%^edge %^RESET%^itself"
        " has been honed to be so extremely %^BOLD%^%^BLACK%^sharp %^RESET%^that this sword is nothing less than deadly."
        " The %^BOLD%^%^WHITE%^blade %^RESET%^and %^BOLD%^%^WHITE%^hilt assembly %^RESET%^have been crafted so finely that"
        " they balance each other perfectly, granting the wielder a wide range of easy movement. Softly"
        " %^CYAN%^gl%^BOLD%^%^CYAN%^o%^RESET%^%^CYAN%^w%^BOLD%^%^CYAN%^i%^RESET%^%^CYAN%^ng runes %^RESET%^shift in shape along"
        " the edge of the fuller, their ever changing %^BOLD%^%^CYAN%^s%^RESET%^%^CYAN%^h%^BLUE%^a%^BOLD%^%^BLUE%^d"
        "%^RESET%^%^CYAN%^e%^BOLD%^%^CYAN%^s %^RESET%^of %^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^q%^BOLD%^%^CYAN%^ua"
        " %^RESET%^looking much like %^BOLD%^%^WHITE%^sh%^RESET%^i%^BOLD%^%^WHITE%^ft%^RESET%^i%^BOLD%^%^WHITE%^ng"
        " %^BOLD%^%^CYAN%^w%^RESET%^%^CYAN%^at%^BOLD%^%^CYAN%^e%^RESET%^%^CYAN%^r%^BOLD%^%^CYAN%^s %^RESET%^against the"
        " cool %^BOLD%^%^WHITE%^silver %^RESET%^of the %^BOLD%^%^WHITE%^blade. %^RESET%^The hilt itself consists of an"
        " intricate %^BOLD%^%^WHITE%^platinum guardpiece %^RESET%^whose curving ~S~ shape is reminiscent of the %^BOLD%^%^WHITE%^turning w%^RESET%^%^CYAN%^i%^BOLD%^%^WHITE%^nds%^RESET%^, a %^ORANGE%^grip %^RESET%^made of %^ORANGE%^leather"
        " %^RESET%^that is so %^ORANGE%^soft %^RESET%^and %^ORANGE%^supple %^RESET%^that it has the feel of the life-giving"
        " %^ORANGE%^e%^RESET%^a%^ORANGE%^r%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^h%^RESET%^, and a"
        " %^RED%^j%^RED%^e%^YELLOW%^w%^RESET%^%^ORANGE%^e%^CYAN%^l%^BOLD%^%^CYAN%^l%^RED%^e%^RESET%^%^BLUE%^d"
        " %^RESET%^pommel that reflects the %^YELLOW%^light %^RESET%^in a"
        " %^RED%^f%^BOLD%^%^RED%^ie%^RESET%^%^RED%^r%^BOLD%^%^RED%^y %^RESET%^display of %^YELLOW%^c%^RED%^o%^BLUE%^l%^CYAN%^o%^%^MAGENTA%^r.%^RESET%^");

	set_lore("%^BOLD%^Scimitar of the Elements %^RESET%^%^CYAN%^was forged by a %^BOLD%^%^BLACK%^madman %^RESET%^%^CYAN%^who wished to see the elemental"
			 " %^BOLD%^%^RED%^powers combined%^RESET%^%^CYAN%^. It is said that this blade would eventually fall into the hands of a powerful %^BOLD%^E%"
			 "^RESET%^%^MAGENTA%^l%^BOLD%^%^CYAN%^e%^MAGENTA%^m%^RESET%^%^MAGENTA%^en%^CYAN%^t%^BOLD%^%^MAGENTA%^a%^CYAN%^l %^RED%^Re%^CYAN%^a%^BLUE%^v%"
			 "^RESET%^%^CYAN%^e%^BOLD%^%^GREEN%^r%^RESET%^%^CYAN%^, someone capable of combining %^BOLD%^%^WHITE%^I%^CYAN%^c%^WHITE%^e%^RESET%^%^CYAN%^,"
			 " %^BOLD%^Wind%^RESET%^%^CYAN%^, %^BOLD%^%^BLUE%^Water%^RESET%^%^CYAN%^, %^BOLD%^%^RED%^Fire %^RESET%^%^CYAN%^and %^ORANGE%^Earth %^CYAN%^i"
			 "nto one powerful %^BOLD%^%^BLACK%^central force%^RESET%^%^CYAN%^. %^BOLD%^Ryorik Denvir %^RESET%^%^CYAN%^was such a man, a %^BOLD%^%^"
			 "GREEN%^Tracker %^RESET%^%^CYAN%^of %^YELLOW%^Lathander %^RESET%^%^CYAN%^whom was cursed by %^BOLD%^%^BLACK%^Talos %^RESET%^%^CYAN%^and %^B"
			 "OLD%^%^WHITE%^A%^CYAN%^u%^WHITE%^r%^CYAN%^i%^WHITE%^l %^RESET%^%^CYAN%^to become such a Reaver. He had lost his %^BOLD%^%^RED%^love%^RESET%^%^CYAN%^,"
			 "%^WHITE%^Sidara FeLore %^RESET%^%^CYAN%^and was %^BOLD%^%^BLACK%^deceived %^RESET%^%^CYAN%^to believe it was because of %^BOLD%^%^RED%^Sune%^RE"
			 "SET%^%^CYAN%^. United, yet separated the two began to build sects within each elemental temple, attempting to merge the %^BOLD%^%^MAGENTA%"
			 "^planes %^RESET%^%^CYAN%^of %^BOLD%^%^RED%^elemental power%^RESET%^%^CYAN%^, hoping to grant power to %^BOLD%^%^BLACK%^Talos %^RESET%^%^CY"
			 "AN%^that would ascend him to %^BOLD%^%^WHITE%^Greater Godhood %^RESET%^%^CYAN%^and weaken the %^BOLD%^%^RED%^elemental powers %^RESET%^%^C"
			 "YAN%^enough for him to %^RED%^slay %^CYAN%^or %^WHITE%^enslaved%^CYAN%^. A group of %^BOLD%^%^WHITE%^adventurers %^RESET%^%^CYAN%^were able"
			 " to %^RED%^melt %^CYAN%^the i%^WHITE%^c%^CYAN%^y %^BOLD%^%^MAGENTA%^h%^RESET%^%^RED%^e%^BOLD%^%^MAGENTA%^arts the %^RESET%^%^CYAN%^of %^BO"
             "LD%^%^RED%^lovers%^RESET%^%^CYAN%^ blessing them in %^MAGENTA%^unity of marriage %^CYAN%^that they sought for so very long. It is foretold"
             " that one day %^BOLD%^Ryorik %^RESET%^%^CYAN%^will return for his %^BOLD%^%^BLUE%^blade %^RESET%^%^CYAN%^and %^BOLD%^%^WHITE%^Sidara %^RESET%"
             "^%^CYAN%^for her %^BOLD%^%^RED%^bow %^RESET%^%^CYAN%^when the %^YELLOW%^world %^RESET%^%^CYAN%^needs them most for no one has a complete pic"
             "ture of what truly happened, but them.");

    set_property("no curse",1);
    set_property("enchantment",7);

    set_item_bonus("damage bonus",7);
    set_item_bonus("caster level",3);

    set_hit((:TO,"hit_func":));
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));

    elec = 0;
    set_value(150000);

    set_property("quest required","%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("level required",35);
}


int wield_func()
{
    tell_object(ETO,"%^YELLOW%^The energy of the elements surge through you as the sword in your hand comes to life!%^RESET%^");
    tell_room(EETO,"%^CYAN%^"+ETO->QCN+"'s sword seems to surge with life as "+ETO->QS+" takes command of the mighty scimitar!%^RESET%^",ETO);
    return 1;
}


int unwield_func()
{
    if(elec == 1)
    {
        tell_object(ETO,"%^YELLOW%^The surge of electrical energy within the sword dies down as you unwield it.%^RESET%^");
        tell_room(EETO,"%^YELLOW%^The surge of energy within "+ETO->QCN+"'s sword dies down as "+ETO->QS+" unwields it.%^RESET%^",ETO);
        elec = 0;
    }
    else
    {
        tell_object(ETO,"%^CYAN%^You feel a sense of disappointment as you unwield the sword and feel the absence of energy it gave you.%^RESET%^");
        tell_room(EETO,"%^CYAN%^The glowing runes of "+ETO->QCN+"'s sword ebb and finally die down as "+ETO->QS+" unwields the sword.%^RESET%^",ETO);
    }
    return 1;
}


int hit_func(object target)
{
    object ob;

    if(!objectp(ETO)) { return 0; }
    if(!objectp(target)) { target = ETO->query_current_attacker(); }
    if(!objectp(target)) return 0;

    if(random(1000) < 500)
    {
        switch(random(20))
        {
        case 0..4:

            tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETO->QCN+" tightens "+ETO->QP+" grip on the hilt of the sword and hits "+target->QCN+" with a devastating blow!",({target,ETO}));
            tell_object(ETO,"%^RESET%^%^ORANGE%^%^You tighten your grip on the smooth leather of the hilt as you hit "+target->QCN+" with a devastating blow!%^RESET%^",({EETO,target}));
            tell_object(target, "%^RESET%^%^ORANGE%^"+ETO->QCN+" tightens the grip on "+ETO->QP+" sword and hits you with a devestating blow!%^RESET%^",({EETO,ETO}));
            return roll_dice(4,18)+3;

        case 5:

            tell_room(EETO,"%^RESET%^%^ORANGE%^"+ETO->QCN+" strikes "+target->QCN+" with earthshaking force that knocks "+target->QO+" off of "+target->QP+" feet!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^RESET%^%^ORANGE%^The grip of the sword lends you strength as you hit "+target->QCN+" with earthshaking force that knocks "+target->QO+" off of "+target->QP+" feet!%^RESET%^",({EETO,target}));
            tell_object(target,"%^RESET%^%^ORANGE%^The sword in "+ETO->QCN+"'s hand hits you so hard that it knocks you off of your feet!%^RESET%^",({EETO,ETO}));
            target->set_paralyzed(20,"You are still trying to stand!");
            return roll_dice(4,10)+5;

        case 6..10:

            ETO->execute_attack();
            tell_room(EETO,"%^BOLD%^%^WHITE%^The platinum hilt of "+ETO->QCN+"'s sword begins to glow as "+ETO->QS+" picks up the speed of the winds and whirls the sword quickly around to strike "+target->QCN+" again!",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^WHITE%^The hilt of your sword begins to glow slightly as you pick up the speed of the winds and whirl the sword around to hit "+target->QCN+" again!%^RESET%^",({EETO,target}));
            tell_object(target, "%^BOLD%^%^WHITE%^The hilt of "+ETO->QCN+"'s sword begins to glow as "+ETO->QS+" spins the sword around to attack you again!%^RESET%^",({EETO,ETO}));
            return roll_dice(4,18)+1;

        case 11:

            tell_room(EETO,"%^BOLD%^%^WHITE%^As "+ETO->QCN+" brings the sword down in a graceful arc, the pommel catches the %^YELLOW%^light %^WHITE%^and reflects it at "+target->QCN+" in a %^YELLOW%^dazzling %^WHITE%^display of %^YELLOW%^blinding %^WHITE%^light!",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^WHITE%^As you swing the sword down in a graceful arc, the pommel catches the %^YELLOW%^light %^WHITE%^and reflects it at "+target->QCN+" in a %^YELLOW%^blinding flash %^WHITE%^of %^YELLOW%^light!%^RESET%^",({EETO,target}));
            tell_object(target, "%^BOLD%^%^WHITE%^As "+ETO->QCN+" brings the sword down in a graceful arc, the pommel catches the %^YELLOW%^light %^WHITE%^and reflects it at you in a %^YELLOW%^blinding flash %^WHITE%^of %^YELLOW%^light!",({EETO,ETO}));
            target->set_paralyzed(20,"You are trying to get to your feet.");
            if(!random(3)) target->set_blind(1);
            else target->set_paralyzed(3+random(4), "%^YELLOW%^You are still trying to recover from the blinding light!");
            break;

        case 12..14:

            tell_room(EETO,"%^BOLD%^%^CYAN%^The runes of "+ETO->QCN+"'s sword begin to shift in form as a soothing flow of energy pulses into "+ETO->QO+".",ETO);
            tell_object(ETO,"%^BOLD%^%^CYAN%^The runes of your sword begin to shift in form as a soothing flow of energy pulses into you.%^RESET%^",({EETO,target}));
            ETO->do_damage("torso",-(random(50)+50));
            break;

        case 15..19:

            if(EETO->query_property("indoors") && elec == 0)
            {
                tell_room(EETO,"%^YELLOW%^"+ETO->QCN+"'s sword seems to suck up the energy from around it before firing it violently towards "+target->QCN+"!",({target,ETO}));
                tell_object(ETO,"%^YELLOW%^Your sword seems to suck up the energy from around it before firing it violently towards "+target->QCN+"!%^RESET%^",({EETO,target}));
                tell_object(target, "%^YELLOW%^"+ETO->QCN+"'s sword seems to suck up the energy around it before firing it violently towards you!%^RESET%^",({EETO,ETO}));
                return roll_dice(4,10)+1;
            }
            else if(!EETO->query_property("indoors") && elec == 0)
            {
                tell_room(EETO,"%^RESET%^CYAN%^The runes of "+ETO->QCN+"'s sword begin to shift into a liquid form as the %^BOLD%^%^BLACK%^clouds %^RESET%^%^CYAN%^above begin to swirl and take form, sending a %^YELLOW%^bolt of lightning %^RESET%^%^CYAN%^down into the sword, %^YELLOW%^electrifying %^RESET%^%^CYAN%^it!",ETO);
                tell_object(ETO,"%^RESET%^%^CYAN%^The runes of your sword begin to shift into a liquid form as the %^BOLD%^%^BLACK%^clouds %^RESET%^%^CYAN%^above begin to swirl and take form, sending a %^YELLOW%^bolt of lightning %^RESET%^%^CYAN%^into the sword, %^YELLOW%^electrifying %^RESET%^it!",({EETO,target}));
                elec = 1;
            }
            else
            {
                switch(random(3))
                {
                case 0:

                    tell_room(EETO,"%^YELLOW%^"+ETO->QCN+"'s sword crackles with electrical energy as it strikes "+target->QCN+"!",({target,ETO}));
                    tell_object(ETO,"%^YELLOW%^Your sword crackles with electrical energy as it hits "+target->QCN+"!%^RESET%^",({EETO,target}));
                    tell_object(target, "%^YELLOW%^"+ETO->QCN+"'s sword crackles with electrical energy as it strikes you!%^RESET%^",({EETO,ETO}));
                    return roll_dice(6,10)+1;

                case 1:

                    tell_room(EETO,"%^YELLOW%^A loud %^WHITE%^POP %^YELLOW%^can be heard as "+ETO->QCN+"'s sword strikes "+target->QCN+", causing small surges of electrical energy to dance along the blade!",({target,ETO}));
                    tell_object(ETO,"%^YELLOW%^A loud %^WHITE%^POP %^YELLOW%^can be heard as you strike "+target->QCN+" with the sword, causing small surges of electrical energy to dance along the length of the blade!%^RESET%^",({EETO,target}));
                    tell_object(target, "%^YELLOW%^A loud %^WHITE%^POP %^YELLOW%^ can be heard coming from "+ETO->QCN+"'s sword as it strikes you, causing small surges of electrical energy to dance along the length of the blade!%^RESET%^",({EETO,ETO}));
                    return roll_dice(6,10)+1;

                case 2:

                    tell_room(EETO,"%^YELLOW%^The pent up energy in "+ETO->QCN+"'s sword comes to a crest at the tip of the blade before shooting out at "+target->QCN+" in a forceful explosion of power before the sword once again goes quiet!",({target,ETO}));
                    tell_object(ETO,"%^YELLOW%^The pent up energy in the sword seems to gather at the tip of the blade and suddenly shoots out at "+target->QCN+" in a forceful explosion of power before the sword once again goes quiet!%^RESET%^",({EETO,target}));
                    tell_object(target, "%^YELLOW%^The pent up energy of "+ETO->QCN+"'s sword seems to crest at the tip of the sword before shooting out towards you in a forceful explosion of power before the blade once again goes quiet!%^RESET%^",({EETO,ETO}));
                    elec = 0;
                    return roll_dice(9,10)+1;
                }
            }
        }
    }
}
