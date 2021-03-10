//an inheritable for creating costumes
//for new Seneca ~Circe~ 12/19/07
//Remember to use set_costume_type() with a brief description
//for the adjective (usually one to two words)
//Also, use set_costume("mask"); on masks
#include <std.h>

inherit ARMOUR;

void set_costume_type(string str);
int query_costume_type();
void set_costume(string str);
int query_costume();
string mycostume,myadjective,mytype;

void create(){
   ::create();
   set_name("costume");
   set_short("a costume");
   set_id(({"costume"}));
   set_long("This is a costume.  You shouldn't be seeing "+
      "this description, so something must be wrong.");
   set_limbs(({"torso"}));
   set_type("clothing");
   set_weight(1);
   set_ac(0);
   set_wear((:TO,"wear_costume":));
   set_remove((:TO,"remove_costume":));
}

int wear_costume(){
string gender,build,race;
   if(!interactive(ETO)) return 1;
   gender = ETO->query_gender();
   build = ETO->query_body_type();
   race = ETO->query_race();
   myadjective = ETO->getDescriptivePhrase();
   ETO->set("descriptive phrase","%^RESET%^%^CYAN%^"+build+" "+gender+" $R wearing a "+mycostume+" %^RESET%^%^CYAN%^"+mytype+"");
   ETO->set_long("%^BOLD%^%^CYAN%^"+capitalize(ETO->QS)+" is wearing a "+
      ""+mycostume+" %^BOLD%^%^CYAN%^"+mytype+".%^RESET%^");
   return 1;
}

int remove_costume(){
   if(!interactive(ETO)) return 1;
   ETO->set("descriptive phrase",myadjective);
   ETO->set("long");
   return 1;
}

void set_costume_type(string str){
   if(!str) mycostume = "invalid";
   mycostume = str;
}

int query_costume_type(){
   return mycostume;
}

void set_costume(string str){
   if(!str) mytype = "costume";
   mytype = str;
}

int query_costume(){
   return mytype;
}