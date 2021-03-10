//Updated to inherit from common studded - Octothorpe 6/8/09
#include <std.h>

inherit "/d/common/obj/armour/studded.c";

string owner;
int uses;
int query_uses(){return uses;}
object ob, ob1, ob2, ob3, ob4, ob5;

void create(){
   ::create();
   set_name("body armor");
   set_id(({ "body armor", "armor", "leather", "mesh","scorpion armor" }));
   set_short("%^BOLD%^%^BLACK%^Carapace of the %^RESET%^%^GREEN%^Sc%^BOLD%^%^BLACK%^o%^RESET%^%^GREEN%^rp"
"%^BOLD%^%^BLACK%^i%^RESET%^%^GREEN%^on %^BOLD%^%^GREEN%^L%^RESET%^%^GREEN%^or%^BOLD%^%^GREEN%^d%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^Black leather carapace%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This suit of armor is made of a strange leather, hardened near to the strength"
" of metal.  All pieces of it fit perfectly together and allow completely free movement.  Designs cover the"
" armor, almost seeming to extend outward slightly from the actual armor.  Eight legs wrap around the center"
" of the armor, encasing the wearer.  The image of a %^RESET%^%^WHITE%^bone %^BOLD%^%^BLACK%^ridge connects each"
" of the eight legs along the back of the armor.  At the bottom of the armor in the back a segmented tail starts,"
" wraping around the armor once in an upwards spiral and going over the left shoulder leaving the end of the"
" tail just over the left breast of the armor. Each leg and the tail are outlined with a faint dark"
" %^RESET%^%^GREEN%^green%^BOLD%^%^BLACK%^.  A symbol is pictured on the stinger of the tail.  A circle,"
" created by a scorpions tail and a curved dagger, connecting hilt to stinger and blade tip to base.  The"
" tail and dagger are dyed %^RESET%^%^BLUE%^blue %^BOLD%^%^BLACK%^with hints of %^RESET%^%^RED%^red"
" %^BOLD%^%^BLACK%^along the stinger and blade tip, with center of the circle remaining black.%^RESET%^
\n");
   set_value(15000);
   set_lore("%^BOLD%^%^BLACK%^This armor has been rumored to have been around for quite some time, and was owned"
" by a deadly desert warrior who could call upon the aid of scorpions by willing them to come to him.  Little"
" else is known of the warrior, or his fate.%^RESET%^");
   set_size(2);
   while((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   set_wear((:TO,"wear_func":));
   set_remove((:TO,"remove_func":));
   uses = random(1000)+1000;
}

int wear_func(){
   if(member_array("%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"You have not earned the right to make use of this item.");
     return 0;
   }
   if((int)ETO->query_level() < 35) {
     tell_object(ETO,"The armor doesn't seem to fit you.");
     return 0;
   }
   tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The armor seems to take on an eerie presence as "+ETO->query_cap_name()+" wears it and the area is suddenly filled with the smell of fear and dark places.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLACK%^A strange yet oddly familiar feeling overcomes you as you slip on the armor.%^RESET%^");
   return 1;
}
int remove_func(){
   tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->query_cap_name()+" seems more placid as "+ETO->query_subjective()+" takes the armor off.%^RESET%^",ETO);
   tell_object(ETO,"%^BOLD%^%^BLACK%^Taking off the armor leaves you feeling vulnerable and open.%^RESET%^");
   return 1;
}
void init() {
    ::init();
    add_action("will","will");
}
void will(string str){
   if(!objectp(ETO)){
   return 1; 
   }
   if(!TO->query_worn()){ 
	tell_object(TP,"%^BOLD%^%^BLACK%^You must be wearing the armor to command the beasts of the dark!%^RESET%^");
   return 1; 
   }
   if(present("prscorpion",environment(ETO))){
	tell_object(TP,"%^RESET%^%^ORANGE%^There are already scorpions protecting you!%^RESET%^");
   return 1; 
   }
   if(uses<1){
	tell_object(TP,"%^BOLD%^%^BLACK%^The armor has no more magic.%^RESET%^");
   return 1;
   }  
   if(!str) {             
	tell_object(TP,"%^BOLD%^%^BLACK%^You mean will the scorpions to you?%^RESET%^");
   return 1;
   }
   if(str == "scorpions"||str=="the scorpions"||str=="the scorpions to come"||str=="the scorpions to come to me"){
	tell_object(TP,"%^BOLD%^%^BLACK%^You close your eyes and put your mind somewhere else.  Slowly the ground shivers and begins to crack, and little black scorpions begin to crawl out of the cracks!%^RESET%^");
     tell_room(environment(ETO),"%^BOLD%^%^BLACK%^As "+ETOQCN+" closes "+ETO->query_possessive()+" eyes and begins to chant some gutteral language, tiny cracks begin to form, from which several small scorpions scamper out to aid "+ETO->query_objective()+"!%^RESET%^",ETO);
      ob=new("/d/islands/common/obj/scorp.c");
      ob->move(environment(ETO));
      ob->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob);
      ob1=new("/d/islands/common/obj/scorp.c");
      ob1->move(environment(ETO));
      ob1->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob1);
      ob2=new("/d/islands/common/obj/scorp.c");
      ob2->move(environment(ETO));
      ob2->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob2);     
      ob3=new("/d/islands/common/obj/scorp.c");
      ob3->move(environment(ETO));
      ob3->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob3);
      ob4=new("/d/islands/common/obj/scorp.c");
      ob4->move(environment(ETO));
      ob4->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob4);
      ob5=new("/d/islands/common/obj/scorp.c");
      ob5->move(environment(ETO));
      ob5->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob5);
      uses --;
      return 1;
   }
}

int query_size(){ 
    if(living(ETO)) 
        return ETO->query_size();
    else return 1;

}
