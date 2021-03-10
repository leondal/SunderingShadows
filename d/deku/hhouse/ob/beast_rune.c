#include <std.h>
#include "../inherits/area_stuff.h"
inherit OBJECT;
int health;

void create() 
{
    ::create();
    set_name("a glowing rune");
    set_value(0);
    set_weight(10000);
	
    set_id(({"rune", "glowing rune", "strange rune"}));
    set_property("no animate", 1);

    set_short("%^BOLD%^%^CYAN%^A gl%^BOLD%^%^WHITE%^o%^BOLD%^%^CYAN%^w"+
    "%^BOLD%^%^WHITE%^i%^BOLD%^%^CYAN%^ng and p%^BOLD%^%^WHITE%^u%^BOLD%^%^CYAN%^"+
    "ls%^BOLD%^%^WHITE%^a%^BOLD%^%^CYAN%^t%^BOLD%^%^WHITE%^i%^BOLD%^%^CYAN%^ng r%^BOLD%^"+
    "%^WHITE%^u%^BOLD%^%^CYAN%^n%^BOLD%^%^WHITE%^e%^RESET%^");

    set_long("%^BOLD%^%^CYAN%^This rune is covered in "+
    "words written in an ancient, forgotten language. It stands "+
    "nearly six feet tall. It glows and pulsates constantly and "+
    "visible waves of power pulsate outwards from it unwaveringly, "+
    "seemingly feeding the beast it is within. You have the "+
    "urge to %^BOLD%^%^WHITE%^<%^BOLD%^%^RED%^smash%^BOLD%^%^WHITE%^> "+
    "%^BOLD%^%^CYAN%^it and you think that you must, if you have "+
    "any hope of surviving.%^RESET%^");

    health = 155 + random(45);
}

void init()
{
    ::init();   
    add_action("smash_function","smash");
}

int smash_function(string what) 
{
    int dam;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(TP)) return 0;
    if(!stringp(what)) return 0;
    if(TO != present(what, ETO)) return 0;
    if (TP->query_bound() || TP->query_unconscious() || TP->query_paralyzed()) 
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    dam = roll_dice(3, 8)+10;
    health -= dam;
    if(health > 0) 
    {
        tell_object(TP, "%^BOLD%^%^RED%^You use all of your strength and try to "+
        "smash the rune, but it does not break!%^RESET%^");

        tell_room(ETO, TPQCN+"%^BOLD%^%^RED%^ uses of all "+TP->QP+" strength and "+
        "tries to smash the rune, but it does not break!%^RESET%^", TP);

        TP->set_paralyzed(5, "%^BOLD%^%^RED%^You are busy trying to smash the rune!%^RESET%^");
        return 1;
    }
    else
    {
        tell_object(TP, "%^BOLD%^%^RED%^You use all of your strength and "+
        "with a %^BOLD%^%^YELLOW%^TH%^BOLD%^%^BLACK%^U%^BOLD%^%^YELLOW%^ND"+
        "%^BOLD%^%^BLACK%^E%^BOLD%^%^YELLOW%^R%^BOLD%^%^BLACK%^I%^BOLD%^%^YELLOW%^"+
        "NG%^BOLD%^%^BLACK%^ BOOM%^BOLD%^%^RED%^ the rune shatters!%^RESET%^");

        tell_room(ETO, TPQCN +"%^BOLD%^%^RED%^ uses all of "+TP->QP+" strength "+
        "and with a %^BOLD%^%^YELLOW%^TH%^BOLD%^%^BLACK%^U%^BOLD%^%^YELLOW%^ND"+
        "%^BOLD%^%^BLACK%^E%^BOLD%^%^YELLOW%^R%^BOLD%^%^BLACK%^I%^BOLD%^%^YELLOW%^"+
        "NG%^BOLD%^%^BLACK%^ BOOM%^BOLD%^%^RED%^ the rune shatters!%^RESET%^", TP);
        ETO->vomit();
        TO->remove();
    }
    return 1;
}		

int get() { return 0; }