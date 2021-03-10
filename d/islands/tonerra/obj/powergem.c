//Crayoned description and added better lore - Octothorpe 1/23/10

#include <std.h>
inherit OBJECT;

object who;
int counter;

void create(){
   ::create();
   set_name("emerald gem");
set_id(({"Emerald gem","Gem","gem","emerald","Gem","emerald gem","powergem","power gem"}));
   set_short("%^RESET%^%^GREEN%^E%^BOLD%^m%^RESET%^%^GREEN%^e%^BOLD%^"+
      "r%^RESET%^%^GREEN%^a%^BOLD%^ld G%^RESET%^%^GREEN%^e%^BOLD%^m "+
	  "%^RESET%^%^GREEN%^o%^BOLD%^f P%^RESET%^%^GREEN%^o%^BOLD%^w"+
	  "%^RESET%^%^GREEN%^e%^BOLD%^r%^RESET%^");
   set_obvious_short("%^RESET%^%^GREEN%^a large e%^BOLD%^m%^RESET%^"+
      "%^GREEN%^e%^BOLD%^r%^RESET%^%^GREEN%^a%^BOLD%^ld%^RESET%^");
   set_lore("The legendary Emerald of Power is said to make the weak "+
      "strong the slow fast, the cowardly brave.  He who possesses this "+
	  "item is said to become strong, fast, and skilled in weaponry.  "+
	  "There is no true proof, but the historical references are "+
	  "consistent.  It is rumored that gems of this type hail from "+
	  "the Inner Planes, and that the emerald variety are especially "+
	  "coveted by Geonslu, the draconic queen of Tonerra.");
   set_long("%^RESET%^%^GREEN%^This roughly-hewn emerald is about the "+
      "size of a grapefruit.  It sparkles with an alluring light that "+
	  "originates deep within the gem...%^RESET%^");
   //set_weight(25);
   set_weight(10); // changing weight along with other encumbrance changes -Ares
   set_value(150000);
   set_property("no animate",1);
   set_property("magic",4);
   set_property("lore",25);   
   set_property("inanimate bonus", 1);
   set_property("repairtype","jewel");
   set_item_bonus("attack bonus", 2);
   set_item_bonus("damage bonus", 5);
   set_item_bonus("caster level", 2);
   counter = 0;
   set_heart_beat(1);
}

int is_powergem() { return 1; }

int add_counter(int num)
{
    if(!counter || counter < 0) { counter = 0; }
    counter += num;
}


void deep_gem_check()
{
    object *inv,*deep_inv,*gems=({}),*sacks=({});
    int i,j,damage;

    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }
    if(!living(ETO)) { return; }

    inv = all_inventory(ETO);

    if(!sizeof(inv)) { return; }

    for(i=0;i<sizeof(inv);i++)
    {
        if(!objectp(inv[i])) { continue; }
        if(!inv[i]->is_container()) { continue; }
        deep_inv = all_inventory(inv[i]);
        if(!sizeof(deep_inv)) { continue; }
        for(j=0;j<sizeof(deep_inv);j++)
        {
            if(!objectp(deep_inv[j])) { continue; }
            if(deep_inv[j]->is_powergem()) 
            { 
                gems += ({ deep_inv[j] });
                TO->add_counter(1);
                deep_inv[j]->add_counter(1);
                sacks += ({ inv[i] });
            }
        }
    }

    sacks = distinct_array(sacks);

    if(!sizeof(gems)) 
    { 
        TO->add_counter(-1);
        return;
    }

    switch(counter)
    {
    case 0..19: break;
    case 20:
        if(objectp(ETO) && living(ETO))
        {
            tell_object(ETO,"%^RESET%^%^GREEN%^Your "+TO->query_short()+" begins to get warm to the touch.%^RESET%^");
            tell_object(ETO,"You can feel something in your sacks start to vibrate.");
        }
        break;
    case 21..99: break;
    case 100:
        if(objectp(ETO) && living(ETO))
        {
            tell_object(ETO,"%^RESET%^%^YELLOW%^Your "+TO->query_short()+" is painfully hot to the touch now!%^RESET%^");
            tell_object(ETO,"%^RESET%^%^BOLD%^The vibration in your sacks increases to a dull hum!");
        }
        break;
    case 101..199: break;
    default:
        if(objectp(ETO) && living(ETO) && objectp(EETO))
        {
            tell_object(ETO,"%^RED%^Your "+TO->query_short()+" suddenly explodes in a violent shower of fragments!");
            tell_room(EETO,"%^RED%^"+ETO->QCN+"'s "+TO->query_short()+" suddenly explodes in a violent shower of fragments!",ETO);
            damage = roll_dice(10,10);
            if(sizeof(sacks))
            {
                for(i=0;i<sizeof(sacks);i++)
                {
                    if(!objectp(sacks[i])) { continue; }
                    tell_object(ETO,"%^RED%^Your "+sacks[i]->query_short()+" rips apart in a violent "
                        "explosion sending debris everywhere!");
                    tell_room(EETO,"%^RED%^"+ETO->QCN+"'s "+sacks[i]->query_short()+" rips apart in "
                        "a violent explosion sending debris everywhere!",ETO);
                    deep_inv = all_inventory(sacks[i]);
                    if(!sizeof(deep_inv)) { continue; }
                    for(j=0;j<sizeof(deep_inv);j++)
                    {
                        if(!objectp(deep_inv[j])) { continue; }
                        if(deep_inv[j]->is_powergem())
                        {
                            damage += roll_dice(10,10);
                            deep_inv[j]->remove();
                            continue;
                        }
                        deep_inv[j]->repairMe(-1*(roll_dice(10,10)));
                        if(objectp(deep_inv[j]))
                        {
                            deep_inv[j]->move(environment(ETO));
                        }
                    }
                    sacks[i]->remove();
                }
            }
        }
        ETO->set_property("magic",1);
        ETO->do_damage("torso",damage);
        ETO->set_property("magic",-1);
        TO->remove();
        return;
    }

    return;
}

void heart_beat()
{
   object ob;

   if(!objectp(ETO)) return;
   /*if(objectp(who)){
      if(ETO != who){
        who->add_attack_bonus(-2);
     who->add_damage_bonus(-5);
	 who = 0;
     }
  }
  if(living(ETO) && ETO != who){
     who = ETO;
     tell_room(environment(who),"%^GREEN%^The gem carried by "+who->query_cap_name()+" glows slightly.",who);
     tell_object(who,"%^GREEN%^The green gem glows slightly.");
     who->add_attack_bonus(2);
      who->add_damage_bonus(5);
  }*/
   if((ob = present("powergem",ETO)) && living(ETO) && ob != TO)
  {
     tell_object(ETO,"The Emerald gems start to interact and shake and quiver.");
     tell_room(environment(ETO),"The gems held by "+ETO->query_cap_name()+" quiver and shake.",ETO);
     tell_room(environment(ETO),"%^BOLD%^%^CYAN%^They explode in a blillient burst of light and fire.");
     ETO->do_damage("torso",roll_dice(3,50));
     ETO->add_attacker(TO);
     ETO->continue_attack();
     ob->remove();
     TO->remove();
  }
  else
  {
     deep_gem_check(); // added so people don't carry an extra around in a sack to use as a weapon -Ares
  }

}

void remove(){
   /*if(objectp(who)){
      who->add_attack_bonus(-2);
      who->add_damage_bonus(-5);
      who = 0;
   }*/
   ::remove();
}

int isMagic() {return 3;}
void init() {
  if (!objectp(ETO))
     return;
  if (!userp(ETO))
  return;
 if (TP != ETO)
  return;
  if ((!ETO->query_property("ultimate_equip")) && !random(150))
  {
     find_object_or_load("/d/islands/tonerra/mountain/dhome.c");
     find_living("emerald dragon")->add_revenge(TPQN);
     return;
  }
}
