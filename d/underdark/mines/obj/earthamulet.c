//Octothorpe (10/27/08)
//Underdark Mining Caverns, Amulet of Earth Control

#include <std.h>
#include <daemons.h>
#include "../defs.h"
#define WAIT_TIME 9600
inherit ARMOUR;
int used_time;
object ob;

void create(){
   ::create();
   set_name("earth amulet");
   set_id(({"amulet", "callarduran", "grumbar", "ruby amulet", "ruby","symbol"}));
   set_short("%^BOLD%^%^RED%^H%^RESET%^%^RED%^o%^BOLD%^%^RED%^ly Symb"+
      "%^RESET%^%^RED%^o%^BOLD%^%^RED%^l of C%^RESET%^%^RED%^a"+
      "%^BOLD%^%^RED%^ll%^RESET%^%^RED%^a%^BOLD%^%^RED%^rd%^RESET%^"+
      "%^RED%^u%^BOLD%^%^RED%^r%^RESET%^%^RED%^a%^BOLD%^%^RED%^n Sm"+
      "%^RESET%^%^RED%^oo%^BOLD%^%^RED%^thh%^RESET%^%^RED%^a%^BOLD%^"+
      "%^RED%^nds%^RESET%^");
   set_obvious_short("%^RESET%^an uncut %^RED%^r%^BOLD%^%^RED%^u"+
      "%^RESET%^%^RED%^by %^RESET%^amulet");
   set_long("This amulet is no more than an uncut hunk of %^RED%^r"+
      "%^BOLD%^%^RED%^u%^RESET%^%^RED%^by %^RESET%^suspended by a "+
      "%^ORANGE%^leather %^RESET%^thong.  The thong appears to be "+
      "melded to the gem itself, as it appears there are no tool marks, "+
      "or a continuous hole through it.  Even in its natural state, "+
      "the %^RED%^r%^BOLD%^%^RED%^u%^RESET%^%^RED%^by %^RESET%^is "+
      "nothing short of magnificent. It is about as large as a clenched "+
      "human fist, yet despite its rough nature and heft, it appears "+
      "that it would hang comfortably around person's neck.  Surely "+
      "this find would net a small fortune on the surface. You have "+
      "the feeling that you could %^BOLD%^invoke %^RESET%^the aid of "+
      "powerful entity with this amulet.");
   set_lore("This amulet is a holy symbol of the Callarduran "+
      "Smoothhands, the name that Grumbar is known by within the "+
      "gnomish civilization. The relative size of a holy symbol denotes "+
      "the rank of the bearer within the Callardurian faith. One of "+
      "this size would only be found in the possession of the most "+
      "honored of the svirfneblin. It is rumored that besides being a "+
      "valuable, physical token of faith, they are imbued with the "+
      "power over stone and the denizens of the Elemental Plane of "+
      "Earth. According to svirfneblin legend, a similar holy amulet "+
      "aided Sixth Facet Aradesh Farnonsten in the Battle of the Spider "+
      "Vault, nearly 600 years ago. Through the power of the amulet, "+
      "and the intercession of Callarduran Smoothhands himself, "+
      "Farnonsten's makeshift army of xorn and earth elementals held "+
      "off 2,000 drow marauders long enough to collapse the cavern "+
      "ceiling on top of them.");
   set_property("lore",22);
   set_weight(6);
   set_value(8000+random(3000));
   set_property("enchantment",3);
   set_type("clothing");
   set_limbs(({"neck"}));
   set_size(-1);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_ac(0);
}

int wear_fun(){
   object *stuff;
   int i, flag;

   stuff = ETO->all_armour(); //ring type, so added a check to prevent stacking; enchanted item!
   for(i=0;i<sizeof(stuff);i++) {
      if(!objectp(stuff[i])) continue;
      if(base_name(stuff[i]) == "/d/underdark/mines/obj/earthamulet") flag = 1;
   }
   if(flag) {
      tell_object(ETO,"The magic of the amulet already worn prevents you from wearing this one!");
      return 0;
   }
   if(base_name(ETO) == "/d/underdark/mines/mon/gnowarden") return 1;
   if(base_name(ETO) != "/d/underdark/mines/mon/gnowarden"){
      if((int)ETO->query_highest_level() < 15 && member_array("Assisted the Kobolds",ETO->query_mini_quests()) == -1 && member_array("Assisted the Svirfneblin",ETO->query_mini_quests()) == -1){
      tell_object(ETO,"%^BOLD%^You require more instruction before you "+
         "can use this holy relic!%^RESET%^");
      return 0;
      }
   }
   if((string)ETO->query_diety() == "akadi"){
      tell_object(ETO,"%^ORANGE%^The amulet grumbles angrily as you put "+
         "it around your neck, or perhaps that is the ground beneath "+
         "your feet...%^RESET%^");
      tell_room(EETO,"%^BOLD%^The earth itself enters a rage as "+ETOQCN+" "+
         "wears the amulet.%^RESET%^",ETO);
      ETO->do_damage("torso",random(63)+30);
      return 1;
   }
   if((string)ETO->query_diety() == "grumbar"){
      tell_object(ETO,"%^ORANGE%^As you wear the amulet, a comforting and "+
         "familiar presence flows up from the ground beneath your "+
         "feet.%^RESET%^");
      tell_room(EETO,"%^ORANGE%^As "+ETOQCN+" carefully places the "+
         "amulet around "+ETO->QP+" neck, the %^RED%^r%^BOLD%^%^RED%^u"+
         "%^RESET%^%^RED%^by %^ORANGE%^glows warmly as rests over their "+
         "heart.%^RESET%^",ETO);
      return 1;
   }
   tell_object(ETO,"%^ORANGE%^The amulet feels like it weighs a "+
      "ton as it falls on your chest.%^RESET%^");
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" grimaces slightly at the "+
      "heft of the amulet as the put it around "+ETO->QP+" "+
      "neck.%^RESET%^",ETO);
   if((string)ETO->query_race() == "gnome") set_item_bonus("wisdom",1);
   else set_item_bonus("wisdom",0);
   return 1;
}

int remove_fun(){
   if((string)ETO->query_diety() == "akadi"){
      tell_object(ETO,"%^ORANGE%^The anger of the amulet lessens as you "+
         "remove it from your neck, but it makes the most of its last "+
         "opportunity at vengeance!%^RESET%^");
      tell_room(EETO,"%^BOLD%^The amulet gets its last licks in as the "+
         "blasphemer removes it.%^RESET%^",ETO);
      ETO->do_damage("torso",random(25)+50);
      return 1;
   }
   if((string)ETO->query_diety() == "grumbar"){
      tell_object(ETO,"%^ORANGE%^The presence of the Earthlord receeds "+
         "ever so slightly as you remove the amulet.%^RESET%^");
      tell_room(EETO,"%^ORANGE%^"+ETOQCN+" sighs wistfully as the "+
         "%^RED%^r%^BOLD%^%^RED%^u%^RESET%^%^RED%^by %^ORANGE%^is "+
         "removed from "+ETO->QP+" chest.%^RESET%^",ETO);
      if(!random(40)){
         if(ETO->query_hp() < ETO->query_max_hp()){
            new("/cmds/spells/c/_cure_serious_wounds.c")->use_spell(ETO,ETO,21,100,"cleric");
         }
      }   
      return 1;
   }
   tell_object(ETO,"%^ORANGE%^You give a sigh of relief as you "+
      "remove the dense amulet.%^RESET%^");
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" gives a sigh of relief "+
      "as they remove the heavy amulet from around "+ETO->QP+" "+
      "neck.%^RESET%^",ETO);
   return 1;
}

void init(){
   ::init();
   if(living(ETO)){
      add_action("invoke_fun","invoke");
   }
}

void failure(){
   tell_object(ETO,"%^BOLD%^You must wait a little bit longer before "+
      "beseeching the Earthlord for aid.\n%^RESET%^");
   return;
}

int invoke_fun(){
   if(!(query_worn())){
      tell_object(ETO,"%^BOLD%^You need to wear the amulet to be able "+
         "to do that.%^RESET%^");
      return 1;
   }
   if(WAIT_TIME > (time() - used_time)){
      failure();
      return 1;
   }
   if((string)ETO->query_diety() == "akadi"){
      tell_object(ETO,"%^ORANGE%^The amulet almost seems too eager to "+
         "grant your request...the ground begins to rumble, and "+
         "suddenly an earth elemental forms out of the ground, and "+
         "turns to attack you!%^RESET%^");
      tell_room(EETO,"%^ORANGE%^The ground begins to rumble, and "+
         "suddenly an earth elemental forms out of the ground, and "+
         "turns to attack "+ETOQCN+".%^RESET%^",ETO);
      used_time = time();
	  ob = new(MON+"earthelement");
      ob->move(EETO);
      ETO->add_follower(ob);
      ob->force_me("kill "+(string)TP->query_name());
      ob->force_me("kill "+(string)TP->query_name());
      return 1;
   }
   tell_object(ETO,"%^ORANGE%^The amulet begins to %^RED%^glow "+
      "%^ORANGE%^softly, and suddenly the ground begins to rumble "+
      "as an earth elemental forms out of the earth and moves to "+
      "protect you!%^RESET%^");
   tell_room(EETO,"%^ORANGE%^The ground begins to rumble, and suddenly "+
      "an earth elemental forms out of the ground, and moves to protect "+
      ""+ETOQCN+".%^RESET%^",ETO);
   used_time = time();
   ob = new(MON+"earthelement");
   ob->move(EETO);
   ETO->add_follower(ob);
   ETO->add_protector(ob);
   return 1;
}