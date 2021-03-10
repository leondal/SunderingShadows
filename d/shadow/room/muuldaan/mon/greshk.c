#include <std.h>
inherit "/std/spell_vend.c";

void create() {
        int i,j;
        float fi;
        object ob;
        mapping spells_sold,spells_to_sell;
        string *spells;

        ::create();
        set_property("no attack",1);
        set_property("no bump", 1);
        set_property("strength","spells");
        set("aggressive", 0);
        set_name("Greshk");
        set_id( ({ "greshk","Greshk","shop keeper","shopkeeper"}) );
        set_short("Greshk, kobold wizard");
        set_level(20);
        set_long("Greshk is a young kobold of particularly bright and alert "
"expression.  He is still relatively young by his appearance, and his crimson "
"eyes are constantly inspecting visitors to his store, or scanning over a "
"parchment.  Rusty black scales cover his body, and the long thin tail that "
"trails along behind him.  Unlike most of his kind, he seems to be dressed in "
"relatively clean clothes, even if they are a little ragged.\n<help shop> will "
"get you a list of shop commands.");
        set_gender("male");
        set_alignment(6);
        set_race("kobold");
        set_class("mage");
        set_hd(20,1);
        set_size(3);
        set_stats("intelligence",17);
        set_stats("wisdom",14);
        set_stats("strength",14);
        set_stats("charisma",11);
        set_stats("dexterity",10);
        set_stats("constitution",15);
        set_body_type("human");
        set_guild_level("mage",20);
        set_mlevel("mage",20);
        set_overall_ac(0);
        set_spell_chance(90);
        set_spells_sold(gen_spells_sold(10));        
        set_spells(({
                "shout",
                "hideous laughter",
                "fireball",
                "magic missile",
                "monster summoning i"
        }));
        set_size(3);
        set_wielding_limbs( ({ "right hand","left hand" }) );
        i=1000000+random(2000000);
        set_spoken("undercommon");
        set_exp(10);
}

int __Pickup(string str){
        if(TP->is_class("mage") || TP->is_class("bard") || avatarp(TP))
                return ::__Pickup(str);
        else {
        tell_object(TP, "Greshk snorts: You?  Hahaha, you're not "+
                "worthy of one of these.");
      return 1;
        }
}

int __Buy(string str){
        if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP))
                return ::__Buy(str);
        else {
        tell_object(TP, "Greshk snorts: You?  Hahaha, "+
                "you're not worthy of one of these.");
      return 1;
        }
}

int __List(string str){
        if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP))
                return ::__List(str);
        else {
        tell_object(TP, "Greshk snorts: You?  Hahaha, "+
                "you're not worthy of one of these.");
      return 1;
        }
}

int __Sell(string str){
        if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP))
                return ::__Sell(str);
        else {
        tell_object(TP, "Greshk snorts: You?  Hahaha, "+
                "you're not worthy of one of these.");
      return 1;
        }
}

int __Help(string str){
        if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP))
                return ::__Help(str);
        else {
        tell_object(TP, "Greshk snorts: You?  "+
                "Hahaha, you're not worthy of one of these.");
      return 1;
        }
}
