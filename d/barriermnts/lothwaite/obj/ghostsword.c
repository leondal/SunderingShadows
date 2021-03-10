//added id of "frostbrand" in response to typo report. ~Circe~ 1/2/2013

#include <std.h>
#include "../lothwaite.h"
inherit "/d/common/obj/weapon/two_hand_sword";

int OWNED;
string owner;

int frostbite;

void create() {
   ::create();
   set_id(({"sword","two handed sword","greatsword","frost brand","frostbrand","Frostbrand"}));
   set_name("Frostbrand");
   set_obvious_short("a shimmering white greatsword");
   set_short("%^BOLD%^%^BLUE%^F%^CYAN%^r%^WHITE%^o%^CYAN%^s%^BLUE%^t"+
      "%^CYAN%^b%^WHITE%^r%^CYAN%^a%^BLUE%^n%^CYAN%^d%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^This large sword has a broad blade sharpened "+
      "on both edges.  At first glance, the blade looks to be made of "+
      "some sort of crystal, but upon closer inspection, you see small "+
      "beads of condensation.  The blade is bitterly cold, and you "+
      "realize it is in fact made of %^CYAN%^ice%^WHITE%^!  The hilt "+
      "of the sword is a str%^BLUE%^i%^WHITE%^at%^CYAN%^ed %^CYAN%^"+
      "platinum %^WHITE%^that compliments the ice well.  The crossbar "+
      "is fitted with stylized %^CYAN%^snowflakes %^WHITE%^carved "+
      "from %^BLUE%^sapp%^CYAN%^h%^BLUE%^ires%^WHITE%^, and the "+
      "pommel has been set with a large, round %^BLUE%^st%^WHITE%^a"+
      "%^BLUE%^r sapp%^CYAN%^h%^BLUE%^ire%^WHITE%^.  A message "+
      "seems to swirl within the ice.%^RESET%^"
   );
   set_lore(
      "This sword was once wielded by the greatest king of Lothwaite, "+
      "Celyddon, in the year 342 SG.  In that year, hordes of hill "+
      "giants poured down out of the upper reaches of the Barrier "+
      "Mountains as Auril plagued the realms with the worst winter "+
      "to ever take place.  Unable to survive in the extreme "+
      "temperatures at the higher altitudes, the hill giants decided "+
      "to invade the lands controlled by the firbolgs, burning all "+
      "in sight.  Not one "+
      "to be so easily ousted, a simple warrior named Celyddon took "+
      "up the defense of the city, besting the hill giants and "+
      "becoming king in the process."
   );
   set_property("lore difficulty",20);
   set_read(
@CIRCE

  %^BOLD%^%^WHITE%^>%^CYAN%^@%^WHITE%^< %^CYAN%^Ice %^WHITE%^may burn with %^RED%^heat %^WHITE%^of %^RED%^f%^YELLOW%^i%^RED%^re %^WHITE%^>%^CYAN%^@%^WHITE%^<
%^WHITE%^>%^CYAN%^@%^WHITE%^< And %^BLUE%^melt %^WHITE%^a foe with %^RED%^smol%^YELLOW%^d%^RED%^er%^YELLOW%^i%^RED%^ng %^CYAN%^ire %^WHITE%^>%^CYAN%^@%^WHITE%^<

CIRCE
   );
   set_value(1900);
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_hit((: TO,"extra_hit" :));
   set_property("enchantment",4);
   set_item_bonus("damage bonus",2);
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
   if((int)ETO->query_level() < 20) {
       tell_object(ETO,"The ghostly weapon freezes your hands.  "+
          "You are too weak for such a weapon!");
       return 0;
   }
   tell_object(ETO,"%^BOLD%^You feel the strength of the cold seep "+
      "into your hand as you wield the sword.");
   tell_room(EETO,"%^BOLD%^"+ETOQCN+" exhales a cloud of ice crystals "+
      "as "+ETO->QS+" wields the sword.",ETO);
   return 1;
}

int unwield_func()
{
   tell_object(ETO,"%^BOLD%^You peel your hand from the blade "+
      "and warmth immediately seeps in.");
   tell_room(EETO,"%^BOLD%^"+ETOQCN+" shivers slightly as "+ETO->QS+" "+
      "unwields the blade.",ETO);
   return 1;
}

int extra_hit(object vic) {
    if(!objectp(TO)) return 1;
    if(!objectp(ETO)) return 1;
    if(!objectp(vic)) return 1;
    if(!random(8)) {
       switch(random(55)){
          case 0..19:  tell_object(ETO,"%^CYAN%^The sword vibrates in "+
                          "your hands as you feel a %^BOLD%^%^WHITE%^"+
                          "frigid wind %^RESET%^%^CYAN%^pick up around "+
                          "you, sending a blast of %^BOLD%^%^WHITE%^"+
                          "frost %^RESET%^%^CYAN%^at "+vic->QCN+"!");
                       tell_object(vic,"%^CYAN%^A %^BOLD%^%^WHITE%^"+
                          "frigid wind %^RESET%^%^CYAN%^rises as a "+
                          "blast of %^BOLD%^%^WHITE%^frost %^RESET%^"+
                          "%^CYAN%^bursts into you from "+ETOQCN+"'s sword!");
                       tell_room(EETO,"%^CYAN%^A %^BOLD%^%^WHITE%^"+
                          "frigid wind %^RESET%^%^CYAN%^sweeps over "+
                          "you as "+vic->QCN+" is frozen by a %^BOLD%^"+
                          "%^WHITE%^frosty blast %^RESET%^%^CYAN%^"+
                          "from "+ETOQCN+"'s sword!", ({ETO,vic}));
                       vic->cause_typed_damage(vic,0,roll_dice(1,10)+7,"cold");            
                       break;
          case 20..29: tell_object(ETO,"%^BOLD%^%^CYAN%^A cool breeze "+
                          "rises, leaving you feeling refreshed.");
                       tell_room(EETO,"%^BOLD%^%^CYAN%^A cool breeze "+
                          "blows through the area, leaving "+ETOQCN+" "+
                          "looking refreshed.",ETO);
                       set_property("magic",1);
                       ETO->do_damage("torso",-1*(random(8)+6));
                       set_property("magic",-1);
                       break;
          case 30..39: 
                       tell_object(ETO,"%^BOLD%^As you strike "+
                          ""+vic->QCN+", a thick layer of ice "+
                          "forms over "+vic->QO+", freezing "+vic->QO+" "+
                          "in place!\n%^CYAN%^You strike quickly before "+
                          ""+vic->QS+" can react!!"); 
                       tell_object(vic,"%^BOLD%^An icy prison forms over "+
                          "your skin, binding you in place as "+ETOQCN+" "+
                          "strikes you quickly!");
                       tell_room(EETO,"%^BOLD%^A thick layer of bluish "+
                          "ice forms on "+vic->QCN+"'s skin as "+
                          ""+ETOQCN+" strikes "+vic->QO+" quickly!",({ETO,vic}));
                       ETO->execute_attack();
                       ETO->execute_attack();
                     break;
          case 40..47:  tell_object(ETO,"%^RESET%^%^CYAN%^You %^BOLD%^"+
                           "%^WHITE%^cleave %^RESET%^%^CYAN%^your "+
                           "sword into "+vic->QCN+", causing steam to "+
                           "rise from the wound!");
                        tell_object(vic,"%^RESET%^%^CYAN%^You gasp "+
                           "as "+ETOQCN+"'s icy sword %^BOLD%^%^WHITE%^"+
                           "cleaves %^RESET%^%^CYAN%^into you, leaving "+
                           "%^BOLD%^%^WHITE%^frostbite %^RESET%^"+
                           "%^CYAN%^in the wound!");
                        tell_room(EETO,"%^RESET%^%^CYAN%^Steam rises "+
                           "in the air as "+ETOQCN+" %^BOLD%^"+
                           "%^WHITE%^cleaves %^RESET%^%^CYAN%^"+
                           ""+vic->QCN+" with "+ETO->QP+" icy "+
                           "sword!",({ETO,vic}));
                       vic->cause_typed_damage(vic,0,roll_dice(1,16)+8,"cold");  
                       call_out("frostbite",7,vic);
                       break;
          case 48..54:  tell_object(ETO,"%^BOLD%^%^BLUE%^You feel "+
                           "the strength of the sword take over as "+
                           "you send forth ice from your fingertips!");
                        tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETOQCN+" "+
                           "begins to chant, holding "+ETO->QP+" "+
                           "sword in front of "+ETO->QO+"!",ETO);
                        new("/cmds/spells/f/_frost_breath")->use_spell(ETO,vic,15,100,"druid");
                        //cleric can't cast frost breath -H
                        break;
          default:  break;
       }
    return random(6);
    }
}

int frostbite(object vic){
   if(!objectp(vic)) return 1;
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   tell_object(vic,"%^BOLD%^Frostbite scalds your flesh!");
   vic->cause_typed_damage(vic,0,roll_dice(1,10)+7,"cold");  
   return 1;
}
