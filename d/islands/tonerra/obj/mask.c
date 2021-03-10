// updated short/long desc, the original long-desc transferred to object lore.
// also changed the charisma penalty to 5 (18 seemed excessive) and dropped the value to 0.
// Nienne, 02/07.
#include <std.h>
#include "/d/islands/tonerra/areadefs.h"
inherit ARMOUR;

int count = 0;

void create(){
   ::create();
   set_name("mask of Ibrandul");
   set_id(({"mask","mask of Ibrandul","Ibrandul"}));
   set_short("%^RESET%^%^RED%^Mask of Ibrandul%^RESET%^");
   set_obvious_short("%^RESET%^%^RED%^A hideous reptilian mask%^RESET%^");
/*   set_long(
@OLI
   This is the hideous mask that holds the power of Ibrandul. It holds
his life. When Shar thought to kill him, before the death blow he
moved his very life force into a mask that a followers carried and
made his life his. The mask can be controlled, but only by the most
in tune with nature. It provides protection from attack but also brings
it. To wear it is to become Ibrandul unless you can resist it. Only
in death will Ibrandul release the captor, or in his own release.
OLI
   ); */
   set_long("This mask is absolutely hideous. It takes the shape of a "
"monstrous %^GREEN%^reptilian %^RESET%^face, somewhat resembling that of a "
"lizard, but %^ORANGE%^misshapen %^RESET%^and horribly marred. Its knobbled "
"skin is a %^RED%^dull crimson shade%^RESET%^, contrasted by the "
"%^BOLD%^%^RED%^blazing red eyes %^RESET%^set into its sockets. "
"%^BOLD%^%^BLACK%^Bony ridges %^RESET%^form its brows, and "
"%^BOLD%^%^WHITE%^jagged teeth %^RESET%^protrude from its fanged maw. Yet "
"even beyond its horrific appearance, there is something else about it that "
"gives you an ill feeling just from looking at it. Some form of nearly "
"tangible %^BLUE%^evil %^RESET%^that emanates from the mask itself...");
   set_lore("This is the hideous mask that is rumored to hold the power of "
"Ibrandul himself. The stories tell that when Shar planned to kill him, "
"before the death blow he transferred his very life force into a mask that "
"one of his followers carried, and thus took over the life of that follower "
"to preserve himself. From that day, anyone who was fool enough to wear the "
"mask was said to slowly lose their mind, eventually being taken over by "
"Ibrandul himself. It is said that only in the death of either the wearer, or "
"Ibrandul himself, would release the victim from the evil mask.");
   set_property("lore difficulty",25);
   set_ac(2);
   set_property("enchantment",-2);
   set_property("no remove",1);
   set_item_bonus("charisma",-3);
   if(query_property("enchantment") > 0){
      remove_property("enchantment");
      set_property("enchantment",-2);
   }
   set_wear((:TO,"wear_func":));
   set_remove((:TO,"remove_func":));
   set_value(0);
   set_weight(2);
   set_heart_beat(5);
   set_limbs(({"head"}));
   set_type("clothing");
}

int wear_func(){
   ETO->set_property("evil item",1);
   return 1;
}

int remove_func(){
   ETO->set_property("evil item",-1);
   return 1;
}

void heart_beat(){
   object ob;
   object *inven;
   int i;

   if(!objectp(query_worn())) return;
      if (!interactive(query_worn())) return;
   if(!objectp(query_worn()) || !interactive(query_worn())) return;
   inven = all_living(environment(query_worn()));

   if(count > 25) {

      for(i = 0;i<sizeof(inven);i++) {
         if((string)inven[i]->query_diety() == "shar") {
            tell_object(query_worn(),"%^MAGENTA%^Ibrandul speaks to you,%^RESET%^ Shar is present.\n");
            tell_object(query_worn(),"Shar must be destroyed. I command you to kill her.");
            tell_object(query_worn(),"Your body is wracked with pain from the command of Ibrandul.");

    set_property("magic",1);
            query_worn()->do_damage("torso",random(40));
            count = 0;
         }
      }
   }
   count++;

   if(!random(100) && query_worn()){
      tell_room(environment(query_worn()),"%^RED%^An irate follower of Ibrandul attacks "+query_worn()->query_cap_name()+" wishing to gain possession of the mask.",query_worn());
      tell_object(query_worn(),"%^RED%^An irate follower of Ibrandul materializes and atacks you.");
       ob = new(MON+"followers");
       ob->move(environment(query_worn()));
       ob->kill_ob(query_worn());
   }

   if(!random(50) && objectp(query_worn())) query_worn()->force_me("emote cackles demonically.");
   if(!random(50) && objectp(query_worn())) query_worn()->force_me("emote grins evilly.");
   if(!random(50) && objectp(query_worn())) query_worn()->force_me("emote does a crazy dance as if possessed.");
   if(!random(50) && objectp(query_worn())) tell_object(query_worn(),"%^MAGENTA%^A voice in your head hisses:%^RESET%^ we must destroy Shar!");
   if(!random(50) && objectp(query_worn())) tell_object(query_worn(),"%^MAGENTA%^A voice in your head hisses:%^RESET%^ we will see Ibrandul returned to his body and power!");
}

void set_property(string prop, mixed value){
   if(prop == "enchantment" && value > 0) return;
   ::set_property(prop, value);
}


int query_size(){
    if(!objectp(ETO) || !living(ETO)) return 2;
    return ETO->query_size();
}
