#include <std.h>
inherit "/d/common/obj/weapon/mspear.c";
string what;
int healed_time;

void create()
{
    int i;
    ::create();
    set_obvious_short("A medium spear");
    set_short("%^BOLD%^%^BLUE%^Spear of The "+
    "Im%^BOLD%^%^RED%^pal%^BOLD%^%^BLUE%^er%^RESET%^");
    set_id(({"spear","medium spear","impaler spear","spear of impaler",
    "spear of the impaler"}));
    set_name("A medium spear");
    set_long("%^BOLD%^%^RED%^The shaft of this spear is a "+
    "solid piece of %^BOLD%^%^WHITE%^"+
    "mithril%^BOLD%^%^RED%^ that extends approximately "+
    "four feet and ends in a serrated "+
    "point.  Wrapped around the shaft are two rods "+
    "of %^CYAN%^adamantium%^BOLD%^%^RED%^, "+
    "one an %^BOLD%^%^BLACK%^obs%^BOLD%^%^BLUE%^idi%^BOLD%^%^BLACK%^"+
    "an%^BOLD%^%^RED%^ hue "+
    "and the other a deep cri%^BOLD%^%^YELLOW%^mso%^BOLD%^%^RED%^n.  "+
    "They spiral around the shaft of the spear and meet up "+
    "with the tip, then branch off to either side and "+
    "form two sharpened %^BOLD%^%^BLUE%^prongs%^BOLD%^%^RED%^.  "+
    "The handle of the spear is a piece of %^BOLD%^%^GREEN%^emerald"+
    "%^BOLD%^%^RED%^ that has been placed on the end of "+
    "the spear as a sort of covering, the shaft of the spear extends "+
    "through the handle and is capped off with a "+
    "%^BOLD%^%^WHITE%^mithril%^BOLD%^%^RED%^ ball.  Etched into the "+
    "shaft are %^BOLD%^%^BLUE%^mysterious, mystic "+
    "runes%^BOLD%^%^RED%^, the rods of "+
    "%^CYAN%^adamantium%^BOLD%^%^RED%^ meld with the shaft right "+
    "above the handle.%^RESET%^");

    set_lore("%^RED%^Very little is known about this impressive spear.  "+
    "Legend has it that it was forged in the intense heat "+
    "of a volcano and enchanted with the ancient magic "+
    "of a %^YELLOW%^gold dragon%^RESET%^%^RED%^.  The same "+
    "legends say that they were forged for a "+
    "powerful warrior of light who used it to battle evil in "+
    "all parts of the realm. The location of this weapon has "+
    "long since been a mystery, it has not been sighted in "+
    "several decades.%^RESET%^");
    set_property("enchantment", 4);
    set_item_bonus("attack bonus", 2);
    set_item_bonus("damage bonus", 2);
    set_value(7000);
    set_wield((:TO,"wield_me":));
    set_unwield("%^CYAN%^You reluctantly release "+
    "your grip on the spear.%^RESET%^");
    set_hit((:TO,"special":));
    set_special_material_type("silver");
}

int wield_me()
{
    if(ALIGN->is_good(ETO))
    {
        write("%^BOLD%^%^CYAN%^You feel strangely refreshed "+
        "as you take hold of the spear!%^RESET%^");
        if(time() - healed_time > 180)
        {
            ETO->heal(roll_dice(5,10));
            healed_time = time();
        }
        return 1;
    }
    write("%^RED%^A sharp pains wrack your body as you wield the spear!%^RESET%^");
    ETO->do_damage("torso",roll_dice(5,10));
    return 1;
}

int special(object targ)
{
    int chance, dam;
    chance = random(1000);

    if(chance > 350 && chance < 650)
    {
        switch(random(3))
        {
            case 0:
            tell_object(ETO,"%^CYAN%^As you impale " +targ->QCN+
            " with your spear, the %^BOLD%^%^GREEN%^emerald%^CYAN%^ "+
            "handle warms slightly, leaving you feeling "+
            "stranglely refreshed!%^RESET%^");
            ETO->heal(25 + random(25));

            tell_object(targ,ETO->QCN + "%^CYAN%^ impales you with " +
            ETO->QP + " spear!%^RESET%^");

            tell_room(EETO,ETO->QCN + "%^CYAN%^ impales " +
            targ->QCN + "%^CYAN%^ with " + ETO->QP +
            " spear!%^RESET%^",({targ,ETO}));

            dam = roll_dice(2,10);
            return dam;
            break;
        case 1:
            tell_object(ETO, "%^RED%^As you impale " +targ->QCN+
            "%^RED%^ with your spear, a ray of %^MAGENTA%^violet "+
            "%^BOLD%^%^WHITE%^light%^RESET%^%^RED%^ arcs from "+
            "the %^BOLD%^%^RED%^cri%^YELLOW%^mso%^BOLD%^%^RED%^"+
            "n%^RESET%^%^RED%^ prong and strikes " + targ->QO +
            "%^RED%^!%^RESET%^");

            tell_object(targ,"%^RED%^As " + ETO->QCN+
            "%^RED%^ impales you with " + ETO->QP +
            "%^RED%^ spear a ray of %^MAGENTA%^violet "+
            "%^BOLD%^%^WHITE%^light%^RESET%^%^RED%^ arcs from "+
            "its %^BOLD%^%^RED%^cri%^YELLOW%^mso%^BOLD%^%^RED%^"+
            "n%^RESET%^%^RED%^ prong and strikes you!%^RESET%^");

            targ->set_temporary_blinded(5 + random(4),"%^MAGENTA%^ "+
            "You have been blinded by the ray of light!%^RESET%^");

            tell_room(EETO,"%^RED%^As " + ETO->QCN + "%^RED%^ "+
            "impales " +targ->QCN + "%^RED%^ with " +
            ETO->QP + "%^RED%^ spear a ray of %^MAGENTA%^violet"+
            "%^BOLD%^%^WHITE%^ light%^RESET%^%^RED%^ arcs from "+
            "its %^BOLD%^%^RED%^cri%^YELLOW%^mso%^BOLD%^%^RED%^n"+
            "%^RESET%^%^RED%^ prong and strikes " +
            targ->QO + "%^RED%^!%^RESET%^",({targ,ETO}));
            break;

       case 2:
            tell_object(ETO, "%^BOLD%^%^GREEN%^As you impale " +
            targ->QCN + "%^BOLD%^%^GREEN%^ with your spear, a "+
            "bolt of %^BOLD%^%^BLACK%^black %^BOLD%^%^WHITE%^"+
            "light%^BOLD%^%^GREEN%^ arcs from the %^BOLD%^%^BLACK%^"+
            "obs%^BOLD%^%^BLUE%^idi%^BOLD%^%^BLACK%^an%^BOLD%^"+
            "%^GREEN%^ prong and strikes " + targ->QO +
            "%^BOLD%^%^GREEN%^!%^RESET%^");

            tell_object(targ,"%^BOLD%^%^GREEN%^As " + ETO->QCN +
            "%^BOLD%^%^GREEN%^ impales you with " + ETO->QP +
            "%^BOLD%^%^GREEN%^spear a bolt of %^BOLD%^%^BLACK%^"+
            "black %^BOLD%^%^WHITE%^light%^BOLD%^^%^GREEN%^ "+
            "arcs from its %^BOLD%^%^BLACK%^obs%^BLUE%^idi"+
			"%^BOLD%^%^BLACK%^an%^BOLD%^%^GREEN%^ prong and "+
            "strikes you!%^RESET%^");

            targ->set_paralyzed(20,"%^BOLD%^%^BLACK%^ "+
            "You have been frozen by the bolt of light!%^RESET%^");

			tell_room(EETO,"%^BOLD%^%^GREEN%^As " + ETO->QCN +
            "%^BOLD%^%^GREEN%^ impales " + targ->QCN +
            "%^BOLD%^%^GREEN%^ with " + ETO->QP +
            "%^BOLD%^%^GREEN%^ spear a bolt of %^BOLD%^%^BLACK%^"+
            "black%^BOLD%^%^WHITE%^ light%^BOLD%^%^GREEN%^ arcs from "+
            "its %^BOLD%^%^BLACK%^obs%^BLUE%^idi%^BOLD%^%^BLACK%^"+
            "an%^BOLD%^%^GREEN%^ prong and strikes " +
            targ->QCN + "%^BOLD%^%^GREEN%^!%^RESET%^",({targ,ETO}));
		    break;
        }
    }
}
