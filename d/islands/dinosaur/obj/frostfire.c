// frost fire spear, based off of ivory spear
//hades 8/10
#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit "/d/common/obj/weapon/mspear.c";

void create(){
    ::create();
    set_name("%^BOLD%^%^WHITE%^Fr%^YELLOW%^o%^WHITE%^st %^YELLOW%^Fi%^WHITE%^r%^YELLOW%^e Spear%^RESET%^");
    set_id( ({"spear", "frost fire", "frost fire spear"}) );
    set_short("%^RESET%^%^BOLD%^Sp%^YELLOW%^i%^WHITE%^ra%^YELLOW%^li%^WHITE%^ng Spear%^RESET%^");
    set_obvious_short("%^RESET%^%^BOLD%^Sp%^YELLOW%^i%^WHITE%^ra%^YELLOW%^li%^WHITE%^ng Spear%^RESET%^");
    set_long("This masterfully crafted spear "+
	"is made from a %^BOLD%^%^BLACK%^large bone%^RESET%^.  The shaft is"+
	" a dull %^BOLD%^%^BLACK%^gray%^RESET%^ with %^ORANGE%^strange etchings%^RESET%^ marking"+
	" it.   Grafted to the shaft is a forked "+
	"spearhead.  One part of the spear tip has "+
	"flickering %^BOLD%^white gem%^RESET%^, the other has a "+
	"dull %^RED%^red gem%^RESET%^.  Both are expertly placed"+
	" and look magical in nature.  %^RESET%^");
    
	
	set_lore("This spear bears similarities to the more widespread"+
	" ivory spear.  However, a crafty mage was rumored to "+
	"deconstruct the gem and add another gem, to give it "+
	"a more powerful magic.  Rumors of this mage are not "+
	"verified but stories have be told of an old man seen "+
	"doing strange experements on the dinosaur island.");
        set_property("lore",19);
        set_value(1700);
        set_hit((:TO,"hitme":));
        set_property("enchantment",3);
        set_wield((:TO,"wield_func":));
        set_unwield((:TO,"unwield_func":));
}
int wield_func(string str) {
   if((int)ETO->query_level() < 16) {
      tell_object(ETO,"%^BOLD%^%^WHITE%^The spear fades away as you"+
                " try to wield it, only to resolidify.");
        return 0;
}
        tell_object(ETO,"%^BOLD%^The spear seems cool to the touch as"+
                " you grasp the shaft.\nA %^RED%^chaotic%^RESET%^ power seems to ebb "+
                "through the spear as you wield it.");
        return 1;
}
int unwield_func(string str) {
        tell_object(ETO,"%^BOLD%^You release your hold of the bone"+
                " shaft of the spear.  %^BOLD%^%^BLACK%^A puff of smoke come off of it.");
        return 1;
}

int hitme(object targ)
{
   if(!random(8)) {
      tell_object(ETO,"%^BOLD%^%^WHITE%^You jab your spear again into "+targ->QCN+".");
      tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->QCN+" jabs "+ETO->QP+" "+
                "spear into you again!");
      tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETO->QCN+" jabs"+
        " "+ETO->QP+" spear into "+targ->QCN+" again.",({ETO,targ}));
                ETO->execute_attack();
      return 1;
   }
   if(!random(16)) {
      tell_object(ETO,"%^BOLD%^The white orb releases a burst of frost into"+
                " "+targ->QCN+", %^RED%^followed by the red orb letting out a blast of fire.");
      tell_object(targ,"%^BOLD%^The white orb inside "+ETO->QCN+"'s"+
                " releases a burst of"+
                " frost that freezes you.  %^RED%^Then the red orb lets out a blast of fire burning you.");
      tell_room(environment(ETO),"%^BOLD%^The white orb inside "+
                ""+ETO->QCN+"'s spearhead releases frost that freezes "+targ->QCN+"'s"+
                " flesh.  %^RESET%^%^RED%^The red orb lets out a blast of fire.",({ETO,targ}));
                        ETO->set_property("magic",1);
     targ->do_damage("torso",random(16)+2);
                        ETO->set_property("magic",-1);
        return 1;
   }
   if(!random(50)) {
      tell_object(ETO,"%^BOLD%^You send the orb of frost and ice "+
                        "speeding towards "+targ->QCN+
						" followed by %^RED%^fire from the red orb.");
      tell_object(targ,"%^BOLD%^"+ETO->QCN+"'s"+
                " spear sends the orb of frost and ice "+
                "speeding towards you followed by a %^RED%^sheet of flames.");
      tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+"'s"+
                " spear sends the orb of frost and ice "+
                "speeding towards "+targ->QCN+
				" followed by a %^RED%^sheet of flames!",({ETO,targ}));
                       
new("/cmds/spells/f/_frost_orb")->use_spell(ETO,targ,11,100,"mage");
new("/cmds/spells/h/_handfire")->use_spell(ETO,targ,11,100,"cleric");
        return 1;
   }

}
