#include <std.h>
#include <move.h>
#define VALID_OBJECTS (["/d/azha/obj/gmr_ring.c" : "%^BOLD%^%^WHITE%^a small rune covered ring%^RESET%^",\
                        "/d/tharis/barrow/obj/sphere.c" : "%^RESET%^%^GREEN%^a smooth glass sphere%^RESET%^",\
                        "/d/common/obj/potion/legendary_heal.c" : "%^BOLD%^%^CYAN%^several glass vials%^RESET%^",\
                        "/d/common/obj/potion/advanced_heal.c" : "%^BOLD%^%^CYAN%^several glass vials%^RESET%^",\
                        "/d/tharis/obj/bpowder.c" : "%^RESET%^%^WHITE%^a small bag full of a loose substance%^RESET%^",\
                        "/d/dagger/drow/obj/cylinder.c" : "%^BOLD%^%^WHITE%^a small cylinder%^RESET%^",\
                        "/d/dagger/drow/obj/hand.c" : "%^BOLD%^%^RED%^a strange hand%^RESET%^",\
                        "/d/dagger/drow/temple/obj/jewel.c" : "%^BOLD%^%^RED%^a small jewel%^RESET%^",\
                        "/d/dagger/drow/temple/obj/worwell.c" : "%^BOLD%^%^BLUE%^a small piece of fabric%^RESET%^"])

#define VALID_BAD_OBJECTS (["/d/attaya/mon/supersolstice.c" : "%^BOLD%^%^MAGENTA%^a strange breathing substance%^RESET%^",\
                            "/d/deku/keep/monster/massivewerewolf.c" : "%^BOLD%^%^BLACK%^something warm and hairy%^RESET%^",\
                            "/d/shadow/room/goblin/mon/footman.c" : "%^BOLD%^%^GREEN%^something small, odd shaped, and breathing%^RESET%^"])
                        
                     
inherit ARMOUR;
int MYDELAY;
string NEXT_OBJECT, NO_DESC;

void create()
{
    ::create();
    set_name("thick cord of leather");
    set_id(({ "belt", "cord", "leather belt", "leather cord", 
    "summoning belt", "belt of summoning", "thick leather cord"}));
    
    set_short("%^BOLD%^%^YELLOW%^B%^RESET%^%^ORANGE%^e%^BOLD%^%^YELLOW%^lt "+
    "%^RESET%^%^ORANGE%^o%^BOLD%^%^YELLOW%^f s%^RESET%^%^ORANGE%^u%^BOLD%^%^YELLOW%^"+
    "mm%^RESET%^%^ORANGE%^o%^BOLD%^%^YELLOW%^n%^RESET%^%^ORANGE%^i%^BOLD%^%^YELLOW%^"+
    "ng%^RESET%^");
    
    set_obvious_short("%^RESET%^%^ORANGE%^thick leather cord%^RESET%^");
    
    set_long("%^RESET%^%^ORANGE%^This belt is nothing more than several strips of "+
    "leather that have been entwined together. Some of the strips are vastly "+
    "different colors, almost as if the leather used was collected from different "+
    "sources. The belt has a %^BOLD%^%^YELLOW%^small pocket%^RESET%^%^ORANGE%^ in the "+
    "center of the front of it. The pocket is formed where the strips of leather "+
    "have started unwinding. However, no matter how hard you try you cannot put "+
    "anything into it. The pocket seems to be constantly full, though you cannot see "+
    "anything in it. You think that you could %^BOLD%^%^YELLOW%^"+
    "feel around%^RESET%^%^ORANGE%^ inside the pocket or even perhaps "+
    "%^BOLD%^%^YELLOW%^produce something%^RESET%^%^ORANGE%^ from the pocket if you were "+
    "so inclined. Apart from this strange %^BOLD%^%^YELLOW%^small pocket%^RESET%^%^ORANGE%^ "+
    "the belt seems rather mundane.%^RESET%^");

    set_weight(1);
    set_value(700);
    set_lore("%^RESET%^%^ORANGE%^No one knows where these strange belts come from. "+
    "There are few rumors about their origin. One being that a demon, who had a particular "+
    "fondness for grand pranks pretended to be a god and gave them to a group for some grand "+
    "deed. The other being that a deity who himself was fond of pranks blessed a group of "+
    "adventurers with them. There are even fewer rumors about their "+
    "purpose. However, some suggest that the small pocket is actually a tear in this plane "+
    "of existence. Others say that it is a hole, placed quite intentionally by some being or "+
    "another, leading to another plane of existence. The truth is entirely unknown. What is "+
    "known is that these belts can produce objects, sometimes mundane, sometimes grand, and "+
    "if the rumors are to be believed, sometimes catastrophic from where ever the pocket "+
    "leads.%^RESET%^");

    set_property("lore difficulty",25);
    set_type("clothing");
    set_limbs(({ "waist" }));
    set_size(-1);
    set_property("enchantment",5);
    set_wear((:TO,"wear_me":));
    set_remove((:TO,"remove_me":));    
}

void init()
{
    ::init();
    add_action("feel_for", "feel");
    add_action("produce_from", "produce");
}

void reset_delay() { MYDELAY = 0; }
void pick_object()
{
    string *tmp;
    if(!objectp(TO)) return;
    if(stringp(NEXT_OBJECT))
    {
        if(file_exists(NEXT_OBJECT)) return;
    }
    if(random(10)) tmp = keys(VALID_OBJECTS);
    else tmp = keys(VALID_BAD_OBJECTS);       
    NEXT_OBJECT = tmp[random(sizeof(tmp))];
    if(VALID_OBJECTS[NEXT_OBJECT]) NO_DESC = VALID_OBJECTS[NEXT_OBJECT];
    else NO_DESC = VALID_BAD_OBJECTS[NEXT_OBJECT];
    return;  
}

int feel_for(string str)
{
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!TO->query_worn()) return 0;
    if(!stringp(str)) return 0;
    if(str != "around") return 0;
    tell_object(ETO, "%^RESET%^%^ORANGE%^You feel around inside "+
    "the pocket... ");
    if(!ETO->query_invis())
    {
        tell_room(EETO, ETOQCN+"%^RESET%^%^ORANGE%^ seems to be feeling "+
        "around in a pocket on "+ETO->QP+" belt!%^RESET%^");
    }
    if(MYDELAY > time())
    {
        tell_object(ETO, "%^RESET%^%^ORANGE%^...and find nothing useful!%^RESET%^");
        return 1;
    }
    if(!stringp(NEXT_OBJECT)) pick_object();    
    tell_object(ETO, "%^BOLD%^%^BLACK%^.... you feel "+NO_DESC+"%^BOLD%^%^BLACK%^... inside the pocket!%^RESET%^");
    return 1;   
}

int produce_from(string str)
{
    object ob;
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!TO->query_worn()) return 0;
    if(!stringp(str)) return 0;
    if(str != "something") return 0;
    tell_object(ETO, "%^RESET%^%^ORANGE%^You feel around inside "+
    "the pocket attemping to produce something from it...");
    if(!ETO->query_invis())
    {
        tell_room(EETO, ETOQCN+"%^RESET%^%^ORANGE%^ seems to be feeling "+
        "around in a pocket on "+ETO->QP+" belt!%^RESET%^");
    }
    if(MYDELAY > time())
    {
        tell_object(ETO, "%^RESET%^%^ORANGE%^...and find nothing useful!%^RESET%^");
        return 1;
    }
    if(!stringp(NEXT_OBJECT)) pick_object();
    if(!file_exists(NEXT_OBJECT))
    {
        tell_object(ETO, "%^RESET%^%^ORANGE%^you struggle to pull "+NO_DESC+" from the "+
        "pocket but no matter how hard you try it just won't come out!%^RESET%^");
        return 1;
    }
    ob = new(NEXT_OBJECT);
    MYDELAY = time() + roll_dice(30,100);
    if(living(ob))
    {
        tell_object(ETO, "%^BOLD%^%^RED%^You are horrified as you pull "+NO_DESC+" from "+
        "the pocket and realize that it is ALIVE and not happy!%^RESET%^");
        tell_room(EETO, ETOQCN+"%^BOLD%^%^RED%^ looks horrified as "+ETO->QS+" pulls "+
        ob->query_short()+"%^BOLD%^%^RED%^ from the pocket of "+ETO->QP+" belt!%^RESET%^", ETO);
        ob->move(EETO);
        ob->kill_ob(ETO);
        NEXT_OBJECT = 0;
        NO_DESC = 0;
        return 1;        
    }
    tell_object(ETO, "%^BOLD%^%^WHITE%^With a struggle you pull "+NO_DESC+"%^BOLD%^%^WHITE%^ from "+
    "the pocket of your belt!%^RESET%^");
    tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^ struggles with the pocket on "+ETO->QP+
    " belt for a moment before pulling out "+ob->query_short()+"!%^RESET%^", ETO);    
    if(strsrch(base_name(ob), "/d/common/obj/potion") != -1) ob->set_uses(10 + random(16));
    if(ob->move(ETO) != MOVE_OK)
    {
        tell_object(ETO, "%^BOLD%^%^WHITE%^You cannot carry "+NO_DESC+" and "+
        "drop it!%^RESET%^");
        ob->move(EETO);
        tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^ drops "+ob->query_short()+
        "!%^RESET%^", ETO);
    }
    NEXT_OBJECT = 0;
    NO_DESC = 0;
    return 1;    
}


int wear_me() 
{
    if((int)ETO->query_highest_level() < 35)
    {
        tell_object(ETO, "%^BOLD%^%^YELLOW%^No matter how hard you try the "+
        "belt simply won't stay on!%^RESET%^");
        return 0;
    }    
    tell_object(ETO, "%^BOLD%^%^YELLOW%^You tie the ends of the belt together around your waist!%^RESET%^");
    if(!ETO->query_invis()) 
    {
        tell_room(EETO,ETOQCN+"%^BOLD%^%^YELLOW%^ ties the ends of the belt together around "+
        ETO->QP+" waist.%^RESET%^", ETO);
    }
    return 1;
}

int remove_me() 
{
    tell_object(ETO,"%^BOLD%^%^YELLOW%^You untie the ends of the belt and free your waist from it!%^RESET%^");
    if(!ETO->query_invis()) 
    {
        tell_room(EETO,ETOQCN+"%^BOLD%^%^YELLOW%^ unties the ends of the belt "+
        "from around "+ETO->QP+" waist!%^RESET%^", ETO);
    }
    return 1;
}


