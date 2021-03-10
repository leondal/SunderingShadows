#include <std.h>
#include <daemons.h>
#include "/d/deku/inherits/graveyard.h"
inherit MONSTER;

create() {
    ::create();
    set_name("narameon");
    set_id(({"narameon","ghost","spirit"}));
    set_gender("male");
    set_race("elf");
    set_short("The spirit of a male elf");
    

    set_long("This is the ghostly form of what was once an "+
    "obviously very handsome male elf.  The %^BOLD%^%^WHITE%^platinum"+
    " hair%^RESET%^%^CYAN%^ that flows from his head and the "+
    "%^YELLOW%^golden%^RESET%^%^CYAN%^ eyes that shine brilliantly "+
    "serve only to intensify his beauty.  His body is perfectly toned "+
    "and if not for transparency that is he, then every part of "+
    "his body would be solid and sturdy, the result of some "+
    "intense training and discipline.  An aura is given off from "+
    "this spirit, an aura of peace and calm.");

    set_alignment(4);
    set_hd(20);
    set_class("mage");
    set_mlevel("mage",20);
    set_guild_level("mage",20);
    set_stats("strength",10);
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
    "widly and conjures up a single blue metal gauntlet and "+
    "then tosses it in front of $N!");
    
    new(GY_OBJS+"narameons_gauntlet")->move(ETO);
    
    
    force_me("say that is all I have to offer... farewell...");

    force_me("emote quickly waves his hands again and blinks out of "+
    "existence!");
    if(objectp(TO)) {
        TO->remove();
    }
}






