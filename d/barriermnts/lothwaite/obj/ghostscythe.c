#include <std.h>
#include "../lothwaite.h"
inherit "/d/common/obj/weapon/two_hand_scythe";

int OWNED;
string owner;

void create() {
   ::create();
   set_id(({"scythe","ghost scythe","touch","ghost touch","ghost touch scythe"}));
   set_name("%^BOLD%^%^WHITE%^Ghost %^CYAN%^Touch%^RESET%^");
   set_obvious_short("%^RESET%^a %^BOLD%^ghostly%^RESET%^ white scythe");
   set_short("%^BOLD%^%^WHITE%^Ghost %^CYAN%^Touch%^RESET%^");
   set_long(
      "%^BOLD%^%^WHITE%^This smooth white scythe is made of no "+
      "material you've ever seen.  It is completely smooth and "+
      "almost soft to the touch, though the wicked gleam from "+
      "the blade suggests it would still do its job well.  "+
      "Once used to cut wheat, this scythe is now a deadly "+
      "weapon."
   );
   set_lore(
      "The ghost touch scythes are taken from the hands of "+
      "ghostly farmers who have lost their lives.  Marked "+
      "by a strange ethrealness, it is said that these "+
      "weapons are no longer wholly of this plane."
   );
   set_property("lore difficulty",12);
   set_value(900);
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_hit((: TO,"extra_hit" :));
   set_property("enchantment",random(3)+2);
}

void init()
{
        ::init();
        if(!interactive(ETO)) return;
        if(interactive(TP) && TP == environment(TO) && !OWNED) {
                owner = TPQN;
                OWNED = 1;
        }
}

int wield_func(string str) {
    int align;
   if((string)ETO->query_name() == "firbolg ghost") return 1;
    align = ETO->query_alignment();
    if((int)ETO->query_level() < 20) {
        tell_object(ETO,"The ghostly weapon burns your hands.  "+
           "You are too weak for such a weapon!");
        return 0;
    }
    switch(align) {
		case 3: case 6: case 9:
			tell_object(ETO,"%^BOLD%^%^BLACK%^The scythe darkens "+
                     "to a glossy black as it conforms to your hands and "+
                     "you feel a strange strength coursing through you.");
			tell_room(EETO,"%^BOLD%^%^BLACK%^The scythe "+
                     "shimmers and fades to a glossy black as "+ETOQCN+" "+
                     "wields it.",ETO);
                  TO->set_long("%^BOLD%^%^BLACK%^This scythe is made "+
                     "of an unknown material the glossy black color "+
                     "of the abyss.  The scythe is completely smooth "+
                     "and seems almost soft to the touch, conforming "+
                     "to the wielder's hands.  Despite its resemblance "+
                     "to other such tools, it is clear that this scythe "+
                     "has sliced more necks than grain.%^RESET%^");
   set_item_bonus("attack bonus",2);
   set_item_bonus("damage bonus",1);
   set_item_bonus("magic resistance",0);
			return 1;

		case 2: case 5: case 8:
			tell_object(ETO,"%^CYAN%^An unexpected sense of strength fills "+
                     "you as you wield the scythe.");
			tell_room(EETO,"%^CYAN%^"+ETOQCN+"'s face "+
                     "looks resolute as "+ETO->QS+" wields the scythe.",ETO);
   set_item_bonus("attack bonus",0);
   set_item_bonus("damage bonus",1);
   set_item_bonus("magic resistance",0);
                  return 1;

		case 1: case 4: case 7:
			tell_object(ETO,"%^BOLD%^A strange sense of loss runs "+
                     "through you as you heft the scythe with a sickening feeling.");
			tell_room(EETO,"%^BOLD%^"+ETOQCN+" hefts the scythe with "+
			"a grim look of determination.",ETO);
   set_item_bonus("attack bonus",0);
   set_item_bonus("damage bonus",0);
   set_item_bonus("magic resistance",-1);
			return 1;
	}
}


int unwield_func()
{
    int align;
    align = ETO->query_alignment();
    switch(align) {
		case 3: case 6: case 9:
			tell_object(ETO,"The scythe fades to pale white and "+
                     "you feel a sense of weakness.");
			tell_room(EETO,"The scythe fades and pales as "+ETOQCN+" "+
                     "unwields it.",ETO);
                  TO->set_long("%^BOLD%^%^WHITE%^This smooth white "+
                     "scythe is made of no material you've ever seen.  "+
                     "It is completely smooth and almost soft to the "+
                     "touch, though the wicked gleam from the blade "+
                     "suggests it would still do its job well.  "+
                     "Once used to cut wheat, this scythe is now a "+
                     "deadly weapon."
                  );
			return 1;

		case 2: case 5: case 8:
			tell_object(ETO,"You set aside the scythe and feel more "+
                     "vulnerable.");
			tell_room(EETO,""+ETOQCN+" looks worried as "+ETO->QS+" "+
                     "unwields the scythe.",ETO);
                  return 1;

		case 1: case 4: case 7:
			tell_object(ETO,"The sense of loss fades as "+
                     "you lower the scythe and it fades to dull white.");
			tell_room(EETO,""+ETOQCN+" lowers the scythe and "+
                     "watches it fade to dull white with a look of relief.",ETO);
			return 1;
	}
}
int extra_hit(object vic) {
    if(!objectp(TO)) return 1;
    if(!objectp(ETO)) return 1;
    if(!objectp(vic)) return 1;
    if(!random(8)) {
       switch(random(50)){
          case 0..35:  tell_object(ETO,"%^CYAN%^You slash "+vic->QCN+" "+
                          "across the chest as you hear a %^BOLD%^ghastly "+
                          "wail%^RESET%^%^CYAN%^!");
                       tell_object(vic,"%^CYAN%^"+ETOQCN+" slashes you viciously "+
                          "across the chest as a %^BOLD%^ghastly wail %^RESET%^"+
                          "%^CYAN%^fills your ears!");
                       tell_room(EETO,"%^CYAN%^A %^BOLD%^deathly wail %^RESET%^"+
                          "%^CYAN%^fills the area as "+
                          ""+ETOQCN+" slashes "+vic->QCN+"'s chest open!", ({ETO,vic}));
                       vic->do_damage("torso",random(15)+8);
                       break;
          case 36..48: tell_object(ETO,"%^BOLD%^%^BLACK%^A sudden anger "+
                          "rises in you as you pierce "+vic->QCN+" savagely "+
                          "with your scythe!");
                       tell_object(vic,"%^BOLD%^%^BLACK%^A look of %^RED%^"+
                          "madness %^BLACK%^fills "+ETOQCN+"'s eyes as "+
                          ""+ETO->QS+" stabs you with the scythe!");
                       tell_room(EETO,"%^BOLD%^%^BLACK%^A look of pure "+
                          "%^RED%^madness %^BLACK%^fills "+ETOQCN+"'s eyes "+
                          "as "+ETO->QS+" stabs "+vic->QCN+" with the scythe!",({ETO,vic}));
                       vic->do_damage("torso",random(25)+20);
                       break;
           case 49:  if(!(int)vic->query_stats("constitution") > random(25)){
                       tell_object(ETO,"%^BOLD%^%^RED%^With a rising "+
                          "malevolence, you sever "+vic->QCN+"'s head "+
                          "from his body!");
                       tell_object(vic,"%^BOLD%^%^RED%^With horror, you "+
                          "see "+ETOQCN+"'s visage fade away, replaced "+
                          "by an image of %^WHITE%^death%^RED%^!");
                       tell_room(EETO,"%^BOLD%^%^RED%^For a brief instant, "+
                          "you see an image of %^WHITE%^death %^RED%^as "+
                          ""+ETOQCN+" severs "+vic->QCN+"'s head!",({ETO,vic}));
                       vic->set_hp(-1000);
                     }else{
                       tell_object(ETO,"%^RED%^You take a vicious slash "+
                          "at "+vic->QCN+", nearly beheading "+vic->QO+"!");
                       tell_object(vic,"%^RED%^You barely move in time to "+
                          "avoid being beheaded by "+ETOQCN+"'s scythe!  "+
                          "%^BOLD%^Blood pours everywhere!");
                       tell_room(EETO,"%^RED%^"+ETOQCN+" swings viciously "+
                          "at "+vic->QCN+", who moves just in time to avoid "+
                          "being beheaded!",({ETO,vic}));
                       vic->do_damage("torso",random(75)+75);
                     }
                     break;
           default:  break;
       }
    }
}
