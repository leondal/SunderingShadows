#include <std.h>
inherit "/d/common/obj/weapon/whip_dagger.c";

string OWNER;

void init() 
{
    ::init();
    if(interactive(ETO) && ETO==environment(TO) && !OWNER) OWNER = ETOQN;
}

void create()
{
    ::create();
    set_name("rosevine whip");
    set_id(({ "whip","rosevine whip", "rose whip" }));
    set_short("%^RESET%^%^RED%^R%^BOLD%^o%^RESET%^%^ORANGE%^s"+
    "%^YELLOW%^e%^MAGENTA%^v%^RESET%^%^MAGENTA%^i%^BOLD%^n"+
    "%^YELLOW%^e %^RESET%^%^GREEN%^Whip%^RESET%^");
    set_obvious_short("%^RESET%^%^GREEN%^A %^RESET%^%^RED%^r%^BOLD%^"+
    "o%^RESET%^%^ORANGE%^s%^YELLOW%^e%^MAGENTA%^v"+
    "%^RESET%^%^MAGENTA%^i%^BOLD%^n%^YELLOW%^e "+
    "%^RESET%^%^GREEN%^whip%^RESET%^");
	
    set_long(
    "%^GREEN%^"+
    "A long lush vine coils about five feet in length.  Woven "+
    "across the living vine are a series of rosevines.  "+
    "The buds of the roses have not yet bloomed and range "+
    "in color from %^RED%^d%^BOLD%^a%^RESET%^%^RED%^r%^BOLD%^"+
    "k%^RESET%^%^RED%^ r%^BOLD%^e%^RESET%^%^RED%^d%^GREEN%^, "+
    "%^YELLOW%^yellow%^RESET%^%^GREEN%^,%^BOLD%^%^MAGENTA%^ pink"+
    "%^RESET%^%^GREEN%^, %^MAGENTA%^violet%^GREEN%^, and"+
    " %^ORANGE%^c%^BOLD%^%^MAGENTA%^o%^RESET%^%^ORANGE%^r"+
    "%^BOLD%^%^MAGENTA%^a%^RESET%^%^ORANGE%^l%^GREEN%^."+
    "  Sharp thick thorns rise off the surface of the whip."+
    "  A handle of any kind seems to be missing on this whip."+
    "%^RESET%^"
    );
    set_weight(3);
    set_value(random(200)+1220);
    set_lore("The rosevine whip was first crafted by a "+
    "coven of priestess' of Eldath, Silvanus, and "+
    "Mielikki.  The dryads and nymphs quickly fell "+
    "in love with the weapon after its creation and "+
    "have used them from that day to now.  Some who "+
    "follow Sune have adopted the whip as well, as "+
    "their favored weapon.");
    set_property("lore",6);
    set_property("enchantment",3);
    set_wield((:TO,"wield_func":));
    set_unwield((:TO,"unwield_func":));
    set_hit((:TO,"hit_func":));
}

int wield_func()
{
    if(interactive(ETO) && (string)ETO->query_name() != OWNER)
    {
        tell_object(ETO,"%^BOLD%^%^GREEN%^The whip has not "+
        "bonded with you and does not recognize you as "+
        "its owner!\nThe vine writhes in your hands as "+
        "you try to wield it raking you with it's thorns, "+
        "then it simply withers and turns to dust.");
    	ETO->do_damage("torso",random(4)+5);
        TO->remove();
        return 0;
    }
    if((int)ETO->query_level() < 21) 
    {
        notify_fail("The whip's thorn scratch you as you try to "+
        "wield it, you simply do not have the skill to use it yet!");
        ETO->do_damage("torso",random(2)+2);
        return 0;
    }
    tell_room(environment(ETO),"%^GREEN%^"+ETOQCN+" looks a bit surprised as the "+
    "vine wraps about "+ETO->QP+" arm.",ETO);
    tell_object(ETO,"%^GREEN%^The whip wraps about your arm and "+
    "secures itself to your hand bonding itself to you.");
    return 1;
}
int unwield_func()
{
    tell_room(environment(ETO),"%^GREEN%^The whip slowly unwraps "+
    "itself from "+ETO->QCN+"'s arm.",ETO);
    tell_object(ETO,"%^GREEN%^As if sensing your thoughts, the whip "+
	"unwraps itself from your forearm.");
    return 1;
}
int hit_func(object targ)
{
    if(!objectp(targ)) return 0;
    if(random(1000) < 200)
    {
        switch(random(50))
        {
            case 0..30:
                tell_room(environment(ETO),"%^GREEN%^"+ETO->QCN+" snaps "+
                "the whip into the air releasing a volley of thorns "+
                "at "+targ->QCN+"!",({ETO,targ}));
                tell_object(targ,"%^GREEN%^"+ETO->QCN+" snaps "+
                "the whip in the air releasing a volley of thorns at you!");
                tell_object(ETO,"%^GREEN%^You snap the whip into the air "+
                "releasing a volley of thorns at "+targ->QCN+"!");
                targ->do_damage("torso",(random(2)+1));
                targ->do_damage("torso",(random(2)+1));
                targ->do_damage("torso",(random(2)+1));
                break;
            case 31..39:
                tell_room(environment(ETO),"%^GREEN%^The %^RED%^rosebuds %^GREEN%^on the vine "+
                "wrapped about "+ETO->QCN+" bloom briefly "+
                "and and %^YELLOW%^glow%^RESET%^%^GREEN%^ slightly before "+
                "closing back up again!",ETO);
                tell_object(ETO,"%^GREEN%^The %^RED%^rosebuds %^GREEN%^on the vine bloom "+
                "with a sudden %^YELLOW%^glow%^RESET%^%^GREEN%^ then close "+
                "as rapidly leaving you a somewhat refreshed.");
                ETO->do_damage("torso",-(random(6)+8));
                break;
	    	case 40..49:
                tell_room(environment(ETO),"%^ORANGE%^The thorns on the rosevine around "+ETO->QCN+"'s arm"+
                "harden and start to grow.",ETO);
                tell_object(ETO,"%^ORANGE%^The thorns on your rosevine whip start to"+
                " harden and grown in size.");
                new("/cmds/spells/t/_thorn_spray")->use_spell(ETO,targ,12,100,"cleric");
                break;
            default:
                tell_object(ETO,"Something is boogered up!!!");
                return 1;
                break;
        }
    }
}