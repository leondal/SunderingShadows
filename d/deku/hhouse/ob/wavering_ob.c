#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
#define COM "/d/common/obj/weapon/" +

inherit OBJECT;

void create()
{
    ::create();
}

void transform(object ob, string form)
{
    object myOb;
    string* myIds, * myBonuses;
    mapping tmp;
    int x;

    if (!objectp(ob)) {
        return;
    }
    if (!stringp(form)) {
        return;
    }
    tmp = query_item_bonuses();
    if (mapp(tmp)) {
        myBonuses = keys(tmp);
    }

    for (x = 0; x < sizeof(myBonuses); x++) {
        set_item_bonus(myBonuses[x], 0);
        continue;
    }

    switch (form) {
    case "dagger":
        myOb = new(COM "dagger");
        myIds = myOb->query_id();
        myIds += ({ "blue dagger", "dull dagger", "dull blue dagger" });

        ob->set_obvious_short("%^RESET%^%^BLUE%^dull blue dagger%^RESET%^");

        ob->set_long("%^RESET%^%^BLUE%^This small dagger extends to perhaps " +
                     "fourteen inches in length. It is much heavier than a typical " +
                     "dagger and seems much sturdier. One side of the blade is flat and slightly " +
                     "thicker. The other side is honed down to a %^BOLD%^%^RED%^sharp" +
                     " point%^RESET%^%^BLUE%^ which seems to give off a constant aura of " +
                     "%^BOLD%^%^CYAN%^cold%^RESET%^%^BLUE%^. There are strange %^BOLD%^%^CYAN%^" +
                     "runes%^RESET%^%^BLUE%^ covering the length of the blade that seem to change " +
                     "constantly, as if looking for a true form but never finding it. " +
                     "The very tip of the blade is a much %^BOLD%^%^BLACK%^darker%^RESET%^%^BLUE%^" +
                     " hue. The crossguard comes out to a point on either side of the blade and the " +
                     "tip of each point is the same %^BOLD%^%^BLACK%^darker%^RESET%^%^BLUE%^ hue as the " +
                     "tip of the blade. The hilt of the dagger is much thicker with a rough texture, " +
                     "an obvious attempt to make the grip of the wielder more secure. A small round knob " +
                     "extends from the bottom of the hilt to serve as the pommel. An %^BOLD%^%^WHITE%^" +
                     "inscription%^RESET%^%^BLUE%^ on the pommel catches your eye.%^RESET%^");
        ob->set_mystate("dagger");
        ob->clear_item_bonus();
        ob->set_item_bonus("dexterity", 4);
        ob->set_item_bonus("dungeoneering", 4);
        ob->set_item_bonus("stealth", 4);
        break;
    case "longbow":
        myOb = new("/d/common/obj/lrweapon/longbow");
        myIds = myOb->query_id();
        myIds += ({ "blue longbow", "longbow","bow" });

        ob->set_obvious_short("%^RESET%^%^BLUE%^blue longbow%^RESET%^");

        ob->set_long("%^RESET%^%^BLUE%^This longbow extends to perhaps " +
                     "sixty inches in length. It is much heavier than a typical " +
                     "longbow and seems much sturdier. One side of the bow is flat and slightly " +
                     "thicker. The other side is honed down to a %^BOLD%^%^RED%^sharp" +
                     " point%^RESET%^%^BLUE%^ which seems to give off a constant aura of " +
                     "%^BOLD%^%^CYAN%^cold%^RESET%^%^BLUE%^. There are strange %^BOLD%^%^CYAN%^" +
                     "runes%^RESET%^%^BLUE%^ covering the length of the bow that seem to change " +
                     "constantly, as if looking for a true form but never finding it. " +
                     "The very tips of the bow is a much %^BOLD%^%^BLACK%^darker%^RESET%^%^BLUE%^" +
                     " hue. The metal string comes out to a point on either side of the bow and the " +
                     "material of the string is the same %^BOLD%^%^BLACK%^darker%^RESET%^%^BLUE%^ hue as the " +
                     "tips of the bow. The arrow rest of the bow is much thicker with a rough texture, " +
                     "an obvious attempt to make the grip of the wielder more secure. An %^BOLD%^%^WHITE%^" +
                     "inscription%^RESET%^%^BLUE%^ on the side catches your eye.%^RESET%^");
        ob->set_mystate("longbow");
        ob->clear_item_bonus();
        ob->set_item_bonus("dexterity", 4);
        ob->set_item_bonus("damage bonus", 4);
        ob->set_item_bonus("stealth", 4);
        break;
    case "short sword":
        myOb = new(COM "shortsword");

        myIds = myOb->query_id();
        myIds += ({ "blue sword", "blue shortsword", "blue short", "dull short", "dull sword", "dull shortsword" });

        ob->set_obvious_short("%^RESET%^%^BLUE%^dull blue short sword%^RESET%^");

        ob->set_long("%^RESET%^%^BLUE%^This short sword extends to perhaps " +
                     "eighteen inches in length. It is heavier than a typical " +
                     "short sword and seems much sturdier. Both sides of its blade are " +
                     "slightly %^BOLD%^%^RED%^serrated%^RESET%^%^BLUE%^ and seem to give off a " +
                     "constant aura of %^BOLD%^%^CYAN%^cold%^RESET%^%^BLUE%^. The tip of each serrated " +
                     "point is a much %^BOLD%^%^BLACK%^darker%^RESET%^%^BLUE%^ hue. " +
                     "There are strange %^BOLD%^%^CYAN%^" +
                     "runes%^RESET%^%^BLUE%^ covering the length of the blade that seem to change " +
                     "constantly, as if looking for a true form but never finding it. " +
                     "The crossguard splits into two pieces on either side of the blade and there " +
                     "are jagged spikes lining it where it splits, making it look almost like a " +
                     "snout lined with %^BOLD%^%^WHITE%^teeth%^RESET%^%^BLUE%^. The hilt is much " +
                     "narrower and has grooves that run the length of it, an obvious attempt to " +
                     "reinforce the grip of the wielder. A large %^BOLD%^%^BLUE%^bright blue%^RESET%^" +
                     "%^BLUE%^ knob extends from the end of the hilt and serves as the pommel. " +
                     "An %^BOLD%^%^WHITE%^inscription%^RESET%^%^BLUE%^ on the pommel catches your " +
                     "eye.%^RESET%^");
        ob->set_mystate("short sword");
        ob->clear_item_bonus();
        ob->set_item_bonus("dexterity", 4);
        ob->set_item_bonus("perception", 4);
        ob->set_item_bonus("stealth", 4);
        break;
    case "scimitar":
        myOb = new(COM "scimitar");

        myIds = myOb->query_id();
        myIds += ({ "blue scimitar", "dull scimitar", "dull blue scimitar" });

        ob->set_obvious_short("%^RESET%^%^BLUE%^dull blue scimitar%^RESET%^");

        ob->set_long("%^RESET%^%^BLUE%^This scimitar extends to almost three feet in " +
                     "length. It is heavier than a typical scimitar and seems much " +
                     "sturdier. The blade curves back from the hilt to the tip drastically " +
                     "with one edge of it honed down to a %^BOLD%^%^RED%^razor sharp%^RESET%^" +
                     "%^BLUE%^ point. The edge of the blade is giving off a constant aura of " +
                     "%^BOLD%^%^CYAN%^cold%^RESET%^%^BLUE%^. There are strange %^BOLD%^%^CYAN%^runes" +
                     "%^RESET%^%^BLUE%^ covering the length of the blade that seem to change " +
                     "constantly, as if looking for a true form but never finding it. " +
                     "The crossguard is simply straight but it is covered with spots of " +
                     "%^BOLD%^%^BLUE%^brighter blue%^RESET%^%^BLUE%^ hues that taper off " +
                     "slowly toward their edges. The hilt is much thicker and heavier " +
                     "and wrapped with layers of metal that are quite rough, seemingly an " +
                     "attempt to reinforce the grip of the wielder. A tiny knob extends from the " +
                     "end of the hilt and seems to serve as the pommel. An %^BOLD%^%^WHITE%^" +
                     "inscription%^RESET%^%^BLUE%^ on the pommel catches your eye.%^RESET%^");
        ob->clear_item_bonus();
        ob->set_item_bonus("strength", 4);
        ob->set_item_bonus("endurance", 4);
        ob->set_item_bonus("athletics", 4);
        ob->set_mystate("scimitar");
        break;
    case "long sword":
        myOb = new(COM "longsword");

        myIds = myOb->query_id();

        myIds += ({ "blue sword", "dull sword", "dull blue sword", "blue long sword",
                    "dull long sword", "dull blue long sword" });

        ob->set_obvious_short("%^RESET%^%^BLUE%^dull blue long sword%^RESET%^");

        ob->set_long("%^RESET%^%^BLUE%^This long sword extens to almost four feet in " +
                     "length. It is slightly lighter than a typical long sword but still seems much " +
                     "sturdier. The blade comes to a %^BOLD%^%^RED%^razor sharp%^RESET%^%^BLUE%^ " +
                     "edge on one side and on the other it is very %^BOLD%^%^RED%^serrated%^RESET%^%^BLUE%^, " +
                     "with numerous tiny %^BOLD%^%^WHITE%^teeth%^RESET%^%^BLUE%^ running the length of " +
                     "it. Both edges of the blade are giving off a constant aura of %^BOLD%^%^CYAN%^cold" +
                     "%^RESET%^%^BLUE%^. There are strange %^BOLD%^%^CYAN%^runes%^RESET%^%^BLUE%^ covering " +
                     "the length of the blade that seem to change constantly, as if looking for a true form " +
                     "but never finding it. The crossguard is a much %^BOLD%^%^BLACK%^darker%^RESET%^%^BLUE%^" +
                     " hue that forms an %^BOLD%^%^WHITE%^'%^BOLD%^%^CYAN%^X%^BOLD%^%^WHITE%^'%^RESET%^%^BLUE%^. " +
                     "The hilt narrows toward the center and has been contoured to provide a better " +
                     "grip to whoever wields it. A large squared knob, made from a %^BOLD%^%^BLUE%^" +
                     "brighter blue%^RESET%^%^BLUE%^ metal extends from the end of the hilt and serves as " +
                     "the pommel. An %^BOLD%^%^WHITE%^inscription%^RESET%^%^BLUE%^ on the pommel catches " +
                     "your eye.%^RESET%^");
        ob->clear_item_bonus();
        ob->set_item_bonus("strength", 4);
        ob->set_item_bonus("survival", 4);
        ob->set_item_bonus("perception", 4);
        ob->set_mystate("long sword");
        break;
    case "two handed sword":
        myOb = new(COM "two_hand_sword");

        myIds = myOb->query_id();

        myIds += ({ "blue sword", "dull sword", "dull blue sword", "blue two handed sword",
                    "dull two handed sword", "dull blue two handed sword" });

        ob->set_obvious_short("%^RESET%^%^BLUE%^dull blue two handed sword%^RESET%^");

        ob->set_long("%^RESET%^%^BLUE%^This massive sword extends to a little more than " +
                     "six feet in length. It is much ligher than a typical two handed sword but " +
                     "still seems much sturdier. One side of the blade is flatter with the other side " +
                     "coming to a %^BOLD%^%^RED%^fine edge%^RESET%^%^BLUE%^ that slowly tapers off toward " +
                     "the center. The edge of the blade is giving off a constant aura of %^BOLD%^%^CYAN%^cold" +
                     "%^RESET%^%^BLUE%^. There are strange %^BOLD%^%^CYAN%^runes%^RESET%^%^BLUE%^ covering " +
                     "the length of the blade that seem to change constantly, as if looking for a true form " +
                     "but never finding it. The crossguard has broken off on either side of the blade " +
                     "leaving behind %^BOLD%^%^GREEN%^vicious jagged %^RESET%^%^BLUE%^edges. The hilt " +
                     "mushrooms out, becoming thicker toward the bottom, an attempt to make the swings " +
                     "of the blade more balanced while at the same time providing a more sure grip for " +
                     "the wielder. An oval shaped knob extends from the end of the hilt and serves as the " +
                     "pommel. An %^BOLD%^%^WHITE%^inscription%^RESET%^%^BLUE%^ on the pommel catches your " +
                     "eye.%^RESET%^");
        ob->clear_item_bonus();
        ob->set_item_bonus("strength", 4);
        ob->set_item_bonus("influence", 4);
        ob->set_item_bonus("healing", 4);
        ob->set_mystate("two handed sword");
        break;
    }
    if (!ob->query_property("enchantment")) {
        ob->set_property("enchantment", 5);
    }
    ob->set_wc((int)myOb->query_wc_num(), (int)myOb->query_wc_dice());
    ob->set_large_wc((int)myOb->query_large_wc_num(), (int)myOb->query_large_wc_dice());
    ob->set_type(myOb->query_type());
    ob->set_weapon_prof(myOb->query_weapon_prof());
    ob->set_weapon_speed(myOb->query_weapon_speed());
    ob->set_critical_threat_range(myOb->query_critical_threat_range());
    ob->set_critical_hit_multiplier(myOb->query_criticial_hit_multiplier());
    ob->set_damage_type(myOb->query_damage_type());
    ob->set_repair_type("weaponsmith");
    ob->set_size(myOb->query_size());
    if (objectp(myOb)) {
        myOb->remove();
    }
    myIds += ({ "wavering" });
    ob->set_id(myIds);
    if (objectp(TO)) {
        TO->remove();
    }
}

//all damage is cold damage - Saide
//1st special
//dagger specials through stoneskin

//shortsword/longsword - heal the wielder

//scimitar/two handed - extra attacks

//2nd special
//dagger/two handed/shortsword - poisons

//scimitar/longsword - trips

void special_attack(object ob, object targ, string form)
{
    object EOB, EEOB;
    string limb, tmp;
    int dam, num;
    if (!objectp(ob) || !objectp(targ) || !stringp(form)) {
        TO->remove();
        return;
    }
    EOB = environment(ob);
    if (!objectp(EOB)) {
        TO->remove();
        return;
    }
    EEOB = environment(environment(ob));
    if (!objectp(EEOB)) {
        TO->remove();
        return;
    }
    limb = targ->return_target_limb();
    tmp = ob->query_obvious_short();
    if (form == "longbow") {
        tmp = "arrow";
    }

    num = random(10);
    //  tell_object(EOB, "NUM = "+num);
    switch (num) {
    case 0..4:
        tell_object(EOB, "%^BOLD%^%^BLUE%^You cut deeply into " + targ->QCN + "%^BOLD%^%^BLUE%^" +
                    "'s " + limb + " and rip your " + tmp + "%^BOLD%^%^BLUE%^ away, spinning around slamming into " +
                    targ->QP + " nose!%^RESET%^");

        tell_object(targ, EOB->QCN + "%^BOLD%^%^BLUE%^ cuts deep into your " + limb + " then rips " +
                    EOB->QP + " freezing cold " + tmp + "%^BOLD%^%^BLUE%^ away to spin around and slam into your " +
                    "nose!%^RESET%^");

        tell_room(EEOB, EOB->QCN + "%^BOLD%^%^BLUE%^ cuts deeply into " + targ->QCN + "%^BOLD%^%^BLUE%^ " +
                  "'s " + limb + " and then rips " + EOB->QP + " " + tmp + "%^BOLD%^%^BLUE%^ away and spins around " +
                  "slamming into " + targ->QCN + "%^BOLD%^%^BLUE%^'s nose!%^RESET%^", ({ EOB, targ }));

        targ->cause_typed_damage(targ, limb, roll_dice(1, 12), "bludgeoning");
        TO->remove();
        return;
        break;
    case 5..8:
        switch (form) {
        case "dagger": case "longbow":
            tell_object(EOB, "%^BOLD%^%^GREEN%^You slash deep into " + targ->QCN + "%^BOLD%^%^" +
                        "%^GREEN%^'s " + limb +
                        " and watch as %^BOLD%^%^CYAN%^ice crystals%^BOLD%^%^GREEN%^ form in the " +
                        "wound!%^RESET%^");

            tell_object(targ, EOB->QCN + "%^BOLD%^%^GREEN%^ slashes deep into your " + limb +
                        " with " + EOB->QP + " frezing cold " + tmp + "%^BOLD%^%^GREEN%^ and %^BOLD%^%^CYAN%^ice crystals " +
                        "form in the wound!%^RESET%^");

            tell_room(EEOB, EOB->QCN + "%^BOLD%^%^GREEN%^ slashes deep into " + targ->QCN + " " + limb +
                      " with " + EOB->QP + " " + tmp + "%^BOLD%^%^GREEN%^ and %^BOLD%^%^CYAN%^ice crystals " +
                      "form in " + targ->QCN + "%^BOLD%^%^GREEN%^'s wound!%^RESET%^", ({ EOB, targ }));

            EOB->set_property("magic", 1);
            targ->cause_typed_damage(targ, limb, roll_dice(2, 8), "cold");
            EOB->set_property("magic", -1);
            TO->remove();
            return;

        case "long sword": case "short sword":
            tell_object(EOB, "%^BOLD%^%^GREEN%^You sink your " + tmp + "%^BOLD%^%^GREEN%^ deep into " +
                        targ->QCN + "%^BOLD%^%^GREEN%^ and feel your own %^BOLD%^%^RED%^lifeforce%^BOLD%^%^GREEN%^ " +
                        "replenished!%^RESET%^");

            tell_object(targ, EOB->QCN + "%^BOLD%^%^GREEN%^ sinks " + EOB->QP + " " + tmp + "%^BOLD%^%^GREEN%^ " +
                        "deep into you and you watch in %^BOLD%^%^RED%^horror%^BOLD%^%^GREEN%^ as " + EOB->QP +
                        " wounds heal on their own!%^RESET%^");

            tell_room(EEOB, EOB->QCN + "%^BOLD%^%^GREEN%^ sinks " + EOB->QP + " " + tmp + "%^BOLD%^%^GREEN%^ " +
                      "deep into " + targ->QCN + " and you watch as " + EOB->QP + " wounds seem to mend " +
                      "themselves!%^RESET%^", ({ EOB, targ }));

            dam = roll_dice(2, 8);
            EOB->heal(dam);
            targ->cause_typed_damage(targ, limb, dam, "cold");
            TO->remove();
            return;

        case "scimitar": case "two handed sword":
            tell_object(EOB, "%^BOLD%^%^RED%^You growl in rage slicing your " + tmp +
                        " across " + targ->QCN + "%^BOLD%^%^RED%^" +
                        "'s " + limb + " and your rage empowers you to swing again!%^RESET%^");

            tell_object(targ, EOB->QCN + "%^BOLD%^%^RED%^ growls in rage as " + EOB->QS +
                        " slices " + EOB->QP + " freezing cold " + tmp + "%^BOLD%^%^RED%^ across your " + limb +
                        " " + EOB->QP + " rage empowering " + EOB->QO + " to swing again!%^RESET%^");

            tell_room(EEOB, EOB->QCN + "%^BOLD%^%^RED%^ growls in rage as " + EOB->QS +
                      " slices " + EOB->QP + " " + tmp + "%^BOLD%^%^RED%^ across " + targ->QCN +
                      "%^BOLD%^%^RED%^'s " + limb + " and " + EOB->QP + " rage empowers " +
                      EOB->QO + " to swing again!%^RESET%^", ({ EOB, targ }));

            targ->cause_typed_damage(targ, limb, roll_dice(2, 6), "cold");
            EOB->execute_attack();
            TO->remove();
            return;
        }
        break;
    case 9:
        switch (form) {
        case "dagger": case "scimitar": case "short sword": case "longbow":
            tell_object(EOB, "%^BOLD%^%^CYAN%^As your " + tmp + "%^BOLD%^%^CYAN%^ " +
                        "sinks into " + targ->QCN + "%^BOLD%^%^CYAN%^'s " + limb + " you watch as the edge of " +
                        "the blade momentarily glows a %^BOLD%^%^GREEN%^ghastly green" +
                        "%^BOLD%^%^CYAN%^!%^RESET%^");

            tell_object(targ, EOB->QCN + "%^BOLD%^%^CYAN%^'s freezing cold " +
                        tmp + "%^BOLD%^%^CYAN%^ sinks into your " + limb + " and the edge of the " +
                        "blade momentarily glows a %^BOLD%^%^GREEN%^ghastly green" +
                        "%^BOLD%^%^CYAN%^ and you feel a substance pumped into the " +
                        "wound!%^RESET%^");

            tell_room(EEOB, "%^BOLD%^%^CYAN%^As " + EOB->QCN + "%^BOLD%^%^CYAN%^'s " +
                      tmp + "%^BOLD%^%^CYAN%^ sinks into " + targ->QCN + "%^BOLD%^%^CYAN%^'s " +
                      limb + " the edge of the blade momentarily glows a %^BOLD%^%^GREEN%^" +
                      "ghastly green%^BOLD%^%^CYAN%^!%^RESET%^", ({ EOB, targ }));

            POISON_D->ApplyPoison(targ, "any", ob, "injury");

            targ->cause_typed_damage(targ, limb, roll_dice(3, 6), "cold");
            TO->remove();
            return;
        case "two handed sword": case "long sword":

            tell_object(EOB, "%^BOLD%^%^MAGENTA%^You slash your " + tmp +
                        "%^BOLD%^%^MAGENTA%^ across " + targ->QCN + "%^BOLD%^%^MAGENTA%^'s " +
                        limb + " and then quickly sweep the blade under " + targ->QP +
                        " feet, tripping " + targ->QO + "!%^RESET%^");

            tell_object(targ, EOB->QCN + "%^BOLD%^%^MAGENTA%^ slashes " +
                        EOB->QP + " freezing cold " + tmp + "%^BOLD%^%^MAGENTA%^ across your " + limb +
                        " and then quickly sweeps the blade under your feet, " +
                        "tripping you!%^RESET%^");

            tell_room(EEOB, EOB->QCN + "%^BOLD%^%^MAGENTA%^ slashes " +
                      EOB->QP + " " + tmp + "%^BOLD%^%^MAGENTA%^ across " + targ->QCN +
                      "%^BOLD%^%^MAGENTA%^'s " + limb + " and then quickly sweeps the " +
                      "blade under " + targ->QP + " feet, tripping " + targ->QO +
                      "!%^RESET%^", ({ EOB, targ }));

            targ->cause_typed_damage(targ, limb, roll_dice(3, 6), "cold");

            targ->set_tripped(3 + random(3), "%^BOLD%^%^MAGENTA%^You " +
                              "struggle to get back to your feet!%^RESET%^");

            TO->remove();
            return;
        }
        break;
    }
}
