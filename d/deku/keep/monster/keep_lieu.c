#include <std.h>
#include "../keep.h"

inherit GUARD;

void create() 
{
    object ob;
    ::create();
    set_name("keep lieutenant");
    set_id(({"lieutenant","klieutenant","orc","orc guard","guard"}));
    set_short("Keep Lieutenant");
    set_hd(20,1);
    set_overall_ac(-8);
    set_stats("strength",19);
    set_stats("intelligence",12);
    set_stats("wisdom",5);
    set_stats("charisma",4);
    set_stats("dexterity", 19);
    set_stats("constitution",15);
    new("/d/common/obj/weapon/longsword")->move(TO);
    set_long("%^RESET%^This orcish guard wears a dull suit of %^BOLD%^%^WHITE%^silver chain mail%^RESET%^ and carries a longsword at ready.  This creature is obviously very unkept, hygiene is not a term that applies to it.  Its skin is a sickly gray and its course hair is matted together with all types of filth.  This guard is one of the elite of this keep, to boast his position he wears a %^BOLD%^%^WHITE%^bone%^RESET%^ ring.%^RESET%^");
    ob = new("/d/common/obj/armour/chain");
    ob->set_name("silver chain mail");
    ob->set_id(({"chain","Chain","silver chain","Silver Chain","chainmail","Chainmail","Mail","mail"}));
    ob->set_obvious_short("silver chain mail");
    ob->set_short("%^BOLD%^%^WHITE%^Silver Chain Mail%^RESET%^");
    ob->set_long("%^BOLD%^%^WHITE%^This dull chain mail is made from interlocking rings of a silver alloy.  The entire suit of mail is three layers thick and has a thick fabric laid underneath of it to provide at least some comfort.  A pattern of shiny silver on the torso creates the image of a large %^BOLD%^%^BLACK%^wolf%^BOLD%^%^WHITE%^ head.%^RESET%^");
    if(random(400) > 390) 
    {
        ob->set_property("enchantment",3);
    }
    ob->move(TO);
    ob = new(KEEPO + "insigniaring");
    ob->move(TO);
    command("wear ring");
    command("wield longsword");
    command("wear chain");
    set_hp(475 + random(21));
    MOB_TR_D->do_treasure(TO,"A");
    set_new_exp(20, "high");
}

