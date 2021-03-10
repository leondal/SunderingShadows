// fancy bracers, made by hades
#include <daemons.h>
#include <std.h>
inherit "/d/common/obj/armour/bracers";
int uses = 10;

void create(){
    ::create();

    set_name("ice bracers");
    set_id(({ "bracers", "bracer", "ice bracers","frozen bracers","bracers of the ice master"}));
    set_short("%^RESET%^%^CYAN%^Br%^BOLD%^a%^RESET%^%^CYAN%^cers of the Ice M%^BOLD%^a%^RESET%^%^CYAN%^ster%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^frozen bracers%^RESET%^");
    set_long("%^CYAN%^These are bracers made from blue coral.  There are several"+
	" %^RESET%^pearls%^CYAN%^ that have been added to them.  Several strange barnacles of"+
	" a light blue also seem to be growing off them.  The shells glow "+
	"with a strange %^BOLD%^chilling magic%^RESET%^%^CYAN%^.   Oddly enough, the bracers seem to "+
	"be covered with an unmelting layer of frost.%^RESET%^");
    set_lore("These bracers look to be the work of an ancient circle"+
	" of wizards known as ice masters.  The magi forsook other elements"+
	" to focus on ice so much that everything they cast was laced "+
	"with ice magic.  Even their bodies gave off an aura of cold"+
	" that was obvious to anyone that saw them.  They are long "+
	"gone from this realm but this creation proves they existed."+
	"There is some writing on it that one could %^BOLD%^<inspect>.");
    set_property("lore difficulty",30);
    set_value(5000);
    set_property("enchantment",4);
    set_remove((:TO,"remove_func":));
    set_wear( (:TO,"check":) );
    set_struck((:TO,"strike_func":));
	set_item_bonus("cold resistance",10);
	set_item_bonus("bonus_spell_slots_4",1);
}
void init(){
    ::init();
    add_action("inspect","inspect_em");
    add_action("cold","cold");
    add_action("recharge","recharge");

}
void recharge(string str){
  write("%^CYAN%^You focus on the bracers and they drain your "+
  "energy to give them more power");
  ETO->set_paralyzed(30,"%^CYAN%^You are regaining your strength.");
  ETO->add_exp(-40000);
  uses +=1;
}

void inspect_em(string str){
    string tmp;
    if(!str && str != "bracer" && str != "bracers") 
	return notify_fail("inspect what? Bracer?\n");
     
    write("These are bracers of cone of cold, it has the "+
	 "following function:\n"
     "cold <name>: casts a cone of cold at target(1 charges)\n"+
     uses+" charges left.\n"+
     "recharge: will drain your exp to give the bracers more power." );
    return 1;
}
void cold(string str){
    object ob;
        if((string)ETO->query_real_age_cat()=="child" ||
          (string)ETO->query_real_age_cat()=="normal"  )
       return notify_fail("You are too young grasp this power");
    if(ETO->query_casting()) return notify_fail("Already casting.");
    if(uses < 0) return notify_fail("The item is out of charges.\n");
    if (ETO->query_bound() || ETO->query_unconscious()) {
       ETO->send_paralyzed_message("info",TP);
       return 1;
    }


    if(!str) return notify_fail("cold who?\n");
    if(!(ob = present(str, ETP))) return notify_fail("That isn't here!\n");
    if(!ETO->is_class("mage") && !ETO->is_class("bard") &&
       !ETO->is_class("thief") && !ETO->is_class("sorcerer")) 
    return notify_fail("Only arcane spellcasters and"+
               " rogues can use this power.\n");

     new("/cmds/spells/c/_cone_of_cold")->use_spell(ETO,ob,10);

    uses --;
    return 1;
}
int check(){

   ::check();
   if(objectp(ETO) && ETO->query_property("no bracers")){    
   tell_object(ETO,"You are currently using an object that "+
          "cannot be worn with bracers.");
       return 0;
   }
 
   if((string)ETO->query_real_age_cat()=="child" || 
     (string)ETO->query_real_age_cat()=="normal"  ){
          write("You are too young grasp this power"); 
      return 0;}          
      tell_object(ETO,"%^CYAN%^The bracers seem to "+
          "%^BOLD%^shimmer%^RESET%^%^CYAN%^ as you settle them on your forearms.");
      tell_room(EETO,"%^CYAN%^"+ETOQCN+"'s bracers seem to %^BOLD%^shimmer "+
         "%^RESET%^%^CYAN%^as they settle on "+ETO->QP+" forearms.",ETO);
          return 1;
          
   
}

int remove_func(){
    if(!ETO->query_invis()) {
        tell_room(EETO,"%^CYAN%^"+ETOQCN+"'s bracer shimmer "+
           "as "+ETO->QS+" removes them.",ETO);
    }
    tell_object(ETO,"%^CYAN%^You see the bracers shimmer as you "+
      "remove them.");
        return 1;
}

int strike_func(int damage, object what, object who){
        if(random(1000) < 100){
        tell_room(environment(query_worn()),""+
            "%^BOLD%^%^BLUE%^"+ETOQCN+"'s bracers "+
            "glow blue as "+
            ""+who->QCN+" strikes them!",({ETO,who}));
        tell_object(ETO,"%^BOLD%^%^BLUE%^Your bracers "+
            "glow blue as "+
            ""+who->QCN+" strikes them!");
        tell_object(who,"%^BOLD%^%^BLUE%^"+ETOQCN+"'s bracers "+
            "glow blue as "+
            "you strike them!");

        return (damage/2);
 }
}
