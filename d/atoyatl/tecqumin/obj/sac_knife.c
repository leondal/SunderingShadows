//updated base damage - Circe 4/29/04
#include <std.h>

inherit "/d/common/obj/weapon/knife.c";

int charges;

int unwield_knife();
int wield_knife();
int hit_stuff(object ob);
void set_unwield_state();

void create(){
  ::create();
  charges = 5;
  set_name("jet black knife");
  set_id(({"knife","sacrificial knife","black knife","weapon", "jet knife", "dagger", "black dagger", "jet dagger", "sacrificial dagger"}));
  set_obvious_short("%^BOLD%^%^BLACK%^jet black knife%^RESET%^");
  set_short("%^BOLD%^%^BLACK%^sacrificial dagger of the %^RESET%^%^CYAN%^Tecqumin%^RESET%^");
  set_wield((:TO, "wield_knife":));          
  set_unwield((:TO, "unwield_knife":));  
  set_property("enchantment", 7);
  set_hit((:TO, "hit_stuff":));

}

int check_for_duplicates(){
  object * stuff;
  string filename;
  int i, count;
  if (!objectp(ETO))
  {
    return 0;
  }
  stuff = deep_inventory(ETO);
  stuff -= ({TO});
  count = sizeof(stuff);
  if (count<1)
  {
    return 0;
  }
  filename = base_name(TO);
  for (i=0; i<count;i++){
    if (base_name(stuff[i])==filename)
    { 
      return 1;
    }
  }
  return 0;
}

void init(){
  ::init();
  add_action("feed_me", "feed");
  if (check_for_duplicates())
  {
    if (objectp(ETO))
    {
      if (living(ETO))
      {
        tell_object(ETO, "The " + query_short() + " recognises another of its own kind and disappears");
      } else 
      {
        tell_room(ETO, "The " + query_short() + " recognises another of its own kind and disappears");
      }
    }
    remove();
  }
}

void set_charges(int c){
  charges = c;
}

int query_charges(){
  return charges;
}

void shall_I_feed(string str){
  if (lower_case(str) != "yes")
  {
    return;
  }
  ETO->set_exp(total_exp_for_level(TP->query_adjusted_character_level() - 1));
  ETO->resetLevelForExp(0); 
  tell_object(ETO, "You allow the point of the " + query_short() 
    + "%^RESET%^ to pierce your %^BOLD%^%^MAGENTA%^flesh%^RESET%^, and it"
    + " drinks its fill as you feel your strength drain away");
  tell_object(ETO, "%^BOLD%^%^YELLOW%^You have lost a level!");
  if (objectp(EETO))
  { 
    tell_room(EETO, ETO->QCN + "%^RESET%^ pierces " + ETO->QP + "%^BOLD%^"
      +" %^MAGENTA%^flesh%^RESET%^ with the " + query_short() + "%^RESET%^"
      +" and shudders as it drinks from " + ETO->QP + "%^BOLD%^%^CYAN%^"
      +" s%^RESET%^%^CYAN%^o%^BOLD%^ul", ETO);
  }
  charges += 3;
}



int feed_me(string str){
  if (!id (str))
  {
    return notify_fail("Do you want to feed the dagger? Try <feed dagger>");
  }
  if (TP!= ETO){
    return notify_fail("You would have to be holding the dagger to feed it");
  }
  if (charges >7){
    tell_object(TP, "The dagger does not need to feed from you any more just now");
  }
  tell_object(ETO, "To feed the dagger, you would have to cut yourself and allow"
    +" it to drink some of your strength. This will be a major sacrifice. Type"
    +" 'yes' to go ahead anyway, anything else to abandon.");
  input_to("shall_I_feed", 0);
  return 1;
}



int hit_stuff(object ob)
{ 
  string * classes, targetclass, attackerclass;
  int count, i, level;
  if (!objectp(TO)||!objectp(ETO)||!objectp(ob)){return 0;}
  if (2> charges > 0 && !random(5)){
    tell_object(ETO, "%^BOLD%^%^BLACK%^The jet black blade %^RESET%^whispers"
      +"%^BOLD%^%^BLACK%^, 'Want... to feed. Need power soon!");
    return 0;
  } 
  if (charges <1){
    tell_object(ETO, "%^BOLD%^%^BLACK%^The jet black blade %^RESET%^whispers"
      +"%^BOLD%^%^BLACK%^, 'No power left.. feed me now!");
    return 0;
  }
  if (random(9))
  {
    return 0;
  }
  if (ob->fort_save(40))
  {
    tell_object(ETO, "Your " + query_short()
    + "%^RESET%^tries to attach itself to " + ob->QCN 
    + "'s %^BOLD%^%^MAGENTA%^flesh%^RESET%^, but " 
    + ob->QS + " fights it off!" );
    tell_object(ob, (string)ETO->QCN + "'s %^RESET%^"
    + query_short() + "%^RESET%^ tries to attach itself to your%^BOLD%^"
    +" %^MAGENTA%^flesh%^RESET%^, but you fight if off!");
    tell_room(EETO, ETO->QCN + "'s " +  query_short() 
    + "%^RESET%^ attaches itself to " + ob->QCN 
    + "'s %^BOLD%^%^MAGENTA%^flesh%^RESET%^, but " + ob->QS 
    + " %^RESET%^fights it off!", ({ob,ETO}));
    return 0;
  }
  tell_object(ETO, "%^BOLD%^%^BLACK%^Your "+ query_short() 
    + "%^BOLD%^%^BLACK%^ attaches itself to " + ob->QCN 
    + "'s %^BOLD%^%^MAGENTA%^flesh%^BOLD%^%^BLACK%^, seeming to suck"
    +" greedily at "+ ob->QP + " %^BOLD%^%^CYAN%^life"
    +" force%^BOLD%^%^BLACK%^!" );
  tell_object(ob, "%^BOLD%^%^BLACK%^"+ (string)ETO->QCN + "'s %^ORANGE%^"
    + query_short() + "%^BOLD%^%^BLACK%^ attaches itself to your%^BOLD%^"
    +" %^MAGENTA%^flesh%^BOLD%^%^BLACK%^, and you can feel strength leaving"
    +" you as it sucks, greedily devouring your %^BOLD%^%^CYAN%^life"
    +" force%^BOLD%^%^BLACK%^!");
  tell_room(EETO, "%^BOLD%^%^BLACK%^" + ETO->QCN + "'s " +  query_short() 
    + "%^BOLD%^%^BLACK%^ attaches itself to " + ob->QCN 
    + "'s %^BOLD%^%^MAGENTA%^flesh%^BOLD%^%^BLACK%^, seeming to suck"
    +" greedily at "+ ob->QP + "%^BOLD%^%^CYAN%^life"
    +" force%^BOLD%^%^BLACK%^!", ({ob,ETO}));
  charges --;
  classes = ob->query_classes();
  targetclass = classes[random(sizeof(classes))];
  level = 0;
  if (ob->query("negative level"))
  {
    level = ob->query("negative level")[targetclass];
  }
  ob->set("negative level", ([targetclass: level-1]));
  ETO->set_hp(ETO->query_hp() + 100);
  return (0);
}


int wield_knife()
{
  if (!objectp(TO)||!objectp(ETO)){return 0;}
  tell_object(ETO, "%^BOLD%^%^BLACK%^As you grip the handle of the jet"
    +" black blade, you become aware of your own %^RESET%^%^RED%^"
    +"heartbeat%^BOLD%^%^BLACK%^ and those of the living things around"
    +" you. You sense the knife urging you to plunge it into their"
    +" %^BOLD%^%^MAGENTA%^flesh%^BOLD%^%^BLACK%^, to release the"
    +" %^CYAN%^life force%^BOLD%^%^BLACK%^ from which it so greedily"
    +" desires to drink.");
  if (objectp(EETO)){
    tell_room(EETO,  (string)ETO->QCN + " looks momentarily distant as " 
      + ETO->QS +" wields " + query_short() + ", and a strange look of"
      +" hunger enters " + ETO->QP + " gaze.",ETO);
  }
  return 1;
}

int unwield_knife()
{
  if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return 0;}
  tell_object(ETO, "You let go of the %^BOLD%^%^BLACK%^jet black blade"
    +"%^RESET%^, and give up on its desires for more%^BOLD%^%^RED%^"
    +" bl%^RESET%^%^RED%^oo%^BOLD%^d%^RESET%^ and more"
    +" %^BOLD%^%^CYAN%^s%^RESET%^%^CYAN%^ou%^BOLD%^ls%^RESET%^.");
  tell_room(EETO, (string)ETO->QCN+" releases the%^BOLD%^%^BLACK%^"
    +" jet black blade%^RESET%^ " + ETO->QS + " wields, and a certain"
    +" hunger for %^BOLD%^%^BLACK%^death%^RESET%^ leaves " + ETO->QP 
    + " eyes." ,ETO);
  return 1;
}

