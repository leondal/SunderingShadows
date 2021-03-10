#include <std.h>
#include <daemons.h>
#include "/d/deku/inherits/graveyard.h"
inherit MONSTER;

create() {
    ::create();
    set_name("alustian");
    set_id(({"alustian","ghost","spirit"}));
    set_gender("male");
    set_race("human");
    set_short("The spirit of a male elf");
    
    set_long("This is the ghostly form of what was once "+
    "a thin and taller than average male elf.  His body, "+
    "although now translucent, was obviously once that of a honed "+
    "warrior.  His facial features consist of high cheekbones, "+
    "a thin and defined nose, %^GREEN%^forest green%^RESET%^%^CYAN%^ "+
    "eyes, thin, tight lips, and pointed ears.  "+
    "An awe inspiring aura is given off by this "+
    "creature, spewing forth in a pale green light from "+
    "his eyes and bathing everything that stands near him.  "+
    "Despite this supernatural aura there seems to be "+
    "something of tremendous sorrow weighing on this "+
    "being.");

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
    "widly and conjures up a single mask and "+
    "then tosses it in front of $N!");
      
    new(GY_OBJS+"alustianmask")->move(ETO);  
       
    force_me("say that is all I have to offer... farewell...");

    force_me("emote quickly waves his hands again and blinks out of "+
    "existence!");
    if(objectp(TO)) {
        TO->remove();
    }
}






