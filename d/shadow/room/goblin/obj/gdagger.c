//updated by Circe 6/1/04 with new desc, lore, etc, by Shar
#include <std.h>
inherit "/d/common/obj/weapon/dagger";
void create() {
    ::create();
    set_name("dagger");
    set_id(({"dagger","bone dagger"}));
    set_obvious_short("a bone dagger");
    set_short("%^BOLD%^%^WHITE%^Bone Dagger%^RESET%^");
    set_long("%^BOLD%^This straight dagger is made from the rib of "+
       "some kind of creature.  It does not appear humanoid in origin, "+
       "for the size is much too large.  The bone blade has been "+
       "fashioned into a solid piercing weapon, be it rather crude.  "+
       "Only the tip of the blade is sharp, as this dagger seems to "+
       "be utilized for piercing the flesh rather than slashing.  Dull "+
       "%^BLACK%^grey leather%^WHITE%^ wraps around the pommel of this "+
       "dagger, also carved from the bone.  A small %^RED%^rat's skull"+
       "%^WHITE%^ has been affixed to the bottom of the pommel.%^RESET%^"
    );
    set_lore("The Bone Dagger, many sages feel, is an insight to "+
       "goblinoid shamanism and their hedge wizardry. There are many "+
       "speculations about what processes are used to enchant such a "+
       "blade.  Some claim that the process is a religious one, with "+
       "the use of blood and prayer, where a dark god shows their favor."+
       "  Others scoff at such an idea and instead focuses on the goblin "+
       "witches as how the blade comes to be enchanted and claim the "+
       "magic lies within the skull.  The truth, it seems, no one knows.");
    set_property("lore difficulty",6);
    set_value(30);
    set_property("enchantment",1);
    set_wield((: TO,"extra_wield" :));
    set_hit((: TO,"extra_hit" :));
}
int extra_wield() {
    tell_object(ETO,"%^BOLD%^WHITE%^You grip the dagger and are "+
       "ready to slay!%^RESET%^");
    tell_room(EETO,"%^BOLD%^%^WHITE%^The dagger held by "+ETOQCN+" "+
	"grins evilly to you!%^RESET%^",ETO);
    return 1;
}

int extra_hit(object ob) {
    object vic;
    vic = ETO->query_current_attacker();
    if(!objectp(vic)) return 1;
    if(random(6) > 2) return 1;
       tell_object(ETO,"%^BOLD%^%^WHITE%^You deliver a piece of "+
          "undead wrath upon your foe!%^RESET%^");
       tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" delivers a blow "+
          "of near death upon "+vic->QCN+"!%^RESET%^",(({ETO, vic})));
       tell_object(vic,"%^BOLD%^%^WHITE%^"+ETOQCN+""+
        " just tried to send you to the land of the dead!%^RESET%^");
    return 1;
}
