#include <std.h>
inherit ARMOUR;
int uses;
int query_uses(){return uses;}
object ob, ob1, ob2, ob3, ob4, ob5, ob6, ob7;

void create(){
        ::create();
        set_name("%^BOLD%^%^BLUE%^B%^WHITE%^u%^CYAN%^bb%^BLUE%^l%^WHITE%^e %^CYAN%^ring%^RESET%^");
        set_id(({ "ring", "bubble ring" }));
        set_short("%^BOLD%^%^BLUE%^B%^WHITE%^u%^CYAN%^bb%^BLUE%^l%^WHITE%^e %^CYAN%^ring%^RESET%^");
        set_long("%^BOLD%^%^CYAN%^This is a marvelous little light blue ring.  Magically held in place like"
" the most precious of gems, is a perfectly shaped bubble that reflects many different %^WHITE%^shimmering"
" %^RED%^c%^CYAN%^o%^WHITE%^l%^BLUE%^o%^MAGENTA%^r%^WHITE%^s.  %^CYAN%^Every once in a while, the bubble"
" seems to change shape and reform, ...but it never breaks.\n");
        set_weight(2);
        set_value(250);
        set_type("ring");
        set_limbs(({"right hand","left hand"}));
        set_size(-1);
        set_wear((:TO,"wearme":));
        uses = random(5)+5;
}
int wearme(string str){
   tell_object(ETO,"%^BOLD%^%^CYAN%^You get the urge to blow on the bubble as you wear the ring.%^RESET%^");
   return 1;
}
void init() {
    ::init();
    add_action("blow","blow");
}
void blow(string str){
   if(!objectp(ETO)){
   return 1; 
   }
   if(!TO->query_worn()){ 
	tell_object(TP,"%^BOLD%^%^BLUE%^You must be wearing the ring to use it.%^RESET%^");
   return 1; 
   }
   if(uses<1){
	tell_object(TP,"%^BOLD%^%^CYAN%^The ring has no more magic.%^RESET%^");
      TO->remove();
   return 1;
   }  
   if(present("bubble",environment(ETO))){
	tell_object(TP,"%^BOLD%^%^CYAN%^There are already bubbles floating around!%^RESET%^");
   return 1; 
   }
   if(!str) {             
	tell_object(TP,"%^BOLD%^%^BLUE%^Blow what?  The ring?%^RESET%^");
   return 1;
   }
   if(str == "bubble"||str=="the bubble"||str=="ring"||str=="the ring"||str=="on the ring"||str=="on the bubble"){
	tell_object(TP,"%^BOLD%^%^CYAN%^You pucker up and blow on the bubble, sending tiny little %^WHITE%^b%^CYAN%^u%^WHITE%^bb%^CYAN%^l%^WHITE%^es %^CYAN%^everywhere!%^RESET%^");
     tell_room(environment(ETO),"%^BOLD%^%^CYAN%^As "+ETOQCN+" puckers up and blows on the bubble, little %^WHITE%^b%^CYAN%^u%^WHITE%^bb%^CYAN%^l%^WHITE%^es %^CYAN%^fly out and %^BLUE%^swirl %^CYAN%^around "+ETO->query_objective()+"!%^RESET%^",ETO);
      ob=new("/d/darkwood/yntala/mon/bubble.c");
      ob->move(environment(ETO));
      ob->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob);
      ob1=new("/d/darkwood/yntala/mon/bubble.c");
      ob1->move(environment(ETO));
      ob1->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob1);
      ob2=new("/d/darkwood/yntala/mon/bubble.c");
      ob2->move(environment(ETO));
      ob2->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob2);     
      ob3=new("/d/darkwood/yntala/mon/bubble.c");
      ob3->move(environment(ETO));
      ob3->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob3);
      ob4=new("/d/darkwood/yntala/mon/bubble.c");
      ob4->move(environment(ETO));
      ob4->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob4);
      ob5=new("/d/darkwood/yntala/mon/bubble.c");
      ob5->move(environment(ETO));
      ob5->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob5);
      ob6=new("/d/darkwood/yntala/mon/bubble.c");
      ob5->move(environment(ETO));
      ob5->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob5);
      ob7=new("/d/darkwood/yntala/mon/bubble.c");
      ob5->move(environment(ETO));
      ob5->force_me("protect "+ETO->query_name());
      ETO->add_follower(ob5);
      uses --;
      return 1;
   }
}
