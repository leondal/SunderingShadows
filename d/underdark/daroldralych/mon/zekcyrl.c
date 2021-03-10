#include <std.h>
#include "../defs.h"
inherit "/std/spell_vend";

void create() {
   int i,j;
   float fi;
   object ob;
   mapping spells_sold,spells_to_sell;
   string *spells;
   ::create();

   set_name("Zekcyrl");
   set_id(({"zekcyrl","zek'cyrl","Zek'cyrl","Zekcyrl","drow","scroll keeper","keeper","keeper of scrolls","mage"}));
   set_short("%^RESET%^%^BLUE%^Zek'cyrl Ghorred'Malac, keeper of scrolls%^RESET%^");
   set_long("%^BLUE%^Zek'cyrl appears to be in his prime, and stands with dignified, perhaps even arrogant poise as "
"he surveys his customers.  He bears all the trappings of %^CYAN%^no%^BOLD%^%^CYAN%^b%^BOLD%^%^GREEN%^i%^RESET%^"
"%^GREEN%^li%^BOLD%^%^GREEN%^t%^RESET%^%^GREEN%^y%^BLUE%^, from his bearing, to his fine garments and the insignia he "
"bears, to his soft and uncalloused hands that hint at never having seen a day's hard work.  %^RESET%^S%^BOLD%^%^WHITE%^n"
"%^RESET%^owy-wh%^BOLD%^%^WHITE%^it%^RESET%^e %^BLUE%^hair that frames a fine-featured elven face, set with piercing "
"%^BOLD%^%^CYAN%^i%^BLUE%^c%^CYAN%^e-b%^BLUE%^l%^CYAN%^ue %^RESET%^%^BLUE%^eyes.  He seems never to have quill and "
"parchment out of reach, surrounded by them here as he is.%^RESET%^");
   set_gender("male");
   set_race("drow");
   set_body_type("human");
   set("aggressive",0);
   set_hd(18,2);
   set_level(22);
   set_class("mage");
   set_mlevel("mage",22);
   set_guild_level("mage",22);
   set_alignment(9);
   add_money("gold", random(500));
   set_property("magic resistance",25);
   set_overall_ac(-10);
   set_stats("strength",18);
   set_stats("intelligence",18);
   set_max_hp(200+random(50));
   set_hp(query_max_hp());
   set_exp(300);
   set_spell_chance(95);
   set_spells(({"cone of cold", "cone of cold", "powerword stun", "magic missile", "magic missile", "frost orb", "frost orb", "phantom guardians", "disintegrate", "chain lightning" }));
   set_property("no bow",1);

   spells_sold=([
     "acid orb":33000,
     "blink":25000,
     "darkness":10000,
     "detect invisibility":25000,
     "detect scrying":60000,
     "dispel magic":30000,
     "disintegrate":80000,
     "fireball":34000,
     "fly":40000,
     "frost orb":33000,
     "hideous laughter":18000,
     "hold person":31000,
     "ice storm":46000,
     "identify":3400,
     "invisibility":23000,
     "gust of wind":40000,
     "lightning bolt":31000,
     "lightning orb":33000,
     "magic mirror":150000,
     "meteor swarm":90000,
     "monster summoning iv":32000,
     "monster summoning vi":42000,
     "powerword stun":78000,
     "prismatic spray":68000,
     "protection from scrying":41000,
     "scorcher":25000,
     "shout":42000,
     "sonic orb":33000,
     "sonic shield":40000,
     "spider climb":18000,
     "static field":40000,
     "stoneskin":100000, 
     "summon companion":6000,
     "tongues":25000,
     "vampiric touch":39000, 
     "wall of fire":40000,
     "water breathing":25000,
     "web":21000
   ]);
 
   for(i=0;i<sizeof(spells_sold);i++)
     spells_sold[keys(spells_sold)[i]] += random(5000);
   spells = ({});
   spells_to_sell = ([]);
   for(j = 1;j<20;j++)
     spells = spells + ({keys(spells_sold)[random(sizeof(keys(spells_sold)))]});
   spells = distinct_array(spells);
   for(j=0;j<sizeof(spells);j++)
     spells_to_sell[spells[j]] = spells_sold[spells[j]];
   set_spells_sold(spells_to_sell);
   set_spoken("drow");
}

int __Pickup(string str){
        if(TP->is_class("mage") || avatarp(TP)) return ::__Pickup(str);
        tell_room(ETO,"Zek'cyrl sneers: You?  Begone, you're not worthy of one of these.");
}

int __Buy(string str){
        if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return ::__Buy(str);
        tell_room(ETO,"Zek'cyrl sneers: You?  Begone, you're not worthy of one of these.");
}

int __List(string str){
        if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return ::__List(str);
        tell_room(ETO,"Zek'cyrl sneers: You?  Begone, you're not worthy of one of these.");
}

int __Sell(string str){
        if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return ::__Sell(str);
        tell_room(ETO,"Zek'cyrl sneers: You?  Begone, you're not worthy of one of these.");
}

int __Help(string str){
        if(TP->is_class("mage") || TP->is_class("bard") || TP->is_class("sorcerer") || avatarp(TP)) return ::__Help(str);
        tell_room(ETO,"Zek'cyrl sneers: You?  Begone, you're not worthy of one of these.");
}