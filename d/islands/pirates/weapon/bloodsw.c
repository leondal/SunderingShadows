#include <std.h>
inherit "/std/weapon";
int attacked;
create(){
    ::create();
    set_id(({"sword of blood","blood","sword"}));
    set_name("%^RESET%^%^RED%^Sword of Blood%^RESET%^");
    set_short((:TO,"short_func":));
      set_long((:TO,"long_func":));
    set_wc(1,6);
    set_large_wc(1,8);
    set_weight(8);
    set_size(1);
    set_property("enchantment",2);
    set("value",500);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((: TO,"extra_hit" :));
    set_type("slashing");
    set_prof_type("small blades");
attacked=0;
}

                   
int wield_func(string str){
        tell_object(TP,"%^RESET%^%^RED%^You wield the sword "
           "of blood and you can hear the sounds of a thousand "
           "souls scream out to you for release.\n"
          "%^BOLD%^The sword tells you:  %^RESET%^I hunger for "
            "blood FEED ME!");
        tell_room(environment(TP),
            "%^RESET%^%^RED%^"+TPQCN+" grins evilly as "
          ""+TP->query_subjective()+" wields "
            ""+TP->query_possessive()+" sword.%^RESET%^",TP);
        return 1;
    }

int unwield_func(string str){
if(attacked==0){
tell_object(TP,"%^BOLD%^%^RED%^The sword won't allow you to "
"release your grip on it! %^RESET%^");
tell_room(ETP,"%^RED%^" +TPQCN+ "tries to release "+TP->query_possessive()+" sword but cannot.%^RESET%^",TP);
return 0;
}else{
write("%^RED%^You release your sword...its bloodlust sated.");
attacked=0;
return 1;
}
}
int extra_hit(object ob){
  int special;
  special=(random(100));
   if(special<20){
         
message("my_action","%^RESET%^%^RED%^The sword sings as you slice into "
         "your opponent. And you watch in awe as your sword "
          "absorbs the blood through the runes of its blade."
         "%^RESET%^",TP);

  message("other_action","%^RESET%^%^RED%^The sword wielded by "
          ""+ETO->query_cap_name()+" glows an %^BOLD%^angry "
        "red%^RESET%^%^RED%^ and seems to sing out in pleasure "
        "as it slices into "+ob->query_cap_name()+"'s "
        "flesh.%^RESET%^",environment(ob),(({ETO, ob})));

message("my_action","%^RESET%^%^RED%^You feel the sword wielded by "
         ""+ETO->query_cap_name()+" cut deeply into your flesh.\n"
        "You watch in terror as the sword absorbs your spilled "
         "blood.",ob);
  attacked=1; 
return (random(10));
}
if(special>98){
         
message("my_action","%^BOLD%^%^RED%^Your sword glows for an "
        "instant, and all of a sudden a huge gout of blood "
         "is drained from your opponent into the sword, covering "
        "you in the process."
        "%^RESET%^",TP);

  message("other_action","%^BOLD%^%^RED%^The sword wielded by "
          ""+ETO->query_cap_name()+" gleams "
        "for an instant and then a huge gout of blood "
        "sprays from "+ob->query_cap_name()+" to the sword "
        "and you watch in horror as the sword absorbs the blood."
        "%^RESET%^",environment(ob),(({ETO, ob})));

message("my_action","%^BOLD%^%^RED%^Your pores are ripped "
         "asunder as your blood sprays out of you "
           "and into the sword wielded by "+ETO->query_cap_name()+".%^RESET%^"
        ,ob);
  ob->do_damage(random(25));
  ob->set_paralyzed((random(5)+5),"%^RESET%^%^RED%^Your muscles are frozen in terror.%^RESET%^");
  attacked=1; 
  call_out("hunger",200,TO);
return 1;
}else{
        return 0;
}
}
string short_func(string str){
if(attacked==0){
str="%^RESET%^%^RED%^Sword of Blood%^RESET%^";
}else{
str="%^BOLD%^%^RED%^Sword of Blood%^RESET%^";
}
return str;
}

string long_func(string str){
if (attacked==0){
str = "%^RESET%^%^RED%^The sword of blood calls to you. "
      "it chants BLOOD! BLOOD! BLOOD! and it wills you to kill "
       "and spray blood over its blade.  You are entranced by "
      "its mystical runes and blood red tinge.%^RESET%^";
}else{
str = "%^BOLD%^%^RED%^The sword glows and pulsates in your hand, "
      "its hunger sated for now.  But you can still feel it "
       "pushing at you, demanding you, calling to you, chanting:"
      "Kill them, bleed them drink their BLOOD!  The runes "
       "on the mystical blade glow ominously.%^RESET%^";
}
return str;
}

void hunger(){
 attacked=0;
}
