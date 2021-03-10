//bow for Aislinn to drop ~Circe~ 9/29/19

#include <std.h>
#include "../defs.h"
inherit "/d/common/obj/lrweapon/longbow";

void create(){
   ::create();
   set_name("longbow");
   set_id(({"bow","longbow","dream bow","prismatic bow","rainbow's end","rainbows end"}));
   set_obvious_short("%^CYAN%^p%^BLUE%^r%^GREEN%^i%^YELLOW%^s%^RED%^m%^MAGENTA%^a%^CYAN%^t%^BLUE%^i%^GREEN%^c %^CYAN%^bow%^RESET%^");
   set_short("%^RESET%^%^RED%^R%^ORANGE%^a%^YELLOW%^i%^GREEN%^n%^CYAN%^b%^RESET%^%^CYAN%^o%^BOLD%^%^BLUE%^w%^MAGENTA%^'%^RESET%^%^MAGENTA%^s %^BOLD%^%^WHITE%^End%^RESET%^");
   set_long("%^RESET%^%^CYAN%^This unique bow is crafted from a single curve of %^BOLD%^%^CYAN%^crystal %^BOLD%^%^CYAN%^v%^RESET%^e%^MAGENTA%^i%^BOLD%^%^BLUE%^n%^CYAN%^e%^WHITE%^d %^RESET%^%^CYAN%^with %^BOLD%^%^BLUE%^cobalt%^RESET%^%^CYAN%^, %^BOLD%^%^MAGENTA%^amethyst%^RESET%^%^CYAN%^, and %^RESET%^clear calcite%^CYAN%^.  %^YELLOW%^Energy %^RESET%^%^CYAN%^crackles along the length, sending shifting %^BOLD%^%^CYAN%^p%^BLUE%^r%^GREEN%^i%^YELLOW%^s%^RED%^m%^MAGENTA%^a%^CYAN%^t%^BLUE%^i%^GREEN%^c %^RESET%^%^CYAN%^patterns of light into the air. From certain angles, the bow seems to have no string until %^YELLOW%^light %^RESET%^%^CYAN%^dances upon it, revealing a %^RESET%^s%^BOLD%^h%^RESET%^i%^BOLD%^m%^RESET%^m%^BOLD%^e%^RESET%^r%^BOLD%^i%^RESET%^n%^BOLD%^g %^RESET%^s%^BOLD%^i%^CYAN%^l%^WHITE%^v%^RESET%^e%^BOLD%^r %^RESET%^%^CYAN%^string so delicate it might be %^BOLD%^illusory %^RESET%^%^CYAN%^after all.  The longbow features fanciful curves at each end that shift and dissolve into %^BOLD%^tendrils %^RESET%^%^CYAN%^of %^RESET%^smoke%^CYAN%^ that form fanciful shapes - a %^MAGENTA%^dragon's whi%^BOLD%^s%^RESET%^%^MAGENTA%^ke%^BOLD%^r%^RESET%^%^MAGENTA%^s%^CYAN%^, a gout of %^RED%^fl%^BOLD%^a%^YELLOW%^m%^RESET%^%^RED%^e%^CYAN%^, a %^BOLD%^cloud %^RESET%^%^CYAN%^drifting on the wind.  The exquisite craftsmanship might make one wonder if this bow were not crafted at all but dreamed into existence.%^RESET%^");
   set_lore("The bow known as Rainbow's End is made of lucindaris, a crystal that draws upon the powers of all the elements and is nearly impossible to shape as it clings stubbornly to its natural form. The string, meanwhile, is the subject of some debate. Many claim it is an illusion, but that seems illogical as the arrows it fires are without a doubt from the Prime Material Plane and are quite solid in a very physical sense. For my part, I am certain the bow is the stuff of dreams themselves, manifested through a great will. - Matylin the Wise, 'An Account of the Dream Realm'");
   set_item_bonus("attack bonus",2);
   set_item_bonus("damage bonus",2);
   set_value(3000);
   set_property("enchantment",4);
   while((int)TO->query_property("enchantment") != 4){
      TO->remove_property("enchantment");
      TO->set_property("enchantment",4);
   }
   set_wield((:TO,"wieldme":));
   set_unwield((:TO,"unwieldme":));
   set_lrhit((:TO,"extra_lrhit":));
}

int wieldme(){
   string mygod = ETO->query_diety();
   if(member_array("%^BOLD%^%^CYAN%^Lucid Dreams%^RESET%^",ETO->query_mini_quests())== -1) {
      tell_object(ETO,"You have not earned the right to make use of this item.");
      return 0;
   }
   switch(mygod){
      case "lysara":
         tell_object(ETO,"%^BOLD%^A bright %^CYAN%^silvery light %^WHITE%^flashes along the bow as you heft it.  You sense that the moon will help you find your path.%^RESET%^");
         tell_room(EETO,"%^BOLD%^The bow held by "+ETOQCN+" flares with a %^CYAN%^silvery light %^WHITE%^as "+ETO->QS+" wields it.%^RESET%^",ETO);
         break;
      case "kismet":
         tell_object(ETO,"%^GREEN%^A bright %^BOLD%^peridot light %^RESET%^%^GREEN%^flashes along the bow as you heft it.  You sense an ancient magic fill you.%^RESET%^");
         tell_room(EETO,"%^GREEN%^The bow held by "+ETOQCN+" flares with a %^BOLD%^green light %^RESET%^%^GREEN%^as "+ETO->QS+" wields it.%^RESET%^",ETO);
         break;
      case "the faceless one":
         tell_object(ETO,"%^BOLD%^%^BLACK%^A dark %^RESET%^sm%^BOLD%^%^BLACK%^o%^RESET%^ke%^BOLD%^%^BLACK%^y %^RESET%^li%^BOLD%^%^BLACK%^g%^RESET%^ht %^BOLD%^%^BLACK%^flashes along the bow as you heft it.  You sense the power of deception fill you.%^RESET%^");
         tell_room(EETO,"%^BOLD%^%^BLACK%^The bow held by "+ETOQCN+" darkens with a %^RESET%^sm%^BOLD%^%^BLACK%^o%^RESET%^ke%^BOLD%^%^BLACK%^y %^RESET%^li%^BOLD%^%^BLACK%^g%^RESET%^ht %^BOLD%^%^BLACK%^as "+ETO->QS+" wields it.%^RESET%^",ETO);
         break;
      default:
         tell_object(ETO,"%^RESET%^%^CYAN%^The bow flashes with %^BOLD%^%^CYAN%^p%^BLUE%^r%^GREEN%^i%^YELLOW%^s%^RED%^m%^MAGENTA%^a%^CYAN%^t%^BLUE%^i%^GREEN%^c %^RESET%^%^CYAN%^light as you wield it.%^RESET%^");
         tell_room(EETO,"%^RESET%^%^CYAN%^The bow flashes with %^BOLD%^%^CYAN%^p%^BLUE%^r%^GREEN%^i%^YELLOW%^s%^RED%^m%^MAGENTA%^a%^CYAN%^t%^BLUE%^i%^GREEN%^c %^RESET%^%^CYAN%^light as "+ETOQCN+" wields it.%^RESET%^",ETO);
         break;
   }
   set_critical_threat_range(2);
   return 1;
}

int unwieldme(){
   tell_object(ETO,"%^RESET%^%^CYAN%^The %^RESET%^s%^BOLD%^h%^RESET%^i%^BOLD%^m%^RESET%^m%^BOLD%^e%^RESET%^r%^BOLD%^i%^RESET%^n%^BOLD%^g %^RESET%^s%^BOLD%^i%^CYAN%^l%^WHITE%^v%^RESET%^e%^BOLD%^r %^RESET%^%^CYAN%^string seems to wink out of existence and the %^BOLD%^c%^BOLD%^o%^GREEN%^l%^YELLOW%^o%^RED%^r%^MAGENTA%^s %^RESET%^%^CYAN%^fade as you lower the bow.%^RESET%^");
   tell_room(EETO,"%^RESET%^%^CYAN%^The %^BOLD%^%^CYAN%^p%^BLUE%^r%^GREEN%^i%^YELLOW%^s%^RED%^m%^MAGENTA%^a%^CYAN%^t%^BLUE%^i%^GREEN%^c %^RESET%^%^CYAN%^light %^RESET%^%^CYAN%^of "+ETOQCN+"'s bow dims as "+ETO->QS+" lowers it.%^RESET%^",ETO);
   set_critical_threat_range(1);
   return 1;
}

int extra_lrhit(object targ){
   int rand, i;
   object *myfoes;

   rand = roll_dice(1,10);
   if(!objectp(ETO)) return 0;
   if(!objectp(EETO)) return 0;
   targ = ETO->query_current_attacker();
   if(!objectp(targ)) return 0;
   if(random(1000) < 400){
      switch(random(10)){
         case 0..3:
            tell_object(ETO,"%^RESET%^%^ORANGE%^The bow grows warm in your hand before brilliant %^YELLOW%^fi%^RED%^e%^WHITE%^r%^YELLOW%^y light %^RESET%^%^ORANGE%^bursts forth, streaking toward "+targ->QCN+"!%^RESET%^");
            tell_object(targ,"%^RESET%^%^ORANGE%^Brilliant %^YELLOW%^fi%^RED%^e%^WHITE%^r%^YELLOW%^y light %^RESET%^%^ORANGE%^bursts forth from "+ETOQCN+"'s bow, streaking toward you!%^RESET%^");
            tell_room(EETO,"%^RESET%^%^ORANGE%^Brilliant %^YELLOW%^fi%^RED%^e%^WHITE%^r%^YELLOW%^y light %^RESET%^%^ORANGE%^bursts forth from "+ETOQCN+"'s bow, streaking toward "+targ->QCN+"!%^RESET%^",({ETO,targ}));
            ETO->set_property("magic",1);
            targ->do_damage((string)targ->return_target_limb(),roll_dice(3,6));
            ETO->set_property("magic",-1);
            myfoes = ETO->query_attackers();
            myfoes -= ({targ});
            if(sizeof(myfoes)){
               for(i=0;i<sizeof(myfoes);i++){
                  if(!"daemon/saving_throw_d"->reflex_save(myfoes[i],-25) && !"daemon/feat_d"->usable_feat(myfoes[i],"evasion")){
                     tell_object(myfoes[i],"%^YELLOW%^The %^YELLOW%^fi%^RED%^e%^WHITE%^r%^YELLOW%^y light singes you!%^RESET%^");
                     tell_room(EETO,"%^BOLD%^%^YELLOW%^"+myfoes[i]->QCN+" is singed by the %^YELLOW%^fi%^RED%^e%^WHITE%^r%^YELLOW%^y light!%^RESET%^",myfoes[i]);
                     myfoes[i]->do_damage("torso",roll_dice(2,10));          
                  }
               }
            }
            break;
         case 4..6:
            tell_object(ETO,"%^RESET%^%^CYAN%^Wind whips through the area, guiding your hand as you rapidly fire another arrow!%^RESET%^");
            tell_room(EETO,"%^RESET%^%^CYAN%^Wind whips through the area, granting "+ETOQCN+" speed as "+ETO->QS+" fires an arrow more quickly than seems possible!%^RESET%^",({ETO,targ}));
            ETO->execute_attack();
            break;
         case 7..8:
            tell_object(ETO,"%^RESET%^%^GREEN%^Your bow glows with a sickly %^BOLD%^green light %^RESET%^%^GREEN%^as you take aim at "+targ->QCN+"!%^RESET%^");
            tell_object(targ,"%^RESET%^%^GREEN%^"+ETOQCN+"'s bow glows with a sickly %^BOLD%^green light %^RESET%^%^GREEN%^as "+ETO->QS+" fires an arrow that strikes you!%^RESET%^");
            tell_room(EETO,"%^RESET%^%^GREEN%^"+ETOQCN+"'s bow glows with a sickly %^BOLD%^green light %^RESET%^%^GREEN%^as "+ETO->QS+" fires an arrow at "+targ->QCN+"!%^RESET%^",({ETO,targ}));
            targ->do_damage("torso",roll_dice(3,10));
            tell_object(targ,"%^BOLD%^%^GREEN%^Acid sears your skin!%^RESET%^");
            new(OBJ"dreambow-dot")->move(targ);
            break;
         default:
            tell_object(ETO,"%^RESET%^%^CYAN%^The %^BOLD%^cool blues %^RESET%^%^CYAN%^of the bow brighten to %^BOLD%^%^WHITE%^blinding intensity %^RESET%^%^CYAN%^as cold seeps into your palms.\n%^BOLD%^%^CYAN%^You let fly an ice arrow straight at "+targ->QCN+"!%^RESET%^");
            tell_object(targ,"%^RESET%^%^CYAN%^"+ETOQCN+"'s bow glows with %^BOLD%^%^WHITE%^blinding light%^RESET%^%^CYAN%^ as "+ETO->QS+" takes aim at you!%^RESET%^");
            tell_room(EETO,"%^RESET%^%^CYAN%^"+ETOQCN+"'s bow glows with %^BOLD%^%^WHITE%^blinding light%^RESET%^%^CYAN%^ as "+ETO->QS+" takes aim at "+targ->QCN+"!%^RESET%^",({ETO,targ}));
            if(!random(2)){
               targ->set_paralyzed(roll_dice(2,5),"You are frozen by the chill of the ice arrow!");
               tell_room(EETO,"%^BOLD%^%^WHITE%^"+targ->QCN+" is frozen in place!%^RESET%^",targ);
            }else{
               tell_object(targ,"%^BOLD%^%^WHITE%^You feel an intense chill from "+ETOQCN+"'s arrow but shake it off!%^RESET%^");
               tell_room(EETO,"%^BOLD%^%^WHITE%^"+targ->QCN+" shivers but shakes off a chill!%^RESET%^",targ);
            }
            tell_object(ETO,"%^BOLD%^%^WHITE%^A wave of %^CYAN%^cool energy %^WHITE%^rolls over you, healing some of your wounds.%^RESET%^");
            ETO->set_property("magic",1);
            ETO->do_damage("torso",roll_dice(8,8)*(-1));
            TO->set_property("magic",-1);
            break;
      }
   }
}