#include <std.h>
inherit "/d/common/obj/weapon/mspear";

void create(){
   ::create();
   set_name("steel-tipped spear");
   set_id(({"spear","lance","lightning lance","steel spear"}));
   set_short("%^YELLOW%^Li%^WHITE%^gh%^YELLOW%^tn%^WHITE%^in%^YELLOW%^g L%^WHITE%^an%^YELLOW%^ce%^RESET%^");
   set_obvious_short("%^YELLOW%^A %^BLACK%^steel-tipped %^YELLOW%^spear%^RESET%^");
   set_long("Of rather mundane appearance, this spear consists only of a shaft of %^RED%^dark wood %^RESET%^"
"and a %^BOLD%^%^BLACK%^sharpened steel tip%^RESET%^. It is well weighted, with tiny threads of metal somehow "
"interwoven down the length of its shaft, integrated into the %^ORANGE%^knotted wood%^RESET%^. The speartip is "
"fairly unremarkable, carved into a prism that leads from four pointed corners to a sharpened tip, used for "
"impaling victims. You'd be tempted to dismiss it as fairly worthless, except for noticing the occasional tiny "
"%^YELLOW%^spa%^WHITE%^r%^YELLOW%^k %^RESET%^that arcs up its length and away from the tip, dissipating in the "
"air.");
   set_value(300);
   set_property("enchantment",3);
   set_lore("Spears such as this are a common weapon amongst the carnivorous creatures of underdark known as "
"grell. Their warriors are trained to use either these, or tiny metal tips that fit onto the ends of their "
"tentacles. The spears themselves are imbued with charges of electricity, to which the grell themselves are "
"immune, making them ideal weapons against foes that are not so invulnerable to its effects.\n");
   set_property("lore difficulty",16);
   set_wield((:TO,"wield_fun":));
   set_unwield((:TO,"unwield_fun":));
   set_hit((:TO,"hit_fun":));
}

int wield_fun() {
    if(ETO->query_lowest_level() < 18) {
      tell_object(ETO,"%^WHITE%^%^BOLD%^You don't have the skill to use such a weapon yet.%^RESET%^");
      return 0;
    }
   tell_room(EETO,"%^ORANGE%^A %^YELLOW%^crac%^WHITE%^k%^YELLOW%^le%^RESET%^%^ORANGE%^ runs up the shaft of "
"the spear as "+ETOQCN+" takes hold of it.%^RESET%^",ETO);
   tell_object(ETO,"%^ORANGE%^A %^YELLOW%^crac%^WHITE%^k%^YELLOW%^le%^RESET%^%^ORANGE%^ runs up the shaft of "
"the spear as you grip it.%^RESET%^");
   return 1;
}

int unwield_fun() {
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+" releases "+ETO->QP+" grip on the simple spear.%^RESET%^",ETO);
   tell_object(ETO,"%^ORANGE%^You release your grip on the simple spear.%^RESET%^");
   return 1;
}

int hit_fun(object targ){
    if(!objectp(TO)) return 1;
    if(!objectp(ETO)) return 1;
    if(!objectp(targ)) return 1;
    targ = ETO->query_current_attacker();

    if(random(1000) < 150){
      switch(random(65)){
        default:
        tell_room(EETO,"%^ORANGE%^A small jolt of %^YELLOW%^electricity %^RESET%^%^ORANGE%^jumps from "
+ETO->QCN+"'s spear to "+targ->QO+".%^RESET%^",({ETO,targ}));
        tell_object(ETO,"%^ORANGE%^A small jolt of %^YELLOW%^electricity %^RESET%^%^ORANGE%^jumps from "
"your spear to "+targ->QO+".%^RESET%^");
        tell_object(targ,"%^ORANGE%^A small jolt of %^YELLOW%^electricity %^RESET%^%^ORANGE%^jumps from "
+ETO->QCN+"'s spear to you.%^RESET%^");
        new("/cmds/spells/l/_lightning_orb")->use_spell(ETO,targ,20,100,"mage");
        break;
        case 60..65:
        tell_room(EETO,"%^CYAN%^A crackling charge of %^YELLOW%^ele%^WHITE%^c%^YELLOW%^tri%^WHITE%^c%^YELLOW%^"
"ity %^RESET%^%^CYAN%^runs the length of "+ETO->QCN+"'s spear, and bounces off "+targ->QCN+" in a massive "
"arc!%^RESET%^",({ETO,targ}));
        tell_object(ETO,"%^CYAN%^A crackling charge of %^YELLOW%^ele%^WHITE%^c%^YELLOW%^tri%^WHITE%^c%^YELLOW%^"
"ity %^RESET%^%^CYAN%^runs the length of "+ETO->QCN+"'s spear, and bounces off "+targ->QCN+" in a massive "
"arc!%^RESET%^");
        tell_object(targ,"%^CYAN%^A crackling charge of %^YELLOW%^ele%^WHITE%^c%^YELLOW%^tri%^WHITE%^c"
"%^YELLOW%^ity %^RESET%^%^CYAN%^runs the length of your spear, and bounces off "+targ->QCN+" in a massive "
"arc!%^RESET%^");
        new("/cmds/spells/c/_chain_lightning")->use_spell(ETO,targ,20,100,"mage");
        break;
      }
      return 1;
    }
}