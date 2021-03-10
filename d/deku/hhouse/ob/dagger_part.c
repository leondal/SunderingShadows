#include <std.h>
#include <move.h>
#include "../inherits/area_stuff.h"
inherit OBJECT;

void create() 
{
    ::create();
    set_name("a fragment of the dagger");
    set_value(0);
    set_weight(1);
	
    set_id(({"fragment"}));    
    set_short("dagger fragment");
    set_long("dagger fragment");
}

void choose_piece(int which)
{
    if(!objectp(TO)) return;
    if(!intp(which)) return;
    if(which < 1) which = 1;
    if(which > 3) which = 3;
    switch(which)
    {
        case 1:
            set_id(({"dagger hilt", "hilt", "hhousedaghilt"}));
		
            set_short("%^BOLD%^%^RED%^a small hilt%^RESET%^");

            set_long("%^BOLD%^%^RED%^This small dark red metallic object is "+
            "the hilt of what might have once been a majestic dagger. "+
            "It curves at the bottom slightly before meeting a brilliant "+
            "red stone that seems to serve as the pommel. It has several "+
            "grooves that extend the length of it to help provide extra "+
            "grip to whoever might have once wielded the entire dagger."+
            " If you found the crossguard and the blade, you could "+
            "probably <%^BOLD%^%^WHITE%^assemble%^BOLD%^%^CYAN%^> it.%^RESET%^");
            break;
        case 2:
            set_id(({"crossguard", "dagger crossguard", "hhousedagcrossguard"}));
		
            set_short("%^BOLD%^%^BLACK%^a dark crossguard%^RESET%^");

            set_long("%^BOLD%^%^BLACK%^This small dark piece of metal "+
            "looks like it was once the crossguard on what might have been "+
            "a majestic dagger. It is covered in small intricate symbols that "+
            "seem to constantly move about on their own. It splits on "+
            "either end and curves up and down to form razor sharp points that "+
            "are a much %^BOLD%^%^WHITE%^lighter%^BOLD%^%^BLACK%^ hue.  If you found "+
            "the hilt and the blade, you could "+
            "probably <%^BOLD%^%^WHITE%^assemble%^BOLD%^%^CYAN%^> it.%^RESET%^");

            break;
        case 3:
            set_id(({"blade", "dagger blade", "hhousedagblade"}));

            set_short("%^BOLD%^%^CYAN%^an iridescent blade%^RESET%^");

            set_long("%^BOLD%^%^CYAN%^This small razor sharp blade is magnificent! "+
            "It almost seems to reflect light and change colors depending on the "+
            "angle at which you view it. There is one constant though, which is the "+
            "depiction of a round orb in the center of it that is a much darker "+
            "red color with what almost looks like a wave of energy radiating out"+
            "ward from it. If you found the hilt and the crossguard, you could "+
            "probably <%^BOLD%^%^WHITE%^assemble%^BOLD%^%^CYAN%^> it.%^RESET%^");
            break;
    }
}

void init()
{
    ::init();   
    add_action("assemble_act", "assemble");
}

int assemble_act(string what) 
{
    object ob1,ob2,ob3, ob;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!objectp(ETO)) return 0;
    if (ETO->query_bound() || ETO->query_unconscious() || ETO->query_paralyzed()) 
    {
        ETO->send_paralyzed_message("info",ETO);
        return 1;
    }
    if(!objectp(ob1 = present("hhousedaghilt", ETO))) 
    {
        tell_object(ETO, "%^BOLD%^%^RED%^You are missing the hilt of the dagger!%^RESET%^");
        return 1;
    }
    if(!objectp(ob2 = present("hhousedagcrossguard", ETO)))
    {
        tell_object(ETO, "%^BOLD%^%^RED%^You are missing the crossguard of the dagger!%^RESET%^");
        return 1;
    }
    if(!objectp(ob3 = present("hhousedagblade", ETO)))
    {
        tell_object(ETO, "%^BOLD%^%^RED%^You are missing the blade of the dagger!%^RESET%^");
        return 1;
    }
    ob = new(HHOB+"blood_rite");
    tell_object(ETO, "%^BOLD%^%^BLUE%^You quickly and easily assemble "+ob->query_short()+"!%^RESET%^");
    if(!ETO->query_invis())
    {
        tell_room(TO, ETOQCN+"%^BOLD%^%^BLUE%^ quickly and easily assembles "+ob->query_short()+"!%^RESET%^",ETO);
    }
    if(ob->move(ETO) != MOVE_OK)
    {
        tell_object(ETO, "%^BOLD%^%^RED%^You drop "+ob->query_short()+"!%^RESET%^");
        ob->move(EETO);
    }
    if(objectp(ob1) && ob1 != TO) ob1->remove();
    if(objectp(ob2) && ob2 != TO) ob2->remove();
    if(objectp(ob3) && ob3 != TO) ob3->remove();
    TO->remove();
    return 1;
}		
