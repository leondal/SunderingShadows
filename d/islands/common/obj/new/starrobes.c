// removed the get/put actions, it wuz not workin. Nienne, 09/07.
// added auto-close of an existing rift if the robe is removed from wearer. Nienne, 11/12.
#include <std.h>

#define CLASSES_ALLOWED ({ "mage","cleric","druid","sorcerer","psion","bard","oracle","inquisitor" })


inherit "/d/common/obj/clothing/magerobe.c";


int uses, open;
object user, to, from;
string short, file;


void create()
{
    ::create();
    set_name("star robes");
    set_id(({"robe","robes","star robes","star robe","robe of stars"}));
    set_obvious_short("%^BOLD%^%^BLUE%^A robe %^CYAN%^d%^BLUE%^e%^CYAN%^c%^BLUE%^o%^CYAN%^ra%^BLUE%^t%^CYA"
                      "N%^ed %^BLUE%^with %^RESET%^%^CYAN%^st%^BOLD%^a%^RESET%^%^CYAN%^rs%^RESET%^");
    set_short("%^BOLD%^%^BLUE%^R%^BOLD%^%^WHITE%^o%^BOLD%^%^BLUE%^b%^BOLD%^%^BLACK%^e o%^BOLD%^%^BLUE%^f"
              " S%^BOLD%^%^WHITE%^t%^BOLD%^%^BLUE%^ar%^BOLD%^%^BLACK%^s%^RESET%^");
    set_long("%^BOLD%^%^BLUE%^This robe is made of many different layers of silk. The fabric is absolutely"
             " smooth to the touch, even more so than average silk. Along the hem of the sleeves and neckli"
             "ne is a %^BOLD%^%^WHITE%^white suede fabric%^BLUE%^ that borders the robes. The silk has bee"
             "n dyed %^BOLD%^%^BLACK%^pitch black%^BOLD%^%^BLUE%^ and %^RESET%^%^BLUE%^dark blue%^BOLD%^%^"
             "BLUE%^ and fades in and out of mixtures throughout the robes. When looking at the robes it r"
             "eminds you of a clear %^BOLD%^%^BLACK%^n%^CYAN%^i%^BLACK%^ght sky%^BLUE%^ as the robes are d"
             "ecorated with millions of tiny %^RESET%^%^CYAN%^st%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^rs%^BOLD"
             "%^%^BLUE%^. However, the %^RESET%^%^CYAN%^st%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^rs%^BOLD%^%^BL"
             "UE%^ are %^BOLD%^%^WHITE%^untouchable%^BOLD%^%^BLUE%^ and are made of no %^RESET%^%^MAGENTA%"
             "^substance%^BOLD%^%^BLUE%^ that you recognize. If you stare hard enough, the %^CYAN%^stars%^"
             "BLUE%^ start to spell something out for you, '%^BOLD%^%^YELLOW%^shift%^BOLD%^%^BLUE%^.'");
    set_lore("%^BOLD%^%^BLUE%^Most of the lore of these robes has been lost to time. However, what is"
             " known is that Au'rus De'Var had them for most of his young adult life and during his t"
             "ravels across the plane, the robes started to collect the %^WHITE%^imprint%^BOLD%^%^BLUE%^"
             " of stars that would allow someone to %^BOLD%^%^YELLOW%^shift%^BOLD%^%^BLUE%^ from one"
             " %^CYAN%^plane %^BLUE%^ to another %^RESET%^%^CYAN%^plane%^BOLD%^%^BLUE%^. De'var seems to"
             " the only one capable of using them for %^CYAN%^pl%^GREEN%^a%^CYAN%^n%^GREEN%^a%^CYAN%^r"
             " %^BOLD%^%^BLUE%^travel, while everyone can open %^WHITE%^rifts%^BOLD%^%^BLUE%^ across t"
             "he prime material %^GREEN%^plane%^BLUE%^. From a passage in Kellan Te'mil Vespar's - Tra"
             "vel's of Ao'rus De'Var%^RESET%^");
    set_weight(5);
    set_value(330000);
    set_type("clothing");
    set_limbs(({"torso"}));

    set_property("no curse",1);
    set_property("enchantment",7);
    set_property("lore difficulty", 45);
    set_item_bonus("magic resistance",4);
    set_item_bonus("bonus_spell_slots",3);

    set_wear((:TO,"wear":));
    set_remove((:TO,"remove_me":));
    open = 0;

    set_property("quest required","%^BOLD%^%^RED%^Defeated the great red wyrm Klauth!%^RESET%^");
    set_property("level required",35);
}


int wear()
{
    string *classes;
    int i;

    if(!objectp(ETO) || !living(ETO)) { return 0; }

    classes = ETO->query_classes();
    for(i=0;sizeof(classes),i<sizeof(classes);i++)
    {
        if(member_array(classes[i],CLASSES_ALLOWED) != -1) { return 1; }
    }

    tell_object(ETO, "The magic of the robe repels you.");
    return 0;

}



int remove_me()
{
    if(open)
    {
        if(objectp(to)) to->remove_exit("rift");
        if(objectp(from)) from->remove_exit("rift");
        to = 0; from = 0; open = 0;
    }
    return 1;
}



void init()
{
    ::init();
    add_action("put_into", "put");
    add_action("get_from", "get");
    add_action("shift", "shift");

    if (interactive(ETO)) {
        if (TO->add_item_owner(ETOQN)) {
            switch ((string)ETO->query_class()) {
            case "mage": case "psion":
                set_item_bonus("intelligence", 6);
                break;
            case "cleric": case "druid": case "inquisitor":
                set_item_bonus("wisdom", 6);
                break;
            case "bard": case "warlock": case "sorcerer": case "oracle" :
                set_item_bonus("charisma", 6);
                break;
            }
        }
    }
}

int shift(string str)
{
    int i, all;
    string temp;

    if(TP->query_bound() || TP->query_unconscious())
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }

    if(!(query_worn()))
    {
        write("You must wear it first.");
        return 1;
    }

    user = TP;

    switch(str)
    {
    case "close":

        if(!open) { break; }
        tell_object(user, "%^BOLD%^%^WHITE%^You speak a foreign word and the rift in space shimmers before vanishing.%^RESET%^");
        if(objectp(to)) { tell_room(to, ""+user->QCN+" speaks a foreign word and the rift in space shimmers, before vanishing.%^RESET%^",({user})); }
        close_rift();
        break;

    case "open":

        if((!file) || (!short)) { break; }
        if(open) { break; }

        if(member_array("rift",environment(TP)->query_exits()) != -1)
        {
            return notify_fail("There is already a rift here!\n");
        }

        if(environment(TP)->query_property("no teleport"))
        {
            return notify_fail("There is too much magical interference here.\n");
        }

        if(environment(TP)->query_property("teleport proof") > 50)
        {
            return notify_fail("There is too much magical interference here.\n");
        }

        from = environment(TP);
        to = find_object_or_load(file);

        if(!objectp(to)) { return notify_fail("The robe's magic fizzles, losing connection to its endpoint."); }

        if(member_array("rift",to->query_exits()) != -1)
        {
            return notify_fail("An existing rift interferes with your endpoint!\n");
        }

        if(to->query_property("no teleport"))
        {
            return notify_fail("There is too much magical interference.\n");
        }

        if(to->query_property("teleport proof") > 50)
        {
            return notify_fail("There is too much magical interference.\n");
        }

        open_rift();
        break;

    case "set":

        if(environment(TP)->query_property("no teleport")) { return 1; }

        else
        {
            file = base_name(environment(TP));
            short = environment(TP)->query_short();
        }
        break;

    default:

        tell_object(TP,"%^BOLD%^BLUE%^As you speak the word, this fills your mind%^RESET%^\n\n"
                       "Shift set...............Set this area as destination.\n"
                       "Shift open..............Open a rift in time and space to this place.\n"
                       "Shift close.............Close the rift in time and space.\n\n\n"
                       "SHIFT\n");

        if((!file) || (!short))
        {
            tell_object(TP, "None.\n");
            return 1;
        }

        tell_object(TP,"Set Destination:  --------> "+short+"\n");
        break;
    }

    return 1;
}


int open_rift()
{
    tell_object(user, "%^BOLD%^%^BLUE%^You speak a foreign word and a rift in space opens up in front of you.%^RESET%^");
    tell_room(from, ""+user->QCN+" speaks a foreign word and a rift in time and space comes to form!%^RESET%^",({user}));
    tell_room(to, "%^BOLD%^%^BLUE%^A bright point of light appears from nowhere and suddenly it opens into a shimmering rift through time and space!!%^RESET%^");

    to->add_exit(base_name(from), "rift");
    from->add_exit(base_name(to), "rift");

    open = 1;
    return 1;
}


int close_rift()
{
    if(objectp(to))
    {
        tell_room(to, "%^BOLD%^%^WHITE%^The rift in space shimmers for only a second then vanishes!%^RESET%^");
        to->remove_exit("rift");
    }

    if(objectp(from))
    {
        tell_room(from, "%^BOLD%^%^WHITE%^The dimensional rift in space shimmers for a moment then vanishes!%^RESET%^");
        from->remove_exit("rift");
    }

    to = 0; from = 0; open = 0;
    return 1;
}


int query_size()
{
    if(living(ETO)) { return ETO->query_size(); }
    else return 3;
}
