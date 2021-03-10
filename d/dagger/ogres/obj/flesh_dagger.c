//updated to remove references to old gods ~Circe~ 8/17/19
//Tears of the Lost - LoKi 05-23-08
#include <std.h>

inherit "/d/common/obj/weapon/knife.c";

int unwield_knife();
int wield_knife();
int hit_stuff(object ob);
void set_unwield_state();

void create(){
   ::create();
   set_name("tears of the lost");
   set_id(({"dagger","tears of the lost","liquid dagger","weapon", "tear", "mass", "mass of flesh"}));
   set_short("%^RESET%^%^ORANGE%^ma%^RESET%^%^RED%^s%^RESET%^%^ORANGE%^s of f%^RESET%^%^RED%^l%^RESET%^%^ORANGE%^esh%^RESET%^");
   set_unwield_state();
   set_wield((:TO, "wield_knife":));          
   set_unwield((:TO, "unwield_knife":));  
   set_property("enchantment", 4);
   set_hit((:TO, "hit_stuff":));
   set_lore("%^BLACK%^%^BOLD%^Few items, either planar or native, have touched me with the ill I felt at my research into the Tears. Created by a fallen archmage of Kreysneothosies, the dagger was the final act of depravity in an attempt to gain the favor of the Faceless One. A hundred children lost their lives and souls to the dagger's creation, and it is obvious to my divinations that the children are still trapped. Most alarming is the fact that more then one of these have been recovered, meaning the archmage is still at large. Fourteen crusades have been waged to rid the world of these daggers and to find the creator, a woman by the name of Serah Kavall. Lord help us if we cannot find her soon.\n\nArchivist Patak, submitted to the Council for the Inquisition of Heretics.%^RESET%^");

}

string query_short(){
   int flag;
   if(objectp(TO) && objectp(ETO)){
      if(!interactive(ETO) || (interactive(ETO)&& member_array(TO,ETO->query_wielded(),flag)==-1)){
         set_unwield_state();
      }
   }
   return ::query_short();    
}

int hit_stuff(object ob){ 
   int dam;
   if (!objectp(TO)||!objectp(ETO)||!objectp(ob)){return 0;}
   if (random(14)<5){
      return 0;
   }
   switch(random(9)){
      case 0..4: tell_object(ETO, "%^RESET%^%^CYAN%^Your "+query_name() + " dagger cuts deeply into " +(string)ob->QCN+"'s %^RESET%^%^CYAN%^skin!");
                 tell_object(ob, (string)ETO->QCN + "'s %^CYAN%^" + query_name()+"%^RESET%^%^CYAN%^ cuts deeply into your skin!");
                 tell_room(EETO, (string)ETO->QCN + "'s %^CYAN%^" + query_name()+"%^RESET%^%^CYAN%^ cuts deeply into " + (string)ob->QCN+" %^RESET%^%^CYAN%^!",({ob,ETO}));
                 set_property("magic",1);
                 ob->do_damage(ob->query_limb(),10 + random(10));
                 remove_property("magic");
                 break;
                 return 0;
      default: tell_object(ETO, "%^RED%^%^BOLD%^The "+ query_name() + "%^RED%^%^BOLD%^ starts to shake in your hand!");
                 tell_object(ob, (string)ETO->QCN +"'s %^RED%^%^BOLD%^dagger starts to shake. You are overcome with a feeling of loss!");
                 tell_room(EETO, (string)ETO->QCN +"'s %^RED%^%^BOLD%^dagger starts to shake!", ({ob,ETO}) );
                 set_property("magic",1);
                 ob->do_damage(ob->query_limb(),5 + random(15));
                 remove_property("magic");
                 break;
                return 0;
   }
}


int wield_knife(){
   if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return 0;}
   tell_object(ETO,"%^RESET%^%^ORANGE%^As you wrap your hand around the mass of flesh, you feel %^RESET%^%^CYAN%^warm liquid %^RESET%^%^ORANGE%^flow through your fingers. The liquid slowly forms into the perfect shape of a dagger.%^RESET%^");
   tell_room(EETO,"%^RESET%^%^ORANGE%^As " + (string)ETO->QCN + " %^RESET%^%^ORANGE%^grasps the mass of flesh, you hear a soft squishing sound as a %^RESET%^%^CYAN%^liquid blade%^RESET%^%^ORANGE%^ flows out.%^RESET%^",ETO);
   set_short("%^RESET%^%^ORANGE%^Te%^RESET%^%^RED%^a%^RESET%^%^ORANGE%^rs of t%^RESET%^%^RED%^h%^RESET%^%^ORANGE%^e Lo%^RESET%^%^RED%^s%^RESET%^
%^ORANGE%^t%^RESET%^");
   set_obvious_short("%^RESET%^%^CYAN%^liq%^RESET%^%^WHITE%^u%^RESET%^%^CYAN%^id d%^RESET%^%^BOLD%^%^CYAN%^a%^RESET%^%^CYAN%^gger%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^Formed from a lump of flesh, the grotesque hilt of this dagger writhes and pulsates. Several %^RESET%^%^BOLD%^%^WHITE%^eyeballs %^RESET%^%^ORANGE%^of different colors seem to be in a constant state of crying, the %^RESET%^%^CYAN%^tears %^RESET%^%^ORANGE%^forming into a %^RESET%^%^CYAN%^liq%^RESET%^%^BOLD%^%^CYAN%^u%^RESET%^%^CYAN%^id b%^RESET%^%^BOLD%^%^CYAN%^l%^RESET%^%^CYAN%^ade %^RESET%^%^ORANGE%^that flows out into a point. A sense of supreme %^RESET%^%^BOLD%^%^BLACK%^loss %^RESET%^%^ORANGE%^flows over you as you watch this blade.%^RESET%^");
   return 1;
}

void __ActuallyUnwield() {
   ::__ActuallyUnwield();
   set_unwield_state();
}

int unwield_knife(){
   if (!objectp(TO)||!objectp(ETO)||!objectp(EETO)){return 0;}
   tell_object(ETO, "%^RESET%^%^ORANGE%^As you release the mass of flesh, the blade of tears falls to the ground, leaving behind a stump of flesh. %^RESET%^");
   tell_room(EETO, "%^RESET%^%^ORANGE%^As "+(string)ETO->QCN+"%^RESET%^%^ORANGE%^ releases the dagger, the liquid falls, leaving behind a stump of flesh.%^RESET%^", ETO);
   set_unwield_state();
   return 1;
}

void set_unwield_state(){
   set_short("%^RESET%^%^ORANGE%^ma%^RESET%^%^RED%^s%^RESET%^%^ORANGE%^s of f%^RESET%^%^RED%^l%^RESET%^%^ORANGE%^esh%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^ma%^RESET%^%^RED%^s%^RESET%^%^ORANGE%^s of f%^RESET%^%^RED%^l%^RESET%^%^ORANGE%^esh%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^Formed from a lump of flesh, this grotesque creation writhes and pulsates. Several %^RESET%^%^BOLD%^%^WHITE%^eyeballs %^RESET%^%^ORANGE%^of different colors blink chaotically and stare out with obvious alarm. A large %^RESET%^%^BOLD%^%^BLACK%^blac%^RESET%^%^WHITE%^k%^RESET%^%^BOLD%^%^BLACK%^ di%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^%^BLACK%^mond %^RESET%^%^ORANGE%^is set into the mass.%^RESET%^");
}
