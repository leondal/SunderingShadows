#include <std.h>
inherit "/d/common/obj/weapon/club.c";
#define MAXUSES 10
int uses, darkened_time;

void create() 
{
    ::create();
    set_id(({ "club" }));
    set_name("granite club");
    set_obvious_short("A granite club");
    set_short("%^BOLD%^%^BLACK%^A gr%^BOLD%^%^WHITE%^a"+
    "%^BOLD%^%^BLACK%^n%^BOLD%^%^WHITE%^i"+
    "%^BOLD%^%^BLACK%^te c%^BOLD%^%^WHITE%^l%^BOLD%^%^BLACK%^ub%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This weapon is made from a solid "+
    "piece of gr%^BOLD%^%^WHITE%^a"+
    "%^BOLD%^%^BLACK%^n%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^"+
    "te that has been shaped into "+
    "the likeness of a club.  The handle of it is slender "+
    "and gradually thickens along "+
    "its length, eventually reaching its "+
    "thickest cross section at the opposite end.  "+
    "The head of the club has been left as a rough "+
    "gr%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^"+
    "n%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^te, "+
    "bumpy and jagged, as if to inflict more "+
    "serious wounds.  There is a lone "+
    "%^BLUE%^rune%^BOLD%^%^BLACK%^ carved into the "+
    "handle that you might be able to read it.%^RESET%^");
    set_lore("Another weapon that is believed to have been produced by Clan Stonecrusher. This items was crafted"+
    "during the great war with the Shadowlord. In an attempt to turn his abilities against him, the clan"+
    "developed this club to escape his bandits who had to fight by torchlight."+
    "It appears that the Clan wasn't very successful as these clubs remain in circulation"+
    "on the island.");
    
    
    set_language("dwarvish");
    set_property("enchantment",3);
	set_item_bonus("damage resistance",3);
    set_read("Darkness and night, friend to those in flight.\n"+
    "Invoke my %^BOLD%^%^BLACK%^shadow%^RESET%^ "+
    "when all is not right...\n");
    //set_weight(20);
    set_value(1000);
    //set_large_wc(1,6);
    //set_weapon_speed(6);
    set_wield((:TO,"wield_me":));
    set_unwield("%^RED%^You relax your muscles "+
    "as you release the heavy club!%^RESET%^");
    set_hit((:TO,"special":));

}

int wield_me() 
{
    tell_object(ETO,"%^RED%^Your muscles ache as you "+
    "wield the heavy club!%^RESET%^");
    return 1;
}

int special(object targ) 
{	
    if(random(3) == 2) 
    {
        if((int)targ->query_size() > 1) 
        {
            return roll_dice(2, 4);
        }
        return roll_dice(1, 4);
    }
}

void init() 
{
    ::init();
    add_action("invoke_action","invoke");
}

int invoke_action(string str) 
{
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if (ETO->query_bound() || ETO->query_unconscious()) 
    {
        ETO->send_paralyzed_message("info",ETO);
        return 1;
    }

    if(!str) return 0;

    if(str == "shadow" || str == "Shadow") 
    {
        ETO->set("last say","");
        ETO->force_me("say I invoke shadow aid!");
        if(uses < MAXUSES) 
        {

            if(time() - darkened_time > 100)
            {

                if(sizeof(ETO->query_attackers()) > 0 && (int)ETO->query_hp() < (int)ETO->query_max_hp() / 2) 
                {
                    new("/cmds/spells/d/_darkness.c")->use_spell(ETO,ETO,random(30) + 10,10,"mage");
                    uses += 1;
                    darkened_time = time();
                    return 1;
                }
                tell_room(environment(ETO),"%^RED%^Nothing seems to happen...%^RESET%^");
                return 1;
            }

            tell_room(environment(ETO),"%^RED%^Nothing seems to happen...%^RESET%^");
            return 1;
        }
        tell_room(environment(ETO),"%^RED%^Nothing seems to happen...%^RESET%^");
        return 1;
	}

    return 0;
}
