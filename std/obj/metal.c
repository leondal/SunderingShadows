//metal.c
// values tweaked by Styx 3/21/03 with T's agreement to adjust
// with the adj. for quality being a mult of 10 for high, made making things far too expensive and also made for potential fencing imbalance
// I'm going to recommend that only mithril and adamantium be able to be enchanted, or at least have a higher success rate
//updated it to make good quality metal harder to find to help balance out the player made armor ac problem and drive prices up 7/11/04 -Tsera
//added cold iron for flavor purposes, metal quality really doesn't mean much anymore, so evening out roll there - Odin 5/6/2020
#include <std.h>
#include <materials.h>

inherit MATERIAL;

string metalType;


void set_metal_type(string type)
{
    if (member_array(lower_case(type), METAL_TYPES) == -1) {
        error("Invalid metal type."); return;
    }
    TO->set_subtype(lower_case(type));
    TO->set_name("" + query_subtype() + " metal");
    TO->set_id(({ "billet", query_subtype(), "metal" }));
    TO->set_short("A billet of " + query_subtype() + " metal");
    TO->set_long("This is a billet of " + query_quality() + " " + query_subtype() + ".");
    return;
}

void set_metal_quality(int quality)
{
    if (quality < 1 || quality > 10) {
        error("You must enter a number between 1 and 10 for quality"); return;
    }
    TO->set_quality_type(quality);
    TO->set_long("This is a billet of " + query_quality() + " " + query_subtype() + ".");
    return;
}

void set_metal_quantity(int quantity)
{
    if (quantity < 1) {
        error("You must enter a number greater than 0 for quantity"); return;
    }
    TO->set_uses(quantity);
    return;
}

string getMetalType()
{
    switch (random(17)) {
    case 0:
        return "iron";

    case 1:
        return "copper";

    case 2:
        return "bronze";

    case 3:
        return "steel";

    case 4:
        return "electrum";

    case 5:
        return "silver";

    case 6:
        return "gold";

    case 7:
        return "platinum";

    case 8:
        return "titanium";

    case 9:
        return "darksteel";

    case 10:
        return "fever iron";

    case 11:
        return "arandur";

    case 12:
        return "dlaran";

    case 13:
        return "palladium";

    case 14:
        return "mithril";

    case 15:
        return "adamantium";

    case 16:
        return "cold iron";
    }
}

void create()
{
    int quality;
    ::create();
    quality = random(11) + 1;
    switch (quality) {
    case 1:
        quality = 1;

        break;

    case 2:
        quality = 2;
        break;

    case 3:
        quality = 3;
        break;

    case 4:
        quality = 4;
        break;

    case 5:
        quality = 5;
        break;

    case 6:
        quality = 6;
        break;

    case 7:
        quality = 7;
        break;

    case 8:
        quality = 8;
        break;

    case 9:
        quality = 9;
        break;

    case 10:
        quality = 10;
        break;
    }

    set_type("metal");
    metalType = METAL_TYPES[random(sizeof(METAL_TYPES))];
    set_subtype(metalType);
    set_quality_type(quality);
    set_uses(random(10) + 4);
    set_name(metalType + " metal");
    set_id(({ "billet", metalType, "metal" }));
    set_short("A billet of " + query_subtype() + " metal");
    set_long("This is a billet of " + query_quality() + " " + query_subtype() + ".");
    set_weight(5);
    set_cointype("gold");
    set_property("treasure_type", "5C");
}

int query_value() //all of this is normalized now to make this a flavor effect
{
    switch (query_subtype()) {
    case "iron":
        return query_uses() * query_quality_type() * 100;   // was 75

    case "copper":
        return query_uses() * query_quality_type() * 100;   // was 80

    case "bronze":
        return query_uses() * query_quality_type() * 100;   // was 85

    case "steel":
        return query_uses() * query_quality_type() * 100;   // was 90

    case "electrum":
        return query_uses() * query_quality_type() * 100;  // was=bronze but is rarer

    case "silver":
        return query_uses() * query_quality_type() * 100;   // was 110

    case "gold":
        return query_uses() * query_quality_type() * 100;   // was 110

    case "platinum":
        return query_uses() * query_quality_type() * 100;  // was 450

    case "titanium":
        return query_uses() * query_quality_type() * 100;  // was 275

/* Values adjusted by Styx after discussion with Tristan and player concerns about costs of making armor 3/13/03 - platinum and titanium are equally rare so making them the same
   I was going to try to make coin types comparable proportions but makes it too skewed and I realized that the coin sizes might be different anyway (i.e. copper coins may be very small, so far less material than a gold coin as well as cheaper material)
 */
    case "darksteel":
        return query_uses() * query_quality_type() * 100;

    case "fever iron":
        return query_uses() * query_quality_type() * 100;

    case "arandur":
        return query_uses() * query_quality_type() * 100;

    case "dlaran":
        return query_uses() * query_quality_type() * 100;

    case "palladium":
        return query_uses() * query_quality_type() * 100;

    case "mithril":
        return query_uses() * query_quality_type() * 100;  // was 475

    case "adamantium":
        return query_uses() * query_quality_type() * 100;   // was 475

    case "cold iron":
        return query_uses() * query_quality_type() * 100;

    default:
        return query_uses() * query_quality_type() * 100;   // was 75
    }
}
