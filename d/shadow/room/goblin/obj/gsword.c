//updated by Circe 6/16/04 with new desc, lore, etc by Shar
#include <std.h>

inherit "/d/common/obj/weapon/bastard";

void create() {
    ::create();
    set_name("falchion of the ursa");
    set_id(({"sword","two handed sword","bastard sword","greatblade","falchion","falchion of the ursa"}));
    set_obvious_short("a large falchion");
    set_short("%^RESET%^%^RED%^Falchion of the %^ORANGE%^Ursa%^RESET%^");
    set_long(
      "This falchion has seen better days.  The %^BOLD%^steel blade "+
      "%^RESET%^has taken many a %^RED%^beating %^RESET%^from the "+
      "%^CYAN%^weather %^RESET%^and from constant use.  The only bit "+
      "of %^BOLD%^bright metal %^RESET%^on this blade is the cutting "+
      "edge, but even that is a dull color.  The sword still seems to "+
      "carry some heft and looks as if it could do some heavy damage, "+
      "though not as much as a sharp blade.  The %^BOLD%^pommel %^RESET%^"+
      "of the blade is made from a thick %^BOLD%^thigh bone%^RESET%^ "+
      "and features a carving a %^ORANGE%^bear %^RESET%^on each side."
    );
    set_lore("The Falchion of the Ursa used to be the defining blade "+
       "from a band of rangers named the Ursa's Claws.  The rangers "+
       "were part of a band that protected the lands from the Orcs "+
       "and other goblinoid tribes years ago.  There was a brutal and "+
       "violent battle around the meadowlands area and lead all the way "+
       "up to what is now Kildare Glen, leaving the Orcs and Goblinoids "+
       "victorious.  It seems as if these goblins have managed to pilage "+
       "these swords from the rangers they and the Orcs were able to "+
       "overwhelm.  During the long years of war with the Orcs, the Ursa's "+
       "Claws worked closely with another band of rangers dedicated "+
       "to Mielikki, the Needles of the Forest.");
    set_property("lore difficulty",8);
    set_value(50);
    set_wield((: TO,"extra_wield" :));
    set_unwield((: TO,"extra_unwield" :));
    set_hit((: TO,"extra_hit" :));
}
int extra_wield() {
    tell_object(ETO,"%^RED%^You feel the primal strength of the "+
       "%^ORANGE%^bear %^RED%^surge through you!%^RESET%^");
    tell_room(EETO,"%^RED%^"+ETOQCN+" gets a fierce look in "
	""+ETO->QP+" eyes!%^RESET%^",ETO);
    return 1;
}

int extra_unwield() {
    tell_object(ETO,"%^RED%^The strength of the %^ORANGE%^bear "+
       "%^RED%^leaves you.%^RESET%^");
    tell_room(EETO,"%^RED%^"+ETOQCN+" appears to calm down.%^RESET%^",ETO);
    return 1;
}

int extra_hit(object vic) {
    int dam;
    if(!objectp(vic)) return 1;
    if(random(3)) return random(2);
    tell_object(ETO,"%^RED%^With a mighty %^BOLD%^%^WHITE%^-="+
       "%^RED%^ROAR%^WHITE%^=- %^RESET%^%^RED%^you slash "+vic->QCN+" "+
       "with your blade!%^RESET%^");
    tell_room(EETO,"%^RED%^With a mighty %^BOLD%^%^WHITE%^-="+
       "%^RED%^ROAR%^WHITE%^=- %^RESET%^%^RED%^"+ETOQCN+" slashes "+vic->QCN+" "+
       "with "+ETO->QP+" blade!%^RESET%^",({ETO, vic}));
    tell_object(vic,"%^RED%^With a mighty %^BOLD%^%^WHITE%^-="+
       "%^RED%^ROAR%^WHITE%^=- %^RESET%^%^RED%^"+ETOQCN+" slashes you "+
       "with "+ETO->QP+" blade!%^RESET%^");
    dam = random(4)+3;
    return dam;
}
