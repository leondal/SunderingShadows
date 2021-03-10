#include <std.h>
#include <daemons.h>
#define WAIT_TIME 14400

inherit "/d/common/obj/clothing/cloak.c";

int used_time;


void create()
{
    ::create();
    set_name("Seeker");
    set_id(({"seeker","seeker's path","cloak","hooded cloak"}));

     set_obvious_short("%^BOLD%^%^BLACK%^A h%^RESET%^o%^BOLD%^%^BLACK%^oded "+
   "s%^RESET%^pi%^BOLD%^%^BLACK%^ders%^RESET%^il%^BOLD%^%^BLACK%^k "+
   "clo%^RESET%^a%^BOLD%^%^BLACK%^k%^RESET%^");

   set_short("%^RESET%^%^CYAN%^S%^GREEN%^e%^BOLD%^e%^RESET%^%^CYAN%^k%^GREEN%^e%^CYAN%^r's "+
   "P%^BOLD%^%^GREEN%^a%^RESET%^%^GREEN%^t%^CYAN%^h%^WHITE%^");

   set_long("%^BOLD%^%^BLACK%^Fashioned from spidersilk, "+
   "this cloak is smooth and light, and remarkably protective. "+
   "It features a deep hood which can be raised to keep out the "+
   "worst of the elements. The cloth is so light that a "+
   "%^RESET%^%^CYAN%^mild breeze %^BOLD%^%^BLACK%^is enough to send "+
   "%^RESET%^r%^BOLD%^%^BLACK%^ip%^RESET%^p%^BOLD%^%^BLACK%^l%^RESET%^e%^BOLD%^%^BLACK%^s "+
   "across its black surface, like light "+
   "r%^RESET%^ef%^BOLD%^%^BLACK%^lec%^RESET%^t%^BOLD%^%^BLACK%^i%^RESET%^n%^BOLD%^%^BLACK%^g "+
   "off deep, dark waters. This is the only touch of opulence found "+
   "on the cloak, relying upon this %^RESET%^simple elegance "+
   "%^BOLD%^%^BLACK%^to bring beauty to this striking garment. "+
   "Two silken cords keep the cloak tightly tied along the collarbone.%^RESET%^"
   );

   set_lore("%^CYAN%^It is said that decades ago, a man by the name of "+
   "%^GREEN%^Bahri al-Skaar %^CYAN%^was named Champion of %^BOLD%^Tyr%^RESET%^%^CYAN%^, "+
   "and gifted with the "+
   "%^BOLD%^%^GREEN%^S%^RESET%^%^CYAN%^e%^GREEN%^e%^BOLD%^k%^RESET%^%^CYAN%^e%^BOLD%^%^GREEN%^r's "+
   "P%^RESET%^%^GREEN%^a%^CYAN%^t%^BOLD%^%^GREEN%^h %^RESET%^%^CYAN%^so that he "+
   "may more easily track down those who would hide away from due justice. "+
   "The magic was so great, that Bahri would need only to think to "+
   "%^BOLD%^<%^BLACK%^seek%^CYAN%^> %^RESET%^%^CYAN%^a name known to him, "+
   "and he would find himself whisked away to their location! For many years, "+
   "he served Tyr faithfully, and with the cloak's aid brought down many evil "+
   "men. Taking a rare break from his duties, Bahri was exploring some southern "+
   "islands when his ship was attacked and lost to Pirate Lord "+
   "%^BOLD%^%^BLACK%^Jean Avery%^RESET%^%^CYAN%^. To the relief of many, the "+
   "cloak was found amongst the wreckage of the ship, and used to locate "+
   "Jean Avery, thus bringing him to justice. It was said the cloak was "+
   "then secured away as a sacred artifact of the faith, but records of "+
   "it are hard to come by. Others have tried to replicate the "+
   "Seeker's magic, but whether they were successful or not is unknown.%^WHITE%^"
   );

    set_weight(2);

    set_property("no curse",1);
    set_property("enchantment",7);

    set_item_bonus("attack bonus",7);
    set_item_bonus("stealth",6);

    set_value(275000);

    set_wear((:TO,"wear_me":));
    set_remove((:TO,"remove_me":));

    set_property("quest required","%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("level required",35);
}


int wear_me()
{
tell_object(ETO,"%^BOLD%^%^BLACK%^The cloak slips around your shoulders weightlessly, the soft spidersilk gently rustling around you.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+"%^BOLD%^%^BLACK%^ ties a long dark cloak around "+ETO->QP+" %^BOLD%^%^BLACK%^shoulders,"
				  "the soft spidersilk gently rustling%^RESET%^.",ETO);
   return 1;
}


int remove_me()
{
   tell_object(ETO,"%^BOLD%^%^BLACK%^You miss the comfort of the long cloak as you remove it.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^BLACK%^"+ETOQCN+" %^BOLD%^%^BLACK%^unfastens the ties and sets "+ETO->QP+" cloak aside.%^RESET%^",ETO);
   return 1;
}


void init()
{
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

    tell_object(ETO, "%^BOLD%^%^WHITE%^You close your eyes and begin to seek...");
    tell_room(EETO, "%^BOLD%^%^WHITE%^"+ETOQCN+" closes "+ETO->QP+" eyes and begins to fade...", ETO);

    location = environment(find_living(target));

    if(location->query_property("teleport proof") || location->query_property("no teleport") || ETP->query_property("no teleport") || ETP->query_property("teleport proof"))
    {
        notify_fail("Something is blocking your path");
        return 0;
    }
    else
    {
        TP->move_player(location);
        used_time = time();
        return 1;
    }
}


void set_used_time(int x) { used_time = x; }


int query_size()
{
    if(living(ETO)) { return ETO->query_size(); }
    else return 2;
}
