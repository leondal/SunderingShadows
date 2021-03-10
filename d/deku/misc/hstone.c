#include <std.h>

inherit "/std/Object.c";

int use_it, use, num;

void create() 
{
    ::create();
    set_name("white polished stone");
    set_id(({"stone","healing stone", "white stone", "polished stone", 
    "smooth stone", "stone of invigoration"}));
    
    set_obvious_short("white polished stone");
    
    if(random(2)) 
    {
        set_short("%^BOLD%^%^WHITE%^Stone of Inv%^CYAN%^i%^WHITE%^"+
        "g%^CYAN%^o%^WHITE%^r%^CYAN%^a%^WHITE%^t%^CYAN%^io%^WHITE%^"+
        "n%^RESET%^");
    }
    else
    {
        set_short("%^BOLD%^%^WHITE%^H%^CYAN%^ea%^WHITE%^l%^CYAN%^"+
        "i%^WHITE%^ng St%^CYAN%^o%^WHITE%^n%^CYAN%^e%^RESET%^");
    }
    
    set_long("%^BOLD%^%^WHITE%^This small stone has been polished "+
    "to the point of being exceptionally smooth and having an almost "+
    "crystalline appearance. It is a simply white hue, but somehow "+
    "has no flaws that would normally be apparent in a natural mineral. "+
    "You think that this stone was somehow created or at least changed. "+
    "You also get the urge to <%^CYAN%^rub stone%^BOLD%^%^WHITE%^> and "+
    "think that perhaps this explains why it is so polished.%^RESET%^");

    set_property("lore difficulty", 15);
    set_lore("%^BOLD%^%^WHITE%^These stones have had many names throughout "+
    "history. Some refer to them simply as 'healing stones' others refer to them as "+
    "'stones of invigoration'. The creator of them has been lost, but what is "+
    "known is that they were created from a specific type of mineral, the mineral "+
    "was somehow purified, much like what a blacksmith might do. After this purification "+
    "process the mineral was imbued with a powerful renewing magic, that was said to "+
    "increase stamina as well as health simply by holding the stone and rubbing it."+
    "%^RESET%^");
    
    set_weight(5);
    set_value(20);
    num = 0;
    use = 10 + random(11);
}

void init() 
{
    ::init();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(living(ETO)) 
    {
        add_action("rub_it","rub");
    }
}

int rub_it(string str) 
{
    int i;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!str) 
    {
        tell_object(ETO, "What are you trying to rub here?");
        return 1;
    }
    if (ETO->query_bound() || ETO->query_unconscious()) 
    {
        ETO->send_paralyzed_message("info",TP);
        return 1;
    }
    if(!TO->id(str) || use < 1)
    {
        tell_object(ETO,"You start rubbing "+str+" but nothing happens?");
        return 1;
    }
    if(num == 1) 
    {
        tell_object(ETO, "%^GREEN%^The stone feels warm to the touch, like it's working already.");
        return 1;
    }
    tell_object(ETO, "%^GREEN%^You start rubbing the stone and it becomes warm to the touch.");
    if(!ETO->query_invis())
    {
        if(objectp(EETO)) { tell_room(EETO, ETOQCN+"%^BOLD%^%^GREEN%^ starts rubbing a smooth white stone.%^RESET%^", ETO); }
    }
    call_out("do_heal", 4 + random(7), ETO);
    num = 1;
    return 1;
}

void do_heal(object tp)
{
    if(!objectp(tp))  return;
    if(!objectp(TO))  return;
    tp->heal(roll_dice(6,12));
    tp->use_stamina(-roll_dice(4,10));
    tell_object(tp, "%^GREEN%^The stone becomes cool again.");
    num = 0;
    use -= 1;
    if(!use) 
    {
        tell_object(tp, "%^GREEN%^The stone become cold real quick and you watch as it crumbles to "+
        "%^WHITE%^dust%^GREEN%^ and blows away!%^RESET%^");
        if(objectp(EETO)) 
        {
                tell_room(EETO, "%^GREEN%^A smooth white stone held by "+tp->QCN+"%^GREEN%^ crumbles to "+
                "%^WHITE%^dust%^GREEN%^ and blows away!%^RESET%^", tp);
        }
        TO->remove();
        return 1;
    }
}
