//Coded by the one and only master of monsters...BANE//
#include <std.h>
#include <daemons.h>
inherit MONSTER;

object *attackers;



void create(){
    ::create();
    set_id(({"dreamshadow"}));
    set_name("Dreamshadow");
    set_short("A Dreamshadow");
    set_long(
        "An illusionary shadow..."
    );
    set_body_type("human");
    set_race("shadow");
    set_gender("male");
    set_size(2);
    set_hd(100,0);
    set_hp(800);
    set_property("magic",1);
    set_property("full attacks",1);
    set_exp(35000);
    set_overall_ac(-5);
    set("aggressive","change");
    set_wielding_limbs(({"right hand"}));
}
void change(){
    int i;
    string *allowed=({
        "magic missile",
        "fireball",
        "lightning bolt",
        "cone of cold",
        "scorcher",
        "acid arrow",
        "burning hands",
        "hideous laughter",
        "web",
        "ray of enfeeblement",
        "sleep",
        "call lightning",
        "cause light wounds",
        "cause serious wounds",
        "cause critical wounds",
        "hold person",
        "cause blindness",
        "limb attack",
        "poison"
    });
    string spells=({});
    string *memorized;
    object ob;
    object *eq;
    if(wizardp(TP)) return;
    write("The Dreamshadow shifts its form.");
    set_id(({"shadow"}));
    set_name(TP->query_cap_name()+"'s shadow");
    set_short(TP->query_cap_name()+"'s shadow");
    set_long("The shadow of "+TP->query_cap_name()+".");
    set_race(TP->query_race());
    set_gender(TP->query_gender());
    set_body_type(TP->query_body_type());
    set_hd(TP->query_hd(),0);
    set_max_hp(TP->query_max_hp());
    set_hp(TP->query_hp());
    set_level(TP->query_level());
    set_overall_ac(10);
    set_size(TP->query_size());
    set_max_sp(TP->query_max_sp());
    set_sp(TP->query_sp());
    set_class(TP->query_class());
    set_spells(({}));
    set_spell_chance(0);
    if(TP->query_guild_level("mage")){
    memorized=keys(TP->query_all_memorized());
        for(i=0;i<sizeof(memorized);i++)
        if(member_array(memorized[i],allowed) != -1) spells += ({memorized[i]});
        set_guild_level("mage",TP->query_guild_level("mage"));
        set_spells(spells);
        set_spell_chance(50);
        } else
    if(TP->query_guild_level("bard")){
        memorized=keys(TP->query_all_memorized());
        for(i=0;i<sizeof(memorized);i++)
        if(member_array(memorized[i],allowed) != -1) spells += ({memorized[i]});
        set_guild_level("bard",TP->query_guild_level("bard"));
        set_spells(spells);
        set_spell_chance(50);
        } else
    if(TP->query_guild_level("cleric")){
        if(ob=present("symbol",TP)){
        memorized=keys( (mapping)ob->query_known_spells());
        for(i=0;i<sizeof(memorized);i++)
        if(member_array(memorized[i],allowed) != -1) spells += ({memorized[i]});
        set_guild_level("cleric",TP->query_guild_level("cleric"));
        set_spells( spells );
        set_spell_chance(50);
	}
    } else
    if(TP->query_guild_level("ranger")){
        if(ob=present("symbol",TP)){
            memorized=keys( (mapping)ob->query_known_spells());
            for(i=0;i<sizeof(memorized);i++)
            if(member_array(memorized[i],allowed) != -1) spells += ({memorized[i]});
            set_guild_level("ranger",TP->query_guild_level("ranger"));
            set_spells( spells );
            set_spell_chance(20);
        }
    } else
    if(TP->query_guild_level("druid")){
        if(ob=present("symbol",TP)){
            memorized=keys( (mapping)ob->query_known_spells());
            for(i=0;i<sizeof(memorized);i++)
            if(member_array(memorized[i],allowed) != -1) spells += ({memorized[i]});
            set_guild_level("druid",TP->query_guild_level("druid"));
            set_spells( spells );
            set_spell_chance(50);
        }
    } else
    if(TP->query_guild_level("paladin")){
        if(ob=present("symbol",TP)){
            memorized=keys( (mapping)ob->query_known_spells());
            for(i=0;i<sizeof(memorized);i++)
            if(member_array(memorized[i],allowed) != -1) spells += ({memorized[i]});
            set_guild_level("paladin",TP->query_guild_level("paladin"));
            set_spells( spells );
            set_spell_chance(20);
        }
    } else
    if(TP->query_guild_level("thief")){
        set_guild_level("thief",TP->query_guild_level("thief"));
        set_thief_skill("hide in shadows",TP->query_thief_skill("hide in shadows"));
        set_thief_skill("move silently",TP->query_thief_skill("move silently"));
        add_search_path("cmds/thief");
        command("stab "+TP->query_cap_name());
    }
    set_alignment(TP->query_alignment());
    set_stats("strength",TP->query_stats("strength"));
    set_stats("dexterity",TP->query_stats("dexterity"));
    set_stats("constitution",TP->query_stats("constitution"));
    set_stats("wisdom",TP->query_stats("wisdom"));
    set_stats("intelligence",TP->query_stats("intelligence"));
    set_stats("charisma",TP->query_stats("charisma"));
    set_exp(1000);
    set_wielding_limbs(TP->query_wielding_limbs());
    eq=all_inventory(TP);
    while(all_inventory(TO) && all_inventory(TO) != ({}))
all_inventory(TO)[0]->remove();
    for(i=0;i<sizeof(eq);i++){
        if( (sizeof(eq[i]->query_id()) &&
        (((string *)(eq[i]->query_id()))[0] == "holy symbol") ||
         (string)eq[i]->query_name() == "components bag" ||
        (string)eq[i]->query_name() == "band"))
            continue;
        ob=new(base_name(eq[i]));
        ob->move(TO);
	ob->remove_property("enchantment");
	ob->set_property("enchantment",eq[i]->query_property("enchantment"));
        if(eq[i]->query_wielded()) force_me("wield "+ob->query_name());
        if(eq[i]->query_worn()) force_me("wear "+ob->query_name());
        ob->set_property("monsterweapon",1);
    }
    force_me("kill "+TPQN);
}
