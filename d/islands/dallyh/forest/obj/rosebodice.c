//created by Shar.  altered/added by Circe 4/27/04
#include <std.h>
inherit "/d/common/obj/armour/leather.c";

void create()
{
    ::create();
    set_name("bodice of the rose");
    set_id(({ "bodice", "rose bodice", "red bodice", "bodice of the rose" }));
    set_short("%^BOLD%^%^WHITE%^Bodice of the%^RESET%^ %^RED%^"+
    "R%^YELLOW%^o%^MAGENTA%^s%^RESET%^%^MAGENTA%^e%^RESET%^");
    set_obvious_short("%^BOLD%^%^WHITE%^A leather bodice "+
    "covered with %^RESET%^%^RED%^r%^YELLOW%^o%^MAGENTA%^s"+
    "%^RESET%^%^MAGENTA%^e%^RED%^s%^RESET%^");
    set_long("This halter style bodice has been crafted from "+
    "the softest leather.  Channels of boning have been"+
    " sewn into the leather, giving the bodice a rigid"+
    " shape.  The bodice has been shaped into a "+
    "curvaceous hourglass-like figure, helping a "+
    "woman to achieve a slim and trim apperance, no "+
    "matter her girth or size.  The outside of the "+
    "bodice is covered with a multitude of %^BOLD%^"+
    "%^RED%^r%^WHITE%^o%^YELLOW%^s%^MAGENTA%^e"+
    "%^RESET%^%^MAGENTA%^s%^RESET%^, from buds to "+
    "flowers in full bloom.  %^RED%^Red%^RESET%^"+
    ", %^BOLD%^%^WHITE%^white%^RESET%^, %^YELLOW%^yellow"+
    "%^RESET%^, %^BOLD%^%^MAGENTA%^pink%^RESET%^, and "+
    "%^MAGENTA%^purple%^RESET%^ roses intermix together."+
    "  %^BOLD%^%^GREEN%^Gr%^RESET%^%^GREEN%^een%^BOLD%^ery"+
    "%^RESET%^ adds to the majestic roses, giving them a "+
    "vibrant quality.  The lower portion of the bodice "+
    "features scalloped edges that look like petals "+
    "from a rose.%^RESET%^");
    set_value(1800);
    set_lore("The Bodice of the Rose was said to have been "+
    "crafted by a coven of nature loving enchantresses"+
    " named the Sisters of Flora.  These enchantresses"+
    " devoted their magical craft to bringing the beauty"+
    " of nature into people's lives, so it's said.  "+
    "Followers of Mielikki, many guess, though no one "+
    "can every say they know the names of any of these"+
    " Sisters of Flora.  Their garments, jewelry, and "+
    "armor they have made has been said to have been "+
    "worn by some of the most famous heros in the lands,"+
    " and prized possesions of many noble folk.  The "+
    "female followers of Sune have come to love and "+
    "adore these bodices, as they are able to carry "+
    "and wear the sacred flower of their goddess with "+
    "them always.");
    set_property("lore difficulty",10);
    set_size(2);
    set_property("enchantment",3);
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    set_struck((:TO,"strike_func":));
}

int wear_func()
{
string long;
    if(!interactive(ETO)) return 1;
    if((string)ETO->query_gender() == "male") 
    {
        tell_object(ETO,"%^BOLD%^You listen to your inner"+
        " voice, passing on wearing this armor.");
        tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+""+
        " has second thoughts about wearing the armor.",ETO);
        return 0;
    }
    if((string)ETO->query_diety() == "sune")
    {
        tell_object(ETO,"%^RED%^You slip into the bodice with"+
        " ease and admire the sensual fragrance of the roses.");
        tell_room(environment(ETO),"%^RED%^"+ETOQCN+" slips into the bodice"+
        " with ease and takes a moment to admire the roses.",ETO);
    }
    else
    {
        tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" exhales "+
        "deeply, squeezing herself into the rigid bodice.",ETO);
        tell_object(ETO,"%^BOLD%^%^GREEN%^You slip into the rigid bodice, "+
        "having to exhale deeply to squeeze yourself into it.");
    }
    long = ETO->query_long();
    ETO->set("long","%^BOLD%^%^WHITE%^"+capitalize(nominative(ETO))+" is cloaked "+
    "in the fragrant scent of %^RED%^r%^BOLD%^%^RED%^o"+
    "%^RESET%^%^RED%^s%^BOLD%^%^RED%^e%^RESET%^%^RED%^s%^BOLD%^%^WHITE%^.");
    return 1;
}

int remove_func()
{
    string long;
    if(!interactive(ETO)) return 1;
    if((string)ETO->query_diety() == "sune")
    {
        tell_object(ETO,"%^RED%^You slip out of the bodice with"+
        " ease and admire the sensual fragrance of the roses.");
        tell_room(environment(ETO),"%^RED%^"+ETOQCN+" slips out of the bodice"+
        " with ease and takes a moment to admire the roses.",ETO);
    }
    else
    {
        tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" pulls "+
        "off the bodice covered in roses, taking a moment to catch "+
        "her breath.",ETO);
        tell_object(ETO,"%^BOLD%^%^GREEN%^You pull the bodice off, "+
        "taking a moment to catch your breath.");
    }
    long = ETO->query_long();
    ETO->set("long");
    return 1;
}

int strike_func(int damage, object what, object who)
{
    if(random(1000) < 75)
    {
        tell_room(environment(query_worn()),"%^BOLD%^%^WHITE%^"+ETOQCN+"'s "+
        "bodice blossoms and blooms, sending the sweet fragrance"+
        " of %^RESET%^%^RED%^r%^BOLD%^%^WHITE%^o%^YELLOW%^s%^MAGENTA%^e%^RESET%^"+
        "%^MAGENTA%^s%^BOLD%^%^WHITE%^ into the air.  "+who->QCN+""+
        " seems to be captivated by the scent!",({ETO,who}));
        tell_object(ETO,"%^BOLD%^%^WHITE%^The %^RESET%^%^RED%^r%^YELLOW%^o"+
        "%^MAGENTA%^s%^WHITE%^e%^RESET%^%^MAGENTA%^s%^BOLD%^"+
        "%^WHITE%^ blossom and bloom, sending their sweet "+
        "fragrance into the air.  "+who->QCN+" seems to be "+
        "caught up in the scent!");
        tell_object(who,"%^BOLD%^%^WHITE%^"+ETOQCN+"'s bodice blossoms"+
        " and blooms, sending the sweet fragrance of %^RESET%^%^RED%^r"+
        "%^BOLD%^%^WHITE%^o%^YELLOW%^s%^MAGENTA%^e%^RESET%^%^MAGENTA%^"+
        "s%^BOLD%^%^WHITE%^ into the air.  The %^MAGENTA%^scent"+
        "%^WHITE%^ seems captivating to you, as you stop to enjoy"+
        " the fragrance.");
        who->set_paralyzed(random(4),"%^RED%^You are overcome by the fragrance!");
    }
}
