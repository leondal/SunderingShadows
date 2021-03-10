// chains that make a person age, attach code stolen from lujke
#include <std.h>
inherit "/std/armour";
int age_mod;
string owner;

void create() {
    ::create();
    set_name("chains of aging");
    set_id(({ "chain","chains" }));
    set_short("%^BOLD%^%^BLACK%^dar%^RESET%^%^WHITE%^k%^BOLD%^%^BLACK%^ened ch%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^ins");
    set_long("%^BOLD%^%^BLACK%^These chains were forged from"+
    " pure %^RESET%^%^MAGENTA%^loss%^BOLD%^%^BLACK%^.  They are completely black."+
    "  The chains have an %^RESET%^%^MAGENTA%^anti-glow%^BOLD%^%^BLACK%^ to them "+
    "causing the area around them to %^RESET%^%^MAGENTA%^darken."+
    "%^BOLD%^%^BLACK%^  The chains would likely be fastened "+
    "around the arms of someone and be"+
    " draped over their whole body.%^RESET%^");
    set_weight(4);
    set_value(1);
    set_type("ring");
    set_limbs( ({ "left arm","right arm" }) );
    set_ac(4);
    set_property("enchantment",-4);
	//set_property("no remove",1);
   if(query_property("enchantment") > -4){
    remove_property("enchantment");
    set_property("enchantment",-4);
	}
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
}
int wear_func(){
      int age;
      if(!objectp(ETO)) return 1;
      if(!objectp(EETO)) return 1;
      age = ETO->query("age_modifier");
      age_mod = age + 50 ;
       ETO->set("age_modifier",age_mod); 
       tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"
           +ETOQCN+" slips"+
        " the chains on making "+ETO->QO+""+
        " quickly age",ETO);
        tell_object(ETO,"%^BOLD%^%^BLACK%^you wear the chains "+
        "and instantly your body ages.");       
       return 1;
}
int remove_func(){
      int age;
      if(!objectp(ETO)) return 1;
      if(!objectp(EETO)) return 1;
      age = ETO->query("age_modifier");
      age_mod = age - 50 ;
       ETO->set("age_modifier",age_mod); 
        tell_room(environment(ETO),"%^BOLD%^%^BLACK%^As "+ETOQCN+
        " removes "+ETO->QP+" chains youth returns.",ETO);
        tell_object(ETO,"%^BOLD%^%^BLACK%^You remove the"+
                " chains and feel your youth return.");
        return 1;


}
void init(){
//int wearorder;
  ::init(); 
 //  if (!objectp(TO)||!objectp(ETO)||!interactive(ETO)){return 0;}
  add_action("attach_bracelets", "attach");
}

   void attach_bracelets(string str){
   object targ;
  string targname, objname;

  if (!objectp(TO)||!objectp(ETO)||!interactive(ETO)){return 0;}
  if (sscanf(str, "%s to %s", objname, targname)<2){
    return 0;
  }
  // prevent players and newbies being able to attach to 
  // another player - this ability for HMs and Imms only, due to trust
  // issues

  if(!id(objname)){return 0; }
  if ((string)ETO->query_position()== "player"
      ||(string)ETO->query_position()== "newbie"){
    tell_object (ETO,"You do not have the power to attach the chains");
    return 1;
  }
  
  targ = present(targname, EETO);
  if (!objectp(targ)){
    tell_object(ETO, targname + " is not here.");
    return 1;
  }
  if (!targ->query_unconscious()&&!targ->query_bound()){
    tell_object(ETO, targ->QCN+" isn't likely to just let you do that.");
    return 1;
  }

//  TP->force_me("give " + objname + " to " + targname);
  tell_object(ETO, "Moving swiftly, you secure the chains on "
                 + targ->QCN +"'s arms.");
  if (!targ->query_unconscious()){

    tell_object(targ, (string)ETO->QCN + " wraps you in"
                      +" blackened chains.");
  }
  tell_room(EETO,(string)ETO->QCN + " wraps darkened chains"
                     +" around " + targ->QCN + "'s body."
                     , ({targ, ETO})); 
                                
  
  move(targ);
  //ETO->set_property("ultimate_equip",1);
  //set_worn(targ);
  //TO->set_actualLimbs(({"left arm","right arm"}));

  ETO->set_bound(0);
  ETO->set_hp(1);
  ETO->force_me("wear chains");
  ETO->set_paralyzed(60,"%^MAGENTA%^You can feel your life force flow from you, your body aging.");
  //ETO->set_property("wear_order",1);
  //wearorder=ETO->query_property("wear_order");  
  //TO->set_property("wear_order",""+(int)ETO->query_property("wear_order")+"##"ETO->query_true_name()+"##"+what);
  //owner = targ->query_name();  
  //ETO->set_property("ultimate_equip",0);
  return 1;
}

string help(){
  return "Try 'attach chains to <target name>'";
}