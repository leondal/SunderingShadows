//Octothorpe (12/18/08)
//Underdark Mining Caverns, Dragon Scale Cloak
//Based upon Crimson Bracers from Derro
///d/dagger/derro/obj/crimson_bracers.c
//Uses modified copies of Fire Shield cleric spell
///cmds/priest/_fire_shield.c

#include <std.h>
#include <daemons.h>
#define WAIT_TIME 9600

inherit ARMOUR;
int used_time;
object *mons = ({});

void create(){
   ::create();
   set_name("dragon scale cloak");
   set_id(({"cloak","dragonscale cloak","scale cloak","dragon cloak","dragon scale cloak"}));
   set_short("%^BOLD%^%^YELLOW%^dragon %^RED%^s%^BLUE%^c%^GREEN%^a"+
      "%^WHITE%^l%^BLACK%^e %^YELLOW%^cloak%^RESET%^");
   set_long("%^BOLD%^%^YELLOW%^This exquisite cloak is constructed "+
      "entirely of numerous dragon %^RED%^s%^BLUE%^c%^GREEN%^a%^WHITE%^"+
      "l%^BLACK%^e%^YELLOW%^s. Each type of chromatic dragon is "+
      "represented on the cloak. Each %^RED%^s%^BLUE%^c%^GREEN%^a"+
      "%^WHITE%^l%^BLACK%^e %^YELLOW%^appears to be from different "+
      "dragon, with some of the same color bearing differing lusters "+
      "and thickness. Some of the %^RED%^s%^BLUE%^c%^GREEN%^a%^WHITE%^"+
      "l%^BLACK%^e%^YELLOW%^s appear to be loose, perhaps you can "+
      "%^RESET%^%^ORANGE%^pluck %^BOLD%^%^YELLOW%^one off the cloak. "+
      "The scores of individual dragons it required to produce this "+
      "cloak suggests its great value and rarity. The magic emanating "+
      "from the cloak crackles like static electricity at the slightest "+
      "touch.%^RESET%^\n");
   set_lore("Those who study dragons speak of many things that dragon "+
      "magic can do which mortal magic cannot.  Even with the Weave, "+
      "there are those scholars who attest that dragon magic is very "+
      "different then the spells conjured by magi.  One branch of "+
      "dragon study suggests that dragons aren't as much mortal but "+
      "conjurations of magic.  Physical embodiments of pure magic, and "+
      "it is this connection, or state of being, which causes dragon "+
      "magic to be as powerful and different as it is.  Some lore "+
      "suggests that because dragons are made of magic that their "+
      "body parts can be collected and harnessed for raw arcane "+
      "power.  This may account for why many mages, apothecaries, "+
      "necromancers and scholars alike vie for the remains of dragon "+
      "kills.  The potential within the scales alone is said to be "+
      "great.  So much so, that those who wear or carry devices made "+
      "of dragon remains will often experience unexpected magical "+
      "effects.");
   set_property("lore difficulty",14);
   set_type("clothing");
   set_limbs(({"neck"}));
   set_weight(10);
   set_size(-1);
   set_value(5250+random(5250));
   set_property("enchantment",3);
   set_item_bonus("magic resistance",1);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_ac(0);
}

int wear_fun(){
   if(base_name(ETO) == "/d/underdark/mines/mon/kobsorc") return 1;
   if(base_name(ETO) != "/d/underdark/mines/mon/kobsorc"){
      if((int)ETO->query_highest_level() < 15 && member_array("Assisted the Kobolds",ETO->query_mini_quests()) == -1 && member_array("Assisted the Svirfneblin",ETO->query_mini_quests()) == -1){
         tell_room(EETO,"%^BOLD%^A surge of %^CYAN%^el%^WHITE%^e%^CYAN%^"+
            "ctric%^WHITE%^i%^CYAN%^ty %^YELLOW%^shocks %^WHITE%^"+ETOQCN+" "+
            "as they try wearing the cloak.%^RESET%^",ETO);
         tell_object(ETO,"%^BOLD%^You are %^YELLOW%^shocked %^WHITE%^by "+
            "the cloak as you try to put it on!%^RESET%^");
      return 0;
      }
   }
   tell_room(EETO,"%^BOLD%^%^CYAN%^"+ETOQCN+" flinches as the cloak "+
      "falls upon their shoulders.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^CYAN%^A moderate el%^WHITE%^e%^CYAN%^"+
      "ctr%^WHITE%^i%^CYAN%^c charge shocks you as you wear the cloak"+
      ".%^RESET%^");
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^BOLD%^%^CYAN%^A discharge of el%^WHITE%^e%^CYAN%^"+
      "ctric%^WHITE%^i%^CYAN%^ty arcs off "+ETOQCN+" towards the "+
      "cloak, as "+ETOQCN+" removes it.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^CYAN%^A charge of el%^WHITE%^e%^CYAN%^"+
      "ctric%^WHITE%^i%^CYAN%^ty jumps off your body, and is absorbed "+
      "within the cloak.%^RESET%^");
   return 1;
}

void init(){
   ::init();
   if(living(ETO)){
      add_action("pluck_fun","pluck");
   }
}

void failure(){
   tell_object(ETO,"%^BOLD%^The magic of the cloak requires more time "+
      "to recharge.\n%^RESET%^");
   return;
}

int pluck_fun(string str){
   int i;
   object *inven;
   object *live;
   inven = all_living(EETO);
   live = filter_array(inven, "is_non_immortal",
FILTERS_D);
   if(!str){
      tell_object(ETO,"%^BOLD%^Pluck what?%^RESET%^");
      return 1;
   }  
   if(!(query_worn())){
      tell_object(ETO,"You need to wear the cloak to be able to do that.");
      return 1;
   }
   if(WAIT_TIME > (time() - used_time)){
      failure();
      return 1;
   }

   if(str == "scale"){
      used_time = time();
      if(ETO->query_property("fire shield")){
         failure();
         return 1;
      }
      ETO->force_me("emote plucks a scale off of their cloak and throws "+
         "it at their feet.");
            switch(random(5)){
               case 0:
                  if(!random(1000)){
                     tell_object(ETO,"%^BOLD%^As the dragon scale "+
                        "hits the ground it detonates in a violent, "+
                        "%^CYAN%^bluish %^WHITE%^blast...%^RED%^oops"+
                        "!%^RESET%^");
                     tell_room(EETO,"%^BOLD%^It becomes readily apparent "+
                        "that you're having a bad day as the dragon "+
                        "scale is consumed by a %^CYAN%^bluish%^WHITE%^ "+
                        "flaming apocalpyse, that is expanding with "+
                        "great haste toward your person. You should "+
                        "have known that hanging around with "+ETOQCN+" was "+
                        "a bad idea.%^RESET%^");
                     for(i=0;i<sizeof(live);i++) {
                        if(!objectp(live[i])) continue;
                        if(live[i] == ETO) continue;
                        tell_object(live[i],"%^BOLD%^%^CYAN%^The blast "+
                           "burns you with great effect, and knocks you "+
                           "back!%^RESET%^");
                        live[i]->do_damage("torso",random(200)+150);
                        live[i]->set_paralyzed(6+random(4),"%^BOLD%^You "+
                           "are stunned by the concussion!%^RESET%^");
                     }
                  return 1;   
                  }
                  else{
                     new("/d/underdark/mines/spell/_fire_shield")->use_spell(ETO,0,25,100);
                     tell_object(ETO,"%^BOLD%^The %^RED%^r%^RESET%^"+
                        "%^RED%^e%^BOLD%^d %^WHITE%^scale transforms "+
                        "into a protective conflagration around you"+
                        "!%^RESET%^");
                     tell_room(EETO,"%^BOLD%^The %^RED%^r%^RESET%^"+
                        "%^RED%^e%^BOLD%^d %^WHITE%^scale transforms "+
                        "into a protective conflagration around "+
                        ""+ETOQCN+"!%^RESET%^",ETO);
                     return 1;
                  }
                  break;                  
               case 1:
                  if(!random(4)){ 
                     ETO->set_property("wail immune",1);
                     call_out("geon",0);
                     tell_object(ETO,"%^BOLD%^You find an unique scale "+
                        "hidden amongst the chromatic dragon scales! The "+
                        "%^RESET%^%^GREEN%^em%^BOLD%^er%^RESET%^a%^BOLD%^"+
                        "%^GREEN%^l%^RESET%^%^GREEN%^d %^BOLD%^%^WHITE%^"+
                        "scale hits the ground, and suddenly transforms "+
                        "into a faceted gem that protects you!%^RESET%^");
                     tell_room(EETO,"%^BOLD%^The %^RESET%^%^GREEN%^em"+
                        "%^BOLD%^er%^RESET%^a%^BOLD%^%^GREEN%^l"+
                        "%^RESET%^%^GREEN%^d %^BOLD%^%^WHITE%^scale "+
                        "transforms into a faceted gem that protects "
                        ""+ETOQCN+"!",ETO);
                  return 1;
                  }
                  else{
                     new("/d/underdark/mines/spell/_acid_shield.c")->use_spell(ETO,0,25,100);
                     tell_object(ETO,"%^BOLD%^The %^BOLD%^%^BLACK%^bl"+
                        "%^RESET%^a%^BOLD%^%^BLACK%^ck %^WHITE%^scale "+
                        "transforms into a protective shield of %^BOLD%^"+
                        "%^BLACK%^a%^GREEN%^c%^RESET%^i%^BOLD%^%^BLACK%^"+
                        "d%^WHITE%^!%^RESET%^");
                     tell_room(EETO,"%^BOLD%^The %^BOLD%^%^BLACK%^bl"+
                        "%^RESET%^a%^BOLD%^%^BLACK%^ck %^WHITE%^scale "+
                        "transforms into a protective shield of %^BOLD%^"+
                        "%^BLACK%^a%^GREEN%^c%^RESET%^i%^BOLD%^%^BLACK%^"+
                        "d %^WHITE%^around "+ETOQCN+"!%^RESET%^",ETO);
                     return 1;
                  }
                  break;
               case 2:
                  if(!random(4)){
                     call_out("aisl",0);
                     tell_object(ETO,"%^BOLD%^You find an unique scale "+
                        "hidden amongst the chromatic dragon scales! The "+
                        "%^CYAN%^p%^BLUE%^r%^GREEN%^i%^YELLOW%^s%^RED%^m"+
                        "%^MAGENTA%^a%^CYAN%^t%^BLUE%^i%^GREEN%^c "+
                        "%^WHITE%^scale hits the ground, leaving an "+
                        "inky %^BOLD%^%^BLACK%^black %^WHITE%^"+
                        "fog, from which a shape begins to emerge"+
                        "to protect you.%^RESET%^");
                     tell_room(EETO,"%^BOLD%^The %^CYAN%^p%^BLUE%^r"+
                        "%^GREEN%^i%^YELLOW%^s%^RED%^m%^MAGENTA%^a"+
                        "%^CYAN%^t%^BLUE%^i%^GREEN%^c %^WHITE%^scale "+
                        "transforms into an inky %^BOLD%^%^BLACK%^black "+
                        "%^WHITE%^fog, from which a shape emerges to "+
                        "protect "+ETOQCN+"!%^RESET%^",ETO);
                     return 1;
                  }
                  else{
                     new("/d/underdark/mines/spell/_ice_shield.c")->use_spell(ETO,0,25,100);
                     tell_object(ETO,"%^BOLD%^The wh%^CYAN%^i%^WHITE%^te "+
                        "scale transforms into an expanding cocoon of i"+
                        "%^CYAN%^c%^WHITE%^e around you!%^RESET%^");
                     tell_room(EETO,"%^BOLD%^The wh%^CYAN%^i%^WHITE%^te "+
                        "scale transforms into an expanding cocoon of i"+
                        "%^CYAN%^c%^WHITE%^e around "+ETOQCN+"!"+
                        "%^RESET%^",ETO);
                     return 1;
                  }
                  break;
               case 3:
                  new("/d/underdark/mines/spell/_electric_shield.c")->use_spell(ETO,0,25,100);
                  tell_object(ETO,"%^BOLD%^The %^BLUE%^blu%^CYAN%^e "+
                     "%^WHITE%^scale transforms into a shower of "+
                     "%^YELLOW%^sp%^RESET%^%^YELLOW%^a%^BOLD%^rks "+
                     "%^WHITE%^that gravitate towards your body, "+
                     "forming an electric shield around you!%^RESET%^");
                  tell_room(EETO,"%^BOLD%^The %^BLUE%^blu%^CYAN%^e "+
                     "%^WHITE%^scale transforms into a shower of "+
                     "%^YELLOW%^sp%^RESET%^%^YELLOW%^a%^BOLD%^rks "+
                     "%^WHITE%^that form a protective shield around "+
                     ""+ETOQCN+"!%^RESET%^",ETO);
                  return 1;
                  break;
               case 4:
                  new("/d/underdark/mines/spell/_gas_shield.c")->use_spell(ETO,0,25,100);
                  tell_object(ETO,"%^BOLD%^The %^GREEN%^gr%^RESET%^"+
                     "%^GREEN%^ee%^BOLD%^n %^WHITE%^scale transforms "+
                     "into a thick cloud of %^GREEN%^g%^RESET%^"+
                     "%^YELLOW%^a%^BOLD%^%^GREEN%^s %^WHITE%^around "+
                     "you!%^RESET%^");
                  tell_room(EETO,"%^BOLD%^The %^GREEN%^gr%^RESET%^"+
                     "%^GREEN%^ee%^BOLD%^n %^WHITE%^scale transforms "+
                     "into a thick cloud of %^GREEN%^g%^RESET%^"+
                     "%^YELLOW%^a%^BOLD%^%^GREEN%^s %^WHITE%^around "+
                     ""+ETOQCN+"!%^RESET%^",ETO);
                  return 1;
                  break;
            }         
   }
}

void geon(){
   object ob;
   ETO->set_property("fire shield",1);
   ETO->set_property("spelled", ({TO}) );
   ob = new("/d/underdark/mines/spell/emgem.c");
   ob->move(EETO);
   ETO->add_follower(ob);
   ETO->add_protector(ob);
   ob->set_property("spelled", ({TO}) );
   ob->set_property("spell_creature", TO);
   ob->set_property("spell", TO);
   ob->add_id("summoned monster");
   ob->add_id(ETO->query_name()+"monster");
   call_out("dest",100);
}

void aisl(){
   object ob;
   ETO->set_property("fire shield",1);
   ETO->set_property("spelled", ({TO}) );
   ob = new("/d/underdark/mines/spell/nightmare.c");
   ob->move(EETO);
   ETO->add_follower(ob);
   ETO->add_protector(ob);
   ob->set_property("spelled", ({TO}) );
   ob->set_property("spell_creature", TO);
   ob->set_property("spell", TO);
   ob->add_id("summoned monster");
   ob->add_id(ETO->query_name()+"monster");
   call_out("dest",100);
}

void dest(){
   int i;
   for (i=0;i<sizeof(mons);i++) {
      if (objectp(mons[i])) {
         ETO->remove_protector(mons[i]);
         ETO->remove_property("fire shield");
         mons[i]->die();
      }
   }
}