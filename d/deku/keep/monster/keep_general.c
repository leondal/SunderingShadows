#include <std.h>
#include "../keep.h"

inherit GUARD;

void create() 
{
    object ob;
    ::create();
    set_name("keep general");
    set_id(({"general","General","orc","orc guard","guard","kguard"}));
    set_short("General of the guard");
    set_hd(22,1);
    set_stats("strength",20);
    set_stats("intelligence",8);
    set_stats("wisdom",5);
    set_stats("charisma",4);
    set_stats("dexterity", 19);
    set_stats("constitution",19);
    set_overall_ac(-10);
    set_hp(570 + random(31));
    switch(random(3)) 
    {
        case 0:  
            ob = new("/d/common/obj/weapon/battle_axe");
			ob->move(TO);
			break;
        case 1:
            ob = new("/d/common/obj/weapon/two_hand_sword");
			ob->move(TO);
			break;
        case 2:
            ob = new(KEEPO + "bone_axe");
			ob->move(TO);
			break;
    }
  
    set_long("%^RESET%^This orcish guard wears a dull suit of %^BOLD%^%^WHITE%^silver chain mail%^RESET%^ and carries " + ob->query_short() + " at ready.  This creature is obviously very unkept, hygiene is not a term that applies to it.  Its skin is a sickly gray and its course hair is matted together with all types of filth.  This guard is one of the elite of this keep, to boast his position he wears a %^BOLD%^%^WHITE%^bone%^RESET%^ ring.%^RESET%^");
    command("wield " +ob->query_name());
    ob = new("/d/common/obj/armour/chain");
    ob->set_name("silver chain mail");
    ob->set_id(({"chain","Chain","silver chain","Silver Chain","chainmail","Chainmail","Mail","mail"}));
    ob->set_obvious_short("silver chain mail");
    ob->set_short("%^BOLD%^%^WHITE%^Silver Chain Mail%^RESET%^");
    ob->set_long("%^BOLD%^%^WHITE%^This dull chain mail is made from interlocking rings of a silver alloy.  The entire suit of mail is three layers thick and has a thick fabric laid underneath of it to provide at least some comfort.  A pattern of shiny silver on the torso creates the image of a large %^BOLD%^%^BLACK%^wolf%^BOLD%^%^WHITE%^ head.%^RESET%^");
    if(!random(4)) 
    {
        ob->set_property("enchantment",4);
    }
    ob->move(TO);
    ob = new(KEEPO + "insigniaring");
    ob->move(TO);
    command("wear ring");
    command("wield trident");
    command("wear chain");
    set_new_exp(20, "very high");
    MOB_TR_D->do_treasure(TO,"A");
}