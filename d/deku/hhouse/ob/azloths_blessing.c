#include <std.h>
#include "../inherits/area_stuff.h"
inherit "/d/common/obj/clothing/magerobe";

void create()
{
    ::create();
    set_name("golden silk robe");
    set_id(({ "robe", "azloths robe", "azloths blessing",
    "blessing robe", "silk robe", "gold robe", "golden robe",
    "golden silk robe", "blessing"}));

    set_short("%^BOLD%^%^WHITE%^Azl%^BOLD%^%^YELLOW%^o"+
    "%^BOLD%^%^WHITE%^th's Bl%^BOLD%^%^YELLOW%^e%^BOLD%^"+
    "%^WHITE%^ss%^BOLD%^%^YELLOW%^i%^BOLD%^%^WHITE%^ng%^RESET%^");

    set_obvious_short("%^BOLD%^%^YELLOW%^A golden silk robe%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^This robe has been expertly "+
    "woven from the finest %^BOLD%^%^YELLOW%^golden%^BOLD%^"+
    "%^WHITE%^ silk. Each thread of the %^BOLD%^%^YELLOW%^"+
    "golden%^BOLD%^%^WHITE%^ silk follows the same distinct "+
    "downward pattern, a further testament to the "+
    "ability of the tailor who fashioned it. A scene has "+
    "been %^BOLD%^%^RED%^embl%^BOLD%^%^WHITE%^a%^BOLD%^%^RED%^"+
    "z%^BOLD%^%^WHITE%^e%^BOLD%^%^RED%^n%^BOLD%^%^WHITE%^e"+
    "%^BOLD%^%^RED%^d%^BOLD%^%^WHITE%^ on the back of the "+
    "garment, in contrast to the rest of the threads, it "+
    "follows an outward pattern, going both directions from "+
    "exactly the center. The scene is that of a "+
    "%^BOLD%^%^CYAN%^warr%^BOLD%^%^YELLOW%^io%^BOLD%^%^CYAN%^r"+
    "%^BOLD%^%^WHITE%^, his flesh coated with a layer of "+
    "stone, sp%^BOLD%^%^YELLOW%^i%^BOLD%^%^WHITE%^nn"+
    "%^BOLD%^%^YELLOW%^i%^BOLD%^%^WHITE%^ng about "+
    "insanely, a %^BOLD%^%^YELLOW%^gl%^BOLD%^%^CYAN%^"+
    "o%^BOLD%^%^YELLOW%^w%^BOLD%^%^CYAN%^i%^BOLD%^%^YELLOW%^"+
    "ng%^BOLD%^%^WHITE%^ scimitar extended from each of "+
    "his hands. The eyes of the %^BOLD%^%^CYAN%^warr%^BOLD%^"+
    "%^YELLOW%^io%^BOLD%^%^CYAN%^r%^BOLD%^%^WHITE%^ "+
    "seem to glance about intelligently, suggesting "+
    "that perhaps there is something to this scene. The "+
    "garment would flow down to near the feet of "+
    "the wearer, almost completely cloaking whoever wears "+
    "it.%^RESET%^");

    set_value(1000);

    set_lore("%^BOLD%^%^WHITE%^The rumours surrounding this "+
    "garment are vast and lengthy.  The most substantial one "+
    "suggests that it was fashioned by a chaotic warrior by "+
    "the name of Azloth. This particular legend states that "+
    "the warrior was angry at the gods for some unspeakable "+
    "tragedy that had befallen him. In his anguish and rage "+
    "he spent years learning how to use some magic, then "+
    "after he believed himself adept enough, he "+
    "taught himself to tailor clothing. Supposedly "+
    "he then hunted down and killed the high priest of "+
    "whichever deity had angered him the most, "+
    "the legends do not specify which one, however "+
    "he was able to use his own magic, along with "+
    "the blood of this high priest, to enchant this "+
    "garment. Unfortunately, the process took "+
    "more out of him than he realized it would, "+
    "which left him weak and unable to defend himself "+
    "from the vengeance that was to come. "+
    "Upon his death his body was locked inside of "+
    "a tomb, where it was believed to lay dormant with "+
    "this robe.%^RESET%^");

    set_property("lore difficulty",18);
    set_property("no curse", 1);
    set_property("enchantment",5);

    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_me":));
    set_struck((:TO,"strike_func":));
    set_item_bonus("bonus_spell_slots_5", 3);
    set_item_bonus("intelligence", 4);
    set_item_bonus("spell damage resistance", 20);
    set_item_bonus("academics", 4);
}

void init()
{
    ::init();
    if(interactive(ETO))
    {
        if(TO->add_item_owner(ETOQN))
        {
            tell_object(ETO, "%^BOLD%^%^WHITE%^You feel an invisible "+
            "wave of energy encompass you for a moment as the "+
            "robe binds to your soul!%^RESET%^");
            if((int)TO->query_size() != (int)ETO->query_size())
            {
                set_size(ETO->query_size());
                tell_object(ETO, "%^BOLD%^%^WHITE%^You feel the robe "+
                "shifting and transforming, as it changes itself "+
                "to fit your body!%^RESET%^");
            }
        }
    }
}


int wear_func()
{

    if(ETO->query_highest_level() < 20)
    {
        tell_object(ETO,"%^BOLD%^%^WHITE%^The magic in the robe "+
        "will not submit to someone as weak as you!%^RESET%^");
        return 0;
    }

    if(!TO->query_owns_item(ETOQN) && ETO->is_player())
    {
        tell_object(ETO,"%^BOLD%^%^WHITE%^The robe has been "+
        "bound to the soul of another!%^RESET%^");
        return 0;
    }

    tell_object(ETO, "%^BOLD%^%^WHITE%^You feel an invisible aura of "+
    "%^BOLD%^%^YELLOW%^energy%^BOLD%^%^WHITE%^ surround "+
    "you as you don the robe!%^RESET%^");
    return 1;
}

int remove_me()
{
    tell_object(ETO, "%^BOLD%^%^WHITE%^You feel the invisible "+
    "%^BOLD%^%^YELLOW%^aura%^BOLD%^%^WHITE%^ fade away!%^RESET%^");
    return 1;
}

int strike_func(int damage, object what, object who)
{
    object mob;
    if(!random(3))
    {
        switch(random(1000))
        {
            case 0..500:
                tell_room(EETO, "%^BOLD%^%^YELLOW%^As "+
                who->QCN+"%^BOLD%^%^YELLOW%^ connects with "+
                "the robe worn by "+ETOQCN+"%^BOLD%^%^YELLOW%^ "+
                "a ray of %^BOLD%^%^CYAN%^energy%^BOLD%^%^YELLOW%^ "+
                "leaps out from it, striking "+
                who->QCN+"%^BOLD%^%^YELLOW%^!%^RESET%^", ({ETO, who}));

                tell_object(ETO, "%^BOLD%^%^YELLOW%^As "+
                who->QCN+"%^BOLD%^%^YELLOW%^ connects with "+
                "your robe, a ray of %^BOLD%^%^CYAN%^energy"+
                "%^BOLD%^%^YELLOW%^ leaps out from it, striking "+
                who->QO+"%^BOLD%^%^YELLOW%^!%^RESET%^");

                tell_object(who, "%^BOLD%^%^YELLOW%^ "+
                "As you connect with the robe worn by "+
                ETOQCN+"%^BOLD%^%^YELLOW%^ a ray of "+
                "%^BOLD%^%^CYAN%^energy%^BOLD%^%^YELLOW%^ "+
                "leaps out from it, striking you!%^RESET%^");

                who->cause_typed_damage(who, "torso", roll_dice(3,4), "light");
                return 0;
                break;

            case 501..995:
                tell_room(EETO, "%^BOLD%^%^WHITE%^As "+
                who->QCN+"%^BOLD%^%^WHITE%^ lands a blow on "+
                ETOQCN+"%^BOLD%^%^WHITE%^'s robe, a massive, "+
                "disembodied sword appears in the air beside "+
                who->QO+"%^BOLD%^%^WHITE%^ and attacks!%^RESET%^", ({who, ETO}));

                tell_object(ETO, "%^BOLD%^%^WHITE%^As "+
                who->QCN+"%^BOLD%^%^WHITE%^ lands a blow on "+
                "your robe, a massive, disembodied sword appears "+
                "in the air beside "+who->QO+"%^BOLD%^%^WHITE%^ and attacks!");

                tell_object(who, "%^BOLD%^%^WHITE%^As you "+
                "land a blow on "+ETOQCN+"%^BOLD%^%^WHITE%^'s "+
                "robe, a massive sword appears in the air "+
                "beside you and attacks!%^RESET%^");

                mob = new(HHMON"disembodied_sword");
                mob->move(EETO);
                mob->set_property("minion", who);
                who->add_follower(mob);
                mob->hit_em(who);
                return 0;
                break;

            case 996..999:
                tell_room(EETO, "%^BOLD%^%^YELLOW%^As "+
                who->QCN+"%^BOLD%^%^YELLOW%^ strikes the "+
                "robe worn by "+ETOQCN+"%^BOLD%^%^WHITE%^ "+
                "you hear a voice speaking in an ancient "+
                "language!%^RESET%^", ({who, ETO}));

                tell_object(ETO, "%^BOLD%^%^YELLOW%^As "+
                who->QCN+"%^BOLD%^%^YELLOW%^ strikes your "+
                "robe, suddenly you begin mouthing the "+
                "%^BOLD%^%^CYAN%^s%^BOLD%^%^YELLOW%^y"+
                "%^BOLD%^%^CYAN%^l%^BOLD%^%^YELLOW%^l"+
                "%^BOLD%^%^CYAN%^a%^BOLD%^%^YELLOW%^b"+
                "%^BOLD%^%^CYAN%^l%^BOLD%^%^YELLOW%^e"+
                "%^BOLD%^%^CYAN%^s %^BOLD%^%^YELLOW%^"+
                "of an ancient word!%^RESET%^");

                tell_object(who, "%^BOLD%^%^YELLOW%^As you "+
                "strike the robe worn by "+ETOQCN+
                "%^BOLD%^%^YELLOW%^ you hear a voice speaking "+
                "in an ancient language!%^RESET%^");

                new("/cmds/spells/s/_stoneskin")->use_spell(ETO, ETO, 25, 25, "mage");
                return 0;
                break;
        }
    }
    return damage;
}
