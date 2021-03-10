#include <std.h>
inherit MONSTER;
#include "../area_stuff.h"

void create()
{
    int lev;
    object ob;
    string me, him, he, his, chim, che, chis;
    ::create();
    set_name("twisted figure");
    set_id( ({"a twisted figure", "twisted figure", "figure", "eldebaro_ice_breaker", "eldebarocreature"}) );    
    if(random(2)) set_gender("male");
    else set_gender("female");
    if(random(3)) set_race("human");
    else if(random(2)) set_race("half-elf");
    else set_race("elf");
    
    set_short("%^RESET%^%^ORANGE%^Twisted "+query_race()+" f%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^gure%^RESET%^");  
    
    him = TO->QO;
    his = TO->QP;
    he = TO->QS;
    chim = capitalize(him);
    chis = capitalize(his);
    che = capitalize(he);
    
    set_long("%^RESET%^%^ORANGE%^This twisted figure no longer really resembles the "+query_race()+" "+
    "that "+he+" is. "+chis+" body is twisted and bent in strange ways, as if something has perverted or corrupted "+
    "the very essence of "+him+". "+chis+" eyes are very dark but shine with some type of strange "+
    "obsession, as if "+he+" is focused on one thing and one thing alone to the denial of anything else. "+chis+
    " body is frail and gaunt, from what you can make of it, though most of it is cloaked in a simple robe. "+chis+
    " hair is stringy and what remains is falling out in clumps or perhaps being pulled out by "+him+". "+chis+
    " fingers are bloody and broken, as if "+he+" has been clawing at something or chipping away at something "+
    "with them constantly. A "+
    "%^BOLD%^%^BLACK%^deep darkness%^RESET%^%^ORANGE%^ hangs heavily over "+him+".%^RESET%^");
    
    set_body_type("human");
    set_overall_ac(-20);

    set_property("swarm",1);
    lev = 40;
    set_property("amorpha", 1);
    if(random(2)) 
    {
        set_class("psion");
        set_mlevel("psion",lev);
        set_guild_level("psion",lev);       
        set_spells(({"call crystals", "tornado blast", "ultrablast", "microcosm", "unravel psionics"}));
        set_stats("intelligence", 25);
        set_stats("charisma", 18);
    }
    else
    {
        set_class("sorcerer");
        set_mlevel("sorcerer", lev);
        set_guild_level("sorcerer", lev);
        set_spells(({"prismatic spray", "meteor swarm", "cone of cold", "lightning bolt", "fireball"}));
        set_stats("charisma", 25);
        set_stats("intelligence", 18);
    }
    set_spell_chance(75); 
    set_speed(10); 
    
    set_stats("strength", 14);
    set_stats("dexterity", 13);
    set_stats("constitution", 12);
    set_stats("wisdom", 4);

    me = TO->query_short();
    
    add_money("gold",random(1800)+600);
    
    set_emotes(3, ({"%^BOLD%^%^BLACK%^Darkness threatens to overwhelm you!%^RESET%^",
	    me+" %^BOLD%^%^GREEN%^laughs loudly!%^RESET%^",
	    me+" %^BOLD%^%^GREEN%^CACKLES%^BOLD%^%^WHITE%^ gleefully!%^RESET%^",
	    me+" %^BOLD%^%^BLACK%^chuckles quietly and then glances around excitedly!%^RESET%^",
	    me+" %^BOLD%^%^GREEN%^growls at you!%^RESET%^",}),1);

    set_achats(4,({
        me +"%^BOLD%^%^BLACK%^ whispers softly: %^RESET%^it is almost time... it is almost done...", 
        me + "%^BOLD%^%^MAGENTA%^ says excitedly: %^RESET%^Asantra is almost awoken!! Just a little longer!!!",
        me + "%^BOLD%^%^GREEN%^ whispers quickly: %^RESET%^not much longer, not much longer at all.",
        me + "%^BOLD%^%^CYAN%^ cackles before speaking: %^RESET%^The WHOLE WORLD will be different soon!!!",
    }));
    
    set_alignment(9);
    set_max_hp(lev * 25);
    set_hp(query_max_hp());
    set_property("full attacks", 1);
    add_money("gold", 400 + random(601));
    set_new_exp(lev,"normal");
    set_monster_feats(({"perfect caster", "spell power", "spell focus"}));

    ob = new("/d/common/obj/armour/robe");
    ob->move(TO);
    ob->set_property("enchantment",5);
    command("wear robe");
    if(!random(15)) new(ELOB+"dreadhorn_guard")->move(TO);

}

void sacrifice(object giant)
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(giant)) return;
    
    tell_room(ETO, TO->query_short()+"%^BOLD%^%^BLACK%^ bows before "+giant->query_short()+
    "%^BOLD%^%^BLACK%^ and whispers quietly: %^RESET%^Asantra, take me, I give myself to you!");
    
    tell_room(ETO, TO->query_short()+"%^BOLD%^%^CYAN%^ whispers something in a strange "+
    "and ancient language!%^RESET%^");
    
    tell_room(ETO, TO->query_short()+"%^BOLD%^%^RED%^ falls dead at the feet of "+giant->query_short()+
    " and you watch as "+TO->QP+" life flows into "+giant->query_short()+"!%^RESET%^");
    
    giant->add_extra_hp(((int)TO->query_hp()/6));
    if(objectp(TO)) TO->die();
}

int query_watched() { return random(101); }