// /d/islands/tonerra/mon/enchanter.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"
#define SHOP "/d/islands/tonerra/compshop"

inherit MONSTER;

void create(){
   ::create();
   set_name("Innara");
   set_short("%^BOLD%^%^MAGENTA%^Innara, enchantress of Tonerra");
   set_id(({"innara","Innara","enchantress"}));
   set_long(
"   Innara the enchantress of Tonerra is a slight thing. Pretty but
dirty, she catches your eye with a glance and a smile. As you look
carefully you notice she lacks a shadow and as she passes through
those of other objects they seem to disappear. She grins with a
clever, playful grin. This is who wields the enchanting magic that
grants the natives their power. Perhaps she will enchant something
for you."
   );
   set_race("human");
    set_body_type("humanoid");
   set_gender("female");
   set_class("mage");
   set_hd(20,5);
   set_mlevel("mage",20);
   set_exp(2000);
   set_guild_level("mage",150);
   set_spell_chance(100);
   set_spells(({"magic missile","lightning bolt","fireball","scorcher","burning hands"}));
   set_overall_ac(0);
   set_mob_magic_resistance("average");
}

void init(){
   ::init();
   add_action("enchant_me","enchant");
}

int enchant_me(string str){
   object ob, comp;
   int enc,num,num2;
   string getter, room,junk,hold1,hold2,place;

   if(!str) return notify_fail("Enchant what?\n");
   if(!(ob = present(str,TP))) return notify_fail("You don't have a "+str+".\n");
   if(!ob->is_weapon()) {
      force_me("say I will only enchant weapons for outsiders.");
      return 1;
   }


   if(ob->is_weapon()){
       if(ob->query_property("enchantment"))
           enc = ob->query_property("enchantment");
       else enc = 0;
       if(enc < 0){
           TO->force_me("say I cannot enchant a cursed item!");
           return 1;
       }
       if(enc > 10){
           TO->force_me("say I cannot enchant this item further!");
           return 1;
       }
       // for now, cost a ton of money
       if(ob->query_wielded()){
           command("say Please unwield the weapon first.");
           return 1;
       }
       if(!comp = present("specialcomp",TP)){
           command("say You lack the special components I need.");
           getter = "daemon/room_d"->query_new_dest(SHOP);


           if(stringp(getter)){
               //sscanf(getter,"%s&%s",room,junk);
               //sscanf(room,"/d/%s/%s/%s",place,hold1,hold2);

               num = strsrch(getter,"&");
               room = getter[0..(num - 1)];
               place = replace_string(room,"/d/","");
               num2 = strsrch(place,"/");
               place = place[0..(num2 - 1)];

               command("whisper "+TPQN+" The shop selling the component is in the "+place+" area.");
               command("whisper "+TPQN+" rumors say something about "+room->query_short());
               return 1;
           }
           return 1;
       }

       if(!TP->query_funds("gold",50000*enc)){
           TO->force_me("say It will cost you "+(50000 * enc)+" gold to have that enchanted.");
           return 1;
       }
       else{
           comp->remove();
           if (ob->query_property("player enchanted")) {
               force_me("say Very well, you won't be able to change its magic after that yourself, though.");
               ob->remove_property("player enchanted");
           }

           TP->use_funds("gold",50000*enc);
           tell_room(ETO,"Innara looks over "+TPQCN+"'s "+ob->query_name()+" and speaks some strange magical words.\n",TP);
           tell_object(TP,"Innara looks over your "+ob->query_name()+" and speaks some strange magical words.\n");
           enc +=1;
           ob->set_property("enchantment",1);
           if((int)ob->query_property("enchantment") == enc) { // AKA if it didn't curse it!
               ob->set_property("manual enchantment",1);
           }
           else ob->set_property("manual enchantment",-1);
       }
   }
   else
       return notify_fail("You cannot have that enchanted.\n");
}
