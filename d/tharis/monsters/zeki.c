#include <std.h>

inherit "/std/spell_vend.c";

void create() {
  int i,j;
  float fi;
  object ob;
  mapping spells_sold,spells_to_sell;
  string *spells;
  ::create();
  set_property("no bump", 1);
  set("aggressive", 0);
  set_name("zeki");
  set_id(({"zeki","clerk","shop keeper","shopkeeper","Zeki"}));
  set_short("%^RED%^Zeki Duman Effendi,%^RESET%^ %^MAGENTA%^Resident Alchemist%^RESET%^");
  set_level(16); 
  set_long(
     "%^MAGENTA%^Zeki Duman %^ORANGE%^is a man of average height.  "+
     "His skin is bronzed and his lively eyes %^BOLD%^%^BLACK%^black "+
     "as coal%^RESET%^%^ORANGE%^.  His %^BOLD%^%^WHITE%^snowy white"+
     "%^RESET%^ %^ORANGE%^hair is loosely tied in a bun at the base "+
     "of his neck, but most of it is hidden by the mage's hat he is "+
     "wearing.  A pair of %^WHITE%^legless spectacles %^ORANGE%^rests "+
     "on the bridge of his nose and occasionally slides down, forcing "+
     "him to push them back up with a finger.  The top of his amber "+
     "colored puffy pantaloons is hidden by a %^BOLD%^%^MAGENTA%^"+
     "bright fuchsia%^RESET%^ %^ORANGE%^embroidered overcoat with "+
     "bell sleeves, the thread of the embroidery and the sash both "+
     "of the same amber as the pantaloons.  The toes of his "+
     "%^YELLOW%^curly toed shoes%^RESET%^ %^ORANGE%^rise high, "+
     "a symbol of wealth and status in the Tsarven society.\n"+
     "%^RESET%^<help shop> will get you a list of shop commands.");
  set_gender("male");
  set_alignment(4);
  set_race("human");
  set_class("mage");
  set_hd(16,1);
  set_stats("intelligence",19);
  set_stats("wisdom",16);
  set_stats("strength",12);
  set_stats("charisma",13);
  set_stats("dexterity",18);
  set_stats("constitution",14);
  set_guild_level("mage",16);
  set_mlevel("mage",16);
  set_overall_ac(0);
  spells_sold=([
    "acid arrow":18000,
    "acid orb":33000,
    "animate dead":50000,
    "armor":5500,
    "blink":25000,
    "burning hands":4000,
    "chain lightning":67500,
    "chill touch":7000,
    "color spray":8000,
    "cone of cold":50000,
    "conjure air elemental":56000,
    "conjure earth elemental":56000,
    "conjure fire elemental":58000,
    "conjure water elemental":52000,
    "contingency":60000,
    "detect invisibility":25000,
    "detect magic":3000,
    "detect scrying":60000,
    "dispel magic":30000,
    "domination":53000,
    "dragon scales":69500,
    "drawmij's instant summons":85000,
    "phantom guardians":92000,
    "finger of death":74000,
    "fireball":34000,
    "frost orb":33000,
    "greater shout":72000,
    "hideous laughter":18000,
    "hold person":31000,
    "ice storm":46000,
    "identify":3400,
    "incendiary cloud":88000,
    "invisibility":23000,
    "know alignment":18000,
    "light":2000,
    "lightning bolt":31000,
    "lightning orb":33000,
    "lower resistance":43000,
    "magic mirror":150000,
    "magic missile":6500, 
    "meteor swarm":98000,
    "monster summoning i":32000,
    "monster summoning ii":42000,
    "monster summoning iii":48000,
    "monster summoning iv":54000,
    "monster summoning v":60000,
    "monster summoning vi":69000,
    "monster summoning vii":77000,
    "powerword stun":66000,
    "prismatic spray":71000,
    "protection from scrying":41000,
    "ray of enfeeblement":28000,
    "rope trick":20000,
    "scorcher":25000,
    "shout":42000,
    "sleep":5000,
    "sonic orb":33000,
    "stoneskin":148000,
    "summon companion":18000,
    "teleport without error":72000,
    "teleport":55000,
    "vampiric touch":39000, 
    "wall of fire":40000,
    "warriors constitution":50000,
    "water breathing":25000,
    "web":21000
  ]);
  for(i=0;i<sizeof(spells_sold);i++)
    spells_sold[keys(spells_sold)[i]] += random(5000);
  spells = ({});
  spells_to_sell = ([]);
  for(j = 1;j<20;j++)
    spells = spells +
({keys(spells_sold)[random(sizeof(keys(spells_sold)))]});
  spells = distinct_array(spells);
  for(j=0;j<sizeof(spells);j++)
    spells_to_sell[spells[j]] = spells_sold[spells[j]];
  set_spells_sold(spells_to_sell);
  set_spell_chance(90);
  set_spells(({"color spray","hideous laughter","acid
arrow","sleep","monster summoning ii"}));
}

int __Pickup(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || avatarp(TP)) return
::__Pickup(str);
    else {
      tell_object(TP, "%^RESET%^%^MAGENTA%^Zeki says%^RESET%^: You?  Hahaha, you're not worthy of one
of these.");
      return 1;
    }
}

int __Buy(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return
::__Buy(str);
    else {
      tell_object(TP, "%^RESET%^%^MAGENTA%^Zeki says%^RESET%^: You?  Hahaha, you're not worthy of one
of these.");
      return 1;
    }
}

int __List(string str){ 
    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return
::__List(str);
    else {
      tell_object(TP, "%^RESET%^%^MAGENTA%^Zeki says%^RESET%^: You?  Hahaha, you're not worthy of one
of these.");
      return 1;
    }
}

int __Sell(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return
::__Sell(str);
    else {
      tell_object(TP, "%^RESET%^%^MAGENTA%^Zeki says%^RESET%^: You?  Hahaha, you're not worthy of one
of these.");
      return 1;
    }
}

int __Help(string str){
    if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return
::__Help(str);
    else {
      tell_object(TP, "%^RESET%^%^MAGENTA%^Zeki says%^RESET%^: You?  Hahaha, you're not worthy of one
of these.");
      return 1;
    }
}
