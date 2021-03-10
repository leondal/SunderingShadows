#include <std.h>

inherit "/d/common/obj/weapon/quarter_staff.c";

string owner;

void init()
{
    ::init();
    if (!objectp(ETO) || !living(ETO)) {
        return;
    }
    if (interactive(TP) && TP == environment(TO) && !wizardp(TP) && !owner) {
        owner = TPQN;
    }
    add_action("resize_staff", "grow");
    add_action("attune_staff", "attune");
}

void resize_staff(string str)
{
    string args;
    if (!regexp(str, "^staff small|normal|big")) {
        return 0;
    }

    sscanf(str, "staff %s", args);
    switch (args) {
    case "small":
        TO->set_size(2);
        tell_object(TP, "%^RESET%^%^BOLD%^The staff shrinks to fit your hand!");
        break;

    case "normal":
        TO->set_size(3);
        tell_object(TP, "%^RESET%^%^BOLD%^The staff assumes normal size!");
        break;

    case "big":
        TO->set_size(4);
        tell_object(TP, "%^RESET%^%^BOLD%^The staff grows even larger!");
        break;

    default:
        ;
        break;
    }
    return 1;
}

void attune_staff(string str)
{
    string args;
    int resistance_base = 50;
    if (!regexp(str, "^staff cold|acid|fire|electricity")) {
        return 0;
    }

    sscanf(str, "staff %s", args);
    switch (args) {
    case "cold":
        TO->set_item_bonus("cold resistance", resistance_base);
        TO->set_item_bonus("electricity resistance", 0);
        TO->set_item_bonus("acid resistance", 0);
        TO->set_item_bonus("fire resistance", 0);
        tell_object(ETO, "%^CYAN%^The staff glows bright blue.");
        break;

    case "electricity":
        TO->set_item_bonus("cold resistance", 0);
        TO->set_item_bonus("electricity resistance", resistance_base);
        TO->set_item_bonus("acid resistance", 0);
        TO->set_item_bonus("fire resistance", 0);
        tell_object(ETO, "%^ORANGE%^The staff glows bright orange.");
        break;

    case "acid":
        TO->set_item_bonus("cold resistance", 0);
        TO->set_item_bonus("electricity resistance", 0);
        TO->set_item_bonus("acid resistance", resistance_base);
        TO->set_item_bonus("fire resistance", 0);
        tell_object(ETO, "%^GREEN%^The staff glows bright green.");
        break;

    case "fire":
        TO->set_item_bonus("cold resistance", 0);
        TO->set_item_bonus("electricity resistance", 0);
        TO->set_item_bonus("acid resistance", 0);
        TO->set_item_bonus("fire resistance", resistance_base);
        tell_object(ETO, "%^GREEN%^The staff glows bright red.");
        break;
    }
    return 1;
}

void create()
{
    ::create();
    set_name("staff of elemental essence");
    set_id(({ "staff", "staff of elemental essence", "quartz staff" }));
    set_obvious_short("%^BOLD%^%^WHITE%^A thick quartz staff%^RESET%^");
    set_short("%^BOLD%^%^WHITE%^Staff of %^RESET%^%^CYAN%^E%^BOLD%^%^BLUE%^" +
              "l%^RED%^e%^RESET%^%^GREEN%^m%^RED%^e%^BLUE%^n%^RESET%^%^CYAN%^t" +
              "%^GREEN%^a%^BOLD%^%^RED%^l %^BLACK%^E%^RESET%^s%^BOLD%^s%^BLACK%^" +
              "e%^RESET%^n%^BOLD%^c%^BLACK%^e%^RESET%^");
    set_long("%^RESET%^Shaped out of %^BOLD%^%^WHITE%^clear quartz" +
             "%^RESET%^ this thick staff measures about five and a " +
             "half feet long.  The rounded dome top of the staff is " +
             "interlaced with multiple holes, creating an aged look to " +
             "the staff.  The thick %^BOLD%^quartz%^RESET%^ is uneven" +
             " across the surface of the staff, giving it a rough texture." +
             "  Within the staff clashing mists of %^BOLD%^%^BLUE%^sky blue" +
             "%^RESET%^, %^RESET%^%^CYAN%^sea green%^RESET%^, %^GREEN%^forest" +
             " green%^RESET%^, and %^BOLD%^%^RED%^fiery red %^RESET%^can be " +
             "seen, as if a battle rages on inside.");
    set_lore("The Staff of Elemental Essence is a curious staff fashioned by Batlin the Mad Mage in his youth. Opening portals to the elemental planes of Fire, Earth, Air, and Water, Batlin was rumored to have trapped a greater elemental from each plane within a quartz crystal staff. Using his mastery of magic, Batlin has bound the four elementals to the staff and to his will. The elementals inside the staff took the form of pure elemental mist, each one clashing for dominance above the other three. It is the essence of these four elements that power the staff. You can change base element with %^ORANGE%^<attune staff cold | acid | fire | electricity>%^RESET%^. You can change the size of the staff with %^ORANGE%^<grow staff small | normal | big>%^RESET%^");
    set_size(3);
    set_property("lore", 18);
    set_property("enchantment", 6);
    set_wield((: TO, "more_wield" :));
    set_hit((: TO, "more_hit" :));
    set_value(50000);
    set_item_bonus("caster level", 2);
    set_item_bonus("spell penetration", 3);
    set_item_bonus("sight bonus", 5);
    set_property("able to cast", 1);
}

int more_wield()
{
    int resistance_base;
    string color, wield_message;
    resistance_base = 50;
    if (member_array("%^BOLD%^%^RED%^Won %^RESET%^%^RED%^a %^BOLD%^%^CYAN%^fair %^RESET%^%^CYAN%^challenge %^RED%^against %^BOLD%^B%^CYAN%^a%^RED%^tl%^CYAN%^i%^RED%^n%^RESET%^", ETO->query_mini_quests()) == -1) {
        tell_object(ETO, "%^BOLD%^You have not earned the %^CYAN%^right%^RESET%^%^BOLD%^ to make use of this item.");
        return 0;
    }
    if ((int)ETO->query_level() < 35) {
        tell_object(ETO, "%^BOLD%^You are too weak to handle this staff!");
        return 0;
    }
    switch (random(4)) {
    case 0:
        TO->set_item_bonus("cold resistance", resistance_base);
        TO->set_item_bonus("electricity resistance", 0);
        TO->set_item_bonus("acid resistance", 0);
        TO->set_item_bonus("fire resistance", 0);
        color = "%^CYAN%^";
        break;

    case 1:
        TO->set_item_bonus("cold resistance", 0);
        TO->set_item_bonus("electricity resistance", resistance_base);
        TO->set_item_bonus("acid resistance", 0);
        TO->set_item_bonus("fire resistance", 0);
        color = "%^ORANGE%^";
        break;

    case 2:
        TO->set_item_bonus("cold resistance", 0);
        TO->set_item_bonus("electricity resistance", 0);
        TO->set_item_bonus("acid resistance", resistance_base);
        TO->set_item_bonus("fire resistance", 0);
        color = "%^GREEN%^";
        break;

    case 3:
        TO->set_item_bonus("cold resistance", 0);
        TO->set_item_bonus("electricity resistance", 0);
        TO->set_item_bonus("acid resistance", 0);
        TO->set_item_bonus("fire resistance", resistance_base);
        color = "%^RED%^";
        break;

    default:
        TO->set_item_bonus("cold resistance", resistance_base);
        TO->set_item_bonus("electricity resistance", 0);
        TO->set_item_bonus("acid resistance", 0);
        TO->set_item_bonus("fire resistance", 0);
        color = "%^CYAN%^";
    }
    if (ETO->is_class("mage") || ETO->is_class("sorcerer") || ETO->is_class("warlock") || ETO->is_class("psion")) {
        wield_message = "bending to your might.";
    }else if (ETO->is_class("cleric") || ETO->is_class("druid")) {
            wield_message = "bending to your will within the staff.";
    }else if (ETO->is_class("bard")) {
            wield_message = "throbbing rhythmically.";
    }else {
        tell_object(ETO, "%^BOLD%^Your mind just doesn't know how to harness" + " the power of this staff.");
        return 0;
    }
    if (!ETO->query_property("silent_wield")) {
        tell_object(ETO, color + "%^BOLD%^As you grip the staff you can feel the raw power of the elements " + wield_message);
    }
    return 1;
}

int more_hit(object targ)
{
    int me_int, you_wis, dam;

    if (!objectp(ETO)) {
        return 1;
    }
    if (!objectp(targ)) {
        return 1;
    }

    me_int = (int)ETO->query_stats("intelligence");
    you_wis = (int)targ->query_stats("wisdom");

    dam = (int)ETO->query_base_character_level() + me_int - you_wis;
    if (dam <= 1) {
        dam = 1;
    }

    if (!random(4)) {
        switch (random(5)) {
        case 0:
            tell_object(ETO, "%^RED%^The fiery red mist inside the" +
                        " staff flares to life and releases a jet of " +
                        "flames at " + targ->QCN + "!");
            tell_object(targ, "%^RED%^" + ETO->QCN + "'s quartz staff glows" +
                        " fiery red and releases a jet of flames at you!");
            tell_room(ETO, "%^RED%^" + ETO->QCN + "'s quartz staff glows fiery" +
                      " red and releases a jet of flames at " + targ->QCN + "" +
                      ".", ({ targ, ETO }));
            new("/cmds/spells/f/_fireball")->use_spell(ETO, targ, dam, 100, "mage");
            break;

        case 1:
            tell_object(ETO, "%^BOLD%^%^BLUE%^The sky blue mist" +
                        " inside the staff flares to life and releases a bolt of" +
                        " lighting at " + targ->QCN + "!");
            tell_object(targ, "%^BOLD%^%^BLUE%^" + ETO->QCN + "'s quartz staff " +
                        "glows sky blue and releases a bolt of lightning at you!");
            tell_room(ETO, "%^BOLD%^%^BLUE%^" + ETO->QCN + "'s quartz staff glows" +
                      " sky blue and releases a bolt of lightning at" +
                      " " + targ->QCN + "!", ({ targ, ETO }));
            new("/cmds/spells/l/_lightning_bolt")->use_spell(ETO, targ, dam, 100, "mage");
            break;

        case 2:
            tell_object(ETO, "%^CYAN%^The sea green mist inside the " +
                        "staff flare to life and releases an orb of frost at" +
                        " " + targ->QCN + "!");
            tell_object(targ, "%^CYAN%^" + ETO->QCN + "'s quartz staff glows sea" +
                        " green and releases an orb of frost at you!");
            tell_room(ETO, "%^CYAN%^" + ETOQCN + "'s quartz staff glows sea green" +
                      " and releases an orb of frost at " + targ->QCN + "!", ({ targ, ETO }));
            new("/cmds/spells/f/_frost_orb")->use_spell(ETO, targ, dam, 100, "mage");
            break;

        case 3:
            tell_object(ETO, "%^GREEN%^The forest green mist inside the staff" +
                        " flares to life and releases an orb of acid at " + targ->QCN + "!");
            tell_object(targ, "%^GREEN%^" + ETOQCN + "'s quartz staff glows forest" +
                        " green and releases an orb of acid at you!");
            tell_room(ETO, "%^GREEN%^" + ETOQCN + "'s quartz staff glows forest " +
                      "green and releases an orb of acid at " + targ->QCN + "" +
                      "!", ({ targ, ETO }));
            new("/cmds/spells/a/_acid_orb")->use_spell(ETO, targ, dam, 100, "mage");
            break;

        default:
            break;
        }
        return roll_dice(2, 3);
    }
    return roll_dice(1, 4);
}
