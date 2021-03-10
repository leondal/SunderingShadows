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
  set_name("Wizbert");
  set_id( ({ "wizbert", "clerk", "shop keeper", "shopkeeper"}) );
  set_short("%^RESET%^%^CYAN%^Wizbert%^MAGENTA%^, the magic entrepreneur");
  set_level(16); 
  set_long(
@DESC
%^WHITE%^Wizbert is a puny looking gnome hidden in a bright %^ORANGE%^y%^BOLD%^%^ORANGE%^e%^RESET%^%^ORANGE%^l%^BOLD%^%^ORANGE%^l%^RESET%^%^ORANGE%^ow%^WHITE%^ robe with a hood pulled over his head. His main feature aside from the robe is his very large nose which protrudes from within the hood. He looks very incoherent, but you know he'll respond to a sale in an instant. He offers spells for lots and lots of money.%^RESET%^


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
  set_overall_ac(0);
  set_spells_sold(gen_spells_sold(20));
  set_spell_chance(90);
  set_spells(({"color spray","hideous laughter","acid
arrow","sleep","monster summoning ii"}));
  set_size(1); 
  set_wielding_limbs( ({ "right hand","left hand" }) );
  i=1000000+random(2000000);
  set_emotes(5,({
    "Wizbert says: Must get money, definitely money...",
    "Wizbert says: Spells are good, lots and lots of spells.",
    "Wizbert says: Must sell spells, definitely must sell spells...
definitely spells.",
    "Wizbert says: Must count gold... "+i+" gold... square root is
"+sqrt(to_float(i))+"...",
    "Wizbert paces around the room nervously.",
    "Wizbert shakes his head while mumbling something",
    "Wizbert counts his spells and gold."
    }), 0);
  set_emotes(5, ({
    "Wizbert says: Being attacked... definitely not good... definitely.",
    "Wizbert says: Must protect money, and spells, definitely spells.",
    "Wizbert says: Dying sucks!"
    }), 1);
  ob=new("/d/shadow/obj/armor/robe.c");
  ob->set_short("A bright-yellow robe");
  ob->set_long("This is a bright-yellow robe owned by Wizbert, the resident
spell selling gnome in Shadow's tower of the magi.");
  ob->move(TO); 
  command("wear robe");
}

int __Pickup(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || avatarp(TP)) return
::__Pickup(str);
    else {
      tell_object(TP, "Wizbert says: You?  Hahaha, you're not worthy of one
of these.");
      return 1;
    }
}

int __Buy(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return
::__Buy(str);
    else {
      tell_object(TP, "Wizbert says: You?  Hahaha, you're not worthy of one
of these.");
      return 1;
    }
}

int __List(string str){ 
    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return
::__List(str);
    else {
      tell_object(TP, "Wizbert says: You?  Hahaha, you're not worthy of one
of these.");
      return 1;
    }
}

int __Sell(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return
::__Sell(str);
    else {
      tell_object(TP, "Wizbert says: You?  Hahaha, you're not worthy of one
of these.");
      return 1;
    }
}

int __Help(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return
::__Help(str);
    else {
      tell_object(TP, "Wizbert says: You?  Hahaha, you're not worthy of one
of these.");
      return 1;
    }
}
