#include <std.h>
#include <daemons.h>
#include "/d/deku/inherits/graveyard.h"
inherit MONSTER;

create() {
    ::create();
    set_name("elazo");
    set_id(({"elazo","ghost","spirit"}));
    set_gender("male");
    set_race("human");
    set_short("The spirit of a male human");
    

    set_long("This is the ghostly form of what was once "+
    "a very short and slightly pudgy man.  His body, though "+
    "translucent, still reflects much of the fat that "+
    "was with him in life.  Despite his appearance, something "+
    "about him is entirely awe inspiring, as if in this "+
    "current form such a minute thing as external appearance "+
    "has no bearing.  The eyes of this creature are a very light "+
    "green and shine with an intense kindness that could perhaps "+
    "shake your very core.  He appears supernaturally happy and "+
    "carefree, yet something else that you cannot identify hangs "+
    "over him like a veil.%^RESET%^");

    set_alignment(4);
    set_hd(20);
    set_stats("strength",16);
    set_stats("constitution",1);
    set_stats("wisdom",15);
    set_stats("intelligence",19);
    set_stats("dexterity",20);
    set_stats("charisma",25);
    set("aggressive",0);
    set_overall_ac(10);
    set_hp(400);    
    set_exp(2000);
}


void freed_me(object who) {
    
    force_me("say thank you for freeing me!");
    force_me("emote smiles brilliantly and his face shines with "+
    "an intense light");
    
    force_me("say I have only one thing to offer you.... "+
    "I hope that it serves you as faithfully as it served me "+
    "in life.");

    force_me("emoteat "+who->query_name()+" waves his hands about "+
    "widly and conjures up a single black hammer and "+
    "then tosses it in front of $N!");
        
    new(GY_OBJS+"elazosshieldbreaker")->move(ETO);
    
    
    force_me("say that is all I have to offer... farewell...");

    force_me("emote quickly waves his hands again and blinks out of "+
    "existence!");
    if(objectp(TO)) {
        TO->remove();
    }
}






