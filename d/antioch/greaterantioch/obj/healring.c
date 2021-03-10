//Changed to 35+ to wear, per Tsera - Octothorpe 7/16/09
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
   set_id(({"ring","ring of healing","platinum ring","healing ring","platinum ring of healing"}));
   set_obvious_short("%^BOLD%^%^WHITE%^A sparkling platinum and gold ring%^RESET%^");
   set_short("%^BOLD%^%^WHITE%^Ring of Healing%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This sparkling ring is made from the purest platinum and white gold.  The two metals twist around one another and meet at the top in the image of two peering eyes that seem to be ever watchful of its wearer.%^RESET%^");
   set_weight(2);
   set_value(3231);
   set_type("ring");
   set_limbs(({"right hand","left hand"}));
   set_size(2);
   set_property("enchantment",0);
   set_ac(0);
   set_wear((:TO,"wearme":));
   set_heart_beat(1);
}

int wearme(string str){
   tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+" looks more confident as "+ETO->query_subjective()+" slips on the ring.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^WHITE%^A feeling of safety overcomes you as you wear the ring.%^RESET%^");
   return 1;
}

void init(object ob){
  ::init();
  add_action("use_ring","use");
}

int lift_portcullis(string str){
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
            if(ETO->is_class("mage")) {
	  tell_object(ETO,"The sword plants the words of a spell into your mind"+
		    " and you begin to say them.");
        new("/cmds/spells/p/_prismatic_spray")->use_spell(ETO,mirror,ETO->query_level(),100,"mage");
      }
      else {
	  tell_object(ETO,"The sword overtakes you as you suddenly begin to say"+
		    " the words to a spell.");
        new("/cmds/spells/p/_prismatic_spray")->use_spell(ETO,targ,20,100,"mage");
      }
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
