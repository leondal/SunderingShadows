#include <std.h>
inherit OBJECT;

object who;
int counter;

void create(){
   ::create();
   set_name("obsidian gem");
set_id(({"Obsidian gem","Gem","gem","obsidian","Gem","obsidian gem","power gem","powergem"}));
   set_short("%^BOLD%^%^BLACK%^Ob%^RED%^s%^BOLD%^%^BLACK%^id%^RESET%^%^ORANGE%^i"
      "%^BOLD%^%^BLACK%^an G%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^m of P%^RED%^o%^BLACK%^"
      "w%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^r%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^a large h%^RESET%^%^RED%^u%^BOLD%^%^BLACK%^nk "
      "of ob%^RED%^s%^BOLD%^%^BLACK%^id%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^an%^RESET%^");
   set_lore("%^RESET%^%^MAGENTA%^Arcanists%^BOLD%^%^BLACK%^, the %^WHITE%^divinely inspired%^BLACK%^, and"
" the %^CYAN%^psionically gifted%^BLACK%^ have always looked to capture the essence of the Obsidian dragon within"
" gems of power - granting them strength far exceeding what would normally be granted to mortals. When acquired"
", they have turned no small few of them from middling to notable, and the notable to heights unfathomed. Balance"
" is a precarious thing - even more so when such are found in the hands of mortals who may run the gamut from the"
" %^WHITE%^benevolent%^BLACK%^ to the %^RED%^malevolent%^BLACK%^ - the %^CYAN%^wisend introspect%^BLACK%^ to the"
" %^YELLOW%^chaotic maelstrom%^BLACK%^. The pendulum swings all the more widely for wielders of this powerful"
" source.%^RESET%^.");
      set_long("%^BOLD%^%^BLACK%^This t%^WHITE%^e%^BLACK%^ar-dr%^WHITE%^o%^BLACK%^p shaped o%^WHITE%^b%^BLACK%^sid%^CYAN%^i%^BLACK%^an"
" g%^WHITE%^e%^BLACK%^m seems a rough cut, as if hewn directly from a massive outcropping, and is roughly the size of a man's fist."
" Deep within its %^RESET%^sm%^BOLD%^%^WHITE%^o%^BLACK%^k%^RESET%^ey-%^BOLD%^%^BLACK%^h%^WHITE%^a%^RESET%^ze%^BOLD%^%^BLACK%^,"
" the gem pulses like a %^RESET%^%^RED%^he%^BOLD%^ar%^RESET%^%^RED%^tb%^BOLD%^ea%^RESET%^%^RED%^t%^BOLD%^%^BLACK%^, giving"
" off a faint %^RESET%^%^ORANGE%^wa%^YELLOW%^rm%^RESET%^%^ORANGE%^th%^BOLD%^%^BLACK%^, and roiling with deep"
" %^RESET%^%^RED%^r%^BOLD%^e%^RESET%^%^RED%^ds%^BOLD%^%^BLACK%^ and %^RESET%^%^ORANGE%^o%^RED%^r%^BOLD%^a%^YELLOW%^n"
"%^RED%^g%^RESET%^%^RED%^e%^ORANGE%^s%^BOLD%^%^BLACK%^, as %^RESET%^%^RED%^l%^BOLD%^av%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^ wishing"
" to find release from its confines.%^RESET%^");
   set_weight(10);
   set_value(150000);
   set_property("no animate",1);
   set_property("magic",4);
   set_property("lore",25);
   set_heart_beat(1);
   counter = 0;
}

int is_powergem() { return 1; }

int add_counter(int num){
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
            tell_object(ETO,"Your "+TO->query_short()+" begins to get warm to the touch.");
            tell_object(ETO,"You can feel something in your sacks start to vibrate.");
        }
        break;
    case 21..99: break;
    case 100:
        if(objectp(ETO) && living(ETO))
        {
            tell_object(ETO,"Your "+TO->query_short()+" is painfully hot to the touch now!");
            tell_object(ETO,"The vibration in your sacks increases to a dull hum!");
        }
        break;
    case 101..199: break;
    default:
        if(objectp(ETO) && living(ETO) && objectp(EETO))
        {
            tell_object(ETO,"Your "+TO->query_short()+" suddenly explodes in a violent shower of
fragments!");
            tell_room(EETO,""+ETO->QCN+"'s "+TO->query_short()+" suddenly explodes in a violent
shower of fragments!",ETO);
            damage = roll_dice(10,10);
            if(sizeof(sacks))
            {
                for(i=0;i<sizeof(sacks);i++)
                {
                    if(!objectp(sacks[i])) { continue; }
                    tell_object(ETO,"Your "+sacks[i]->query_short()+" rips apart in a violent "
                        "explosion sending debris everywhere!");
                    tell_room(EETO,""+ETO->QCN+"'s "+sacks[i]->query_short()+" rips apart in "
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
   if(objectp(who)){
      if(ETO != who){
      //who->add_clevel(-2);
      who->add_property("empowered",-2);
      //who->set_property("spell dcs",-2);
         who = 0;
     }
  }
  if(living(ETO) && ETO != who){
     who = ETO;
     tell_room(environment(who),"%^BOLD%^%^BLACK%^The gem carried by "+who->query_cap_name()+" %^RESET%^%^RED%^g%^BOLD%^l%^YELLOW%^o%^RED%^w%^RESET%^%^RED%^s %^BOLD%^%^BLACK%^slightly.%^RESET%^",who);
      tell_object(who,"%^BOLD%^%^BLACK%^The black gem %^RESET%^%^RED%^g%^BOLD%^l%^YELLOW%^o%^RED%^w%^RESET%^%^RED%^s %^BOLD%^%^BLACK%^slightly.%^RESET%^");
      //who->add_clevel(2);
      //who->set_property("spell dcs",2);
      who->set_property("empowered",2);
  }
   if((ob = present("powergem",ETO)) && living(ETO) && ob != TO)
  {
     tell_object(ETO,"The gems of power start to interact and shake and quiver.");
     tell_room(environment(ETO),"The gems held by "+ETO->query_cap_name()+" quiver and shake.",ETO);
     tell_room(environment(ETO),"They explode in a brilliant burst of light and fire.");
     ETO->do_damage("torso",roll_dice(3,50));
     ETO->add_attacker(TO);
     ETO->continue_attack();
     ob->remove();

     TO->remove();
  }
  else
  {
     deep_gem_check(); 
  }

}

void remove(){
   if(objectp(who)){
      //who->add_clevel(-2);
      //who->set_property("spell dcs",-2);
      who->set_property("empowered",-2);
      //who->add_damage_bonus(-2); will be spell dc
      who = 0;
   }
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
     find_object_or_load("/d/undead/rooms/xerylhome.c");
     find_living("obsidian dragon")->add_revenge(TPQN);
     return;
  }
}
