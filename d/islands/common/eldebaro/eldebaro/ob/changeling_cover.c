#include <std.h>
#include "../area_stuff.h"
#define VALIDFORMS ({"plate", "chain", "hide"})
inherit ARMOUR;

int MYDELAY;
string MYSTATE;

void create()
{
    ::create();

    set_name("malleable substance");

    set_id(({ "substance", "malleable substance", "changeling armor", 
    "armor", "strange substance", "changeling cover", "dark orange armor", 
    "orange armor"}));

    set_short("%^RESET%^%^ORANGE%^C%^BOLD%^%^WHITE%^h%^RESET%^%^ORANGE%^"+
    "a%^BOLD%^%^WHITE%^n%^RESET%^%^ORANGE%^g%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^"+
    "l%^BOLD%^%^WHITE%^i%^RESET%^%^ORANGE%^n%^BOLD%^%^WHITE%^g %^RESET%^%^ORANGE%^"+
    "C%^BOLD%^%^WHITE%^o%^RESET%^%^ORANGE%^v%^BOLD%^%^WHITE%^e%^RESET%^%^ORANGE%^r"+
    "%^RESET%^");

    set_obvious_short("%^RESET%^%^ORANGE%^strange malleable substance%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^This strange object is a dark orange hue. It is "+
    "composed of a thick malleable substance that is unlike anything that you have "+
    "ever seen. Holding it is a challenge as it seems as if it wants to drip through "+
    "your fingers, in fact you think it is almost a liquid, but for whatever reason it "+
    "remains mostly solid and stable. There is an intensely powerful magic radiating out "+
    "from it that bestows a feeling of warmth and comfort on any who observe it, albeit "+
    "only for a moment. There seems to be %^BOLD%^%^CYAN%^writing%^RESET%^%^ORANGE%^ "+
    "on it that changes both location and script frequently.%^RESET%^");

    set_lore("%^RESET%^%^ORANGE%^This object is referred to as a changeling cover. "+
    "It was thought of as nothing more than a strange rumor until now. It is said to be "+
    "a suit of powerful armor, but malleable enough to morph into whatever type of armor the "+
    "possessor needed. Some say that it takes on different properties depending on the type of "+
    "armor that it becomes... some suggest that it is as powerful as a suit of chain mail, "+
    "as sturdy as a suit of fullplate, or as flexible as a set of hide. However, who knows "+
    "what truth there might be in any such legends.%^RESET%^");

    set_read("%^RESET%^%^ORANGE%^You hold a legend, something forged in secrecy "+
    "so long ago that the process, the creator, and even the result has almost been "+
    "forgotten. You hold the changeling cover... consider yourself lucky, for I, was "+
    "the last to see such a powerful object and even I am gone now. Simply morph "+
    "it into the type of armor that you need and behold the power of it!%^RESET%^");

    set_language("common");

    set_property("lore difficulty", 40);
    set_size(2);
    set_weight(4);
    set("no curse", 1);
    set_decay_rate(0);
    set_wear((:TO,"wearme":));
    set_remove((:TO,"removeme":));
    set_struck((:TO, "strike_func":));
    set_max_dex_bonus(8);
    set_armor_prof("light");
    set_type("armour");
    set_limbs( ({ "torso" }) );
    set_ac(4);
    MYDELAY = 0;
    MYSTATE = "base";
    set_heart_beat(1);
}

void init()
{
    ::init();
    add_action("assume_form", "morph");
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
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!living(ETO)) return 0;
    if(!stringp(form)) 
    {
        tell_object(ETO, "%^RESET%^%^ORANGE%^You must choose a form for the "+
        "changeling cover to morph into!%^RESET%^");
        return 1;
    }
    
    if(member_array(form, VALIDFORMS) == -1 || form == MYSTATE || MYDELAY)
    {
        tell_object(ETO, "%^BOLD%^%^YELLOW%^You concentrate carefully and feel "+
        TO->query_short() + "%^BOLD%^%^YELLOW%^ begin to change.... but then suddenly "+
        "it stops!");
        return 1;
    }
    tmp = TO->query_obvious_short();

    if(TO->query_worn()) 
    {
        tell_object(ETO, "%^BOLD%^%^YELLOW%^You must remove "+tmp+"%^BOLD%^%^YELLOW%^ "+
        "before morphing it into anything!%^RESET%^");
        return 1;
    }

    tell_object(ETO, "%^BOLD%^%^YELLOW%^You concentrate carefully and feel "+
    tmp+ "%^BOLD%^%^YELLOW%^ beginning to change!%^RESET%^");

    if(!ETO->query_invis()) 
    {
        tell_room(EETO, ETOQCN+"%^BOLD%^%^YELLOW%^ begins concentrating carefully!%^RESET%^", ETO);
    }

    myOb = new(ELOB+"changeling_object");
    myOb->transform(TO, form);	
    if(objectp(myOb)) myOb->remove();
    TO->set_size((int)ETO->query_size());
    col = "%^BOLD%^%^WHITE%^";
    tell_object(ETO, col+"You watch in amazement as "+tmp+col+" morphs, changing into "+
    "a "+TO->query_obvious_short()+col+" perfectly fitted for you!%^RESET%^");
    
    if(!ETO->query_invis()) 
    {
        tell_room(EETO, col+"You watch in amazement as "+ETOQCN+col+"'s "+tmp+
        col+" morphs, changing into a "+TO->query_obvious_short()+col+"!%^RESET%^", ETO);      
    }
    MYDELAY = 900;
    return 1;
}

int wearme()
{
    if(MYSTATE == "base")
    {
        tell_object(ETO, "%^BOLD%^%^YELLOW%^You can find no way to wear the "+
        TO->query_short()+"!%^RESET%^");
        return 0;
    }
    if(ETO->query_highest_level() < 35) 
    {
        tell_object(ETO, "%^BOLD%^%^YELLOW%^You are far too weak to wear such a "+
        "powerful object!%^RESET%^");
        return 0;
    }
    tell_object(ETO, "%^RESET%^%^ORANGE%^You feel power encompass you as you "+
    "don the armor!%^RESET%^");
	return 1;
}
	
int removeme()
{
    tell_object(ETO, "%^RESET%^%^ORANGE%^You feel the power quickly ebb away "+
    "as you remove the armor.%^RESET%^");
	return 1;
}

int strike_func(int damage, object what, object who)
{
    object myOb;
    if(!objectp(ETO) || MYSTATE == "base" || !objectp(who)) return damage;
    if(random(200) < 170) return damage;
    myOb = new(ELOB+"changeling_object");
    return myOb->special_attack(TO, who, MYSTATE, damage);    
}

int is_metal() { return 0; }