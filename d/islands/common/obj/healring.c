//Changed to 35+ to wear, per Tsera - Octothorpe 7/16/09
// fixed to looking for rop IDs, was missed. N, 3/17
#include <std.h>
#include <daemons.h>
inherit ARMOUR;

#define WAIT_TIME 14400
#define WAIT_TIME2 5

int used_time, used_time2, uses;
int query_uses(){return uses;}

void create(){
   ::create();
   set_name("ring of healing");
   set_id(({"ring","ring of healing","platinum ring","healing ring","platinum ring of healing","rop","ring of protection","greater ring of protection"}));
   set_obvious_short("%^BOLD%^%^WHITE%^A sparkling platinum and gold ring%^RESET%^");
   set_short("%^BOLD%^%^WHITE%^Ring of Healing%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This sparkling ring is made from the purest platinum and white gold.  The two metals twist around one another and meet at the top in the image of two peering eyes that seem to be ever watchful of its wearer.%^RESET%^");
   set_weight(2);
   set_value(3231);
   set_type("ring");
   set_limbs(({"right hand","left hand"}));
   set_size(2);
   set_property("no curse",1);
   set_property("enchantment",6);
   set_item_bonus("healing",4);
   set_item_bonus("damage resistance",10);
   set_item_bonus("magic resistance",1);
   set_ac(0);
   set_wear((:TO,"wearme":));
   set_heart_beat(1);
}

int wearme(string str){
    object *stuff;
    int i,j, flag;
   if(member_array("%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"You have not earned the right to make use of this item.");
     return 0;
   }
   if((int)ETO->query_level() < 35) {
     tell_object(ETO,"The ring doesn't seem to fit you.");
     return 0;
   }
    stuff = TP->all_armour();
    j = sizeof(stuff);
    for(i=0;i<j;i++) {
        if(!objectp(stuff[i])) continue;
        if((string)stuff[i]->query_type() == "ring") {
            if(member_array("ring of protection",stuff[i]->query_id()) != -1) {
                flag = 1;
                break;
            }
        }
    }
    if(flag) {
        write("The magic of the ring already worn prevents you from wearing this one!");
        return 0;
    }
   tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+" looks more confident as "+ETO->query_subjective()+" slips on the ring.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^WHITE%^A feeling of safety overcomes you as you wear the ring.%^RESET%^");
   return 1;  
}

void heart_beat(){
   if(!objectp(ETO)){
   return ;
   }
   if(uses>0){
   used_time = time();
   }
   if(WAIT_TIME < (time() - used_time)) {
   uses=3;
   }
   if(WAIT_TIME2 > (time() - used_time2)) {
   return;
   }
   if(!TO->query_worn()){ 
   return ; 
   }  
   if(ETO->query_hp()<((int)ETO->query_max_hp())/3&&!ETO->query_unconscious()&&!ETO->query_bound()&&uses>0){
      tell_object(ETO,"%^BOLD%^%^WHITE%^The ring feels your pain and heals you completely!%^RESET%^");
   ETO->add_hp(ETO->query_max_hp());
      used_time2 = time();
      uses --;
      return 1;
   }
}

void set_used_time(int x) {
   used_time = x;
}

void set_used_time2(int y) {
   used_time2 = y;
}
