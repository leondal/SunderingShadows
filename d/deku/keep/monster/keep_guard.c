#include <std.h>
#include "../keep.h"

inherit GUARD;

void create() 
{
    object ob;
    ::create();
    set_name("keep guard");
    set_id(({"guard","keep guard","orc","orc guard", "kguard"}));
    set_short("Keep guard");
    set_hd(18,1);
    set_stats("strength",18);
    set_stats("intelligence",8);
    set_stats("wisdom",5);
    set_stats("charisma",4);
    set_stats("dexterity", 17);
    set_stats("constitution",12);
    set_overall_ac(-6);
    set_wielding_limbs(({"right hand","left hand"}));
    switch(random(3)) {
        case 0:  ob = new("/d/common/obj/weapon/scimitar");      break;
        case 1:  ob = new("/d/common/obj/weapon/shortsword");    break;
        case 2:  ob = new("/d/common/obj/weapon/bastard");       break;
    }
    set_long("%^RESET%^This orcish guard wears a dull suit of %^BOLD%^%^WHITE%^silver chain mail%^RESET%^ and carries " + ob->query_short() + " at ready.  This creature is obviously very unkept, hygiene is not a term that applies to it.  Its skin is a sickly gray and its course hair is matted together with all types of filth.  It patrols this keep, but how effective of a patrol that is remains to be seen.%^RESET%^");
    ob->move(TO);
    ob = new("/d/common/obj/armour/chain");
    ob->set_name("silver chain mail");
    ob->set_id(({"chain","Chain","silver chain","Silver Chain","chainmail","Chainmail","Mail","mail"}));
    ob->set_obvious_short("silver chain mail");
    ob->set_short("%^BOLD%^%^WHITE%^Silver Chain Mail%^RESET%^");
    ob->set_long("%^BOLD%^%^WHITE%^This dull chain mail is made from interlocking rings of a silver alloy.  The entire suit of mail is three layers thick and has a thick fabric laid underneath of it to provide at least some comfort.  A pattern of shiny silver on the torso creates the image of a large %^BOLD%^%^BLACK%^wolf%^BOLD%^%^WHITE%^ head.%^RESET%^");
    if(!random(3)) 
    {
        ob->set_property("enchantment",2);
    }
    ob->move(TO);
    command("wield sword");
    command("wear chain");
    set_hp(385 + random(21));
    set_new_exp(20, "normal");
    set_max_hp(query_hp());
 }


