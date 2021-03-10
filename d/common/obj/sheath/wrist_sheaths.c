//wrist_sheaths.c
// Major recode coinciding with the stab recode of December 2004 by Garrett.

#include <std.h>
#include <move.h>

inherit PARMOUR;

int uses;

int item_allowed(object what) {
  if (!objectp(what)) 
    return notify_fail("bad object.\n")
;
  if(!what->is_weapon()){
    notify_fail("This is meant for daggers only.\n");
    return 0;
  }
  if(sizeof(all_inventory(TO)) > 0) {
    notify_fail("This sheath already has its dagger.\n");
    return 0;
  }
  if( (what->query_size() > 1) || !(what->id("dagger")) ) {
    notify_fail("That is a little large, this is meant for daggers only.\n");
    return 0;
  }

  return 1;
}
object valid_stab_sheath() {
  if (!uses)               return 0;
  if(!TO->query_worn())    return 0;
  // Both of these cases should not be communicted to the user.
  // So... you know, we could have sheaths in odder places, if they were
  // meant to be unique rewards, special items, or etc. - Garrett, 2004
  if (sizeof(all_inventory(TO)) > 1) {    
    if (objectp(ETO))
      tell_object(ETO,"%^BOLD%^%^RED%^Your sheath is jammed and needs your attention!");
    return 0;
  }
  if ( sizeof(all_inventory(TO)) && (objectp(all_inventory(TO)[0]) ) && !(all_inventory(TO)[0]->is_weapon()) ) {
    if (objectp(ETO))
      tell_object(ETO,"%^BOLD%^%^RED%^Your sheath does not hold a weapon!");
    return 0;
  }

  // This case is last for telling them their sheath is empty! - g
  if (!sizeof(all_inventory(TO))) {
    if (objectp(ETO))
      tell_object(ETO,"%^BOLD%^%^RED%^You don't have a dagger in your sheath.");
    return 0;
  }
  
  return TO;
}


void use_sheath() {
  uses -= 1;
  if(!uses){
    write("%^BOLD%^%^RED%^As you extract your weapon you slice the last thong through, destroying the sheath!");
    call_out("dest",1,ETO);
  }
}

void create(){
  ::create();
  
  set_name("Wrist Sheaths");
  set_id(({"wrist sheaths","sheaths","sheath","Wrist Sheaths","wrist"}));
  set("short","Wrist sheaths");
  set_long(
@OLI
This special sheath is made especially for thieves.
They store daggers in small sheaths on the wrist.
When thieves stab, they skillfully stab and leave the dagger in the back.
They then flip the new dagger from the sheath and stab quickly again.
Made basically of small bits of leather thong so that they might avoid notice
under a sleeve or such, they are very weak.
You realize that after a couple uses several of the
thongs will be cut and useless.
OLI
);
  uses = random(8) + 15;
  set_type("clothing");
  set_limbs(({"right hand"}));
  set_weight(2);
  set_value(500);
  set_wear((:TO, "my_wear":));
  set_remove((:TO,"my_remove":));
  set_max_internal_encumbrance(20);
}

int my_wear()
{
	if(!ETO->is_class("thief"))
	{
		tell_object(ETO,"As you fiddle with the thongs you realize you have"+
			" no idea how to do this!");
		return 0;
	}
    if((int)ETO->query_lowest_level() < 7)
	{
		tell_object(ETO,"%^BOLD%^%^BLUE%^You just cant seem to figure out"+
			" how to use the sheaths.");
        return 0;
	}
    tell_object(ETO,"%^BOLD%^%^BLACK%^You knowingly place thongs over you"+
		" thumb and around your arm as you wear the sheath!");
		"daemon/hide_d"->hideItem(TO,TP,1);
    return 1;
}
//if(!TP->is_class("thief")
//     && !TP->is_class("assassin") || (int)TP->query_highest_level() < 7){
//    write("As you fiddle with the thongs you realize you have no idea how
//to do this!\n");
//    return 0;
//  } else {
//    write("You knowingly place thongs over you thumb and around your arm as
//you wear the sheath!");
//    "daemon/hide_d"->hideItem(TO,TP,1);
//    return 1;
//  }
//}

int my_remove(){
  set_hidden(0);
  return 1;
}

void dest(object tp) {
  object *inven;
  
  inven = all_inventory(TO);
  if(sizeof(inven))
    if((string)inven[0]->move(tp) != MOVE_OK){
      write("%^BOLD%^You drop the dagger in the sheath as the sheath breaks.");
      inven[0]->move(environment(tp));
    }
  TO->remove();
}

int query_size(){
  if(!objectp(ETO) || !living(ETO)) return 2;
  return ETO->query_size();
}

// int is_detectable(){
//   return !query_worn();
// }
