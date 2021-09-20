
//Vasha's Pride - LoKi


inherit "/d/common/obj/armour/shield.c";
int is_metal() { return 0; }
string owner;

void create() {
   ::create();
   set_name("Vasha's Pride");
   set_id(({"shield","black dragon scale","scale shield","black dragon scale shield"}));
   set_obvious_short("%^C059%^b%^CRST%^la%^C059%^ck dr%^CRST%^a%^C059%^gon sca%^CRST%^l%^C059%^e shie%^CRST%^l%^C059%^d%^CRST%^");
   set_short("%^C059%^Va%^CRST%^%^MAGENTA%^h%^C059%^sa's Pr%^CRST%^%^MAGENTA%^i%^C059%^de%^CRST%^");
   set_long("%^C059%^Formed from a single giant %^C249%^"+
   "scale%^C059%^ from a %^C249%^black dragon%^C059%^, this "+
   "scale is as large as the largest kite shield. The surface "+
   "of it is %^C249%^scarred%^C059%^ as if it had been struck "+
   "a thousand times but it is as solid today as the day it "+
   "was on the %^C249%^dragon%^C059%^ itself. The back of "+
   "the scale has been prepared with %^C090%^runes%^C059%^ "+
   "scored along the edges, and a solid %^C058%^leather "+
  "strap%^C059%^ for the wearer's arm.%^CRST%^\n");
   set_lore("%^C059%^Vasha was a black dragon raised by Mielikkians after "+
   "the egg was stolen from its brood. Against all odds the black was "+
   "raised to the light and still is a champion of the forces of good "+
   "acting through the Silver Thread. This scale was said to have been "+
   "lost fighting a blue dragon that had been attacking Kinaro in 725 "+
   "SG. The dwarves fasioned a shield of it and it was blessed by each "+
   "warrior priest that surived that day."+
		        " \n%^ORANGE%^Father Belanos, the Weapons of Light%^CRST%^");

   set_property("lore",20);
   set_value(1000);
   set_property("enchantment",7);
   set_item_bonus("athletics",6);
   set_item_bonus("poison resistance",35);
   set_struck((:TO,"strikeme":));
   set_wear( (: TO,"limited_wear" :) );
   set_remove( (: TO,"unwear_msg" :) );
}

void init() {
   ::init();
   if(interactive(TP) && TP == environment(TO) && !owner) {
      owner = TPQN;
   }
}

int limited_wear() {

      if( (string)TPQN != owner ) {
         tell_room(EETO,"%^C059%^You hear a growl as the shield refuses "+ETOQCN+"'s arm!\n The shield starts to bleed poison.%^CRST%^",ETO);
         tell_object(ETO,"%^C059%^You hear a growl as you try to put on the shield. Poison starts to bleed from the scale and the shield melts away.%^CRST%^");
         ETO->add_attacker(TO);
         ETO->continue_attack();
         ETO->do_typed_damage(ETO, ETO->return_target_limb(),50 + random(50),"acid");
         ETO->remove_attacker(TO);
         TO->remove();
         return 0;
      }

   
}
int unwear_msg() {
        tell_room(environment(query_worn()),"%^C100%^Unwrapping the leather, "+ETOQCN+" %^C100%^removes their shield.%^CRST%^",ETO);
      tell_object(ETO,"%^C100%^You unstrap the shield from your arm.%^CRST%^");
   return 1;
}

int strikeme(int damage, object what, object who){
        if(random(1000) < 250){
        tell_room(environment(query_worn()),"%^C059%^As a blow lands on "+ETOQCN+"%^C059%^'s shield. Your hear the scream of a dragon that staggers "+who->QCN+"%^C059%^!%^CRST%^",({ETO,who}));
        tell_object(ETO,"%^C059%^You hear the scream of a dragon coming from your shield and "+who->QCN+"%^C059%^ staggers backwards!%^CRST%^");
        tell_object(who,"%^C059%^You are stagged by the scream of a dragon from "+ETOQCN+"%^C059%^'s shield!");
        who->set_paralyzed(1,"%^C059%^You are staggered from the shield!%^CRST%^");
        return 1;
      }
}

