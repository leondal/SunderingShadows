#include <std.h>
#include "../inherits/area_stuff.h"
#define VALIDFORMS ({"dagger", "short sword", "scimitar", "long sword", "two handed sword", "longbow"})
inherit WEAPON;

int MYDELAY;
string MYSTATE;

void create()
{
    ::create();

    set_name("piece of dull blue metal");

    set_id(({ "metal", "dull blue", "piece", "wavering" }));

    set_short("%^BOLD%^%^BLUE%^W%^BOLD%^%^WHITE%^a%^BOLD%^%^BLUE%^"+
    "v%^BOLD%^%^WHITE%^e%^BOLD%^%^BLUE%^r%^BOLD%^%^WHITE%^i%^BOLD%^"+
    "%^BLUE%^n%^BOLD%^%^WHITE%^g%^RESET%^");

    set_obvious_short("%^BOLD%^%^BLUE%^piece of dull blue metal%^RESET%^");

    set_long("%^RESET%^%^BLUE%^This piece of dull blue metal extends almost three feet "+
    "in length and it is giving off a "+
    "strange aura of cold. As if inside it is frozen or it was just pulled from a "+
    "chunk of ice. Strange, unrecognizable %^BOLD%^%^CYAN%^runes%^RESET%^%^BLUE%^ "+
    "are engraved over the entire length of it. The %^BOLD%^%^CYAN%^runes%^RESET%^%^BLUE%^ "+
    "seem to change constantly as if looking for a true form but never finding it. "+
    "The top of it looks almost melted, as if it were stuck quickly into a hot "+
    "forge and then removed before the process of molding was ever actually started. "+
    "An %^BOLD%^%^WHITE%^inscription%^RESET%^%^BLUE%^ near the base of it "+
    "catches your eye.%^RESET%^");

    set_lore("%^RESET%^%^BLUE%^Legend suggest that this item "+
    "was forged long ago for a king who had trouble making up his "+
    "mind. He was raised as a warrior and through years of conflict "+
    "eventually assumed the throne. He needed a weapon yet was never "+
    "satisfied with what was provided to him for very long at all. "+
    "A weaponsmith, knowing this, sought out a powerful mage, whose "+
    "name legend has forgotten, to imbue a weapon with the ability "+
    "to waver and shift, meeting the expectations of the king. "+
    "It is unknown what eventually befell the king or his weapon, but "+
    "if the legends are to be believed, whoever possesses this item can "+
    "simply %^BOLD%^%^CYAN%^will%^RESET%^%^BLUE%^ it into the form they "+
    "prefer. There are suggestions that the weapon is limited in its form, "+
    "it must always remain a blade and the power within it needs time to replenish "+
    "itself once it assumes a different form. It was given the name "+
    "%^BOLD%^%^WHITE%^wavering%^RESET%^%^BLUE%^ to match the personality of "+
    "the king for whom it was forged.%^RESET%^");

    set_read("%^BOLD%^%^WHITE%^Know that your will is your "+
    "most powerful asset. "+
    "You hold in your grasp 'wavering' and with it the ability "+
    "to choose your own instrument of destruction! The magic which "+
    "the wizard imbued wavering with was limited but I have seen "+
    "'wavering' as scimitar and long sword, perhaps there are "+
    "other forms which it can be willed into.%^RESET%^");

    set_language("common");

    set_property("lore difficulty", 40);
    set_size(2);
    set_weight(6);
    set("no curse", 1);
    set_decay_rate(0);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((:TO,"hit_func":));
    set_wc(1,1);
    set_large_wc(1,1);
    set_type("bludgeoning");
    set_weapon_prof("simple");
    set_critical_threat_range(1);
    set_critical_hit_multiplier(2);
    set_damage_type("bludgeoning");
    MYDELAY = 0;
    MYSTATE = "base";
    set_heart_beat(1);
}

void init()
{
    ::init();
    add_action("assume_form", "will");
}

int query_mydelay() { return MYDELAY; }
void set_mystate(string str) { MYSTATE = str; }
void clear_delay() { MYDELAY = 0; }
void heart_beat()
{
    if(!objectp(TO)) return;
    if(!MYDELAY) return;
    if(MYDELAY >= 1)
    {
        MYDELAY --;
    }
    return;
}

int assume_form(string form)
{
    string tmp, col;
    object myOb;
    int x, y;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!living(ETO)) return 0;
    if(!stringp(form))
    {
        tell_object(ETO, "%^BOLD%^%^CYAN%^You must will the weapon to assume "+
        "a form.%^RESET%^");
        return 1;
    }

    if(member_array(form, VALIDFORMS) == -1 || form == MYSTATE)
    {
        tell_object(ETO, "%^BOLD%^%^RED%^You concentrate carefully and feel "+
        TO->query_short() + "%^BOLD%^%^RED%^ begin to warm rapidly for a brief "+
        "moment before it cools back down.%^RESET%^");
        return 1;
    }
    tmp = TO->query_obvious_short();

    if(TO->query_wielded())
    {
        tell_object(ETO, "%^BOLD%^%^RED%^You must first release your hold on "+
        tmp+"!%^RESET%^");
        return 1;
    }

    if(MYDELAY)
    {
        tell_object(ETO, "%^BOLD%^%^RED%^The power within "+tmp+"%^BOLD%^"+
        "%^RED%^ is still recharging!%^RESET%^");
        return 1;
    }

    tell_object(ETO, "%^BOLD%^%^RED%^You concentrate carefully and feel "+
    tmp+ "%^BOLD%^%^RED%^ begin to warm rapidly for a brief moment!%^RESET%^");

    if(!ETO->query_invis())
    {
        tell_room(EETO, ETOQCN+"%^BOLD%^%^RED%^ begins concentrating carefully!%^RESET%^", ETO);
    }

    x = TO->query_size();
    myOb = new(HHOB+"wavering_ob");
    myOb->transform(TO, form);
    if(objectp(myOb)) myOb->remove();
    y = TO->query_size();
    col = "%^BOLD%^%^WHITE%^";
    if(x == y)
    {
        tell_object(ETO, col+"You watch in amazement as "+tmp+col+" responds to your "+
        "%^BOLD%^%^CYAN%^will"+col+" and shifts form, becoming "+
        "a "+TO->query_obvious_short()+col+"!%^RESET%^");

        if(!ETO->query_invis())
        {
            tell_room(EETO, col+"You watch in amazement as "+ETOQCN+col+"'s "+tmp+
            col+"shifts forms, becoming a "+TO->query_obvious_short()+col+"!%^RESET%^", ETO);
        }
    }
    else if(x > y)
    {
        tell_object(ETO, col+"You watch in amazement as "+tmp+col+" responds to your "+
        "%^BOLD%^%^CYAN%^will"+col+" and shrinks, shifting forms to become a "+
        TO->query_obvious_short()+col+"!%^RESET%^");

        if(!ETO->query_invis())
        {
            tell_room(EETO, col+"You watch in amazement as "+ETOQCN+col+"'s "+tmp+col+
            " shrinks, shifting forms to become a "+TO->query_obvious_short()+
            col+"!%^RESET%^", ETO);
        }
    }
    else
    {
        tell_object(ETO, col+"You watch in amazement as "+tmp+col+" responds to your "+
        "%^BOLD%^%^CYAN%^will"+col+" and elongates, shifting forms to become a "+
        TO->query_obvious_short()+col+"!%^RESET%^");

        if(!ETO->query_invis())
        {
            tell_room(EETO, col+"You watch in amazement as "+ETOQCN+col+"'s "+tmp+col+
            " elongates, shifting forms to become a "+TO->query_obvious_short()+
            col+"!%^RESET%^", ETO);
        }
    }
    MYDELAY = 30;
    return 1;
}

int wield_func()
{
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if((int)ETO->query_level() < 25)
    {
        tell_object(ETO, TO->query_short()+"%^BOLD%^%^RED%^ will never yield "+
        "to someone as weak as you!%^RESET%^");
        return 0;
    }
    tell_object(ETO, "%^BOLD%^%^CYAN%^You grasp "+TO->query_short()+"%^BOLD%^%^CYAN%^ "+
    "and feel it submit entirely to your will!%^RESET%^");

    return 1;
}

int unwield_func()
{
    tell_object(ETO, "%^BOLD%^%^CYAN%^You release your hold on "+TO->query_short()+
    "%^BOLD%^%^CYAN%^.%^RESET%^");
    return 1;
}

int hit_func(object targ)
{
    object myOb;
    if (!objectp(targ) || MYSTATE == "base") {
        return 1 + random(6);
    }
    if (random(5)) {
        return 0;
    }
    myOb = new(HHOB + "wavering_ob");
    myOb->special_attack(TO, targ, MYSTATE);
    return 1;
}
