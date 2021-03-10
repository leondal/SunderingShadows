//updated by Circe 6/1/04 with new desc, lore, etc, by Shar
#include <std.h>

inherit "/d/common/obj/weapon/mace";
void create() {
    ::create();
    set_name("sceptre");
    set_id(({"sceptre","sceptre of might","scepter","scepter of might"}));
    set_obvious_short("a brass scepter");
    set_short("%^YELLOW%^Sceptre of might%^RESET%^");
    set_long("A beaten sphere of %^YELLOW%^brass%^RESET%^ is fused "+
       "to a %^ORANGE%^copper shaft%^RESET%^, to create this scepter.  "+
       "The shaft of the scepter is actually copper wrapped birch, "+
       "providing added strength.   Inlaid into the brass sphere are "+
       "%^BOLD%^%^BLACK%^black pearls%^RESET%^, orbs of %^ORANGE%^amber"+
       "%^RESET%^, and squares of %^GREEN%^bloo%^RED%^d%^GREEN%^sto"+
       "%^RED%^n%^GREEN%^e%^RESET%^.  A raven carved out of %^BOLD%^%^RED%^"+
       "fire opal%^RESET%^ tops the crown of this scepter.%^RESET%^"
    );
    set_lore("This by far is not an object that was made by goblin "+
       "hands.  The scepter seems far polished for something that "+
       "crude and barbaric goblins to have made.  The use of the "+
       "gems and their shapes points to this alone.  Though the "+
       "raven carved out of fire opal seems to point to a now defunct "+
       "warlord by the name of Trelezarn, a human who use to control "+
       "the lands of what is now the city of Shadow.  Trelezarn's "+
       "reign was in the first century, diviners have been able to "+
       "point to somewhere in the area of the years 50 - 75.  "+
       "Trelezarn's kingdom was to be a grand place, until a great "+
       "plague wiped everything out.");
    set_property("lore difficulty",9);
    set_value(100);
    set_property("enchantment",1);
    set_wield((: TO,"extra_wield" :));
    set_unwield((: TO,"extra_unwield" :));
    set_hit((: TO,"extra_hit" :));
}
int extra_wield() {
    tell_object(ETO,"%^YELLOW%^The sceptre begins to glow with an inner "+
      "light.%^RESET%^");
    tell_room(EETO,"%^YELLOW%^The sceptre held by "+ETOQCN+" begins to "+
      "glow with an inner light.%^RESET%^",ETO);
    return 1;
}

int extra_unwield() {
    tell_object(ETO,"%^YELLOW%^The sceptre stops glowing and seems "+
      "mundane now.%^RESET%^");
    tell_room(EETO,"%^YELLOW%^The sceptre wielded by "+ETOQCN+" "+
	"stops glowing and seems mundane now.%^RESET%^",ETO);
    return 1;
}
int extra_hit(object ob) {
    object vic;
    int dam;
    vic = ETO->query_current_attacker();
    if(!objectp(vic)) return 1;
    if(random(6) > 0) return 1;
    tell_object(ETO,"%^YELLOW%^You smite your foe with great force!");
    tell_room(EETO,"%^YELLOW%^"+ETOQCN+" smites "+vic->QCN+" with "+
      "great force!%^RESET%^",(({ETO, vic})));
    tell_object(vic,"%^YELLOW%^"+ETOQCN+" smites you with great force!");
    dam = random(6)+1;
    vic->set_paralyzed(random(3)+1,"You are still reeling from the blow!");
    return dam;
}
