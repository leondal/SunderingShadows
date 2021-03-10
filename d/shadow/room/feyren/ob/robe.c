#include <std.h>
#include "../inherits/area_stuff.h"
inherit "/d/common/obj/armour/robe";

void create()
{
    ::create();
    set_name("bright green robe");

    set_id(({ "robe", "green robe", "bright robe", 
    "bright green robe", "ashillas robe", "ashillas vestment", 
    "vestment" }));
	
    set_obvious_short("%^BOLD%^%^GREEN%^A bright green "+
    "robe%^RESET%^");

    set_short("%^BOLD%^%^GREEN%^Ash%^BOLD%^%^CYAN%^"+
    "i%^BOLD%^%^GREEN%^ll%^BOLD%^%^CYAN%^a%^BOLD%^%^GREEN%^"+
    "'s V%^BOLD%^%^CYAN%^e%^BOLD%^%^GREEN%^stm%^BOLD%^%^CYAN%^"+
    "e%^BOLD%^%^GREEN%^nt%^RESET%^");
	
    set_long("%^BOLD%^%^GREEN%^This robe has been tailored "+
    "from a %^BOLD%^%^CYAN%^strange%^BOLD%^%^GREEN%^ br"+
    "%^BOLD%^%^YELLOW%^i%^BOLD%^%^GREEN%^ll%^BOLD%^%^YELLOW%^"+
    "ia%^BOLD%^%^GREEN%^nt green material. It looks "+
    "%^BOLD%^%^RED%^hazy%^BOLD%^%^GREEN%^ and a thin "+
    "layer of %^BOLD%^%^WHITE%^foggy mist%^BOLD%^%^GREEN%^ "+
    "hangs in the air around it. %^BOLD%^%^RED%^Sp%^BOLD%^%^BLACK%^"+
    "i%^BOLD%^%^RED%^ders%^BOLD%^%^GREEN%^ of varying "+
    "breeds have been %^BOLD%^%^YELLOW%^em%^BOLD%^%^GREEN%^"+
    "br%^BOLD%^%^YELLOW%^oi%^BOLD%^%^GREEN%^d"+
    "%^BOLD%^%^YELLOW%^e%^BOLD%^%^GREEN%^r%^BOLD%^%^YELLOW%^"+
    "e%^BOLD%^%^GREEN%^d on the back of it. The %^BOLD%^"+
    "%^RED%^sp%^BOLD%^%^BLACK%^"+
    "i%^BOLD%^%^RED%^der%^BOLD%^%^GREEN%^ images appear "+
    "to move about randomly, as if they are actually "+
    "alive. The robe extends down to just below the knees of "+
    "the wearer. The seams are a much %^RESET%^%^GREEN%^"+
    "darker green%^BOLD%^%^GREEN%^ and look fairly "+
    "haphazard, as if it were patched together "+
    "by someone of a questionable skill. The neckline is "+
    "cut unevenly and very frayed, causing the robe "+
    "to hang down further "+
    "than what it should. A %^RESET%^%^BLUE%^deep blue "+
    "%^BOLD%^%^GREEN%^and frayed sash helps to "+
    "tie the robe closed.%^RESET%^");

    set_property("lore difficulty", 15);

    set_lore("This strange robe was one of the "+
    "crowning achievements of Ashilla, the Mad. It was said "+
    "to have been gifted to her from a goblin king, "+
    "upon his death, and she embroidered the spiders "+
    "onto the back of it, using a large portion of "+
    "her magic to enchant them. Some believe the "+
    "spiders actually live inside the material of "+
    "the robe and many have cringed at the thought. "+
    "Ashilla was known for her love of arachnids, "+
    "so perhaps there is some truth to that belief.");
         	
    set_value(3000);
    set_size(2);
    set_property("enchantment",2);
    set_heart_beat(1);
    set_wear("%^BOLD%^%^GREEN%^You carefully tie "+
    "the frayed %^RESET%^%^BLUE%^sash%^BOLD%^%^GREEN%^, "+
    "securing your robe in place, and feel a slight "+
    "movement, as if something inside "+
    "the robe has shifted.%^RESET%^");
    set_struck((:TO,"strike_func":));
}

void SpiderMe()
{
    object mon;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(EETO)) return;
    if(!TO->query_worn()) return;
    mon = new(FFMON+"spiderling");
    mon->delete("aggressive");
	
    tell_object(ETO, "%^BOLD%^%^GREEN%^You feel as if "+
    "something large suddenly leaps off of your back and "+
    "are astonished as a "+mon->query_short()+ " "
    "%^BOLD%^%^GREEN%^lands next to you and comes to your "+
    "protection!%^RESET%^");

    tell_room(EETO, "%^BOLD%^%^GREEN%^You watch in astonishment "+
    "as one of the larger %^BOLD%^%^RED%^sp%^BOLD%^%^BLACK%^"+
    "i%^BOLD%^%^RED%^ders%^BOLD%^%^GREEN%^ embroidered "+
    "on the back of "+ETOQCN+"%^BOLD%^%^GREEN%^'s robe "+
    "leaps to life and comes to "+ETO->QP+" protection!%^RESET%^", ETO);

    mon->move(EETO);
    mon->force_me("protect "+ETO->query_name());
    mon->set_property("minion", ETO);
    ETO->add_follower(mon);
    mon->set_new_exp(10, "very low");
}

int strike_func(int damage, object what, object who)
{
    if(!random(20)) SpiderMe();
    return damage;
}

void heart_beat()
{	
    object mon;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(EETO)) return;
    if(!TO->query_worn()) return;
    if(random(1000) < 998) return;
    switch(random(3)) 
    {
        case 0:
            tell_object(ETO, "%^BOLD%^%^BLACK%^You feel, for a fleeting "+
            "moment, as if something is crawling around on your back!"+
            "%^RESET%^");
            if(!ETO->query_invis())
            {
                tell_room(EETO, "%^BOLD%^%^BLACK%^You notice one of the "+
                "%^BOLD%^%^RED%^sp%^BOLD%^%^BLACK%^"+
                "i%^BOLD%^%^RED%^ders%^BOLD%^%^BLACK%^ embroidered on the "+
                "back of "+ETOQCN+"%^BOLD%^%^BLACK%^'s robe move quickly "+
                "to another spot!%^RESET%^", ETO);
            }
            break;
        case 1:
            if(sizeof(ETO->query_attackers()))
            {
                SpiderMe();				
            }
            break;
        case 2:
            tell_object(ETO, "%^BOLD%^%^BLACK%^You feel a sudden sense of "+
            "unease as you feel something skitter up your leg and "+
            "into your robe!%^RESET%^");
			
            if(!ETO->query_invis()) 
            {
                tell_room(EETO, "%^BOLD%^%^BLACK%^You notice a small "+
                "%^BOLD%^%^RED%^p%^BOLD%^%^BLACK%^i%^BOLD%^%^RED%^der"+
                "%^BOLD%^%^BLACK%^ skitter up "+ETOQCN+"%^BOLD%^%^BLACK%^"+
                "'s leg and into "+ETO->QP+" robe!%^RESET%^", ETO);
            }
            break;
    }
    return;
}

