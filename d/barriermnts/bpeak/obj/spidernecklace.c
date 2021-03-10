#include <std.h>
inherit ARMOUR;
int uses;
int query_uses(){return uses;}
object ob, ob1, ob2, ob3, ob4, ob5;

void create(){
        ::create();
        set_name("%^BOLD%^%^BLACK%^Spiders call%^RESET%^");
        set_id(({ "necklace", "spider necklace", "spiders call","pendant","spider pendant" }));
        set_short("%^RESET%^A %^BOLD%^%^BLACK%^spider pendant %^RESET%^suspended by a %^BOLD%^silver chain%^RESET%^");
        set_long("%^BOLD%^%^BLACK%^Suspended by a thin %^WHITE%^silver chain %^BLACK%^is a small pendant of dark"
" black spider.  The pendant itself is lifelike in appearance and the spiders outstretched legs are designed to"
" make it appear that the spider is crawling up the wearers chest.  A small inscription has been set into the"
" belly of the spider.\n");
        set_weight(2);
        set_value(2500);
        set_lore(
@AVATAR
%^BOLD%^%^BLACK%^It is said that this is one of the dark necklaces used by the drow race to call upon the spiders they so dearly love.

AVATAR
        );
        set_read("%^BOLD%^BLUE%^%^Beckon them and they shall come.%^RESET%^");
        set_language("drow");
        set_type("ring");
        set_limbs(({"neck"}));
        set_size(2);
        set_wear((:TO,"wearme":));
        uses = random(5)+5;
}
int wearme(string str){
   tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The spider looks like it moves just slightly as "+ETOQCN+" slips on the necklace.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLACK%^You can almost feel the spider move just slightly as you wear the necklace.%^RESET%^");
   return 1;
}
void init() {
    ::init();
    add_action("beckon","beckon");
}
void beckon(string str){
   if(!objectp(ETO)){
   return 1; 
   }
   if(!TO->query_worn()){ 
	tell_object(TP,"%^BOLD%^%^BLACK%^You must be wearing the necklace to use it.%^RESET%^");
   return 1; 
   }
   if(present("prspider",environment(ETO))){
	tell_object(TP,"%^BOLD%^%^BLACK%^There are already spiders protecting you!%^RESET%^");
   return 1; 
   }
   if(uses<1){
	tell_object(TP,"%^BOLD%^%^BLACK%^The necklance has no more magic.%^RESET%^");
      TO->remove();
   return 1;
   }  
   if(!str) {             
	tell_object(TP,"%^BOLD%^%^BLACK%^Beckon what?  The spiders?%^RESET%^");
   return 1;
   }
   if(str == "spiders"||str=="the spiders"||str=="spider"||str=="the spider"){
	tell_object(TP,"%^BOLD%^%^BLACK%^You call forth the magic of the necklace and several small spiders begin to crawl out of nearby cracks to aid you!%^RESET%^");
     tell_room(environment(ETO),"%^BOLD%^%^BLACK%^As "+ETOQCN+" speaks some unknown words, spiders begin to crawl out of nearby cracks to aid "+ETO->query_objective()+"!%^RESET%^",ETO);
      ob=new("/d/barriermnts/bpeak/mon/spider1.c");
      ob->move(environment(ETO));
      ob->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob);
      ob1=new("/d/barriermnts/bpeak/mon/spider1.c");
      ob1->move(environment(ETO));
      ob1->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob1);
      ob2=new("/d/barriermnts/bpeak/mon/spider1.c");
      ob2->move(environment(ETO));
      ob2->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob2);     
      ob3=new("/d/barriermnts/bpeak/mon/spider1.c");
      ob3->move(environment(ETO));
      ob3->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob3);
      ob4=new("/d/barriermnts/bpeak/mon/spider1.c");
      ob4->move(environment(ETO));
      ob4->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob4);
      ob5=new("/d/barriermnts/bpeak/mon/spider1.c");
      ob5->move(environment(ETO));
      ob5->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob5);
      uses --;
      return 1;
   }
}





