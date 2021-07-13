#include <std.h>
inherit "/d/common/obj/jewelry/necklace";
int mod, delay, being_hunted, using_amulet, timer, warned, amulet_level;
string belongs_to;
object hunter;

void create()
{
    ::create();
    set_name("glowing sandstone amulet");
    
    set_id(({"amulet", "sandstone amulet", "glowing sandstone amulet",
    "wyndarian trinket", "amulet of the wyndarian legacy", "legacy"}));
	
    set_short("%^RESET%^%^ORANGE%^A%^BOLD%^m%^RESET%^%^ORANGE%^u%^BOLD%^"+
    "l%^RESET%^%^ORANGE%^e%^BOLD%^t%^RESET%^%^ORANGE%^ of The %^BOLD%^W"+
    "%^RESET%^%^ORANGE%^y%^BOLD%^n%^RESET%^%^ORANGE%^d%^BOLD%^%^WHITE%^"+
    "a%^RESET%^%^ORANGE%^r%^BOLD%^i%^RESET%^%^ORANGE%^a%^BOLD%^n%^RESET%^%^ORANGE%^ "+
    "L%^BOLD%^%^CYAN%^e%^RESET%^%^ORANGE%^g%^BOLD%^a%^RESET%^%^ORANGE%^c%^BOLD%^"+
    "y%^RESET%^");
	
    set_obvious_short("%^RESET%^%^ORANGE%^A glowing %^BOLD%^%^YELLOW%^"+
    "sandstone%^RESET%^%^ORANGE%^ amulet%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^This small amulet looks quite mundane. "+
    "It is composed of a very small and light weight piece of simple %^BOLD%^%^YELLOW%^"+
    "sandstone%^RESET%^%^ORANGE%^ with a hole in the center of it. A "+
    "%^RESET%^%^MAGENTA%^cord%^RESET%^%^ORANGE%^ has been run through the "+
    "hole. The %^RESET%^%^MAGENTA%^cord%^RESET%^%^ORANGE%^ looks like nothing "+
    "more than simple %^RESET%^%^MAGENTA%^twine%^RESET%^%^ORANGE%^ that has "+
    "been wrapped together several strands thick. The only strange thing about "+
    "the amulet is that the %^BOLD%^%^YELLOW%^sandstone%^RESET%^%^ORANGE%^ "+
    "gives off a dim glow. As you examine it carefully you notice that there "+
    "is a tiny %^BOLD%^%^BLACK%^inscription%^RESET%^%^ORANGE%^ engraved on the "+
    "underside of it.%^RESET%^");

    set_value(25000);
    
    set_language("wizish");
    
    set_read("\n%^BOLD%^%^WHITE%^My sons,\n\n"+
    "There will be days when your mortal shell is "+
    "simply too much for you... I wish with all that I am that "+
    "this was not the case. Hell, I wish I were still with you, how I know "+
    "that my soul yearns to see all three of you in this life again. \n"+
    "I know that I have went to join Lysara now, these amulets where "+
    "my gift to you for the sacrifice that I had to make that day... \n\n"+
    "With them comes a tremendous power... for on those days in which your "+
    "mortal shell is too much, simply %^BOLD%^%^BLACK%^shed%^BOLD%^%^WHITE%^ "+
    "it. BUT heed my warning, you MUST return to your shell quickly, simply "+
    "by willing the amulet to let you %^BOLD%^%^BLACK%^return%^BOLD%^%^WHITE%^. \n\n"+
    "Also know this, Lysara has warned me, that should your mortal shell be "+
    "shed, there is a planar being who watches, waiting, and he WILL come for you"+
    " and he will demand of you your mortal life, but I have confidence "+
    "and have reassured Lysara that you would be able to persevere.\n\n"+
    "Stay strong my sons, for the journey does not end, it simply changes, and soon "+
    "you too shall come to realize this, \n\n"+
    "Your loving father, \n"+
    "Marsivian Wyndar%^RESET%^");

    set_lore("%^RESET%^%^ORANGE%^These amulets are ancient. They were rumored to be "+
    "divine gifts granted to a man who history has mostly forgotten. His name was "+
    "Marsivian Wyndar. He did not receive the amulets for himself, but rather received "+
    "them as a boon for his three children, Arsheeva, Dyveryll, and Myrkahl. "+
    "The entire family had long ago devoted itself to the service of Lysara and "+
    "ending any and all undead. Marsivian spent his last breath banishing a powerful "+
    "lich that had for years been terrorizing some community in the northern Dagger "+
    "reaches, a community that itself has been forgotten to time. After his death "+
    "the amulets were bestowed to his children by a messenger of Lysara. "+
    "At least if the stories are to be believed. The same stories suggest that "+
    "they were imbued with a powerful magic that allows them to grow in strength as "+
    "the children did. However, their most powerful feature and most dangerous, is the "+
    "ability to become, at will, a ghost and avoid circumstances which would bring about "+
    "certain death. Some rumors suggest that doing so can only happen rarely and "+
    "that there is a heavy penalty invoked, which could include facing Lysara anyway.%^RESET%^");

    set_property("lore difficulty",35);
    
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_me":));
    set_struck((:TO,"strike_func":));
    set_property("no curse", 1);
    set_heart_beat(1);
}

void set_up_amulet(string name, int x)
{
    //mod should be 6 for first place, 7 for 2nd place, and 9 for 3rd place
    belongs_to = name;
    mod = x;
}

void update_bonuses()
{
    if(!objectp(ETO)) return;
    if(!living(ETO)) return;
    if(!intp(mod)) return;
    if(!stringp(belongs_to)) return;
    if((string)ETO->query_name() != belongs_to) return;
    clear_item_bonus();
    amulet_level = (int)ETO->query_base_character_level();
    set_item_bonus("damage resistance", (int)ETO->query_base_character_level()/mod);
    remove_property("enchantment");
    set_property("enchantment", (int)ETO->query_base_character_level()/mod);    
}

void init() 
{
    ::init();
    add_action("shed_act", "shed");
    add_action("return_act", "return");    
}

int return_act(string str)
{
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!ETO->query_ghost() && !using_amulet || belongs_to != (string)ETO->query_name())
    {
        tell_object(ETO, "%^BOLD%^%^WHITE%^The amulet fails to respond!%^RESET%^");
        return 1;
    }
    
    being_hunted = 1; 
    
    tell_object(ETO, "%^BOLD%^%^WHITE%^A cruel voice inside your own mind booms: %^RESET%^"+
    "YOU THINK THAT I HAVE FORGOTTEN MY PROMISE?!?!?! I WILL FIND YOU AND YOU WILL STAND "+
    "BEFORE KELEMVOR!\n");
    
    tell_object(ETO, "%^BOLD%^%^BLACK%^Your possessions instantly return to normal as "+
    "you see your body materialize below you!!%^RESET%^\n");
    
    tell_object(ETO, "%^BOLD%^%^WHITE%^With a frightful ease you return to "+
    "your %^BOLD%^%^RED%^mortal shell%^BOLD%^%^WHITE%^... and a sense of being hunted "+
    "nags heavily on you....%^RESET%^\n");
    
    tell_room(EETO, ETOQCN+"%^BOLD%^%^BLACK%^'s possessions return to norml as "+ETO->QP+
    " body materializes here!!!%^RESET%^", ETO);
    
    tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^ returns to "+ETO->QP+" %^BOLD%^%^RED%^mortal "+
    "shell%^BOLD%^%^WHITE%^!%^RESET%^", ETO);
    delay = time() + 10800;
    ETO->set_ghost(0);
    ETO->new_body();
    using_amulet = 0;
    return 1;
}

int shed_act(string str)
{
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!query_worn()) 
    {
        tell_object(ETO, "%^BOLD%^%^WHITE%^You must be wearing the amulet!%^RESET%^");
        return 1;
    }
    if(delay && delay > time() || using_amulet || belongs_to != (string)ETO->query_name())
    {
        tell_object(ETO, "%^RESET%^%^ORANGE%^The amulet fails to respond!%^RESET%^");
        return 1;
    }
    tell_object(ETO, "%^BOLD%^%^WHITE%^With frightful ease you simply %^BOLD%^%^RED%^"+
    "shed%^BOLD%^%^WHITE%^ your mortal coil and look down as your body simply vanishes!%^RESET%^\n");
    
    tell_object(ETO, "%^BOLD%^%^BLACK%^Your possessions!!! You realize that they have "+
    "clung to you and now give off a nearly blindly %^BOLD%^%^CYAN%^glow%^BOLD%^%^BLACK%^.%^RESET%^\n");
    
    tell_object(ETO, "%^BOLD%^%^CYAN%^You feel strangely at peace.. for a moment, before a voice whispers to you "+
    "from somewhere else.%^RESET%^\n");
    
    tell_object(ETO, "%^BOLD%^%^BLACK%^I AM coming for you and I %^BOLD%^%^RED%^WILL%^BOLD%^%^BLACK%^"+
    " have you.... %^BOLD%^%^RED%^NONE%^BOLD%^%^BLACK%^ should do "+
    "as %^BOLD%^%^RED%^YOU%^BOLD%^%^BLACK%^ have, and %^BOLD%^%^RED%^NONE%^BOLD%^%^BLACK%^ shall!!%^RESET%^\n");
    
    
    tell_room(EETO, ETOQCN+"%^BOLD%^%^WHITE%^ simply sheds "+ETO->QP+" %^BOLD%^%^RED%^mortal shell"+
    "%^BOLD%^%^WHITE%^!! "+capitalize(ETO->QP)+" body quickly vanishes, all of "+ETO->QP+" possessions "+
    "stay with "+ETO->QO+" and begin %^BOLD%^%^CYAN%^glowing%^BOLD%^%^WHITE%^ brilliantly!%^RESET%^", ETO);
    
    ETO->set_ghost(1);
    ETO->reset_all_status_problems();
    all_inventory(ETO)->unequip();
    ETO->set_attackers(({}));
    using_amulet = 1;
    timer = 0;
    warned = 0;
    return 1;
}

int stop_hunting() { being_hunted = 0; }
int query_hunted() { return being_hunted; }
void heart_beat()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!using_amulet) 
    {
        if(amulet_level != (int)ETO->query_base_character_level() && belongs_to == (string)ETO->query_name()) update_bonuses();
        if(being_hunted)
        {
            if(!objectp(hunter))
            {
                hunter = new("/d/islands/common/eldebaro/planar_hunter");
                hunter->hunting(ETO);
                hunter->connected_to(TO);
                hunter->move("/realms/saide/workroom");
            }
        }
        return;
    }
    if(using_amulet)
    {
        if(ETO->query_paralyzed() || ETO->query_blinded() || ETO->query_temporary_blinded()) ETO->reset_all_status_problems();
        timer++;
        if(timer >= 500 && !warned)
        {
            tell_object(ETO, "%^BOLD%^%^CYAN%^A soothing voice whispers to you: %^RESET%^If you do not return "+
            "you shall be lost soon... you shall die for real and go to face Lysara");
            warned = 1;
        }
        if(timer >= 650)
        {
            tell_object(ETO, "%^BOLD%^%^CYAN%^A frantic voice calls out to you: %^RESET%^I am sorry... but your time "+
            "is up.... You go now to face Lysara!%^RESET%^");
            tell_room(EETO, ETOQCN+"%^BOLD%^%^CYAN%^ fades away to meet Lysara!%^RESET%^", ETO);
            warned = 0;
            using_amulet = 0;
            being_hunted = 0;
            timer = 0;
            ETO->die();        
            return;
        }
    }    
}

int wear_func()
{
    tell_object(ETO, "%^RESET%^%^ORANGE%^As you drape the amulet around your neck "+
    "you feel a sense of peace fall over you.%^RESET%^");
    tell_room(EETO, ETOQCN+"%^RESET%^%^ORANGE%^ looks strangely at peace.%^RESET%^", ETO);
    TO->set_overallStatus(100);
    return 1;
}

int remove_me() 
{
    tell_object(ETO, "%^RESET%^%^ORANGE%^As you remove the amulet from around your neck "+
    "you feel the sense of peace provided by it falter.%^RESET%^");
    tell_room(EETO, "%^RESET%^%^ORANGE%^The look of peace falters from "+ETOQCN+"%^RESET%^%^ORANGE%^.%^RESET%^", ETO);
    return 1;
}

int strike_func(int damage, object what, object who)
{
    int flag;
    if(!objectp(TO)) return damage;
    if(!objectp(ETO)) return damage;
    if((string)ETO->query_name() != belongs_to) return damage;
    tell_object(ETO, "%^BOLD%^%^CYAN%^A soothing voice whispers to you: %^RESET%^Death does not come for you yet!%^RESET%^");
    if(objectp(what)) 
    {
        tell_object(ETO, "%^BOLD%^%^BLACK%^The strike by "+what->query_short()+"%^BOLD%^%^BLACK%^ leaves you feeling refreshed!%^RESET%^");
        flag = 1;
    }
    if(objectp(who))
    {
        tell_room(EETO, who->QCN+"%^BOLD%^%^BLACK%^'s strike against "+ETOQCN+"%^BOLD%^%^BLACK%^ leaves "+ETO->QO+" looking refreshed!%^RESET%", ({who, ETO}));
        tell_object(who, "%^BOLD%^%^BLACK%^Your strike against "+ETOQCN+"%^BOLD%^%^BLACK%^ leaves "+ETO->QO+" looking refreshed!%^RESET%^");
        if(!flag)
        {
            tell_object(ETO, who->QCN+"%^BOLD%^%^BLACK%^'s strike against you leaves you feeling refreshed!%^RESET%^");
        }
    }
    ETO->heal(damage);
    return damage;
}

