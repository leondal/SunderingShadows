#include "/d/dagger/Torm/tormdefs.h"
#include <std.h>
inherit "/d/dagger/Torm/mon/dayperson.c";
create(){
    ::create();
    set_name("Wizened mage");
    set_id(({ "dayperson", "mage","wizened mage" }));
    set_emotes(5,({ "The mage mutters and makes few gestures over something "
    "before putting it back in "+TO->query_possessive()+" robes." }));
    set_short( "Wizened mage" );
    set_long("This ancient mage wanders through the bazaar "+
    "searching for some mysterious component or artifacts from "+
    "the private hawkers.  The mage shows no interest in you at all "+
    "and continues past you.");
    set_race("human");
    if(!random(2)){set_gender("male");} else {set_gender("female");}
    set_class("mage");
    set_guild_level("mage",25 + random(11));
    set_hd(20,1);
    set_stoneSkinned(20);
    set_mlevel("mage",query_guild_level("mage"));
    set_spell_chance(100);
    set_spells(({ "magic missile", "lightning bolt","web","scorcher",
    "meteor swarm","cone of cold","lower resistance","fireball" }));
    set_max_hp(250 + random(101));
    set_property("magic resistance",75);
    set_property("no rush",1);
    set_property("no dominate",1);
    set_property("no death",1);
    set_property("no animate",1);
    set_property("no stab",1);
    set_hp(query_max_hp());
    set_overall_ac(0);
    set_stats("strength",12);
    set_stats("intelligence",18);
    set_stats("dexterity",9);
    set_stats("charisma",7);
    set_stats("constitution",11);
    set_stats("wisdom",18);
    set_money("silver",random(100));
    set_exp(query_hp()*10);
    if(!random(2)) {
                new("/d/common/obj/rand/randrobe.c")->move(TO);
    }
    else {
        new("/d/common/obj/armour/robe.c")->move(TO);
    }
    command("wearall");
}

void heart_beat() {
    ::heart_beat();
    if(!objectp(TO) || !objectp(ETO)) return;
    if(query_paralyzed()) {
        tell_room(ETO,"%^RED%^The mage chants a quick phrase "+
        "to counter his own paralyzation!%^RESET%^");
        TO->set_paralyzed(0);
        TO->add_hp(30 + random(49));
        TO->set_max_hp(query_max_hp() + (30 + random(51)));
        return;
    }

}
        