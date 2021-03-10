#include <std.h>
#include <spellsbylevel.h>
inherit "/std/spell_vend.c";

void do_my_spells() {
    mapping spells=([]);
    string spell,*dir;
    int i,num;

    for(i=0;i<sizeof(LEVEL_1);i++) {
        spell = "/cmds/spells/"+LEVEL_1[i][0..0]+"/_"+LEVEL_1[i]+".c";
        spell = replace_string(spell,"_"," ");
        spells += ([ spell : num * 1000 ]);
    }

    for(i=0;i<sizeof(LEVEL_2);i++) {
        spell = "/cmds/spells/"+LEVEL_2[i][0..0]+"/_"+LEVEL_2[i]+".c";
        spell = replace_string(spell,"_"," ");
        spells += ([ spell : num * 1000 ]);
    }

    set_spells_sold(spells);
    return;
}

void create() 
{
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
  set_name("Spellbert");
  set_id( ({ "spellbert", "clerk", "shop keeper", "shopkeeper"}) );
  set_short("Spellbert, the magic entrepreneur");
  set_level(16); 
  set_long(
@DESC
Spellbert is a puny looking gnome hidden in a bright yellow robe with a hood
pulled over his head.  His main feature aside from the robe is his very
large nose which protrudes from within the hood.  He looks very incoherent, but
you know he'll respond to a sale in an instant.  He offers spells for lots and
lots of money.
<help shop> will get you a list of shop commands.
DESC
  );
  set_gender("male");
  set_alignment(7);
  set("race", "gnome");
  set_class("mage");
  set_hd(16,1);
  set_stats("intelligence",19);
  set_stats("wisdom",10);
  set_stats("strength",8);
  set_stats("charisma",13);
  set_stats("dexterity",18);
  set_stats("constitution",14);
  set_body_type("human");
  set_guild_level("mage",16);
  set_mlevel("mage",16);
  set_overall_ac(-80);
  set_property("magic resistance",800);
  set_spells(({"color spray","hideous laughter","acid arrow","sleep","monster summoning ii"}));
  set_spell_chance(90);
  set_size(1); 
  set_wielding_limbs( ({ "right hand","left hand" }) );
  ob=new("/d/shadow/obj/armor/robe.c");
  ob->set_short("A bright-yellow robe");
  ob->set_property("monsterweapon",1);
  ob->move(TO); 
  command("wear robe");

  do_my_spells();
}

int __Pickup(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || avatarp(TP)) return
::__Pickup(str);
    else {
      tell_object(TP, "Spellbert says: You?  Hahaha, you're not worthy of one
of these.");
      return 1;
    }
}

int __Buy(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return
::__Buy(str);
    else {
      tell_object(TP, "Spellbert says: You?  Hahaha, you're not worthy of one
of these.");
      return 1;
    }
}

int __List(string str){ 
    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return
::__List(str);
    else {
      tell_object(TP, "Spellbert says: You?  Hahaha, you're not worthy of one
of these.");
      return 1;
    }
}

int __Sell(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return
::__Sell(str);
    else {
      tell_object(TP, "Spellbert says: You?  Hahaha, you're not worthy of one
of these.");
      return 1;
    }
}

int __Help(string str)
{
    return 0;
}
