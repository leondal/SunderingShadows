#include <std.h>
#include <daemons.h>
#define WAIT_TIME 14400


inherit ARMOUR;
int used_time;

void create() {
::create();
   set_name("Seeker");
   set_id(({"seeker","seeker's path","cloak","hooded cloak"}));
   set_obvious_short("%^BOLD%^%^BLACK%^hooded black cloak%^RESET%^");
   set_short("%^BOLD%^%^WHITE%^S%^BOLD%^%^BLACK%^ee%^BOLD%^%^WHITE%^k%^BOLD%^%^BLACK%^e%^BOLD%^%^WHITE%^r'%^BOLD%^%^BLACK%^s P%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^th%^RESET%^");
   set_long("%^RESET%^%^CYAN%^This cloak lacks design"+
   " or fancy decorations. Its beauty lies in its simple"+
   " elegance. The whole cloak and hood are fashioned from"+
   " spider silk giving it an unnatural smoothness."
   );
   set_lore("This cloak was worn by High Priest of Tyr many"+
   " years ago. He issued the cloak to champions of his god"+
   " so that they might <seek> out grave violators of justice."+
   " Then one day the High Priest boat was sank when he did not have the cloak."+
   " The cloak was then used to find the one responsible for sinking"+
   " the boat and it was never seen again."
   );
   set_weight(2);
   set_type("clothing");
   set_limbs(({"neck"}));
   set_ac(0);
   set_item_bonus("attack bonus",2);
   set_item_bonus("stealth",2);
   while((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   set_value(75000);
   set_wear((:TO,"wear_me":));
   set_remove((:TO,"remove_me":));
}

int wear_me() {
   if(member_array("%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"You have not earned the right to make use of this item.");
     return 0;
   }
   if((int)ETO->query_level() < 35) {
     tell_object(ETO,"The cloak doesn't seem to fit you.");
     return 0;
   }
   tell_object(ETO,"%^BOLD%^%^BLACK%^You slip the smooth hood over your head.");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" slips a smooth dark hood over "+ETO->QP+" head.",ETO);
   return 1;
}


int remove_me() {
   tell_object(ETO,"%^BOLD%^%^BLACK%^You remove your hood and slip the cloak off your shoulders.");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" slips the hood off and removes the cloak.",ETO);
   return 1;
}

void init(){
   ::init();
   add_action("seeker","seek");
}

int seeker(string str)
{
    object ob,location;
    string target;
    if(!str) return 0;
    if(!TO->query_worn())
    {
        tell_object(TP,"You can't feel anything from the cloak, without it wrapped about you.");
        return 1;
    }
    if(WAIT_TIME > (time() - used_time))
    {
        tell_object(TP,"The magic is faded.");
        return 1;
    }
    if (ETO->query_bound() || EETO->query_unconscious() || EETO->query_paralyzed())
    {
        ETO->send_paralyzed_message("info",ETO);
    }

    target = ETO->realNameVsProfile(str);
    ob = find_player(target);

    if(!ob)
    {
        notify_fail("Nothing happens...");
        return 0;
    }
    if(ob == TP)
    {
        notify_fail("You need only look around you to find yourself!\n");
        return 0;
    }
    if(wizardp(ob))
    {
        notify_fail("Nothing happens...");
        return 0;
    }
    write("%^BOLD%^%^WHITE%^You close your eyes and begin to seek...");
    say("%^BOLD%^%^WHITE%^"+ETOQCN+" closes "+ETO->QP+" eyes and begins to fade...");
    location = environment(find_living(target));
    if(location->query_property("teleport proof") || location->query_property("no teleport") || ETP->query_property("no teleport") || ETP->query_property("teleport proof"))
    {
        notify_fail("Something is blocking your path");
        return 0;
    }
    else
    {
        this_player()->move_player(location);
        used_time = time();
        return 1;
    }
}


void set_used_time(int x) {
   used_time = x;
}


int query_size(){
    if(living(ETO))
        return ETO->query_size();
    else return 2;
}
