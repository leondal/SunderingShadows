#include <std.h>

inherit WEAPONLESS;


void create() {
   object ob;
    ::create();
    set_name("black creature");
    set_id(({"creature","black creature"}));
    set_race("creature");
    set_body_type("human");
    set_size(3);
    
    set_short("A monstrous black skinned creature");
    switch(random(2)) {
        case 0:
            set_hd(25 + random(4),1);   
            break;
        case 1:
            set_class("mage");
            set_guild_level("mage",25 + random(4));
            set_mlevel("mage",query_guild_level("mage"));
            set_spells(({"fireball","magic missile","lower resistance",
            "lightning bolt","scorcher","lower resistance",
            "burning hands","cone of cold"}));
            set_spell_chance(90);
            break;
    }
    set_long("%^BOLD%^%^BLACK%^This massive creature towers "+
    "close to ten feet high, its body forged from a black substance.  "+
    "The substance is not easily identifiable, yet somewhat "+
    "resembles a dark flesh.  The substance is visibly pudgy, with "+
    "various bones poking out grotesquely against the epidermis.  "+
    "An occassional piece of the substance falls from the "+
    "creature to only reconnect further down the body.  The "+
    "lower part of the creature is visibly thicker than the "+
    "upper, an obvious result of the pooling of the strange "+
    "substance that forms it.  The creature has no visible "+
    "mouth but has two gray, lifeless orbs within tiny slits that "+
    "probably serve as its eyes.  Its arms are larger than "+
    "the rest of the upper body and appear quite capable of "+
    "inflicting massive wounds with their strangely pointed "+
    "ends.%^RESET%^");

    set_hp(query_level() * 14);
    add_limb("left point","left hand",0,0,0);
    add_limb("right point","right hand",0,0,0);
    set_attack_limbs(({"left point", "right point"}));	
    //set_exp(query_max_hp() * (30 + random(8)));
	set_new_exp(5, "very low");
    set_alignment(9);
    set_stats("strength",19);
    set_stats("intelligence",17);
    set_stats("wisdom",15);
    set_stats("dexterity",13);
    set_stats("charisma",12);
    set_stats("constitution",19);
    
    if(!random(4)) {
        ob = new("/d/deku/armours/ring_p");
        ob->set_property("enchantment",1);
        ob->move(TO);
        command("wear ring");
    }
  
    set_property("no paralyze",1);
    set_property("full attacks",1);
    set_property("weapon resistance",1);
    set_mob_magic_resistance("average");
    set_overall_ac(-4);
    set_max_level(20);
    set_lang("outlander",100);
    command("speak outlander");
    if(query_class_string() == "Mage") {
        set_attacks_num(1);
        set_damage(1,4);
    }
    else {
        set_attacks_num(2 + random(3));
        set_damage(2,3);
    }
}

void special_attack(object targ) {
    TO->force_me("speech growl");
    TO->force_me("say you shall be gone soon....");
    TO->force_me("say and I shall have the flesh of "+
    "Dralthorak!");
    targ->add_follower(TO);
    if(query_class_string() == "Mage") {
        new("/cmds/spells/p/_powerword_stun")->use_spell(TO,targ,16,16,"mage");
        return;
    }
    TO->force_me("kill "+targ->query_name());
    return;
}

void heart_beat() {
    ::heart_beat();
    if(!objectp(TO) || !objectp(ETO)) return;
    if(query_hp() < query_max_hp()) {
        TO->add_hp(2 + random(3));
    }
}

void die(object ob) {
    tell_room(ETO,"%^MAGENTA%^The black creature "+
    "yells:%^RESET%^ THIS IS NOT THE END!!!  YOU WILL PAY!!");
    tell_room(ETO,"%^BOLD%^%^BLACK%^The creatures body slumps to "+
    "the ground and melts into a pile of black goo.%^RESET%^");
    TO->set_long("%^BOLD%^%^BLACK%^All that remains of this is "+
    "a pile of thick black goo.%^RESET%^");
    return ::die(ob);
}
